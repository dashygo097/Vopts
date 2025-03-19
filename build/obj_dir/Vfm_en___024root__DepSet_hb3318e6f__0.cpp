// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfm_en.h for the primary calling header

#include "Vfm_en__pch.h"
#include "Vfm_en___024root.h"

VlCoroutine Vfm_en___024root___eval_initial__TOP__Vtiming__0(Vfm_en___024root* vlSelf);
VlCoroutine Vfm_en___024root___eval_initial__TOP__Vtiming__1(Vfm_en___024root* vlSelf);

void Vfm_en___024root___eval_initial(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_initial\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vfm_en___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vfm_en___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__FM_tb__DOT__clock__0 
        = vlSelfRef.FM_tb__DOT__clock;
}

VL_INLINE_OPT VlCoroutine Vfm_en___024root___eval_initial__TOP__Vtiming__1(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "fm_en_tb.sv", 
                                             18);
        vlSelfRef.FM_tb__DOT__clock = (1U & (~ (IData)(vlSelfRef.FM_tb__DOT__clock)));
    }
}

void Vfm_en___024root___eval_act(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_act\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vfm_en___024root___nba_sequent__TOP__0(Vfm_en___024root* vlSelf);

void Vfm_en___024root___eval_nba(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_nba\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfm_en___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

extern const VlWide<256>/*8191:0*/ Vfm_en__ConstPool__CONST_hfdda0392_0;

VL_INLINE_OPT void Vfm_en___024root___nba_sequent__TOP__0(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___nba_sequent__TOP__0\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __Vdly__FM_tb__DOT__uut__DOT__cw__DOT__phase;
    __Vdly__FM_tb__DOT__uut__DOT__cw__DOT__phase = 0;
    SData/*31:0*/ __Vtemp_1;
    // Body
    __Vdly__FM_tb__DOT__uut__DOT__cw__DOT__phase = vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase;
    if (vlSelfRef.FM_tb__DOT__reset) {
        __Vdly__FM_tb__DOT__uut__DOT__cw__DOT__phase = 0U;
        __Vtemp_1 = 0U;
    } else {
        __Vdly__FM_tb__DOT__uut__DOT__cw__DOT__phase 
            = (0xffffU & ((IData)(0x1a80U) + (IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase)));
        __Vtemp_1 = (0xffffU & (((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase) 
                                 + (((0U == (0x1fU 
                                             & ((IData)(0x10U) 
                                                + (0x1fffU 
                                                   & VL_SHIFTL_III(13,13,32, 
                                                                   (0xffU 
                                                                    & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                       >> 8U)), 5U)))))
                                      ? 0U : (Vfm_en__ConstPool__CONST_hfdda0392_0[
                                              (((IData)(0x1fU) 
                                                + (0x1fffU 
                                                   & VL_SHIFTL_III(13,13,32, 
                                                                   (0xffU 
                                                                    & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                       >> 8U)), 5U))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x10U) 
                                                      + 
                                                      (0x1fffU 
                                                       & VL_SHIFTL_III(13,13,32, 
                                                                       (0xffU 
                                                                        & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                           >> 8U)), 5U))))))) 
                                    | (Vfm_en__ConstPool__CONST_hfdda0392_0[
                                       (((IData)(0x10U) 
                                         + (0x1fffU 
                                            & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                >> 8U)), 5U))) 
                                        >> 5U)] >> 
                                       (0x1fU & ((IData)(0x10U) 
                                                 + 
                                                 (0x1fffU 
                                                  & VL_SHIFTL_III(13,13,32, 
                                                                  (0xffU 
                                                                   & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                      >> 8U)), 5U))))))) 
                                - (IData)(0x6980U)));
    }
    vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
        = __Vtemp_1;
    vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase 
        = __Vdly__FM_tb__DOT__uut__DOT__cw__DOT__phase;
}

void Vfm_en___024root___timing_resume(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___timing_resume\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vfm_en___024root___eval_triggers__act(Vfm_en___024root* vlSelf);

bool Vfm_en___024root___eval_phase__act(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_phase__act\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfm_en___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vfm_en___024root___timing_resume(vlSelf);
        Vfm_en___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfm_en___024root___eval_phase__nba(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_phase__nba\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfm_en___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm_en___024root___dump_triggers__nba(Vfm_en___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm_en___024root___dump_triggers__act(Vfm_en___024root* vlSelf);
#endif  // VL_DEBUG

void Vfm_en___024root___eval(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vfm_en___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fm_en_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vfm_en___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fm_en_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vfm_en___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vfm_en___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfm_en___024root___eval_debug_assertions(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_debug_assertions\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
