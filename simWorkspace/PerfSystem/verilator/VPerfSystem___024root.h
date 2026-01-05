// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPerfSystem.h for the primary calling header

#ifndef VERILATED_VPERFSYSTEM___024ROOT_H_
#define VERILATED_VPERFSYSTEM___024ROOT_H_  // guard

#include "verilated.h"


class VPerfSystem__Syms;

class alignas(VL_CACHE_LINE_BYTES) VPerfSystem___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(io_enable,0,0);
        CData/*0:0*/ PerfSystem__DOT__generator_io_axi_ar_valid;
        CData/*3:0*/ PerfSystem__DOT__generator_io_axi_ar_payload_id;
        CData/*7:0*/ PerfSystem__DOT__generator_io_axi_ar_payload_len;
        CData/*2:0*/ PerfSystem__DOT__generator_io_axi_ar_payload_size;
        CData/*1:0*/ PerfSystem__DOT__generator_io_axi_ar_payload_burst;
        CData/*0:0*/ PerfSystem__DOT__generator_io_axi_aw_valid;
        CData/*3:0*/ PerfSystem__DOT__generator_io_axi_aw_payload_id;
        CData/*7:0*/ PerfSystem__DOT__generator_io_axi_aw_payload_len;
        CData/*2:0*/ PerfSystem__DOT__generator_io_axi_aw_payload_size;
        CData/*1:0*/ PerfSystem__DOT__generator_io_axi_aw_payload_burst;
        CData/*0:0*/ PerfSystem__DOT__generator_io_axi_w_valid;
        CData/*3:0*/ PerfSystem__DOT__generator_io_axi_w_payload_strb;
        CData/*0:0*/ PerfSystem__DOT__generator_io_axi_w_payload_last;
        CData/*0:0*/ PerfSystem__DOT__sram_io_axi_r_valid;
        CData/*0:0*/ PerfSystem__DOT__sram_io_axi_b_valid;
        CData/*0:0*/ PerfSystem__DOT__sram_io_arw_valid_debug;
        CData/*2:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__3;
        CData/*3:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__8;
        CData/*3:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__7;
        CData/*0:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__2;
        CData/*1:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9647ad__1;
        CData/*2:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__2;
        CData/*7:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d94df49__1;
        CData/*3:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__6;
        CData/*3:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__5;
        CData/*0:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__1;
        CData/*3:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__4;
        CData/*2:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__1;
        CData/*3:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__3;
        CData/*3:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__2;
        CData/*0:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__0;
        CData/*1:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9647ad__0;
        CData/*2:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__0;
        CData/*7:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d94df49__0;
        CData/*3:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__1;
        CData/*3:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__0;
        CData/*0:0*/ PerfSystem__DOT__generator__DOT___zz_lfsr_2;
        CData/*7:0*/ PerfSystem__DOT__generator__DOT__burstLen;
        CData/*0:0*/ PerfSystem__DOT__generator__DOT__awDone;
        CData/*0:0*/ PerfSystem__DOT__generator__DOT__wDone;
        CData/*0:0*/ PerfSystem__DOT__generator__DOT__fsm_wantStart;
        CData/*2:0*/ PerfSystem__DOT__generator__DOT__fsm_stateReg;
        CData/*2:0*/ PerfSystem__DOT__generator__DOT__fsm_stateNext;
        CData/*0:0*/ PerfSystem__DOT__generator__DOT__when_TrafficGenerator_l79;
        CData/*0:0*/ PerfSystem__DOT__generator__DOT__io_axi_aw_fire;
        CData/*0:0*/ PerfSystem__DOT__generator__DOT__io_axi_w_fire;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready;
        CData/*3:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id;
        CData/*7:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len;
        CData/*2:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size;
        CData/*1:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_valid;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_ready;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_last;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_doResult;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid;
        CData/*7:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len;
        CData/*7:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat;
        CData/*3:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_id;
    };
    struct {
        CData/*2:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size;
        CData/*1:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_burst;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_write;
        CData/*2:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__stage0_valid;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__stage0_fire;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_last;
        CData/*3:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_id;
        CData/*2:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_size;
        CData/*1:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_burst;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_write;
        CData/*7:0*/ PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read;
        CData/*7:0*/ PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_1;
        CData/*7:0*/ PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_2;
        CData/*7:0*/ PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_3;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__locked;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_0;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_1;
        CData/*0:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0;
        CData/*3:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_2;
        CData/*1:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_3;
        CData/*7:0*/ __Vdly__PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr;
        SData/*11:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_addr;
        SData/*11:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_result;
        SData/*11:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base;
        SData/*11:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr;
        SData/*11:0*/ PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_addr;
        VL_OUT(io_writeCount,31,0);
        VL_OUT(io_readCount,31,0);
        IData/*31:0*/ PerfSystem__DOT__generator_io_axi_ar_payload_addr;
        IData/*31:0*/ PerfSystem__DOT__generator_io_axi_aw_payload_addr;
        IData/*31:0*/ PerfSystem__DOT__generator_io_axi_w_payload_data;
        IData/*31:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__2;
        IData/*31:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__1;
        IData/*31:0*/ PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__0;
        IData/*31:0*/ PerfSystem__DOT__generator__DOT___zz_lfsr;
        IData/*31:0*/ PerfSystem__DOT__generator__DOT__lfsr;
        IData/*31:0*/ PerfSystem__DOT__generator__DOT__currentAddr;
        IData/*31:0*/ PerfSystem__DOT__generator__DOT__writeCounter;
        IData/*31:0*/ PerfSystem__DOT__generator__DOT__readCounter;
        IData/*31:0*/ PerfSystem__DOT__generator__DOT__txnData;
        VlWide<3>/*79:0*/ PerfSystem__DOT__generator__DOT__fsm_stateReg_string;
        VlWide<3>/*79:0*/ PerfSystem__DOT__generator__DOT__fsm_stateNext_string;
        IData/*31:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*7:0*/, 1024> PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0;
        VlUnpacked<CData/*7:0*/, 1024> PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1;
        VlUnpacked<CData/*7:0*/, 1024> PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2;
        VlUnpacked<CData/*7:0*/, 1024> PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3;
        VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VPerfSystem__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPerfSystem___024root(VPerfSystem__Syms* symsp, const char* v__name);
    ~VPerfSystem___024root();
    VL_UNCOPYABLE(VPerfSystem___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
