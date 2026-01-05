// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPerfSystem__Syms.h"


void VPerfSystem___024root__trace_chg_0_sub_0(VPerfSystem___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VPerfSystem___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_chg_0\n"); );
    // Init
    VPerfSystem___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPerfSystem___024root*>(voidSelf);
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VPerfSystem___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VPerfSystem___024root__trace_chg_0_sub_0(VPerfSystem___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgCData(oldp+0,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__6),4);
        bufp->chgBit(oldp+1,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__2));
        bufp->chgCData(oldp+2,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__7),4);
        bufp->chgCData(oldp+3,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__8),4);
        bufp->chgCData(oldp+4,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__3),3);
        bufp->chgCData(oldp+5,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__1),4);
        bufp->chgBit(oldp+6,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__0));
        bufp->chgCData(oldp+7,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__2),4);
        bufp->chgCData(oldp+8,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__3),4);
        bufp->chgCData(oldp+9,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__1),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+10,((((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_3) 
                                  << 0x18U) | (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_2) 
                                                << 0x10U) 
                                               | (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_1) 
                                                   << 8U) 
                                                  | (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read))))),32);
        bufp->chgCData(oldp+11,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_id),4);
        bufp->chgCData(oldp+12,(vlSelf->PerfSystem__DOT__generator__DOT__burstLen),8);
        bufp->chgCData(oldp+13,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len),8);
        bufp->chgSData(oldp+14,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_addr),12);
        bufp->chgCData(oldp+15,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_id),4);
        bufp->chgCData(oldp+16,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size),3);
        bufp->chgCData(oldp+17,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_burst),2);
        bufp->chgBit(oldp+18,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_write));
        bufp->chgCData(oldp+19,((3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))),2);
        bufp->chgSData(oldp+20,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_result),12);
        bufp->chgCData(oldp+21,((((2U == (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                                  << 2U) | (((1U == 
                                              (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                                             << 1U) 
                                            | (0U == 
                                               (3U 
                                                & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size)))))),3);
        bufp->chgSData(oldp+22,((((1U < (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                                  << 1U) | (0U < (3U 
                                                  & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))))),12);
        bufp->chgSData(oldp+23,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base),12);
        bufp->chgSData(oldp+24,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr),12);
        bufp->chgCData(oldp+25,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase),3);
        bufp->chgBit(oldp+26,(1U));
        bufp->chgSData(oldp+27,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_addr),12);
        bufp->chgCData(oldp+28,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_size),3);
        bufp->chgCData(oldp+29,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_burst),2);
        bufp->chgBit(oldp+30,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_write));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+31,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_valid));
        bufp->chgIData(oldp+32,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_addr),32);
        bufp->chgCData(oldp+33,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_id),4);
        bufp->chgCData(oldp+34,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_size),3);
        bufp->chgCData(oldp+35,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_burst),2);
        bufp->chgBit(oldp+36,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_valid));
        bufp->chgIData(oldp+37,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_addr),32);
        bufp->chgCData(oldp+38,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_id),4);
        bufp->chgCData(oldp+39,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_size),3);
        bufp->chgCData(oldp+40,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_burst),2);
        bufp->chgBit(oldp+41,(vlSelf->PerfSystem__DOT__generator_io_axi_w_valid));
        bufp->chgIData(oldp+42,(vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_data),32);
        bufp->chgCData(oldp+43,(vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_strb),4);
        bufp->chgBit(oldp+44,(vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_last));
        bufp->chgBit(oldp+45,(vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug));
        bufp->chgIData(oldp+46,(vlSelf->PerfSystem__DOT__generator__DOT__lfsr),32);
        bufp->chgBit(oldp+47,((1U & VL_REDXOR_32((0x80200003U 
                                                  & vlSelf->PerfSystem__DOT__generator__DOT__lfsr)))));
        bufp->chgCData(oldp+48,((0x7fU & vlSelf->PerfSystem__DOT__generator__DOT__lfsr)),7);
        bufp->chgBit(oldp+49,((0x32U > (0x7fU & vlSelf->PerfSystem__DOT__generator__DOT__lfsr))));
        bufp->chgCData(oldp+50,((0x7fU & (vlSelf->PerfSystem__DOT__generator__DOT__lfsr 
                                          >> 7U))),7);
        bufp->chgBit(oldp+51,((0x50U > (0x7fU & (vlSelf->PerfSystem__DOT__generator__DOT__lfsr 
                                                 >> 7U)))));
        bufp->chgIData(oldp+52,(vlSelf->PerfSystem__DOT__generator__DOT__currentAddr),32);
        bufp->chgIData(oldp+53,(vlSelf->PerfSystem__DOT__generator__DOT__writeCounter),32);
        bufp->chgIData(oldp+54,(vlSelf->PerfSystem__DOT__generator__DOT__readCounter),32);
        bufp->chgIData(oldp+55,(vlSelf->PerfSystem__DOT__generator__DOT__txnData),32);
        bufp->chgBit(oldp+56,(vlSelf->PerfSystem__DOT__generator__DOT__awDone));
        bufp->chgBit(oldp+57,(vlSelf->PerfSystem__DOT__generator__DOT__wDone));
        bufp->chgBit(oldp+58,(vlSelf->PerfSystem__DOT__generator__DOT__fsm_wantStart));
        bufp->chgCData(oldp+59,(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg),3);
        bufp->chgBit(oldp+60,((0x1000U <= vlSelf->PerfSystem__DOT__generator__DOT__currentAddr)));
        bufp->chgWData(oldp+61,(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg_string),80);
        bufp->chgSData(oldp+64,((0xfffU & vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr)),12);
        bufp->chgBit(oldp+65,(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write));
        bufp->chgIData(oldp+66,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr),32);
        bufp->chgCData(oldp+67,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id),4);
        bufp->chgCData(oldp+68,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
                                  ? (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__6)
                                  : (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__1))),4);
        bufp->chgCData(oldp+69,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size),3);
        bufp->chgCData(oldp+70,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst),2);
        bufp->chgBit(oldp+71,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
                                ? (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__2)
                                : (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__0))));
        bufp->chgCData(oldp+72,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
                                  ? (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__7)
                                  : (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__2))),4);
        bufp->chgCData(oldp+73,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
                                  ? (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__8)
                                  : (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__3))),4);
        bufp->chgCData(oldp+74,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
                                  ? (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__3)
                                  : (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__1))),3);
        bufp->chgCData(oldp+75,((((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write) 
                                  << 1U) | (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0))),2);
        bufp->chgBit(oldp+76,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_valid));
        bufp->chgBit(oldp+77,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid));
        bufp->chgBit(oldp+78,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid));
        bufp->chgBit(oldp+79,((1U & (~ (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid)))));
        bufp->chgBit(oldp+80,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__locked));
        bufp->chgBit(oldp+81,((1U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_3))));
        bufp->chgBit(oldp+82,((1U & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_3) 
                                     >> 1U))));
        bufp->chgBit(oldp+83,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_0));
        bufp->chgBit(oldp+84,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_1));
        bufp->chgBit(oldp+85,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[2U] 
                     | vlSelf->__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+86,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0) 
                               & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready))));
        bufp->chgBit(oldp+87,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write) 
                               & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready))));
        bufp->chgBit(oldp+88,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_valid) 
                               & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write) 
                                  & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready)))));
        bufp->chgBit(oldp+89,((((IData)(vlSelf->PerfSystem__DOT__generator__DOT__awDone) 
                                | (IData)(vlSelf->PerfSystem__DOT__generator__DOT__io_axi_aw_fire)) 
                               & ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__wDone) 
                                  | (IData)(vlSelf->PerfSystem__DOT__generator__DOT__io_axi_w_fire)))));
        bufp->chgBit(oldp+90,(((IData)(vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug) 
                               & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+91,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_last));
        bufp->chgCData(oldp+92,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat),8);
        bufp->chgBit(oldp+93,((1U == (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgCData(oldp+94,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_len),8);
        bufp->chgCData(oldp+95,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_len),8);
        bufp->chgBit(oldp+96,(vlSelf->PerfSystem__DOT__sram_io_axi_r_valid));
        bufp->chgBit(oldp+97,(vlSelf->PerfSystem__DOT__sram_io_axi_b_valid));
        bufp->chgBit(oldp+98,(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready));
        bufp->chgBit(oldp+99,(vlSelf->PerfSystem__DOT__generator__DOT__io_axi_aw_fire));
        bufp->chgBit(oldp+100,(vlSelf->PerfSystem__DOT__generator__DOT__io_axi_w_fire));
        bufp->chgCData(oldp+101,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len),8);
        bufp->chgBit(oldp+102,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_ready));
        bufp->chgBit(oldp+103,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_last));
        bufp->chgSData(oldp+104,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr),12);
        bufp->chgBit(oldp+105,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write));
        bufp->chgBit(oldp+106,((0U != (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len))));
        bufp->chgBit(oldp+107,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_valid));
        bufp->chgBit(oldp+108,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready));
        bufp->chgBit(oldp+109,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_fire));
    }
    bufp->chgBit(oldp+110,(vlSelf->io_enable));
    bufp->chgIData(oldp+111,(vlSelf->io_writeCount),32);
    bufp->chgIData(oldp+112,(vlSelf->io_readCount),32);
    bufp->chgBit(oldp+113,(vlSelf->clk));
    bufp->chgBit(oldp+114,(vlSelf->reset));
    bufp->chgCData(oldp+115,(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext),3);
    bufp->chgBit(oldp+116,(((3U != (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg)) 
                            & (3U == (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext)))));
    bufp->chgWData(oldp+117,(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext_string),80);
    bufp->chgCData(oldp+120,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid)
                               ? (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_id)
                               : (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id))),4);
    bufp->chgCData(oldp+121,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid)
                               ? (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size)
                               : (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size))),3);
    bufp->chgCData(oldp+122,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid)
                               ? (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_burst)
                               : (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst))),2);
}

void VPerfSystem___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_cleanup\n"); );
    // Init
    VPerfSystem___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPerfSystem___024root*>(voidSelf);
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
