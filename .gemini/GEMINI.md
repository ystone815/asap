# Gemini Project Context & Memories

This file stores the design philosophy, coding conventions, and lessons learned for the `assap` (Accelerated Samsung Solution Architecture Platform) project.

## Core Design Philosophy

1.  **Hardware-First Verification:**
    *   Prefer implementing a **Synthesizable Hardware Master** (e.g., `SimpleAxiMaster`) to drive the DUT.
    *   This ensures the testbench itself is closer to the real hardware environment.

2.  **Performance Modeling (`assap.perf`):**
    *   **Hardware-Like Ports:** All Perf components must define `input: PerfIn[T]` and `output: PerfOut[T]` ports.
    *   **Channel-Based Connection:** Connect components using channels (FIFOs) via the `>>` operator: `source.output >> channel >> dest.input`.
    *   **SimPy-Style Blocking:** Internally, components use `input.read()` and `output.write()` which block simulation time (`waitSampling`) until the operation completes (Backpressure support).
    *   **Mixed-Mode Ready:** The simulation environment runs on SpinalSim's `ClockDomain`, allowing seamless integration of Software Models and Hardware RTL.
    *   **Generic Components:** Use `[T]` type parameters (`Fifo[T]`, `Arbiter[T]`) to ensure reusability.

3.  **AXI4 Handling (`assap.design`):**
    *   **Handshake Safety:** When designing Masters, use independent or parallel assertion of `AW` and `W` valid signals.
    *   **Connection:** Use `AxiUtils.drive(slave: Axi4)` for direct AXI4-to-AXI4 connections.

4.  **Testing Strategy:**
    *   **Unit Tests:** Use `ScalaTest` in `src/test/scala` for logic verification.
    *   **Simulation:** Use `examples` folder for integration level simulation.
    *   **VCD Tracing:** Use `PerfVcdManager` to generate VCD dumps for software models.

## Implementation Guidelines (Perf Models)

*   **Component Pattern:**
    ```scala
    class MyComponent[T](...) extends SimComponent {
      val input = new PerfIn[T]
      val output = new PerfOut[T]
      
      override def run(cd: ClockDomain): Unit = fork {
        while(true) {
          val data = input.read()  // Blocking fetch
          cd.waitSampling(latency) // Process
          output.write(data)       // Blocking commit
        }
      }
    }
    ```
*   **Connection Pattern:**
    ```scala
    val fifo = new PerfFifo[Packet]("fifo", 16)
    source.output >> fifo
    fifo >> dest.input
    ```

## Lessons Learned & Gotchas

*   **RTL vs Perf FIFO:** `StreamFifo` is for RTL (synthesizable), while `PerfFifo` is for software modeling (speed, generics, blocking API). Do not confuse them.
*   **Latency Accuracy:** To model N-cycle latency correctly in a sequential loop, ensure `waitSampling` is called N times between read and write, or manage timestamps carefully.
