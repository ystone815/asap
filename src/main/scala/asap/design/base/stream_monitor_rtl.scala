package asap.design.base

import spinal.core._
import spinal.lib._

/** Synthesizable Hardware Monitor for Stream[T]. Counts transactions in RTL to
  * avoid per-cycle simulation overhead.
  *
  * NOTE: Takes dataType purely for type signature compatibility if needed, but
  * only monitors control signals.
  */
case class stream_monitor_rtl[T <: Data](dataType: T, logInterval: Int = 0)
    extends Component {
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

  // Periodic Logging (RTL-based)
  // If logInterval > 0, prints status every 'logInterval' cycles
  if (logInterval > 0) {
    val timer = Reg(UInt(32 bits)) init (0)
    timer := timer + 1
    when(timer === logInterval - 1) {
      timer := 0
      report(Seq("Sim Monitor: TxCount=", counter))
    }
  }
}

object stream_monitor_rtl {
  // Utility to attach monitor to a stream inline
  def on[T <: Data](
      stream: Stream[T],
      logInterval: Int = 0
  ): stream_monitor_rtl[T] = {
    // Pass the payload instance itself as the witness for type T
    val mon = stream_monitor_rtl(stream.payload, logInterval)
    mon.setName(stream.getName() + "_monitor")

    // Tap signals
    mon.io.valid := stream.valid
    mon.io.ready := stream.ready
    mon
  }
}
