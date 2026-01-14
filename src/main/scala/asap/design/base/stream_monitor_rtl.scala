package asap.design.base

import spinal.core._
import spinal.lib._

/** Synthesizable Hardware Monitor for Stream[T]. Counts transactions in RTL to
  * avoid per-cycle simulation overhead.
  *
  * NOTE: Takes dataType purely for type signature compatibility if needed, but
  * only monitors control signals.
  */
case class stream_monitor_rtl[T <: Data](dataType: T) extends Component {
  val io = new Bundle {
    val valid = in Bool ()
    val ready = in Bool ()
    val txCount = out UInt (64 bits)
  }

  val counter = Reg(UInt(64 bits)) init (0)

  // Passive monitoring: increment when transaction occurs
  when(io.valid && io.ready) {
    counter := counter + 1
  }

  io.txCount := counter
}

object stream_monitor_rtl {
  // Utility to attach monitor to a stream inline
  def on[T <: Data](stream: Stream[T]): stream_monitor_rtl[T] = {
    // Pass the payload instance itself as the witness for type T
    val mon = stream_monitor_rtl(stream.payload)
    mon.setName(stream.getName() + "_monitor")

    // Tap signals
    mon.io.valid := stream.valid
    mon.io.ready := stream.ready
    mon
  }
}
