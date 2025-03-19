// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfm_en.h for the primary calling header

#ifndef VERILATED_VFM_EN___024ROOT_H_
#define VERILATED_VFM_EN___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vfm_en__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfm_en___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ FM_tb__DOT__clock;
    CData/*0:0*/ FM_tb__DOT__reset;
    CData/*0:0*/ __Vtrigprevexpr___TOP__FM_tb__DOT__clock__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ FM_tb__DOT__uut__DOT__cw__DOT__phase;
    SData/*15:0*/ FM_tb__DOT__uut__DOT__trig__DOT__phase;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfm_en__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfm_en___024root(Vfm_en__Syms* symsp, const char* v__name);
    ~Vfm_en___024root();
    VL_UNCOPYABLE(Vfm_en___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
