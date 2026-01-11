package asap.perf.base

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import asap.perf.types.{Packet, PacketType}

class PerfComponentsSpec extends AnyFlatSpec with Matchers {

  // Helper to create a dummy packet
  def mkPacket(id: Int, dest: Int = 0) = Packet(
    id = id, srcId = 0, destId = dest, pType = PacketType.WRITE,
    addr = 0, size = 64
  )

  "PerfFifo" should "handle push and pop correctly" in {
    val fifo = new PerfFifo[Packet]("test_fifo", capacity = 2)
    
    fifo.isEmpty should be (true)
    
    // Push 1
    fifo.push(mkPacket(1)) should be (true)
    fifo.isEmpty should be (false)
    fifo.peek().get.id should be (1)
    
    // Push 2
    fifo.push(mkPacket(2)) should be (true)
    fifo.isFull should be (true)
    
    // Push 3 (Should fail/drop)
    fifo.push(mkPacket(3)) should be (false)
    
    // Pop 1
    fifo.pop().get.id should be (1)
    fifo.isFull should be (false)
    
    // Pop 2
    fifo.pop().get.id should be (2)
    fifo.isEmpty should be (true)
  }

  "PerfArbiter" should "perform round-robin arbitration" in {
    val q1 = new PerfFifo[Packet]("q1", 10)
    val q2 = new PerfFifo[Packet]("q2", 10)
    val out = new PerfFifo[Packet]("out", 10)
    
    val arb = new PerfArbiter[Packet]("arb", Seq(q1, q2), out)
    
    // Setup: q1 has [1, 3], q2 has [2]
    q1.push(mkPacket(1))
    q2.push(mkPacket(2))
    q1.push(mkPacket(3))
    
    // Cycle 1: Should pick from q1 (starts at index 0)
    arb.step()
    out.pop().get.id should be (1)
    
    // Cycle 2: Should pick from q2 (RR index moved)
    arb.step()
    out.pop().get.id should be (2)
    
    // Cycle 3: Should pick from q1 again
    arb.step()
    out.pop().get.id should be (3)
    
    // Cycle 4: Empty
    arb.step()
    out.isEmpty should be (true)
  }

  "PerfRouter" should "route packets based on destination function" in {
    val in = new PerfFifo[Packet]("in", 10)
    val out0 = new PerfFifo[Packet]("out0", 10)
    val out1 = new PerfFifo[Packet]("out1", 10)
    
    // Router logic: use packet's destId
    val router = new PerfRouter[Packet]("router", in, Map(0 -> out0, 1 -> out1), p => p.destId)
    
    // Push dest 0, dest 1, dest 0
    in.push(mkPacket(10, dest = 0))
    in.push(mkPacket(11, dest = 1))
    in.push(mkPacket(12, dest = 0))
    
    // Step 1: Route Pkt 10 -> Out0
    router.step()
    out0.pop().get.id should be (10)
    
    // Step 2: Route Pkt 11 -> Out1
    router.step()
    out1.pop().get.id should be (11)
    
    // Step 3: Route Pkt 12 -> Out0
    router.step()
    out0.pop().get.id should be (12)
  }
  
  "PerfDelayLine" should "delay packets by specified latency" in {
    val delay = new PerfDelayLine[Packet]("dly", latency = 2)
    
    // t=0: Push
    delay.push(mkPacket(1))
    
    // t=0 step: Current cycle 0 -> 1. (0+2=2) <= 1 ? False.
    delay.step()
    delay.output.isEmpty should be (true)
    
    // t=1 step: Current cycle 1 -> 2. (2) <= 2 ? True.
    delay.step()
    delay.output.nonEmpty should be (true)
    delay.output.pop().get.id should be (1)
  }
}
