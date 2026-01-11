package asap.examples

import spinal.core._
import spinal.core.sim._
import asap.design.asap_system

object asap_system_sim extends App {
  SimConfig.withWave.compile(new asap_system).doSim { dut =>
    dut.clockDomain.forkStimulus(period = 10)

    // Monitor
    var finished = false
    var cycle = 0
    while (!finished && cycle < 1000) {
      dut.clockDomain.waitSampling()
      cycle += 1
      if (dut.io.done.toBoolean) {
        finished = true
        println(s"Sim Finished at cycle $cycle")
        if (dut.io.error.toBoolean) {
          println("ERROR: Verif Failed")
          simFailure()
        } else {
          println("SUCCESS: Verif Passed")
        }
      }
    }
  }
}
