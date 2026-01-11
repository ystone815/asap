package asap.design

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import asap.design.base.asap_config

/** A simple DRAMC model:
  *   - Acts as AXI4 Slave
  *   - Simulates fixed read/write latency (tCAS/tRCD etc combined)
  *   - "Infinite Bank" assumption: can accept request every cycle if pipeline
  *     not full
  */
case class SimpleDramc(latencyCycles: Int = 100) extends Component {
  val io = new Bundle {
    val axi = slave(Axi4(asap_config.axiConfig))
  }

  // --- Write Path ---
  // Simple: Accept Write immediately, acknowledge after latency.
  // Ideally DRAM write is fire-and-forget for throughput, but we need B-channel response.

  // Handshake Logic
  io.axi.aw.ready := True // Always ready to buffer command (assuming deep internal queues in real DRAMC)
  io.axi.w.ready := True // Always ready to accept data

  // We need to correlate AW and W to generate B.
  // For simplicity, let's assume AW comes before W or same cycle.
  // We'll push Write Transactions into a FIFO and pop them after 'latency'.

  case class WriteCtx() extends Bundle {
    val id = UInt(asap_config.axiConfig.idWidth bits)
  }

  val writeFifo = StreamFifo(WriteCtx(), latencyCycles + 16)

  val awValid = io.axi.aw.valid
  val wValid = io.axi.w.valid
  val wLast = io.axi.w.last

  // We only push to FIFO when we have BOTH address and full data (last).
  // This is a simplification. Real DRAMC buffers separately.
  // Let's implement a simpler "Response Delay" model.

  // --- Write Response ---
  // Just use a delay line for the BID
  val rawB = Stream(WriteCtx())
  // Trigger when AW fires (assuming W follows rapidly), OR trigger on W.last?
  // AXI4 strict ordering: B must follow W.last.
  // Let's trigger on W.last & W.valid & W.ready.
  // But we need the ID from AW.

  // simplified: We assume strict ordering AW -> W.
  // Store AW ID in a FIFO. When W.last arrives, pop ID and start B-delay.
  val awIdFifo = StreamFifo(UInt(asap_config.axiConfig.idWidth bits), 64)
  awIdFifo.io.push.valid := io.axi.aw.fire
  awIdFifo.io.push.payload := io.axi.aw.id

  val bTrigger = Stream(WriteCtx())
  bTrigger.valid := io.axi.w.fire && io.axi.w.last
  bTrigger.id := awIdFifo.io.pop.payload
  awIdFifo.io.pop.ready := bTrigger.fire

  // Delay Line for B Response
  // Using FIFO for simplicity (Pipeline delay)
  val bDelayFifo = StreamFifo(WriteCtx(), latencyCycles + 2)
  bDelayFifo.io.push << bTrigger
  val bDelayed = bDelayFifo.io.pop

  io.axi.b.valid := bDelayed.valid
  io.axi.b.id := bDelayed.payload.id
  io.axi.b.resp := Axi4.resp.OKAY
  bDelayed.ready := io.axi.b.ready

  // --- Read Path ---
  // AR -> Latency -> R
  // Support pipelined AR.

  case class ReadCtx() extends Bundle {
    val id = UInt(asap_config.axiConfig.idWidth bits)
    val len = UInt(8 bits)
  }

  val arFifo = StreamFifo(ReadCtx(), 64)
  io.axi.ar.ready := arFifo.io.push.ready
  arFifo.io.push.valid := io.axi.ar.valid
  arFifo.io.push.payload.id := io.axi.ar.id
  arFifo.io.push.payload.len := io.axi.ar.len

  // Pop from AR FIFO and feed into Delay Line
  val rCmdPre = Stream(ReadCtx())
  rCmdPre << arFifo.io.pop

  val rDelayFifo = StreamFifo(ReadCtx(), latencyCycles + 2)
  rDelayFifo.io.push << rCmdPre
  val rCmdDelayed = rDelayFifo.io.pop

  // Expand burst
  // We need to generate 'len + 1' beats for each command.
  val beatCounter = Reg(UInt(8 bits)) init (0)
  val working = RegInit(False)
  val currentCtx = Reg(ReadCtx())

  rCmdDelayed.ready := !working

  io.axi.r.valid := False
  io.axi.r.data := B(0, 32 bits) // Dummy data
  io.axi.r.id := currentCtx.id
  io.axi.r.last := False
  io.axi.r.resp := Axi4.resp.OKAY

  when(!working) {
    when(rCmdDelayed.valid) {
      working := True
      currentCtx := rCmdDelayed.payload
      beatCounter := 0
    }
  } otherwise {
    io.axi.r.valid := True
    // Dummy Data Pattern: ID + Counter
    io.axi.r.data := (currentCtx.id ## beatCounter).resized

    when(io.axi.r.ready) {
      beatCounter := beatCounter + 1
      when(beatCounter === currentCtx.len) {
        io.axi.r.last := True
        working := False
        // Immediate check for next
        // Optimized: if rCmdDelayed valid, we could potentially reload immediately,
        // but let's stick to 1-cycle bubble for simplicity unless bottleneck.
      }
    }
  }
}
