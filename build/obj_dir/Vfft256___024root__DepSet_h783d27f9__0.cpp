// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft256.h for the primary calling header

#include "Vfft256__pch.h"
#include "Vfft256___024root.h"

VlCoroutine Vfft256___024root___eval_initial__TOP__Vtiming__0(Vfft256___024root* vlSelf);
VlCoroutine Vfft256___024root___eval_initial__TOP__Vtiming__1(Vfft256___024root* vlSelf);

void Vfft256___024root___eval_initial(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___eval_initial\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vfft256___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vfft256___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__FFT256_tb__DOT__clock__0 
        = vlSelfRef.FFT256_tb__DOT__clock;
}

VL_INLINE_OPT VlCoroutine Vfft256___024root___eval_initial__TOP__Vtiming__1(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "fft256_tb.sv", 
                                             30);
        vlSelfRef.FFT256_tb__DOT__clock = (1U & (~ (IData)(vlSelfRef.FFT256_tb__DOT__clock)));
    }
}

void Vfft256___024root___act_sequent__TOP__0(Vfft256___024root* vlSelf);

void Vfft256___024root___eval_act(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___eval_act\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vfft256___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

extern const VlWide<128>/*4095:0*/ Vfft256__ConstPool__CONST_hf3784b49_0;
extern const VlWide<64>/*2047:0*/ Vfft256__ConstPool__CONST_h8abd5580_0;
extern const VlWide<32>/*1023:0*/ Vfft256__ConstPool__CONST_hb3c963b9_0;
extern const VlWide<16>/*511:0*/ Vfft256__ConstPool__CONST_h942db0a5_0;
extern const VlWide<8>/*255:0*/ Vfft256__ConstPool__CONST_hfd15effc_0;

VL_INLINE_OPT void Vfft256___024root___act_sequent__TOP__0(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___act_sequent__TOP__0\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_real 
           - vlSelfRef.FFT256_tb__DOT__io_in_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_imag 
           - vlSelfRef.FFT256_tb__DOT__io_in_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__io_in_real + vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__io_in_imag + vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_imag);
    FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T);
    if ((0x40U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_imag;
    }
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft256__ConstPool__CONST_hf3784b49_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xfffU 
                                                                        & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0xfffU 
                                                                          & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft256__ConstPool__CONST_hf3784b49_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0xfffU 
                                                                     & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft256__ConstPool__CONST_hf3784b49_0[
                                                                   (0x7fU 
                                                                    & (VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_imag);
    if ((0x20U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft256__ConstPool__CONST_h8abd5580_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7ffU 
                                                                        & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x7ffU 
                                                                          & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft256__ConstPool__CONST_h8abd5580_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7ffU 
                                                                     & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft256__ConstPool__CONST_h8abd5580_0[
                                                                   (0x3fU 
                                                                    & (VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    if ((0x10U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft256__ConstPool__CONST_hb3c963b9_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x3ffU 
                                                                        & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x3ffU 
                                                                          & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft256__ConstPool__CONST_hb3c963b9_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x3ffU 
                                                                     & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft256__ConstPool__CONST_hb3c963b9_0[
                                                                   (0x1fU 
                                                                    & (VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    if ((8U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft256__ConstPool__CONST_h942db0a5_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x1ffU 
                                                                        & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x1ffU 
                                                                          & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft256__ConstPool__CONST_h942db0a5_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft256__ConstPool__CONST_h942db0a5_0[
                                                                   (0xfU 
                                                                    & (VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    if ((4U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft256__ConstPool__CONST_hfd15effc_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xffU 
                                                                        & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0xffU 
                                                                          & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft256__ConstPool__CONST_hfd15effc_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0xffU 
                                                                     & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft256__ConstPool__CONST_hfd15effc_0[
                                                                   (7U 
                                                                    & (VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    if ((2U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_real);
    __Vtemp_1[0U] = 0x100000U;
    __Vtemp_1[1U] = 0xb504fU;
    __Vtemp_1[2U] = 0U;
    __Vtemp_1[3U] = 0xfff4afb1U;
    __Vtemp_2[0U] = 0x100000U;
    __Vtemp_2[1U] = 0xb504fU;
    __Vtemp_2[2U] = 0U;
    __Vtemp_2[3U] = 0xfff4afb1U;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (__Vtemp_1[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7fU 
                                                                        & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x7fU 
                                                                          & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (__Vtemp_2[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7fU 
                                                                     & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (__Vtemp_2[
                                                                   (3U 
                                                                    & (VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_imag);
    if ((1U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((QData)((IData)((0x100000U 
                                                  & ((~ (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)) 
                                                     << 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T)))));
}

void Vfft256___024root___nba_sequent__TOP__0(Vfft256___024root* vlSelf);
void Vfft256___024root___nba_comb__TOP__0(Vfft256___024root* vlSelf);

void Vfft256___024root___eval_nba(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___eval_nba\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfft256___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfft256___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

extern const VlWide<64>/*2047:0*/ Vfft256__ConstPool__CONST_h5478b25e_0;
extern const VlWide<32>/*1023:0*/ Vfft256__ConstPool__CONST_h35564355_0;
extern const VlWide<16>/*511:0*/ Vfft256__ConstPool__CONST_h0bfcbe7a_0;
extern const VlWide<8>/*255:0*/ Vfft256__ConstPool__CONST_h04042068_0;
extern const VlWide<128>/*4095:0*/ Vfft256__ConstPool__CONST_h944bc563_0;

VL_INLINE_OPT void Vfft256___024root___nba_sequent__TOP__0(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___nba_sequent__TOP__0\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vdly__FFT256_tb__DOT__uut__DOT__cnt;
    __Vdly__FFT256_tb__DOT__uut__DOT__cnt = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    // Body
    __Vdly__FFT256_tb__DOT__uut__DOT__cnt = vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt;
    if (vlSelfRef.FFT256_tb__DOT__reset) {
        __Vdly__FFT256_tb__DOT__uut__DOT__cnt = 0U;
    } else if (vlSelfRef.FFT256_tb__DOT__io_in_valid) {
        __Vdly__FFT256_tb__DOT__uut__DOT__cnt = (0xffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)));
    }
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out1_REG_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__out1_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out2_REG_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__out1_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out1_REG_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__out1_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out2_REG_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__out1_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_378_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_378_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_374_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_374_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_366_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_366_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_350_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_350_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_126_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_126_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_318_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_318_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_254_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_254_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_255 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_254;
    if ((1U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__out1_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_imag;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__out1_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_real;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__out1_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_imag;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__out1_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_real;
    }
    if ((2U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_378_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_imag;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_378_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_real;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_378_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_imag;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_378_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_real;
    }
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_374_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_373_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_374_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_373_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_366_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_365_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_366_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_365_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_350_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_349_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_350_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_349_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_126_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_125_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_126_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_125_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_318_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_317_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_318_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_317_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_254_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_253_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_254_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_253_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_254 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_253;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_376_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_376_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_373_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_372_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_373_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_372_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_365_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_364_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_365_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_364_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_349_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_348_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_349_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_348_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_125_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_124_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_125_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_124_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_317_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_316_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_317_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_316_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_253_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_252_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_253_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_252_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_253 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_252;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_376_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_376_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    if ((4U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_372_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_372_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_372_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_372_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_imag;
    }
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_364_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_363_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_364_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_363_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_348_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_347_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_348_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_347_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_124_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_123_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_124_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_123_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_316_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_315_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_316_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_315_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_252_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_251_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_252_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_251_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_252 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_251;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_370_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_370_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_363_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_362_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_363_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_362_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_347_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_346_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_347_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_346_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_123_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_122_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_123_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_122_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_315_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_314_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_315_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_314_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_251_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_250_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_251_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_250_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_251 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_250;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_370_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_369_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_370_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_369_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_362_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_361_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_362_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_361_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_346_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_345_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_346_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_345_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_122_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_121_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_122_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_121_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_314_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_313_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_314_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_313_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_250_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_249_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_250_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_249_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_250 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_249;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_369_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_368_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_369_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_368_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_361_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_360_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_361_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_360_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_345_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_344_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_345_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_344_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_121_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_120_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_121_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_120_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_313_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_312_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_313_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_312_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_249_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_248_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_249_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_248_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_249 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_248;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_368_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_368_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    if ((8U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_360_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_360_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_360_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_360_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_imag;
    }
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_344_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_343_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_344_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_343_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_120_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_119_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_120_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_119_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_312_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_311_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_312_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_311_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_248_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_247_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_248_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_247_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_248 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_247;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_358_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_358_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_343_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_342_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_343_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_342_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_119_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_118_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_119_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_118_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_311_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_310_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_311_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_310_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_247_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_246_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_247_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_246_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_247 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_246;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_358_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_357_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_358_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_357_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_342_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_341_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_342_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_341_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_118_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_117_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_118_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_117_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_310_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_309_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_310_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_309_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_246_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_245_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_246_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_245_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_246 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_245;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_357_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_356_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_357_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_356_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_341_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_340_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_341_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_340_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_117_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_116_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_117_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_116_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_309_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_308_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_309_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_308_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_245_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_244_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_245_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_244_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_245 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_244;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_356_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_355_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_356_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_355_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_340_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_339_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_340_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_339_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_116_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_115_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_116_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_115_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_308_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_307_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_308_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_307_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_244_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_243_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_244_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_243_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_244 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_243;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_355_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_354_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_355_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_354_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_339_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_338_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_339_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_338_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_115_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_114_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_115_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_114_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_307_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_306_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_307_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_306_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_243_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_242_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_243_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_242_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_243 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_242;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_354_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_353_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_354_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_353_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_338_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_337_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_338_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_337_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_114_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_113_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_114_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_113_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_306_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_305_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_306_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_305_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_242_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_241_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_242_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_241_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_242 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_241;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_353_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_352_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_353_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_352_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_337_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_336_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_337_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_336_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_113_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_112_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_113_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_112_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_305_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_304_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_305_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_304_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_241_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_240_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_241_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_240_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_241 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_240;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_352_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_352_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    if ((0x10U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_336_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_336_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_336_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_336_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_imag;
    }
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_112_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_111_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_112_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_111_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_304_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_303_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_304_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_303_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_240_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_239_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_240_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_239_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_240 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_239;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_334_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_334_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_111_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_110_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_111_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_110_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_303_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_302_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_303_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_302_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_239_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_238_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_239_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_238_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_239 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_238;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_334_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_333_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_334_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_333_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_110_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_109_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_110_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_109_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_302_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_301_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_302_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_301_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_238_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_237_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_238_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_237_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_238 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_237;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_333_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_332_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_333_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_332_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_109_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_108_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_109_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_108_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_301_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_300_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_301_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_300_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_237_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_236_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_237_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_236_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_237 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_236;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_332_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_331_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_332_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_331_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_108_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_107_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_108_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_107_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_300_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_299_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_300_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_299_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_236_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_235_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_236_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_235_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_236 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_235;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_331_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_330_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_331_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_330_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_107_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_106_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_107_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_106_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_299_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_298_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_299_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_298_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_235_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_234_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_235_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_234_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_235 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_234;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_330_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_329_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_330_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_329_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_106_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_105_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_106_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_105_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_298_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_297_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_298_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_297_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_234_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_233_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_234_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_233_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_234 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_233;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_329_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_328_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_329_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_328_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_105_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_104_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_105_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_104_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_297_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_296_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_297_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_296_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_233_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_232_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_233_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_232_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_233 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_232;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_328_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_327_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_328_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_327_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_104_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_103_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_104_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_103_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_296_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_295_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_296_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_295_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_232_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_231_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_232_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_231_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_232 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_231;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_327_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_326_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_327_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_326_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_103_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_102_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_103_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_102_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_295_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_294_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_295_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_294_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_231_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_230_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_231_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_230_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_231 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_230;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_326_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_325_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_326_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_325_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_102_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_101_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_102_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_101_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_294_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_293_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_294_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_293_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_230_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_229_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_230_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_229_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_230 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_229;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_325_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_324_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_325_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_324_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_101_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_100_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_101_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_100_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_293_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_292_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_293_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_292_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_229_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_228_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_229_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_228_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_229 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_228;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_324_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_323_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_324_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_323_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_100_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_99_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_100_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_99_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_292_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_291_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_292_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_291_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_228_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_227_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_228_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_227_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_228 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_227;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_323_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_322_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_323_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_322_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_99_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_98_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_99_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_98_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_291_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_290_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_291_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_290_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_227_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_226_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_227_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_226_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_227 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_226;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_322_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_321_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_322_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_321_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_98_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_97_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_98_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_97_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_290_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_289_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_290_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_289_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_226_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_225_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_226_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_225_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_226 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_225;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_321_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_320_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_321_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_320_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_97_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_96_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_97_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_96_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_289_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_288_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_289_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_288_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_225_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_224_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_225_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_224_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_225 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_224;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_320_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_320_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_96_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_95_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_96_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_95_imag;
    if ((0x20U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_288_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_288_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_288_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_288_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_imag;
    }
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_224_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_223_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_224_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_223_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_224 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_223;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_95_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_94_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_95_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_94_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_286_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_286_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_223_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_222_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_223_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_222_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_223 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_222;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_94_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_93_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_94_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_93_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_286_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_285_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_286_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_285_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_222_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_221_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_222_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_221_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_222 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_221;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_93_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_92_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_93_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_92_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_285_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_284_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_285_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_284_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_221_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_220_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_221_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_220_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_221 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_220;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_92_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_91_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_92_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_91_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_284_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_283_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_284_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_283_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_220_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_219_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_220_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_219_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_220 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_219;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_91_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_90_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_91_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_90_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_283_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_282_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_283_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_282_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_219_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_218_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_219_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_218_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_219 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_218;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_90_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_89_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_90_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_89_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_282_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_281_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_282_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_281_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_218_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_217_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_218_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_217_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_218 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_217;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_89_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_88_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_89_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_88_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_281_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_280_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_281_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_280_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_217_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_216_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_217_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_216_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_217 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_216;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_88_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_87_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_88_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_87_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_280_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_279_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_280_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_279_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_216_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_215_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_216_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_215_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_216 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_215;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_87_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_86_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_87_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_86_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_279_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_278_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_279_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_278_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_215_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_214_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_215_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_214_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_215 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_214;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_86_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_85_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_86_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_85_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_278_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_277_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_278_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_277_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_214_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_213_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_214_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_213_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_214 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_213;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_85_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_84_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_85_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_84_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_277_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_276_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_277_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_276_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_213_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_212_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_213_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_212_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_213 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_212;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_84_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_83_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_84_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_83_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_276_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_275_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_276_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_275_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_212_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_211_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_212_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_211_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_212 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_211;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_83_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_82_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_83_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_82_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_275_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_274_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_275_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_274_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_211_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_210_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_211_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_210_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_211 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_210;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_82_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_81_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_82_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_81_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_274_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_273_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_274_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_273_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_210_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_209_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_210_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_209_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_210 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_209;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_81_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_80_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_81_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_80_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_273_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_272_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_273_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_272_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_209_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_208_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_209_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_208_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_209 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_208;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_80_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_79_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_80_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_79_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_272_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_271_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_272_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_271_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_208_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_207_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_208_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_207_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_208 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_207;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_79_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_78_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_79_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_78_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_271_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_270_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_271_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_270_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_207_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_206_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_207_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_206_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_207 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_206;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_78_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_77_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_78_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_77_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_270_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_269_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_270_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_269_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_206_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_205_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_206_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_205_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_206 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_205;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_77_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_76_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_77_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_76_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_269_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_268_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_269_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_268_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_205_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_204_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_205_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_204_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_205 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_204;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_76_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_75_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_76_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_75_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_268_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_267_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_268_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_267_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_204_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_203_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_204_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_203_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_204 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_203;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_75_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_74_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_75_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_74_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_267_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_266_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_267_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_266_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_203_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_202_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_203_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_202_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_203 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_202;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_74_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_73_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_74_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_73_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_266_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_265_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_266_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_265_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_202_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_201_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_202_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_201_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_202 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_201;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_73_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_72_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_73_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_72_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_265_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_264_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_265_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_264_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_201_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_200_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_201_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_200_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_201 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_200;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_72_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_71_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_72_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_71_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_264_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_263_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_264_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_263_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_200_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_199_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_200_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_199_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_200 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_199;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_71_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_70_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_71_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_70_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_263_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_262_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_263_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_262_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_199_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_198_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_199_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_198_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_199 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_198;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_70_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_69_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_70_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_69_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_262_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_261_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_262_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_261_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_198_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_197_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_198_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_197_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_198 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_197;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_69_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_68_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_69_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_68_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_261_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_260_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_261_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_260_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_197_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_196_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_197_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_196_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_197 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_196;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_68_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_67_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_68_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_67_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_260_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_259_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_260_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_259_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_196_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_195_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_196_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_195_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_196 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_195;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_67_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_66_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_67_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_66_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_259_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_258_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_259_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_258_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_195_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_194_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_195_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_194_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_195 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_194;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_66_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_65_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_66_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_65_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_258_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_257_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_258_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_257_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_194_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_193_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_194_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_193_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_194 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_193;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_65_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_64_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_65_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_64_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_257_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_256_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_257_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_256_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_193_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_192_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_193_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_192_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_193 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_192;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_64_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_63_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_64_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_63_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_256_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_256_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    if ((0x40U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_192_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_192_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_192_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT__r_192_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_imag;
    }
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_192 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_191;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt = __Vdly__FFT256_tb__DOT__uut__DOT__cnt;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_63_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_62_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_63_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_62_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_190_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                           (0x3fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft256__ConstPool__CONST_h5478b25e_0[
                      (((IData)(0x1fU) + (0x7ffU & 
                                          VL_SHIFTL_III(11,11,32, 
                                                        (0x3fU 
                                                         & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft256__ConstPool__CONST_h5478b25e_0[
               (0x3fU & (VL_SHIFTL_III(11,11,32, (0x3fU 
                                                  & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                             (0x3fU 
                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft256__ConstPool__CONST_h8abd5580_0[
                        (((IData)(0x1fU) + (0x7ffU 
                                            & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft256__ConstPool__CONST_h8abd5580_0[
                 (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                         (0x3fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                           (0x3fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft256__ConstPool__CONST_h5478b25e_0[
                      (((IData)(0x1fU) + (0x7ffU & 
                                          VL_SHIFTL_III(11,11,32, 
                                                        (0x3fU 
                                                         & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft256__ConstPool__CONST_h5478b25e_0[
               (0x3fU & (VL_SHIFTL_III(11,11,32, (0x3fU 
                                                  & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                             (0x3fU 
                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft256__ConstPool__CONST_h8abd5580_0[
                        (((IData)(0x1fU) + (0x7ffU 
                                            & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft256__ConstPool__CONST_h8abd5580_0[
                 (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                         (0x3fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                           (0x1fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft256__ConstPool__CONST_h35564355_0[
                      (((IData)(0x1fU) + (0x3ffU & 
                                          VL_SHIFTL_III(10,10,32, 
                                                        (0x1fU 
                                                         & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft256__ConstPool__CONST_h35564355_0[
               (0x1fU & (VL_SHIFTL_III(10,10,32, (0x1fU 
                                                  & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                             (0x1fU 
                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft256__ConstPool__CONST_hb3c963b9_0[
                        (((IData)(0x1fU) + (0x3ffU 
                                            & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft256__ConstPool__CONST_hb3c963b9_0[
                 (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                         (0x1fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                           (0x1fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft256__ConstPool__CONST_h35564355_0[
                      (((IData)(0x1fU) + (0x3ffU & 
                                          VL_SHIFTL_III(10,10,32, 
                                                        (0x1fU 
                                                         & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft256__ConstPool__CONST_h35564355_0[
               (0x1fU & (VL_SHIFTL_III(10,10,32, (0x1fU 
                                                  & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                             (0x1fU 
                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft256__ConstPool__CONST_hb3c963b9_0[
                        (((IData)(0x1fU) + (0x3ffU 
                                            & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft256__ConstPool__CONST_hb3c963b9_0[
                 (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                         (0x1fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                           (0xfU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft256__ConstPool__CONST_h0bfcbe7a_0[
                      (((IData)(0x1fU) + (0x1ffU & 
                                          VL_SHIFTL_III(9,9,32, 
                                                        (0xfU 
                                                         & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft256__ConstPool__CONST_h0bfcbe7a_0[
               (0xfU & (VL_SHIFTL_III(9,9,32, (0xfU 
                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                        >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                           (0xfU 
                                                            & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                             (0xfU 
                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft256__ConstPool__CONST_h942db0a5_0[
                        (((IData)(0x1fU) + (0x1ffU 
                                            & VL_SHIFTL_III(9,9,32, 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft256__ConstPool__CONST_h942db0a5_0[
                 (0xfU & (VL_SHIFTL_III(9,9,32, (0xfU 
                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                          >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                           (0xfU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft256__ConstPool__CONST_h0bfcbe7a_0[
                      (((IData)(0x1fU) + (0x1ffU & 
                                          VL_SHIFTL_III(9,9,32, 
                                                        (0xfU 
                                                         & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft256__ConstPool__CONST_h0bfcbe7a_0[
               (0xfU & (VL_SHIFTL_III(9,9,32, (0xfU 
                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                        >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                           (0xfU 
                                                            & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                             (0xfU 
                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft256__ConstPool__CONST_h942db0a5_0[
                        (((IData)(0x1fU) + (0x1ffU 
                                            & VL_SHIFTL_III(9,9,32, 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft256__ConstPool__CONST_h942db0a5_0[
                 (0xfU & (VL_SHIFTL_III(9,9,32, (0xfU 
                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                          >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                           (7U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft256__ConstPool__CONST_h04042068_0[
                      (((IData)(0x1fU) + (0xffU & VL_SHIFTL_III(8,8,32, 
                                                                (7U 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft256__ConstPool__CONST_h04042068_0[
               (7U & (VL_SHIFTL_III(8,8,32, (7U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                      >> 5U))] >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                         (7U 
                                                          & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                             (7U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft256__ConstPool__CONST_hfd15effc_0[
                        (((IData)(0x1fU) + (0xffU & 
                                            VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                              (7U 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft256__ConstPool__CONST_hfd15effc_0[
                 (7U & (VL_SHIFTL_III(8,8,32, (7U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                        >> 5U))] >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                           (7U 
                                                            & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                           (7U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft256__ConstPool__CONST_h04042068_0[
                      (((IData)(0x1fU) + (0xffU & VL_SHIFTL_III(8,8,32, 
                                                                (7U 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft256__ConstPool__CONST_h04042068_0[
               (7U & (VL_SHIFTL_III(8,8,32, (7U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                      >> 5U))] >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                         (7U 
                                                          & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                             (7U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft256__ConstPool__CONST_hfd15effc_0[
                        (((IData)(0x1fU) + (0xffU & 
                                            VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                              (7U 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft256__ConstPool__CONST_hfd15effc_0[
                 (7U & (VL_SHIFTL_III(8,8,32, (7U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                        >> 5U))] >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                           (7U 
                                                            & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    __Vtemp_1[0U] = 0U;
    __Vtemp_1[1U] = 0xb504fU;
    __Vtemp_1[2U] = 0x100000U;
    __Vtemp_1[3U] = 0xb504fU;
    __Vtemp_2[0U] = 0x100000U;
    __Vtemp_2[1U] = 0xb504fU;
    __Vtemp_2[2U] = 0U;
    __Vtemp_2[3U] = 0xfff4afb1U;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                           (3U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (__Vtemp_1[(((IData)(0x1fU) + 
                                  (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                 >> 5U)] << ((IData)(0x20U) 
                                             - (0x1fU 
                                                & VL_SHIFTL_III(7,7,32, 
                                                                (3U 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (__Vtemp_1[(3U & (VL_SHIFTL_III(7,7,32, 
                                              (3U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                >> 5U))] >> (0x1fU 
                                             & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                             (3U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (__Vtemp_2[(((IData)(0x1fU) 
                                    + (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (__Vtemp_2[(3U & (VL_SHIFTL_III(7,7,32, 
                                                (3U 
                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                  >> 5U))] >> (0x1fU 
                                               & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0xb504fU;
    __Vtemp_3[2U] = 0x100000U;
    __Vtemp_3[3U] = 0xb504fU;
    __Vtemp_4[0U] = 0x100000U;
    __Vtemp_4[1U] = 0xb504fU;
    __Vtemp_4[2U] = 0U;
    __Vtemp_4[3U] = 0xfff4afb1U;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                           (3U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (__Vtemp_3[(((IData)(0x1fU) + 
                                  (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                 >> 5U)] << ((IData)(0x20U) 
                                             - (0x1fU 
                                                & VL_SHIFTL_III(7,7,32, 
                                                                (3U 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (__Vtemp_3[(3U & (VL_SHIFTL_III(7,7,32, 
                                              (3U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                >> 5U))] >> (0x1fU 
                                             & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                             (3U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (__Vtemp_4[(((IData)(0x1fU) 
                                    + (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (__Vtemp_4[(3U & (VL_SHIFTL_III(7,7,32, 
                                                (3U 
                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                  >> 5U))] >> (0x1fU 
                                               & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T 
        = ((0x100000U & ((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt) 
                         << 0x14U)) - (0x100000U & 
                                       ((~ (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)) 
                                        << 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T 
        = ((0x100000U & ((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt) 
                         << 0x14U)) + (0x100000U & 
                                       ((~ (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)) 
                                        << 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_190_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_191 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_190;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_62_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_61_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_62_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_61_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_190_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_189_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_190_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_189_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_190 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_189;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_61_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_60_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_61_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_60_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_189_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_188_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_189_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_188_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_189 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_188;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_60_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_59_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_60_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_59_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_188_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_187_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_188_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_187_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_188 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_187;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_59_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_58_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_59_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_58_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_187_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_186_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_187_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_186_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_187 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_186;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_58_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_57_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_58_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_57_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_186_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_185_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_186_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_185_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_186 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_185;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_57_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_56_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_57_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_56_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_185_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_184_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_185_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_184_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_185 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_184;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_56_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_55_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_56_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_55_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_184_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_183_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_184_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_183_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_184 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_183;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_55_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_54_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_55_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_54_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_183_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_182_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_183_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_182_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_183 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_182;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_54_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_53_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_54_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_53_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_182_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_181_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_182_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_181_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_182 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_181;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_53_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_52_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_53_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_52_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_181_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_180_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_181_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_180_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_181 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_180;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_52_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_51_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_52_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_51_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_180_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_179_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_180_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_179_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_180 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_179;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_51_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_50_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_51_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_50_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_179_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_178_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_179_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_178_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_179 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_178;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_50_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_49_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_50_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_49_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_178_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_177_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_178_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_177_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_178 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_177;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_49_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_48_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_49_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_48_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_177_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_176_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_177_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_176_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_177 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_176;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_48_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_47_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_48_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_47_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_176_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_175_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_176_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_175_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_176 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_175;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_47_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_46_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_47_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_46_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_175_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_174_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_175_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_174_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_175 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_174;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_46_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_45_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_46_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_45_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_174_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_173_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_174_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_173_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_174 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_173;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_45_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_44_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_45_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_44_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_173_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_172_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_173_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_172_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_173 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_172;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_44_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_43_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_44_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_43_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_172_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_171_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_172_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_171_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_172 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_171;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_43_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_42_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_43_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_42_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_171_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_170_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_171_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_170_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_171 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_170;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_42_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_41_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_42_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_41_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_170_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_169_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_170_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_169_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_170 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_169;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_41_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_40_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_41_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_40_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_169_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_168_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_169_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_168_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_169 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_168;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_40_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_39_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_40_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_39_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_168_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_167_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_168_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_167_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_168 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_167;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_39_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_38_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_39_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_38_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_167_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_166_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_167_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_166_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_167 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_166;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_38_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_37_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_38_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_37_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_166_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_165_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_166_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_165_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_166 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_165;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_37_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_36_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_37_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_36_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_165_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_164_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_165_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_164_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_165 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_164;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_36_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_35_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_36_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_35_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_164_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_163_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_164_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_163_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_164 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_163;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_35_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_34_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_35_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_34_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_163_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_162_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_163_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_162_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_163 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_162;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_34_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_33_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_34_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_33_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_162_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_161_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_162_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_161_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_162 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_161;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_33_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_32_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_33_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_32_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_161_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_160_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_161_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_160_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_161 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_160;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_32_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_31_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_32_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_31_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_160_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_159_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_160_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_159_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_160 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_159;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_31_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_30_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_31_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_30_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_159_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_158_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_159_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_158_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_159 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_158;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_30_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_29_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_30_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_29_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_158_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_157_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_158_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_157_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_158 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_157;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_29_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_28_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_29_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_28_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_157_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_156_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_157_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_156_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_157 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_156;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_28_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_27_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_28_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_27_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_156_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_155_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_156_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_155_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_156 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_155;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_27_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_26_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_27_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_26_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_155_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_154_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_155_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_154_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_155 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_154;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_26_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_25_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_26_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_25_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_154_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_153_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_154_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_153_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_154 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_153;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_25_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_24_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_25_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_24_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_153_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_152_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_153_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_152_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_153 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_152;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_24_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_23_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_24_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_23_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_152_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_151_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_152_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_151_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_152 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_151;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_23_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_22_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_23_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_22_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_151_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_150_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_151_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_150_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_151 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_150;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_22_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_21_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_22_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_21_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_150_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_149_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_150_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_149_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_150 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_149;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_21_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_20_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_21_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_20_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_149_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_148_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_149_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_148_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_149 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_148;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_20_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_19_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_20_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_19_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_148_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_147_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_148_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_147_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_148 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_147;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_19_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_18_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_19_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_18_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_147_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_146_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_147_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_146_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_147 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_146;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_18_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_17_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_18_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_17_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_146_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_145_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_146_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_145_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_146 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_145;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_17_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_16_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_17_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_16_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_145_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_144_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_145_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_144_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_145 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_144;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_16_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_15_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_16_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_15_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_144_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_143_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_144_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_143_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_144 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_143;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_15_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_14_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_15_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_14_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_143_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_142_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_143_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_142_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_143 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_142;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_14_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_13_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_14_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_13_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_142_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_141_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_142_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_141_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_142 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_141;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_13_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_12_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_13_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_12_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_141_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_140_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_141_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_140_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_141 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_140;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_12_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_11_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_12_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_11_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_140_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_139_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_140_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_139_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_140 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_139;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_11_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_10_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_11_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_10_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_139_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_138_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_139_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_138_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_139 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_138;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_10_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_9_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_10_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_9_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_138_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_137_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_138_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_137_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_138 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_137;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_9_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_8_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_9_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_8_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_137_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_136_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_137_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_136_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_137 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_136;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_8_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_7_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_8_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_7_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_136_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_135_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_136_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_135_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_136 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_135;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_7_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_6_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_7_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_6_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_135_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_134_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_135_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_134_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_135 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_134;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_6_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_5_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_6_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_5_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_134_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_133_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_134_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_133_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_134 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_133;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_5_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_4_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_5_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_4_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_133_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_132_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_133_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_132_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_133 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_132;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_4_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_3_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_4_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_3_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_132_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_131_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_132_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_131_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_132 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_131;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_3_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_2_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_3_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_2_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_131_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_130_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_131_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_130_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_131 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_130;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_2_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_1_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_2_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_1_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_130_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_129_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_130_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_129_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_130 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_129;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_1_real = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_1_imag = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_129_real 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_128_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_129_imag 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_128_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_129 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_128;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_real = vlSelfRef.FFT256_tb__DOT__io_in_real;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_imag = vlSelfRef.FFT256_tb__DOT__io_in_imag;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_128_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__r_128_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_128 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_127;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(12,12,32, 
                                           (0x7fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft256__ConstPool__CONST_h944bc563_0[
                      (((IData)(0x1fU) + (0xfffU & 
                                          VL_SHIFTL_III(12,12,32, 
                                                        (0x7fU 
                                                         & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                          (0x7fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft256__ConstPool__CONST_h944bc563_0[
               (0x7fU & (VL_SHIFTL_III(12,12,32, (0x7fU 
                                                  & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                            (0x7fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(12,12,32, 
                                             (0x7fU 
                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft256__ConstPool__CONST_hf3784b49_0[
                        (((IData)(0x1fU) + (0xfffU 
                                            & VL_SHIFTL_III(12,12,32, 
                                                            (0x7fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft256__ConstPool__CONST_hf3784b49_0[
                 (0x7fU & (VL_SHIFTL_III(12,12,32, 
                                         (0x7fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(12,12,32, 
                                           (0x7fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft256__ConstPool__CONST_h944bc563_0[
                      (((IData)(0x1fU) + (0xfffU & 
                                          VL_SHIFTL_III(12,12,32, 
                                                        (0x7fU 
                                                         & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                          (0x7fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft256__ConstPool__CONST_h944bc563_0[
               (0x7fU & (VL_SHIFTL_III(12,12,32, (0x7fU 
                                                  & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                            (0x7fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(12,12,32, 
                                             (0x7fU 
                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft256__ConstPool__CONST_hf3784b49_0[
                        (((IData)(0x1fU) + (0xfffU 
                                            & VL_SHIFTL_III(12,12,32, 
                                                            (0x7fU 
                                                             & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft256__ConstPool__CONST_hf3784b49_0[
                 (0x7fU & (VL_SHIFTL_III(12,12,32, 
                                         (0x7fU & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_127 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_126;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_126 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_125;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_125 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_124;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_124 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_123;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_123 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_122;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_122 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_121;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_121 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_120;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_120 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_119;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_119 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_118;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_118 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_117;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_117 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_116;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_116 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_115;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_115 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_114;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_114 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_113;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_113 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_112;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_112 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_111;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_111 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_110;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_110 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_109;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_109 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_108;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_108 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_107;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_107 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_106;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_106 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_105;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_105 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_104;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_104 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_103;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_103 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_102;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_102 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_101;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_101 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_100;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_100 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_99;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_99 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_98;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_98 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_97;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_97 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_96;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_96 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_95;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_95 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_94;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_94 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_93;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_93 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_92;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_92 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_91;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_91 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_90;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_90 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_89;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_89 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_88;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_88 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_87;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_87 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_86;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_86 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_85;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_85 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_84;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_84 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_83;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_83 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_82;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_82 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_81;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_81 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_80;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_80 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_79;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_79 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_78;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_78 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_77;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_77 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_76;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_76 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_75;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_75 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_74;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_74 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_73;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_73 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_72;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_72 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_71;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_71 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_70;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_70 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_69;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_69 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_68;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_68 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_67;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_67 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_66;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_66 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_65;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_65 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_64;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_64 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_63;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_63 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_62;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_62 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_61;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_61 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_60;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_60 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_59;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_59 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_58;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_58 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_57;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_57 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_56;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_56 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_55;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_55 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_54;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_54 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_53;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_53 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_52;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_52 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_51;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_51 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_50;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_50 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_49;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_49 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_48;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_48 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_47;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_47 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_46;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_46 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_45;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_45 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_44;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_44 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_43;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_43 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_42;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_42 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_41;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_41 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_40;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_40 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_39;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_39 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_38;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_38 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_37;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_37 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_36;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_36 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_35;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_35 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_34;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_34 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_33;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_33 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_32;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_32 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_31;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_31 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_30;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_30 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_29;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_29 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_28;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_28 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_27;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_27 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_26;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_26 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_25;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_25 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_24;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_24 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_23;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_23 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_22;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_22 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_21;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_21 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_20;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_20 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_19;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_19 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_18;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_18 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_17;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_17 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_16;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_16 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_15;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_15 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_14;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_14 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_13;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_13 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_12;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_12 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_11;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_11 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_10;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_10 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_9;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_9 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_8;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_8 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_7;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_7 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_6;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_6 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_5;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_5 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_4;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_4 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_3;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_3 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_2;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_2 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_1;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_1 
        = vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r 
        = vlSelfRef.FFT256_tb__DOT__io_in_valid;
}

VL_INLINE_OPT void Vfft256___024root___nba_comb__TOP__0(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___nba_comb__TOP__0\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T;
    FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__io_in_real + vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__io_in_imag + vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_imag 
           - vlSelfRef.FFT256_tb__DOT__io_in_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_real 
           - vlSelfRef.FFT256_tb__DOT__io_in_real);
    if ((0x40U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_imag;
    }
    FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft256__ConstPool__CONST_hf3784b49_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xfffU 
                                                                        & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0xfffU 
                                                                          & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft256__ConstPool__CONST_hf3784b49_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0xfffU 
                                                                     & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft256__ConstPool__CONST_hf3784b49_0[
                                                                   (0x7fU 
                                                                    & (VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T)))));
    if ((0x20U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft256__ConstPool__CONST_h8abd5580_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7ffU 
                                                                        & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x7ffU 
                                                                          & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft256__ConstPool__CONST_h8abd5580_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7ffU 
                                                                     & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft256__ConstPool__CONST_h8abd5580_0[
                                                                   (0x3fU 
                                                                    & (VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    if ((0x10U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft256__ConstPool__CONST_hb3c963b9_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x3ffU 
                                                                        & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x3ffU 
                                                                          & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft256__ConstPool__CONST_hb3c963b9_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x3ffU 
                                                                     & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft256__ConstPool__CONST_hb3c963b9_0[
                                                                   (0x1fU 
                                                                    & (VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    if ((8U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft256__ConstPool__CONST_h942db0a5_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x1ffU 
                                                                        & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x1ffU 
                                                                          & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft256__ConstPool__CONST_h942db0a5_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft256__ConstPool__CONST_h942db0a5_0[
                                                                   (0xfU 
                                                                    & (VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    if ((4U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft256__ConstPool__CONST_hfd15effc_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xffU 
                                                                        & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0xffU 
                                                                          & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft256__ConstPool__CONST_hfd15effc_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0xffU 
                                                                     & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft256__ConstPool__CONST_hfd15effc_0[
                                                                   (7U 
                                                                    & (VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    if ((2U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_real 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_real 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_real);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_real 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_real);
    __Vtemp_1[0U] = 0x100000U;
    __Vtemp_1[1U] = 0xb504fU;
    __Vtemp_1[2U] = 0U;
    __Vtemp_1[3U] = 0xfff4afb1U;
    __Vtemp_2[0U] = 0x100000U;
    __Vtemp_2[1U] = 0xb504fU;
    __Vtemp_2[2U] = 0U;
    __Vtemp_2[3U] = 0xfff4afb1U;
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (__Vtemp_1[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7fU 
                                                                        & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x7fU 
                                                                          & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (__Vtemp_2[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7fU 
                                                                     & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (__Vtemp_2[
                                                                   (3U 
                                                                    & (VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_imag 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_imag 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_imag);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_imag 
           - vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_imag);
    if ((1U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_imag;
    } else {
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_real 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_real;
        vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_imag 
            = vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_imag;
    }
    FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((QData)((IData)((0x100000U 
                                                  & ((~ (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)) 
                                                     << 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T)))));
}

void Vfft256___024root___timing_resume(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___timing_resume\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vfft256___024root___eval_triggers__act(Vfft256___024root* vlSelf);

bool Vfft256___024root___eval_phase__act(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___eval_phase__act\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfft256___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vfft256___024root___timing_resume(vlSelf);
        Vfft256___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfft256___024root___eval_phase__nba(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___eval_phase__nba\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfft256___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft256___024root___dump_triggers__nba(Vfft256___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft256___024root___dump_triggers__act(Vfft256___024root* vlSelf);
#endif  // VL_DEBUG

void Vfft256___024root___eval(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___eval\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vfft256___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fft256_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vfft256___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fft256_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vfft256___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vfft256___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfft256___024root___eval_debug_assertions(Vfft256___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root___eval_debug_assertions\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
