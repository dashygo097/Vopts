// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlimiter.h for the primary calling header

#include "Vlimiter__pch.h"
#include "Vlimiter___024root.h"

VL_ATTR_COLD void Vlimiter___024root___eval_static(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_static\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vlimiter___024root___eval_final(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_final\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vlimiter___024root___eval_settle(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_settle\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlimiter___024root___dump_triggers__act(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___dump_triggers__act\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlimiter___024root___dump_triggers__nba(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___dump_triggers__nba\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vlimiter___024root___ctor_var_reset(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___ctor_var_reset\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->Limiter_tb__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->Limiter_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->Limiter_tb__DOT__io_in_value = VL_RAND_RESET_I(32);
    vlSelf->Limiter_tb__DOT__unnamedblk1__DOT__i = 0;
    }
