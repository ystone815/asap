package assap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib._
import assap.design.base.PacketBundle
import assap.design.RtlDelayLine

object RtlPureStressTest extends App {
  val targetPackets = 100000 
  
  println(s"=== ASSAP Pure RTL Stress Test ($targetPackets packets target) ===")

  // 1. Hardware Generator using LFSR
  class RtlGenerator extends Component {
    val io = new Bundle {
      val output = master Stream(PacketBundle())
    }
    val counter = Reg(UInt(32 bits)) init(0)
    
    io.output.valid := True
    io.output.payload.addr := counter
    io.output.payload.size := 64
    io.output.payload.id   := counter(15 downto 0)
    
    when(io.output.ready) {
      counter := counter + 1
    }
  }

  // 2. Hardware Sink
  class RtlSink extends Component {
    val io = new Bundle {
      val input = slave Stream(PacketBundle())
      val count = out UInt(32 bits)
    }
    val counter = Reg(UInt(32 bits)) init(0)
    io.input.ready := True
    
    when(io.input.valid) {
      counter := counter + 1
    }
    io.count := counter
  }

  // 3. Top Level Connection with Explicit ClockDomain
  class Top extends Component {
    // Define an explicit clock domain configuration
    val systemClkConfig = ClockDomainConfig(
      resetKind = SYNC,
      resetActiveLevel = HIGH
    )
    
    // Define ports for the clock domain
    val clk = in Bool()
    val reset = in Bool()
    
    // Create the ClockDomain object
    val systemClk = ClockDomain(
      clock = clk,
      reset = reset,
      config = systemClkConfig,
      frequency = FixedFrequency(1 GHz) // Explicit Frequency
    )
    
    // Expose counter for sim check
    val receiveCount = out(UInt(32 bits))

    // ALL Logic resides within this explicit ClockingArea
    val systemArea = new ClockingArea(systemClk) {
      val gen = new RtlGenerator()
      val delay = new RtlDelayLine(latency = 5)
      val sink = new RtlSink()
      
      gen.io.output >> delay.io.input
      delay.io.output >> sink.io.input
      
      receiveCount := sink.io.count
    }
  }

  // 4. Simulation
  SimConfig.compile(new Top).doSim {
    dut =>
    // Drive the explicit clock domain
    // Note: forkStimulus usually targets the component's default clock domain.
    // Here we must target 'dut.systemClk' specifically.
    
    dut.systemClk.forkStimulus(period = 1000) // 1GHz (1ns period)
    
    println("Simulation started...")
    val startTime = System.nanoTime()
    
    var count = 0L
    while(count < targetPackets) {
      dut.systemClk.waitSampling(1000) // Wait on specific clock
      count = dut.receiveCount.toLong
    }
    
    val endTime = System.nanoTime()
    val durationMs = (endTime - startTime) / 1e6
    
    println(s"\n--- Pure RTL Stress Test Results ---")
    println(s"Total Packets: $count")
    println(s"Wall Time:     $durationMs ms")
    if (durationMs > 0) {
      val tput = (count * 1000.0) / durationMs
      println(f"Throughput:    $tput%.2f packets/sec")
    }
  }
}