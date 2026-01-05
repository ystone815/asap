// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VDummyTop__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VDummyTop::VDummyTop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VDummyTop__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , io_qM1Size{vlSymsp->TOP.io_qM1Size}
    , io_qM2Size{vlSymsp->TOP.io_qM2Size}
    , io_qMemSize{vlSymsp->TOP.io_qMemSize}
    , io_totalProcessed{vlSymsp->TOP.io_totalProcessed}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VDummyTop::VDummyTop(const char* _vcname__)
    : VDummyTop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VDummyTop::~VDummyTop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VDummyTop___024root___eval_debug_assertions(VDummyTop___024root* vlSelf);
#endif  // VL_DEBUG
void VDummyTop___024root___eval_static(VDummyTop___024root* vlSelf);
void VDummyTop___024root___eval_initial(VDummyTop___024root* vlSelf);
void VDummyTop___024root___eval_settle(VDummyTop___024root* vlSelf);
void VDummyTop___024root___eval(VDummyTop___024root* vlSelf);

void VDummyTop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDummyTop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VDummyTop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VDummyTop___024root___eval_static(&(vlSymsp->TOP));
        VDummyTop___024root___eval_initial(&(vlSymsp->TOP));
        VDummyTop___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VDummyTop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VDummyTop::eventsPending() { return false; }

uint64_t VDummyTop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VDummyTop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VDummyTop___024root___eval_final(VDummyTop___024root* vlSelf);

VL_ATTR_COLD void VDummyTop::final() {
    VDummyTop___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VDummyTop::hierName() const { return vlSymsp->name(); }
const char* VDummyTop::modelName() const { return "VDummyTop"; }
unsigned VDummyTop::threads() const { return 1; }
void VDummyTop::prepareClone() const { contextp()->prepareClone(); }
void VDummyTop::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VDummyTop::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VDummyTop___024root__trace_decl_types(VerilatedVcd* tracep);

void VDummyTop___024root__trace_init_top(VDummyTop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VDummyTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VDummyTop___024root*>(voidSelf);
    VDummyTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VDummyTop___024root__trace_decl_types(tracep);
    VDummyTop___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VDummyTop___024root__trace_register(VDummyTop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VDummyTop::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VDummyTop::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VDummyTop___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
