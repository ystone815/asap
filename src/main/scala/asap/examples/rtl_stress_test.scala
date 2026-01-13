package asap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import asap.tlm.base._
import asap.tlm.types.{packet, packet_type}
import asap.design.rtl_delay_line
import asap.design.base.packet_bundle

object rtl_stress_test extends App {
  val packetCount = 100000

  println(s"=== ASAP RTL Stress Test ($packetCount packets) ===")

  class Top extends Component {
    val dut = new rtl_delay_line(packet_bundle(), latency = 16)
    val input = slave(Stream(packet_bundle()))
    val output = master(Stream(packet_bundle()))

    dut.io.input << input
    dut.io.output >> output
  }

  SimConfig.compile(new Top).doSim { dut =>
    dut.clockDomain.forkStimulus(period = 1000)
    tlm_vcd_manager.init("rtl_trace.vcd")
    tlm_vcd_manager.start()

    val qGen = new tlm_fifo[packet]("QGen", 100, trace = false)
    val qSink = new tlm_fifo[packet]("QSink", 100, trace = false)

    val gen = new tlm_packet_generator(
      "Gen",
      output = qGen,
      srcId = 0,
      rate = 1.0,
      trace = false
    )
    val sink = new tlm_sink("Sink", input = qSink, trace = false)

    gen.run(dut.clockDomain)
    sink.run(dut.clockDomain)

    // SW -> HW (Driver)
    fork {
      while (true) {
        val pkt = qGen.read()

        dut.input.valid #= true
        dut.input.payload.addr #= pkt.addr
        dut.input.payload.size #= pkt.size
        dut.input.payload.id #= pkt.id

        dut.clockDomain.waitSamplingWhere(dut.input.ready.toBoolean)

        dut.input.valid #= false
      }
    }

    // HW -> SW (Monitor)
    dut.output.ready #= true
    fork {
      while (true) {
        dut.clockDomain.waitSamplingWhere(
          dut.output.valid.toBoolean && dut.output.ready.toBoolean
        )

        val pkt = packet(
          id = dut.output.payload.id.toLong,
          src_id = 0,
          dest_id = 0,
          p_type = packet_type.WRITE,
          addr = dut.output.payload.addr.toLong,
          size = dut.output.payload.size.toInt,
          start_time = 0
        )
        qSink.write(pkt)
      }
    }

    val startTime = System.nanoTime()

    var cycles = 0
    // Arbitrary timeout or cycle limit
    val maxCycles = packetCount * 20

    while (sink.receivedCount < packetCount && cycles < maxCycles) {
      dut.clockDomain.waitSampling(1000)
      cycles += 1000
    }

    val endTime = System.nanoTime()
    val durationMs = (endTime - startTime) / 1e6

    tlm_vcd_manager.close()

    println(s"\n--- RTL Stress Test Results ---")
    println(s"Total Packets: ${sink.receivedCount}")
    println(s"Real Time:     $durationMs ms")
    if (durationMs > 0) {
      val tput = (sink.receivedCount * 1000.0) / durationMs
      println(f"Throughput:    $tput%.2f packets/sec")
    }
  }
}
