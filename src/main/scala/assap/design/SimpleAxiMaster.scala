package assap.design

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import spinal.lib.fsm._

case class SimpleAxiMaster(config: Axi4Config) extends Component {
  val io = new Bundle {
    val axi = master(Axi4(config))
    val done = out Bool ()
    val error = out Bool ()
    val stateDebug = out UInt (3 bits)
  }

  // Default output values
  io.axi.aw.setIdle()
  io.axi.w.setIdle()
  io.axi.ar.setIdle()
  io.axi.b.ready := True
  io.axi.r.ready := True

  io.done := False
  io.error := False

  val write_data =
    Reg(UInt(32 bits)) init (0x12345678) allowUnsetRegToAvoidLatch
  val read_check = Reg(UInt(32 bits)) init (0)
  val state_debug_reg = Reg(UInt(3 bits)) init (0)
  io.stateDebug := state_debug_reg

  // Handshake tracking registers
  val aw_done = RegInit(False)
  val w_done = RegInit(False)

  val fsm = new StateMachine {
    val IDLE = new State with EntryPoint
    val WRITE = new State // Combined AW and W
    val WRITE_RESP = new State
    val READ_ADDR = new State
    val READ_DATA = new State
    val DONE = new State

    state_debug_reg := 0

    IDLE.whenIsActive {
      state_debug_reg := 0
      goto(WRITE)
    }

    WRITE.onEntry {
      aw_done := False
      w_done := False
    }

    // --- WRITE TRANSACTION (AW & W in parallel) ---
    WRITE.whenIsActive {
      state_debug_reg := 1

      // Drive AW if not done
      io.axi.aw.valid := !aw_done
      io.axi.aw.addr := 0x100
      io.axi.aw.id := 0
      io.axi.aw.len := 0
      io.axi.aw.size := 2
      io.axi.aw.burst := 1

      // Drive W if not done
      io.axi.w.valid := !w_done
      io.axi.w.data.assignFromBits(write_data.asBits)
      io.axi.w.strb := 0xf
      io.axi.w.last := True

      // Check for fires
      when(io.axi.aw.fire) { aw_done := True }
      when(io.axi.w.fire) { w_done := True }

      // Check completion (current fire OR previously done)
      val aw_finished = aw_done || io.axi.aw.fire
      val w_finished = w_done || io.axi.w.fire

      when(aw_finished && w_finished) {
        goto(WRITE_RESP)
      }
    }

    WRITE_RESP.whenIsActive {
      state_debug_reg := 3
      when(io.axi.b.valid) {
        goto(READ_ADDR)
      }
    }

    READ_ADDR.whenIsActive {
      state_debug_reg := 4
      io.axi.ar.valid := True
      io.axi.ar.addr := 0x100
      io.axi.ar.id := 0
      io.axi.ar.len := 0
      io.axi.ar.size := 2
      io.axi.ar.burst := 1

      when(io.axi.ar.ready) {
        goto(READ_DATA)
      }
    }

    READ_DATA.whenIsActive {
      state_debug_reg := 5
      when(io.axi.r.valid) {
        when(io.axi.r.data.asUInt =/= write_data) {
          io.error := True
        }
        goto(DONE)
      }
    }

    DONE.whenIsActive {
      state_debug_reg := 6
      io.done := True
    }
  }
}
