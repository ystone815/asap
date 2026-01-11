package asap.examples

import spinal.core._
import spinal.core.sim._
import spinal.lib.bus.amba4.axi._

object axi_sram_sim extends App {
  SimConfig.withWave
    .compile {
      val dut = new simple_axi_sram(
        addressWidth = 32,
        dataWidth = 32,
        idWidth = 4,
        size = 4096
      )
      dut
    }
    .doSim { dut =>
      dut.clockDomain.forkStimulus(period = 10)

      // Manual AXI Driver (Simple)
      dut.io.axi.arw.valid #= false
      dut.io.axi.w.valid #= false
      dut.io.axi.r.ready #= true
      dut.io.axi.b.ready #= true

      dut.clockDomain.waitSampling(10)

      println("[Sim] Starting Write...")
      // Write 0x12345678 to Addr 0x100
      dut.io.axi.arw.payload.addr #= 0x100
      dut.io.axi.arw.payload.id #= 0
      dut.io.axi.arw.payload.len #= 0
      dut.io.axi.arw.payload.size #= 2
      dut.io.axi.arw.payload.burst #= 1
      dut.io.axi.arw.payload.write #= true
      dut.io.axi.arw.valid #= true

      dut.io.axi.w.payload.data #= 0x12345678
      dut.io.axi.w.payload.strb #= 0xf
      dut.io.axi.w.payload.last #= true
      dut.io.axi.w.valid #= true

      // Wait for Ready
      var arwDone = false
      var wDone = false

      // Safety Timeout
      var timeout = 0
      while ((!arwDone || !wDone) && timeout < 100) {
        if (dut.io.axi.arw.ready.toBoolean) {
          dut.io.axi.arw.valid #= false
          arwDone = true
        }
        if (dut.io.axi.w.ready.toBoolean) {
          dut.io.axi.w.valid #= false
          wDone = true
        }
        dut.clockDomain.waitSampling()
        timeout += 1
      }

      if (timeout >= 100) {
        println("[Sim] Connect Timeout! Possible Ready stuck.")
        simFailure()
      }

      println("[Sim] Write Request Sent. Waiting for response...")

      // Wait for B (Write Response)
      dut.clockDomain.waitSamplingWhere(dut.io.axi.b.valid.toBoolean)
      println("[Sim] Write Response Received.")

      dut.clockDomain.waitSampling(10)

      println("[Sim] Starting Read...")
      // Read from Addr 0x100
      dut.io.axi.arw.payload.addr #= 0x100
      dut.io.axi.arw.payload.write #= false
      dut.io.axi.arw.valid #= true

      dut.clockDomain.waitSamplingWhere(dut.io.axi.arw.ready.toBoolean)
      dut.io.axi.arw.valid #= false

      dut.clockDomain.waitSamplingWhere(dut.io.axi.r.valid.toBoolean)
      val readData = dut.io.axi.r.payload.data.toBigInt
      println(f"[Sim] Read Data: 0x$readData%x")

      assert(readData == 0x12345678, "Read data mismatch!")
      println("[Sim] Test Passed.")
    }
}
