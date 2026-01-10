# Gemini Project Context & Memories

This file stores the design philosophy, coding conventions, and lessons learned for the `assap` (Accelerated Samsung Solution Architecture Platform) project.

## Core Design Philosophy

1.  **Hardware-First Verification:**
    *   Prefer implementing a **Synthesizable Hardware Master** (e.g., `simple_axi_master`) to drive the DUT.
    *   This ensures the testbench itself is closer to the real hardware environment.

2.  **Performance Modeling (`assap.perf`):**
    *   **Simplicity First:** Use `perf_fifo[T]` directly as the port and channel. Avoid wrapper classes.
    *   **Blocking I/O (Standard API):** Use **`read()`** and **`write(data)`** as the primary blocking methods. These align with SimPy/SystemC paradigms and handle backpressure implicitly.
    *   **Event-Driven Efficiency:** Use **`waitUntil(condition)`** inside `perf_fifo` to avoid busy-waiting or polling loops, significantly increasing simulation throughput.
    *   **Explicit Connectivity:** Pass `perf_fifo` references through component constructors to define the topology during instantiation.
    *   **Mixed-Mode Ready:** The simulation environment runs on SpinalSim's `ClockDomain`, supporting interaction between SW Models and RTL via adapters.

3.  **AXI4 Handling (`assap.design`):**
    *   **Handshake Safety:** When designing Masters, use independent or parallel assertion of `AW` and `W` valid signals to avoid deadlocks.
    *   **Connection:** Use `axi_utils.drive(slave: Axi4)` for direct AXI4-to-AXI4 connections.

4.  **Testing & Debugging:**
    *   **Unit Tests:** Use `ScalaTest` in `src/test/scala` for logic verification.
    *   **VCD Tracing:** Use `perf_vcd_manager` to generate VCD dumps for software models.

## Naming Conventions (Snake Case)

*   **Strict Snake Case:** All file names, class names, object names, and trait names MUST be in `snake_case`.
    *   Example: `PerfstressTest.scala` -> `perf_stress_test.scala`
    *   Example: `class PerfFifo` -> `class perf_fifo`
*   **Rationale:** This convention aligns strictly with the internal RTL naming standards and company policy, ensuring seamless integration and consistent style across both SW models and HW designs.

## Implementation Guidelines (Perf Models)

*   **Time Resolution:** All performance models must assume **1 Time Unit = 1ps**. 
    *   This resolution is chosen to support fractional utilization (e.g., 0.5ns delay via `sleep(500)`) using integer logic.
    *   **1ns = 1000 Units**.
*   **Method Naming:** Always name blocking communication methods **`read()`** and **`write()`**.
*   **Standard Component Pattern:**
    ```scala
    class my_component[T](...) extends sim_component {
      override def run(cd: ClockDomain): Unit = fork {
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
*   **Event-Driven vs Polling:** Switching from `while-sleep` polling to `waitUntil` in `perf_fifo` tripled the simulation speed (~20k -> ~70k pps).
*   **JNI Overhead:** Mixed-mode simulation (SW driving HW) is limited by JNI communication overhead. For maximum speed (>1M pps), keep the entire hot-path in synthesizable RTL.
*   **VCD for SW Models:** Registered variables in `perf_vcd_manager` are the only way to see SW states in wave viewers.
