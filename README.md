# ASSAP (Accelerated Samsung Solution Architecture Platform)

ASSAP is a dual-purpose platform designed for both **Synthesizable RTL Design** (using SpinalHDL) and **High-Level Performance Modeling** (using Scala). It aims to bridge the gap between architectural exploration and hardware implementation.

## Key Features

### 1. Synthesizable RTL Design (`assap.design`)
*   **SpinalHDL based:** High-productivity hardware description.
*   **AXI4 Support:** Robust AXI4 Master/Slave implementations and utilities.
*   **Base Library:** Common synthesizable utilities in `assap.design.base`.
*   **Generic RTL Models:** Reusable hardware components like `RtlDelayLine[T]`.

### 2. Performance Modeling (`assap.perf`)
*   **Event-Driven Modeling:** Efficient simulation using `waitUntil` and `sleep`.
*   **SimPy-Style Blocking:** Direct `read()` and `write()` methods on FIFOs.
*   **Generic Components:** Type-agnostic base library (`Fifo[T]`, `Arbiter[T]`, `Router[T]`, `DelayLine[T]`).
*   **Packet-based Simulation:** Flexible `Packet` structure for NoC/Interconnect modeling.
*   **TDD Approach:** Fully tested components using ScalaTest.

## Directory Structure

```
src/
├── main/scala/assap/
│   ├── design/             # Synthesizable RTL
│   │   ├── base/           # Common RTL utilities (AxiUtils, Config, PacketBundle)
│   │   └── ...             # IP and System definitions
│   ├── perf/               # Performance Modeling
│   │   ├── base/           # Generic Sim Components (Fifo, Arbiter, etc.)
│   │   └── types/          # Data structures (Packet)
│   └── examples/           # Runnable examples and stress tests
└── test/scala/assap/       # Unit Tests
    └── perf/base/          # Tests for Performance Library
```

## Getting Started

### Simulation Time and Units
ASSAP Performance models use **Absolute Time Delay** for maximum flexibility.
*   **Base Time Unit:** 1 Time Unit = **1ps (picosecond)**.
*   **Standard Scale:** 1ns = 1000ps.
*   **High Resolution:** Allows modeling fractional utilization (e.g., `sleep(500)` for 0.5ns) using integer logic.

### Prerequisites
*   Java JDK 8 or 17+
*   sbt (Scala Build Tool)
*   Verilator (for RTL and Mixed-mode simulation)

### Running Stress Tests
Compare performance between different modeling styles:
```bash
sbt "runMain assap.examples.PerfStressTest"     # Pure SW (~70k pps)
sbt "runMain assap.examples.RtlStressTest"      # Mixed SW/HW (~40k pps with JNI overhead)
sbt "runMain assap.examples.RtlPureStressTest"  # Pure RTL (~1M pps)
```

## Design Philosophy
*   **Simplicity First:** Use `PerfFifo[T]` directly as ports and channels. Avoid over-engineering.
*   **Explicit Connectivity:** Pass channel references through constructors to define topology clearly.
*   **Hybrid Modeling:** Rapidly prototype in SW (`perf`), then migrate bottlenecks to HW (`design`).