package assap.design

import spinal.core._

object AssapConfig {
  def spinal = SpinalConfig(
    targetDirectory = "generated/src/verilog",
    defaultConfigForClockDomains = ClockDomainConfig(
      resetKind = SYNC
    )
  )
}

object AssapVerilog {
  def apply[T <: Component](component: => T): SpinalReport[T] = {
    AssapConfig.spinal.generateVerilog(component)
  }
}
