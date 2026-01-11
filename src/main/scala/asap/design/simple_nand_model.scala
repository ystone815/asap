package asap.design

import spinal.core._
import spinal.lib._

/** A simple Synthesizable NAND Model with configurable tR (Read Latency).
  * Operates on a Stream interface.
  */
class simple_nand_model(tR_cycles: Int) extends Component {
  val io = new Bundle {
    val cmd = slave Stream (Bits(32 bits)) // Dummy Command
    val data = master Stream (Bits(32 bits)) // Read Data
  }

  // State Machine
  object State extends SpinalEnum {
    val IDLE, BUSY, TRANSFER = newElement
  }
  val state = RegInit(State.IDLE)
  val timer = Reg(UInt(32 bits)) init (0)

  // Default Outputs
  io.cmd.ready := False
  io.data.valid := False
  io.data.payload := B(BigInt("DEADBEEF", 16), 32 bits) // Dummy Data

  switch(state) {
    is(State.IDLE) {
      io.cmd.ready := True
      when(io.cmd.valid) {
        state := State.BUSY
        timer := 0
      }
    }

    is(State.BUSY) {
      timer := timer + 1
      when(timer >= tR_cycles) {
        state := State.TRANSFER
      }
    }

    is(State.TRANSFER) {
      io.data.valid := True
      when(io.data.ready) {
        state := State.IDLE
      }
    }
  }
}
