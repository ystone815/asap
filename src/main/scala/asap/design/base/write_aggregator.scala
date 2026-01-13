package asap.design.base

import spinal.core._
import spinal.lib._

/** Aggregates N commands into 1, and expands 1 response into N. Used to model
  * Write Buffer aggregation (e.g., 4KB -> 192KB).
  */
class write_aggregator(aggregationFactor: Int, dataType: HardType[Bits])
    extends Component {
  val io = new Bundle {
    val cmdIn = slave Stream (dataType)
    val cmdOut = master Stream (dataType) // To NAND (1 aggregated op)

    val rspIn = slave Stream (dataType) // From NAND (1 op completion)
    val rspOut = master Stream (dataType) // To Host (N user completions)
  }

  // --- Command Aggregation Path ---
  // Consume 'aggregationFactor' inputs. Only the last one triggers an output.
  // Packets 0 to N-2 are acknowledged immediately.
  // Packet N-1 is forwarded to cmdOut.

  val cmdCounter = Reg(UInt(log2Up(aggregationFactor) bits)) init (0)
  val isFullBatch = cmdCounter === (aggregationFactor - 1)

  io.cmdIn.ready := False
  io.cmdOut.valid := False
  io.cmdOut.payload := io.cmdIn.payload

  when(!isFullBatch) {
    // Phase 1: Absorb inputs until we have enough
    io.cmdIn.ready := True
    when(io.cmdIn.valid) {
      cmdCounter := cmdCounter + 1
    }
  } otherwise {
    // Phase 2: Forward the last input as the "Aggregated Command"
    io.cmdOut.valid := io.cmdIn.valid

    // ready propagates back
    io.cmdIn.ready := io.cmdOut.ready

    when(io.cmdOut.fire) {
      cmdCounter := 0
    }
  }

  // --- Response Expansion Path ---
  // Receive 1 response from NAND, generate 'aggregationFactor' responses to Host.

  val rspCounter = Reg(UInt(log2Up(aggregationFactor) bits)) init (0)
  val rspPayload = Reg(dataType)
  val active = RegInit(False)

  // Input Side (From NAND)
  io.rspIn.ready := !active

  when(!active) {
    when(io.rspIn.valid) {
      active := True
      rspPayload := io.rspIn.payload
      rspCounter := 0
    }
  }

  // Output Side (To Host)
  io.rspOut.valid := active
  io.rspOut.payload := rspPayload

  when(active) {
    when(io.rspOut.fire) {
      rspCounter := rspCounter + 1
      when(rspCounter === (aggregationFactor - 1)) {
        active := False
      }
    }
  }
}
