package assap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

/**
  * Delays packets for a fixed number of cycles.
  * Connects to input and output channels provided in the constructor.
  */
class PerfDelayLine[T](val name: String, inputCh: PerfFifo[T], outputCh: PerfFifo[T], val latency: Int) extends SimComponent {
  val input = new PerfIn[T]
  val output = new PerfOut[T]
  
  // Auto-bind ports
  input.bind(inputCh)
  output.bind(outputCh)
  
  override def run(cd: ClockDomain): Unit = {
    fork {
      while(true) {
        val pkt = input.read()
        if (latency > 0) {
          cd.waitSampling(latency)
        }
        output.write(pkt)
      }
    }
  }
}