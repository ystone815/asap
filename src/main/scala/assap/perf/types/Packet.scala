package assap.perf.types

/**
  * Packet type definitions for performance modeling
  */
object PacketType extends Enumeration {
  type PacketType = Value
  val READ, WRITE, CONTROL, RESPONSE = Value
}

/**
  * A generic Packet structure for architecture-level simulation.
  *
  * @param id        Unique identifier for tracking
  * @param srcId     Source component ID
  * @param destId    Destination component ID
  * @param pType     Type of packet (Read, Write, etc.)
  * @param addr      Target address
  * @param size      Payload size in bytes
  * @param priority  QoS or priority level (default 0)
  * @param startTime Injection time (cycle or nanoseconds)
  */
case class Packet(
    id: Long,
    srcId: Int,
    destId: Int,
    pType: PacketType.Value,
    addr: Long,
    size: Int,
    priority: Int = 0,
    startTime: Long = 0,
    var endTime: Long = 0 // To be updated upon completion
) {
  def latency: Long = if (endTime > 0) endTime - startTime else 0
}
