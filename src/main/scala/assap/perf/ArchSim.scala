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
        if (rand.nextDouble() < injectionRate) {
          val txn = ArchTxn(txnId, rand.nextInt(1000), rand.nextBoolean(), simTime())
          queue.enqueue(txn)
          txnId += 1
        }
        cd.waitSampling()
      }
    }
  }
}

class SimArbiter(inputs: Seq[Queue[ArchTxn]], output: Queue[ArchTxn], delay: Int, cd: ClockDomain) {
  def start(): Unit = {
    fork {
      while (true) {
        val activeInput = inputs.find(_.nonEmpty)
        if (activeInput.isDefined) {
          val txn = activeInput.get.dequeue()
          if (delay > 0) cd.waitSampling(delay)
          output.enqueue(txn)
        }
        cd.waitSampling()
      }
    }
  }
}

class SimMemory(input: Queue[ArchTxn], latency: Int, cd: ClockDomain) {
  var processedCount = 0
  var totalLatency = 0L
  def start(): Unit = {
    fork {
      while (true) {
        if (input.nonEmpty) {
          val txn = input.dequeue()
          cd.waitSampling(latency)
          val endTime = simTime()
          val duration = endTime - txn.creationTime
          totalLatency += duration
          processedCount += 1
        } else {
          cd.waitSampling()
        }
      }
    }
  }
}

// 3. Dummy Hardware with Monitor Ports
class DummyTop extends Component {
  val io = new Bundle {
    // These ports are just for VCD visibility
    val qM1Size = out UInt(16 bits)
    val qM2Size = out UInt(16 bits)
    val qMemSize = out UInt(16 bits)
    val totalProcessed = out UInt(32 bits)
  }
  io.qM1Size := 0
  io.qM2Size := 0
  io.qMemSize := 0
  io.totalProcessed := 0
}

// 4. Simulation Runner
object ArchSim extends App {
  // .withWave is important!
  SimConfig.withWave.compile(new DummyTop).doSim { dut =>
    dut.clockDomain.forkStimulus(period = 10)
    
    // Links
    val linkM1 = new Queue[ArchTxn]()
    val linkM2 = new Queue[ArchTxn]()
    val linkMem = new Queue[ArchTxn]()

    val master1 = new SimMaster("M1", linkM1, 0.3, dut.clockDomain)
    val master2 = new SimMaster("M2", linkM2, 0.2, dut.clockDomain)
    val arbiter = new SimArbiter(Seq(linkM1, linkM2), linkMem, 1, dut.clockDomain)
    val memory = new SimMemory(linkMem, 20, dut.clockDomain)

    master1.start()
    master2.start()
    arbiter.start()
    memory.start()

    // --- VCD Update Loop ---
    // Every cycle, we copy Scala queue sizes to hardware ports
    fork {
      while(true) {
        dut.io.qM1Size #= linkM1.size
        dut.io.qM2Size #= linkM2.size
        dut.io.qMemSize #= linkMem.size
        dut.io.totalProcessed #= memory.processedCount
        dut.clockDomain.waitSampling()
      }
    }

    println("Starting Architectural Simulation with VCD tracing...")
    dut.clockDomain.waitSampling(5000) // Run shorter for quick VCD check

    println("Simulation Finished. Check simWorkspace/DummyTop/test.vcd")
    println(s"Final Mem Queue Size: ${linkMem.size}")
  }
}