// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfm_en.h for the primary calling header

#include "Vfm_en__pch.h"
#include "Vfm_en__Syms.h"
#include "Vfm_en___024root.h"

void Vfm_en___024root___ctor_var_reset(Vfm_en___024root* vlSelf);

Vfm_en___024root::Vfm_en___024root(Vfm_en__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfm_en___024root___ctor_var_reset(this);
}

void Vfm_en___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vfm_en___024root::~Vfm_en___024root() {
}
