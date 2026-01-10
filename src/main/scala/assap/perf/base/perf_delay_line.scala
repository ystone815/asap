package assap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

/** Delays packets for a fixed number of time units. Connects directly to input
  * and output FIFOs.
  */
class perf_delay_line[T](
    val name: String,
    input: perf_fifo[T],
    output: perf_fifo[T],
    val latency: Int
) extends sim_component {

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
