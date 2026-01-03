package assap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

/**
  * 1-to-N Router based on Destination ID.
  * Connects one input channel to multiple output channels based on routing table.
  */
class PerfRouter[T](val name: String, inputCh: PerfFifo[T], outputChs: Map[Int, PerfFifo[T]], getDest: T => Int) extends SimComponent {
  val input = new PerfIn[T]
  input.bind(inputCh)
  
  // Convert Map[Int, Fifo] to Map[Int, PerfOut]
  val outputs = outputChs.mapValues { ch =>
    val p = new PerfOut[T]
    p.bind(ch)
    p
  }
  
  override def run(cd: ClockDomain): Unit = {
    fork {
      while (true) {
        val pkt = input.read()
        
        cd.waitSampling() // Latency
        
        val destId = getDest(pkt)
        outputs.get(destId) match {
          case Some(outPort) =>
            outPort.write(pkt)
          case None =>
            println(s"[$name] Error: Invalid Dest ID $destId. Dropping packet $pkt")
        }
      }
    }
  }
}
