// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNativePerfSystem.h for the primary calling header

#include "VNativePerfSystem__pch.h"
#include "VNativePerfSystem___024root.h"

VL_INLINE_OPT void VNativePerfSystem___024root___ico_sequent__TOP__0(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->NativePerfSystem__DOT__mem__DOT___zz_1 = 0U;
    if (((0x32U > (0x7fU & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr)) 
         & (IData)(vlSelf->io_enable))) {
        vlSelf->NativePerfSystem__DOT__mem__DOT___zz_1 = 1U;
    }
}

void VNativePerfSystem___024root___eval_ico(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VNativePerfSystem___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VNativePerfSystem___024root___eval_triggers__ico(VNativePerfSystem___024root* vlSelf);

bool VNativePerfSystem___024root___eval_phase__ico(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VNativePerfSystem___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VNativePerfSystem___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VNativePerfSystem___024root___eval_act(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_act\n"); );
}

VL_INLINE_OPT void VNativePerfSystem___024root___nba_sequent__TOP__0(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__NativePerfSystem__DOT__gen__DOT__counter;
    __Vdly__NativePerfSystem__DOT__gen__DOT__counter = 0;
    // Body
    __Vdly__NativePerfSystem__DOT__gen__DOT__counter 
        = vlSelf->NativePerfSystem__DOT__gen__DOT__counter;
    vlSelf->__Vdly__NativePerfSystem__DOT__gen__DOT__addrReg 
        = vlSelf->NativePerfSystem__DOT__gen__DOT__addrReg;
    if (vlSelf->reset) {
        __Vdly__NativePerfSystem__DOT__gen__DOT__counter = 0U;
        vlSelf->__Vdly__NativePerfSystem__DOT__gen__DOT__addrReg = 0U;
    } else if (vlSelf->io_enable) {
        __Vdly__NativePerfSystem__DOT__gen__DOT__counter 
            = ((IData)(1U) + vlSelf->NativePerfSystem__DOT__gen__DOT__counter);
        vlSelf->__Vdly__NativePerfSystem__DOT__gen__DOT__addrReg 
            = ((0x50U > (0x7fU & (vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr 
                                  >> 7U))) ? ((IData)(4U) 
                                              + vlSelf->NativePerfSystem__DOT__gen__DOT__addrReg)
                : (0x3fffcU & (vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr 
                               << 2U)));
    }
    vlSelf->NativePerfSystem__DOT__mem__DOT__rspValid 
        = ((1U & (~ (IData)(vlSelf->reset))) && ((IData)(vlSelf->io_enable) 
                                                 & (0x32U 
                                                    <= 
                                                    (0x7fU 
                                                     & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr))));
    vlSelf->NativePerfSystem__DOT__gen__DOT__counter 
        = __Vdly__NativePerfSystem__DOT__gen__DOT__counter;
    vlSelf->io_totalTxns = vlSelf->NativePerfSystem__DOT__gen__DOT__counter;
}

VL_INLINE_OPT void VNativePerfSystem___024root___nba_sequent__TOP__1(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*7:0*/ __Vdlyvdim0__NativePerfSystem__DOT__mem__DOT__mem__v0;
    __Vdlyvdim0__NativePerfSystem__DOT__mem__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__NativePerfSystem__DOT__mem__DOT__mem__v0;
    __Vdlyvval__NativePerfSystem__DOT__mem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__NativePerfSystem__DOT__mem__DOT__mem__v0;
    __Vdlyvset__NativePerfSystem__DOT__mem__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__NativePerfSystem__DOT__mem__DOT__mem__v0 = 0U;
    if (vlSelf->NativePerfSystem__DOT__mem__DOT___zz_1) {
        __Vdlyvval__NativePerfSystem__DOT__mem__DOT__mem__v0 
            = vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr;
        __Vdlyvset__NativePerfSystem__DOT__mem__DOT__mem__v0 = 1U;
        __Vdlyvdim0__NativePerfSystem__DOT__mem__DOT__mem__v0 
            = (0xffU & (vlSelf->NativePerfSystem__DOT__gen__DOT__addrReg 
                        >> 2U));
    }
    if (((0x32U <= (0x7fU & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr)) 
         & (IData)(vlSelf->io_enable))) {
        vlSelf->NativePerfSystem__DOT__mem__DOT___zz_mem_port0 
            = vlSelf->NativePerfSystem__DOT__mem__DOT__mem
            [(0xffU & (vlSelf->NativePerfSystem__DOT__gen__DOT__addrReg 
                       >> 2U))];
    }
    if (__Vdlyvset__NativePerfSystem__DOT__mem__DOT__mem__v0) {
        vlSelf->NativePerfSystem__DOT__mem__DOT__mem[__Vdlyvdim0__NativePerfSystem__DOT__mem__DOT__mem__v0] 
            = __Vdlyvval__NativePerfSystem__DOT__mem__DOT__mem__v0;
    }
}

VL_INLINE_OPT void VNativePerfSystem___024root___nba_sequent__TOP__2(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->NativePerfSystem__DOT__gen__DOT__addrReg 
        = vlSelf->__Vdly__NativePerfSystem__DOT__gen__DOT__addrReg;
    if (vlSelf->reset) {
        vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr = 0x13579bdfU;
    } else if (vlSelf->io_enable) {
        vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr 
            = (vlSelf->NativePerfSystem__DOT__gen__DOT___zz_lfsr 
               | (IData)(vlSelf->NativePerfSystem__DOT__gen__DOT___zz_lfsr_2));
    }
    vlSelf->NativePerfSystem__DOT__gen__DOT___zz_lfsr 
        = VL_SHIFTL_III(32,32,32, vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr, 1U);
    vlSelf->NativePerfSystem__DOT__gen__DOT___zz_lfsr_2 
        = (1U & VL_REDXOR_32((0x80200003U & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr)));
    vlSelf->NativePerfSystem__DOT__mem__DOT___zz_1 = 0U;
    if (((0x32U > (0x7fU & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr)) 
         & (IData)(vlSelf->io_enable))) {
        vlSelf->NativePerfSystem__DOT__mem__DOT___zz_1 = 1U;
    }
}

void VNativePerfSystem___024root___eval_nba(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VNativePerfSystem___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VNativePerfSystem___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VNativePerfSystem___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VNativePerfSystem___024root___eval_triggers__act(VNativePerfSystem___024root* vlSelf);

bool VNativePerfSystem___024root___eval_phase__act(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VNativePerfSystem___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VNativePerfSystem___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VNativePerfSystem___024root___eval_phase__nba(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VNativePerfSystem___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VNativePerfSystem___024root___dump_triggers__ico(VNativePerfSystem___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VNativePerfSystem___024root___dump_triggers__nba(VNativePerfSystem___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VNativePerfSystem___024root___dump_triggers__act(VNativePerfSystem___024root* vlSelf);
#endif  // VL_DEBUG

void VNativePerfSystem___024root___eval(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VNativePerfSystem___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/stone/assap/tmp/job_1/NativePerfSystem.v", 7, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VNativePerfSystem___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VNativePerfSystem___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/stone/assap/tmp/job_1/NativePerfSystem.v", 7, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VNativePerfSystem___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/stone/assap/tmp/job_1/NativePerfSystem.v", 7, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VNativePerfSystem___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VNativePerfSystem___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VNativePerfSystem___024root___eval_debug_assertions(VNativePerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->io_enable & 0xfeU))) {
        Verilated::overWidthError("io_enable");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
