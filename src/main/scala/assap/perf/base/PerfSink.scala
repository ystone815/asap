package assap.perf.base

import assap.perf.types.Packet
import spinal.core.sim._
import spinal.core.ClockDomain

class PerfSink(val name: String, sourceFifo: PerfFifo[Packet], override val trace: Boolean = false) extends SimComponent {
  var receivedCount = 0
  var totalLatency = 0L

  if (trace) {
    addTraceVar("received")
    addTraceVar("last_latency")
  }

  override def run(cd: ClockDomain): Unit = {
    fork {
      while (true) {
        // Blocking read (will wait if FIFO is empty)
        val pkt = sourceFifo.read(cd)
        
        pkt.endTime = currentCycle
        val latency = pkt.latency
        
        receivedCount += 1
        totalLatency += latency
        
        if (trace) {
          updateTraceVar("received", receivedCount)
          updateTraceVar("last_latency", latency)
        }
        
        // Processing time? If sink is instant, we don't wait.
        // If sink takes time, add cd.waitSampling(delay) here.
      }
    }
  }
}
