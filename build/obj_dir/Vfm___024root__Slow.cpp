// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfm.h for the primary calling header

#include "Vfm__pch.h"
#include "Vfm__Syms.h"
#include "Vfm___024root.h"

void Vfm___024root___ctor_var_reset(Vfm___024root* vlSelf);

Vfm___024root::Vfm___024root(Vfm__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfm___024root___ctor_var_reset(this);
}

void Vfm___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vfm___024root::~Vfm___024root() {
}
