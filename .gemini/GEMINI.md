# Gemini Project Context & Memories

This file stores the design philosophy, coding conventions, and lessons learned for the `assap` (Accelerated Samsung Solution Architecture Platform) project.

## Core Design Philosophy

1.  **Hardware-First Verification:**
    *   Prefer implementing a **Synthesizable Hardware Master** (e.g., `SimpleAxiMaster`) to drive the DUT.
    *   This ensures the testbench itself is closer to the real hardware environment.

2.  **Performance Modeling (`assap.perf`):**
    *   **SimPy / SystemC Style:** Adopt a **Process-Driven** approach using SpinalSim's `fork` and `waitSampling`.
    *   **Blocking I/O:** Components communicate via `PerfFifo` using blocking `read(cd)` and `write(data, cd)` methods. This simplifies logic by removing manual state polling (`step()`).
    *   **Mixed-Mode Ready:** The simulation environment runs on SpinalSim's `ClockDomain`, allowing seamless integration of **Software Models (Perf)** and **Hardware RTL (Design)** in the same simulation.
    *   **Generic Components:** Use `[T]` type parameters (`Fifo[T]`, `Arbiter[T]`) to ensure reusability for any transaction type (`Packet`, `Flit`, `AxiTrans`).

3.  **AXI4 Handling (`assap.design`):**
    *   **Handshake Safety:** When designing Masters, use independent or parallel assertion of `AW` and `W` valid signals to avoid deadlocks.
    *   **Connection:** Use `AxiUtils.drive(slave: Axi4)` for direct AXI4-to-AXI4 connections.

4.  **Testing Strategy:**
    *   **Unit Tests:** Use `ScalaTest` in `src/test/scala` for logic verification.
    *   **Simulation:** Use `examples` folder for integration level simulation.
    *   **VCD Tracing:** Use `PerfVcdManager` to generate VCD dumps for software models, making them viewable alongside RTL waveforms.

## Directory Structure Strategy
*   `src/main/scala/assap/design/base`: Synthesizable common libs.
*   `src/main/scala/assap/perf/base`: Generic performance modeling libs (individual files per class).
*   `src/main/scala/assap/perf/types`: Shared data structures.
*   `src/test/scala`: Unit tests mirroring the main package structure.

## Lessons Learned & Gotchas

*   **SpinalSim Timing:**
    *   `clockDomain.cycle` is not directly available in all contexts. Use a helper (e.g., `simTime() / period`) or maintain a local counter for VCD timestamping.
    *   Blocking I/O (`waitSampling`) inside `fork` creates efficient, non-busy-waiting threads.

*   **Latency Modeling:**
    *   In a cycle-accurate model, "Latency N" typically means output appears at `Current + N`. Care must be taken with the order of `waitSampling` and logic execution to avoid off-by-one errors.

*   **VCD for Software Models:**
    *   Since SW objects don't have signals, a Singleton `PerfVcdManager` is used. Components register variables (`addTraceVar`) and update them (`updateTraceVar`) manually.
