package assap.examples

import spinal.core._
import spinal.lib._

// Hardware definition
class BlinkingLed extends Component {
  val io = new Bundle {
    val led = out Bool ()
  }

  // Create a counter that counts up to 1000
  val counter = Reg(UInt(10 bits)) init (0)
  counter := counter + 1

  // Blink the led every time the counter overflows
  io.led := counter === 0
}

// Generate Verilog
object BlinkingLedMain extends App {
  import assap.design.base.AssapVerilog
  AssapVerilog(new BlinkingLed)
}
