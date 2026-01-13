package asap.arch

import spinal.core._
import spinal.lib._

/** A simple Synthesizable NAND Model with configurable tR (Read Latency).
  * Operates on a Stream interface.
  */
case class arch_nand(tR_cycles: Int) extends Component {
  val io = new Bundle {
    val cmd = slave Stream (Bits(32 bits)) // Dummy Command
    val data = master Stream (Bits(32 bits)) // Read Data
  }

  // Behavior:
  // 1. Accept Cmd
  // 2. Wait tR
  // 3. Output Data

  // Implementation:
  // Use a StreamDelay (Pipe) or FIFO.
  // For large tR (20us = 20,000 cycles), pure registers are too heavy?
  // 32 bits * 20,000 ~ 640 Kbits. Large but synth tools might map to BRAM.
  // Verilator handles it fine.
  // But for better sim performance, maybe use a counter-based delay?

  // Counter Based Delay Logic:
  val busy = RegInit(False)
  val timer = Reg(UInt(32 bits))
  val storedCmd = Reg(Bits(32 bits))

  io.cmd.ready := !busy
  io.data.valid := False
  io.data.payload := storedCmd // Echo back the command (Address/Tag)

  when(!busy) {
    when(io.cmd.valid) {
      busy := True
      storedCmd := io.cmd.payload
      timer := tR_cycles
    }
  } otherwise {
    // Busy
    when(timer > 0) {
      timer := timer - 1
    } otherwise {
      // Done
      io.data.valid := True
      when(io.data.ready) {
        busy := False
      }
    }
  }
}
