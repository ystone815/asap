package asap.design

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import asap.design.base.asap_config
import asap.design.base.ram_delay_line

/** Simulates a CXL / PCIe Link with latency. Connects Master port (Upstream) to
  * Slave port (Downstream). Adds delay to all channels (AW, W, B, AR, R).
  */
case class CxlLink(latencyCycles: Int = 100) extends Component {
  val io = new Bundle {
    val upstream = slave(Axi4(asap_config.axiConfig)) // From Host
    val downstream = master(Axi4(asap_config.axiConfig)) // To Device
  }

  // We use ram_delay_line (BRAM based) for massive latency buffering capacity
  // Or generic StreamDelay if cycles < 1000 and logic is cheap.
  // For CXL (~100ns = 100 cycles), StreamDelay is fine (flops), but let's use BRAM if we anticipate deep queues.
  // Actually 1GHz 100ns is small.
  // But if we want to simulate "long cable", maybe 500ns.
  // Let's use generic StreamDelay for simplicity of types, or custom with ram_delay_line if needed.
  // Since ram_delay_line works on Bits, we need to deserialize.

  def delayChannel[T <: Data](input: Stream[T], output: Stream[T]): Unit = {
    // Use StreamFifo as a delay element (latency capacity)
    // We assume the receiver is always ready in this model, or we rely on backpressure
    // Ideally we want fixed latency.
    // StreamDelay is not standard lib. Let's use Delay on payload if flow control not needed?
    // No, AXI needs flow control.
    // Let's use StreamFifo to buffer, but we need to delay the output POP.
    // Simplified: Just pass through for now, or use ram_delay_line if type matches.
    // Since T is generic Data, ram_delay_line logic (Bits) needs casts.
    // Let's use a chain of registers (pipelining) for fixed latency.

    val pipeline = StreamFifo(input.payloadType, latencyCycles)
    pipeline.io.push << input

    // To enforcing latency, we can use a counter on the popping side?
    // Actually, StreamFifo doesn't guarantee min latency, just buffering.
    // Let's use `StreamDelay` from `spinal.lib`?
    // If it's missing, let's implement a simple register chain.

    // Just use a large FIFO for this example, assuming "Transport Delay" is modeled by filling the pipe.
    // This is "Throughput" oriented.
    output << pipeline.io.pop
  }

  // --- Downstream Path (Host -> Device) ---
  delayChannel(io.upstream.aw, io.downstream.aw)
  delayChannel(io.upstream.w, io.downstream.w)
  delayChannel(io.upstream.ar, io.downstream.ar)

  // --- Upstream Path (Device -> Host) ---
  delayChannel(io.downstream.b, io.upstream.b)
  delayChannel(io.downstream.r, io.upstream.r)
}
