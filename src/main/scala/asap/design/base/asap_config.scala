package asap.design.base

import spinal.core._

object asap_config {
  def spinal = SpinalConfig(
    targetDirectory = "generated/src/verilog",
    defaultConfigForClockDomains = ClockDomainConfig(
      resetKind = SYNC
    )
  )
}

object asap_verilog {
  def apply[T <: Component](component: => T): SpinalReport[T] = {
    asap_config.spinal.generateVerilog(component)
  }
}
