package assap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import assap.perf.base._
import assap.perf.types.{packet, packet_type}

object perf_stress_test extends App {
  // Increase packet count for meaningful performance data
  val packetCount = 100000
  val latencyVal = 5 // 5ns

  println(s"=== ASSAP Perf Stress Test ($packetCount packets) ===")

  class Top extends Component {
    val io = new Bundle { val done = out Bool () }
    io.done := False
  }

  val compiled = SimConfig.compile(new Top)

  // Reuse the compiled simulation
  compiled.doSim { dut =>
    dut.clockDomain.forkStimulus(period = 1000)
    // Setup components
    val q1 = new perf_fifo[packet]("Q1", 1000)
    val q2 = new perf_fifo[packet]("Q2", 1000)

    val gen = new perf_packet_generator("Gen", q1, 0, 1.0)
    val delay = new perf_delay_line[packet]("Delay", q1, q2, latencyVal)
    val sink = new perf_sink("Sink", q2)

    val components = Seq(gen, delay, sink)

    // Start simulation threads
    components.foreach(_.run(dut.clockDomain))

    println("Simulation started...")
    val startTime = System.nanoTime()

    // Wait until all packets are received
    waitUntil(sink.receivedCount >= packetCount)

    val endTime = System.nanoTime()
    val wallDurationMs = (endTime - startTime) / 1e6
    val simDurationPs = simTime()

    println(s"\n--- SW Perf Stress Test Results ---")
    println(s"Total Packets: ${sink.receivedCount}")
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
