package assap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

/**
  * Round-Robin Arbiter.
  * Connects multiple input channels to one output channel.
  */
class PerfArbiter[T](val name: String, inputChs: Seq[PerfFifo[T]], outputCh: PerfFifo[T]) extends SimComponent {
  val inputs = inputChs.map { ch =>
    val p = new PerfIn[T]
    p.bind(ch)
    p
  }
  
  val output = new PerfOut[T]
  output.bind(outputCh)
  
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
        
        cd.waitSampling()
      }
    }
  }
}