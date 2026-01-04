package assap.perf.base

import spinal.core.sim._

class PerfRouter[T](val name: String, input: PerfFifo[T], outputs: Map[Int, PerfFifo[T]], getDest: T => Int) extends SimComponent {
  
  override def run(): Unit = {
    fork {
      while (true) {
        val pkt = input.read()
        
        sleep(1000) // Routing Latency
        
        val destId = getDest(pkt)
        outputs.get(destId) match {
          case Some(outQueue) =>
            outQueue.write(pkt)
          case None =>
            println(s"[$name] Error: Invalid Dest ID $destId. Dropping packet $pkt")
        }
      }
    }
  }
}