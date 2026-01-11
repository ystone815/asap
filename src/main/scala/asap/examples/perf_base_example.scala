package asap.examples

import asap.perf.base._
import asap.perf.types.{packet, packet_type}
import spinal.core._
import spinal.core.sim._

object perf_base_example extends App {
  val packetCount = 100
  val latencyVal = 500 // 500 ps

  println(s"=== ASAP Perf Base Example ($packetCount packets) ===")

  // Dummy Top for SpinalSim
  class Top extends Component {
    val io = new Bundle { val done = out Bool () }
    io.done := False
  }

  val compiled = SimConfig.compile(new Top)

  compiled.doSim { (dut: Top) =>
    // 1. Setup
    val q1 = new perf_fifo[packet]("Q1", 100, trace = false)
    val q2 = new perf_fifo[packet]("Q2", 100, trace = false)

    // Gen Rate 1.0 -> 1ns -> 1G pps.
    val gen = new perf_packet_generator(
      "Gen",
      output = q1,
      srcId = 0,
      rate = 1.0,
      trace = false
    )

    val delay = new perf_delay_line[packet](
      "Delay",
      input = q1,
      output = q2,
      latency = latencyVal
    )
    val sink = new perf_sink("Sink", input = q2, trace = false)

    val components = Seq(gen, delay, sink)
    components.foreach(_.run(dut.clockDomain))

    println("Initialization complete. Starting measurement...")
    val startTime = System.nanoTime()

    // 2. Main Wait
    waitUntil(sink.receivedCount >= packetCount)

    val endTime = System.nanoTime()
    val wallDurationMs = (endTime - startTime) / 1e6
    val simDurationPs = simTime()

    println(s"\n--- SW Perf Stress Test Results ---")
    println(s"Total Packets: ${sink.receivedCount}")
    println(s"Latency Setting: $latencyVal ps")
    println(s"Sim Time:      $simDurationPs ps")
    println(s"Wall Time:     $wallDurationMs ms")

    if (wallDurationMs > 0) {
      val simSpeed = (sink.receivedCount * 1000.0) / wallDurationMs
      println(
        f"Sim Speed:     $simSpeed%.2f packets/sec (Real-time processing speed)"
      )
    }

    if (simDurationPs > 0) {
      val bandwidth = (sink.receivedCount * 1e12) / simDurationPs
      println(f"Model BW:      $bandwidth%.2f packets/sec (Logical throughput)")
      println(f"               ${bandwidth / 1e9}%.2f Gpps")
    }
  }
}
