package assap.perf.types

/** Packet type definitions for performance modeling
  */
object packet_type extends Enumeration {
  type packet_type = Value
  val READ, WRITE, CONTROL, RESPONSE = Value
}

/** A generic Packet structure for architecture-level simulation. Uses
  * snake_case for better readability and RTL alignment.
  *
  * @param id
  *   Unique identifier for tracking
  * @param src_id
  *   Source component ID
  * @param dest_id
  *   Destination component ID
  * @param p_type
  *   Type of packet (Read, Write, etc.)
  * @param addr
  *   Target address
  * @param size
  *   Payload size in bytes
  * @param priority
  *   QoS or priority level (default 0)
  * @param start_time
  *   Injection time (cycle or nanoseconds)
  */
case class packet(
    id: Long,
    src_id: Int,
    dest_id: Int,
    p_type: packet_type.Value,
    addr: Long,
    size: Int,
    priority: Int = 0,
    start_time: Long = 0,
    var end_time: Long = 0 // To be updated upon completion
) {
  def latency: Long = if (end_time > 0) end_time - start_time else 0
}
