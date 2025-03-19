// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft512.h for the primary calling header

#include "Vfft512__pch.h"
#include "Vfft512___024root.h"

void Vfft512___024root___timing_resume(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___timing_resume\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vfft512___024root___eval_triggers__act(Vfft512___024root* vlSelf);
void Vfft512___024root___eval_act(Vfft512___024root* vlSelf);

bool Vfft512___024root___eval_phase__act(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_phase__act\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfft512___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vfft512___024root___timing_resume(vlSelf);
        Vfft512___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vfft512___024root___eval_nba(Vfft512___024root* vlSelf);

bool Vfft512___024root___eval_phase__nba(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_phase__nba\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfft512___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft512___024root___dump_triggers__nba(Vfft512___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft512___024root___dump_triggers__act(Vfft512___024root* vlSelf);
#endif  // VL_DEBUG

void Vfft512___024root___eval(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vfft512___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fft512_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vfft512___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fft512_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vfft512___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vfft512___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfft512___024root___eval_debug_assertions(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_debug_assertions\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
