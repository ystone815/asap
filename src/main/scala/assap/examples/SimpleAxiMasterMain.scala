package assap.examples

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import assap.design.SimpleAxiMaster
import assap.design.base.AssapVerilog

object SimpleAxiMasterMain extends App {
  val axiConfig = Axi4Config(
    addressWidth = 32,
    dataWidth = 32,
    idWidth = 4
  )

  AssapVerilog(new SimpleAxiMaster(axiConfig))
}
