// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDummyTop.h for the primary calling header

#include "VDummyTop__pch.h"
#include "VDummyTop___024root.h"

VL_ATTR_COLD void VDummyTop___024root___eval_static(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_static\n"); );
}

VL_ATTR_COLD void VDummyTop___024root___eval_initial__TOP(VDummyTop___024root* vlSelf);

VL_ATTR_COLD void VDummyTop___024root___eval_initial(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_initial\n"); );
    // Body
    VDummyTop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void VDummyTop___024root___eval_initial__TOP(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->io_qM1Size = 0U;
    vlSelf->io_qM2Size = 0U;
    vlSelf->io_qMemSize = 0U;
    vlSelf->io_totalProcessed = 0U;
}

VL_ATTR_COLD void VDummyTop___024root___eval_final(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_final\n"); );
}

VL_ATTR_COLD void VDummyTop___024root___eval_settle(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDummyTop___024root___dump_triggers__act(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VDummyTop___024root___dump_triggers__nba(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VDummyTop___024root___ctor_var_reset(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->io_qM1Size = VL_RAND_RESET_I(16);
    vlSelf->io_qM2Size = VL_RAND_RESET_I(16);
    vlSelf->io_qMemSize = VL_RAND_RESET_I(16);
    vlSelf->io_totalProcessed = VL_RAND_RESET_I(32);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
}
