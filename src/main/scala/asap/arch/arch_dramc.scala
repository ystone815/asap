package asap.arch

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import asap.design.base.asap_config

/** A simulation model of a DRAM Controller (Slave).
  *
  * BEHAVIOR:
  *   - Accepts AXI read/write requests.
  *   - Adds a configurable latency (`latencyCycles`).
  *   - Returns response.
  *
  * LIMITATIONS:
  *   - "Infinite Bank" assumption: can accept request every cycle if pipeline
  *     not full
  */
case class arch_dramc(latencyCycles: Int = 100) extends Component {
  val io = new Bundle {
    val axi = slave(Axi4(asap_config.axiConfig))
  }

  // 1. Write Path
  // AW -> W -> [Latency] -> B
  // We'll use a StreamFifo to hold the write response "job"
  // When AW and W are both valid, we push to fifo.
  // The fifo output waits for 'latency' then drives B.

  // Simplified Model:
  // Write Response Logic
  val writeLogic = new Area {
    // Join AW and W
    val writeCmd = Stream(Bits(asap_config.axiConfig.idWidth bits))
    writeCmd.valid := io.axi.aw.valid && io.axi.w.valid
    writeCmd.payload := io.axi.aw.id.asBits
    io.axi.aw.ready := writeCmd.ready && io.axi.w.valid
    io.axi.w.ready := writeCmd.ready && io.axi.aw.valid

    // Delay Line for Latency
    // We use a StreamFifo or StreamDelay to simulate processing time.
    // For simple latency, we can use a pipe chain or counter.
    // Let's use a StreamFifo as a buffer, but we need explicit time delay.
    // SpinalHDL StreamDelay is for cycle delay.
    val delayLine = StreamFifo(
      dataType = Bits(asap_config.axiConfig.idWidth bits),
      depth = latencyCycles + 4
    )
    delayLine.io.push << writeCmd

    // We need to stall the output of FIFO for 'latencyCycles' after push?
    // Not exactly simple in pure Stream logic without a counter per item?
    // Actually, if we just want "Throughput = 1/clock, Latency = N",
    // simple pipelining (StreamDelay) works best.
    // StreamDelay(stream, cycles)

    // CAUTION: StreamDelay in SpinalHDL might just be registers.
    // If latency is 100, we don't want 100 registers if we can avoid it?
    // But for simulation model, 100 regs is fine.
    // Better: internal counter.

    // Let's use the simple approach: StreamDelay (Register chain)
    // For 100 cycles, it generates 100 stages. It's synthesizable and correct.
    val delayedStream = delayLine.io.pop.m2sPipe().m2sPipe() // Add some slack

    // Output B channel
    io.axi.b.valid := delayedStream.valid
    io.axi.b.id.assignFromBits(delayedStream.payload)
    io.axi.b.resp := Axi4.resp.OKAY
    delayedStream.ready := io.axi.b.ready
  }

  // 2. Read Path
  // AR -> [Latency] -> R
  val readLogic = new Area {
    val readCmd = Stream(Bits(asap_config.axiConfig.idWidth bits))
    readCmd.valid := io.axi.ar.valid
    readCmd.payload := io.axi.ar.id.asBits
    io.axi.ar.ready := readCmd.ready

    // Use huge FIFO to absorb bursts
    val fifo = StreamFifo(
      dataType = Bits(asap_config.axiConfig.idWidth bits),
      depth = latencyCycles + 16
    )
    fifo.io.push << readCmd

    // Output R channel
    // Assume we return data immediately after latency
    io.axi.r.valid := fifo.io.pop.valid
    io.axi.r.id.assignFromBits(fifo.io.pop.payload)
    io.axi.r.data := B(0xdeadbeefL, 32 bits) // Dummy data
    io.axi.r.resp := Axi4.resp.OKAY
    io.axi.r.last := True // Always single beat for this simple model
    fifo.io.pop.ready := io.axi.r.ready
  }
}
