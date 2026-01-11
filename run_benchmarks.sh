#!/bin/bash

# Ensure logs directory exists
mkdir -p logs

TIMESTAMP=$(date +"%Y%m%d_%H%M%S")

function run_test() {
    TEST_NAME=$1
    CLASS_NAME=$2
    LOG_FILE="logs/${TEST_NAME}_${TIMESTAMP}.log"
    LATEST_LINK="logs/latest_${TEST_NAME}.log"

    echo "--------------------------------------------------"
    echo "Running: $TEST_NAME"
    echo "Log: $LOG_FILE"
    echo "--------------------------------------------------"

    # Run SBT command
    export PATH=$HOME/tools/verilator_v4.200/bin:$PATH 
    export VERILATOR_ROOT=$HOME/tools/verilator_v4.200/share/verilator
    
    sbt "runMain asap.examples.$CLASS_NAME" > "$LOG_FILE" 2>&1
    
    # Move VCDs to output folder (if generated)
    mv *.vcd output/ 2>/dev/null
    
    # Update latest link
    rm -f "$LATEST_LINK"
    ln -s "$(basename "$LOG_FILE")" "$LATEST_LINK"

    # Show summary (last 10 lines)
    tail -n 10 "$LOG_FILE"
    echo ""
}

case "$1" in
    "pure")
        run_test "rtl_pure" "rtl_pure_stress_test"
        ;;
    "massive")
        run_test "rtl_massive" "rtl_massive_stress_test"
        ;;
    "sw")
        run_test "perf_sw" "perf_stress_test"
        ;;
    "ssd")
        run_test "rtl_ssd" "ssd_architecture_test"
        ;;
    "write")
        run_test "rtl_write" "ssd_write_benchmark"
        ;;
    "all")
        run_test "rtl_pure" "rtl_pure_stress_test"
        run_test "rtl_massive" "rtl_massive_stress_test"
        run_test "rtl_ssd" "ssd_architecture_test"
        run_test "rtl_write" "ssd_write_benchmark"
        ;;
    *)
        echo "Usage: $0 {pure|massive|ssd|write|sw|all}"
        echo "  pure    : Run RTL Phase Stress Test (Baseline)"
        echo "  massive : Run RTL Massive Stress Test (1024 NANDs)"
        echo "  ssd     : Run Full SSD Architecture Test (16 Ch, 1024 Die, QD 2048)"
        echo "  write   : Run Write Workload (48:1 Aggregation)"
        echo "  sw      : Run SW Performance Model Stress Test"
        echo "  all     : Run all benchmarks"
        exit 1
        ;;
esac
