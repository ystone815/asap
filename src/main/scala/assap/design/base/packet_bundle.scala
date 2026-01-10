package assap.design.base

import spinal.core._

case class packet_bundle() extends Bundle {
  val addr = UInt(32 bits)
  val size = UInt(16 bits)
  val id = UInt(32 bits)
}
