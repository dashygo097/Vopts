// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfir.h for the primary calling header

#include "Vfir__pch.h"
#include "Vfir___024root.h"

VL_ATTR_COLD void Vfir___024root___eval_static(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_static\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfir___024root___eval_final(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_final\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfir___024root___eval_settle(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_settle\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfir___024root___dump_triggers__act(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___dump_triggers__act\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge FIR_tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfir___024root___dump_triggers__nba(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___dump_triggers__nba\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge FIR_tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfir___024root___ctor_var_reset(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___ctor_var_reset\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->FIR_tb__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->FIR_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->FIR_tb__DOT__io_in_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->FIR_tb__DOT__uut__DOT__regs_0_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_1_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_2_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_3_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_4_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_5_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_6_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_7_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_8_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_9_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_10_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_11_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_12_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_13_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_14_value = VL_RAND_RESET_I(32);
    vlSelf->FIR_tb__DOT__uut__DOT__regs_15_value = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__FIR_tb__DOT__clock__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
