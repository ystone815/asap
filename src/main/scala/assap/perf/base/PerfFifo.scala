package assap.perf.base

import scala.collection.mutable
import spinal.core.sim._
import spinal.core.ClockDomain

/**
  * A standard FIFO buffer for performance modeling.
  * Supports blocking read/write for SimPy-style interaction.
  * @tparam T The type of data payload
  */
class PerfFifo[T](val name: String, val capacity: Int, override val trace: Boolean = false) extends SimComponent {
  private val queue = mutable.Queue[T]()
  private var droppedCount = 0

  if (trace) {
    addTraceVar("size")
    addTraceVar("dropped")
  }

  // Non-blocking ops
  def isFull: Boolean = queue.size >= capacity
  def isEmpty: Boolean = queue.isEmpty
  def nonEmpty: Boolean = queue.nonEmpty
  def size: Int = queue.size

  // --- Blocking API (SimPy style) ---
  
  /**
    * Writes data to FIFO. Blocks if full.
    */
  def write(data: T, cd: ClockDomain): Unit = {
    while (isFull) {
      cd.waitSampling()
    }
    queue.enqueue(data)
    if (trace) updateTraceVar("size", queue.size)
  }

  /**
    * Reads data from FIFO. Blocks if empty.
    */
  def read(cd: ClockDomain): T = {
    while (isEmpty) {
      cd.waitSampling()
    }
    val data = queue.dequeue()
    if (trace) updateTraceVar("size", queue.size)
    data
  }

  // FIFO usually doesn't have its own active thread, it's a resource.
  override def run(cd: ClockDomain): Unit = {
    if (trace) {
      updateTraceVar("size", 0)
      updateTraceVar("dropped", 0)
    }
  }
}