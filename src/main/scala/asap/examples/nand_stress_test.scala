package asap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import asap.design.simple_nand_model
import asap.design.base.packet_bundle
import scala.util.Random

/** Stress Test for 128 Parallel NAND Models + Delay Lines Clock: 1GHz (1ns) tR:
  * 20us (20,000 cycles) Delay: 5ns (5 cycles)
  */
object nand_stress_test extends App {
  val totalPlanes = 128
  val tR_us = 20
  val clkFreq = 1 GHz
  val tR_cycles = (tR_us * 1000) // 20us * 1000ns/us / 1ns = 20000 cycles
  val targetOpsPerPlane = 50 // Each plane does 50 ops (Total ~6400 ops)

  println(s"=== NAND Stress Test (Planes: $totalPlanes, tR: ${tR_us}us) ===")
  // Fix: use toDouble for HertzNumber
  println(s"Clock: ${clkFreq.toDouble / 1e6} MHz")
  println(s"tR Cycles: $tR_cycles")

  class Top extends Component {
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

    val done = out Bool ()
    val counter = out UInt (32 bits)

    val systemArea = new ClockingArea(systemClk) {
      // Create 128 Chains of [Delay -> NAND]
      val planes = for (i <- 0 until totalPlanes) yield new Area {
        // Input Generator (Always trying to issue command)
        val gen = new Component {
          val output = master Stream (Bits(32 bits))
          output.valid := True
          output.payload := i // Plane ID as data
        }

        // NAND Model
        val nand = new simple_nand_model(tR_cycles)

        // 5ns Delay Line (Interface Delay)
        // Correctly use m2sPipe for delay
        var delayedStream = gen.output
        for (_ <- 0 until 5) {
          delayedStream = delayedStream.m2sPipe()
        }

        delayedStream >> nand.io.cmd

        nand.io.data.ready := True
        val completed = Reg(UInt(32 bits)) init (0)
        when(nand.io.data.valid) {
          completed := completed + 1
        }
      }

      // Aggregate completion
      val totalCompleted = planes.map(_.completed).reduce(_ + _)
      counter := totalCompleted
      done := totalCompleted >= (totalPlanes * targetOpsPerPlane)
    }
  }

  SimConfig.compile(new Top).doSim { dut =>
    dut.systemClk.forkStimulus(period = 1000) // 1ns period
    dut.systemClk.waitSampling(100) // Wait for reset to complete

    println("Simulation started...")
    val startTime = System.nanoTime()

    var cycles = 0L
    // Polling done signal
    while (!dut.done.toBoolean) {
      dut.systemClk.waitSampling(1000) // Check every 1000 cycles (1us)
      cycles += 1000
    }

    val endTime = System.nanoTime()
    val wallDurationMs = (endTime - startTime) / 1e6
    val simDurationNs = cycles * 1 // 1 cycle = 1ns

    val totalOps = dut.counter.toLong

    println(s"\n--- NAND Stress Test Results ---")
    println(s"Total Operations: $totalOps")
    println(s"Sim Time:      ${simDurationNs / 1000.0} us")
    println(s"Wall Time:     $wallDurationMs ms")

    if (wallDurationMs > 0) {
      val opsPerSec = (totalOps * 1000.0) / wallDurationMs
      println(f"Sim Speed:     $opsPerSec%.2f ops/sec (End-to-end NAND Ops)")

      // Calculate Cycle Speed (How many clock cycles simulated per second)
      val cyclesPerSec = (cycles * 1000.0) / wallDurationMs
      println(
        f"Engine Speed:  ${cyclesPerSec / 1e6}%.2f MHz (Simulated Clock Speed)"
      )
    }
  }
}
