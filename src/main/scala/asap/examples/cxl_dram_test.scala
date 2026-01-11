package asap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import asap.design._
import asap.design.base._
import asap.design.base.asap_config

object cxl_dram_test extends App {
  println("DEBUG: Object cxl_dram_test initialized")
  // Config
  val cxlLatencyNs = 100 // 100ns one-way
  val dramLatencyNs = 50 // 50ns access
  val clkFreq = 1 GHz

  // Cycles
  val cxlLatCycles = cxlLatencyNs // 1ns period
  val dramLatCycles = dramLatencyNs

  // Continuous Traffic Generator
  class LoopingTrafficGen(config: Axi4Config) extends Component {
    val io = new Bundle {
      val axi = master(Axi4(config))
      val doneCycle = out Bool () // Pulses high when a sequence completes
    }
    val inner = new simple_axi_master(config)
    io.axi <> inner.io.axi

    // Hack: Restart inner logic when it finishes?
    // simple_axi_master logic is FSM based.
    // Ideally we'd modify simple_axi_master to loop, but let's just create a quick FSM here if possible?
    // No, reusing simple_axi_master is hard if it stays in DONE.
    // Let's implement a fresh, simple state machine here for continuous read/write.
  }

  // Custom simple master that loops
  class BenchmarkMaster(config: Axi4Config) extends Component {
    val io = new Bundle {
      val axi = master(Axi4(config))
      val opsCount = out UInt (32 bits)
    }

    // Simple FSM: Write -> Read -> Repeat
    val fsm = new Area {
      import spinal.lib.fsm._

      val counter = Reg(UInt(32 bits)) init (0)
      io.opsCount := counter

      val writeCmd =
        Reg(Bool()) init (True) // Toggle between Write(True) and Read(False)

      val sm = new StateMachine {
        val IDLE = new State with EntryPoint
        val WRITE_CMD = new State
        val WRITE_DATA = new State
        val WRITE_RESP = new State
        val READ_CMD = new State
        val READ_RESP = new State

        IDLE.whenIsActive { goto(WRITE_CMD) }

        // WRITE : AW -> W -> B
        WRITE_CMD.whenIsActive {
          io.axi.aw.valid := True
          io.axi.aw.addr := 0x1000
          io.axi.aw.id := 0
          io.axi.aw.len := 0
          io.axi.aw.size := 2
          io.axi.aw.burst := 1
          when(io.axi.aw.ready) { goto(WRITE_DATA) }
        }

        WRITE_DATA.whenIsActive {
          io.axi.w.valid := True
          io.axi.w.data := B(0xcafebabeL, 32 bits)
          io.axi.w.strb := 0xf
          io.axi.w.last := True
          when(io.axi.w.ready) { goto(WRITE_RESP) }
        }

        WRITE_RESP.whenIsActive {
          io.axi.b.ready := True
          when(io.axi.b.valid) {
            counter := counter + 1
            goto(READ_CMD)
          }
        }

        // READ: AR -> R
        READ_CMD.whenIsActive {
          io.axi.ar.valid := True
          io.axi.ar.addr := 0x1000
          io.axi.ar.id := 0
          io.axi.ar.len := 0
          io.axi.ar.size := 2
          io.axi.ar.burst := 1
          when(io.axi.ar.ready) { goto(READ_RESP) }
        }

        READ_RESP.whenIsActive {
          io.axi.r.ready := True
          when(io.axi.r.valid && io.axi.r.last) {
            counter := counter + 1
            goto(WRITE_CMD) // Loop back
          }
        }
      }
    }

    // Defaults
    io.axi.aw.valid := False; io.axi.aw.payload.assignDontCare()
    io.axi.w.valid := False; io.axi.w.payload.assignDontCare()
    io.axi.ar.valid := False; io.axi.ar.payload.assignDontCare()
    io.axi.r.ready := False
    io.axi.b.ready := False
  }

  class Top extends Component {
    val systemClkConfig =
      ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH)
    val clk = in Bool ()
    val reset = in Bool ()
    val systemClk = ClockDomain(
      clk,
      reset,
      config = systemClkConfig,
      frequency = FixedFrequency(clkFreq)
    )

    val opsCount = out UInt (32 bits)

    val systemArea = new ClockingArea(systemClk) {
      // 1. Traffic Generator (Looping)
      val host = new BenchmarkMaster(asap_config.axiConfig)

      // 2. CXL Link
      val cxl = new CxlLink(latencyCycles = cxlLatCycles)

      // 3. DRAM Controller
      val dram = new SimpleDramc(latencyCycles = dramLatCycles)

      // Connections
      host.io.axi >> cxl.io.upstream
      cxl.io.downstream >> dram.io.axi

      // Output stats
      opsCount := host.io.opsCount
    }
  }

  SimConfig.compile(new Top).doSim { dut =>
    dut.systemClk.forkStimulus(period = 1000)
    dut.systemClk.waitSampling(100)

    println(s"=== CXL-DRAM System Benchmark ===")
    println(
      s"CXL Latency: ${cxlLatCycles}ns (One-way), DRAM Latency: ${dramLatCycles}ns"
    )
    println("Running continuous traffic...")

    val targetOps = 50000L
    var startTime = System.nanoTime()
    var startSimTime = simTime()

    while (dut.opsCount.toLong < targetOps) {
      dut.systemClk.waitSampling(1000)
      if (dut.opsCount.toLong % 10000 == 0 && dut.opsCount.toLong > 0) {
        // print(".")
      }
    }

    var endTime = System.nanoTime()
    var endSimTime = simTime()

    val durationMs = (endTime - startTime) / 1e6
    val simDurationPs = endSimTime - startSimTime
    val ops = dut.opsCount.toLong

    println(s"\n--- CXL Benchmark Results ---")
    println(s"Total Ops: $ops")
    println(s"Wall Time: $durationMs ms")
    println(s"Sim Time: ${simDurationPs / 1e9} sec")

    val flowRate = (simDurationPs / 1e9) / (durationMs / 1000.0)
    println(f"Flow Rate: ${flowRate * 1000}%.2f ms (Sim) / sec (Wall)")

    val engineSpeedMHz = (simDurationPs / 1000.0) / (durationMs * 1000.0)
    println(f"Engine Speed: $engineSpeedMHz%.2f MHz")

    val throughput = (ops * 1000.0) / durationMs
    println(f"Throughput: $throughput%.2f Ops/sec")
  }
}
