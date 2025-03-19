// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdds_sinewave.h for the primary calling header

#include "Vdds_sinewave__pch.h"
#include "Vdds_sinewave___024unit.h"

VL_ATTR_COLD void Vdds_sinewave___024unit___ctor_var_reset(Vdds_sinewave___024unit* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vdds_sinewave___024unit___ctor_var_reset\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__VmonitorOff = VL_RAND_RESET_I(1);
}
