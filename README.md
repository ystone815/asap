# ASSAP (Accelerated Samsung Solution Architecture Platform)

ASSAP is a dual-purpose platform designed for both **Synthesizable RTL Design** (using SpinalHDL) and **High-Level Performance Modeling** (using Scala). It aims to bridge the gap between architectural exploration and hardware implementation.

## Key Features

### 1. Synthesizable RTL Design (`assap.design`)
*   **SpinalHDL based:** High-productivity hardware description.
*   **AXI4 Support:** Robust AXI4 Master/Slave implementations and utilities.
*   **Base Library:** Common synthesizable utilities in `assap.design.base`.
*   **Generic RTL Models:** Reusable hardware components like `rtl_delay_line[T]`.

### 2. Performance Modeling (`assap.perf`)
*   **Event-Driven Modeling:** Efficient simulation using `waitUntil` and `sleep`.
*   **SimPy-Style Blocking:** Direct `read()` and `write()` methods on FIFOs.
*   **Generic Components:** Type-agnostic base library (`perf_fifo[T]`, `perf_arbiter[T]`, `perf_router[T]`, `perf_delay_line[T]`).
*   **Packet-based Simulation:** Flexible `packet` structure for NoC/Interconnect modeling.
*   **TDD Approach:** Fully tested components using ScalaTest.

## Naming Convention

**Strict Snake Case:** This project adheres to a strict `snake_case` naming convention for all files, classes, objects, and traits (e.g., `simple_axi_master`, `perf_fifo`). This aligns with RTL signal naming standards.

## Directory Structure

```
src/
├── main/scala/assap/
│   ├── design/             # Synthesizable RTL
│   │   ├── base/           # Common RTL utilities (axi_utils, assap_config, packet_bundle)
│   │   └── ...             # IP and System definitions
│   ├── perf/               # Performance Modeling
│   │   ├── base/           # Generic Sim Components (perf_fifo, perf_arbiter, etc.)
│   │   └── types/          # Data structures (packet)
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
*   Verilator (for RTL and Mixed-mode simulation) (v4.200 recommended)

### Performance Benchmarks
Comparison of simulation speeds for a 5-Stage Delay Line (500k packets):

| Model Type | Implementation | Speed (kpps) | Relative Speed |
| :--- | :--- | :--- | :--- |
| **SimPy** | Python (Event-Driven) | ~50 kpps | 1.0x |
| **Assap Perf** | Scala (SW Coroutine) | ~20 kpps | 0.4x |
| **Assap Design** | **Verilator (RTL)** | **~1,000 kpps** | **20.0x** |

#### Scalability Test (Background Traffic)
Measuring the impact of running background NAND models alongside the main datapath:

| Scenario | Active Instances | Speed (kpps) | Impact |
| :--- | :--- | :--- | :--- |
| **Baseline** | 5 Delay Lines | ~1,000 kpps | - |
| **Heavy Load** | +128 NAND Models | ~850 kpps | -15% |
| **Massive Load** | **+1024 NAND Models** | **~890 kpps** | **-11%** |

*Verilator demonstrates near-zero marginal cost for scaling up parallel instances, making it ideal for massive architecture exploration.*

### Running the Tests
We provide a helper script to run benchmarks and manage logs (saved to `logs/` with timestamps).

```bash
# Run all benchmarks
./run_benchmarks.sh all

# Run specific test
./run_benchmarks.sh pure    # Pure RTL (Baseline)
./run_benchmarks.sh massive # Massive RTL (1024 NANDs)
./run_benchmarks.sh sw      # SW Model
```

## Design Philosophy
*   **Simplicity First:** Use `perf_fifo[T]` directly as ports and channels. Avoid over-engineering.
*   **Explicit Connectivity:** Pass channel references through constructors to define topology clearly.
*   **Hybrid Modeling:** Rapidly prototype in SW (`perf`), then migrate bottlenecks to HW (`design`).