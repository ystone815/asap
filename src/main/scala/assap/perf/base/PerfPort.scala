package assap.perf.base

trait PerfChannel[T] {
  def write(data: T): Unit
  def read(): T
  def nonEmpty: Boolean // Added for probing
}

class PerfIn[T] {
  private var channel: Option[PerfChannel[T]] = None

  def bind(c: PerfChannel[T]): Unit = {
    channel = Some(c)
  }

  def read(): T = channel match {
    case Some(c) => c.read()
    case None => throw new Exception("PerfIn port not connected!")
  }
  
  def nonEmpty: Boolean = channel.exists(_.nonEmpty)
}

class PerfOut[T] {
  private var channel: Option[PerfChannel[T]] = None

  def bind(c: PerfChannel[T]): Unit = {
    channel = Some(c)
  }

  def write(data: T): Unit = {
    channel match {
      case Some(c) => c.write(data)
      case None => throw new Exception("PerfOut port not connected!")
    }
  }
  
  def >>(fifo: PerfFifo[T]): Unit = this.bind(fifo)
}

object PerfConnectionOps {
  implicit class FifoOps[T](fifo: PerfFifo[T]) {
    def >>(in: PerfIn[T]): Unit = in.bind(fifo)
  }
}