// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdds_sinewave.h for the primary calling header

#ifndef VERILATED_VDDS_SINEWAVE___024ROOT_H_
#define VERILATED_VDDS_SINEWAVE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vdds_sinewave__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdds_sinewave___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ SineWave_tb__DOT__clock;
    CData/*0:0*/ SineWave_tb__DOT__reset;
    CData/*0:0*/ __Vtrigprevexpr___TOP__SineWave_tb__DOT__clock__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ SineWave_tb__DOT__uut__DOT__phase;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdds_sinewave__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdds_sinewave___024root(Vdds_sinewave__Syms* symsp, const char* v__name);
    ~Vdds_sinewave___024root();
    VL_UNCOPYABLE(Vdds_sinewave___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
