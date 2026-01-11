package asap.design.base

import spinal.core._

import spinal.lib.bus.amba4.axi._

object asap_config {
  def spinal = SpinalConfig(
    targetDirectory = "generated/src/verilog",
    defaultConfigForClockDomains = ClockDomainConfig(
      resetKind = SYNC
    )
  )

  val axiConfig = Axi4Config(
    addressWidth = 32,
    dataWidth = 32,
    idWidth = 4,
    useId = true,
    useRegion = false,
    useBurst = true,
    useLock = false,
    useCache = false,
    useSize = true,
    useQos = false,
    useLen = true,
    useLast = true,
    useResp = true,
    useProt = false,
    useStrb = true
  )
}

object asap_verilog {
  def apply[T <: Component](component: => T): SpinalReport[T] = {
    asap_config.spinal.generateVerilog(component)
  }
}
