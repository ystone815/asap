# Gemini Project Context & Memories

This file stores the design philosophy, coding conventions, and lessons learned for the `assap` project.

## Core Design Philosophy

1.  **Hardware-First Verification:**
    *   Prefer implementing a **Synthesizable Hardware Master** (e.g., `SimpleAxiMaster`) to drive the DUT.
    *   This ensures the testbench itself is closer to the real hardware environment.

2.  **Performance Modeling Layers (`assap.perf`):**
    *   **Generic Components:** Use `[T]` type parameters for infrastructure components (`Fifo`, `Arbiter`, `DelayLine`) to ensure reusability.
    *   **Separation:** Keep data definitions (`types`) separate from logic (`base`).
    *   **SimComponent:** All perf components should extend `SimComponent` and implement `step()` and `reset()`.

3.  **AXI4 Handling (`assap.design`):**
    *   **Handshake Safety:** When designing Masters, use independent or parallel assertion of `AW` and `W` valid signals to avoid deadlocks with strict slaves.
    *   **Connection:** Use `AxiUtils.drive(slave: Axi4)` for direct AXI4-to-AXI4 connections with automatic address resizing.

4.  **Testing Strategy:**
    *   **Unit Tests:** Use `ScalaTest` in `src/test/scala` for logic verification. Do not pollute production code with tests.
    *   **Simulation:** Use `examples` folder for integration level simulation (both RTL and Perf).

## Lessons Learned & Gotchas

*   **AXI Interconnect Deadlocks:**
    *   A Master that waits for `AW.ready` before asserting `W.valid` can deadlock if the Slave (or Interconnect/Converter) waits for `W.valid` before asserting `AW.ready`.
    *   **Fix:** Assert both `AW.valid` and `W.valid` independently or in parallel in the Master FSM.

*   **Performance Simulation Timing:**
    *   In cycle-based models (`step()`), the order of time increment vs. logic processing matters.
    *   For `DelayLine`, incrementing current time **before** checking the timeline correctly models "N-cycle delay" (where N=1 means available next cycle). Incrementing after results in N-1 delay.

*   **SpinalSim & Reset:**
    *   `forkStimulus` asserts reset for ~100 cycles. Always `waitSampling(100)` or check `!isResetActive` before checking simulation results to avoid reading initialization states.

## Directory Structure Strategy
*   `src/main/scala/assap/design/base`: Synthesizable common libs.
*   `src/main/scala/assap/perf/base`: Generic performance modeling libs (individual files per class).
*   `src/main/scala/assap/perf/types`: Shared data structures.
*   `src/test/scala`: Unit tests mirroring the main package structure.