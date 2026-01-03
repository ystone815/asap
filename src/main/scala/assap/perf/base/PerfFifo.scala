package assap.perf.base

import scala.collection.mutable
import spinal.core.sim._
import spinal.core.ClockDomain

/**
  * A standard FIFO buffer acting as a Channel between ports.
  */
class PerfFifo[T](val name: String, val capacity: Int, override val trace: Boolean = false) extends SimComponent with PerfChannel[T] {
  private val queue = mutable.Queue[T]()
  private var droppedCount = 0
  private var cd: ClockDomain = null

  if (trace) {
    addTraceVar("size")
    addTraceVar("dropped")
  }

  def isFull: Boolean = queue.size >= capacity
  def isEmpty: Boolean = queue.isEmpty
  def nonEmpty: Boolean = queue.nonEmpty
  def size: Int = queue.size

  override def write(data: T): Unit = {
    // If cd is not set yet (e.g. static init), we can't block properly.
    // Assuming run() is called before any traffic.
    while (isFull) {
      if (cd != null) cd.waitSampling() else Thread.sleep(1) // Fallback safety
    }
    queue.enqueue(data)
    if (trace) updateTraceVar("size", queue.size)
  }

  override def read(): T = {
    while (isEmpty) {
      if (cd != null) cd.waitSampling() else Thread.sleep(1)
    }
    val data = queue.dequeue()
    if (trace) updateTraceVar("size", queue.size)
    data
  }

  override def run(clockDomain: ClockDomain): Unit = {
    this.cd = clockDomain
    if (trace) {
      updateTraceVar("size", 0)
      updateTraceVar("dropped", 0)
    }
  }
}