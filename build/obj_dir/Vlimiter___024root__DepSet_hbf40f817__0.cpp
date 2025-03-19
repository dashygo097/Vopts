// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlimiter.h for the primary calling header

#include "Vlimiter__pch.h"
#include "Vlimiter___024root.h"

VlCoroutine Vlimiter___024root___eval_initial__TOP__Vtiming__0(Vlimiter___024root* vlSelf);
VlCoroutine Vlimiter___024root___eval_initial__TOP__Vtiming__1(Vlimiter___024root* vlSelf);

void Vlimiter___024root___eval_initial(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_initial\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vlimiter___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vlimiter___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vlimiter___024root___eval_initial__TOP__Vtiming__1(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "limiter_tb.sv", 
                                             18);
        vlSelfRef.Limiter_tb__DOT__clock = (1U & (~ (IData)(vlSelfRef.Limiter_tb__DOT__clock)));
    }
}

void Vlimiter___024root___eval_act(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_act\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vlimiter___024root___eval_nba(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_nba\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vlimiter___024root___timing_resume(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___timing_resume\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vlimiter___024root___eval_triggers__act(Vlimiter___024root* vlSelf);

bool Vlimiter___024root___eval_phase__act(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_phase__act\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vlimiter___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vlimiter___024root___timing_resume(vlSelf);
        Vlimiter___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vlimiter___024root___eval_phase__nba(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_phase__nba\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vlimiter___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlimiter___024root___dump_triggers__nba(Vlimiter___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vlimiter___024root___dump_triggers__act(Vlimiter___024root* vlSelf);
#endif  // VL_DEBUG

void Vlimiter___024root___eval(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vlimiter___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("limiter_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vlimiter___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("limiter_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vlimiter___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vlimiter___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vlimiter___024root___eval_debug_assertions(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_debug_assertions\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
