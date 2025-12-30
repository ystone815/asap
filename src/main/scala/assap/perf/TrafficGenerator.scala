package assap.perf

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import spinal.lib.fsm._

// Configuration parameters for the generator
case class TrafficConfig(
    axiConfig: Axi4Config,
    startAddress: BigInt = 0x0000,
    endAddress: BigInt = 0x1000,
    writeRatioPercent: Int = 50, // 0 to 100
    localityPercent: Int = 80, // 0 (Fully Random) to 100 (Fully Sequential)
    maxBurstSize: Int = 4 // 1 to 16
)

class TrafficGenerator(config: TrafficConfig) extends Component {
  val io = new Bundle {
    val axi = master(Axi4(config.axiConfig))
    val enable = in Bool()
    val done = out Bool()
    val writeCount = out UInt (32 bits)
    val readCount = out UInt (32 bits)
  }

  // --- Random Number Generator (LFSR) ---
  val lfsr = Reg(UInt(32 bits)) init (0x12345678)
  val feedback = lfsr(31) ^ lfsr(21) ^ lfsr(1) ^ lfsr(0)
  when(io.enable) {
    lfsr := (lfsr |<< 1) | feedback.asUInt.resize(32)
  }

  val rnd100 = lfsr(6 downto 0) 
  val isWrite = rnd100 < config.writeRatioPercent
  val rndLocality = lfsr(13 downto 7)
  val isSequential = rndLocality < config.localityPercent

  // --- State Registers ---
  val currentAddr = Reg(UInt(config.axiConfig.addressWidth bits)) init (config.startAddress)
  val burstLen = Reg(UInt(8 bits))
  val writeCounter = Reg(UInt(32 bits)) init (0)
  val readCounter = Reg(UInt(32 bits)) init (0)
  val txnData = Reg(UInt(config.axiConfig.dataWidth bits)) init (0)

  io.writeCount := writeCounter
  io.readCount := readCounter
  io.done := False

  // Defaults
  io.axi.aw.setIdle()
  io.axi.w.setIdle()
  io.axi.ar.setIdle()
  io.axi.b.ready := True
  io.axi.r.ready := True

  // Handshake tracking for Write
  val awDone = RegInit(False)
  val wDone = RegInit(False)

  // --- Main State Machine ---
  val fsm = new StateMachine {
    val IDLE = new State with EntryPoint
    val PREPARE = new State
    val WRITE = new State
    val WRITE_RESP = new State
    val READ_ADDR = new State
    val READ_DATA = new State

    IDLE.whenIsActive {
      when(io.enable) {
        goto(PREPARE)
      }
    }

    PREPARE.whenIsActive {
      when(isSequential) {
        currentAddr := currentAddr + 4
        when(currentAddr >= config.endAddress) {
          currentAddr := config.startAddress
        }
      } .otherwise {
        currentAddr := (lfsr(20 downto 0) << 2).resize(config.axiConfig.addressWidth)
      }

      burstLen := 0 

      when(isWrite) {
        txnData := lfsr.resize(config.axiConfig.dataWidth)
        goto(WRITE)
      } otherwise {
        goto(READ_ADDR)
      }
    }

    WRITE.onEntry {
      awDone := False
      wDone := False
    }

    WRITE.whenIsActive {
      // AW Logic
      io.axi.aw.valid := !awDone
      io.axi.aw.addr := currentAddr
      io.axi.aw.id := 0
      io.axi.aw.len := burstLen
      io.axi.aw.size := 2 
      io.axi.aw.burst := 1 
      
      when(io.axi.aw.fire) { awDone := True }

      // W Logic
      io.axi.w.valid := !wDone
      io.axi.w.data := txnData.asBits
      io.axi.w.strb := 0xF
      io.axi.w.last := True 
      
      when(io.axi.w.fire) { wDone := True }

      // Check completion
      val awFinished = awDone || io.axi.aw.fire
      val wFinished = wDone || io.axi.w.fire
      
      when(awFinished && wFinished) {
        goto(WRITE_RESP)
      }
    }

    WRITE_RESP.whenIsActive {
      when(io.axi.b.valid) {
        writeCounter := writeCounter + 1
        goto(PREPARE) 
      }
    }

    // Read Path (Can keep sequential for now as AR is independent)
    READ_ADDR.whenIsActive {
      io.axi.ar.valid := True
      io.axi.ar.addr := currentAddr
      io.axi.ar.id := 0
      io.axi.ar.len := burstLen
      io.axi.ar.size := 2
      io.axi.ar.burst := 1

      when(io.axi.ar.ready) {
        goto(READ_DATA)
      }
    }

    READ_DATA.whenIsActive {
      when(io.axi.r.valid) {
        when(io.axi.r.last) {
          readCounter := readCounter + 1
          goto(PREPARE) 
        }
      }
    }
  }
}