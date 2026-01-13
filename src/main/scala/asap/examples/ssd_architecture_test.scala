package asap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import asap.design.base.ram_delay_line
import asap.arch.arch_nand
import scala.util.Random

/** SSD Architecture Stress Test
  *   - 1024 NANDs (16 Channels x 64 Dies)
  *   - Queue Depth: 2048
  *   - Latency: 10us Downstream + 20us tR + 10us Upstream
  */
object ssd_architecture_test extends App {
  // Configuration
  val numChannels = 16
  val diesPerChannel = 64
  val totalNands = numChannels * diesPerChannel // 1024
  val queueDepth = 2048
  val clkFreq = 1 GHz

  // Latencies (1GHz = 1ns period)
  val downstreamDelayCycles = 10000 // 10us
  val upstreamDelayCycles = 10000 // 10us
  val nandTRCycles = 20000 // 20us

  class SsdArchTop extends Component {
    val systemClkConfig =
      ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH)
    val clk = in Bool ()
    val reset = in Bool ()
    val systemClk = ClockDomain(
      clk,
      reset,
      config = systemClkConfig,
      frequency = FixedFrequency(clkFreq)
    )

    val completedCount = out UInt (32 bits)
    val pendingCount = out UInt (32 bits)

    val systemArea = new ClockingArea(systemClk) {
      // Host: Traffic Generator with Credit (QD) System
      val pendingTags = Reg(UInt(32 bits)) init (0)
      val completions = Reg(UInt(32 bits)) init (0)

      // Infinite Stream of Commands, gated by QD
      val hostCmd = Stream(Bits(32 bits))
      hostCmd.valid := pendingTags < queueDepth
      // Actually we need unique tags to track? For throughput we just blast commands.
      // But verify routing: payload = Address.
      // Layout: [Channel: 4 bits] [Die: 6 bits] [Resvd: 22 bits]
      // Mapping: LSB.

      // Let's use a counter to ensure we hit all addresses evenly if possible, but Random is fine for stress.
      // Using a global counter for "Tag"/"Address"
      val tagCounter = Reg(UInt(32 bits)) init (0)
      hostCmd.payload := tagCounter.asBits

      when(hostCmd.fire) {
        pendingTags := pendingTags + 1
        tagCounter := tagCounter + 1
      }

      // ==========================================
      // Interconnect (Host -> 16 Channels)
      // ==========================================
      // Simple Demux based on LSB 4 bits (Channel ID)
      val channelsCmd = StreamDemux(
        hostCmd,
        select = tagCounter(3 downto 0),
        portCount = numChannels
      )

      // ==========================================
      // 16 SSD Channels
      // ==========================================
      val channelOutputs = for (c <- 0 until numChannels) yield new Area {
        val cmdIn = channelsCmd(c)

        // 1. Downstream Delay (Firmware/Controller overhead)
        val ramDelayDown =
          new ram_delay_line(Bits(32 bits), downstreamDelayCycles)
        ramDelayDown.io.input << cmdIn

        // 2. Demux to 64 Dies (Next 6 bits: 9 downto 4)
        // Extract Die ID from the delayed payload
        val dieSelect = ramDelayDown.io.output.payload(9 downto 4).asUInt
        val diesCmd = StreamDemux(
          ramDelayDown.io.output,
          select = dieSelect,
          portCount = diesPerChannel
        )

        // 3. 64 NAND Models
        val dieOutputs = for (d <- 0 until diesPerChannel) yield new Area {
          val nand = new arch_nand(tR_cycles = nandTRCycles)
          nand.io.cmd << diesCmd(d)

          // Result
          val output = nand.io.data
        }

        // 4. Arbiter (64 Dies -> 1 Upstream Path)
        // Round Robin Arbiter
        val arbiter =
          StreamArbiterFactory().roundRobin.on(dieOutputs.map(_.output))

        // 5. Upstream Delay (Firmware/Controller overhead)
        val ramDelayUp = new ram_delay_line(Bits(32 bits), upstreamDelayCycles)
        ramDelayUp.io.input << arbiter

        val result = ramDelayUp.io.output
      }

      // ==========================================
      // Aggregation (16 Channels -> Host)
      // ==========================================
      // Round Robin Arbiter to collect completions
      val finalArbiter =
        StreamArbiterFactory().roundRobin.on(channelOutputs.map(_.result))

      // Host Sink
      finalArbiter.ready := True
      when(finalArbiter.valid) {
        pendingTags := pendingTags - 1
        completions := completions + 1
      }

      completedCount := completions
      pendingCount := pendingTags
    }
  }

  SimConfig.compile(new SsdArchTop).doSim { dut =>
    dut.systemClk.forkStimulus(period = 1000)
    dut.systemClk.waitSampling(100) // Wait for reset to complete

    println(s"=== SSD Architecture Stress Test ===")
    println(s"NANDs: $totalNands (16 Ch x 64 Die)")
    println(s"Queue Depth: $queueDepth")
    println(
      s"Latencies: Down=${downstreamDelayCycles / 1000}us, tR=${nandTRCycles / 1000}us, Up=${upstreamDelayCycles / 1000}us"
    )

    // Warmup + Measure
    // We want to run until we complete ~50,000 ops (enough for steady state)
    val targetOps = 50000L

    var startTime = System.nanoTime()
    var startSimTime = simTime()

    // Wait for some completions
    while (dut.completedCount.toLong < targetOps) {
      dut.systemClk.waitSampling(1000)
      if (dut.completedCount.toLong % 10000 == 0) {
        // print(".")
      }
    }

    var endTime = System.nanoTime()
    var endSimTime = simTime()

    val durationMs = (endTime - startTime) / 1e6
    val simDurationPs = endSimTime - startSimTime
    val ops = dut.completedCount.toLong

    println(s"\n--- SSD Benchmark Results ---")
    println(s"Total Ops: $ops")
    println(s"Real Time: $durationMs ms")
    println(s"Sim Time:  ${simDurationPs / 1e9} sec")

    val sps = (ops * 1000.0) / durationMs
    println(f"Sim Speed: $sps%.2f Ops/sec")

    val engineSpeedMHz = (simDurationPs / 1000.0) / (durationMs * 1000.0)
    println(f"Engine Speed: $engineSpeedMHz%.2f MHz")

    val flowRate = (simDurationPs / 1e9) / (durationMs / 1000.0)
    println(f"Flow Rate: ${flowRate * 1000}%.2f ms (Sim) / sec (Real)")
  }
}
