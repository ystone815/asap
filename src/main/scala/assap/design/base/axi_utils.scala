package assap.design.base

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._

object axi_utils {

  /** Connects an Axi4 Master to an Axi4Shared Slave, handling address resizing
    * automatically. This is useful when connecting a full 32-bit/64-bit Bus to
    * a smaller On-Chip RAM.
    */
  implicit class axi4_rich(master: Axi4) {
    def drive(slave: Axi4Shared): Unit = {
      val masterShared = Axi4ToAxi4Shared(master)

      // ARW Channel (Read/Write Address)
      slave.arw.arbitrationFrom(masterShared.arw)

      // Manual assignment for ARW payload to skip 'addr' for resizing
      for ((name, slaveSignal) <- slave.arw.payload.elements) {
        if (name != "addr") {
          masterShared.arw.payload.elements.find(_._1 == name).foreach {
            case (_, masterSignal) =>
              slaveSignal := masterSignal
          }
        }
      }

      // Explicitly resize address
      slave.arw.payload.addr := masterShared.arw.payload.addr
        .resize(slave.config.addressWidth bits)

      // W Channel (Write Data)
      slave.w << masterShared.w

      // B Channel (Write Response)
      masterShared.b << slave.b

      // R Channel (Read Data)
      masterShared.r << slave.r
    }

    def drive(slave: Axi4): Unit = {
      // Connect AW Channel
      slave.aw.arbitrationFrom(master.aw)
      for ((name, slaveSignal) <- slave.aw.payload.elements) {
        if (name != "addr") {
          master.aw.payload.elements.find(_._1 == name).foreach {
            case (_, src) => slaveSignal := src
          }
        }
      }
      slave.aw.payload.addr := master.aw.payload.addr
        .resize(slave.config.addressWidth bits)

      // Connect W Channel
      slave.w << master.w

      // Connect B Channel
      master.b << slave.b

      // Connect AR Channel
      slave.ar.arbitrationFrom(master.ar)
      for ((name, slaveSignal) <- slave.ar.payload.elements) {
        if (name != "addr") {
          master.ar.payload.elements.find(_._1 == name).foreach {
            case (_, src) => slaveSignal := src
          }
        }
      }
      slave.ar.payload.addr := master.ar.payload.addr
        .resize(slave.config.addressWidth bits)

      // Connect R Channel
      master.r << slave.r
    }
  }
}
