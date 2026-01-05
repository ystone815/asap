// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VNativePerfSystem__Syms.h"


void VNativePerfSystem___024root__trace_chg_0_sub_0(VNativePerfSystem___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VNativePerfSystem___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root__trace_chg_0\n"); );
    // Init
    VNativePerfSystem___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VNativePerfSystem___024root*>(voidSelf);
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VNativePerfSystem___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VNativePerfSystem___024root__trace_chg_0_sub_0(VNativePerfSystem___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->NativePerfSystem__DOT__gen__DOT__addrReg),32);
        bufp->chgIData(oldp+1,(vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr),32);
        bufp->chgBit(oldp+2,((0x32U > (0x7fU & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr))));
        bufp->chgBit(oldp+3,((1U & VL_REDXOR_32((0x80200003U 
                                                 & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr)))));
        bufp->chgCData(oldp+4,((0x7fU & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr)),7);
        bufp->chgBit(oldp+5,((0x50U > (0x7fU & (vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr 
                                                >> 7U)))));
    }
    bufp->chgBit(oldp+6,(vlSelf->io_enable));
    bufp->chgIData(oldp+7,(vlSelf->io_totalTxns),32);
    bufp->chgBit(oldp+8,(vlSelf->clk));
    bufp->chgBit(oldp+9,(vlSelf->reset));
    bufp->chgBit(oldp+10,(vlSelf->NativePerfSystem__DOT__mem__DOT__rspValid));
    bufp->chgIData(oldp+11,(vlSelf->NativePerfSystem__DOT__mem__DOT___zz_mem_port0),32);
    bufp->chgIData(oldp+12,(vlSelf->NativePerfSystem__DOT__gen__DOT__counter),32);
    bufp->chgBit(oldp+13,(((0x32U > (0x7fU & vlSelf->NativePerfSystem__DOT__gen__DOT__lfsr)) 
                           & (IData)(vlSelf->io_enable))));
}

void VNativePerfSystem___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNativePerfSystem___024root__trace_cleanup\n"); );
    // Init
    VNativePerfSystem___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VNativePerfSystem___024root*>(voidSelf);
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
