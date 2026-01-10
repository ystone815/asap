package assap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

class PerfRouter[T](
    val name: String,
    input: PerfFifo[T],
    outputs: Map[Int, PerfFifo[T]],
    getDest: T => Int
) extends SimComponent {

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
            println(
              s"[$name] Error: Invalid Dest ID $destId. Dropping packet $pkt"
            )
        }
      }
    }
  }
}
