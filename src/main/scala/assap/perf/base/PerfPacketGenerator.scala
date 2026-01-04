package assap.perf.base

import scala.util.Random
import assap.perf.types.{Packet, PacketType}
import spinal.core.sim._

class PerfPacketGenerator(val name: String, output: PerfFifo[Packet], srcId: Int, rate: Double, override val trace: Boolean = false) extends SimComponent {
  val rand = new Random(srcId)
  var pCounter = 0

  if (trace) addTraceVar("generated")

  override def run(): Unit = {
    fork {
      while (true) {
        if (rand.nextDouble() < rate) {
          pCounter += 1
          val pkt = Packet(
            id = (srcId.toLong * 1000000) + pCounter,
            srcId = srcId,
            destId = if (rand.nextBoolean()) 1 else 0,
            pType = PacketType.WRITE,
            addr = rand.nextInt(1000).toLong,
            size = 64,
            startTime = currentTime // Absolute Time
          )
          output.write(pkt)
          if (trace) updateTraceVar("generated", pCounter)
        }
        sleep(1000) // Wait 1 time unit
      }
    }
  }
}
