package assap.perf.base

/**
  * Round-Robin Arbiter.
  * Selects one packet from multiple input FIFOs and pushes to output.
  * @tparam T The type of data payload
  */
class PerfArbiter[T](val name: String, inputs: Seq[PerfFifo[T]], output: PerfFifo[T]) extends SimComponent {
  private var rrIndex = 0

  override def step(): Unit = {
    // Try to find a valid request starting from current RR index
    var selected = false
    var checks = 0
    
    // Check all inputs once
    while (!selected && checks < inputs.size) {
      val idx = (rrIndex + checks) % inputs.size
      val src = inputs(idx)

      if (src.nonEmpty && !output.isFull) {
        val pkt = src.pop().get
        output.push(pkt)
        selected = true
        // Update RR index for next cycle to be fair
        rrIndex = (idx + 1) % inputs.size
      }
      checks += 1
    }
  }

  override def reset(): Unit = {
    rrIndex = 0
  }
}