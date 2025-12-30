# Gemini Project Context & Memories

This file stores the design philosophy, coding conventions, and lessons learned for the `assap` project.

## Core Design Philosophy

1.  **Hardware-First Verification:**
    *   Prefer implementing a **Synthesizable Hardware Master** (e.g., `SimpleAxiMaster`) to drive the DUT, rather than complex software-only testbenches.
    *   This ensures the testbench itself is closer to the real hardware environment.

2.  **Performance Modeling Layers:**
    *   **RTL Layer (`TrafficGenerator`):** Must be synthesizable. Use LFSR for randomness. Supports parameters like `WriteRatio`, `Locality`.
    *   **Architecture Layer (`ArchSim`):** Pure Scala logic using `fork`, `queue`, `waitSampling`. NO RTL generation required. Used for fast iteration.
    *   **Visibility:** Even for ArchSim, **expose internal states to dummy hardware ports** to allow VCD tracing.

3.  **AXI4 Handling:**
    *   Use `AssapConfig` for global configuration.
    *   **Handshake Safety:** When designing Masters, assert `AW` and `W` valid signals **in parallel** (or allow them to be independent) to avoid deadlocks with slaves that depend on `W` to accept `AW`.
    *   **Connection:** Use `AxiUtils.drive(slave: Axi4)` to connect Master(Axi4) to Slave(Axi4) with automatic address resizing and arbitration.

## Lessons Learned & Gotchas

*   **Simulation Reset:**
    *   `forkStimulus(period=10)` asserts reset for ~100 cycles by default.
    *   Always use `dut.clockDomain.waitSampling(100)` (or more) at the start of `doSim` to wait for the reset to release before checking signals or starting monitors.
    *   Avoid checking `io.done` or `counters` immediately after start; wait for the reset period.

*   **SpinalSim Data Types:**
    *   When reading 32-bit `UInt` from simulation (e.g., counters), use `.toLong`. `.toInt` will throw an exception for large unsigned values (overflow).
    *   Simulation-only objects (like Scala classes in `ArchSim`) cannot be viewed in VCD unless mapped to a `Component`'s IO.

*   **AXI Interconnect:**
    *   Simple native interfaces (`NativeBus`) can be used for simpler modeling when full AXI complexity is not needed.
    *   Manual stream connection is sometimes preferred over `>>` for custom bundles to ensure clarity.

## Directory Structure
*   `src/main/scala/assap/design`: Synthesizable IP & System.
*   `src/main/scala/assap/perf`: Performance models (RTL & Arch).
*   `src/main/scala/assap/examples`: Usage examples & Sim runners.
