package assap.examples

import assap.perf.base._
import assap.perf.types.Packet

object PerfBaseExample extends App {
  var currentCycle: Long = 0
  
  // Time provider lambda
  val timeProvider = () => currentCycle

  println("=== Assap Performance Library Example ===")

  // 1. Instantiation
  // Input Queues (Explicit type parameter [Packet])
  val q1 = new PerfFifo[Packet]("Q1", 10)
  val q2 = new PerfFifo[Packet]("Q2", 10)

  // Generators
  val gen1 = new PerfPacketGenerator("Gen1", q1, srcId = 10, rate = 0.3, timeProvider)
  val gen2 = new PerfPacketGenerator("Gen2", q2, srcId = 20, rate = 0.3, timeProvider)

  // Intermediate Queue after Arbiter
  val qArb = new PerfFifo[Packet]("Q_Arb", 10)

  // Arbiter (Q1, Q2 -> Q_Arb)
  val arbiter = new PerfArbiter[Packet]("Arbiter", Seq(q1, q2), qArb)

  // Delay Line (5 cycles)
  val delayLine = new PerfDelayLine[Packet]("Delay5", latency = 5)

  // Output Queues for Router
  val qSinkA = new PerfFifo[Packet]("Q_SinkA", 100)
  val qSinkB = new PerfFifo[Packet]("Q_SinkB", 100)

  // Router (Q_Delay -> SinkA or SinkB)
  // Need to provide extraction function for destId
  val router = new PerfRouter[Packet](
    "Router", 
    delayLine.output, 
    Map(0 -> qSinkA, 1 -> qSinkB),
    getDest = (p: Packet) => p.destId // Extraction Lambda
  )

  // Sinks
  val sinkA = new PerfSink("SinkA", qSinkA, timeProvider)
  val sinkB = new PerfSink("SinkB", qSinkB, timeProvider)

  // 2. Simulation Loop
  val simCycles = 100
  println(s"Running simulation for $simCycles cycles...")

  for (i <- 0 until simCycles) {
    currentCycle = i.toLong
    
    // Step 1: Generators produce
    gen1.step()
    gen2.step()
    
    // Step 2: Arbiter moves Q1/Q2 -> Q_Arb
    arbiter.step()

    // Step 3: Move Q_Arb -> DelayLine (Manual Glue)
    if (qArb.nonEmpty) {
       val p = qArb.pop().get
       delayLine.push(p)
    }

    // Step 4: DelayLine internals
    delayLine.step()

    // Step 5: Router moves DelayLine.output -> Sink Queues
    router.step()

    // Step 6: Sinks consume
    sinkA.step()
    sinkB.step()
  }

  // 3. Report
  println("\n--- Simulation Results ---")
  println(s"SinkA: Received ${sinkA.receivedCount}, Avg Latency: ${if(sinkA.receivedCount>0) sinkA.totalLatency/sinkA.receivedCount else 0}")
  println(s"SinkB: Received ${sinkB.receivedCount}, Avg Latency: ${if(sinkB.receivedCount>0) sinkB.totalLatency/sinkB.receivedCount else 0}")
  
  println(s"Leftover in Q1: ${q1.size}")
  println(s"Leftover in Q2: ${q2.size}")
  println(s"Leftover in DelayLine Output: ${delayLine.output.size}")
}
