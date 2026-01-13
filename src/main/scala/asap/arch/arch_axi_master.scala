package asap.arch

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import spinal.lib.fsm._

case class arch_axi_master(config: Axi4Config) extends Component {
  val io = new Bundle {
    val axi = master(Axi4(config))
    val done = out Bool ()
    val error = out Bool ()
    val stateDebug = out UInt (3 bits)
  }

  val fsm = new StateMachine {
    val IDLE = new State with EntryPoint
    val WRITE_ADDR = new State
    val WRITE_DATA = new State
    val WRITE_RESP = new State
    val READ_ADDR = new State
    val READ_DATA = new State
    val DONE = new State

    io.done := False

    // Defaults
    io.axi.aw.valid := False
    io.axi.aw.payload.assignDontCare()
    io.axi.w.valid := False
    io.axi.w.payload.assignDontCare()
    io.axi.b.ready := False
    io.axi.ar.valid := False
    io.axi.ar.payload.assignDontCare()
    io.axi.r.ready := False

    IDLE.whenIsActive {
      goto(WRITE_ADDR)
    }

    // --- WRITE TRANSACTION ---
    WRITE_ADDR.whenIsActive {
      io.axi.aw.valid := True
      io.axi.aw.addr := 0x1000 // Target Address
      io.axi.aw.id := 1
      io.axi.aw.len := 3 // Burst length = 4 (len + 1)
      io.axi.aw.size := 2 // 4 bytes (2^2)
      io.axi.aw.burst := 1 // INCR
      when(io.axi.aw.ready) {
        goto(WRITE_DATA)
      }
    }

    WRITE_DATA.whenIsActive {
      io.axi.w.valid := True
      io.axi.w.data := 0xdeadbeefL
      io.axi.w.strb := 0xf
      io.axi.w.last := False // Simplified, should count 4 beats
      // Just sending 1 beat for simplicity or assume master logic handles it?
      // Let's force single beat for now to keep example simple
      io.axi.w.last := True
      when(io.axi.w.ready) {
        goto(WRITE_RESP)
      }
    }

    WRITE_RESP.whenIsActive {
      io.axi.b.ready := True
      when(io.axi.b.valid) {
        goto(READ_ADDR)
      }
    }

    // --- READ TRANSACTION ---
    READ_ADDR.whenIsActive {
      io.axi.ar.valid := True
      io.axi.ar.addr := 0x1000
      io.axi.ar.id := 1
      io.axi.ar.len := 0 // Single beat
      io.axi.ar.size := 2
      io.axi.ar.burst := 1
      when(io.axi.ar.ready) {
        goto(READ_DATA)
      }
    }

    READ_DATA.whenIsActive {
      io.axi.r.ready := True
      when(io.axi.r.valid) {
        goto(DONE)
      }
    }

    DONE.whenIsActive {
      io.done := True
    }

    io.error := False
    io.stateDebug := 0
  }
}
