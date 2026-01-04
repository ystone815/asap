package assap.design

import spinal.core._
import spinal.lib._
import assap.design.base.PacketBundle

class RtlDelayLine(latency: Int) extends Component {
  val io = new Bundle {
    val input = slave Stream(PacketBundle())
    val output = master Stream(PacketBundle())
  }

  // Pure RTL delay (Pipeline registers) -> Use FIFO for buffering
  io.output << io.input.queue(latency)
}
