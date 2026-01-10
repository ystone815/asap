package assap.perf.base

import scala.util.Random
import assap.perf.types.{Packet, PacketType}
import spinal.core.sim._
import spinal.core.ClockDomain

class PerfPacketGenerator(
    val name: String,
    output: PerfFifo[Packet],
    srcId: Int,
    rate: Double,
    override val trace: Boolean = false
) extends SimComponent {
  val rand = new Random(srcId)
  var pCounter = 0

  if (trace) addTraceVar("generated")

  override def run(cd: ClockDomain): Unit = {
    fork {
      while (true) {
        if (rand.nextDouble() < rate) {
          pCounter += 1
          val pkt = Packet(
            id = (srcId.toLong * 1000000) + pCounter,
            src_id = srcId,
            dest_id = if (rand.nextBoolean()) 1 else 0,
            p_type = PacketType.WRITE,
            addr = rand.nextInt(1000).toLong,
            size = 64,
            start_time = simTime()
          )
          output.write(pkt)
          if (trace) updateTraceVar("generated", pCounter)
        }
        cd.waitSampling()
      }
    }
  }
}
