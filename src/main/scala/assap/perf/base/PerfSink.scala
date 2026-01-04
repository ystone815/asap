package assap.perf.base

import assap.perf.types.Packet
import spinal.core.sim._

class PerfSink(val name: String, input: PerfFifo[Packet], override val trace: Boolean = false) extends SimComponent {
  var receivedCount = 0
  var totalLatency = 0L

  if (trace) {
    addTraceVar("received")
    addTraceVar("last_latency")
  }

  override def run(): Unit = {
    fork {
      while (true) {
        val pkt = input.read()
        pkt.endTime = currentTime
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
