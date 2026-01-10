package assap.perf.base

import assap.perf.types.Packet
import spinal.core.sim._
import spinal.core.ClockDomain

class PerfSink(
    val name: String,
    input: PerfFifo[Packet],
    override val trace: Boolean = false
) extends SimComponent {
  var receivedCount = 0
  var totalLatency = 0L

  if (trace) {
    addTraceVar("received")
    addTraceVar("last_latency")
  }

  override def run(cd: ClockDomain): Unit = {
    fork {
      while (true) {
        val pkt = input.read()
        pkt.end_time = simTime()
        receivedCount += 1
        totalLatency += pkt.latency
        if (trace) {
          updateTraceVar("received", receivedCount)
          updateTraceVar("last_latency", pkt.latency)
        }
      }
    }
  }
}
