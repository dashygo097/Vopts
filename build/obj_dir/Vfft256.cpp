// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfft256__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vfft256::Vfft256(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfft256__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vfft256::Vfft256(const char* _vcname__)
    : Vfft256(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfft256::~Vfft256() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfft256___024root___eval_debug_assertions(Vfft256___024root* vlSelf);
#endif  // VL_DEBUG
void Vfft256___024root___eval_static(Vfft256___024root* vlSelf);
void Vfft256___024root___eval_initial(Vfft256___024root* vlSelf);
void Vfft256___024root___eval_settle(Vfft256___024root* vlSelf);
void Vfft256___024root___eval(Vfft256___024root* vlSelf);

void Vfft256::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfft256::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfft256___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfft256___024root___eval_static(&(vlSymsp->TOP));
        Vfft256___024root___eval_initial(&(vlSymsp->TOP));
        Vfft256___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfft256___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vfft256::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vfft256::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vfft256::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vfft256::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vfft256::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfft256___024root___eval_final(Vfft256___024root* vlSelf);

VL_ATTR_COLD void Vfft256::final() {
    Vfft256___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfft256::hierName() const { return vlSymsp->name(); }
const char* Vfft256::modelName() const { return "Vfft256"; }
unsigned Vfft256::threads() const { return 1; }
void Vfft256::prepareClone() const { contextp()->prepareClone(); }
void Vfft256::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vfft256::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vfft256___024root__trace_decl_types(VerilatedVcd* tracep);

void Vfft256___024root__trace_init_top(Vfft256___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfft256___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft256___024root*>(voidSelf);
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vfft256___024root__trace_decl_types(tracep);
    Vfft256___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfft256___024root__trace_register(Vfft256___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vfft256::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfft256::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vfft256___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
