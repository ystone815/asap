package assap.design

import spinal.core._
import spinal.lib._

/** A generic RTL delay line (FIFO-based) for any Data type.
  * @tparam T
  *   The payload data type
  * @param payloadType
  *   The hardware type generator (e.g. HardType(UInt(32 bits)))
  * @param latency
  *   The number of cycles to delay (depth of FIFO)
  */
class rtl_delay_line[T <: Data](payloadType: HardType[T], latency: Int)
    extends Component {
  val io = new Bundle {
    val input = slave Stream (payloadType())
    val output = master Stream (payloadType())
  }

  // Use FIFO for simple pipeline delay with backpressure support
  io.output << io.input.queue(latency)
}
