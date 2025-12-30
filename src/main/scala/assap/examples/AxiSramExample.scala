package assap.examples

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._

// A wrapper component for AXI4 Shared On-Chip RAM
// We use Axi4Shared interface which is slightly simpler than full Axi4
// as it shares the address channel for both read and write.
class SimpleAxiSram(
    addressWidth: Int,
    dataWidth: Int,
    idWidth: Int,
    size: BigInt
) extends Component {

  // Define AXI4 Configuration
  val axiConfig = Axi4Config(
    addressWidth = addressWidth,
    dataWidth = dataWidth,
    idWidth = idWidth
  )

  val io = new Bundle {
    // We expose standard Axi4 interface
    val axi = slave(Axi4(axiConfig))
    val arw_valid_debug = out Bool()
    val arw_ready_debug = out Bool()
  }

  // Use SpinalHDL's built-in Axi4SharedOnChipRam library
  val ram = new Axi4SharedOnChipRam(
    dataWidth = dataWidth,
    byteCount = size,
    idWidth = idWidth
  )

  io.arw_valid_debug := ram.io.axi.arw.valid
  io.arw_ready_debug := ram.io.axi.arw.ready

  // Use the implicit rich class from AxiUtils for easier connection
  import assap.design.AxiUtils._
  io.axi.drive(ram.io.axi)
}

object AxiSramMain extends App {
  import assap.design.AssapVerilog

  try {
    AssapVerilog(
      new SimpleAxiSram(
        addressWidth = 32,
        dataWidth = 32,
        idWidth = 4,
        size = 4096 // 4 KB
      )
    )
    println("Verilog generation successful!")
  } catch {
    case e: Throwable =>
      println("Error generating Verilog:")
      e.printStackTrace()
      System.exit(1)
  }
}
