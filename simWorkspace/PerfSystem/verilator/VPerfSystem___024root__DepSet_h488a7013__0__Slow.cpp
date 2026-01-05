// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPerfSystem.h for the primary calling header

#include "VPerfSystem__pch.h"
#include "VPerfSystem__Syms.h"
#include "VPerfSystem___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VPerfSystem___024root___dump_triggers__stl(VPerfSystem___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VPerfSystem___024root___eval_triggers__stl(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VPerfSystem___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
