package assap.design.base

import spinal.core._

object assap_config {
  def spinal = SpinalConfig(
    targetDirectory = "generated/src/verilog",
    defaultConfigForClockDomains = ClockDomainConfig(
      resetKind = SYNC
    )
  )
}

object assap_verilog {
  def apply[T <: Component](component: => T): SpinalReport[T] = {
    assap_config.spinal.generateVerilog(component)
  }
}
