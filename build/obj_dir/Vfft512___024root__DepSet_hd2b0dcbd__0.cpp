// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft512.h for the primary calling header

#include "Vfft512__pch.h"
#include "Vfft512___024root.h"

VlCoroutine Vfft512___024root___eval_initial__TOP__Vtiming__0(Vfft512___024root* vlSelf);
VlCoroutine Vfft512___024root___eval_initial__TOP__Vtiming__1(Vfft512___024root* vlSelf);

void Vfft512___024root___eval_initial(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_initial\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vfft512___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vfft512___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__FFT512_tb__DOT__clock__0 
        = vlSelfRef.FFT512_tb__DOT__clock;
}

VL_INLINE_OPT VlCoroutine Vfft512___024root___eval_initial__TOP__Vtiming__1(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "fft512_tb.sv", 
                                             30);
        vlSelfRef.FFT512_tb__DOT__clock = (1U & (~ (IData)(vlSelfRef.FFT512_tb__DOT__clock)));
    }
}

void Vfft512___024root___act_sequent__TOP__0(Vfft512___024root* vlSelf);

void Vfft512___024root___eval_act(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_act\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vfft512___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

extern const VlWide<256>/*8191:0*/ Vfft512__ConstPool__CONST_h010c7fca_0;
extern const VlWide<128>/*4095:0*/ Vfft512__ConstPool__CONST_hf3784b49_0;
extern const VlWide<64>/*2047:0*/ Vfft512__ConstPool__CONST_h8abd5580_0;
extern const VlWide<32>/*1023:0*/ Vfft512__ConstPool__CONST_hb3c963b9_0;
extern const VlWide<16>/*511:0*/ Vfft512__ConstPool__CONST_h942db0a5_0;
extern const VlWide<8>/*255:0*/ Vfft512__ConstPool__CONST_hfd15effc_0;

VL_INLINE_OPT void Vfft512___024root___act_sequent__TOP__0(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___act_sequent__TOP__0\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k1_T = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_real 
           - vlSelfRef.FFT512_tb__DOT__io_in_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_imag 
           - vlSelfRef.FFT512_tb__DOT__io_in_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__io_in_real + vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__io_in_imag + vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_imag);
    FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T);
    if ((0x80U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_imag;
    }
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_h010c7fca_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x1fffU 
                                                                        & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x1fffU 
                                                                          & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_h010c7fca_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1fffU 
                                                                     & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_h010c7fca_0[
                                                                   (0xffU 
                                                                    & (VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag);
    if ((0x40U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_hf3784b49_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xfffU 
                                                                        & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0xfffU 
                                                                          & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_hf3784b49_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0xfffU 
                                                                     & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_hf3784b49_0[
                                                                   (0x7fU 
                                                                    & (VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    if ((0x20U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_h8abd5580_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7ffU 
                                                                        & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x7ffU 
                                                                          & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_h8abd5580_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7ffU 
                                                                     & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_h8abd5580_0[
                                                                   (0x3fU 
                                                                    & (VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    if ((0x10U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_hb3c963b9_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x3ffU 
                                                                        & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x3ffU 
                                                                          & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_hb3c963b9_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x3ffU 
                                                                     & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_hb3c963b9_0[
                                                                   (0x1fU 
                                                                    & (VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    if ((8U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_h942db0a5_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x1ffU 
                                                                        & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x1ffU 
                                                                          & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_h942db0a5_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_h942db0a5_0[
                                                                   (0xfU 
                                                                    & (VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    if ((4U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_hfd15effc_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xffU 
                                                                        & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0xffU 
                                                                          & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_hfd15effc_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0xffU 
                                                                     & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_hfd15effc_0[
                                                                   (7U 
                                                                    & (VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag);
    if ((2U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real);
    __Vtemp_1[0U] = 0x100000U;
    __Vtemp_1[1U] = 0xb504fU;
    __Vtemp_1[2U] = 0U;
    __Vtemp_1[3U] = 0xfff4afb1U;
    __Vtemp_2[0U] = 0x100000U;
    __Vtemp_2[1U] = 0xb504fU;
    __Vtemp_2[2U] = 0U;
    __Vtemp_2[3U] = 0xfff4afb1U;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
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
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x7fU 
                                                                          & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (__Vtemp_2[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7fU 
                                                                     & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (__Vtemp_2[
                                                                   (3U 
                                                                    & (VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag);
    if ((1U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((QData)((IData)((0x100000U 
                                                  & ((~ (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)) 
                                                     << 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k1_T)))));
}

void Vfft512___024root___nba_sequent__TOP__0(Vfft512___024root* vlSelf);
void Vfft512___024root___nba_comb__TOP__0(Vfft512___024root* vlSelf);

void Vfft512___024root___eval_nba(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_nba\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfft512___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfft512___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

extern const VlWide<128>/*4095:0*/ Vfft512__ConstPool__CONST_h944bc563_0;
extern const VlWide<64>/*2047:0*/ Vfft512__ConstPool__CONST_h5478b25e_0;
extern const VlWide<32>/*1023:0*/ Vfft512__ConstPool__CONST_h35564355_0;
extern const VlWide<16>/*511:0*/ Vfft512__ConstPool__CONST_h0bfcbe7a_0;
extern const VlWide<8>/*255:0*/ Vfft512__ConstPool__CONST_h04042068_0;
extern const VlWide<256>/*8191:0*/ Vfft512__ConstPool__CONST_h15912bbd_0;

VL_INLINE_OPT void Vfft512___024root___nba_sequent__TOP__0(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___nba_sequent__TOP__0\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*9:0*/ __Vdly__FFT512_tb__DOT__uut__DOT__cnt;
    __Vdly__FFT512_tb__DOT__uut__DOT__cnt = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    // Body
    __Vdly__FFT512_tb__DOT__uut__DOT__cnt = vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out1_REG_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out2_REG_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out1_REG_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out2_REG_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_762_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_762_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_758_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_758_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_750_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_750_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_734_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_734_imag;
    if (vlSelfRef.FFT512_tb__DOT__reset) {
        __Vdly__FFT512_tb__DOT__uut__DOT__cnt = 0U;
    } else if (((IData)(vlSelfRef.FFT512_tb__DOT__io_in_valid) 
                | (0U != (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)))) {
        __Vdly__FFT512_tb__DOT__uut__DOT__cnt = ((0x2ffU 
                                                  == (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                                  ? 0U
                                                  : 
                                                 (0x3ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))));
    }
    vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out_valid_REG 
        = (0x1ffU == (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_702_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_702_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_638_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_638_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_254_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_254_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_510_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_510_imag;
    if ((1U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_imag;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_real;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_imag;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_real;
    }
    if ((2U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_762_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_762_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_762_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_762_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_imag;
    }
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_758_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_757_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_758_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_757_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_750_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_749_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_750_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_749_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_734_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_733_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_734_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_733_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_702_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_701_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_702_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_701_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_638_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_637_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_638_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_637_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_254_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_253_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_254_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_253_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_510_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_509_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_510_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_509_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_760_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_760_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_757_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_756_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_757_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_756_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_749_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_748_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_749_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_748_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_733_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_732_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_733_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_732_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_701_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_700_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_701_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_700_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_637_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_636_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_637_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_636_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_253_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_252_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_253_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_252_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_509_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_508_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_509_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_508_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_760_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_760_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    if ((4U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_756_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_756_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_756_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_756_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_imag;
    }
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_748_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_747_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_748_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_747_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_732_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_731_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_732_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_731_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_700_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_699_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_700_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_699_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_636_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_635_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_636_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_635_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_252_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_251_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_252_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_251_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_508_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_507_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_508_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_507_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_754_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_754_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_747_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_746_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_747_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_746_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_731_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_730_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_731_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_730_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_699_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_698_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_699_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_698_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_635_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_634_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_635_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_634_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_251_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_250_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_251_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_250_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_507_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_506_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_507_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_506_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_754_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_753_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_754_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_753_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_746_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_745_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_746_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_745_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_730_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_729_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_730_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_729_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_698_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_697_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_698_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_697_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_634_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_633_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_634_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_633_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_250_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_249_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_250_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_249_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_506_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_505_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_506_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_505_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_753_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_752_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_753_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_752_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_745_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_744_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_745_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_744_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_729_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_728_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_729_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_728_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_697_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_696_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_697_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_696_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_633_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_632_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_633_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_632_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_249_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_248_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_249_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_248_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_505_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_504_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_505_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_504_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_752_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_752_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    if ((8U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_744_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_744_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_744_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_744_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_imag;
    }
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_728_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_727_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_728_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_727_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_696_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_695_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_696_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_695_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_632_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_631_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_632_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_631_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_248_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_247_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_248_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_247_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_504_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_503_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_504_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_503_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_742_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_742_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_727_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_726_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_727_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_726_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_695_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_694_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_695_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_694_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_631_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_630_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_631_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_630_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_247_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_246_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_247_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_246_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_503_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_502_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_503_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_502_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_742_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_741_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_742_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_741_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_726_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_725_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_726_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_725_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_694_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_693_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_694_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_693_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_630_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_629_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_630_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_629_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_246_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_245_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_246_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_245_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_502_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_501_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_502_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_501_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_741_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_740_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_741_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_740_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_725_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_724_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_725_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_724_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_693_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_692_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_693_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_692_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_629_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_628_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_629_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_628_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_245_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_244_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_245_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_244_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_501_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_500_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_501_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_500_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_740_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_739_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_740_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_739_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_724_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_723_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_724_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_723_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_692_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_691_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_692_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_691_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_628_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_627_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_628_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_627_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_244_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_243_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_244_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_243_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_500_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_499_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_500_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_499_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_739_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_738_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_739_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_738_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_723_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_722_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_723_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_722_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_691_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_690_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_691_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_690_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_627_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_626_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_627_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_626_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_243_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_242_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_243_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_242_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_499_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_498_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_499_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_498_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_738_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_737_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_738_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_737_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_722_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_721_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_722_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_721_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_690_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_689_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_690_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_689_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_626_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_625_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_626_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_625_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_242_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_241_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_242_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_241_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_498_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_497_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_498_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_497_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_737_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_736_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_737_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_736_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_721_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_720_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_721_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_720_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_689_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_688_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_689_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_688_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_625_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_624_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_625_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_624_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_241_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_240_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_241_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_240_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_497_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_496_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_497_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_496_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_736_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_736_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    if ((0x10U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_720_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_720_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_720_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_720_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_imag;
    }
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_688_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_687_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_688_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_687_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_624_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_623_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_624_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_623_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_240_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_239_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_240_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_239_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_496_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_495_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_496_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_495_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_718_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_718_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_687_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_686_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_687_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_686_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_623_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_622_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_623_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_622_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_239_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_238_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_239_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_238_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_495_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_494_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_495_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_494_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_718_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_717_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_718_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_717_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_686_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_685_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_686_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_685_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_622_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_621_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_622_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_621_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_238_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_237_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_238_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_237_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_494_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_493_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_494_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_493_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_717_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_716_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_717_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_716_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_685_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_684_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_685_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_684_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_621_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_620_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_621_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_620_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_237_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_236_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_237_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_236_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_493_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_492_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_493_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_492_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_716_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_715_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_716_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_715_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_684_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_683_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_684_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_683_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_620_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_619_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_620_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_619_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_236_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_235_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_236_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_235_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_492_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_491_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_492_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_491_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_715_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_714_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_715_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_714_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_683_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_682_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_683_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_682_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_619_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_618_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_619_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_618_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_235_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_234_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_235_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_234_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_491_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_490_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_491_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_490_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_714_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_713_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_714_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_713_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_682_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_681_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_682_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_681_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_618_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_617_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_618_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_617_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_234_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_233_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_234_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_233_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_490_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_489_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_490_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_489_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_713_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_712_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_713_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_712_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_681_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_680_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_681_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_680_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_617_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_616_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_617_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_616_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_233_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_232_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_233_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_232_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_489_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_488_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_489_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_488_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_712_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_711_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_712_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_711_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_680_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_679_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_680_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_679_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_616_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_615_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_616_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_615_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_232_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_231_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_232_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_231_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_488_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_487_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_488_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_487_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_711_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_710_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_711_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_710_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_679_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_678_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_679_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_678_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_615_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_614_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_615_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_614_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_231_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_230_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_231_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_230_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_487_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_486_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_487_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_486_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_710_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_709_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_710_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_709_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_678_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_677_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_678_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_677_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_614_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_613_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_614_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_613_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_230_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_229_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_230_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_229_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_486_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_485_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_486_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_485_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_709_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_708_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_709_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_708_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_677_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_676_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_677_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_676_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_613_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_612_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_613_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_612_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_229_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_228_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_229_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_228_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_485_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_484_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_485_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_484_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_708_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_707_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_708_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_707_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_676_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_675_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_676_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_675_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_612_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_611_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_612_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_611_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_228_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_227_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_228_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_227_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_484_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_483_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_484_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_483_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_707_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_706_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_707_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_706_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_675_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_674_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_675_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_674_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_611_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_610_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_611_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_610_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_227_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_226_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_227_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_226_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_483_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_482_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_483_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_482_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_706_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_705_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_706_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_705_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_674_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_673_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_674_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_673_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_610_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_609_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_610_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_609_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_226_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_225_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_226_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_225_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_482_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_481_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_482_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_481_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_705_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_704_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_705_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_704_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_673_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_672_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_673_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_672_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_609_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_608_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_609_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_608_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_225_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_224_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_225_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_224_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_481_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_480_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_481_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_480_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_704_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_704_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    if ((0x20U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_672_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_672_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_672_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_672_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_imag;
    }
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_608_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_607_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_608_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_607_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_224_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_223_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_224_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_223_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_480_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_479_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_480_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_479_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_670_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_670_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_607_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_606_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_607_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_606_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_223_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_222_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_223_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_222_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_479_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_478_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_479_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_478_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_670_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_669_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_670_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_669_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_606_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_605_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_606_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_605_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_222_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_221_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_222_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_221_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_478_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_477_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_478_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_477_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_669_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_668_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_669_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_668_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_605_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_604_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_605_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_604_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_221_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_220_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_221_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_220_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_477_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_476_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_477_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_476_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_668_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_667_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_668_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_667_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_604_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_603_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_604_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_603_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_220_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_219_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_220_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_219_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_476_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_475_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_476_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_475_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_667_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_666_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_667_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_666_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_603_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_602_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_603_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_602_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_219_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_218_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_219_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_218_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_475_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_474_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_475_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_474_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_666_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_665_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_666_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_665_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_602_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_601_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_602_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_601_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_218_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_217_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_218_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_217_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_474_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_473_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_474_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_473_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_665_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_664_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_665_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_664_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_601_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_600_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_601_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_600_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_217_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_216_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_217_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_216_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_473_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_472_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_473_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_472_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_664_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_663_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_664_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_663_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_600_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_599_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_600_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_599_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_216_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_215_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_216_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_215_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_472_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_471_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_472_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_471_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_663_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_662_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_663_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_662_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_599_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_598_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_599_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_598_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_215_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_214_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_215_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_214_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_471_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_470_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_471_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_470_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_662_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_661_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_662_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_661_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_598_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_597_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_598_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_597_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_214_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_213_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_214_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_213_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_470_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_469_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_470_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_469_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_661_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_660_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_661_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_660_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_597_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_596_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_597_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_596_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_213_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_212_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_213_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_212_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_469_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_468_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_469_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_468_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_660_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_659_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_660_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_659_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_596_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_595_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_596_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_595_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_212_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_211_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_212_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_211_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_468_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_467_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_468_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_467_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_659_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_658_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_659_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_658_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_595_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_594_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_595_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_594_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_211_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_210_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_211_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_210_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_467_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_466_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_467_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_466_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_658_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_657_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_658_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_657_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_594_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_593_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_594_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_593_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_210_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_209_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_210_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_209_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_466_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_465_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_466_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_465_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_657_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_656_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_657_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_656_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_593_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_592_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_593_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_592_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_209_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_208_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_209_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_208_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_465_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_464_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_465_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_464_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_656_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_655_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_656_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_655_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_592_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_591_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_592_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_591_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_208_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_207_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_208_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_207_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_464_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_463_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_464_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_463_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_655_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_654_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_655_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_654_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_591_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_590_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_591_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_590_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_207_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_206_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_207_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_206_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_463_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_462_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_463_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_462_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_654_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_653_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_654_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_653_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_590_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_589_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_590_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_589_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_206_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_205_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_206_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_205_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_462_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_461_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_462_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_461_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_653_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_652_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_653_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_652_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_589_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_588_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_589_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_588_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_205_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_204_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_205_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_204_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_461_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_460_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_461_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_460_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_652_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_651_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_652_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_651_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_588_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_587_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_588_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_587_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_204_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_203_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_204_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_203_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_460_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_459_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_460_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_459_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_651_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_650_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_651_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_650_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_587_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_586_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_587_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_586_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_203_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_202_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_203_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_202_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_459_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_458_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_459_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_458_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_650_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_649_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_650_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_649_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_586_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_585_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_586_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_585_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_202_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_201_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_202_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_201_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_458_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_457_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_458_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_457_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_649_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_648_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_649_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_648_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_585_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_584_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_585_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_584_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_201_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_200_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_201_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_200_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_457_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_456_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_457_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_456_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_648_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_647_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_648_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_647_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_584_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_583_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_584_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_583_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_200_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_199_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_200_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_199_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_456_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_455_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_456_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_455_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_647_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_646_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_647_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_646_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_583_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_582_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_583_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_582_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_199_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_198_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_199_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_198_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_455_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_454_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_455_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_454_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_646_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_645_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_646_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_645_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_582_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_581_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_582_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_581_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_198_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_197_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_198_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_197_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_454_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_453_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_454_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_453_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_645_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_644_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_645_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_644_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_581_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_580_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_581_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_580_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_197_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_196_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_197_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_196_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_453_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_452_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_453_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_452_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_644_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_643_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_644_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_643_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_580_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_579_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_580_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_579_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_196_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_195_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_196_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_195_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_452_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_451_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_452_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_451_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_643_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_642_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_643_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_642_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_579_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_578_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_579_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_578_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_195_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_194_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_195_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_194_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_451_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_450_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_451_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_450_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_642_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_641_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_642_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_641_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_578_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_577_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_578_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_577_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_194_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_193_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_194_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_193_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_450_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_449_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_450_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_449_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_641_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_640_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_641_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_640_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_577_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_576_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_577_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_576_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_193_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_192_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_193_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_192_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_449_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_448_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_449_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_448_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_640_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_640_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    if ((0x40U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_576_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_576_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_576_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_576_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_imag;
    }
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_192_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_191_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_192_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_191_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_448_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_447_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_448_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_447_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_574_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_574_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_191_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_190_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_191_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_190_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_447_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_446_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_447_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_446_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_574_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_573_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_574_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_573_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_190_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_189_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_190_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_189_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_446_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_445_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_446_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_445_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_573_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_572_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_573_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_572_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_189_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_188_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_189_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_188_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_445_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_444_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_445_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_444_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_572_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_571_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_572_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_571_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_188_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_187_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_188_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_187_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_444_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_443_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_444_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_443_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_571_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_570_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_571_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_570_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_187_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_186_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_187_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_186_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_443_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_442_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_443_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_442_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_570_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_569_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_570_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_569_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_186_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_185_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_186_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_185_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_442_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_441_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_442_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_441_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_569_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_568_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_569_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_568_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_185_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_184_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_185_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_184_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_441_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_440_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_441_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_440_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_568_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_567_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_568_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_567_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_184_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_183_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_184_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_183_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_440_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_439_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_440_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_439_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_567_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_566_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_567_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_566_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_183_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_182_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_183_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_182_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_439_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_438_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_439_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_438_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_566_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_565_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_566_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_565_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_182_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_181_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_182_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_181_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_438_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_437_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_438_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_437_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_565_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_564_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_565_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_564_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_181_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_180_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_181_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_180_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_437_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_436_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_437_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_436_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_564_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_563_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_564_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_563_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_180_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_179_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_180_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_179_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_436_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_435_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_436_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_435_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_563_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_562_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_563_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_562_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_179_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_178_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_179_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_178_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_435_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_434_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_435_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_434_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_562_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_561_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_562_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_561_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_178_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_177_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_178_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_177_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_434_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_433_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_434_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_433_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_561_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_560_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_561_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_560_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_177_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_176_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_177_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_176_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_433_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_432_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_433_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_432_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_560_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_559_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_560_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_559_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_176_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_175_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_176_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_175_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_432_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_431_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_432_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_431_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_559_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_558_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_559_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_558_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_175_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_174_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_175_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_174_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_431_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_430_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_431_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_430_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_558_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_557_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_558_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_557_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_174_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_173_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_174_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_173_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_430_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_429_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_430_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_429_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_557_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_556_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_557_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_556_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_173_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_172_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_173_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_172_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_429_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_428_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_429_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_428_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_556_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_555_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_556_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_555_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_172_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_171_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_172_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_171_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_428_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_427_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_428_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_427_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_555_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_554_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_555_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_554_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_171_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_170_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_171_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_170_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_427_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_426_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_427_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_426_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_554_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_553_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_554_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_553_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_170_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_169_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_170_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_169_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_426_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_425_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_426_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_425_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_553_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_552_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_553_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_552_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_169_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_168_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_169_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_168_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_425_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_424_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_425_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_424_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_552_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_551_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_552_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_551_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_168_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_167_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_168_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_167_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_424_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_423_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_424_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_423_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_551_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_550_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_551_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_550_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_167_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_166_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_167_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_166_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_423_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_422_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_423_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_422_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_550_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_549_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_550_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_549_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_166_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_165_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_166_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_165_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_422_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_421_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_422_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_421_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_549_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_548_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_549_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_548_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_165_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_164_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_165_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_164_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_421_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_420_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_421_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_420_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_548_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_547_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_548_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_547_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_164_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_163_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_164_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_163_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_420_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_419_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_420_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_419_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_547_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_546_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_547_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_546_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_163_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_162_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_163_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_162_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_419_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_418_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_419_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_418_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_546_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_545_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_546_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_545_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_162_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_161_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_162_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_161_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_418_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_417_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_418_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_417_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_545_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_544_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_545_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_544_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_161_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_160_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_161_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_160_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_417_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_416_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_417_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_416_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_544_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_543_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_544_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_543_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_160_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_159_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_160_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_159_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_416_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_415_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_416_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_415_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_543_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_542_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_543_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_542_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_159_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_158_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_159_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_158_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_415_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_414_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_415_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_414_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_542_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_541_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_542_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_541_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_158_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_157_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_158_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_157_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_414_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_413_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_414_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_413_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_541_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_540_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_541_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_540_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_157_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_156_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_157_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_156_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_413_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_412_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_413_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_412_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_540_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_539_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_540_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_539_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_156_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_155_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_156_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_155_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_412_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_411_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_412_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_411_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_539_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_538_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_539_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_538_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_155_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_154_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_155_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_154_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_411_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_410_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_411_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_410_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_538_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_537_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_538_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_537_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_154_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_153_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_154_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_153_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_410_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_409_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_410_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_409_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_537_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_536_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_537_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_536_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_153_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_152_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_153_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_152_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_409_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_408_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_409_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_408_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_536_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_535_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_536_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_535_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_152_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_151_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_152_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_151_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_408_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_407_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_408_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_407_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_535_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_534_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_535_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_534_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_151_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_150_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_151_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_150_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_407_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_406_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_407_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_406_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_534_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_533_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_534_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_533_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_150_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_149_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_150_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_149_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_406_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_405_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_406_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_405_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_533_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_532_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_533_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_532_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_149_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_148_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_149_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_148_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_405_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_404_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_405_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_404_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_532_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_531_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_532_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_531_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_148_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_147_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_148_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_147_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_404_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_403_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_404_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_403_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_531_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_530_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_531_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_530_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_147_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_146_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_147_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_146_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_403_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_402_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_403_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_402_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_530_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_529_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_530_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_529_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_146_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_145_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_146_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_145_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_402_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_401_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_402_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_401_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_529_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_528_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_529_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_528_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_145_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_144_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_145_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_144_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_401_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_400_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_401_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_400_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_528_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_527_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_528_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_527_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_144_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_143_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_144_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_143_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_400_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_399_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_400_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_399_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_527_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_526_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_527_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_526_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_143_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_142_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_143_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_142_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_399_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_398_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_399_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_398_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_526_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_525_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_526_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_525_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_142_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_141_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_142_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_141_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_398_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_397_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_398_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_397_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_525_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_524_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_525_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_524_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_141_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_140_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_141_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_140_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_397_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_396_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_397_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_396_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_524_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_523_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_524_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_523_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_140_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_139_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_140_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_139_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_396_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_395_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_396_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_395_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_523_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_522_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_523_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_522_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_139_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_138_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_139_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_138_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_395_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_394_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_395_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_394_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_522_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_521_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_522_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_521_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_138_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_137_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_138_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_137_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_394_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_393_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_394_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_393_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_521_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_520_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_521_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_520_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_137_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_136_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_137_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_136_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_393_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_392_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_393_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_392_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_520_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_519_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_520_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_519_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_136_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_135_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_136_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_135_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_392_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_391_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_392_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_391_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_519_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_518_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_519_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_518_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_135_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_134_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_135_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_134_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_391_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_390_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_391_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_390_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_518_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_517_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_518_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_517_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_134_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_133_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_134_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_133_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_390_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_389_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_390_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_389_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_517_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_516_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_517_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_516_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_133_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_132_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_133_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_132_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_389_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_388_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_389_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_388_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_516_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_515_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_516_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_515_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_132_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_131_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_132_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_131_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_388_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_387_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_388_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_387_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_515_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_514_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_515_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_514_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_131_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_130_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_131_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_130_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_387_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_386_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_387_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_386_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_514_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_513_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_514_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_513_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_130_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_129_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_130_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_129_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_386_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_385_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_386_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_385_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_513_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_512_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_513_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_512_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_129_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_128_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_129_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_128_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_385_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_384_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_385_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_384_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_512_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_512_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_128_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_127_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_128_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_127_imag;
    if ((0x80U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_384_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_384_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_384_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT__r_384_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_imag;
    }
    vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt = __Vdly__FFT512_tb__DOT__uut__DOT__cnt;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_127_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_126_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_127_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_126_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_382_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(12,12,32, 
                                           (0x7fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h944bc563_0[
                      (((IData)(0x1fU) + (0xfffU & 
                                          VL_SHIFTL_III(12,12,32, 
                                                        (0x7fU 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                          (0x7fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h944bc563_0[
               (0x7fU & (VL_SHIFTL_III(12,12,32, (0x7fU 
                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                            (0x7fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(12,12,32, 
                                             (0x7fU 
                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_hf3784b49_0[
                        (((IData)(0x1fU) + (0xfffU 
                                            & VL_SHIFTL_III(12,12,32, 
                                                            (0x7fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_hf3784b49_0[
                 (0x7fU & (VL_SHIFTL_III(12,12,32, 
                                         (0x7fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(12,12,32, 
                                           (0x7fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h944bc563_0[
                      (((IData)(0x1fU) + (0xfffU & 
                                          VL_SHIFTL_III(12,12,32, 
                                                        (0x7fU 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                          (0x7fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h944bc563_0[
               (0x7fU & (VL_SHIFTL_III(12,12,32, (0x7fU 
                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                            (0x7fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(12,12,32, 
                                             (0x7fU 
                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_hf3784b49_0[
                        (((IData)(0x1fU) + (0xfffU 
                                            & VL_SHIFTL_III(12,12,32, 
                                                            (0x7fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_hf3784b49_0[
                 (0x7fU & (VL_SHIFTL_III(12,12,32, 
                                         (0x7fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                           (0x3fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h5478b25e_0[
                      (((IData)(0x1fU) + (0x7ffU & 
                                          VL_SHIFTL_III(11,11,32, 
                                                        (0x3fU 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h5478b25e_0[
               (0x3fU & (VL_SHIFTL_III(11,11,32, (0x3fU 
                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                             (0x3fU 
                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_h8abd5580_0[
                        (((IData)(0x1fU) + (0x7ffU 
                                            & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_h8abd5580_0[
                 (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                         (0x3fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                           (0x3fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h5478b25e_0[
                      (((IData)(0x1fU) + (0x7ffU & 
                                          VL_SHIFTL_III(11,11,32, 
                                                        (0x3fU 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h5478b25e_0[
               (0x3fU & (VL_SHIFTL_III(11,11,32, (0x3fU 
                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                             (0x3fU 
                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_h8abd5580_0[
                        (((IData)(0x1fU) + (0x7ffU 
                                            & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_h8abd5580_0[
                 (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                         (0x3fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                           (0x1fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h35564355_0[
                      (((IData)(0x1fU) + (0x3ffU & 
                                          VL_SHIFTL_III(10,10,32, 
                                                        (0x1fU 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h35564355_0[
               (0x1fU & (VL_SHIFTL_III(10,10,32, (0x1fU 
                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                             (0x1fU 
                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_hb3c963b9_0[
                        (((IData)(0x1fU) + (0x3ffU 
                                            & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_hb3c963b9_0[
                 (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                         (0x1fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                           (0x1fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h35564355_0[
                      (((IData)(0x1fU) + (0x3ffU & 
                                          VL_SHIFTL_III(10,10,32, 
                                                        (0x1fU 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h35564355_0[
               (0x1fU & (VL_SHIFTL_III(10,10,32, (0x1fU 
                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                             (0x1fU 
                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_hb3c963b9_0[
                        (((IData)(0x1fU) + (0x3ffU 
                                            & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_hb3c963b9_0[
                 (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                         (0x1fU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                           (0xfU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h0bfcbe7a_0[
                      (((IData)(0x1fU) + (0x1ffU & 
                                          VL_SHIFTL_III(9,9,32, 
                                                        (0xfU 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h0bfcbe7a_0[
               (0xfU & (VL_SHIFTL_III(9,9,32, (0xfU 
                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                        >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                           (0xfU 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                             (0xfU 
                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_h942db0a5_0[
                        (((IData)(0x1fU) + (0x1ffU 
                                            & VL_SHIFTL_III(9,9,32, 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_h942db0a5_0[
                 (0xfU & (VL_SHIFTL_III(9,9,32, (0xfU 
                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                          >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                           (0xfU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h0bfcbe7a_0[
                      (((IData)(0x1fU) + (0x1ffU & 
                                          VL_SHIFTL_III(9,9,32, 
                                                        (0xfU 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h0bfcbe7a_0[
               (0xfU & (VL_SHIFTL_III(9,9,32, (0xfU 
                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                        >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                           (0xfU 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                             (0xfU 
                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_h942db0a5_0[
                        (((IData)(0x1fU) + (0x1ffU 
                                            & VL_SHIFTL_III(9,9,32, 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_h942db0a5_0[
                 (0xfU & (VL_SHIFTL_III(9,9,32, (0xfU 
                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                          >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                           (7U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h04042068_0[
                      (((IData)(0x1fU) + (0xffU & VL_SHIFTL_III(8,8,32, 
                                                                (7U 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h04042068_0[
               (7U & (VL_SHIFTL_III(8,8,32, (7U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                      >> 5U))] >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                         (7U 
                                                          & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                             (7U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_hfd15effc_0[
                        (((IData)(0x1fU) + (0xffU & 
                                            VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                              (7U 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_hfd15effc_0[
                 (7U & (VL_SHIFTL_III(8,8,32, (7U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                        >> 5U))] >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                           (7U 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                           (7U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h04042068_0[
                      (((IData)(0x1fU) + (0xffU & VL_SHIFTL_III(8,8,32, 
                                                                (7U 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h04042068_0[
               (7U & (VL_SHIFTL_III(8,8,32, (7U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                      >> 5U))] >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                         (7U 
                                                          & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                             (7U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_hfd15effc_0[
                        (((IData)(0x1fU) + (0xffU & 
                                            VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                              (7U 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_hfd15effc_0[
                 (7U & (VL_SHIFTL_III(8,8,32, (7U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                        >> 5U))] >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                           (7U 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    __Vtemp_1[0U] = 0U;
    __Vtemp_1[1U] = 0xb504fU;
    __Vtemp_1[2U] = 0x100000U;
    __Vtemp_1[3U] = 0xb504fU;
    __Vtemp_2[0U] = 0x100000U;
    __Vtemp_2[1U] = 0xb504fU;
    __Vtemp_2[2U] = 0U;
    __Vtemp_2[3U] = 0xfff4afb1U;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                           (3U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (__Vtemp_1[(((IData)(0x1fU) + 
                                  (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                 >> 5U)] << ((IData)(0x20U) 
                                             - (0x1fU 
                                                & VL_SHIFTL_III(7,7,32, 
                                                                (3U 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (__Vtemp_1[(3U & (VL_SHIFTL_III(7,7,32, 
                                              (3U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                >> 5U))] >> (0x1fU 
                                             & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                             (3U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (__Vtemp_2[(((IData)(0x1fU) 
                                    + (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (__Vtemp_2[(3U & (VL_SHIFTL_III(7,7,32, 
                                                (3U 
                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                  >> 5U))] >> (0x1fU 
                                               & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0xb504fU;
    __Vtemp_3[2U] = 0x100000U;
    __Vtemp_3[3U] = 0xb504fU;
    __Vtemp_4[0U] = 0x100000U;
    __Vtemp_4[1U] = 0xb504fU;
    __Vtemp_4[2U] = 0U;
    __Vtemp_4[3U] = 0xfff4afb1U;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                           (3U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (__Vtemp_3[(((IData)(0x1fU) + 
                                  (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                 >> 5U)] << ((IData)(0x20U) 
                                             - (0x1fU 
                                                & VL_SHIFTL_III(7,7,32, 
                                                                (3U 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (__Vtemp_3[(3U & (VL_SHIFTL_III(7,7,32, 
                                              (3U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                >> 5U))] >> (0x1fU 
                                             & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                             (3U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (__Vtemp_4[(((IData)(0x1fU) 
                                    + (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (__Vtemp_4[(3U & (VL_SHIFTL_III(7,7,32, 
                                                (3U 
                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                  >> 5U))] >> (0x1fU 
                                               & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k2_T 
        = ((0x100000U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                         << 0x14U)) - (0x100000U & 
                                       ((~ (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)) 
                                        << 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k3_T 
        = ((0x100000U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                         << 0x14U)) + (0x100000U & 
                                       ((~ (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)) 
                                        << 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_382_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_126_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_125_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_126_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_125_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_382_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_381_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_382_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_381_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_125_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_124_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_125_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_124_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_381_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_380_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_381_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_380_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_124_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_123_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_124_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_123_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_380_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_379_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_380_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_379_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_123_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_122_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_123_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_122_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_379_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_378_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_379_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_378_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_122_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_121_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_122_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_121_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_378_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_377_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_378_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_377_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_121_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_120_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_121_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_120_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_377_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_376_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_377_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_376_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_120_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_119_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_120_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_119_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_376_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_375_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_376_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_375_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_119_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_118_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_119_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_118_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_375_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_374_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_375_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_374_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_118_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_117_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_118_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_117_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_374_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_373_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_374_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_373_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_117_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_116_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_117_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_116_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_373_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_372_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_373_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_372_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_116_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_115_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_116_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_115_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_372_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_371_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_372_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_371_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_115_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_114_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_115_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_114_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_371_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_370_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_371_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_370_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_114_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_113_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_114_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_113_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_370_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_369_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_370_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_369_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_113_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_112_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_113_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_112_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_369_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_368_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_369_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_368_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_112_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_111_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_112_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_111_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_368_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_367_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_368_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_367_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_111_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_110_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_111_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_110_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_367_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_366_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_367_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_366_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_110_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_109_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_110_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_109_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_366_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_365_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_366_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_365_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_109_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_108_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_109_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_108_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_365_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_364_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_365_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_364_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_108_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_107_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_108_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_107_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_364_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_363_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_364_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_363_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_107_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_106_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_107_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_106_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_363_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_362_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_363_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_362_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_106_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_105_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_106_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_105_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_362_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_361_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_362_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_361_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_105_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_104_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_105_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_104_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_361_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_360_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_361_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_360_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_104_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_103_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_104_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_103_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_360_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_359_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_360_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_359_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_103_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_102_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_103_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_102_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_359_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_358_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_359_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_358_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_102_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_101_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_102_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_101_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_358_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_357_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_358_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_357_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_101_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_100_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_101_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_100_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_357_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_356_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_357_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_356_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_100_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_99_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_100_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_99_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_356_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_355_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_356_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_355_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_99_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_98_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_99_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_98_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_355_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_354_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_355_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_354_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_98_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_97_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_98_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_97_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_354_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_353_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_354_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_353_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_97_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_96_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_97_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_96_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_353_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_352_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_353_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_352_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_96_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_95_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_96_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_95_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_352_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_351_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_352_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_351_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_95_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_94_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_95_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_94_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_351_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_350_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_351_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_350_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_94_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_93_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_94_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_93_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_350_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_349_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_350_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_349_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_93_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_92_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_93_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_92_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_349_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_348_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_349_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_348_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_92_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_91_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_92_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_91_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_348_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_347_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_348_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_347_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_91_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_90_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_91_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_90_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_347_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_346_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_347_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_346_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_90_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_89_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_90_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_89_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_346_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_345_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_346_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_345_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_89_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_88_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_89_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_88_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_345_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_344_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_345_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_344_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_88_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_87_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_88_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_87_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_344_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_343_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_344_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_343_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_87_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_86_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_87_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_86_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_343_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_342_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_343_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_342_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_86_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_85_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_86_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_85_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_342_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_341_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_342_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_341_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_85_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_84_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_85_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_84_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_341_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_340_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_341_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_340_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_84_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_83_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_84_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_83_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_340_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_339_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_340_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_339_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_83_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_82_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_83_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_82_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_339_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_338_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_339_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_338_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_82_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_81_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_82_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_81_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_338_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_337_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_338_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_337_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_81_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_80_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_81_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_80_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_337_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_336_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_337_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_336_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_80_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_79_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_80_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_79_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_336_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_335_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_336_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_335_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_79_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_78_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_79_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_78_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_335_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_334_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_335_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_334_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_78_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_77_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_78_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_77_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_334_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_333_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_334_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_333_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_77_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_76_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_77_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_76_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_333_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_332_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_333_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_332_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_76_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_75_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_76_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_75_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_332_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_331_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_332_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_331_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_75_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_74_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_75_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_74_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_331_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_330_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_331_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_330_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_74_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_73_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_74_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_73_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_330_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_329_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_330_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_329_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_73_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_72_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_73_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_72_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_329_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_328_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_329_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_328_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_72_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_71_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_72_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_71_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_328_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_327_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_328_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_327_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_71_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_70_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_71_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_70_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_327_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_326_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_327_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_326_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_70_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_69_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_70_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_69_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_326_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_325_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_326_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_325_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_69_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_68_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_69_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_68_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_325_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_324_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_325_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_324_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_68_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_67_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_68_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_67_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_324_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_323_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_324_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_323_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_67_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_66_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_67_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_66_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_323_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_322_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_323_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_322_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_66_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_65_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_66_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_65_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_322_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_321_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_322_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_321_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_65_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_64_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_65_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_64_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_321_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_320_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_321_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_320_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_64_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_63_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_64_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_63_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_320_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_319_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_320_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_319_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_63_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_62_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_63_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_62_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_319_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_318_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_319_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_318_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_62_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_61_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_62_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_61_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_318_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_317_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_318_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_317_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_61_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_60_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_61_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_60_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_317_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_316_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_317_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_316_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_60_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_59_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_60_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_59_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_316_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_315_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_316_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_315_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_59_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_58_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_59_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_58_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_315_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_314_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_315_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_314_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_58_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_57_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_58_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_57_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_314_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_313_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_314_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_313_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_57_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_56_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_57_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_56_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_313_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_312_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_313_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_312_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_56_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_55_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_56_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_55_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_312_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_311_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_312_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_311_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_55_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_54_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_55_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_54_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_311_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_310_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_311_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_310_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_54_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_53_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_54_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_53_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_310_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_309_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_310_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_309_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_53_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_52_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_53_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_52_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_309_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_308_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_309_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_308_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_52_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_51_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_52_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_51_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_308_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_307_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_308_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_307_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_51_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_50_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_51_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_50_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_307_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_306_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_307_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_306_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_50_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_49_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_50_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_49_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_306_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_305_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_306_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_305_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_49_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_48_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_49_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_48_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_305_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_304_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_305_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_304_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_48_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_47_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_48_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_47_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_304_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_303_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_304_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_303_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_47_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_46_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_47_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_46_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_303_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_302_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_303_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_302_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_46_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_45_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_46_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_45_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_302_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_301_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_302_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_301_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_45_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_44_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_45_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_44_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_301_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_300_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_301_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_300_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_44_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_43_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_44_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_43_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_300_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_299_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_300_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_299_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_43_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_42_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_43_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_42_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_299_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_298_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_299_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_298_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_42_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_41_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_42_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_41_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_298_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_297_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_298_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_297_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_41_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_40_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_41_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_40_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_297_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_296_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_297_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_296_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_40_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_39_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_40_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_39_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_296_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_295_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_296_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_295_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_39_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_38_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_39_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_38_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_295_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_294_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_295_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_294_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_38_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_37_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_38_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_37_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_294_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_293_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_294_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_293_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_37_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_36_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_37_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_36_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_293_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_292_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_293_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_292_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_36_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_35_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_36_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_35_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_292_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_291_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_292_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_291_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_35_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_34_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_35_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_34_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_291_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_290_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_291_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_290_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_34_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_33_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_34_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_33_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_290_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_289_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_290_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_289_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_33_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_32_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_33_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_32_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_289_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_288_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_289_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_288_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_32_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_31_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_32_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_31_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_288_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_287_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_288_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_287_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_31_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_30_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_31_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_30_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_287_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_286_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_287_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_286_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_30_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_29_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_30_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_29_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_286_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_285_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_286_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_285_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_29_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_28_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_29_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_28_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_285_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_284_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_285_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_284_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_28_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_27_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_28_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_27_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_284_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_283_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_284_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_283_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_27_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_26_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_27_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_26_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_283_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_282_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_283_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_282_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_26_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_25_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_26_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_25_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_282_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_281_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_282_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_281_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_25_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_24_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_25_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_24_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_281_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_280_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_281_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_280_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_24_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_23_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_24_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_23_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_280_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_279_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_280_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_279_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_23_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_22_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_23_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_22_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_279_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_278_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_279_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_278_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_22_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_21_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_22_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_21_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_278_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_277_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_278_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_277_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_21_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_20_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_21_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_20_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_277_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_276_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_277_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_276_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_20_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_19_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_20_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_19_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_276_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_275_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_276_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_275_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_19_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_18_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_19_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_18_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_275_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_274_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_275_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_274_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_18_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_17_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_18_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_17_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_274_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_273_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_274_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_273_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_17_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_16_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_17_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_16_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_273_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_272_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_273_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_272_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_16_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_15_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_16_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_15_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_272_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_271_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_272_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_271_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_15_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_14_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_15_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_14_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_271_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_270_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_271_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_270_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_14_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_13_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_14_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_13_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_270_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_269_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_270_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_269_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_13_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_12_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_13_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_12_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_269_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_268_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_269_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_268_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_12_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_11_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_12_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_11_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_268_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_267_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_268_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_267_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_11_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_10_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_11_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_10_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_267_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_266_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_267_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_266_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_10_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_9_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_10_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_9_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_266_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_265_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_266_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_265_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_9_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_8_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_9_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_8_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_265_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_264_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_265_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_264_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_8_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_7_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_8_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_7_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_264_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_263_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_264_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_263_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_7_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_6_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_7_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_6_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_263_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_262_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_263_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_262_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_6_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_5_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_6_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_5_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_262_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_261_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_262_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_261_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_5_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_4_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_5_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_4_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_261_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_260_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_261_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_260_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_4_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_3_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_4_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_3_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_260_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_259_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_260_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_259_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_3_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_2_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_3_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_2_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_259_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_258_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_259_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_258_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_2_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_1_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_2_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_1_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_258_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_257_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_258_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_257_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_1_real = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_1_imag = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_257_real 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_256_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_257_imag 
        = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_256_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_real = vlSelfRef.FFT512_tb__DOT__io_in_real;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_imag = vlSelfRef.FFT512_tb__DOT__io_in_imag;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_256_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__r_256_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                           (0xffU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h15912bbd_0[
                      (((IData)(0x1fU) + (0x1fffU & 
                                          VL_SHIFTL_III(13,13,32, 
                                                        (0xffU 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                          (0xffU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h15912bbd_0[
               (0xffU & (VL_SHIFTL_III(13,13,32, (0xffU 
                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                             (0xffU 
                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_h010c7fca_0[
                        (((IData)(0x1fU) + (0x1fffU 
                                            & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                              (0xffU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_h010c7fca_0[
                 (0xffU & (VL_SHIFTL_III(13,13,32, 
                                         (0xffU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                              (0xffU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                           (0xffU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft512__ConstPool__CONST_h15912bbd_0[
                      (((IData)(0x1fU) + (0x1fffU & 
                                          VL_SHIFTL_III(13,13,32, 
                                                        (0xffU 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                          (0xffU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft512__ConstPool__CONST_h15912bbd_0[
               (0xffU & (VL_SHIFTL_III(13,13,32, (0xffU 
                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))) 
           - (((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                             (0xffU 
                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft512__ConstPool__CONST_h010c7fca_0[
                        (((IData)(0x1fU) + (0x1fffU 
                                            & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                              (0xffU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft512__ConstPool__CONST_h010c7fca_0[
                 (0xffU & (VL_SHIFTL_III(13,13,32, 
                                         (0xffU & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                              (0xffU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))));
}

VL_INLINE_OPT void Vfft512___024root___nba_comb__TOP__0(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___nba_comb__TOP__0\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k1_T;
    FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k1_T = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__io_in_real + vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__io_in_imag + vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_imag 
           - vlSelfRef.FFT512_tb__DOT__io_in_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_real 
           - vlSelfRef.FFT512_tb__DOT__io_in_real);
    if ((0x80U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_imag;
    }
    FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_h010c7fca_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x1fffU 
                                                                        & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x1fffU 
                                                                          & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_h010c7fca_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1fffU 
                                                                     & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_h010c7fca_0[
                                                                   (0xffU 
                                                                    & (VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T)))));
    if ((0x40U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_hf3784b49_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xfffU 
                                                                        & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0xfffU 
                                                                          & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_hf3784b49_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0xfffU 
                                                                     & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_hf3784b49_0[
                                                                   (0x7fU 
                                                                    & (VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(12,12,32, 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    if ((0x20U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_h8abd5580_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7ffU 
                                                                        & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x7ffU 
                                                                          & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_h8abd5580_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7ffU 
                                                                     & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_h8abd5580_0[
                                                                   (0x3fU 
                                                                    & (VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    if ((0x10U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_hb3c963b9_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x3ffU 
                                                                        & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x3ffU 
                                                                          & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_hb3c963b9_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x3ffU 
                                                                     & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_hb3c963b9_0[
                                                                   (0x1fU 
                                                                    & (VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    if ((8U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_h942db0a5_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x1ffU 
                                                                        & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x1ffU 
                                                                          & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_h942db0a5_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_h942db0a5_0[
                                                                   (0xfU 
                                                                    & (VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    if ((4U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (Vfft512__ConstPool__CONST_hfd15effc_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xffU 
                                                                        & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0xffU 
                                                                          & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (Vfft512__ConstPool__CONST_hfd15effc_0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0xffU 
                                                                     & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (Vfft512__ConstPool__CONST_hfd15effc_0[
                                                                   (7U 
                                                                    & (VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag);
    if ((2U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_real 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_real 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_real 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real);
    __Vtemp_1[0U] = 0x100000U;
    __Vtemp_1[1U] = 0xb504fU;
    __Vtemp_1[2U] = 0U;
    __Vtemp_1[3U] = 0xfff4afb1U;
    __Vtemp_2[0U] = 0x100000U;
    __Vtemp_2[1U] = 0xb504fU;
    __Vtemp_2[2U] = 0U;
    __Vtemp_2[3U] = 0xfff4afb1U;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
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
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(0x1fU) 
                                                                         + 
                                                                         (0x7fU 
                                                                          & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (((0U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                  ? 0U
                                                                  : 
                                                                 (__Vtemp_2[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7fU 
                                                                     & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                   >> 5U)] 
                                                                  << 
                                                                  ((IData)(0x20U) 
                                                                   - 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                | (__Vtemp_2[
                                                                   (3U 
                                                                    & (VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                       >> 5U))] 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_imag 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_imag 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_imag 
           - vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag);
    if ((1U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_imag;
    } else {
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_real 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_real;
        vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_imag 
            = vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_imag;
    }
    FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((QData)((IData)((0x100000U 
                                                  & ((~ (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)) 
                                                     << 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k1_T)))));
}

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
