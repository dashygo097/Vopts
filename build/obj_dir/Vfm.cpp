// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfm__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vfm::Vfm(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfm__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vfm::Vfm(const char* _vcname__)
    : Vfm(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfm::~Vfm() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfm___024root___eval_debug_assertions(Vfm___024root* vlSelf);
#endif  // VL_DEBUG
void Vfm___024root___eval_static(Vfm___024root* vlSelf);
void Vfm___024root___eval_initial(Vfm___024root* vlSelf);
void Vfm___024root___eval_settle(Vfm___024root* vlSelf);
void Vfm___024root___eval(Vfm___024root* vlSelf);

void Vfm::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfm::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfm___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfm___024root___eval_static(&(vlSymsp->TOP));
        Vfm___024root___eval_initial(&(vlSymsp->TOP));
        Vfm___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfm___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vfm::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vfm::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vfm::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vfm::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vfm::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfm___024root___eval_final(Vfm___024root* vlSelf);

VL_ATTR_COLD void Vfm::final() {
    Vfm___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfm::hierName() const { return vlSymsp->name(); }
const char* Vfm::modelName() const { return "Vfm"; }
unsigned Vfm::threads() const { return 1; }
void Vfm::prepareClone() const { contextp()->prepareClone(); }
void Vfm::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vfm::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vfm___024root__trace_decl_types(VerilatedVcd* tracep);

void Vfm___024root__trace_init_top(Vfm___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfm___024root*>(voidSelf);
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vfm___024root__trace_decl_types(tracep);
    Vfm___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfm___024root__trace_register(Vfm___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vfm::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfm::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vfm___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
