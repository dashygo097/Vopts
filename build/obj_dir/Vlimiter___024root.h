// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlimiter.h for the primary calling header

#ifndef VERILATED_VLIMITER___024ROOT_H_
#define VERILATED_VLIMITER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vlimiter__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vlimiter___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ Limiter_tb__DOT__clock;
    CData/*0:0*/ Limiter_tb__DOT__reset;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ Limiter_tb__DOT__io_in_value;
    IData/*31:0*/ Limiter_tb__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vlimiter__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vlimiter___024root(Vlimiter__Syms* symsp, const char* v__name);
    ~Vlimiter___024root();
    VL_UNCOPYABLE(Vlimiter___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
