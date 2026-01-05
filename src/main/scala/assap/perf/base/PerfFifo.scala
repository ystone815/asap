package assap.perf.base

import scala.collection.mutable
import spinal.core.sim._

/**
  * A standard FIFO buffer for performance modeling.
  * Uses event-driven blocking (waitUntil) for efficient synchronization.
  */
class PerfFifo[T](val name: String, val capacity: Int, override val trace: Boolean = false) extends SimComponent {
  private val queue = mutable.Queue[T]()
  private var droppedCount = 0

  if (trace) {
    addTraceVar("size")
    addTraceVar("dropped")
  }

  def isFull: Boolean = queue.size >= capacity
  def isEmpty: Boolean = queue.isEmpty
  def nonEmpty: Boolean = queue.nonEmpty
  def size: Int = queue.size

  /**
    * Blocking Write: waits until space is available.
    */
  def write(data: T): Unit = {
    if (isFull) {
      waitUntil(!isFull)
    }
    queue.enqueue(data)
    if (trace) updateTraceVar("size", queue.size)
  }

  /**
    * Blocking Read: waits until data is available.
    */
  def read(): T = {
    if (isEmpty) {
      waitUntil(nonEmpty)
    }
    val data = queue.dequeue()
    if (trace) updateTraceVar("size", queue.size)
    data
  }

  override def run(): Unit = {
    if (trace) {
      updateTraceVar("size", 0)
      updateTraceVar("dropped", 0)
    }
  }
}