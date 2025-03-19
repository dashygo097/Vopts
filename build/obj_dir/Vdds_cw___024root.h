// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdds_cw.h for the primary calling header

#ifndef VERILATED_VDDS_CW___024ROOT_H_
#define VERILATED_VDDS_CW___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vdds_cw__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdds_cw___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ CW_tb__DOT__clock;
    CData/*0:0*/ CW_tb__DOT__reset;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CW_tb__DOT__clock__0;
    CData/*0:0*/ __VactContinue;
    IData/*23:0*/ CW_tb__DOT__uut__DOT__phase;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdds_cw__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdds_cw___024root(Vdds_cw__Syms* symsp, const char* v__name);
    ~Vdds_cw___024root();
    VL_UNCOPYABLE(Vdds_cw___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
