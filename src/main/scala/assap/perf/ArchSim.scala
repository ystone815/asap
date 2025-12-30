package assap.perf

import spinal.core._
import spinal.core.sim._
import scala.collection.mutable.Queue
import scala.util.Random

// 1. Transaction Definition (Pure Software Object)
case class ArchTxn(id: Int, addr: Long, isWrite: Boolean, creationTime: Long)

// 2. Architectural Components (Pure Scala Classes)

class SimMaster(name: String, queue: Queue[ArchTxn], injectionRate: Double, cd: ClockDomain) {
  var txnId = 0
  val rand = new Random(name.hashCode)

  def start(): Unit = {
    fork {
      while (true) {
        // Randomly decide to generate a transaction
        if (rand.nextDouble() < injectionRate) {
          val txn = ArchTxn(txnId, rand.nextInt(1000), rand.nextBoolean(), simTime())
          queue.enqueue(txn)
          txnId += 1
          // println(s"[$name] Generated Txn $txnId at ${SimTime()}")
        }
        cd.waitSampling() // Wait 1 cycle
      }
    }
  }
}

class SimArbiter(
    inputs: Seq[Queue[ArchTxn]], 
    output: Queue[ArchTxn], 
    delay: Int, 
    cd: ClockDomain
) {
  def start(): Unit = {
    fork {
      while (true) {
        // Simple Round Robin Logic
        // In pure software, we can just iterate buffers
        val activeInput = inputs.find(_.nonEmpty)
        
        if (activeInput.isDefined) {
          val txn = activeInput.get.dequeue()
          
          // Model Arbitration + Routing Delay
          if (delay > 0) cd.waitSampling(delay)
          
          output.enqueue(txn)
        }
        
        cd.waitSampling() // Process 1 txn per cycle (throughput limit)
      }
    }
  }
}

class SimMemory(
    input: Queue[ArchTxn], 
    latency: Int, 
    cd: ClockDomain
) {
  var processedCount = 0
  var totalLatency = 0L

  def start(): Unit = {
    fork {
      while (true) {
        if (input.nonEmpty) {
          val txn = input.dequeue()
          
          // Model Memory Access Latency
          // (Can be random, fixed, or dependent on address for bank conflicts)
          cd.waitSampling(latency)
          
          val endTime = simTime()
          val duration = endTime - txn.creationTime
          
          totalLatency += duration
          processedCount += 1
          
          // println(s"[Mem] Finished Txn ${txn.id} (Lat: $duration cycles)")
        } else {
          cd.waitSampling() // Idle
        }
      }
    }
  }
}

// 3. Dummy Hardware (Needed just to launch the Simulator)
class DummyTop extends Component {
  val io = new Bundle {
    val keepAlive = out Bool()
  }
  io.keepAlive := True
}

// 4. Simulation Runner
object ArchSim extends App {
  SimConfig.compile(new DummyTop).doSim { dut =>
    dut.clockDomain.forkStimulus(period = 10)
    
    // --- System Construction (Wiring in Software) ---
    // Links (Infinite Queues representing buffers)
    val linkM1 = new Queue[ArchTxn]()
    val linkM2 = new Queue[ArchTxn]()
    val linkMem = new Queue[ArchTxn]()

    // Parameters
    val master1 = new SimMaster("M1", linkM1, injectionRate = 0.3, dut.clockDomain)
    val master2 = new SimMaster("M2", linkM2, injectionRate = 0.2, dut.clockDomain)
    
    // Arbiter: 2 inputs -> 1 output, 1 cycle delay
    val arbiter = new SimArbiter(Seq(linkM1, linkM2), linkMem, delay = 1, dut.clockDomain)
    
    // Memory: 20 cycles fixed latency
    val memory = new SimMemory(linkMem, latency = 20, dut.clockDomain)

    // --- Start Threads ---
    master1.start()
    master2.start()
    arbiter.start()
    memory.start()

    println("Starting Architectural Simulation...")
    
    // Run for 10000 cycles
    dut.clockDomain.waitSampling(10000)

    // --- Report ---
    println("=" * 40)
    println("Simulation Result")
    println("=" * 40)
    println(s"Master 1 Generated: ${master1.txnId}")
    println(s"Master 2 Generated: ${master2.txnId}")
    println(s"Memory Processed:   ${memory.processedCount}")
    
    if (memory.processedCount > 0) {
      val avgLat = memory.totalLatency.toDouble / memory.processedCount
      println(f"Average Latency:    $avgLat%.2f cycles")
    }
    
    // Congestion Analysis
    println(s"Leftover in M1 Queue: ${linkM1.size}")
    println(s"Leftover in M2 Queue: ${linkM2.size}")
    println(s"Leftover in Mem Queue: ${linkMem.size}")
    
    val totalGen = master1.txnId + master2.txnId
    val throughput = memory.processedCount.toDouble / 10000.0
    println(f"System Throughput:    $throughput%.4f txns/cycle")
    
    if (linkM1.size > 100 || linkM2.size > 100) {
      println("WARNING: High congestion detected at Masters!")
    }
  }
}
