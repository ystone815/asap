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

### Performance Benchmarks (2026 Update)
Comparison of simulation speeds across different scenarios. Note that "User Ops/sec" for Write workloads includes aggregation (1 NAND Op = 48 User Ops).

| Scenario | Implementation | Scale | Engine Speed | Wall Time (1s Sim) | Throughput (Simulated) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **SimPy Baseline** | Python (Event) | N/A | N/A | ~10 sec | ~100-400 Ops/sec |
| **Pure Delay Line** | Assap RTL (Verilator) | 5 Stages | **0.87 MHz** | ~1.15 sec | ~870,000 Ops/sec |
| **Massive Stress** | +1024 Background NANDs | 1024 Dies | **1.11 MHz** | ~0.90 sec | ~1,100,000 Ops/sec |
| **Full SSD (Read)** | 16 Ch x 64 Die, QD 2k | 1024 Dies | **0.17 MHz** | ~6.0 sec | ~8,500 Ops/sec |
| **Full SSD (Write)** | 1024 Die, QD 64k, Agg 48:1 | 1024 Dies | **0.06 MHz** | ~17.0 sec | **~16,000 Ops/sec** |

#### Key Findings
1.  **Scalability**: Verilator maintains ~1MHz engine speed even with 1024 parallel background NAND models.
2.  **Complexity Impact**: Full SSD Architecture (Interconnect + Aggregation Logic + RAM Delays) reduces engine speed to ~0.06 - 0.17 MHz, which is still **orders of magnitude faster** than SimPy or SystemC.
3.  **Latency Independence**: Increasing NAND Program Time from 100us to 1ms (10x cycles) **did not change Engine Speed (0.06 MHz)**. Simulating slower hardware simply takes linearly longer in Wall Time.
4.  **Write Aggregation**: Successfully simulated **48:1 Write Buffering** with a Queue Depth of 65,536, achieving stable saturation.

### Running the Tests
We provide a helper script to run benchmarks and manage logs (saved to `logs/` with timestamps).

```bash
# Run all benchmarks
./run_benchmarks.sh all

# Run specific test
./run_benchmarks.sh pure    # Pure RTL (Baseline)
./run_benchmarks.sh massive # Massive RTL (1024 NANDs)
./run_benchmarks.sh ssd     # Full SSD Architecture (Read)
./run_benchmarks.sh write   # SSD Write Workload (48:1, QD 64k)
./run_benchmarks.sh sw      # SW Model
```

## Design Philosophy
*   **Simplicity First:** Use `perf_fifo[T]` directly as ports and channels. Avoid over-engineering.
*   **Explicit Connectivity:** Pass channel references through constructors to define topology clearly.
*   **Hybrid Modeling:** Rapidly prototype in SW (`perf`), then migrate bottlenecks to HW (`design`).