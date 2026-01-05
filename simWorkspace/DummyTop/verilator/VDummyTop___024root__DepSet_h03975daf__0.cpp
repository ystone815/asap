// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDummyTop.h for the primary calling header

#include "VDummyTop__pch.h"
#include "VDummyTop___024root.h"

void VDummyTop___024root___eval_act(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_act\n"); );
}

void VDummyTop___024root___eval_nba(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_nba\n"); );
}

void VDummyTop___024root___eval_triggers__act(VDummyTop___024root* vlSelf);

bool VDummyTop___024root___eval_phase__act(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VDummyTop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VDummyTop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VDummyTop___024root___eval_phase__nba(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VDummyTop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDummyTop___024root___dump_triggers__nba(VDummyTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VDummyTop___024root___dump_triggers__act(VDummyTop___024root* vlSelf);
#endif  // VL_DEBUG

void VDummyTop___024root___eval(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VDummyTop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/stone/assap/tmp/job_1/DummyTop.v", 7, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VDummyTop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/stone/assap/tmp/job_1/DummyTop.v", 7, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VDummyTop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VDummyTop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VDummyTop___024root___eval_debug_assertions(VDummyTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDummyTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
