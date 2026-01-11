package asap.examples

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import asap.design.simple_axi_master
import asap.design.base.asap_verilog

object simple_axi_master_main extends App {
  val axiConfig = Axi4Config(
    addressWidth = 32,
    dataWidth = 32,
    idWidth = 4
  )

  asap_verilog(new simple_axi_master(axiConfig))
}
