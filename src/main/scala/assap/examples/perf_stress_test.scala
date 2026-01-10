package assap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import assap.perf.base._
import assap.perf.types.{packet, packet_type}

object perf_stress_test extends App {
  // Increase packet count for meaningful performance data
  val packetCount = 500000
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
    // 5-Stage Delay Line Chain
    val stages = 5
    val queues = (0 to stages).map(i => new perf_fifo[packet](s"Q$i", 1000))

    val gen = new perf_packet_generator("Gen", queues(0), 0, 1.0)

    val delays = (0 until stages).map { i =>
      new perf_delay_line[packet](
        s"Delay$i",
        queues(i),
        queues(i + 1),
        latencyVal
      )
    }

    val sink = new perf_sink("Sink", queues.last)

    val components = Seq(gen, sink) ++ delays

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
