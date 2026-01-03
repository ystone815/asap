package assap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

/**
  * Round-Robin Arbiter.
  * Selects one packet from multiple input FIFOs and pushes to output.
  */
class PerfArbiter[T](val name: String, inputs: Seq[PerfFifo[T]], output: PerfFifo[T]) extends SimComponent {
  private var rrIndex = 0

  override def run(cd: ClockDomain): Unit = {
    fork {
      while (true) {
        var selected = false
        var checks = 0
        
        // Try to find a valid request
        while (!selected && checks < inputs.size) {
          val idx = (rrIndex + checks) % inputs.size
          val src = inputs(idx)

          if (src.nonEmpty) {
            // Found a candidate. Pop it (blocking if empty, but we checked nonEmpty so it's instant)
            val pkt = src.read(cd)
            
            // Push to output (blocking if full)
            output.write(pkt, cd)
            
            selected = true
            rrIndex = (idx + 1) % inputs.size
          }
          checks += 1
        }
        
        // If nothing selected, wait a cycle to avoid busy loop
        if (!selected) {
          cd.waitSampling()
        }
      }
    }
  }
}
