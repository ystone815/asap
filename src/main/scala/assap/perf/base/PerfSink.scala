package assap.perf.base

import assap.perf.types.Packet

/**
  * A sink to consume packets and track stats.
  * @param timeProvider Function that returns the current simulation cycle
  */
class PerfSink(val name: String, sourceFifo: PerfFifo[Packet], timeProvider: () => Long) extends SimComponent {
  var receivedCount = 0
  var totalLatency = 0L

  override def step(): Unit = {
    if (sourceFifo.nonEmpty) {
      val pkt = sourceFifo.pop().get
      pkt.endTime = timeProvider()
      receivedCount += 1
      totalLatency += pkt.latency
    }
  }

  override def reset(): Unit = {
    receivedCount = 0
    totalLatency = 0
  }
}