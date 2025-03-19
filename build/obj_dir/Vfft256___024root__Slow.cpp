// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft256.h for the primary calling header

#include "Vfft256__pch.h"
#include "Vfft256__Syms.h"
#include "Vfft256___024root.h"

void Vfft256___024root___ctor_var_reset(Vfft256___024root* vlSelf);

Vfft256___024root::Vfft256___024root(Vfft256__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfft256___024root___ctor_var_reset(this);
}

void Vfft256___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vfft256___024root::~Vfft256___024root() {
}
