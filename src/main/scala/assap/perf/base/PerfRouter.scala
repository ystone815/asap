package assap.perf.base

/**
  * 1-to-N Router based on Destination ID.
  * Routes packets from input to one of the outputs map.
  * @tparam T The type of data payload
  * @param getDest A function to extract destination ID from the payload
  */
class PerfRouter[T](val name: String, input: PerfFifo[T], routingTable: Map[Int, PerfFifo[T]], getDest: T => Int) extends SimComponent {
  override def step(): Unit = {
    if (input.nonEmpty) {
      val pkt = input.peek().get
      val destId = getDest(pkt)
      val dest = routingTable.get(destId)
      
      dest match {
        case Some(outQueue) =>
          if (!outQueue.isFull) {
            input.pop() // Consume from input
            outQueue.push(pkt)
          }
          // Else: Stall (Head of Line blocking)
        case None =>
          // Drop or log error for unroutable packet
          // Since T is generic, we rely on toString for logging
          println(s"[$name] Error: No route for Dest ID $destId. Dropping packet $pkt")
          input.pop()
      }
    }
  }

  override def reset(): Unit = {}
}