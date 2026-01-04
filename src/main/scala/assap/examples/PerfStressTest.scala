package assap.examples

import spinal.core._
import spinal.core.sim._
import assap.perf.base._
import assap.perf.types.{Packet, PacketType}

object PerfStressTest extends App {
  val packetCount = 10000 // 10K packets
  
  println(s"=== Assap Performance Stress Test ($packetCount packets) ===")
  
  class Top extends Component {
    val io = new Bundle { val done = out Bool() }
    io.done := False
  }

  val compiled = SimConfig.compile(new Top)

  compiled.doSim { (dut: Top) =>
    // 1. Setup
    val q1 = new PerfFifo[Packet]("Q1", 100, trace = false)
    val q2 = new PerfFifo[Packet]("Q2", 100, trace = false)
    
    val gen = new PerfPacketGenerator("Gen", output = q1, srcId = 0, rate = 1.0, trace = false)
    val delay = new PerfDelayLine[Packet]("Delay", input = q1, output = q2, latency = 5000)
    val sink = new PerfSink("Sink", input = q2, trace = false)

    val components = Seq(gen, delay, sink)
    components.foreach(_.run())

    println("Initialization complete. Starting measurement...")
    val startTime = System.nanoTime()
    
    // 2. Main Loop
    var cycles = 0
    val maxCycles = packetCount * 20000 // Failsafe
    
    while(sink.receivedCount < packetCount && cycles < maxCycles) {
      // We are using sleep(1000) inside components, so we should wait in time units
      // However, dut.clockDomain.waitSampling uses Cycles. 
      // If we don't have a clock, we must use sleep()
      sleep(10000) // Advance 10ns
      cycles += 10000
    }
    
    val endTime = System.nanoTime()
    val durationMs = (endTime - startTime) / 1e6
    
    println(s"\n--- Stress Test Results ---")
    println(s"Total Packets: ${sink.receivedCount}")
    println(s"Sim Time:      $cycles ps")
    println(s"Wall Time:     $durationMs ms")
    if (durationMs > 0) {
      val tput = (sink.receivedCount * 1000.0) / durationMs
      println(f"Throughput:    $tput%.2f packets/sec")
    }
  }
}
