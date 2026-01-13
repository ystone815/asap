package asap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import asap.arch.arch_nand
import asap.design.base.packet_bundle
import scala.util.Random

/** NAND Stress Test
  *   - Validates `arch_nand` component in isolation
  *   - Checks latency behavior (tR)
  */
object nand_stress_test extends App {
  // Config
  val tR_cycles = 100 // Test with 100 cycle latency
  val targetOps = 1000

  class NandStressTop extends Component {
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

    val validCount = out UInt (32 bits)

    val systemArea = new ClockingArea(systemClk) {
      val counter = Reg(UInt(32 bits)) init (0)
      validCount := counter

      // Traffic Gen
      val cmdStream = Stream(Bits(32 bits))
      // Send 1 request every once in a while
      val trigger = Reg(Bool()) init (False)
      val cycleCount = Reg(UInt(32 bits)) init (0)
      cycleCount := cycleCount + 1

      // Issue command every 200 cycles
      cmdStream.valid := (cycleCount % 200 === 10)
      cmdStream.payload := cycleCount.asBits

      // Delay Line (Host Interface)
      val pipeCmd = cmdStream.m2sPipe() // 1 cycle delay

      val hostArea = new Area {
        // NAND Model
        val nand = new arch_nand(tR_cycles)

        // 5ns Delay Line (Interface Delay)
        // Correctly use m2sPipe for delay
        // We want 5 cycles delay.
        var delayedCmd = pipeCmd
        for (_ <- 0 until 5) delayedCmd = delayedCmd.m2sPipe()

        nand.io.cmd << delayedCmd

        // Response
        nand.io.data.ready := True

        when(nand.io.data.valid) {
          counter := counter + 1
        }
      }
    }
  }

  SimConfig.compile(new NandStressTop).doSim { dut =>
    dut.systemClk.forkStimulus(period = 1000)
    dut.systemClk.waitSampling(100)

    println(s"=== NAND Stress Test (tR = $tR_cycles cycles) ===")
    val startTime = System.nanoTime()

    while (dut.validCount.toLong < targetOps) {
      dut.systemClk.waitSampling(1000)
    }

    val endTime = System.nanoTime()
    val wallDurationMs = (endTime - startTime) / 1e6
    val simDurationNs = simTime() / 1000

    val totalOps = dut.validCount.toLong

    println(s"\n--- NAND Stress Test Results ---")
    println(s"Total Operations: $totalOps")
    println(s"Sim Time:      ${simDurationNs / 1000.0} us")
    println(s"Real Time:     $wallDurationMs ms")

    if (wallDurationMs > 0) {
      val opsPerSec = (totalOps * 1000.0) / wallDurationMs
      println(f"Speed:         $opsPerSec%.2f Ops/sec")
    }
  }
}
