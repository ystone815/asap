// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VNativePerfSystem__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VNativePerfSystem::VNativePerfSystem(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VNativePerfSystem__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , io_enable{vlSymsp->TOP.io_enable}
    , io_totalTxns{vlSymsp->TOP.io_totalTxns}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VNativePerfSystem::VNativePerfSystem(const char* _vcname__)
    : VNativePerfSystem(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VNativePerfSystem::~VNativePerfSystem() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VNativePerfSystem___024root___eval_debug_assertions(VNativePerfSystem___024root* vlSelf);
#endif  // VL_DEBUG
void VNativePerfSystem___024root___eval_static(VNativePerfSystem___024root* vlSelf);
void VNativePerfSystem___024root___eval_initial(VNativePerfSystem___024root* vlSelf);
void VNativePerfSystem___024root___eval_settle(VNativePerfSystem___024root* vlSelf);
void VNativePerfSystem___024root___eval(VNativePerfSystem___024root* vlSelf);

void VNativePerfSystem::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VNativePerfSystem::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VNativePerfSystem___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VNativePerfSystem___024root___eval_static(&(vlSymsp->TOP));
        VNativePerfSystem___024root___eval_initial(&(vlSymsp->TOP));
        VNativePerfSystem___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VNativePerfSystem___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VNativePerfSystem::eventsPending() { return false; }

uint64_t VNativePerfSystem::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VNativePerfSystem::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VNativePerfSystem___024root___eval_final(VNativePerfSystem___024root* vlSelf);

VL_ATTR_COLD void VNativePerfSystem::final() {
    VNativePerfSystem___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VNativePerfSystem::hierName() const { return vlSymsp->name(); }
const char* VNativePerfSystem::modelName() const { return "VNativePerfSystem"; }
unsigned VNativePerfSystem::threads() const { return 1; }
void VNativePerfSystem::prepareClone() const { contextp()->prepareClone(); }
void VNativePerfSystem::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VNativePerfSystem::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VNativePerfSystem___024root__trace_decl_types(VerilatedVcd* tracep);

void VNativePerfSystem___024root__trace_init_top(VNativePerfSystem___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VNativePerfSystem___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VNativePerfSystem___024root*>(voidSelf);
    VNativePerfSystem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VNativePerfSystem___024root__trace_decl_types(tracep);
    VNativePerfSystem___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VNativePerfSystem___024root__trace_register(VNativePerfSystem___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VNativePerfSystem::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VNativePerfSystem::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VNativePerfSystem___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
