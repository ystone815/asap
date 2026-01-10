package assap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import assap.design.base.packet_bundle
import assap.design.rtl_delay_line

object rtl_pure_stress_test extends App {
  val targetPackets = 100000
  val latencyCycles = 5 // 5 cycles * 1ns period = 5ns

  println(
    s"=== ASSAP Pure RTL Stress Test ($targetPackets packets, Latency ${latencyCycles} cycles) ==="
  )

  class RtlGenerator extends Component {
    val io = new Bundle {
      val output = master Stream (packet_bundle())
    }
    val counter = Reg(UInt(32 bits)) init (0)

    // Full speed generator (1 packet per cycle)
    io.output.valid := True
    io.output.payload.addr := counter
    io.output.payload.size := 64
    io.output.payload.id := counter

    when(io.output.ready) {
      counter := counter + 1
    }
  }

  class RtlSink extends Component {
    val io = new Bundle {
      val input = slave Stream (packet_bundle())
      val count = out UInt (32 bits)
    }
    val counter = Reg(UInt(32 bits)) init (0)
    io.input.ready := True

    when(io.input.valid) {
      counter := counter + 1
    }
    io.count := counter
  }

  class Top extends Component {
    val systemClkConfig =
      ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH)
    val clk = in Bool ()
    val reset = in Bool ()
    val systemClk = ClockDomain(
      clk,
      reset,
      config = systemClkConfig,
      frequency = FixedFrequency(1 GHz)
    )

    val receiveCount = out(UInt(32 bits))

    val systemArea = new ClockingArea(systemClk) {
      val gen = new RtlGenerator()
      // Generic RtlDelayLine with PacketBundle
      val delay = new rtl_delay_line(packet_bundle(), latency = latencyCycles)
      val sink = new RtlSink()

      gen.io.output >> delay.io.input
      delay.io.output >> sink.io.input

      receiveCount := sink.io.count
    }
  }

  SimConfig.compile(new Top).doSim { dut =>
    // 1 Cycle = 1000 ps (1ns)
    dut.systemClk.forkStimulus(period = 1000)

    println("Simulation started...")
    val startTime = System.nanoTime()

    var count = 0L
    while (count < targetPackets) {
      dut.systemClk.waitSampling(1000)
      count = dut.receiveCount.toLong
    }

    val endTime = System.nanoTime()
    val wallDurationMs = (endTime - startTime) / 1e6
    // simTime() returns ps.
    val simDurationPs = simTime()

    println(s"\n--- Pure RTL Stress Test Results ---")
    println(s"Total Packets: $count")
    println(s"Sim Time:      $simDurationPs ps")
    println(s"Wall Time:     $wallDurationMs ms")

    if (wallDurationMs > 0) {
      val simSpeed = (count * 1000.0) / wallDurationMs
      println(
        f"Sim Speed:     $simSpeed%.2f packets/sec (Real-time processing speed)"
      )
    }

    if (simDurationPs > 0) {
      val bandwidth = (count * 1e12) / simDurationPs
      println(f"Model BW:      $bandwidth%.2f packets/sec (Logical throughput)")
      println(f"               ${bandwidth / 1e9}%.2f Gpps")
    }
  }
}
