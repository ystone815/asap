package assap.design.base

import spinal.core._

case class PacketBundle() extends Bundle {
  val addr = UInt(32 bits)
  val size = UInt(16 bits)
  val id   = UInt(16 bits)
  // destId, pType etc can be added
  // For simplicity, let's map essential fields
}
