// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPerfSystem__Syms.h"


VL_ATTR_COLD void VPerfSystem___024root__trace_init_sub__TOP__0(VPerfSystem___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+111,0,"io_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"io_writeCount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"io_readCount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+114,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("PerfSystem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+111,0,"io_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"io_writeCount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"io_readCount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+114,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"generator_io_axi_ar_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"generator_io_axi_ar_payload_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"generator_io_axi_ar_payload_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1,0,"generator_io_axi_ar_payload_region",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+95,0,"generator_io_axi_ar_payload_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+35,0,"generator_io_axi_ar_payload_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+36,0,"generator_io_axi_ar_payload_burst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+2,0,"generator_io_axi_ar_payload_lock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+3,0,"generator_io_axi_ar_payload_cache",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"generator_io_axi_ar_payload_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"generator_io_axi_ar_payload_prot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+37,0,"generator_io_axi_aw_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"generator_io_axi_aw_payload_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"generator_io_axi_aw_payload_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+6,0,"generator_io_axi_aw_payload_region",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+96,0,"generator_io_axi_aw_payload_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"generator_io_axi_aw_payload_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+41,0,"generator_io_axi_aw_payload_burst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+7,0,"generator_io_axi_aw_payload_lock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+8,0,"generator_io_axi_aw_payload_cache",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+9,0,"generator_io_axi_aw_payload_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+10,0,"generator_io_axi_aw_payload_prot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+42,0,"generator_io_axi_w_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"generator_io_axi_w_payload_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"generator_io_axi_w_payload_strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+45,0,"generator_io_axi_w_payload_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"generator_io_axi_r_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"generator_io_axi_b_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"generator_io_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"generator_io_writeCount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"generator_io_readCount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+87,0,"sram_io_axi_ar_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"sram_io_axi_aw_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"sram_io_axi_w_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"sram_io_axi_r_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"sram_io_axi_r_payload_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"sram_io_axi_r_payload_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"sram_io_axi_r_payload_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+92,0,"sram_io_axi_r_payload_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"sram_io_axi_b_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"sram_io_axi_b_payload_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"sram_io_axi_b_payload_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+46,0,"sram_io_arw_valid_debug",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"sram_io_arw_ready_debug",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("generator", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+37,0,"io_axi_aw_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"io_axi_aw_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"io_axi_aw_payload_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"io_axi_aw_payload_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+6,0,"io_axi_aw_payload_region",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+96,0,"io_axi_aw_payload_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"io_axi_aw_payload_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+41,0,"io_axi_aw_payload_burst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+7,0,"io_axi_aw_payload_lock",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+8,0,"io_axi_aw_payload_cache",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+9,0,"io_axi_aw_payload_qos",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+10,0,"io_axi_aw_payload_prot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+42,0,"io_axi_w_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"io_axi_w_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"io_axi_w_payload_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"io_axi_w_payload_strb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+45,0,"io_axi_w_payload_last",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"io_axi_b_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"io_axi_b_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"io_axi_b_payload_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"io_axi_b_payload_resp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+32,0,"io_axi_ar_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"io_axi_ar_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"io_axi_ar_payload_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"io_axi_ar_payload_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1,0,"io_axi_ar_payload_region",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+95,0,"io_axi_ar_payload_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+35,0,"io_axi_ar_payload_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+36,0,"io_axi_ar_payload_burst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+2,0,"io_axi_ar_payload_lock",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+3,0,"io_axi_ar_payload_cache",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"io_axi_ar_payload_qos",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"io_axi_ar_payload_prot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+97,0,"io_axi_r_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"io_axi_r_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"io_axi_r_payload_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"io_axi_r_payload_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"io_axi_r_payload_resp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+92,0,"io_axi_r_payload_last",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"io_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"io_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"io_writeCount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"io_readCount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+114,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"fsm_enumDef_BOOT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+128,0,"fsm_enumDef_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+129,0,"fsm_enumDef_PREPARE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+130,0,"fsm_enumDef_WRITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+131,0,"fsm_enumDef_WRITE_RESP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+132,0,"fsm_enumDef_READ_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+133,0,"fsm_enumDef_READ_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+47,0,"lfsr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+48,0,"feedback",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"rnd100",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+50,0,"isWrite",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"rndLocality",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+52,0,"isSequential",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+53,0,"currentAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"burstLen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+54,0,"writeCounter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"readCounter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"txnData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+57,0,"awDone",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"wDone",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"fsm_wantExit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"fsm_wantStart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"fsm_wantKill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"fsm_stateReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+116,0,"fsm_stateNext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+61,0,"when_TrafficGenerator_l79",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"io_axi_aw_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"io_axi_w_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"when_TrafficGenerator_l124",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"when_StateMachine_l253",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+62,0,"fsm_stateReg_string",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 79,0);
    tracep->declArray(c+118,0,"fsm_stateNext_string",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 79,0);
    tracep->popPrefix();
    tracep->pushPrefix("sram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+37,0,"io_axi_aw_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"io_axi_aw_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"io_axi_aw_payload_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"io_axi_aw_payload_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+6,0,"io_axi_aw_payload_region",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+96,0,"io_axi_aw_payload_len",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"io_axi_aw_payload_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+41,0,"io_axi_aw_payload_burst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+7,0,"io_axi_aw_payload_lock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+8,0,"io_axi_aw_payload_cache",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+9,0,"io_axi_aw_payload_qos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+10,0,"io_axi_aw_payload_prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+42,0,"io_axi_w_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"io_axi_w_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"io_axi_w_payload_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"io_axi_w_payload_strb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+45,0,"io_axi_w_payload_last",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"io_axi_b_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"io_axi_b_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"io_axi_b_payload_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"io_axi_b_payload_resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+32,0,"io_axi_ar_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"io_axi_ar_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"io_axi_ar_payload_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"io_axi_ar_payload_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1,0,"io_axi_ar_payload_region",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+95,0,"io_axi_ar_payload_len",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+35,0,"io_axi_ar_payload_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+36,0,"io_axi_ar_payload_burst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+2,0,"io_axi_ar_payload_lock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+3,0,"io_axi_ar_payload_cache",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"io_axi_ar_payload_qos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"io_axi_ar_payload_prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+97,0,"io_axi_r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"io_axi_r_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"io_axi_r_payload_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"io_axi_r_payload_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"io_axi_r_payload_resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+92,0,"io_axi_r_payload_last",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"io_arw_valid_debug",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"io_arw_ready_debug",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+65,0,"ram_io_axi_arw_payload_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+66,0,"ram_io_axi_arw_payload_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"ram_io_axi_arw_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"ram_io_axi_w_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"ram_io_axi_b_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"ram_io_axi_b_payload_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"ram_io_axi_b_payload_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+97,0,"ram_io_axi_r_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"ram_io_axi_r_payload_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"ram_io_axi_r_payload_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"ram_io_axi_r_payload_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+92,0,"ram_io_axi_r_payload_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"streamArbiter_1_io_inputs_0_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"streamArbiter_1_io_inputs_1_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"streamArbiter_1_io_output_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"streamArbiter_1_io_output_payload_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"streamArbiter_1_io_output_payload_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+69,0,"streamArbiter_1_io_output_payload_region",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+102,0,"streamArbiter_1_io_output_payload_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+70,0,"streamArbiter_1_io_output_payload_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+71,0,"streamArbiter_1_io_output_payload_burst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+72,0,"streamArbiter_1_io_output_payload_lock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+73,0,"streamArbiter_1_io_output_payload_cache",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+74,0,"streamArbiter_1_io_output_payload_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+75,0,"streamArbiter_1_io_output_payload_prot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+66,0,"streamArbiter_1_io_chosen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+76,0,"streamArbiter_1_io_chosenOH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("ram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+46,0,"io_axi_arw_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"io_axi_arw_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+65,0,"io_axi_arw_payload_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+68,0,"io_axi_arw_payload_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+102,0,"io_axi_arw_payload_len",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+70,0,"io_axi_arw_payload_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+71,0,"io_axi_arw_payload_burst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+66,0,"io_axi_arw_payload_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"io_axi_w_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"io_axi_w_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"io_axi_w_payload_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"io_axi_w_payload_strb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+45,0,"io_axi_w_payload_last",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"io_axi_b_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"io_axi_b_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"io_axi_b_payload_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"io_axi_b_payload_resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+97,0,"io_axi_r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"io_axi_r_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"io_axi_r_payload_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"io_axi_r_payload_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"io_axi_r_payload_resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+92,0,"io_axi_r_payload_last",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"unburstify_result_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"unburstify_result_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"unburstify_result_payload_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"unburstify_result_payload_fragment_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+121,0,"unburstify_result_payload_fragment_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+122,0,"unburstify_result_payload_fragment_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+123,0,"unburstify_result_payload_fragment_burst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+106,0,"unburstify_result_payload_fragment_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"unburstify_doResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"unburstify_buffer_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+14,0,"unburstify_buffer_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+93,0,"unburstify_buffer_beat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+15,0,"unburstify_buffer_transaction_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+16,0,"unburstify_buffer_transaction_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+17,0,"unburstify_buffer_transaction_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+18,0,"unburstify_buffer_transaction_burst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+19,0,"unburstify_buffer_transaction_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"unburstify_buffer_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"Axi4Incr_validSize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+21,0,"Axi4Incr_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+22,0,"Axi4Incr_sizeValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+23,0,"Axi4Incr_alignMask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
}

VL_ATTR_COLD void VPerfSystem___024root__trace_init_sub__TOP__1(VPerfSystem___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_init_sub__TOP__1\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+24,0,"Axi4Incr_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+25,0,"Axi4Incr_baseIncr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+26,0,"Axi4Incr_wrapCase",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+107,0,"when_Axi4Channel_l322",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"stage0_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"stage0_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"stage0_payload_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"stage0_payload_fragment_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+121,0,"stage0_payload_fragment_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+122,0,"stage0_payload_fragment_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+123,0,"stage0_payload_fragment_burst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+106,0,"stage0_payload_fragment_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"stage0_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"stage1_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"stage1_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"stage1_payload_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"stage1_payload_fragment_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+12,0,"stage1_payload_fragment_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+29,0,"stage1_payload_fragment_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+30,0,"stage1_payload_fragment_burst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+31,0,"stage1_payload_fragment_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"stage0_rValid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"stage0_rData_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"stage0_rData_fragment_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+12,0,"stage0_rData_fragment_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+29,0,"stage0_rData_fragment_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+30,0,"stage0_rData_fragment_burst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+31,0,"stage0_rData_fragment_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"when_Stream_l369",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("streamArbiter_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+32,0,"io_inputs_0_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"io_inputs_0_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"io_inputs_0_payload_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"io_inputs_0_payload_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1,0,"io_inputs_0_payload_region",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+95,0,"io_inputs_0_payload_len",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+35,0,"io_inputs_0_payload_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+36,0,"io_inputs_0_payload_burst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+2,0,"io_inputs_0_payload_lock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+3,0,"io_inputs_0_payload_cache",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"io_inputs_0_payload_qos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"io_inputs_0_payload_prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+37,0,"io_inputs_1_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"io_inputs_1_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"io_inputs_1_payload_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"io_inputs_1_payload_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+6,0,"io_inputs_1_payload_region",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+96,0,"io_inputs_1_payload_len",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"io_inputs_1_payload_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+41,0,"io_inputs_1_payload_burst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+7,0,"io_inputs_1_payload_lock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+8,0,"io_inputs_1_payload_cache",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+9,0,"io_inputs_1_payload_qos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+10,0,"io_inputs_1_payload_prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+46,0,"io_output_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"io_output_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"io_output_payload_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"io_output_payload_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+69,0,"io_output_payload_region",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+102,0,"io_output_payload_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+70,0,"io_output_payload_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+71,0,"io_output_payload_burst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+72,0,"io_output_payload_lock",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+73,0,"io_output_payload_cache",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+74,0,"io_output_payload_qos",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+75,0,"io_output_payload_prot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+66,0,"io_chosen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+76,0,"io_chosenOH",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+114,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"locked",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"maskProposal_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"maskProposal_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"maskLocked_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"maskLocked_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"maskRouted_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"maskRouted_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"io_output_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VPerfSystem___024root__trace_init_top(VPerfSystem___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_init_top\n"); );
    // Body
    VPerfSystem___024root__trace_init_sub__TOP__0(vlSelf, tracep);
    VPerfSystem___024root__trace_init_sub__TOP__1(vlSelf, tracep);
}

VL_ATTR_COLD void VPerfSystem___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VPerfSystem___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VPerfSystem___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VPerfSystem___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VPerfSystem___024root__trace_register(VPerfSystem___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&VPerfSystem___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VPerfSystem___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VPerfSystem___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VPerfSystem___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VPerfSystem___024root__trace_const_0_sub_0(VPerfSystem___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VPerfSystem___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_const_0\n"); );
    // Init
    VPerfSystem___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPerfSystem___024root*>(voidSelf);
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VPerfSystem___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VPerfSystem___024root__trace_const_0_sub_0(VPerfSystem___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+124,(1U));
    bufp->fullBit(oldp+125,(0U));
    bufp->fullCData(oldp+126,(0U),2);
    bufp->fullCData(oldp+127,(0U),3);
    bufp->fullCData(oldp+128,(1U),3);
    bufp->fullCData(oldp+129,(2U),3);
    bufp->fullCData(oldp+130,(3U),3);
    bufp->fullCData(oldp+131,(4U),3);
    bufp->fullCData(oldp+132,(5U),3);
    bufp->fullCData(oldp+133,(6U),3);
    bufp->fullBit(oldp+134,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_doResult));
}

VL_ATTR_COLD void VPerfSystem___024root__trace_full_0_sub_0(VPerfSystem___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VPerfSystem___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_full_0\n"); );
    // Init
    VPerfSystem___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPerfSystem___024root*>(voidSelf);
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VPerfSystem___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VPerfSystem___024root__trace_full_0_sub_0(VPerfSystem___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPerfSystem___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__6),4);
    bufp->fullBit(oldp+2,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__2));
    bufp->fullCData(oldp+3,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__7),4);
    bufp->fullCData(oldp+4,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__8),4);
    bufp->fullCData(oldp+5,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__3),3);
    bufp->fullCData(oldp+6,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__1),4);
    bufp->fullBit(oldp+7,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__0));
    bufp->fullCData(oldp+8,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__2),4);
    bufp->fullCData(oldp+9,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__3),4);
    bufp->fullCData(oldp+10,(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__1),3);
    bufp->fullIData(oldp+11,((((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_3) 
                               << 0x18U) | (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_2) 
                                             << 0x10U) 
                                            | (((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read_1) 
                                                << 8U) 
                                               | (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT___zz_ramsymbol_read))))),32);
    bufp->fullCData(oldp+12,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_id),4);
    bufp->fullCData(oldp+13,(vlSelf->PerfSystem__DOT__generator__DOT__burstLen),8);
    bufp->fullCData(oldp+14,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_len),8);
    bufp->fullSData(oldp+15,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_addr),12);
    bufp->fullCData(oldp+16,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_id),4);
    bufp->fullCData(oldp+17,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size),3);
    bufp->fullCData(oldp+18,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_burst),2);
    bufp->fullBit(oldp+19,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_write));
    bufp->fullCData(oldp+20,((3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))),2);
    bufp->fullSData(oldp+21,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_result),12);
    bufp->fullCData(oldp+22,((((2U == (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                               << 2U) | (((1U == (3U 
                                                  & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                                          << 1U) | 
                                         (0U == (3U 
                                                 & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size)))))),3);
    bufp->fullSData(oldp+23,((((1U < (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))) 
                               << 1U) | (0U < (3U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size))))),12);
    bufp->fullSData(oldp+24,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_base),12);
    bufp->fullSData(oldp+25,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_baseIncr),12);
    bufp->fullCData(oldp+26,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__Axi4Incr_wrapCase),3);
    bufp->fullBit(oldp+27,(1U));
    bufp->fullSData(oldp+28,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_addr),12);
    bufp->fullCData(oldp+29,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_size),3);
    bufp->fullCData(oldp+30,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_burst),2);
    bufp->fullBit(oldp+31,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_fragment_write));
    bufp->fullBit(oldp+32,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_valid));
    bufp->fullIData(oldp+33,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_addr),32);
    bufp->fullCData(oldp+34,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_id),4);
    bufp->fullCData(oldp+35,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_size),3);
    bufp->fullCData(oldp+36,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_burst),2);
    bufp->fullBit(oldp+37,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_valid));
    bufp->fullIData(oldp+38,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_addr),32);
    bufp->fullCData(oldp+39,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_id),4);
    bufp->fullCData(oldp+40,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_size),3);
    bufp->fullCData(oldp+41,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_burst),2);
    bufp->fullBit(oldp+42,(vlSelf->PerfSystem__DOT__generator_io_axi_w_valid));
    bufp->fullIData(oldp+43,(vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_data),32);
    bufp->fullCData(oldp+44,(vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_strb),4);
    bufp->fullBit(oldp+45,(vlSelf->PerfSystem__DOT__generator_io_axi_w_payload_last));
    bufp->fullBit(oldp+46,(vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug));
    bufp->fullIData(oldp+47,(vlSelf->PerfSystem__DOT__generator__DOT__lfsr),32);
    bufp->fullBit(oldp+48,((1U & VL_REDXOR_32((0x80200003U 
                                               & vlSelf->PerfSystem__DOT__generator__DOT__lfsr)))));
    bufp->fullCData(oldp+49,((0x7fU & vlSelf->PerfSystem__DOT__generator__DOT__lfsr)),7);
    bufp->fullBit(oldp+50,((0x32U > (0x7fU & vlSelf->PerfSystem__DOT__generator__DOT__lfsr))));
    bufp->fullCData(oldp+51,((0x7fU & (vlSelf->PerfSystem__DOT__generator__DOT__lfsr 
                                       >> 7U))),7);
    bufp->fullBit(oldp+52,((0x50U > (0x7fU & (vlSelf->PerfSystem__DOT__generator__DOT__lfsr 
                                              >> 7U)))));
    bufp->fullIData(oldp+53,(vlSelf->PerfSystem__DOT__generator__DOT__currentAddr),32);
    bufp->fullIData(oldp+54,(vlSelf->PerfSystem__DOT__generator__DOT__writeCounter),32);
    bufp->fullIData(oldp+55,(vlSelf->PerfSystem__DOT__generator__DOT__readCounter),32);
    bufp->fullIData(oldp+56,(vlSelf->PerfSystem__DOT__generator__DOT__txnData),32);
    bufp->fullBit(oldp+57,(vlSelf->PerfSystem__DOT__generator__DOT__awDone));
    bufp->fullBit(oldp+58,(vlSelf->PerfSystem__DOT__generator__DOT__wDone));
    bufp->fullBit(oldp+59,(vlSelf->PerfSystem__DOT__generator__DOT__fsm_wantStart));
    bufp->fullCData(oldp+60,(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg),3);
    bufp->fullBit(oldp+61,((0x1000U <= vlSelf->PerfSystem__DOT__generator__DOT__currentAddr)));
    bufp->fullWData(oldp+62,(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg_string),80);
    bufp->fullSData(oldp+65,((0xfffU & vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr)),12);
    bufp->fullBit(oldp+66,(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write));
    bufp->fullIData(oldp+67,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_addr),32);
    bufp->fullCData(oldp+68,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id),4);
    bufp->fullCData(oldp+69,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
                               ? (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__6)
                               : (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__1))),4);
    bufp->fullCData(oldp+70,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size),3);
    bufp->fullCData(oldp+71,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst),2);
    bufp->fullBit(oldp+72,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
                             ? (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__2)
                             : (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d96565c__0))));
    bufp->fullCData(oldp+73,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
                               ? (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__7)
                               : (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__2))),4);
    bufp->fullCData(oldp+74,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
                               ? (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__8)
                               : (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d9668fa__3))),4);
    bufp->fullCData(oldp+75,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0)
                               ? (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__3)
                               : (IData)(vlSelf->PerfSystem__DOT__generator__DOT____Vxrand_h8d967414__1))),3);
    bufp->fullCData(oldp+76,((((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write) 
                               << 1U) | (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0))),2);
    bufp->fullBit(oldp+77,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_valid));
    bufp->fullBit(oldp+78,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid));
    bufp->fullBit(oldp+79,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid));
    bufp->fullBit(oldp+80,((1U & (~ (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rValid)))));
    bufp->fullBit(oldp+81,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__locked));
    bufp->fullBit(oldp+82,((1U & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_3))));
    bufp->fullBit(oldp+83,((1U & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT___zz_maskProposal_0_3) 
                                  >> 1U))));
    bufp->fullBit(oldp+84,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_0));
    bufp->fullBit(oldp+85,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskLocked_1));
    bufp->fullBit(oldp+86,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0));
    bufp->fullBit(oldp+87,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1__DOT__maskRouted_0) 
                            & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready))));
    bufp->fullBit(oldp+88,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_payload_write) 
                            & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready))));
    bufp->fullBit(oldp+89,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_valid) 
                            & ((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write) 
                               & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready)))));
    bufp->fullBit(oldp+90,((((IData)(vlSelf->PerfSystem__DOT__generator__DOT__awDone) 
                             | (IData)(vlSelf->PerfSystem__DOT__generator__DOT__io_axi_aw_fire)) 
                            & ((IData)(vlSelf->PerfSystem__DOT__generator__DOT__wDone) 
                               | (IData)(vlSelf->PerfSystem__DOT__generator__DOT__io_axi_w_fire)))));
    bufp->fullBit(oldp+91,(((IData)(vlSelf->PerfSystem__DOT__sram_io_arw_valid_debug) 
                            & (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready))));
    bufp->fullBit(oldp+92,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_rData_last));
    bufp->fullCData(oldp+93,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat),8);
    bufp->fullBit(oldp+94,((1U == (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_beat))));
    bufp->fullCData(oldp+95,(vlSelf->PerfSystem__DOT__generator_io_axi_ar_payload_len),8);
    bufp->fullCData(oldp+96,(vlSelf->PerfSystem__DOT__generator_io_axi_aw_payload_len),8);
    bufp->fullBit(oldp+97,(vlSelf->PerfSystem__DOT__sram_io_axi_r_valid));
    bufp->fullBit(oldp+98,(vlSelf->PerfSystem__DOT__sram_io_axi_b_valid));
    bufp->fullBit(oldp+99,(vlSelf->PerfSystem__DOT__sram__DOT__ram_io_axi_arw_ready));
    bufp->fullBit(oldp+100,(vlSelf->PerfSystem__DOT__generator__DOT__io_axi_aw_fire));
    bufp->fullBit(oldp+101,(vlSelf->PerfSystem__DOT__generator__DOT__io_axi_w_fire));
    bufp->fullCData(oldp+102,(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len),8);
    bufp->fullBit(oldp+103,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_ready));
    bufp->fullBit(oldp+104,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_last));
    bufp->fullSData(oldp+105,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_addr),12);
    bufp->fullBit(oldp+106,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_result_payload_fragment_write));
    bufp->fullBit(oldp+107,((0U != (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_len))));
    bufp->fullBit(oldp+108,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_valid));
    bufp->fullBit(oldp+109,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_ready));
    bufp->fullBit(oldp+110,(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__stage0_fire));
    bufp->fullBit(oldp+111,(vlSelf->io_enable));
    bufp->fullIData(oldp+112,(vlSelf->io_writeCount),32);
    bufp->fullIData(oldp+113,(vlSelf->io_readCount),32);
    bufp->fullBit(oldp+114,(vlSelf->clk));
    bufp->fullBit(oldp+115,(vlSelf->reset));
    bufp->fullCData(oldp+116,(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext),3);
    bufp->fullBit(oldp+117,(((3U != (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateReg)) 
                             & (3U == (IData)(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext)))));
    bufp->fullWData(oldp+118,(vlSelf->PerfSystem__DOT__generator__DOT__fsm_stateNext_string),80);
    bufp->fullCData(oldp+121,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid)
                                ? (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_id)
                                : (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_id))),4);
    bufp->fullCData(oldp+122,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid)
                                ? (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_size)
                                : (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_size))),3);
    bufp->fullCData(oldp+123,(((IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_valid)
                                ? (IData)(vlSelf->PerfSystem__DOT__sram__DOT__ram__DOT__unburstify_buffer_transaction_burst)
                                : (IData)(vlSelf->PerfSystem__DOT__sram__DOT__streamArbiter_1_io_output_payload_burst))),2);
}
