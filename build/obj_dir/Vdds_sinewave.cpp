// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdds_sinewave__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdds_sinewave::Vdds_sinewave(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdds_sinewave__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vdds_sinewave::Vdds_sinewave(const char* _vcname__)
    : Vdds_sinewave(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdds_sinewave::~Vdds_sinewave() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdds_sinewave___024root___eval_debug_assertions(Vdds_sinewave___024root* vlSelf);
#endif  // VL_DEBUG
void Vdds_sinewave___024root___eval_static(Vdds_sinewave___024root* vlSelf);
void Vdds_sinewave___024root___eval_initial(Vdds_sinewave___024root* vlSelf);
void Vdds_sinewave___024root___eval_settle(Vdds_sinewave___024root* vlSelf);
void Vdds_sinewave___024root___eval(Vdds_sinewave___024root* vlSelf);

void Vdds_sinewave::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdds_sinewave::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdds_sinewave___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdds_sinewave___024root___eval_static(&(vlSymsp->TOP));
        Vdds_sinewave___024root___eval_initial(&(vlSymsp->TOP));
        Vdds_sinewave___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdds_sinewave___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vdds_sinewave::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vdds_sinewave::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vdds_sinewave::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vdds_sinewave::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vdds_sinewave::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdds_sinewave___024root___eval_final(Vdds_sinewave___024root* vlSelf);

VL_ATTR_COLD void Vdds_sinewave::final() {
    Vdds_sinewave___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdds_sinewave::hierName() const { return vlSymsp->name(); }
const char* Vdds_sinewave::modelName() const { return "Vdds_sinewave"; }
unsigned Vdds_sinewave::threads() const { return 1; }
void Vdds_sinewave::prepareClone() const { contextp()->prepareClone(); }
void Vdds_sinewave::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vdds_sinewave::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdds_sinewave___024root__trace_decl_types(VerilatedVcd* tracep);

void Vdds_sinewave___024root__trace_init_top(Vdds_sinewave___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdds_sinewave___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdds_sinewave___024root*>(voidSelf);
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vdds_sinewave___024root__trace_decl_types(tracep);
    Vdds_sinewave___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vdds_sinewave___024root__trace_register(Vdds_sinewave___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdds_sinewave::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdds_sinewave::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdds_sinewave___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
