package assap.perf.base

import spinal.core.sim._

/**
  * Delays packets for a fixed number of time units.
  * Connects directly to input and output FIFOs.
  */
class PerfDelayLine[T](val name: String, input: PerfFifo[T], output: PerfFifo[T], val latency: Int) extends SimComponent {
  
  override def run(): Unit = {
    fork {
      while(true) {
        val pkt = input.read()
        if (latency > 0) {
          sleep(latency)
        }
        output.write(pkt)
      }
    }
  }
}