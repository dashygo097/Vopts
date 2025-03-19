// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdds_sinewave.h for the primary calling header

#include "Vdds_sinewave__pch.h"
#include "Vdds_sinewave__Syms.h"
#include "Vdds_sinewave___024root.h"

void Vdds_sinewave___024root___ctor_var_reset(Vdds_sinewave___024root* vlSelf);

Vdds_sinewave___024root::Vdds_sinewave___024root(Vdds_sinewave__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdds_sinewave___024root___ctor_var_reset(this);
}

void Vdds_sinewave___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vdds_sinewave___024root::~Vdds_sinewave___024root() {
}
