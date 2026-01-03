package assap.perf.base

import spinal.core.sim._
import spinal.core.ClockDomain

/**
  * Base trait for all performance simulation components.
  */
trait SimComponent {
  def name: String
  
  // Tracing support
  def trace: Boolean = false
  
  // Start the component's thread(s)
  def run(cd: ClockDomain): Unit

  protected def addTraceVar(varName: String): Unit = {
    if (trace) PerfVcdManager.register(name, varName, 32)
  }
  
  protected def updateTraceVar(varName: String, value: Long): Unit = {
    if (trace) PerfVcdManager.update(name, varName, value)
  }
  
  // Helper to get cycle count (Assuming period=10)
  protected def currentCycle: Long = simTime() / 10
}
