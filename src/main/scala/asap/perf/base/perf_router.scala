package asap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

class perf_router[T](
    val name: String,
    input: perf_fifo[T],
    outputs: Map[Int, perf_fifo[T]],
    getDest: T => Int
) extends sim_component {

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
