package asap.tlm.base

import spinal.core.sim._
import spinal.core.ClockDomain

class tlm_arbiter[T](
    val name: String,
    inputs: Seq[tlm_fifo[T]],
    output: tlm_fifo[T]
) extends tlm_component {
  private var rr_index = 0

  override def run(cd: ClockDomain): Unit = {
    fork {
      while (true) {
        var transferred = false
        var i = 0

        while (!transferred && i < inputs.size) {
          val idx = (rr_index + i) % inputs.size
          val src = inputs(idx)

          if (src.non_empty) {
            val pkt = src.read()
            output.write(pkt)
            rr_index = (idx + 1) % inputs.size
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
