package assap.perf.base

import scala.collection.mutable
import spinal.core.sim._
import spinal.core.ClockDomain

/**
  * Delays packets for a fixed number of cycles.
  */
class PerfDelayLine[T](val name: String, input: PerfFifo[T], output: PerfFifo[T], val latency: Int) extends SimComponent {
  // A queue of (releaseTime, Data)
  private val timeline = mutable.Queue[(Long, T)]()
  
  override def run(cd: ClockDomain): Unit = {
    // Thread 1: Ingress (Read -> Timeline)
    fork {
      while(true) {
        val pkt = input.read(cd) // Blocks until input available
        timeline.enqueue((currentCycle + latency, pkt))
      }
    }

    // Thread 2: Egress (Timeline -> Write)
    fork {
      while(true) {
        if (timeline.nonEmpty && timeline.head._1 <= currentCycle) {
          val (_, pkt) = timeline.dequeue()
          output.write(pkt, cd) // Blocks until output space available
        } else {
          cd.waitSampling() // Wait for time to pass or data to arrive
        }
      }
    }
  }
}