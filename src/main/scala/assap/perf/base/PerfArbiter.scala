package assap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

class PerfArbiter[T](
    val name: String,
    inputs: Seq[PerfFifo[T]],
    output: PerfFifo[T]
) extends SimComponent {
  private var rrIndex = 0

  override def run(cd: ClockDomain): Unit = {
    fork {
      while (true) {
        var transferred = false
        var i = 0

        while (!transferred && i < inputs.size) {
          val idx = (rrIndex + i) % inputs.size
          val src = inputs(idx)

          if (src.nonEmpty) {
            val pkt = src.read()
            output.write(pkt)
            rrIndex = (idx + 1) % inputs.size
            transferred = true
          }
          i += 1
        }

        // Arbitration Latency
        sleep(1000)
      }
    }
  }
}
