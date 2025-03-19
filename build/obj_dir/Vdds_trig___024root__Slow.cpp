// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdds_trig.h for the primary calling header

#include "Vdds_trig__pch.h"
#include "Vdds_trig__Syms.h"
#include "Vdds_trig___024root.h"

void Vdds_trig___024root___ctor_var_reset(Vdds_trig___024root* vlSelf);

Vdds_trig___024root::Vdds_trig___024root(Vdds_trig__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdds_trig___024root___ctor_var_reset(this);
}

void Vdds_trig___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vdds_trig___024root::~Vdds_trig___024root() {
}
