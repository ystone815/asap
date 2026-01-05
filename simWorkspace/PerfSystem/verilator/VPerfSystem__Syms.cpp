// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VPerfSystem__pch.h"
#include "VPerfSystem.h"
#include "VPerfSystem___024root.h"

// FUNCTIONS
VPerfSystem__Syms::~VPerfSystem__Syms()
{
}

VPerfSystem__Syms::VPerfSystem__Syms(VerilatedContext* contextp, const char* namep, VPerfSystem* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
