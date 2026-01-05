// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDummyTop.h for the primary calling header

#include "VDummyTop__pch.h"
#include "VDummyTop__Syms.h"
#include "VDummyTop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VDummyTop___024root___dump_triggers__act(VDummyTop___024root* vlSelf);
#endif  // VL_DEBUG

void VDummyTop___024root___eval_triggers__act(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VDummyTop___024root___dump_triggers__act(vlSelf);
    }
#endif
}
