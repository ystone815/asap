package assap.design

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import spinal.lib.fsm._

case class SimpleAxiMaster(config: Axi4Config) extends Component {
  val io = new Bundle {
    val axi = master(Axi4(config))
    val done = out Bool()
    val error = out Bool()
    val stateDebug = out UInt(3 bits)
  }

  // Default output values
  io.axi.aw.setIdle()
  io.axi.w.setIdle()
  io.axi.ar.setIdle()
  io.axi.b.ready := True
  io.axi.r.ready := True

  io.done := False
  io.error := False

  val writeData = Reg(UInt(32 bits)) init(0x12345678) allowUnsetRegToAvoidLatch
  val readCheck = Reg(UInt(32 bits)) init(0)
  val stateDebugReg = Reg(UInt(3 bits)) init(0)
  io.stateDebug := stateDebugReg

  // Handshake tracking registers
  val awDone = RegInit(False)
  val wDone = RegInit(False)

  val fsm = new StateMachine {
    val IDLE = new State with EntryPoint
    val WRITE = new State // Combined AW and W
    val WRITE_RESP = new State
    val READ_ADDR = new State
    val READ_DATA = new State
    val DONE = new State

    stateDebugReg := 0

    IDLE.whenIsActive {
      stateDebugReg := 0
      goto(WRITE)
    }

    WRITE.onEntry {
      awDone := False
      wDone := False
    }

    // --- WRITE TRANSACTION (AW & W in parallel) ---
    WRITE.whenIsActive {
      stateDebugReg := 1
      
      // Drive AW if not done
      io.axi.aw.valid := !awDone
      io.axi.aw.addr := 0x100
      io.axi.aw.id := 0
      io.axi.aw.len := 0
      io.axi.aw.size := 2
      io.axi.aw.burst := 1

      // Drive W if not done
      io.axi.w.valid := !wDone
      io.axi.w.data.assignFromBits(writeData.asBits)
      io.axi.w.strb := 0xF
      io.axi.w.last := True
      
      // Check for fires
      when(io.axi.aw.fire) { awDone := True }
      when(io.axi.w.fire)  { wDone := True }

      // Check completion (current fire OR previously done)
      val awFinished = awDone || io.axi.aw.fire
      val wFinished  = wDone || io.axi.w.fire

      when(awFinished && wFinished) {
        goto(WRITE_RESP)
      }
    }

    WRITE_RESP.whenIsActive {
      stateDebugReg := 3
      when(io.axi.b.valid) {
        goto(READ_ADDR)
      }
    }

    READ_ADDR.whenIsActive {
      stateDebugReg := 4
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
      stateDebugReg := 5
      when(io.axi.r.valid) {
        when(io.axi.r.data.asUInt =/= writeData) {
          io.error := True
        }
        goto(DONE)
      }
    }

    DONE.whenIsActive {
      stateDebugReg := 6
      io.done := True
    }
  }
}
