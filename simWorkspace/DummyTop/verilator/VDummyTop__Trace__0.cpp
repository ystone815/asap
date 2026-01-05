// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VDummyTop__Syms.h"


void VDummyTop___024root__trace_chg_0_sub_0(VDummyTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VDummyTop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root__trace_chg_0\n"); );
    // Init
    VDummyTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VDummyTop___024root*>(voidSelf);
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VDummyTop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VDummyTop___024root__trace_chg_0_sub_0(VDummyTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgSData(oldp+0,(vlSelf->io_qM1Size),16);
    bufp->chgSData(oldp+1,(vlSelf->io_qM2Size),16);
    bufp->chgSData(oldp+2,(vlSelf->io_qMemSize),16);
    bufp->chgIData(oldp+3,(vlSelf->io_totalProcessed),32);
    bufp->chgBit(oldp+4,(vlSelf->clk));
    bufp->chgBit(oldp+5,(vlSelf->reset));
}

void VDummyTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root__trace_cleanup\n"); );
    // Init
    VDummyTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VDummyTop___024root*>(voidSelf);
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
