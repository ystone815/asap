# ASSAP (Architecture & System Simulation / Analysis Platform)

**ASSAP** is a SpinalHDL-based project designed for hardware architecture exploration, system-level verification, and performance modeling. It bridges the gap between RTL implementation and high-level architectural simulation.

## Project Structure

- **`src/main/scala/assap/design`**: Core hardware IP and system integration.
  - `AssapSystem`: Top-level integration of Master and Slave.
  - `SimpleAxiMaster`: A synthesizable AXI4 hardware driver with FSM.
  - `AxiUtils`: Utilities for AXI4 connections (resizing, direct master-slave connection).
- **`src/main/scala/assap/perf`**: Performance modeling and traffic generation.
  - `TrafficGenerator`: Synthesizable, LFSR-based AXI4 traffic generator.
  - `ArchSim`: Pure software, cycle-accurate architectural simulator (fast prototyping).
  - `NativePerf`: Simplified request/response bus model.
- **`src/main/scala/assap/examples`**: Example implementations and simulations.

## Design Philosophy

### 1. Hardware-Driven Verification
Instead of relying solely on software testbenches (SW driving signals), ASSAP prefers **Hardware Masters** (`SimpleAxiMaster`).
- **Why?** It verifies the system closer to the real deployment scenario (FPGA/ASIC) and allows checking deadlock conditions (e.g., AW/W handshake dependencies).

### 2. Dual-Layer Performance Modeling
ASSAP provides two layers of performance modeling:
1.  **RTL-Accurate (`TrafficGenerator`):** Synthesizable logic. Useful for FPGA emulation and precise cycle measurements with real IPs.
2.  **Architectural (`ArchSim`):** Pure Scala software logic running on the simulator clock. Useful for rapid bottleneck analysis, infinite queue experimentation, and high-level topology exploration without writing RTL.

### 3. Visibility
Even in pure software simulations (`ArchSim`), internal states (queue sizes, throughput) are mapped to dummy hardware ports to enable **VCD Tracing**. This allows visual debugging using tools like GTKWave.

## How to Run

### System Integration Test
Runs the `AssapSystem` with a Hardware Master writing/reading to an AXI SRAM.
```bash
sbt "runMain assap.examples.AssapSystemSim"
```

### RTL Performance Model
Runs the synthesizable `TrafficGenerator` against an SRAM.
```bash
sbt "runMain assap.perf.PerfSim"
```

### Architectural Simulation (Software Model)
Runs the cycle-accurate software model for bottleneck analysis.
```bash
sbt "runMain assap.perf.ArchSim"
```
*Note: Check `simWorkspace/DummyTop/test.vcd` for results.*

### Native Interface Model
Runs the simplified Native interface model.
```bash
sbt "runMain assap.perf.NativePerfSim"
```