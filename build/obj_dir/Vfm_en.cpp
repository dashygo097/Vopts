// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfm_en__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vfm_en::Vfm_en(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfm_en__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vfm_en::Vfm_en(const char* _vcname__)
    : Vfm_en(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfm_en::~Vfm_en() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfm_en___024root___eval_debug_assertions(Vfm_en___024root* vlSelf);
#endif  // VL_DEBUG
void Vfm_en___024root___eval_static(Vfm_en___024root* vlSelf);
void Vfm_en___024root___eval_initial(Vfm_en___024root* vlSelf);
void Vfm_en___024root___eval_settle(Vfm_en___024root* vlSelf);
void Vfm_en___024root___eval(Vfm_en___024root* vlSelf);

void Vfm_en::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfm_en::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfm_en___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfm_en___024root___eval_static(&(vlSymsp->TOP));
        Vfm_en___024root___eval_initial(&(vlSymsp->TOP));
        Vfm_en___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfm_en___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vfm_en::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vfm_en::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vfm_en::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vfm_en::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vfm_en::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfm_en___024root___eval_final(Vfm_en___024root* vlSelf);

VL_ATTR_COLD void Vfm_en::final() {
    Vfm_en___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfm_en::hierName() const { return vlSymsp->name(); }
const char* Vfm_en::modelName() const { return "Vfm_en"; }
unsigned Vfm_en::threads() const { return 1; }
void Vfm_en::prepareClone() const { contextp()->prepareClone(); }
void Vfm_en::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vfm_en::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vfm_en___024root__trace_decl_types(VerilatedVcd* tracep);

void Vfm_en___024root__trace_init_top(Vfm_en___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfm_en___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfm_en___024root*>(voidSelf);
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vfm_en___024root__trace_decl_types(tracep);
    Vfm_en___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfm_en___024root__trace_register(Vfm_en___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vfm_en::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfm_en::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vfm_en___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
