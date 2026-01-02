package assap.perf.base

import scala.util.Random
import assap.perf.types.{Packet, PacketType}

/**
  * A simple packet generator component.
  * @param timeProvider Function that returns the current simulation cycle
  */
class PerfPacketGenerator(val name: String, targetFifo: PerfFifo[Packet], srcId: Int, rate: Double, timeProvider: () => Long) extends SimComponent {
  val rand = new Random(srcId)
  var pCounter = 0

  override def step(): Unit = {
    // Generate packet based on rate probability
    if (rand.nextDouble() < rate && !targetFifo.isFull) {
      pCounter += 1
      // Randomly pick destId (0 or 1)
      val dest = if (rand.nextBoolean()) 1 else 0
      val pkt = Packet(
        id = (srcId.toLong * 1000000) + pCounter, // Unique ID encoding
        srcId = srcId,
        destId = dest,
        pType = PacketType.WRITE,
        addr = rand.nextInt(1000).toLong,
        size = 64,
        startTime = timeProvider() // Use provided time
      )
      targetFifo.push(pkt)
    }
  }

  override def reset(): Unit = { pCounter = 0 }
}