package asap.perf.base

import scala.collection.mutable
import spinal.core.sim._
import spinal.core.ClockDomain

/** A standard FIFO buffer for performance modeling. Uses event-driven blocking
  * (waitUntil) for efficient synchronization.
  */
class perf_fifo[T](
    val name: String,
    val capacity: Int,
    override val trace: Boolean = false
) extends sim_component {
  private val queue = mutable.Queue[T]()
  private var dropped_count = 0

  if (trace) {
    addTraceVar("size")
    addTraceVar("dropped")
  }

  def is_full: Boolean = queue.size >= capacity
  def is_empty: Boolean = queue.isEmpty
  def non_empty: Boolean = queue.nonEmpty
  def size: Int = queue.size

  /** Blocking Write: waits until space is available.
    */
  def write(data: T): Unit = {
    if (is_full) {
      waitUntil(!is_full)
    }
    queue.enqueue(data)
    if (trace) updateTraceVar("size", queue.size)
  }

  /** Blocking Read: waits until data is available.
    */
  def read(): T = {
    if (is_empty) {
      waitUntil(non_empty)
    }
    val data = queue.dequeue()
    if (trace) updateTraceVar("size", queue.size)
    data
  }

  override def run(cd: ClockDomain): Unit = {
    if (trace) {
      updateTraceVar("size", 0)
      updateTraceVar("dropped", 0)
    }
  }
}
