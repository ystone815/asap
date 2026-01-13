package asap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import asap.design.base.{ram_delay_line, write_aggregator}
import asap.arch.arch_nand
import scala.util.Random

/** SSD Write Benchmark (Program Operation)
  *   - Workload: 48 Host Commands (4KB) -> 1 NAND Program (192KB)
  *   - Scale: 1024 NANDs
  */
object ssd_write_benchmark extends App {
  // Configuration
  val numChannels = 16
  val diesPerChannel = 64
  val totalNands = numChannels * diesPerChannel
  val queueDepth =
    65536 // Increased to avoid Write Buffer starvation (Need > 1024*48/2 to keep pipes full?)
  val aggregationFactor = 48

  val clkFreq = 1 GHz

  // Latencies
  val downstreamDelayCycles = 10000 // 10us
  val upstreamDelayCycles = 10000 // 10us
  val nandProgramCycles = 1000000 // 1ms (Slow Program)

  class SsdWriteTop extends Component {
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
      // Host Generator
      val pendingTags = Reg(UInt(32 bits)) init (0)
      val completions = Reg(UInt(32 bits)) init (0)

      val hostCmd = Stream(Bits(32 bits))
      hostCmd.valid := pendingTags < queueDepth

      // Sequential Tag Generation
      val tagCounter = Reg(UInt(32 bits)) init (0)
      hostCmd.payload := tagCounter.asBits

      when(hostCmd.fire) {
        pendingTags := pendingTags + 1
        tagCounter := tagCounter + 1
      }

      // Interconnect
      val channelSelectBits = log2Up(numChannels)
      val channelsCmd = if (numChannels > 1) {
        StreamDemux(
          hostCmd,
          select = tagCounter(channelSelectBits - 1 downto 0),
          portCount = numChannels
        )
      } else {
        Vec(hostCmd) // Single channel pass-through
      }

      val channelOutputs = for (c <- 0 until numChannels) yield new Area {
        val cmdIn = channelsCmd(c)

        // Downstream Delay
        val ramDelayDown =
          new ram_delay_line(Bits(32 bits), downstreamDelayCycles)
        ramDelayDown.io.input << cmdIn

        // Demux to Dies
        val dieSelectBits = log2Up(diesPerChannel)
        val dieSelectOffset = 4 // Arbitrary bit offset after channel bits
        // Logic: [Channel Bits] [Die Bits] ...
        // We used LSB for channel. Next bits for Die.
        val dieSelect = ramDelayDown.io.output
          .payload(dieSelectOffset + dieSelectBits - 1 downto dieSelectOffset)
          .asUInt

        val diesCmd = if (diesPerChannel > 1) {
          StreamDemux(
            ramDelayDown.io.output,
            select = dieSelect,
            portCount = diesPerChannel
          )
        } else {
          Vec(ramDelayDown.io.output)
        }

        val dieOutputs = for (d <- 0 until diesPerChannel) yield new Area {
          // Aggregator: 48 Cmds -> 1 Nand Op
          val aggregator =
            new write_aggregator(aggregationFactor, Bits(32 bits))
          aggregator.io.cmdIn << diesCmd(d)

          val nand = new arch_nand(tR_cycles = nandProgramCycles)
          nand.io.cmd << aggregator.io.cmdOut

          aggregator.io.rspIn << nand.io.data
          val output = aggregator.io.rspOut
        }

        // Arbiter
        val arbiter =
          StreamArbiterFactory().roundRobin.on(dieOutputs.map(_.output))

        // Upstream Delay
        val ramDelayUp = new ram_delay_line(Bits(32 bits), upstreamDelayCycles)
        ramDelayUp.io.input << arbiter

        val result = ramDelayUp.io.output
      }

      // Final Aggregation
      val finalArbiter =
        StreamArbiterFactory().roundRobin.on(channelOutputs.map(_.result))
      finalArbiter.ready := True

      when(finalArbiter.valid) {
        pendingTags := pendingTags - 1
        completions := completions + 1
      }

      completedCount := completions
      pendingCount := pendingTags
    }
  }

  SimConfig
    .compile(new SsdWriteTop)
    .doSim { dut =>
      dut.systemClk.forkStimulus(period = 1000)
      dut.systemClk.waitSampling(100)

      println(s"=== SSD Write Benchmark (Agg $aggregationFactor:1) ===")
      println(s"NANDs: $totalNands, Queue Depth: $queueDepth")

      // We expect roughly 1 NAND Op for every 48 User Ops
      // Running 100,000 user ops (approx 2080 NAND ops)
      val targetOps = 100000L

      var startTime = System.nanoTime()
      var startSimTime = simTime()

      while (dut.completedCount.toLong < targetOps) {
        dut.systemClk.waitSampling(1000)
        if (
          dut.completedCount.toLong % 100 == 0 && dut.completedCount.toLong > 0
        ) {
          println(
            s"[${simTime()}] Completed: ${dut.completedCount.toLong} / $targetOps"
          )
        }
      }

      var endTime = System.nanoTime()
      var endSimTime = simTime()

      val durationMs = (endTime - startTime) / 1e6
      val simDurationPs = endSimTime - startSimTime
      val ops = dut.completedCount.toLong

      println(s"\n--- Write Benchmark Results ---")
      println(s"Total User Ops: $ops")
      println(s"Real Time: $durationMs ms")
      println(s"Sim Time: ${simDurationPs / 1e9} sec")

      val flowRate = (simDurationPs / 1e9) / (durationMs / 1000.0)
      println(f"Flow Rate: ${flowRate * 1000}%.2f ms (Sim) / sec (Real)")

      val engineSpeedMHz = (simDurationPs / 1000.0) / (durationMs * 1000.0)
      println(f"Engine Speed: $engineSpeedMHz%.2f MHz")
    }
}
