// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPerfSystem.h for the primary calling header

#include "VPerfSystem__pch.h"
#include "VPerfSystem__Syms.h"
#include "VPerfSystem___024root.h"

void VPerfSystem___024root___ctor_var_reset(VPerfSystem___024root* vlSelf);

VPerfSystem___024root::VPerfSystem___024root(VPerfSystem__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VPerfSystem___024root___ctor_var_reset(this);
}

void VPerfSystem___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VPerfSystem___024root::~VPerfSystem___024root() {
}
