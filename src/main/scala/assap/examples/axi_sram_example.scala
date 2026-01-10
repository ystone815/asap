package assap.examples

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import assap.design.base._

// A simple AXI4 Shared SRAM customized for our test
class simple_axi_sram(
    addressWidth: Int,
    dataWidth: Int,
    idWidth: Int,
    size: BigInt
) extends Component {
  val axiConfig = Axi4Config(
    addressWidth = addressWidth,
    dataWidth = dataWidth,
    idWidth = idWidth
  )
  val io = new Bundle {
    val axi = slave(Axi4Shared(axiConfig))
    // Debug ports
    val arw_valid_debug = out Bool ()
    val arw_ready_debug = out Bool ()
  }

  // Create standard AXI4 Shared RAM
  val ram = Axi4SharedOnChipRam(
    dataWidth = dataWidth,
    byteCount = size,
    idWidth = idWidth
  )

  // Explicitly connect signals to avoid mismatches
  // Axi4SharedOnChipRam uses specific naming, so we connect carefully.
  // Actually, standard connect usually works for same config.

  // Directly connect the AXI slave port
  ram.io.axi << io.axi

  // Expose debug signals
  io.arw_valid_debug := io.axi.arw.valid
  io.arw_ready_debug := io.axi.arw.ready
}

object axi_sram_example extends App {
  val axiConfig = Axi4Config(
    addressWidth = 32,
    dataWidth = 32,
    idWidth = 4
  )

  assap_verilog(new simple_axi_sram(32, 32, 4, 4096))
}
