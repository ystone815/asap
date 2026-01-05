// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNativePerfSystem.h for the primary calling header

#include "VNativePerfSystem__pch.h"
#include "VNativePerfSystem___024root.h"

VL_ATTR_COLD void VNativePerfSystem___024root___eval_static(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_static\n"); );
}

VL_ATTR_COLD void VNativePerfSystem___024root___eval_initial(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
}

VL_ATTR_COLD void VNativePerfSystem___024root___eval_final(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VNativePerfSystem___024root___dump_triggers__stl(VNativePerfSystem___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VNativePerfSystem___024root___eval_phase__stl(VNativePerfSystem___024root* vlSelf);

VL_ATTR_COLD void VNativePerfSystem___024root___eval_settle(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VNativePerfSystem___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/stone/assap/tmp/job_1/NativePerfSystem.v", 7, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VNativePerfSystem___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VNativePerfSystem___024root___dump_triggers__stl(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VNativePerfSystem___024root___stl_sequent__TOP__0(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->NativePerfSystem__DOT__gen__DOT___zz_lfsr 
        = VL_SHIFTL_III(32,32,32, vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr, 1U);
    vlSelf->NativePerfSystem__DOT__gen__DOT___zz_lfsr_2 
        = (1U & VL_REDXOR_32((0x80200003U & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr)));
    vlSelf->io_totalTxns = vlSelf->NativePerfSystem__DOT__gen__DOT__counter;
    vlSelf->NativePerfSystem__DOT__mem__DOT___zz_1 = 0U;
    if (((0x32U > (0x7fU & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr)) 
         & (IData)(vlSelf->io_enable))) {
        vlSelf->NativePerfSystem__DOT__mem__DOT___zz_1 = 1U;
    }
}

VL_ATTR_COLD void VNativePerfSystem___024root___eval_stl(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VNativePerfSystem___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VNativePerfSystem___024root___eval_triggers__stl(VNativePerfSystem___024root* vlSelf);

VL_ATTR_COLD bool VNativePerfSystem___024root___eval_phase__stl(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VNativePerfSystem___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VNativePerfSystem___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VNativePerfSystem___024root___dump_triggers__ico(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VNativePerfSystem___024root___dump_triggers__act(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VNativePerfSystem___024root___dump_triggers__nba(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VNativePerfSystem___024root___ctor_var_reset(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->io_enable = VL_RAND_RESET_I(1);
    vlSelf->io_totalTxns = VL_RAND_RESET_I(32);
    vlSelf->clk = 0;
    vlSelf->reset = 0;
    vlSelf->NativePerfSystem__DOT__gen__DOT___zz_lfsr = VL_RAND_RESET_I(32);
    vlSelf->NativePerfSystem__DOT__gen__DOT___zz_lfsr_2 = VL_RAND_RESET_I(1);
    vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr = VL_RAND_RESET_I(32);
    vlSelf->NativePerfSystem__DOT__gen__DOT__addrReg = VL_RAND_RESET_I(32);
    vlSelf->NativePerfSystem__DOT__gen__DOT__counter = VL_RAND_RESET_I(32);
    vlSelf->NativePerfSystem__DOT__mem__DOT___zz_mem_port0 = VL_RAND_RESET_I(32);
    vlSelf->NativePerfSystem__DOT__mem__DOT___zz_1 = VL_RAND_RESET_I(1);
    vlSelf->NativePerfSystem__DOT__mem__DOT__rspValid = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->NativePerfSystem__DOT__mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vdly__NativePerfSystem__DOT__gen__DOT__addrReg = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
