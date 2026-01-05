// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPerfSystem.h for the primary calling header

#include "VPerfSystem__pch.h"
#include "VPerfSystem___024root.h"

extern const VlUnpacked<CData/*2:0*/, 2048> VPerfSystem__ConstPool__TABLE_ha72c7d4f_0;
extern const VlUnpacked<VlWide<3>/*79:0*/, 8> VPerfSystem__ConstPool__TABLE_h4ad435a8_0;

VL_INLINE_OPT void VPerfSystem___024root___ico_sequent__TOP__0(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    SData/*10:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    // Body
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

void VPerfSystem___024root___eval_ico(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VPerfSystem___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VPerfSystem___024root___eval_triggers__ico(VPerfSystem___024root* vlSelf);

bool VPerfSystem___024root___eval_phase__ico(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VPerfSystem___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VPerfSystem___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VPerfSystem___024root___eval_act(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_act\n"); );
}

VL_INLINE_OPT void VPerfSystem___024root___nba_sequent__TOP__0(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0;
    __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0 = 0;
    CData/*7:0*/ __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0;
    __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0 = 0;
    CData/*0:0*/ __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0;
    __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0;
    __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0 = 0;
    CData/*7:0*/ __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0;
    __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0 = 0;
    CData/*0:0*/ __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0;
    __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0;
    __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0 = 0;
    CData/*7:0*/ __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0;
    __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0 = 0;
    CData/*0:0*/ __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0;
    __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0;
    __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0 = 0;
    CData/*7:0*/ __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0;
    __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0 = 0;
    CData/*0:0*/ __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0;
    __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0 = 0;
    // Body
    __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0 = 0U;
    __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0 = 0U;
    __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0 = 0U;
    __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0 = 0U;
    vlSelf->__Vdly__PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat 
        = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat;
    if (((((IData)(vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_strb) 
           >> 3U) & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_fire)) 
         & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write))) {
        __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0 
            = (vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_data 
               >> 0x18U);
        __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0 = 1U;
        __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0 
            = (0x3ffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr) 
                         >> 2U));
    }
    if (((((IData)(vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_strb) 
           >> 2U) & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_fire)) 
         & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write))) {
        __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0 
            = (0xffU & (vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_data 
                        >> 0x10U));
        __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0 = 1U;
        __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0 
            = (0x3ffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr) 
                         >> 2U));
    }
    if (((((IData)(vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_strb) 
           >> 1U) & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_fire)) 
         & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write))) {
        __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0 
            = (0xffU & (vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_data 
                        >> 8U));
        __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0 = 1U;
        __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0 
            = (0x3ffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr) 
                         >> 2U));
    }
    if ((((IData)(vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_strb) 
          & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_fire)) 
         & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write))) {
        __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0 
            = (0xffU & vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_data);
        __Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0 = 1U;
        __Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0 
            = (0x3ffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr) 
                         >> 2U));
    }
    if (vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_ready) {
        vlSelf->__Vdly__PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat 
            = (0xffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat) 
                        - (IData)(1U)));
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_addr 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_result;
    }
    if (vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_fire) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_2 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2
            [(0x3ffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr) 
                        >> 2U))];
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_1 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1
            [(0x3ffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr) 
                        >> 2U))];
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_3 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3
            [(0x3ffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr) 
                        >> 2U))];
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0
            [(0x3ffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr) 
                        >> 2U))];
    }
    if (vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_addr 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr;
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_write 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write;
        if (vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid) {
            vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_id 
                = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_id;
            vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_burst 
                = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_burst;
            vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_size 
                = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size;
        } else {
            vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_id 
                = vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id;
            vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_burst 
                = vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst;
            vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_size 
                = vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size;
        }
    }
    if ((1U & (~ (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid)))) {
        if ((0U != (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len))) {
            if (vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_ready) {
                vlSelf->__Vdly__PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat 
                    = vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len;
                vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len 
                    = vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len;
                vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_addr 
                    = (0xfffU & vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr);
                vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_write 
                    = vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write;
                vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_id 
                    = vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id;
                vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_burst 
                    = vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst;
                vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size 
                    = vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size;
            }
        }
    }
    if ((1U & (~ ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
            if ((1U & (~ (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg)))) {
                vlSelf->PerfSystem__DOT__generator__DOT__burstLen = 0U;
            }
        }
    }
    if (__Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2[__Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0] 
            = __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol2__v0;
    }
    if (__Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1[__Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0] 
            = __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol1__v0;
    }
    if (__Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3[__Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0] 
            = __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol3__v0;
    }
    if (__Vdlyvset__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0[__Vdlyvdim0__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0] 
            = __Vdlyvval__PerfSystem__DOT__sram__DOT__ram__DOT__ram_symbol0__v0;
    }
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase 
        = (7U & ((3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size)) 
                 + ((8U == (8U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len)))
                     ? 3U : ((4U == (0xcU & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len)))
                              ? 2U : ((2U == (0xeU 
                                              & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len)))
                                       ? 1U : 0U)))));
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base 
        = ((~ (((1U < (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                << 1U) | (0U < (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))))) 
           & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_addr));
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr 
        = (0xfffU & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base) 
                     + (((2U == (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                         << 2U) | (((1U == (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                                    << 1U) | (0U == 
                                              (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size)))))));
}

VL_INLINE_OPT void VPerfSystem___024root___nba_sequent__TOP__1(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___nba_sequent__TOP__1\n"); );
    // Init
    SData/*11:0*/ PerfSystem__DOT__sram__DOT__ram__DOT____VdfgExtracted_h3a2d63ce__0;
    PerfSystem__DOT__sram__DOT__ram__DOT____VdfgExtracted_h3a2d63ce__0 = 0;
    // Body
    PerfSystem__DOT__sram__DOT__ram__DOT____VdfgExtracted_h3a2d63ce__0 
        = ((0xfc0U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base)) 
           | (0x3fU & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr)));
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

extern const VlUnpacked<CData/*1:0*/, 256> VPerfSystem__ConstPool__TABLE_ha3607f79_0;
extern const VlUnpacked<CData/*0:0*/, 256> VPerfSystem__ConstPool__TABLE_hbefd2083_0;
extern const VlUnpacked<CData/*0:0*/, 256> VPerfSystem__ConstPool__TABLE_h1b4bad59_0;

VL_INLINE_OPT void VPerfSystem___024root___nba_sequent__TOP__2(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx8;
    __Vtableidx8 = 0;
    IData/*31:0*/ __Vdly__PerfSystem__DOT__generator__DOT__currentAddr;
    __Vdly__PerfSystem__DOT__generator__DOT__currentAddr = 0;
    IData/*31:0*/ __Vdly__PerfSystem__DOT__generator__DOT__writeCounter;
    __Vdly__PerfSystem__DOT__generator__DOT__writeCounter = 0;
    IData/*31:0*/ __Vdly__PerfSystem__DOT__generator__DOT__readCounter;
    __Vdly__PerfSystem__DOT__generator__DOT__readCounter = 0;
    // Body
    __Vdly__PerfSystem__DOT__generator__DOT__readCounter 
        = vlSelf->PerfSystem__DOT__generator__DOT__readCounter;
    __Vdly__PerfSystem__DOT__generator__DOT__writeCounter 
        = vlSelf->PerfSystem__DOT__generator__DOT__writeCounter;
    __Vdly__PerfSystem__DOT__generator__DOT__currentAddr 
        = vlSelf->PerfSystem__DOT__generator__DOT__currentAddr;
    if (vlSelf->reset) {
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__locked = 0U;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_0 = 0U;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_1 = 1U;
        __Vdly__PerfSystem__DOT__generator__DOT__currentAddr = 0U;
        __Vdly__PerfSystem__DOT__generator__DOT__writeCounter = 0U;
        __Vdly__PerfSystem__DOT__generator__DOT__readCounter = 0U;
        vlSelf->PerfSystem__DOT__generator__DOT__txnData = 0U;
        vlSelf->PerfSystem__DOT__generator__DOT__awDone = 0U;
        vlSelf->PerfSystem__DOT__generator__DOT__wDone = 0U;
        vlSelf->PerfSystem__DOT__generator__DOT__lfsr = 0x12345678U;
        vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg = 0U;
    } else {
        if (vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug) {
            vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__locked = 1U;
            vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_0 
                = vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0;
            vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_1 
                = vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write;
        }
        if (((IData)(vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug) 
             & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready))) {
            vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__locked = 0U;
        }
        if ((4U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
            if ((2U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
                if ((1U & (~ (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg)))) {
                    if (vlSelf->PerfSystem__DOT__sram_io_axi_r_valid) {
                        if (vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_last) {
                            __Vdly__PerfSystem__DOT__generator__DOT__readCounter 
                                = ((IData)(1U) + vlSelf->PerfSystem__DOT__generator__DOT__readCounter);
                        }
                    }
                }
            } else if ((1U & (~ (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg)))) {
                if (vlSelf->PerfSystem__DOT__sram_io_axi_b_valid) {
                    __Vdly__PerfSystem__DOT__generator__DOT__writeCounter 
                        = ((IData)(1U) + vlSelf->PerfSystem__DOT__generator__DOT__writeCounter);
                }
            }
        } else if ((2U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
            if ((1U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
                if (vlSelf->PerfSystem__DOT__generator__DOT__io_axi_aw_fire) {
                    vlSelf->PerfSystem__DOT__generator__DOT__awDone = 1U;
                }
                if (vlSelf->PerfSystem__DOT__generator__DOT__io_axi_w_fire) {
                    vlSelf->PerfSystem__DOT__generator__DOT__wDone = 1U;
                }
            } else {
                if ((0x50U > (0x7fU & (vlSelf->PerfSystem__DOT__generator__DOT__lfsr 
                                       >> 7U)))) {
                    __Vdly__PerfSystem__DOT__generator__DOT__currentAddr 
                        = ((IData)(4U) + vlSelf->PerfSystem__DOT__generator__DOT__currentAddr);
                    if (vlSelf->PerfSystem__DOT__generator__DOT__when_TrafficGenerator_l79) {
                        __Vdly__PerfSystem__DOT__generator__DOT__currentAddr = 0U;
                    }
                } else {
                    __Vdly__PerfSystem__DOT__generator__DOT__currentAddr 
                        = (0x7ffffcU & (vlSelf->PerfSystem__DOT__generator__DOT__lfsr 
                                        << 2U));
                }
                if ((0x32U > (0x7fU & vlSelf->PerfSystem__DOT__generator__DOT__lfsr))) {
                    vlSelf->PerfSystem__DOT__generator__DOT__txnData 
                        = vlSelf->PerfSystem__DOT__generator__DOT__lfsr;
                }
            }
        }
        if (((3U != (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg)) 
             & (3U == (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext)))) {
            vlSelf->PerfSystem__DOT__generator__DOT__awDone = 0U;
            vlSelf->PerfSystem__DOT__generator__DOT__wDone = 0U;
        }
        if (vlSelf->io_enable) {
            vlSelf->PerfSystem__DOT__generator__DOT__lfsr 
                = (vlSelf->PerfSystem__DOT__generator__DOT___zz_lfsr 
                   | (IData)(vlSelf->PerfSystem__DOT__generator__DOT___zz_lfsr_2));
        }
        vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg 
            = vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext;
    }
    __Vtableidx8 = (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_valid) 
                     << 7U) | (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready) 
                                << 6U) | (((IData)(vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug) 
                                           << 5U) | 
                                          (((0U != (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len)) 
                                            << 4U) 
                                           | (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid) 
                                               << 3U) 
                                              | (((1U 
                                                   == (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat)) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_ready) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->reset))))))));
    if ((1U & VPerfSystem__ConstPool__TABLE_ha3607f79_0
         [__Vtableidx8])) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid 
            = VPerfSystem__ConstPool__TABLE_hbefd2083_0
            [__Vtableidx8];
    }
    if ((2U & VPerfSystem__ConstPool__TABLE_ha3607f79_0
         [__Vtableidx8])) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid 
            = VPerfSystem__ConstPool__TABLE_h1b4bad59_0
            [__Vtableidx8];
    }
    vlSelf->PerfSystem__DOT__generator__DOT__writeCounter 
        = __Vdly__PerfSystem__DOT__generator__DOT__writeCounter;
    vlSelf->PerfSystem__DOT__generator__DOT__readCounter 
        = __Vdly__PerfSystem__DOT__generator__DOT__readCounter;
    vlSelf->PerfSystem__DOT__generator__DOT__currentAddr 
        = __Vdly__PerfSystem__DOT__generator__DOT__currentAddr;
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
            }
        }
    }
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_id 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__5;
    if ((4U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
                vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_id = 0U;
            }
        }
    }
}

extern const VlUnpacked<CData/*0:0*/, 8> VPerfSystem__ConstPool__TABLE_h14e0e0b9_0;
extern const VlUnpacked<CData/*0:0*/, 16> VPerfSystem__ConstPool__TABLE_h171d64e5_0;
extern const VlUnpacked<CData/*0:0*/, 8> VPerfSystem__ConstPool__TABLE_h70de94fd_0;

VL_INLINE_OPT void VPerfSystem___024root___nba_sequent__TOP__3(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___nba_sequent__TOP__3\n"); );
    // Init
    CData/*1:0*/ PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0;
    PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*3:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*2:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*2:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_size 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__2;
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_burst 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9647ad__1;
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_addr 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__0;
    if ((1U & (~ ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
            if ((1U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
                vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_addr 
                    = vlSelf->PerfSystem__DOT__generator__DOT__currentAddr;
            }
        }
    }
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_addr 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d93fe75__2;
    if ((4U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
                vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_size = 2U;
                vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_burst = 1U;
                vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_addr 
                    = vlSelf->PerfSystem__DOT__generator__DOT__currentAddr;
            }
        }
    }
    __Vtableidx6 = vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg;
    vlSelf->PerfSystem__DOT__generator__DOT__fsm_wantStart 
        = VPerfSystem__ConstPool__TABLE_h14e0e0b9_0
        [__Vtableidx6];
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
    PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0 
        = (((IData)(vlSelf->PerfSystem__DOT__generator_io_axi_aw_valid) 
            << 1U) | (IData)(vlSelf->PerfSystem__DOT__generator_io_axi_ar_valid));
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_2 
        = (0xfU & ((~ ((((IData)(PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0) 
                         << 2U) | (IData)(PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0)) 
                       - (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_0) 
                           << 1U) | (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_1)))) 
                   & (((IData)(PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0) 
                       << 2U) | (IData)(PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0))));
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
    } else {
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id 
            = vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_id;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size 
            = vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_size;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst 
            = vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_burst;
        vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr 
            = vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_addr;
    }
    vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug 
        = (((IData)(vlSelf->PerfSystem__DOT__generator_io_axi_ar_valid) 
            & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)) 
           | ((IData)(vlSelf->PerfSystem__DOT__generator_io_axi_aw_valid) 
              & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write)));
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_valid 
        = ((IData)(vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug) 
           | (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid));
}

VL_INLINE_OPT void VPerfSystem___024root___nba_sequent__TOP__4(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___nba_sequent__TOP__4\n"); );
    // Body
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat 
        = vlSelf->__Vdly__PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat;
    if (vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_last 
            = vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_last;
    }
}

VL_INLINE_OPT void VPerfSystem___024root___nba_comb__TOP__0(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___nba_comb__TOP__0\n"); );
    // Init
    CData/*0:0*/ PerfSystem__DOT__sram__DOT__ram__DOT___zz_unburstify_result_ready;
    PerfSystem__DOT__sram__DOT__ram__DOT___zz_unburstify_result_ready = 0;
    CData/*2:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    SData/*10:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    // Body
    vlSelf->PerfSystem__DOT__sram_io_axi_r_valid = 
        ((~ (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_write)) 
         & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid));
    vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_len 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d94df49__0;
    if ((1U & (~ ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
            if ((1U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
                vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_len 
                    = vlSelf->PerfSystem__DOT__generator__DOT__burstLen;
            }
        }
    }
    vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_len 
        = vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d94df49__1;
    if ((4U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg))) {
                vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_len 
                    = vlSelf->PerfSystem__DOT__generator__DOT__burstLen;
            }
        }
    }
    vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready = 1U;
    if ((1U & (~ (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid)))) {
        vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready = 1U;
    }
    vlSelf->PerfSystem__DOT__sram_io_axi_b_valid = 
        ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid) 
         & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_write) 
            & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_last)));
    vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len 
        = ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
            ? (IData)(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_len)
            : (IData)(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_len));
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

void VPerfSystem___024root___eval_nba(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VPerfSystem___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        VPerfSystem___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VPerfSystem___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        VPerfSystem___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VPerfSystem___024root___nba_sequent__TOP__4(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VPerfSystem___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
}

void VPerfSystem___024root___eval_triggers__act(VPerfSystem___024root* vlSelf);

bool VPerfSystem___024root___eval_phase__act(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VPerfSystem___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VPerfSystem___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VPerfSystem___024root___eval_phase__nba(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VPerfSystem___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPerfSystem___024root___dump_triggers__ico(VPerfSystem___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VPerfSystem___024root___dump_triggers__nba(VPerfSystem___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VPerfSystem___024root___dump_triggers__act(VPerfSystem___024root* vlSelf);
#endif  // VL_DEBUG

void VPerfSystem___024root___eval(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval\n"); );
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
            VPerfSystem___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/stone/assap/tmp/job_1/PerfSystem.v", 7, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VPerfSystem___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VPerfSystem___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/stone/assap/tmp/job_1/PerfSystem.v", 7, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VPerfSystem___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/stone/assap/tmp/job_1/PerfSystem.v", 7, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VPerfSystem___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VPerfSystem___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VPerfSystem___024root___eval_debug_assertions(VPerfSystem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->io_enable & 0xfeU))) {
        Verilated::overWidthError("io_enable");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
