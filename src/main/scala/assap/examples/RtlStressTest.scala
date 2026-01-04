package assap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import assap.perf.base._
import assap.perf.types.{Packet, PacketType}
import assap.design.RtlDelayLine
import assap.design.base.PacketBundle

object RtlStressTest extends App {
  val packetCount = 10000 
  
  println(s"=== ASSAP RTL Stress Test ($packetCount packets) ===")

  class Top extends Component {
    val dut = new RtlDelayLine(latency = 16) // Sufficient depth
    val input = slave(Stream(PacketBundle()))
    val output = master(Stream(PacketBundle()))
    
    dut.io.input << input
    dut.io.output >> output
  }

  SimConfig.withWave.compile(new Top).doSim { dut =>
    // Match Time Unit: 1 Cycle = 1000 Time Unit (1ns)
    dut.clockDomain.forkStimulus(period = 1000) 
    PerfVcdManager.init("rtl_trace.vcd")
    PerfVcdManager.start()

    val qGen = new PerfFifo[Packet]("QGen", 100, trace = false)
    val qSink = new PerfFifo[Packet]("QSink", 100, trace = false)
    
    val gen = new PerfPacketGenerator("Gen", output = qGen, srcId = 0, rate = 1.0, trace = false)
    val sink = new PerfSink("Sink", input = qSink, trace = false)
    
    gen.run()  // No arguments
    sink.run() // No arguments

    // SW -> HW (Driver)
    fork {
      while(true) {
        val pkt = qGen.read()
        
        dut.input.valid #= true
        dut.input.payload.addr #= pkt.addr
        dut.input.payload.size #= pkt.size
        dut.input.payload.id   #= pkt.id
        
        dut.clockDomain.waitSamplingWhere(dut.input.ready.toBoolean)
        
        dut.input.valid #= false
      }
    }

    // HW -> SW (Monitor)
    dut.output.ready #= true
    fork {
      while(true) {
        dut.clockDomain.waitSamplingWhere(dut.output.valid.toBoolean && dut.output.ready.toBoolean)
        
        val pkt = Packet(
          id = dut.output.payload.id.toLong,
          srcId = 0,
          destId = 0,
          pType = PacketType.WRITE,
          addr = dut.output.payload.addr.toLong,
          size = dut.output.payload.size.toInt,
          startTime = 0
        )
        qSink.write(pkt)
      }
    }

    val startTime = System.nanoTime()
    
    var cycles = 0
    val maxCycles = packetCount * 20
    
    while(sink.receivedCount < packetCount && cycles < maxCycles) {
      dut.clockDomain.waitSampling(1000)
      cycles += 1000
    }
    
    val endTime = System.nanoTime()
    val durationMs = (endTime - startTime) / 1e6
    
    PerfVcdManager.close()
    
    println(s"\n--- RTL Stress Test Results ---")
    println(s"Total Packets: ${sink.receivedCount}")
    println(s"Wall Time:     $durationMs ms")
    if (durationMs > 0) {
      val tput = (sink.receivedCount * 1000.0) / durationMs
      println(f"Throughput:    $tput%.2f packets/sec")
    }
  }
}