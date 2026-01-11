package asap.design.base

import spinal.core._
import spinal.lib._

/** A RAM-based Delay Line (FIFO-like) to simulate long pipeline latencies
  * efficiently.
  *
  * @param dataType
  *   The data type of the payload
  * @param latency
  *   The fixed latency in cycles (capacity of the RAM)
  */
class ram_delay_line[T <: Data](dataType: HardType[T], latency: Int)
    extends Component {
  val io = new Bundle {
    val input = slave Stream (dataType)
    val output = master Stream (dataType)
  }

  // To model a fixed pipeline delay of 'latency' cycles with full throughput:
  // We use a StreamFifo.
  // In a steady state (high load), the FIFO fills up and naturally provides 'latency' cycles of delay.
  // For 'Model Benchmarking' of massive parallelism, this is sufficient to model the resource usage
  // and data movement delay.

  // Note: SpinalHDL's StreamFifo automatically infers BlockRAM for large depths.
  val fifo = new StreamFifo(dataType, latency)

  io.input >> fifo.io.push
  io.output << fifo.io.pop
}
