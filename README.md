# ASSAP (Architecture Simulation & Synthesizable Architecture Platform)

ASSAP is a dual-purpose platform designed for both **Synthesizable RTL Design** (using SpinalHDL) and **High-Level Performance Modeling** (using Scala). It aims to bridge the gap between architectural exploration and hardware implementation.

## Key Features

### 1. Synthesizable RTL Design (`assap.design`)
*   **SpinalHDL based:** High-productivity hardware description.
*   **AXI4 Support:** robust AXI4 Master/Slave implementations and utilities.
*   **AssapSystem:** A reference SoC structure connecting Hardware Masters to SRAM Slaves.
*   **Base Library:** Common synthesizable utilities in `assap.design.base`.

### 2. Performance Modeling (`assap.perf`)
*   **Cycle-Accurate Modeling:** Fast simulation for architectural exploration.
*   **Generic Components:** Type-agnostic base library (`Fifo[T]`, `Arbiter[T]`, `Router[T]`, `DelayLine[T]`).
*   **Packet-based Simulation:** Flexible `Packet` structure for NoC/Interconnect modeling.
*   **TDD Approach:** Fully tested components using ScalaTest.

## Directory Structure

```
src/
├── main/scala/assap/
│   ├── design/             # Synthesizable RTL
│   │   ├── base/           # Common RTL utilities (AxiUtils, Config)
│   │   └── ...             # IP and System definitions
│   ├── perf/               # Performance Modeling
│   │   ├── base/           # Generic Sim Components (Fifo, Router, etc.)
│   │   └── types/          # Data structures (Packet)
│   └── examples/           # Runnable examples for both RTL and Perf
└── test/scala/assap/       # Unit Tests
    └── perf/base/          # Tests for Performance Library
```

## Getting Started

### Prerequisites
*   Java JDK 8 or 17+
*   sbt (Scala Build Tool)
*   Verilator (for RTL simulation)

### Running Performance Simulation
Run the architecture exploration example using the generic library:
```bash
sbt "runMain assap.examples.PerfBaseExample"
```

### Running RTL Simulation
Run the hardware system simulation (Hardware Master + SRAM):
```bash
sbt "runMain assap.examples.AssapSystemSim"
```

### Running Unit Tests
Execute all unit tests (including Perf library verification):
```bash
sbt test
```

## Design Philosophy
*   **Separation of Concerns:** Keep synthesizable RTL (`design`) and software models (`perf`) separate but structurally aligned.
*   **Generic Modeling:** Performance components should not depend on specific data types.
*   **Hardware-First Verification:** Prefer hardware-based masters for verification over software-only testbenches where possible.
