// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdds_sinewave.h for the primary calling header

#ifndef VERILATED_VDDS_SINEWAVE___024UNIT_H_
#define VERILATED_VDDS_SINEWAVE___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vdds_sinewave__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdds_sinewave___024unit final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VmonitorOff;

    // INTERNAL VARIABLES
    Vdds_sinewave__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdds_sinewave___024unit(Vdds_sinewave__Syms* symsp, const char* v__name);
    ~Vdds_sinewave___024unit();
    VL_UNCOPYABLE(Vdds_sinewave___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
