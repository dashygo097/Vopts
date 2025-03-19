// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfft512__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vfft512::Vfft512(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfft512__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vfft512::Vfft512(const char* _vcname__)
    : Vfft512(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfft512::~Vfft512() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfft512___024root___eval_debug_assertions(Vfft512___024root* vlSelf);
#endif  // VL_DEBUG
void Vfft512___024root___eval_static(Vfft512___024root* vlSelf);
void Vfft512___024root___eval_initial(Vfft512___024root* vlSelf);
void Vfft512___024root___eval_settle(Vfft512___024root* vlSelf);
void Vfft512___024root___eval(Vfft512___024root* vlSelf);

void Vfft512::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfft512::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfft512___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfft512___024root___eval_static(&(vlSymsp->TOP));
        Vfft512___024root___eval_initial(&(vlSymsp->TOP));
        Vfft512___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfft512___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vfft512::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vfft512::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vfft512::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vfft512::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vfft512::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfft512___024root___eval_final(Vfft512___024root* vlSelf);

VL_ATTR_COLD void Vfft512::final() {
    Vfft512___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfft512::hierName() const { return vlSymsp->name(); }
const char* Vfft512::modelName() const { return "Vfft512"; }
unsigned Vfft512::threads() const { return 1; }
void Vfft512::prepareClone() const { contextp()->prepareClone(); }
void Vfft512::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vfft512::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vfft512___024root__trace_decl_types(VerilatedVcd* tracep);

void Vfft512___024root__trace_init_top(Vfft512___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfft512___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft512___024root*>(voidSelf);
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vfft512___024root__trace_decl_types(tracep);
    Vfft512___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfft512___024root__trace_register(Vfft512___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vfft512::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfft512::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vfft512___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
