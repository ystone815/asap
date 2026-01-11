# ASSAP Project System Requirements

This document specifies the software and library versions required to build and simulate the ASSAP project. This configuration is tested and verified for stability, especially for offline/restricted network environments.

## 1. Core System Tools

| Tool | Version | Notes |
|------|---------|-------|
| **OS** | Linux (Ubuntu recommended) | Verified on Ubuntu 24.04 LTS (WSL2) |
| **Java (JDK)** | **JDK 17** (LTS) | Temurin/Adoptium 17.0.9 verified. JDK 11+ is required. |
| **Verilator** | **v4.200** | **CRITICAL**. Do not use v5.x. <br> Project scripts assume v4.x path structure for compatibility. |
| **Make** | 4.3+ | Standard GNU Make |
| **GCC/G++** | 9.0+ | Required for compiling Verilator output |

## 2. Scala & SpinalHDL Stack (Defined in `build.sbt`)

These versions are handled automatically by SBT, but must be matched if manually setting up dependencies.

| Library | Version | Description |
|---------|---------|-------------|
| **SBT** | **1.9.7** | Scala Build Tool |
| **Scala** | **2.12.18** | Standard legacy version for hardware ecosystem compatibility. |
| **SpinalHDL** | **1.10.1** | Core HDL library (Core, Lib, IDSL Plugin). |
| **ScalaTest** | 3.2.17 | Unit testing framework. |

## 3. Offline Environment Setup Guide (For Closed Networks)

Since `sbt` attempts to download dependencies at runtime, moving the project to an offline execution environment requires copying the dependency cache manually.

### Steps to migrate:

1.  **On Online PC (Source):**
    *   Run a full simulation to ensure all dependencies are downloaded:
        ```bash
        sbt "runMain asap.examples.RtlStressTest"
        ```
2.  **Copy Cache Directories:**
    *   Archive and copy the following directories from the User Home (`~`) to the same location on the offline PC:
        *   `~/.cache/coursier`  (Main artifact cache)
        *   `~/.sbt`             (SBT plugins and global settings)
        *   `~/.ivy2`            (Legacy cache, if present)
3.  **On Offline PC (Target):**
    *   Restore the folders to `~/`.
    *   Run sbt with offline flag (optional but recommended):
        ```bash
        sbt "set offline := true" run
        ```

## 4. Environment Variables

Ensure `VERILATOR_ROOT` is set correctly for version 4.200.

```bash
# Example for local install
export VERILATOR_ROOT=$HOME/tools/verilator_v4.200/share/verilator
export PATH=$HOME/tools/verilator_v4.200/bin:$PATH
```
