package asap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import asap.design.base.packet_bundle
import asap.design.rtl_delay_line

object rtl_massive_stress_test extends App {
  val targetPackets = 100000
  val latencyCycles = 5 // 5 cycles * 1ns period = 5ns

  println(
    s"=== ASAP Massive RTL Stress Test (1024 NANDs) ==="
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

      // ==========================================
      // Background Traffic: 1024 Parallel NAND Models
      // ==========================================
      val bgPlanes = for (i <- 0 until 1024) yield new Area {
        val nand =
          new asap.design.simple_nand_model(tR_cycles = 20000) // 20us tR

        // Traffic Gen: Always push commands
        nand.io.cmd.valid := True
        nand.io.cmd.payload := B(i, 32 bits)

        // Sink: Always consume data
        nand.io.data.ready := True
      }
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

    println(s"\n--- Massive RTL Stress Test Results ---")
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

      // Engine Speed (Cycles/sec)
      val totalCycles = simDurationPs / 1000
      val engineSpeed = (totalCycles * 1000.0) / wallDurationMs
      println(
        f"Engine Speed:  ${engineSpeed / 1e6}%.2f MHz (Simulated Clock Speed)"
      )

      val simTimeMs = simDurationPs / 1e9
      val wallTimeSec = wallDurationMs / 1000.0
      println(
        f"Sim Rate:      ${simTimeMs / wallTimeSec}%.4f ms (Sim Time) / sec (Wall Time)"
      )
    }
  }
}
