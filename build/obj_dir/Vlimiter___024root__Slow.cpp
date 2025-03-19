// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlimiter.h for the primary calling header

#include "Vlimiter__pch.h"
#include "Vlimiter__Syms.h"
#include "Vlimiter___024root.h"

void Vlimiter___024root___ctor_var_reset(Vlimiter___024root* vlSelf);

Vlimiter___024root::Vlimiter___024root(Vlimiter__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vlimiter___024root___ctor_var_reset(this);
}

void Vlimiter___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vlimiter___024root::~Vlimiter___024root() {
}
