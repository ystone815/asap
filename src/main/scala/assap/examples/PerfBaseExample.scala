package assap.examples

import spinal.core._
import spinal.core.sim._
import assap.perf.base._
import assap.perf.types.Packet

object PerfBaseExample extends App {
  println("=== Assap Performance Library Example (1ps Resolution) ===")

  class Top extends Component {
    val io = new Bundle { val done = out Bool () }
    io.done := False
  }

  SimConfig.withWave.compile(new Top).doSim { dut =>
    PerfVcdManager.init("perf_trace.vcd")
    PerfVcdManager.start()

    // --- 1. Channels ---
    val q1 = new PerfFifo[Packet]("Q1", 10, trace = true)
    val q2 = new PerfFifo[Packet]("Q2", 10, trace = true)
    val qArb = new PerfFifo[Packet]("Q_Arb", 10, trace = true)
    val qDelay = new PerfFifo[Packet]("Q_Delay", 10, trace = true)
    val qSinkA = new PerfFifo[Packet]("Q_SinkA", 100, trace = true)
    val qSinkB = new PerfFifo[Packet]("Q_SinkB", 100, trace = true)

    // --- 2. Components ---
    val gen1 = new PerfPacketGenerator(
      "Gen1",
      output = q1,
      srcId = 10,
      rate = 0.3,
      trace = true
    )
    val gen2 = new PerfPacketGenerator(
      "Gen2",
      output = q2,
      srcId = 20,
      rate = 0.3,
      trace = true
    )

    val arbiter =
      new PerfArbiter[Packet]("Arbiter", inputs = Seq(q1, q2), output = qArb)
    val delayLine = new PerfDelayLine[Packet](
      "Delay5ns",
      input = qArb,
      output = qDelay,
      latency = 5000
    )

    val router = new PerfRouter[Packet](
      "Router",
      input = qDelay,
      outputs = Map(0 -> qSinkA, 1 -> qSinkB),
      getDest = _.dest_id
    )

    val sinkA = new PerfSink("SinkA", input = qSinkA, trace = true)
    val sinkB = new PerfSink("SinkB", input = qSinkB, trace = true)

    // --- 3. Run ---
    val components = Seq(
      gen1,
      gen2,
      arbiter,
      delayLine,
      router,
      sinkA,
      sinkB,
      q1,
      q2,
      qArb,
      qDelay,
      qSinkA,
      qSinkB
    )
    components
      .foreach(c => if (c.isInstanceOf[SimComponent]) c.run(dut.clockDomain))

    // VCD Ticker (Log every 1ns)
    fork {
      while (true) {
        PerfVcdManager.tick(simTime())
        sleep(1000)
      }
    }

    // Run for 100ns (100,000ps)
    sleep(100000)
    PerfVcdManager.close()

    println("\n--- Simulation Results ---")
    println(s"SinkA: Received ${sinkA.receivedCount}, Avg Latency: ${if (
        sinkA.receivedCount > 0
      ) sinkA.totalLatency / sinkA.receivedCount
      else 0} ps")
    println(s"SinkB: Received ${sinkB.receivedCount}, Avg Latency: ${if (
        sinkB.receivedCount > 0
      ) sinkB.totalLatency / sinkB.receivedCount
      else 0} ps")
    println(s"VCD generated at: perf_trace.vcd")
  }
}
