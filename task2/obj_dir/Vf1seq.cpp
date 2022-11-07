// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vf1seq.h"
#include "Vf1seq__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vf1seq::Vf1seq(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vf1seq__Syms(contextp(), _vcname__, this)}
    , en{vlSymsp->TOP.en}
    , rst{vlSymsp->TOP.rst}
    , clk{vlSymsp->TOP.clk}
    , dout{vlSymsp->TOP.dout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vf1seq::Vf1seq(const char* _vcname__)
    : Vf1seq(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vf1seq::~Vf1seq() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vf1seq___024root___eval_initial(Vf1seq___024root* vlSelf);
void Vf1seq___024root___eval_settle(Vf1seq___024root* vlSelf);
void Vf1seq___024root___eval(Vf1seq___024root* vlSelf);
#ifdef VL_DEBUG
void Vf1seq___024root___eval_debug_assertions(Vf1seq___024root* vlSelf);
#endif  // VL_DEBUG
void Vf1seq___024root___final(Vf1seq___024root* vlSelf);

static void _eval_initial_loop(Vf1seq__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vf1seq___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vf1seq___024root___eval_settle(&(vlSymsp->TOP));
        Vf1seq___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vf1seq::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vf1seq::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vf1seq___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vf1seq___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vf1seq::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vf1seq::final() {
    Vf1seq___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vf1seq::hierName() const { return vlSymsp->name(); }
const char* Vf1seq::modelName() const { return "Vf1seq"; }
unsigned Vf1seq::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vf1seq::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vf1seq___024root__trace_init_top(Vf1seq___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vf1seq___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vf1seq___024root*>(voidSelf);
    Vf1seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vf1seq___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vf1seq___024root__trace_register(Vf1seq___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vf1seq::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vf1seq::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vf1seq___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
