package assap.perf

import scala.collection.mutable.Queue

// A simple transaction class for performance modeling
case class Transaction(id: Int, timestamp: Long)

// A simple generator that produces transactions
class WorkloadGenerator(count: Int) {
  def generate(): Seq[Transaction] = {
    (1 to count).map(i => Transaction(i, System.nanoTime()))
  }
}

object PerfEntry extends App {
  println("Starting Performance Model Simulation...")
  val generator = new WorkloadGenerator(5)
  val transactions = generator.generate()
  
  transactions.foreach { t =>
    println(s"Generated transaction ID: ${t.id} at time ${t.timestamp}")
  }
  println("Simulation finished.")
}
