package assap.perf.base

/**
  * Base trait for all performance simulation components.
  */
trait SimComponent {
  def name: String
  def step(): Unit // Called every cycle
  def reset(): Unit
}
