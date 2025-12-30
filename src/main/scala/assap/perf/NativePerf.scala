package assap.perf

import spinal.core._
import spinal.lib._
import spinal.core.sim._

// 1. Simple Native Interface Definition
case class NativeConfig(addrWidth: Int = 32, dataWidth: Int = 32)

case class NativeCmd(c: NativeConfig) extends Bundle {
  val addr = UInt(c.addrWidth bits)
  val data = UInt(c.dataWidth bits) // Write Data
  val we   = Bool()                 // Write Enable
}

case class NativeBus(c: NativeConfig) extends Bundle with IMasterSlave {
  val cmd = Stream(NativeCmd(c))
  val rsp = Stream(UInt(c.dataWidth bits)) // Read Data Response

  override def asMaster(): Unit = {
    master(cmd)
    slave(rsp)
  }
}

// 2. Simple Traffic Generator
case class NativeGenConfig(
  nativeConfig: NativeConfig,
  writeRatio: Double = 0.5,
  locality: Double = 0.8
)

class NativeTrafficGenerator(c: NativeGenConfig) extends Component {
  val io = new Bundle {
    val bus = master(NativeBus(c.nativeConfig))
    val enable = in Bool()
    // Counters
    val totalTxns = out UInt(32 bits)
  }

  val lfsr = Reg(UInt(32 bits)) init(0x13579BDF)
  val feedback = lfsr(31) ^ lfsr(21) ^ lfsr(1) ^ lfsr(0)
  when(io.enable) {
    lfsr := (lfsr |<< 1) | feedback.asUInt.resize(32)
  }

  // Parameters mapped to integer thresholds (0-100 scale)
  val writeThresh = (c.writeRatio * 100).toInt
  val localThresh = (c.locality * 100).toInt
  val rnd100 = lfsr(6 downto 0) // approx 0-127

  val isWrite = rnd100 < writeThresh
  val isSeq   = lfsr(13 downto 7) < localThresh

  // Logic
  val addrReg = Reg(UInt(c.nativeConfig.addrWidth bits)) init(0)
  val counter = Reg(UInt(32 bits)) init(0)

  // Command Generation
  io.bus.cmd.valid := io.enable
  io.bus.cmd.we    := isWrite
  io.bus.cmd.addr  := addrReg
  io.bus.cmd.data  := lfsr.resize(c.nativeConfig.dataWidth) // Random data

  // Next Address Logic
  when(io.bus.cmd.fire) {
    counter := counter + 1
    when(isSeq) {
      addrReg := addrReg + 4
    } otherwise {
      addrReg := (lfsr(15 downto 0) << 2).resize(c.nativeConfig.addrWidth)
    }
  }

  // Response Handling (Just consume it)
  io.bus.rsp.ready := True

  io.totalTxns := counter
}

// 3. Simple Memory (Slave)
class NativeMemory(c: NativeConfig, size: Int) extends Component {
  val io = new Bundle {
    val bus = slave(NativeBus(c))
  }

  val mem = Mem(UInt(c.dataWidth bits), size / 4)

  // Command Processing
  io.bus.cmd.ready := True // Always ready for simplicity
  
  val rdata = mem.readSync(
    address = (io.bus.cmd.addr >> 2).resize(log2Up(size/4)),
    enable  = io.bus.cmd.fire && !io.bus.cmd.we
  )
  
  when(io.bus.cmd.fire && io.bus.cmd.we) {
    mem.write(
      address = (io.bus.cmd.addr >> 2).resize(log2Up(size/4)),
      data    = io.bus.cmd.data
    )
  }

  // Response (1 cycle latency due to readSync)
  // We need to valid signal for read response.
  // Since we accept every cycle, we pipe the read request valid to response valid
  val rspValid = RegNext(io.bus.cmd.fire && !io.bus.cmd.we) init(False)
  
  io.bus.rsp.valid := rspValid
  io.bus.rsp.payload := rdata
}

// 4. Top Level Simulation
class NativePerfSystem extends Component {
  val config = NativeConfig(32, 32)
  val genConfig = NativeGenConfig(config, writeRatio = 0.5)

  val gen = new NativeTrafficGenerator(genConfig)
  val mem = new NativeMemory(config, 1024)

  mem.io.bus.cmd << gen.io.bus.cmd
  gen.io.bus.rsp << mem.io.bus.rsp
  
  val io = new Bundle {
    val enable = in Bool()
    val totalTxns = out UInt(32 bits)
  }
  
  gen.io.enable := io.enable
  io.totalTxns := gen.io.totalTxns
}

object NativePerfSim extends App {
  SimConfig.withWave.compile(new NativePerfSystem).doSim { dut =>
    dut.clockDomain.forkStimulus(period = 10)
    
    dut.io.enable #= false
    dut.clockDomain.waitSampling(10)
    
    println("Start Native Traffic...")
    dut.io.enable #= true
    
    // Run 200 cycles
    for(i <- 0 until 200) {
      dut.clockDomain.waitSampling()
    }
    
    dut.io.enable #= false
    dut.clockDomain.waitSampling(10)
    
    println(s"Total Transactions: ${dut.io.totalTxns.toLong}")
  }
}
