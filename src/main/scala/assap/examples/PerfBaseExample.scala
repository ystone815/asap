package assap.examples

import spinal.core._
import spinal.core.sim._
import assap.perf.base._
import assap.perf.types.Packet

object PerfBaseExample extends App {
  println("=== Assap Performance Library Example (SpinalSim Threading) ===")
  
  // Dummy component to host simulation
  class Top extends Component {
    val io = new Bundle { val done = out Bool() }
    io.done := False
  }

  SimConfig.withWave.compile(new Top).doSim {
    dut =>
      dut.clockDomain.forkStimulus(period = 10)
    
    // Initialize VCD
    PerfVcdManager.init("perf_trace.vcd")
    PerfVcdManager.start()

    // --- 1. Instantiation ---
    val q1 = new PerfFifo[Packet]("Q1", 10, trace = true)
    val q2 = new PerfFifo[Packet]("Q2", 10, trace = true)
    
    val gen1 = new PerfPacketGenerator("Gen1", q1, srcId = 10, rate = 0.3, trace = true)
    val gen2 = new PerfPacketGenerator("Gen2", q2, srcId = 20, rate = 0.3, trace = true)

    val qArb = new PerfFifo[Packet]("Q_Arb", 10, trace = true)
    val arbiter = new PerfArbiter[Packet]("Arbiter", Seq(q1, q2), qArb)

    val qDelayOut = new PerfFifo[Packet]("Q_DelayOut", 10, trace = true)
    val delayLine = new PerfDelayLine[Packet]("Delay5", input = qArb, output = qDelayOut, latency = 5)

    val qSinkA = new PerfFifo[Packet]("Q_SinkA", 100, trace = true)
    val qSinkB = new PerfFifo[Packet]("Q_SinkB", 100, trace = true)

    val router = new PerfRouter[Packet](
      "Router", 
      input = qDelayOut, 
      routingTable = Map(0 -> qSinkA, 1 -> qSinkB),
      getDest = (p: Packet) => p.destId
    )

    val sinkA = new PerfSink("SinkA", qSinkA, trace = true)
    val sinkB = new PerfSink("SinkB", qSinkB, trace = true)

    val components = Seq(q1, q2, gen1, gen2, qArb, arbiter, qDelayOut, delayLine, qSinkA, qSinkB, router, sinkA, sinkB)

    // --- 2. Run Threads ---
    // Start all component threads
    components.foreach(_.run(dut.clockDomain))

    // VCD Ticker Thread
    fork {
      while(true) {
        PerfVcdManager.tick(simTime() / 10)
        dut.clockDomain.waitSampling()
      }
    }

    // Run Simulation
    dut.clockDomain.waitSampling(100)

    // Close
    PerfVcdManager.close()

    // --- 3. Report ---
    println("\n--- Simulation Results ---")
    println(s"SinkA: Received ${sinkA.receivedCount}, Avg Latency: ${if(sinkA.receivedCount>0) sinkA.totalLatency/sinkA.receivedCount else 0}")
    println(s"SinkB: Received ${sinkB.receivedCount}, Avg Latency: ${if(sinkB.receivedCount>0) sinkB.totalLatency/sinkB.receivedCount else 0}")
    println(s"VCD generated at: perf_trace.vcd")
  }
}