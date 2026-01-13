package asap.tlm.base

import spinal.core.sim._
import spinal.core.ClockDomain

/** Delays packets for a fixed number of time units. Connects directly to input
  * and output FIFOs.
  */
class tlm_delay_line[T](
    val name: String,
    input: tlm_fifo[T],
    output: tlm_fifo[T],
    val latency: Int
) extends tlm_component {

  override def run(cd: ClockDomain): Unit = {
    fork {
      while (true) {
        val pkt = input.read()
        if (latency > 0) {
          sleep(latency)
        }
        output.write(pkt)
      }
    }
  }
}
