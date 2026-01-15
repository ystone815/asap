package asap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import asap.design.base.packet_bundle
import asap.design.base.stream_monitor_rtl
import asap.design.rtl_delay_line

object rtl_pure_stress_test extends App {
  val targetPackets = 100000
  val latencyCycles = 5 // 5 cycles * 1ns period = 5ns

  println(
    s"=== ASAP Pure RTL Stress Test ($targetPackets packets, Latency ${latencyCycles} cycles) ==="
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

      // RTL-based Printing (Synthesis-time check, Runtime Execution)
      // Prints every 10,000th packet (Simulation Only)
      when(counter % 10000 === 0) {
        report(Seq("Generator Packet Sent: ID=", io.output.payload.id))
      }
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

  class RtlPureTop extends Component {
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
    val monitorCount = out(UInt(64 bits))

    val systemArea = new ClockingArea(systemClk) {
      val gen = new RtlGenerator()
      val sink = new RtlSink()

      // 5-Stage RTL Delay Line Chain
      val stages = 5
      val delays = (0 until stages).map { i =>
        new rtl_delay_line(packet_bundle(), latency = latencyCycles)
          .setName(s"delay_$i")
      }

      // Connect: Gen -> Delay0 -> Delay1 ... -> Sink
      gen.io.output >> delays(0).io.input

      for (i <- 0 until stages - 1) {
        delays(i).io.output >> delays(i + 1).io.input
      }

      delays.last.io.output >> sink.io.input

      receiveCount := sink.io.count

      // Inline RTL Monitor
      val monitor = stream_monitor_rtl.on(sink.io.input, logInterval = 10000)
      monitorCount := monitor.io.txCount
    }
  }

  SimConfig.compile(new RtlPureTop).doSim { dut =>
    // 1 Cycle = 1000 ps (1ns)
    dut.systemClk.forkStimulus(period = 1000)

    println("Simulation started...")

    val startTime = simTime()
    val wallStartTime = System.nanoTime()

    // Start background logger (Removed - moved to RTL)
    // asap.sim.sim_monitor_logger.log(...)

    // Wait for Reset to deassert (forkStimulus default is 100 cycles)
    dut.systemClk.waitSampling(100)

    // Wait for target packets
    println(s"Waiting for target: $targetPackets")
    var currentCount = dut.monitorCount.toBigInt
    while (currentCount < targetPackets) {
      dut.systemClk.waitSampling(1000)
      currentCount = dut.monitorCount.toBigInt
      // println(s"Current: $currentCount") // Debug spam
    }
    println(s"Finished waiting. Final: $currentCount")

    val endTime = simTime()
    val wallEndTime = System.nanoTime()

    // Read final count for stats
    // Ensure we read it safely
    dut.systemClk.waitSampling(1)
    val count = dut.monitorCount.toBigInt.toLong

    val durationPs = endTime - startTime
    val durationSec = durationPs / 1e12
    val wallDurationNs = wallEndTime - wallStartTime
    val wallDurationSec = wallDurationNs / 1e9

    println(s"\n--- Pure RTL Stress Test Results (RTL Monitor) ---")
    println(s"Total Packets: $count")
    println(f"Model Time:    ${durationPs / 1e9} ms")
    println(f"Real Time:     ${wallDurationSec}%.3f sec")

    val throughput = if (durationSec > 0) count / durationSec else 0.0
    val simSpeed = if (wallDurationSec > 0) count / wallDurationSec else 0.0

    println(f"Throughput:    $throughput%.2f Ops/sec (Logical)")
    println(f"Sim Speed:     $simSpeed%.2f Ops/sec (Real Time)")

    println(s"--------------------------")

    // Engine Speed (Cycles/sec)
    if (durationPs > 0) {
      val totalCycles = durationPs / 1000
      val engineSpeed =
        if (wallDurationSec > 0) totalCycles.toDouble / wallDurationSec else 0.0

      // wallDurationMs for comparison
      val wallDurationMs = wallDurationSec * 1000

      println(
        f"Engine Speed:  ${engineSpeed / 1e6}%.2f MHz (Simulated Clock Speed)"
      )

      val simTimeMs = durationPs / 1e9
      val simRate =
        if (wallDurationSec > 0) simTimeMs / wallDurationSec else 0.0
      println(f"Sim Rate:      ${simRate}%.4f ms (Sim Time) / sec (Real Time)")
    }
  }
}
