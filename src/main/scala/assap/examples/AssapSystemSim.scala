package assap.examples

import spinal.core._
import spinal.core.sim._
import assap.design.AssapSystem

object AssapSystemSim extends App {
  SimConfig.withWave.compile(new AssapSystem).doSim { dut =>
    dut.clockDomain.forkStimulus(period = 10)

    println("Simulation Start: Waiting for Reset...")
    // Wait enough time for reset to be asserted and then released.
    // forkStimulus default reset duration is 100 cycles? Actually usually 100 time units or so.
    // Let's check documentation or source. forkStimulus(period=10) toggles clock every 5 units.
    // It asserts reset for 100 cycles usually.
    
    dut.clockDomain.waitSampling(100) // Wait for reset to finish + some cycles
    
    val doneStart = dut.io.done.toBoolean
    val stateStart = dut.io.stateDebug.toInt
    println(f"Check after wait: Done=$doneStart, State=$stateStart")

    var cycles = 0
    val timeout = 1000 

    // Monitor
    fork {
      while(true) {
        dut.clockDomain.waitSampling(100)
        // ... logging ...
      }
    }

    while (!dut.io.done.toBoolean && cycles < timeout) {
      dut.clockDomain.waitSampling()
      cycles += 1
    }

    if (cycles >= timeout) {
      println(f"TIMEOUT: Master stuck at state ${dut.io.stateDebug.toInt}")
      simFailure()
    } else {
      if (dut.io.error.toBoolean) {
        println("FAILURE: Master reported data mismatch error.")
        simFailure()
      } else {
        println(s"SUCCESS: Master finished correctly in $cycles cycles (after initial wait).")
        println(f"Final State: ${dut.io.stateDebug.toInt}")
      }
    }
  }
}