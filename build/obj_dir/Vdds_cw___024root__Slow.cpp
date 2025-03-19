// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdds_cw.h for the primary calling header

#include "Vdds_cw__pch.h"
#include "Vdds_cw__Syms.h"
#include "Vdds_cw___024root.h"

void Vdds_cw___024root___ctor_var_reset(Vdds_cw___024root* vlSelf);

Vdds_cw___024root::Vdds_cw___024root(Vdds_cw__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdds_cw___024root___ctor_var_reset(this);
}

void Vdds_cw___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vdds_cw___024root::~Vdds_cw___024root() {
}
