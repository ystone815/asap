// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPerfSystem.h for the primary calling header

#include "VPerfSystem__pch.h"
#include "VPerfSystem___024root.h"

VL_ATTR_COLD void VPerfSystem___024root___eval_static(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_static\n"); );
}

VL_ATTR_COLD void VPerfSystem___024root___eval_initial__TOP(VPerfSystem___024root* vlSelf);

VL_ATTR_COLD void VPerfSystem___024root___eval_initial(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_initial\n"); );
    // Body
    VPerfSystem___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
}

VL_ATTR_COLD void VPerfSystem___024root___eval_initial__TOP(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__3 
        = (7U & VL_RAND_RESET_I(3));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__8 
        = (0xfU & VL_RAND_RESET_I(4));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__7 
        = (0xfU & VL_RAND_RESET_I(4));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__2 
        = (1U & VL_RAND_RESET_I(1));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9647ad__1 
        = (3U & VL_RAND_RESET_I(2));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__2 
        = (7U & VL_RAND_RESET_I(3));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d94df49__1 
        = (0xffU & VL_RAND_RESET_I(8));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__6 
        = (0xfU & VL_RAND_RESET_I(4));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__5 
        = (0xfU & VL_RAND_RESET_I(4));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__2 
        = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__1 
        = (1U & VL_RAND_RESET_I(1));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__4 
        = (0xfU & VL_RAND_RESET_I(4));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__1 
        = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__1 
        = (7U & VL_RAND_RESET_I(3));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__3 
        = (0xfU & VL_RAND_RESET_I(4));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__2 
        = (0xfU & VL_RAND_RESET_I(4));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__0 
        = (1U & VL_RAND_RESET_I(1));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9647ad__0 
        = (3U & VL_RAND_RESET_I(2));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__0 
        = (7U & VL_RAND_RESET_I(3));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d94df49__0 
        = (0xffU & VL_RAND_RESET_I(8));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__1 
        = (0xfU & VL_RAND_RESET_I(4));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__0 
        = (0xfU & VL_RAND_RESET_I(4));
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__0 
        = VL_RAND_RESET_I(32);
}

VL_ATTR_COLD void VPerfSystem___024root___eval_final(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPerfSystem___024root___dump_triggers__stl(VPerfSystem___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VPerfSystem___024root___eval_phase__stl(VPerfSystem___024root* vlSelf);

VL_ATTR_COLD void VPerfSystem___024root___eval_settle(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_settle\n"); );
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
            VPerfSystem___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/stone/assap/tmp/job_1/PerfSystem.v", 7, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VPerfSystem___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPerfSystem___024root___dump_triggers__stl(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<VlWide<3>/*79:0*/, 8> VPerfSystem__ConstPool__TABLE_h4ad435a8_0;
extern const VlUnpacked<CData/*0:0*/, 8> VPerfSystem__ConstPool__TABLE_h14e0e0b9_0;
extern const VlUnpacked<CData/*0:0*/, 16> VPerfSystem__ConstPool__TABLE_h171d64e5_0;
extern const VlUnpacked<CData/*0:0*/, 8> VPerfSystem__ConstPool__TABLE_h70de94fd_0;

VL_ATTR_COLD void VPerfSystem___024root___stl_sequent__TOP__0(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___stl_sequent__TOP__0\n"); );
    // Init
    SData/*11:0*/ PerfSystem__DOT__sram__DOT__ram__DOT____VdfgExtracted_h3a2d63ce__0;
    PerfSystem__DOT__sram__DOT__ram__DOT____VdfgExtracted_h3a2d63ce__0 = 0;
    CData/*1:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0;
    PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0 = 0;
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*3:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*2:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*2:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    vlSelf->io_writeCount = vlSelf->PerfSystem__DOT__generator__DOT__writeCounter;
    vlSelf->io_readCount = vlSelf->PerfSystem__DOT__generator__DOT__readCounter;
    vlSelf->PerfSystem__DOT__generator__DOT__when_TrafficGenerator_l79 
        = (0x1000U <= vlSelf->PerfSystem__DOT__generator__DOT__currentAddr);
    vlSelf->PerfSystem__DOT__generator__DOT___zz_lfsr 
        = VL_SHIFTL_III(32,32,32, vlSelf->PerfSystem__DOT__generator__DOT__lfsr, 1U);
    vlSelf->PerfSystem__DOT__generator__DOT___zz_lfsr_2 
        = (1U & VL_REDXOR_32((0x80200003U & vlSelf->PerfSystem__DOT__generator__DOT__lfsr)));
    vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_strb 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__4;
    vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_last 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__1;
    vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_data 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__1;
    __Vtableidx1 = vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg;
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg_string[0U] 
        = VPerfSystem__ConstPool__TABLE_h4ad435a8_0
        [__Vtableidx1][0U];
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg_string[1U] 
        = VPerfSystem__ConstPool__TABLE_h4ad435a8_0
        [__Vtableidx1][1U];
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg_string[2U] 
        = VPerfSystem__ConstPool__TABLE_h4ad435a8_0
        [__Vtableidx1][2U];
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_id 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__0;
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_size 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__0;
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_burst 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9647ad__0;
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_id 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__5;
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_size 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__2;
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_burst 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9647ad__1;
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_addr 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__0;
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_len 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d94df49__0;
    if ((1U & (~ ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
            if ((1U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
                vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_strb = 0xfU;
                vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_last = 1U;
                vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_data 
                    = vlSelf->PerfSystem__DOT__generator__DOT__txnData;
                vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_id = 0U;
                vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_size = 2U;
                vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_burst = 1U;
                vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_addr 
                    = vlSelf->PerfSystem__DOT__generator__DOT__currentAddr;
                vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_len 
                    = vlSelf->PerfSystem__DOT__generator__DOT__burstLen;
            }
        }
    }
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_addr 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__2;
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_len 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d94df49__1;
    if ((4U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
                vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_id = 0U;
                vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_size = 2U;
                vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_burst = 1U;
                vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_addr 
                    = vlSelf->PerfSystem__DOT__generator__DOT__currentAddr;
                vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_len 
                    = vlSelf->PerfSystem__DOT__generator__DOT__burstLen;
            }
        }
    }
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase 
        = (7U & ((3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size)) 
                 + ((8U == (8U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len)))
                     ? 3U : ((4U == (0xcU & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len)))
                              ? 2U : ((2U == (0xeU 
                                              & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len)))
                                       ? 1U : 0U)))));
    vlSelf->PerfSystem__DOT__sram_io_axi_r_valid = 
        ((~ (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_write)) 
         & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid));
    vlSelf->PerfSystem__DOT__sram_io_axi_b_valid = 
        ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid) 
         & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_write) 
            & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_last)));
    __Vtableidx6 = vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg;
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_wantStart 
        = VPerfSystem__ConstPool__TABLE_h14e0e0b9_0
        [__Vtableidx6];
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base 
        = ((~ (((1U < (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                << 1U) | (0U < (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))))) 
           & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_addr));
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready = 1U;
    if ((1U & (~ (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid)))) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready = 1U;
    }
    __Vtableidx4 = (((IData)(vlSelf->PerfSystem__DOT__generator__DOT__wDone) 
                     << 3U) | (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg));
    vlSelf->PerfSystem__DOT__generator_io_axi_w_valid 
        = VPerfSystem__ConstPool__TABLE_h171d64e5_0
        [__Vtableidx4];
    __Vtableidx5 = vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg;
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_valid 
        = VPerfSystem__ConstPool__TABLE_h70de94fd_0
        [__Vtableidx5];
    __Vtableidx3 = (((IData)(vlSelf->PerfSystem__DOT__generator__DOT__awDone) 
                     << 3U) | (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg));
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_valid 
        = VPerfSystem__ConstPool__TABLE_h171d64e5_0
        [__Vtableidx3];
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr 
        = (0xfffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base) 
                     + (((2U == (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                         << 2U) | (((1U == (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                                    << 1U) | (0U == 
                                              (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size)))))));
    PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0 
        = (((IData)(vlSelf->PerfSystem__DOT__generator_io_axi_aw_valid) 
            << 1U) | (IData)(vlSelf->PerfSystem__DOT__generator_io_axi_ar_valid));
    PerfSystem__DOT__sram__DOT__ram__DOT____VdfgExtracted_h3a2d63ce__0 
        = ((0xfc0U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base)) 
           | (0x3fU & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr)));
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_2 
        = (0xfU & ((~ ((((IData)(PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0) 
                         << 2U) | (IData)(PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0)) 
                       - (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_0) 
                           << 1U) | (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_1)))) 
                   & (((IData)(PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0) 
                       << 2U) | (IData)(PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0))));
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_result 
        = ((0U == (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_burst))
            ? (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_addr)
            : ((2U == (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_burst))
                ? ((4U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase))
                    ? ((2U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase))
                        ? (IData)(PerfSystem__DOT__sram__DOT__ram__DOT____VdfgExtracted_h3a2d63ce__0)
                        : ((1U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase))
                            ? (IData)(PerfSystem__DOT__sram__DOT__ram__DOT____VdfgExtracted_h3a2d63ce__0)
                            : ((0xfe0U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base)) 
                               | (0x1fU & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr)))))
                    : ((2U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase))
                        ? ((1U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase))
                            ? ((0xff0U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base)) 
                               | (0xfU & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr)))
                            : ((0xff8U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base)) 
                               | (7U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr))))
                        : ((1U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase))
                            ? ((0xffcU & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base)) 
                               | (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr)))
                            : ((0xffeU & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base)) 
                               | (1U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr))))))
                : (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr)));
}

extern const VlUnpacked<CData/*2:0*/, 2048> VPerfSystem__ConstPool__TABLE_ha72c7d4f_0;

VL_ATTR_COLD void VPerfSystem___024root___stl_sequent__TOP__1(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___stl_sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT___zz_unburstify_result_ready;
    PerfSystem__DOT__sram__DOT__ram__DOT___zz_unburstify_result_ready = 0;
    CData/*2:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    SData/*10:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    // Body
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_3 
        = (3U & (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_2) 
                  >> 2U) | (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_2)));
    if (vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__locked) {
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0 
            = (1U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_0));
        vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write 
            = (1U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_1));
    } else {
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0 
            = (1U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_3));
        vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write 
            = (1U & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_3) 
                     >> 1U));
    }
    if (vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0) {
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id 
            = vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_id;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size 
            = vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_size;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst 
            = vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_burst;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr 
            = vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_addr;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len 
            = vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_len;
    } else {
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id 
            = vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_id;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size 
            = vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_size;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst 
            = vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_burst;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr 
            = vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_addr;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len 
            = vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_len;
    }
    vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug 
        = (((IData)(vlSelf->PerfSystem__DOT__generator_io_axi_ar_valid) 
            & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)) 
           | ((IData)(vlSelf->PerfSystem__DOT__generator_io_axi_aw_valid) 
              & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write)));
    if (vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_write;
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr 
            = (0xfffU & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_result));
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_last 
            = (1U == (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat));
    } else {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write;
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr 
            = (0xfffU & vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr);
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_last = 1U;
        if ((0U != (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len))) {
            vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_last = 0U;
        }
    }
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_valid 
        = ((IData)(vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug) 
           | (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid));
    PerfSystem__DOT__sram__DOT__ram__DOT___zz_unburstify_result_ready 
        = (1U & (~ ((~ (IData)(vlSelf->PerfSystem__DOT__generator_io_axi_w_valid)) 
                    & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write))));
    vlSelf->PerfSystem__DOT__generator__DOT__io_axi_w_fire 
        = (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_valid) 
            & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write) 
               & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready))) 
           & (IData)(vlSelf->PerfSystem__DOT__generator_io_axi_w_valid));
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_valid 
        = ((IData)(PerfSystem__DOT__sram__DOT__ram__DOT___zz_unburstify_result_ready) 
           & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_valid));
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_ready 
        = ((IData)(PerfSystem__DOT__sram__DOT__ram__DOT___zz_unburstify_result_ready) 
           & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready));
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_fire 
        = ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_valid) 
           & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready));
    vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready = 0U;
    if ((1U & (~ (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid)))) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_ready;
    }
    vlSelf->PerfSystem__DOT__generator__DOT__io_axi_aw_fire 
        = (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write) 
            & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready)) 
           & (IData)(vlSelf->PerfSystem__DOT__generator_io_axi_aw_valid));
    __Vtableidx7 = (((IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_wantStart) 
                     << 0xaU) | (((IData)(vlSelf->io_enable) 
                                  << 9U) | (((0x32U 
                                              > (0x7fU 
                                                 & vlSelf->PerfSystem__DOT__generator__DOT__lfsr)) 
                                             << 8U) 
                                            | (((((IData)(vlSelf->PerfSystem__DOT__generator__DOT__awDone) 
                                                  | (IData)(vlSelf->PerfSystem__DOT__generator__DOT__io_axi_aw_fire)) 
                                                 & ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__wDone) 
                                                    | (IData)(vlSelf->PerfSystem__DOT__generator__DOT__io_axi_w_fire))) 
                                                << 7U) 
                                               | (((IData)(vlSelf->PerfSystem__DOT__sram_io_axi_b_valid) 
                                                   << 6U) 
                                                  | ((((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0) 
                                                       & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready)) 
                                                      << 5U) 
                                                     | (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_last) 
                                                         << 4U) 
                                                        | (((IData)(vlSelf->PerfSystem__DOT__sram_io_axi_r_valid) 
                                                            << 3U) 
                                                           | (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg)))))))));
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext 
        = VPerfSystem__ConstPool__TABLE_ha72c7d4f_0
        [__Vtableidx7];
    __Vtableidx2 = vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext;
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext_string[0U] 
        = VPerfSystem__ConstPool__TABLE_h4ad435a8_0
        [__Vtableidx2][0U];
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext_string[1U] 
        = VPerfSystem__ConstPool__TABLE_h4ad435a8_0
        [__Vtableidx2][1U];
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext_string[2U] 
        = VPerfSystem__ConstPool__TABLE_h4ad435a8_0
        [__Vtableidx2][2U];
}

VL_ATTR_COLD void VPerfSystem___024root___eval_stl(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VPerfSystem___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
        VPerfSystem___024root___stl_sequent__TOP__1(vlSelf);
    }
}

VL_ATTR_COLD void VPerfSystem___024root___eval_triggers__stl(VPerfSystem___024root* vlSelf);

VL_ATTR_COLD bool VPerfSystem___024root___eval_phase__stl(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VPerfSystem___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VPerfSystem___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPerfSystem___024root___dump_triggers__ico(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void VPerfSystem___024root___dump_triggers__act(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void VPerfSystem___024root___dump_triggers__nba(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___dump_triggers__nba\n"); );
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

VL_ATTR_COLD void VPerfSystem___024root___ctor_var_reset(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->io_enable = VL_RAND_RESET_I(1);
    vlSelf->io_writeCount = VL_RAND_RESET_I(32);
    vlSelf->io_readCount = VL_RAND_RESET_I(32);
    vlSelf->clk = 0;
    vlSelf->reset = 0;
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_valid = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_addr = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_id = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_len = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_size = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_burst = VL_RAND_RESET_I(2);
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_valid = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_addr = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_id = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_len = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_size = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_burst = VL_RAND_RESET_I(2);
    vlSelf->PerfSystem__DOT__generator_io_axi_w_valid = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_data = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_strb = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_last = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram_io_axi_r_valid = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram_io_axi_b_valid = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__3 = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__8 = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__7 = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__2 = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9647ad__1 = VL_RAND_RESET_I(2);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__2 = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d94df49__1 = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__6 = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__5 = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__2 = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__1 = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__4 = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__1 = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__1 = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__3 = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__2 = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__0 = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9647ad__0 = VL_RAND_RESET_I(2);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__0 = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d94df49__0 = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__1 = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__0 = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__0 = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT___zz_lfsr = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT___zz_lfsr_2 = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator__DOT__lfsr = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT__currentAddr = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT__burstLen = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__generator__DOT__writeCounter = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT__readCounter = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT__txnData = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__generator__DOT__awDone = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator__DOT__wDone = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_wantStart = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__generator__DOT__when_TrafficGenerator_l79 = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator__DOT__io_axi_aw_fire = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__generator__DOT__io_axi_w_fire = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(80, vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg_string);
    VL_RAND_RESET_W(80, vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext_string);
    vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr = VL_RAND_RESET_I(32);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst = VL_RAND_RESET_I(2);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_valid = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_ready = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_last = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr = VL_RAND_RESET_I(12);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_doResult = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_addr = VL_RAND_RESET_I(12);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_id = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_burst = VL_RAND_RESET_I(2);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_write = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_result = VL_RAND_RESET_I(12);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base = VL_RAND_RESET_I(12);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr = VL_RAND_RESET_I(12);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_valid = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_fire = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_last = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_addr = VL_RAND_RESET_I(12);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_id = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_size = VL_RAND_RESET_I(3);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_burst = VL_RAND_RESET_I(2);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_write = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_1 = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_2 = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_3 = VL_RAND_RESET_I(8);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__locked = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_0 = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_1 = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0 = VL_RAND_RESET_I(1);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_2 = VL_RAND_RESET_I(4);
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_3 = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
