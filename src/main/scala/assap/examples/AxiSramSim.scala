package assap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib.bus.amba4.axi._
import scala.util.Random
import scala.collection.mutable

// Simple Manual AXI4 Driver for Simulation
class AxiMasterDriver(axi: Axi4, clockDomain: ClockDomain) {
  // Initialize signals
  axi.aw.valid #= false
  axi.w.valid #= false
  axi.ar.valid #= false
  axi.r.ready #= true
  axi.b.ready #= true

  def write(addr: BigInt, data: BigInt): Unit = {
    // We can drive AW and W in parallel or sequence. 
    // For simplicity, we'll do them concurrently using forks, or just manage them in a loop.
    // Using simple sequential logic here (AW then W) is valid but slower. 
    // Let's try to be a bit more parallel to stress test slightly.

    var awDone = false
    var wDone = false

    axi.aw.valid #= true
    axi.aw.payload.addr #= addr
    axi.aw.payload.id #= 0
    axi.aw.payload.len #= 0
    axi.aw.payload.size #= 2 // 4 bytes
    axi.aw.payload.burst #= 1 // INCR
    
    axi.w.valid #= true
    axi.w.payload.data #= data
    axi.w.payload.strb #= 0xF
    axi.w.payload.last #= true

    // Wait until both handshakes are done
    while(!awDone || !wDone) {
      clockDomain.waitSampling()
      
      if (!awDone && axi.aw.ready.toBoolean) {
        axi.aw.valid #= false
        awDone = true
      }
      
      if (!wDone && axi.w.ready.toBoolean) {
        axi.w.valid #= false
        wDone = true
      }
    }
    
    // Wait for B response
    while(!axi.b.valid.toBoolean) {
      clockDomain.waitSampling()
    }
    // B ready is already true
  }

  def read(addr: BigInt): BigInt = {
    axi.ar.valid #= true
    axi.ar.payload.addr #= addr
    axi.ar.payload.id #= 0
    axi.ar.payload.len #= 0
    axi.ar.payload.size #= 2
    axi.ar.payload.burst #= 1
    
    // Wait for AR ready
    clockDomain.waitSamplingWhere(axi.ar.ready.toBoolean)
    axi.ar.valid #= false
    
    // Wait for R valid
    clockDomain.waitSamplingWhere(axi.r.valid.toBoolean)
    val data = axi.r.payload.data.toBigInt
    // R ready is already true
    
    data
  }
}

object AxiSramSim extends App {
  SimConfig.withWave
    .withConfig(
      SpinalConfig(defaultConfigForClockDomains =
        ClockDomainConfig(resetKind = SYNC)
      )
    )
    .compile(
      new SimpleAxiSram(
        addressWidth = 32,
        dataWidth = 32,
        idWidth = 4,
        size = 4096
      )
    )
    .doSim { dut =>
      dut.clockDomain.forkStimulus(period = 10)
      
      val driver = new AxiMasterDriver(dut.io.axi, dut.clockDomain)

      dut.clockDomain.waitSampling(10)
      println("Simulation Start...")

      val scoreboard = mutable.HashMap[Long, BigInt]()
      val rand = new Random(42)
      val numTransactions = 50

      // Write Phase
      println(s"Starting $numTransactions Write Transactions...")
      for (i <- 0 until numTransactions) {
        val addr = (rand.nextInt(1024) * 4).toLong
        val data = BigInt(32, rand)
        
        scoreboard(addr) = data
        driver.write(addr, data) 
      }

      dut.clockDomain.waitSampling(10)

      // Read Phase
      println("Starting Read Verification...")
      var errorCount = 0
      
      for ((addr, expectedData) <- scoreboard) {
        val readData = driver.read(addr)
        
        if (readData != expectedData) {
          println(f"[FAIL] Addr: 0x$addr%x, Read: 0x$readData%x, Expected: 0x$expectedData%x")
          errorCount += 1
        }
      }

      if (errorCount == 0) {
        println(s"SUCCESS! Verified $numTransactions transactions.")
      } else {
        println(s"FAILED with $errorCount errors.")
        simFailure("Verification failed")
      }
    }
}
