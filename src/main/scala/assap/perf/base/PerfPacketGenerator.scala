package assap.perf.base

import scala.util.Random
import assap.perf.types.{Packet, PacketType}
import spinal.core.sim._
import spinal.core.ClockDomain

class PerfPacketGenerator(val name: String, targetFifo: PerfFifo[Packet], srcId: Int, rate: Double, override val trace: Boolean = false) extends SimComponent {
  val rand = new Random(srcId)
  var pCounter = 0

  if (trace) {
    addTraceVar("generated")
  }

  override def run(cd: ClockDomain): Unit = {
    // Fork a new simulation thread
    fork {
      while (true) {
        // Generate packet logic
        if (rand.nextDouble() < rate) {
          pCounter += 1
          val dest = if (rand.nextBoolean()) 1 else 0
          val pkt = Packet(
            id = (srcId.toLong * 1000000) + pCounter,
            srcId = srcId,
            destId = dest,
            pType = PacketType.WRITE,
            addr = rand.nextInt(1000).toLong,
            size = 64,
            startTime = currentCycle // Simulation time
          )
          
          // Blocking write (will wait if FIFO is full)
          targetFifo.write(pkt, cd)
          
          if (trace) updateTraceVar("generated", pCounter)
        }
        
        // Wait 1 cycle before next attempt (or multiple for rate control)
        cd.waitSampling()
      }
    }
  }
}
