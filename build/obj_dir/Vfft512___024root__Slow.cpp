// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft512.h for the primary calling header

#include "Vfft512__pch.h"
#include "Vfft512__Syms.h"
#include "Vfft512___024root.h"

void Vfft512___024root___ctor_var_reset(Vfft512___024root* vlSelf);

Vfft512___024root::Vfft512___024root(Vfft512__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfft512___024root___ctor_var_reset(this);
}

void Vfft512___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vfft512___024root::~Vfft512___024root() {
}
