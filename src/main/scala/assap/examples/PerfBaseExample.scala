package assap.examples

import spinal.core._
import spinal.core.sim._
import assap.perf.base._
import assap.perf.types.Packet

object PerfBaseExample extends App {
  println("=== Assap Performance Library Example (Constructor Connection) ===")
  
  class Top extends Component {
    val io = new Bundle { val done = out Bool() }
    io.done := False
  }

  SimConfig.withWave.compile(new Top).doSim {
    dut =>
      dut.clockDomain.forkStimulus(period = 10)
      PerfVcdManager.init("perf_trace.vcd")
      PerfVcdManager.start()

      // --- 1. Define Channels (Wires) ---
      val q1 = new PerfFifo[Packet]("Q1", 10, trace = true)
      val q2 = new PerfFifo[Packet]("Q2", 10, trace = true)
      val qArb = new PerfFifo[Packet]("Q_Arb", 10, trace = true)
      val qDelay = new PerfFifo[Packet]("Q_Delay", 10, trace = true)
      val qSinkA = new PerfFifo[Packet]("Q_SinkA", 100, trace = true)
      val qSinkB = new PerfFifo[Packet]("Q_SinkB", 100, trace = true)

      // --- 2. Instantiate Components (Connect in Constructor) ---
      val gen1 = new PerfPacketGenerator("Gen1", outputCh = q1, srcId = 10, rate = 0.3, trace = true)
      val gen2 = new PerfPacketGenerator("Gen2", outputCh = q2, srcId = 20, rate = 0.3, trace = true)
      
      val arbiter = new PerfArbiter[Packet]("Arbiter", inputChs = Seq(q1, q2), outputCh = qArb)
      
      val delayLine = new PerfDelayLine[Packet]("Delay5", inputCh = qArb, outputCh = qDelay, latency = 5)
      
      val router = new PerfRouter[Packet](
        "Router", 
        inputCh = qDelay, 
        outputChs = Map(0 -> qSinkA, 1 -> qSinkB),
        getDest = _.destId
      )
      
      val sinkA = new PerfSink("SinkA", inputCh = qSinkA, trace = true)
      val sinkB = new PerfSink("SinkB", inputCh = qSinkB, trace = true)

      // --- 3. Run ---
      val components = Seq(gen1, gen2, arbiter, delayLine, router, sinkA, sinkB, q1, q2, qArb, qDelay, qSinkA, qSinkB)
      components.foreach(_.run(dut.clockDomain))

      fork {
        while(true) {
          PerfVcdManager.tick(simTime() / 10)
          dut.clockDomain.waitSampling()
        }
      }

      dut.clockDomain.waitSampling(100)
      PerfVcdManager.close()

      println("\n--- Simulation Results ---")
      println(s"SinkA: Received ${sinkA.receivedCount}, Avg Latency: ${if(sinkA.receivedCount>0) sinkA.totalLatency/sinkA.receivedCount else 0}")
      println(s"SinkB: Received ${sinkB.receivedCount}, Avg Latency: ${if(sinkB.receivedCount>0) sinkB.totalLatency/sinkB.receivedCount else 0}")
      println(s"VCD generated at: perf_trace.vcd")
  }
}