// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNativePerfSystem.h for the primary calling header

#include "VNativePerfSystem__pch.h"
#include "VNativePerfSystem__Syms.h"
#include "VNativePerfSystem___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VNativePerfSystem___024root___dump_triggers__ico(VNativePerfSystem___024root* vlSelf);
#endif  // VL_DEBUG

void VNativePerfSystem___024root___eval_triggers__ico(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VNativePerfSystem___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VNativePerfSystem___024root___dump_triggers__act(VNativePerfSystem___024root* vlSelf);
#endif  // VL_DEBUG

void VNativePerfSystem___024root___eval_triggers__act(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((IData)(vlSelf->reset) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__reset__0)))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(0U, 1U);
        vlSelf->__VactTriggered.set(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VNativePerfSystem___024root___dump_triggers__act(vlSelf);
    }
#endif
}
