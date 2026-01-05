// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNativePerfSystem.h for the primary calling header

#include "VNativePerfSystem__pch.h"
#include "VNativePerfSystem__Syms.h"
#include "VNativePerfSystem___024root.h"

void VNativePerfSystem___024root___ctor_var_reset(VNativePerfSystem___024root* vlSelf);

VNativePerfSystem___024root::VNativePerfSystem___024root(VNativePerfSystem__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VNativePerfSystem___024root___ctor_var_reset(this);
}

void VNativePerfSystem___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VNativePerfSystem___024root::~VNativePerfSystem___024root() {
}
