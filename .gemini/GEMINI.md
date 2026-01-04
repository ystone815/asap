# Gemini Project Context & Memories

This file stores the design philosophy, coding conventions, and lessons learned for the `assap` (Accelerated Samsung Solution Architecture Platform) project.

## Core Design Philosophy

1.  **Hardware-First Verification:**
    *   Prefer implementing a **Synthesizable Hardware Master** (e.g., `SimpleAxiMaster`) to drive the DUT.
    *   This ensures the testbench itself is closer to the real hardware environment.

2.  **Performance Modeling (`assap.perf`):**
    *   **Simplicity First:** Use `PerfFifo[T]` directly as the port and channel. Avoid wrapper classes.
    *   **Blocking I/O (Standard API):** Use **`read()`** and **`write(data)`** as the primary blocking methods. These align with SimPy/SystemC paradigms and handle backpressure implicitly.
    *   **Explicit Connectivity:** Pass `PerfFifo` references through component constructors to define the topology during instantiation.
    *   **Mixed-Mode Ready:** The simulation environment runs on SpinalSim's `ClockDomain`, supporting interaction between SW Models and RTL via adapters.

3.  **AXI4 Handling (`assap.design`):**
    *   **Handshake Safety:** When designing Masters, use independent or parallel assertion of `AW` and `W` valid signals to avoid deadlocks.
    *   **Connection:** Use `AxiUtils.drive(slave: Axi4)` for direct AXI4-to-AXI4 connections.

4.  **Testing & Debugging:**
    *   **Unit Tests:** Use `ScalaTest` in `src/test/scala` for logic verification.
    *   **VCD Tracing:** Use `PerfVcdManager` to generate VCD dumps for software models.

## Implementation Guidelines (Perf Models)

*   **Time Resolution:** All performance models must assume **1 Time Unit = 1ps**. 
    *   This resolution is chosen to support fractional utilization (e.g., 0.5ns delay via `sleep(500)`) using integer logic.
    *   **1ns = 1000 Units**.
*   **Method Naming:** Always name blocking communication methods **`read()`** and **`write()`**.
*   **Standard Component Pattern:**
    ```scala
    class MyComponent[T](...) extends SimComponent {
      override def run(): Unit = fork {
        while(true) {
          val pkt = input.read()       
          if (latency > 0) sleep(latency) // latency in ps
          output.write(pkt)            
        }
      }
    }
    ```

## Lessons Learned & Gotchas

*   **Terminology:** Standardizing on `read/write` (instead of `push/pop`) improved clarity when discussing hardware-like blocking behavior.
*   **Latency Modeling:** Accurate N-cycle delay requires careful ordering of `waitSampling` and data movement.
*   **VCD for SW Models:** Registered variables in `PerfVcdManager` are the only way to see SW states in wave viewers.
