package assap.perf

import spinal.core._
import spinal.core.sim._
import spinal.lib.bus.amba4.axi._
import assap.design.AxiUtils._
import assap.examples.SimpleAxiSram

// Top level component connecting Generator and SRAM
class PerfSystem extends Component {
  val axiConfig = Axi4Config(32, 32, 4)
  val genConfig = TrafficConfig(
    axiConfig = axiConfig,
    writeRatioPercent = 50, // 50% Reads, 50% Writes
    localityPercent = 80    // 80% Sequential
  )

  val generator = new TrafficGenerator(genConfig)
  val sram = new SimpleAxiSram(32, 32, 4, 4096)

  val io = new Bundle {
    val enable = in Bool()
    val writeCount = out UInt(32 bits)
    val readCount = out UInt(32 bits)
  }

  // Connect Gen -> SRAM
  generator.io.axi.drive(sram.io.axi)

  // Control & Status
  generator.io.enable := io.enable
  io.writeCount := generator.io.writeCount
  io.readCount := generator.io.readCount
}

object PerfSim extends App {
  SimConfig.withWave.compile(new PerfSystem).doSim { dut =>
    dut.clockDomain.forkStimulus(period = 10)
    
    dut.io.enable #= false
    dut.clockDomain.waitSampling(10)

    println("Starting Traffic Generation...")
    dut.io.enable #= true

    // Run for 2000 cycles
    for(i <- 0 until 200) {
      if (i % 20 == 0) {
        println(s"Time $i: Writes=${dut.io.writeCount.toLong}, Reads=${dut.io.readCount.toLong}")
      }
      dut.clockDomain.waitSampling(10)
    }

    dut.io.enable #= false
    dut.clockDomain.waitSampling(10)
    
    println("Simulation Finished.")
    println(s"Total Writes: ${dut.io.writeCount.toLong}")
    println(s"Total Reads:  ${dut.io.readCount.toLong}")
    println(s"Total Txns:   ${dut.io.writeCount.toLong + dut.io.readCount.toLong}")
  }
}
