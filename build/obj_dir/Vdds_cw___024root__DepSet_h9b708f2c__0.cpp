// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdds_cw.h for the primary calling header

#include "Vdds_cw__pch.h"
#include "Vdds_cw___024root.h"

VlCoroutine Vdds_cw___024root___eval_initial__TOP__Vtiming__0(Vdds_cw___024root* vlSelf);
VlCoroutine Vdds_cw___024root___eval_initial__TOP__Vtiming__1(Vdds_cw___024root* vlSelf);

void Vdds_cw___024root___eval_initial(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___eval_initial\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdds_cw___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vdds_cw___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__CW_tb__DOT__clock__0 
        = vlSelfRef.CW_tb__DOT__clock;
}

VL_INLINE_OPT VlCoroutine Vdds_cw___024root___eval_initial__TOP__Vtiming__1(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "dds_cw_tb.sv", 
                                             16);
        vlSelfRef.CW_tb__DOT__clock = (1U & (~ (IData)(vlSelfRef.CW_tb__DOT__clock)));
    }
}

void Vdds_cw___024root___eval_act(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___eval_act\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vdds_cw___024root___nba_sequent__TOP__0(Vdds_cw___024root* vlSelf);

void Vdds_cw___024root___eval_nba(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___eval_nba\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdds_cw___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vdds_cw___024root___nba_sequent__TOP__0(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___nba_sequent__TOP__0\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CW_tb__DOT__uut__DOT__phase = ((IData)(vlSelfRef.CW_tb__DOT__reset)
                                              ? 0U : 
                                             (0xffffffU 
                                              & ((IData)(0x3e8U) 
                                                 + vlSelfRef.CW_tb__DOT__uut__DOT__phase)));
}

void Vdds_cw___024root___timing_resume(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___timing_resume\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vdds_cw___024root___eval_triggers__act(Vdds_cw___024root* vlSelf);

bool Vdds_cw___024root___eval_phase__act(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___eval_phase__act\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdds_cw___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdds_cw___024root___timing_resume(vlSelf);
        Vdds_cw___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdds_cw___024root___eval_phase__nba(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___eval_phase__nba\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdds_cw___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdds_cw___024root___dump_triggers__nba(Vdds_cw___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdds_cw___024root___dump_triggers__act(Vdds_cw___024root* vlSelf);
#endif  // VL_DEBUG

void Vdds_cw___024root___eval(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___eval\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vdds_cw___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("dds_cw_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vdds_cw___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("dds_cw_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdds_cw___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdds_cw___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdds_cw___024root___eval_debug_assertions(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___eval_debug_assertions\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
