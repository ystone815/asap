package assap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

/** Delays packets for a fixed number of time units. Connects directly to input
  * and output FIFOs.
  */
class PerfDelayLine[T](
    val name: String,
    input: PerfFifo[T],
    output: PerfFifo[T],
    val latency: Int
) extends SimComponent {

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
