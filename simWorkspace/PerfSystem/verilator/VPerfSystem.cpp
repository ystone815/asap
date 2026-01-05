// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPerfSystem__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VPerfSystem::VPerfSystem(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPerfSystem__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , io_enable{vlSymsp->TOP.io_enable}
    , io_writeCount{vlSymsp->TOP.io_writeCount}
    , io_readCount{vlSymsp->TOP.io_readCount}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VPerfSystem::VPerfSystem(const char* _vcname__)
    : VPerfSystem(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VPerfSystem::~VPerfSystem() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VPerfSystem___024root___eval_debug_assertions(VPerfSystem___024root* vlSelf);
#endif  // VL_DEBUG
void VPerfSystem___024root___eval_static(VPerfSystem___024root* vlSelf);
void VPerfSystem___024root___eval_initial(VPerfSystem___024root* vlSelf);
void VPerfSystem___024root___eval_settle(VPerfSystem___024root* vlSelf);
void VPerfSystem___024root___eval(VPerfSystem___024root* vlSelf);

void VPerfSystem::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPerfSystem::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPerfSystem___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VPerfSystem___024root___eval_static(&(vlSymsp->TOP));
        VPerfSystem___024root___eval_initial(&(vlSymsp->TOP));
        VPerfSystem___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VPerfSystem___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VPerfSystem::eventsPending() { return false; }

uint64_t VPerfSystem::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VPerfSystem::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VPerfSystem___024root___eval_final(VPerfSystem___024root* vlSelf);

VL_ATTR_COLD void VPerfSystem::final() {
    VPerfSystem___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPerfSystem::hierName() const { return vlSymsp->name(); }
const char* VPerfSystem::modelName() const { return "VPerfSystem"; }
unsigned VPerfSystem::threads() const { return 1; }
void VPerfSystem::prepareClone() const { contextp()->prepareClone(); }
void VPerfSystem::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VPerfSystem::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VPerfSystem___024root__trace_decl_types(VerilatedVcd* tracep);

void VPerfSystem___024root__trace_init_top(VPerfSystem___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VPerfSystem___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPerfSystem___024root*>(voidSelf);
    VPerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VPerfSystem___024root__trace_decl_types(tracep);
    VPerfSystem___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VPerfSystem___024root__trace_register(VPerfSystem___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VPerfSystem::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VPerfSystem::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VPerfSystem___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
