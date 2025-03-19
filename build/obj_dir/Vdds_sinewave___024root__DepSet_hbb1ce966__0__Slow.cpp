// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdds_sinewave.h for the primary calling header

#include "Vdds_sinewave__pch.h"
#include "Vdds_sinewave___024root.h"

VL_ATTR_COLD void Vdds_sinewave___024root___eval_static(Vdds_sinewave___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root___eval_static\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vdds_sinewave___024root___eval_final(Vdds_sinewave___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root___eval_final\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vdds_sinewave___024root___eval_settle(Vdds_sinewave___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root___eval_settle\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdds_sinewave___024root___dump_triggers__act(Vdds_sinewave___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root___dump_triggers__act\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge SineWave_tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdds_sinewave___024root___dump_triggers__nba(Vdds_sinewave___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root___dump_triggers__nba\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge SineWave_tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdds_sinewave___024root___ctor_var_reset(Vdds_sinewave___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root___ctor_var_reset\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->SineWave_tb__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->SineWave_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->SineWave_tb__DOT__uut__DOT__phase = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__SineWave_tb__DOT__clock__0 = VL_RAND_RESET_I(1);
}
