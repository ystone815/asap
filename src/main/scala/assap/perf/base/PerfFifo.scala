package assap.perf.base

import scala.collection.mutable

/**
  * A standard FIFO buffer for performance modeling.
  * Handles push/pop and backpressure (full/empty).
  * @tparam T The type of data payload
  */
class PerfFifo[T](val name: String, val capacity: Int) extends SimComponent {
  private val queue = mutable.Queue[T]()
  private var droppedCount = 0

  def push(p: T): Boolean = {
    if (queue.size < capacity) {
      queue.enqueue(p)
      true
    } else {
      droppedCount += 1
      false // Drop or stall indication
    }
  }

  def pop(): Option[T] = {
    if (queue.nonEmpty) Some(queue.dequeue()) else None
  }

  def peek(): Option[T] = queue.headOption
  def isFull: Boolean = queue.size >= capacity
  def isEmpty: Boolean = queue.isEmpty
  def nonEmpty: Boolean = queue.nonEmpty
  def size: Int = queue.size

  override def step(): Unit = {} // Passive component
  override def reset(): Unit = {
    queue.clear()
    droppedCount = 0
  }
}