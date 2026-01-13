package asap.arch

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import asap.design.base.asap_config

/** Simulates a CXL / PCIe Link with latency. Connects Master port (Upstream) to
  * Slave port (Downstream). Adds delay to all channels (AW, W, B, AR, R).
  */
case class arch_cxl_link(latencyCycles: Int = 100) extends Component {
  val io = new Bundle {
    val upstream = slave(Axi4(asap_config.axiConfig)) // From Host
    val downstream = master(Axi4(asap_config.axiConfig)) // To Device
  }

  // Helper utility to add delay to a Stream
  def addDelay[T <: Data](stream: Stream[T], cycles: Int): Stream[T] = {
    // Using StreamFifo + logic to simulate cable delay
    // Simple approach: StreamDelay (Valid Bubble insertion logic) causes synthesis overhead but good for sim.
    // Better for "Link": Pipe (Latency) but allow bubbles?
    // StreamDelay does exactly fixed latency.
    // StreamDelay(stream, cycles) -- Manually implement pipe chain for fixed latency
    var s = stream
    for (_ <- 0 until cycles) {
      s = s.m2sPipe()
    }
    return s
  }

  // 1. Downstream (Host -> Device)
  // AW
  io.downstream.aw << addDelay(io.upstream.aw, latencyCycles)
  // W
  io.downstream.w << addDelay(io.upstream.w, latencyCycles)
  // AR
  io.downstream.ar << addDelay(io.upstream.ar, latencyCycles)

  // 2. Upstream (Device -> Host)
  // B
  io.upstream.b << addDelay(io.downstream.b, latencyCycles)
  // R
  io.upstream.r << addDelay(io.downstream.r, latencyCycles)
}
