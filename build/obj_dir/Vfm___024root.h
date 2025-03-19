// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfm.h for the primary calling header

#ifndef VERILATED_VFM___024ROOT_H_
#define VERILATED_VFM___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vfm__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfm___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ FM_tb__DOT__clock;
    CData/*0:0*/ FM_tb__DOT__reset;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__FM_tb__DOT__clock__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ FM_tb__DOT__io_in_value;
    IData/*31:0*/ FM_tb__DOT__unnamedblk1__DOT__i;
    IData/*23:0*/ FM_tb__DOT__uut__DOT__trig__DOT__phase;
    IData/*31:0*/ __VactIterCount;
    QData/*50:0*/ FM_tb__DOT__uut__DOT___trig_io_phase_delta_T;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfm__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfm___024root(Vfm__Syms* symsp, const char* v__name);
    ~Vfm___024root();
    VL_UNCOPYABLE(Vfm___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
