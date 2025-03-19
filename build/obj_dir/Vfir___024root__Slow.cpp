// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfir.h for the primary calling header

#include "Vfir__pch.h"
#include "Vfir__Syms.h"
#include "Vfir___024root.h"

void Vfir___024root___ctor_var_reset(Vfir___024root* vlSelf);

Vfir___024root::Vfir___024root(Vfir__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfir___024root___ctor_var_reset(this);
}

void Vfir___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vfir___024root::~Vfir___024root() {
}
