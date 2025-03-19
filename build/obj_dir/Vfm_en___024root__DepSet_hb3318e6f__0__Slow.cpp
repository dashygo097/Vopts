// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfm_en.h for the primary calling header

#include "Vfm_en__pch.h"
#include "Vfm_en___024root.h"

VL_ATTR_COLD void Vfm_en___024root___eval_static(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_static\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfm_en___024root___eval_final(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_final\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfm_en___024root___eval_settle(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_settle\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm_en___024root___dump_triggers__act(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___dump_triggers__act\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge FM_tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm_en___024root___dump_triggers__nba(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___dump_triggers__nba\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge FM_tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfm_en___024root___ctor_var_reset(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___ctor_var_reset\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->FM_tb__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->FM_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->FM_tb__DOT__uut__DOT__cw__DOT__phase = VL_RAND_RESET_I(16);
    vlSelf->FM_tb__DOT__uut__DOT__trig__DOT__phase = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__FM_tb__DOT__clock__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
