# ASSAP Project Roadmap & TODOs

This document tracks future tasks, architectural discussions, and open questions for the ASSAP project.

## 1. Mixed-Mode Simulation (SW <-> RTL)
We have confirmed that SW models (`PerfFifo`) and RTL models (`Stream`) can interact, but they require explicit bridges due to protocol and type differences.

*   **[ ] Implement `PerfBridge` Utility:**
    *   Create a reusable bridge component to connect `PerfFifo[T]` (SW) and `Stream[D <: Data]` (RTL).
    *   **Challenge:** Data type mismatch. SW uses Scala objects (`case class Packet`), while RTL uses Hardware signals (`Bundle PacketBundle`).
    *   **Solution:** The bridge must support a user-defined conversion function (`T => D` and `D => T`).
    *   **Goal:** Enable easy connections like: `swGen.output >> PerfBridge.toRtl >> rtlDut.input`.

## 2. Performance Model Optimization
Current SW models use a **Sequential Blocking** pattern (`read -> delay -> write`), which models non-pipelined resources.

*   **[ ] Pipeline Support for SW Models:**
    *   **Issue:** `PerfDelayLine` throughput drops as latency increases (1/N) because it handles only one packet at a time.
    *   **Proposal:** Implement a multi-threaded or polling-based `PerfPipelinedDelay` that can accept new inputs every cycle regardless of latency (matching RTL throughput).
    *   **Discussion:** Is the complexity of multi-threading worth the throughput accuracy for high-level models?

## 3. Large Scale Simulation
*   **[ ] Pure RTL Simulation Infrastructure:**
    *   We achieved ~1M pps with pure RTL simulation. Expand this to support full SoC scenarios.
    *   Need synthesizable traffic generators and checkers (VIPs) to avoid JNI overhead.

## 4. Architectural Decisions (For Team Discussion)
*   **Data Type Sharing:** Should we try to use SpinalHDL `Bundle` classes as the primary data object in SW models to avoid conversion? Or keep SW models lightweight with Scala `case classes`?
*   **Clock Domain Management:** Currently, SW models use absolute time (`sleep`). Should we enforce explicit `ClockDomain` awareness in SW models to better match RTL behavior in multi-clock systems?
