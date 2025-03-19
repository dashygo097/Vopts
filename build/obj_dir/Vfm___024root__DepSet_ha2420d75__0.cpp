// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfm.h for the primary calling header

#include "Vfm__pch.h"
#include "Vfm___024root.h"

VlCoroutine Vfm___024root___eval_initial__TOP__Vtiming__0(Vfm___024root* vlSelf);
VlCoroutine Vfm___024root___eval_initial__TOP__Vtiming__1(Vfm___024root* vlSelf);

void Vfm___024root___eval_initial(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_initial\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vfm___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vfm___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__FM_tb__DOT__clock__0 
        = vlSelfRef.FM_tb__DOT__clock;
}

VL_INLINE_OPT VlCoroutine Vfm___024root___eval_initial__TOP__Vtiming__1(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "fm_tb.sv", 
                                             18);
        vlSelfRef.FM_tb__DOT__clock = (1U & (~ (IData)(vlSelfRef.FM_tb__DOT__clock)));
    }
}

void Vfm___024root___act_sequent__TOP__0(Vfm___024root* vlSelf);

void Vfm___024root___eval_act(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_act\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vfm___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vfm___024root___act_sequent__TOP__0(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___act_sequent__TOP__0\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.FM_tb__DOT__uut__DOT___trig_io_phase_delta_T 
        = (0x7ffffffffffffULL & (0x7a120ULL * (((QData)((IData)(
                                                                (0x7ffffU 
                                                                 & (- (IData)(
                                                                              (vlSelfRef.FM_tb__DOT__io_in_value 
                                                                               >> 0x1fU)))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlSelfRef.FM_tb__DOT__io_in_value)))));
}

void Vfm___024root___nba_sequent__TOP__0(Vfm___024root* vlSelf);

void Vfm___024root___eval_nba(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_nba\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfm___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfm___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vfm___024root___nba_sequent__TOP__0(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___nba_sequent__TOP__0\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
        = ((IData)(vlSelfRef.FM_tb__DOT__reset) ? 0U
            : (0xffffffU & ((IData)(0xf4240U) + (vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
                                                 + (IData)(
                                                           (0xfffffffffffffULL 
                                                            & VL_DIVS_QQQ(52, 
                                                                          (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.FM_tb__DOT__uut__DOT___trig_io_phase_delta_T 
                                                                                >> 0x32U))))) 
                                                                            << 0x33U) 
                                                                           | vlSelfRef.FM_tb__DOT__uut__DOT___trig_io_phase_delta_T), 0x100000ULL)))))));
}

void Vfm___024root___timing_resume(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___timing_resume\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vfm___024root___eval_triggers__act(Vfm___024root* vlSelf);

bool Vfm___024root___eval_phase__act(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_phase__act\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfm___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vfm___024root___timing_resume(vlSelf);
        Vfm___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfm___024root___eval_phase__nba(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_phase__nba\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfm___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm___024root___dump_triggers__nba(Vfm___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm___024root___dump_triggers__act(Vfm___024root* vlSelf);
#endif  // VL_DEBUG

void Vfm___024root___eval(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vfm___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fm_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vfm___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fm_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vfm___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vfm___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfm___024root___eval_debug_assertions(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_debug_assertions\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
