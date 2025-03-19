// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfm.h for the primary calling header

#include "Vfm__pch.h"
#include "Vfm___024root.h"

VL_ATTR_COLD void Vfm___024root___eval_static(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_static\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfm___024root___eval_final(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_final\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm___024root___dump_triggers__stl(Vfm___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfm___024root___eval_phase__stl(Vfm___024root* vlSelf);

VL_ATTR_COLD void Vfm___024root___eval_settle(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_settle\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vfm___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fm_tb.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfm___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm___024root___dump_triggers__stl(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___dump_triggers__stl\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vfm___024root___act_sequent__TOP__0(Vfm___024root* vlSelf);

VL_ATTR_COLD void Vfm___024root___eval_stl(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_stl\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vfm___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vfm___024root___eval_triggers__stl(Vfm___024root* vlSelf);

VL_ATTR_COLD bool Vfm___024root___eval_phase__stl(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_phase__stl\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfm___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vfm___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm___024root___dump_triggers__act(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___dump_triggers__act\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void Vfm___024root___dump_triggers__nba(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___dump_triggers__nba\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vfm___024root___ctor_var_reset(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___ctor_var_reset\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->FM_tb__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->FM_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->FM_tb__DOT__io_in_value = VL_RAND_RESET_I(32);
    vlSelf->FM_tb__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->FM_tb__DOT__uut__DOT___trig_io_phase_delta_T = VL_RAND_RESET_Q(51);
    vlSelf->FM_tb__DOT__uut__DOT__trig__DOT__phase = VL_RAND_RESET_I(24);
    vlSelf->__Vtrigprevexpr___TOP__FM_tb__DOT__clock__0 = VL_RAND_RESET_I(1);
}
