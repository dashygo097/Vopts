// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft128.h for the primary calling header

#include "Vfft128__pch.h"
#include "Vfft128__Syms.h"
#include "Vfft128___024root.h"

void Vfft128___024root___ctor_var_reset(Vfft128___024root* vlSelf);

Vfft128___024root::Vfft128___024root(Vfft128__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfft128___024root___ctor_var_reset(this);
}

void Vfft128___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vfft128___024root::~Vfft128___024root() {
}
