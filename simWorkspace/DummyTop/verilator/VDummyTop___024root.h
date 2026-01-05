// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VDummyTop.h for the primary calling header

#ifndef VERILATED_VDUMMYTOP___024ROOT_H_
#define VERILATED_VDUMMYTOP___024ROOT_H_  // guard

#include "verilated.h"


class VDummyTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VDummyTop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ __VactContinue;
    VL_OUT16(io_qM1Size,15,0);
    VL_OUT16(io_qM2Size,15,0);
    VL_OUT16(io_qMemSize,15,0);
    VL_OUT(io_totalProcessed,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VDummyTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VDummyTop___024root(VDummyTop__Syms* symsp, const char* v__name);
    ~VDummyTop___024root();
    VL_UNCOPYABLE(VDummyTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
