package assap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

/**
  * 1-to-N Router based on Destination ID.
  */
class PerfRouter[T](val name: String, input: PerfFifo[T], routingTable: Map[Int, PerfFifo[T]], getDest: T => Int) extends SimComponent {
  override def run(cd: ClockDomain): Unit = {
    fork {
      while (true) {
        // Blocking read
        val pkt = input.read(cd)
        val destId = getDest(pkt)
        val dest = routingTable.get(destId)
        
        dest match {
          case Some(outQueue) =>
            // Blocking write
            outQueue.write(pkt, cd)
          case None =>
            // Drop
            println(s"[$name] Error: No route for Dest ID $destId. Dropping packet $pkt")
        }
      }
    }
  }
}
