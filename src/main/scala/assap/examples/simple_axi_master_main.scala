package assap.examples

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import assap.design.simple_axi_master
import assap.design.base.assap_verilog

object simple_axi_master_main extends App {
  val axiConfig = Axi4Config(
    addressWidth = 32,
    dataWidth = 32,
    idWidth = 4
  )

  assap_verilog(new simple_axi_master(axiConfig))
}
