// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDummyTop.h for the primary calling header

#include "VDummyTop__pch.h"
#include "VDummyTop__Syms.h"
#include "VDummyTop___024root.h"

void VDummyTop___024root___ctor_var_reset(VDummyTop___024root* vlSelf);

VDummyTop___024root::VDummyTop___024root(VDummyTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VDummyTop___024root___ctor_var_reset(this);
}

void VDummyTop___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VDummyTop___024root::~VDummyTop___024root() {
}
