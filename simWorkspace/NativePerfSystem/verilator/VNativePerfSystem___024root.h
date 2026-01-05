// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VNativePerfSystem.h for the primary calling header

#ifndef VERILATED_VNATIVEPERFSYSTEM___024ROOT_H_
#define VERILATED_VNATIVEPERFSYSTEM___024ROOT_H_  // guard

#include "verilated.h"


class VNativePerfSystem__Syms;

class alignas(VL_CACHE_LINE_BYTES) VNativePerfSystem___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_enable,0,0);
    CData/*0:0*/ NativePerfSystem__DOT__gen__DOT___zz_lfsr_2;
    CData/*0:0*/ NativePerfSystem__DOT__mem__DOT___zz_1;
    CData/*0:0*/ NativePerfSystem__DOT__mem__DOT__rspValid;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    VL_OUT(io_totalTxns,31,0);
    IData/*31:0*/ NativePerfSystem__DOT__gen__DOT___zz_lfsr;
    IData/*31:0*/ NativePerfSystem__DOT__gen__DOT__lfsr;
    IData/*31:0*/ NativePerfSystem__DOT__gen__DOT__addrReg;
    IData/*31:0*/ NativePerfSystem__DOT__gen__DOT__counter;
    IData/*31:0*/ NativePerfSystem__DOT__mem__DOT___zz_mem_port0;
    IData/*31:0*/ __Vdly__NativePerfSystem__DOT__gen__DOT__addrReg;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 256> NativePerfSystem__DOT__mem__DOT__mem;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VNativePerfSystem__Syms* const vlSymsp;

    // CONSTRUCTORS
    VNativePerfSystem___024root(VNativePerfSystem__Syms* symsp, const char* v__name);
    ~VNativePerfSystem___024root();
    VL_UNCOPYABLE(VNativePerfSystem___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
