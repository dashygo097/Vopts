// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfir.h for the primary calling header

#include "Vfir__pch.h"
#include "Vfir___024root.h"

VlCoroutine Vfir___024root___eval_initial__TOP__Vtiming__0(Vfir___024root* vlSelf);
VlCoroutine Vfir___024root___eval_initial__TOP__Vtiming__1(Vfir___024root* vlSelf);

void Vfir___024root___eval_initial(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_initial\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vfir___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vfir___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__FIR_tb__DOT__clock__0 
        = vlSelfRef.FIR_tb__DOT__clock;
}

VL_INLINE_OPT VlCoroutine Vfir___024root___eval_initial__TOP__Vtiming__1(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "fir_tb.sv", 
                                             18);
        vlSelfRef.FIR_tb__DOT__clock = (1U & (~ (IData)(vlSelfRef.FIR_tb__DOT__clock)));
    }
}

void Vfir___024root___eval_act(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_act\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vfir___024root___nba_sequent__TOP__0(Vfir___024root* vlSelf);

void Vfir___024root___eval_nba(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_nba\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfir___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vfir___024root___nba_sequent__TOP__0(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___nba_sequent__TOP__0\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.FIR_tb__DOT__reset) {
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_15_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_14_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_13_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_12_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_11_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_10_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_9_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_8_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_7_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_6_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_5_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_4_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_3_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_2_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_1_value = 0U;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_0_value = 0U;
    } else {
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_15_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_14_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_14_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_13_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_13_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_12_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_12_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_11_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_11_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_10_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_10_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_9_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_9_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_8_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_8_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_7_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_7_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_6_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_6_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_5_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_5_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_4_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_4_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_3_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_3_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_2_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_2_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_1_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_1_value 
            = vlSelfRef.FIR_tb__DOT__uut__DOT__regs_0_value;
        vlSelfRef.FIR_tb__DOT__uut__DOT__regs_0_value 
            = vlSelfRef.FIR_tb__DOT__io_in_value;
    }
}

void Vfir___024root___timing_resume(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___timing_resume\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vfir___024root___eval_triggers__act(Vfir___024root* vlSelf);

bool Vfir___024root___eval_phase__act(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_phase__act\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfir___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vfir___024root___timing_resume(vlSelf);
        Vfir___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfir___024root___eval_phase__nba(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_phase__nba\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfir___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfir___024root___dump_triggers__nba(Vfir___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfir___024root___dump_triggers__act(Vfir___024root* vlSelf);
#endif  // VL_DEBUG

void Vfir___024root___eval(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vfir___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fir_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vfir___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fir_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vfir___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vfir___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfir___024root___eval_debug_assertions(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_debug_assertions\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
