package asap.tlm.base

import spinal.core.sim._
import spinal.core.ClockDomain

class tlm_router[T](
    val name: String,
    input: tlm_fifo[T],
    outputs: Map[Int, tlm_fifo[T]],
    getDest: T => Int
) extends tlm_component {

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
