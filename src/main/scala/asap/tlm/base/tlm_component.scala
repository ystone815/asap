package asap.tlm.base

import spinal.core.sim._
import spinal.core.ClockDomain

/** Base trait for all performance simulation components.
  */
trait tlm_component {
  def name: String

  // Tracing support
  def trace: Boolean = false

  // Start the component's thread(s)
  def run(cd: ClockDomain): Unit

  protected def addTraceVar(varName: String): Unit = {
    if (trace) tlm_vcd_manager.register(name, varName, 32)
  }

  protected def updateTraceVar(varName: String, value: Long): Unit = {
    if (trace) tlm_vcd_manager.update(name, varName, value)
  }

  // Use absolute simulation time directly
  protected def currentTime: Long = simTime()
}
