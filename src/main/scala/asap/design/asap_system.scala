package asap.design

import spinal.core._
import spinal.lib.bus.amba4.axi._
import asap.examples.simple_axi_sram
import asap.arch.arch_axi_master

// Note: simple_axi_sram is in examples package.

class asap_system extends Component {
  val io = new Bundle {
    val done = out Bool ()
    val error = out Bool ()
    val stateDebug = out UInt (3 bits)
    val sram_arw_valid = out Bool ()
    val sram_arw_ready = out Bool ()
    val master_aw_valid = out Bool ()
    val master_aw_ready = out Bool ()
  }

  // 1. Configs
  val axiConfig = Axi4Config(
    addressWidth = 32,
    dataWidth = 32,
    idWidth = 4
  )

  // 2. Instantiate Components
  val master = arch_axi_master(axiConfig)
  val sram = new simple_axi_sram(
    addressWidth = 32,
    dataWidth = 32,
    idWidth = 4,
    size = 4096 // 4 KB
  )

  // 3. Connect Master to Slave using our Utility
  import asap.design.base.axi_utils._
  master.io.axi.drive(sram.io.axi)

  // 4. Map outputs
  io.done := master.io.done
  io.error := master.io.error
  io.stateDebug := master.io.stateDebug

  // Debug connections
  io.sram_arw_valid := sram.io.arw_valid_debug
  io.sram_arw_ready := sram.io.arw_ready_debug
  io.master_aw_valid := master.io.axi.aw.valid
  io.master_aw_ready := master.io.axi.aw.ready
}

object asap_system_main extends App {
  SpinalConfig(targetDirectory = "generated/src/verilog")
    .generateVerilog(new asap_system)
}
