package assap.perf.base

import scala.collection.mutable

/**
  * Delays packets for a fixed number of cycles.
  * Useful for modeling wire delay or pipeline stages.
  * @tparam T The type of data payload
  */
class PerfDelayLine[T](val name: String, val latency: Int) extends SimComponent {
  // A queue of (releaseTime, Data)
  private val timeline = mutable.Queue[(Long, T)]()
  private var currentCycle: Long = 0
  
  // Output buffer to hold ready packets
  val output = new PerfFifo[T](s"${name}_out", capacity = 100) 

  def push(p: T): Unit = {
    timeline.enqueue((currentCycle + latency, p))
  }

  override def step(): Unit = {
    currentCycle += 1
    // Move ready packets to output
    while (timeline.nonEmpty && timeline.head._1 <= currentCycle) {
      val (_, pkt) = timeline.dequeue()
      output.push(pkt) 
    }
  }

  override def reset(): Unit = {
    timeline.clear()
    output.reset()
    currentCycle = 0
  }
}