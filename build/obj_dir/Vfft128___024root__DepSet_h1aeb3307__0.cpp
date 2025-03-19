// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft128.h for the primary calling header

#include "Vfft128__pch.h"
#include "Vfft128___024root.h"

VlCoroutine Vfft128___024root___eval_initial__TOP__Vtiming__0(Vfft128___024root* vlSelf);
VlCoroutine Vfft128___024root___eval_initial__TOP__Vtiming__1(Vfft128___024root* vlSelf);

void Vfft128___024root___eval_initial(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_initial\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vfft128___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vfft128___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__FFT128_tb__DOT__clock__0 
        = vlSelfRef.FFT128_tb__DOT__clock;
}

VL_INLINE_OPT VlCoroutine Vfft128___024root___eval_initial__TOP__Vtiming__1(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "fft128_tb.sv", 
                                             30);
        vlSelfRef.FFT128_tb__DOT__clock = (1U & (~ (IData)(vlSelfRef.FFT128_tb__DOT__clock)));
    }
}

void Vfft128___024root___act_sequent__TOP__0(Vfft128___024root* vlSelf);

void Vfft128___024root___eval_act(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_act\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vfft128___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

extern const VlWide<64>/*2047:0*/ Vfft128__ConstPool__CONST_h8abd5580_0;
extern const VlWide<64>/*2047:0*/ Vfft128__ConstPool__CONST_h16a5c00c_0;
extern const VlWide<32>/*1023:0*/ Vfft128__ConstPool__CONST_hb3c963b9_0;
extern const VlWide<32>/*1023:0*/ Vfft128__ConstPool__CONST_hffb3c89b_0;
extern const VlWide<16>/*511:0*/ Vfft128__ConstPool__CONST_h942db0a5_0;
extern const VlWide<16>/*511:0*/ Vfft128__ConstPool__CONST_ha2844606_0;
extern const VlWide<8>/*255:0*/ Vfft128__ConstPool__CONST_hfd15effc_0;
extern const VlWide<8>/*255:0*/ Vfft128__ConstPool__CONST_h5ba1edbd_0;

VL_INLINE_OPT void Vfft128___024root___act_sequent__TOP__0(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___act_sequent__TOP__0\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k2_T;
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k2_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k3_T;
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k3_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k2_T;
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k2_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k3_T;
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k3_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k2_T;
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k2_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k3_T;
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k3_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k3_T;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k3_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k2_T;
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k2_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k3_T;
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k3_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    // Body
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_real 
           - vlSelfRef.FFT128_tb__DOT__io_in_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_imag 
           - vlSelfRef.FFT128_tb__DOT__io_in_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k2_T 
        = (vlSelfRef.FFT128_tb__DOT__io_in_imag - vlSelfRef.FFT128_tb__DOT__io_in_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k3_T 
        = (vlSelfRef.FFT128_tb__DOT__io_in_imag + vlSelfRef.FFT128_tb__DOT__io_in_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__io_in_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__io_in_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__io_in_imag + vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__io_in_real + vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_real);
    FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T);
    FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__tmp_k1 
                                 + ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_h8abd5580_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x7ffU 
                                                                           & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x7ffU 
                                                                             & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_h8abd5580_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7ffU 
                                                                        & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_h8abd5580_0[
                                                                      (0x3fU 
                                                                       & (VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k2_T))))));
    FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_h16a5c00c_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x7ffU 
                                                                           & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x7ffU 
                                                                             & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_h16a5c00c_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7ffU 
                                                                        & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_h16a5c00c_0[
                                                                      (0x3fU 
                                                                       & (VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k3_T))))));
    if ((0x20U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_real;
    }
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k2_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag 
         - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k3_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag 
         + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real);
    if ((0x10U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_real;
    }
    FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T);
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__tmp_k1 
                                 + ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_hb3c963b9_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x3ffU 
                                                                           & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x3ffU 
                                                                             & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_hb3c963b9_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x3ffU 
                                                                        & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_hb3c963b9_0[
                                                                      (0x1fU 
                                                                       & (VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k2_T))))));
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_hffb3c89b_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x3ffU 
                                                                           & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x3ffU 
                                                                             & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_hffb3c89b_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x3ffU 
                                                                        & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_hffb3c89b_0[
                                                                      (0x1fU 
                                                                       & (VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k3_T))))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k2_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
         - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k3_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
         + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    if ((8U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_real;
    }
    FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T);
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__tmp_k1 
                                 + ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_h942db0a5_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x1ffU 
                                                                           & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x1ffU 
                                                                             & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_h942db0a5_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x1ffU 
                                                                        & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_h942db0a5_0[
                                                                      (0xfU 
                                                                       & (VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k2_T))))));
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_ha2844606_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x1ffU 
                                                                           & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x1ffU 
                                                                             & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_ha2844606_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x1ffU 
                                                                        & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_ha2844606_0[
                                                                      (0xfU 
                                                                       & (VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k3_T))))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k2_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
         - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k3_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
         + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    if ((4U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_real;
    }
    FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T);
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__tmp_k1 
                                 + ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_hfd15effc_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0xffU 
                                                                           & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0xffU 
                                                                             & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_hfd15effc_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xffU 
                                                                        & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_hfd15effc_0[
                                                                      (7U 
                                                                       & (VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k2_T))))));
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0xffU 
                                                                           & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0xffU 
                                                                             & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xffU 
                                                                        & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                                                                      (7U 
                                                                       & (VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k3_T))))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
         - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k3_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
         + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    if ((2U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_real;
    }
    FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T);
    __Vtemp_1[0U] = 0x100000U;
    __Vtemp_1[1U] = 0xb504fU;
    __Vtemp_1[2U] = 0U;
    __Vtemp_1[3U] = 0xfff4afb1U;
    __Vtemp_2[0U] = 0x100000U;
    __Vtemp_2[1U] = 0xb504fU;
    __Vtemp_2[2U] = 0U;
    __Vtemp_2[3U] = 0xfff4afb1U;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1 
                                 + ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (__Vtemp_1[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x7fU 
                                                                           & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x7fU 
                                                                             & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (__Vtemp_2[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7fU 
                                                                        & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (__Vtemp_2[
                                                                      (3U 
                                                                       & (VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T))))));
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0xfff4afb1U;
    __Vtemp_3[2U] = 0xfff00000U;
    __Vtemp_3[3U] = 0xfff4afb1U;
    __Vtemp_4[0U] = 0U;
    __Vtemp_4[1U] = 0xfff4afb1U;
    __Vtemp_4[2U] = 0xfff00000U;
    __Vtemp_4[3U] = 0xfff4afb1U;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (__Vtemp_3[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x7fU 
                                                                           & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x7fU 
                                                                             & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (__Vtemp_4[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7fU 
                                                                        & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (__Vtemp_4[
                                                                      (3U 
                                                                       & (VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k3_T))))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k2_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
         - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k3_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
         + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k1_T)))));
    if ((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_real;
    }
    FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T);
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__tmp_k1 
                                 + ((QData)((IData)(
                                                    (0x100000U 
                                                     & ((~ (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)) 
                                                        << 0x14U)))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k2_T))))));
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  ((1U 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                                                    ? 0xfff00000U
                                                                    : 0U)))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k3_T))))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
}

void Vfft128___024root___nba_sequent__TOP__0(Vfft128___024root* vlSelf);
void Vfft128___024root___nba_sequent__TOP__1(Vfft128___024root* vlSelf);
void Vfft128___024root___nba_comb__TOP__0(Vfft128___024root* vlSelf);

void Vfft128___024root___eval_nba(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_nba\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfft128___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfft128___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfft128___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vfft128___024root___nba_sequent__TOP__0(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___nba_sequent__TOP__0\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vdly__FFT128_tb__DOT__uut__DOT__cnt;
    __Vdly__FFT128_tb__DOT__uut__DOT__cnt = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    __Vdly__FFT128_tb__DOT__uut__DOT__cnt = vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt;
    if (vlSelfRef.FFT128_tb__DOT__reset) {
        __Vdly__FFT128_tb__DOT__uut__DOT__cnt = 0U;
    } else if (vlSelfRef.FFT128_tb__DOT__io_in_valid) {
        __Vdly__FFT128_tb__DOT__uut__DOT__cnt = (0x7fU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)));
    }
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_62_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_62_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_127 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_126;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out1_REG_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out2_REG_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out1_REG_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out2_REG_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_186_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_186_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_182_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_182_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_174_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_174_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_158_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_158_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_126_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_126_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_62_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_61_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_62_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_61_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_126 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_125;
    if ((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_real;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_imag;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_real;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_imag;
    }
    if ((2U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_186_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_186_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_186_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_186_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_real;
    }
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_182_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_181_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_182_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_181_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_174_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_173_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_174_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_173_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_158_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_157_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_158_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_157_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_126_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_125_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_126_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_125_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_61_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_60_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_61_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_60_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_125 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_124;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_184_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_184_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_181_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_180_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_181_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_180_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_173_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_172_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_173_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_172_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_157_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_156_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_157_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_156_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_125_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_124_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_125_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_124_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_60_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_59_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_60_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_59_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_124 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_123;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_184_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_184_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    if ((4U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_180_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_180_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_180_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_180_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_real;
    }
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_172_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_171_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_172_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_171_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_156_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_155_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_156_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_155_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_124_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_123_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_124_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_123_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_59_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_58_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_59_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_58_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_123 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_122;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_178_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_178_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_171_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_170_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_171_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_170_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_155_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_154_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_155_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_154_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_123_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_122_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_123_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_122_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_58_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_57_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_58_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_57_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_122 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_121;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_178_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_177_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_178_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_177_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_170_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_169_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_170_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_169_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_154_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_153_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_154_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_153_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_122_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_121_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_122_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_121_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_57_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_56_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_57_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_56_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_121 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_120;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_177_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_176_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_177_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_176_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_169_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_168_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_169_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_168_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_153_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_152_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_153_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_152_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_121_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_120_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_121_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_120_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_56_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_55_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_56_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_55_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_120 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_119;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_176_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_176_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    if ((8U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_168_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_168_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_168_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_168_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_real;
    }
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_152_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_151_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_152_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_151_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_120_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_119_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_120_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_119_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_55_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_54_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_55_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_54_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_119 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_118;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_166_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_166_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_151_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_150_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_151_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_150_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_119_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_118_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_119_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_118_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_54_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_53_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_54_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_53_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_118 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_117;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_166_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_165_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_166_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_165_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_150_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_149_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_150_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_149_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_118_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_117_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_118_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_117_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_53_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_52_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_53_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_52_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_117 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_116;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_165_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_164_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_165_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_164_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_149_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_148_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_149_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_148_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_117_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_116_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_117_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_116_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_52_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_51_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_52_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_51_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_116 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_115;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_164_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_163_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_164_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_163_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_148_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_147_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_148_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_147_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_116_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_115_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_116_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_115_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_51_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_50_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_51_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_50_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_115 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_114;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_163_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_162_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_163_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_162_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_147_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_146_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_147_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_146_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_115_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_114_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_115_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_114_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_50_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_49_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_50_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_49_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_114 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_113;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_162_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_161_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_162_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_161_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_146_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_145_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_146_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_145_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_114_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_113_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_114_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_113_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_49_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_48_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_49_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_48_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_113 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_112;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_161_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_160_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_161_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_160_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_145_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_144_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_145_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_144_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_113_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_112_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_113_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_112_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_48_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_47_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_48_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_47_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_112 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_111;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_160_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_160_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    if ((0x10U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_144_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_144_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_144_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_144_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_real;
    }
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_112_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_111_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_112_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_111_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_47_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_46_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_47_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_46_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_111 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_110;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_142_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_142_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_111_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_110_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_111_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_110_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_46_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_45_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_46_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_45_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_110 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_109;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_142_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_141_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_142_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_141_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_110_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_109_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_110_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_109_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_45_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_44_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_45_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_44_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_109 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_108;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_141_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_140_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_141_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_140_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_109_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_108_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_109_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_108_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_44_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_43_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_44_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_43_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_108 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_107;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_140_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_139_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_140_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_139_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_108_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_107_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_108_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_107_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_43_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_42_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_43_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_42_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_107 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_106;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_139_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_138_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_139_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_138_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_107_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_106_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_107_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_106_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_42_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_41_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_42_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_41_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_106 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_105;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_138_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_137_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_138_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_137_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_106_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_105_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_106_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_105_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_41_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_40_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_41_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_40_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_105 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_104;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_137_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_136_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_137_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_136_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_105_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_104_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_105_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_104_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_40_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_39_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_40_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_39_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_104 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_103;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_136_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_135_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_136_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_135_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_104_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_103_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_104_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_103_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_39_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_38_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_39_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_38_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_103 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_102;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_135_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_134_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_135_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_134_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_103_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_102_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_103_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_102_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_38_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_37_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_38_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_37_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_102 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_101;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_134_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_133_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_134_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_133_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_102_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_101_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_102_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_101_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_37_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_36_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_37_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_36_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_101 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_100;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_133_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_132_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_133_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_132_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_101_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_100_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_101_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_100_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_36_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_35_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_36_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_35_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_100 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_99;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_132_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_131_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_132_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_131_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_100_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_99_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_100_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_99_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_35_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_34_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_35_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_34_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_99 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_98;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_131_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_130_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_131_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_130_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_99_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_98_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_99_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_98_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_34_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_33_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_34_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_33_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_98 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_97;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_130_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_129_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_130_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_129_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_98_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_97_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_98_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_97_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_33_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_32_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_33_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_32_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_97 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_96;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_129_imag 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_128_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_129_real 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_128_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_97_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_96_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_97_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_96_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_32_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_31_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_32_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_31_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_96 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_95;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_128_imag 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                     + ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T))))) 
                                    >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_128_real 
        = (IData)((0xffffffffULL & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                     - ((((QData)((IData)(
                                                          (0xfffffU 
                                                           & (- (IData)(
                                                                        (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
                                                                         >> 0x1fU)))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T))) 
                                        * (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
                                                                           >> 0x1fU)))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T))))) 
                                    >> 0x14U)));
    if ((0x20U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_96_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_96_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_96_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT__r_96_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_real;
    }
    vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt = __Vdly__FFT128_tb__DOT__uut__DOT__cnt;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_31_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_30_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_31_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_30_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_95 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_94;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_94_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_94_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k1_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                           (0x3fU & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft128__ConstPool__CONST_h16a5c00c_0[
                      (((IData)(0x1fU) + (0x7ffU & 
                                          VL_SHIFTL_III(11,11,32, 
                                                        (0x3fU 
                                                         & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft128__ConstPool__CONST_h16a5c00c_0[
               (0x3fU & (VL_SHIFTL_III(11,11,32, (0x3fU 
                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                             (0x3fU 
                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft128__ConstPool__CONST_h8abd5580_0[
                        (((IData)(0x1fU) + (0x7ffU 
                                            & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft128__ConstPool__CONST_h8abd5580_0[
                 (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                         (0x3fU & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k1_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                           (0x1fU & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft128__ConstPool__CONST_hffb3c89b_0[
                      (((IData)(0x1fU) + (0x3ffU & 
                                          VL_SHIFTL_III(10,10,32, 
                                                        (0x1fU 
                                                         & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft128__ConstPool__CONST_hffb3c89b_0[
               (0x1fU & (VL_SHIFTL_III(10,10,32, (0x1fU 
                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                         >> 5U))] >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                             (0x1fU 
                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft128__ConstPool__CONST_hb3c963b9_0[
                        (((IData)(0x1fU) + (0x3ffU 
                                            & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft128__ConstPool__CONST_hb3c963b9_0[
                 (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                         (0x1fU & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k1_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                           (0xfU & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft128__ConstPool__CONST_ha2844606_0[
                      (((IData)(0x1fU) + (0x1ffU & 
                                          VL_SHIFTL_III(9,9,32, 
                                                        (0xfU 
                                                         & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft128__ConstPool__CONST_ha2844606_0[
               (0xfU & (VL_SHIFTL_III(9,9,32, (0xfU 
                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                        >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                           (0xfU 
                                                            & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                             (0xfU 
                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft128__ConstPool__CONST_h942db0a5_0[
                        (((IData)(0x1fU) + (0x1ffU 
                                            & VL_SHIFTL_III(9,9,32, 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft128__ConstPool__CONST_h942db0a5_0[
                 (0xfU & (VL_SHIFTL_III(9,9,32, (0xfU 
                                                 & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                          >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k1_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                           (7U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                      (((IData)(0x1fU) + (0xffU & VL_SHIFTL_III(8,8,32, 
                                                                (7U 
                                                                 & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                       >> 5U)] << ((IData)(0x20U) - 
                                   (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (Vfft128__ConstPool__CONST_h5ba1edbd_0[
               (7U & (VL_SHIFTL_III(8,8,32, (7U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                      >> 5U))] >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                         (7U 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                             (7U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (Vfft128__ConstPool__CONST_hfd15effc_0[
                        (((IData)(0x1fU) + (0xffU & 
                                            VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                         >> 5U)] << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                              (7U 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (Vfft128__ConstPool__CONST_hfd15effc_0[
                 (7U & (VL_SHIFTL_III(8,8,32, (7U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                        >> 5U))] >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                           (7U 
                                                            & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))));
    __Vtemp_1[0U] = 0U;
    __Vtemp_1[1U] = 0xfff4afb1U;
    __Vtemp_1[2U] = 0xfff00000U;
    __Vtemp_1[3U] = 0xfff4afb1U;
    __Vtemp_2[0U] = 0x100000U;
    __Vtemp_2[1U] = 0xb504fU;
    __Vtemp_2[2U] = 0U;
    __Vtemp_2[3U] = 0xfff4afb1U;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k1_T 
        = ((((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                           (3U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
              ? 0U : (__Vtemp_1[(((IData)(0x1fU) + 
                                  (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                 >> 5U)] << ((IData)(0x20U) 
                                             - (0x1fU 
                                                & VL_SHIFTL_III(7,7,32, 
                                                                (3U 
                                                                 & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
            | (__Vtemp_1[(3U & (VL_SHIFTL_III(7,7,32, 
                                              (3U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                >> 5U))] >> (0x1fU 
                                             & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))) 
           + (((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                             (3U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                ? 0U : (__Vtemp_2[(((IData)(0x1fU) 
                                    + (0x7fU & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
              | (__Vtemp_2[(3U & (VL_SHIFTL_III(7,7,32, 
                                                (3U 
                                                 & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                  >> 5U))] >> (0x1fU 
                                               & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k1_T 
        = (((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
             ? 0xfff00000U : 0U) + (0x100000U & ((~ (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)) 
                                                 << 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_30_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_29_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_30_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_29_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_94 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_93;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_94_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_93_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_94_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_93_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_29_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_28_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_29_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_28_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_93 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_92;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_93_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_92_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_93_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_92_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_28_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_27_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_28_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_27_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_92 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_91;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_92_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_91_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_92_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_91_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_27_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_26_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_27_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_26_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_91 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_90;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_91_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_90_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_91_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_90_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_26_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_25_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_26_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_25_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_90 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_89;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_90_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_89_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_90_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_89_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_25_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_24_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_25_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_24_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_89 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_88;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_89_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_88_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_89_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_88_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_24_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_23_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_24_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_23_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_88 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_87;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_88_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_87_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_88_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_87_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_23_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_22_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_23_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_22_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_87 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_86;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_87_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_86_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_87_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_86_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_22_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_21_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_22_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_21_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_86 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_85;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_86_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_85_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_86_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_85_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_21_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_20_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_21_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_20_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_85 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_84;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_85_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_84_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_85_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_84_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_20_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_19_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_20_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_19_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_84 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_83;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_84_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_83_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_84_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_83_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_19_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_18_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_19_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_18_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_83 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_82;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_83_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_82_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_83_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_82_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_18_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_17_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_18_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_17_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_82 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_81;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_82_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_81_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_82_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_81_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_17_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_16_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_17_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_16_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_81 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_80;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_81_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_80_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_81_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_80_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_16_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_15_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_16_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_15_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_80 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_79;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_80_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_79_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_80_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_79_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_15_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_14_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_15_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_14_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_79 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_78;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_79_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_78_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_79_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_78_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_14_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_13_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_14_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_13_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_78 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_77;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_78_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_77_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_78_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_77_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_13_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_12_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_13_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_12_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_77 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_76;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_77_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_76_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_77_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_76_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_12_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_11_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_12_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_11_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_76 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_75;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_76_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_75_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_76_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_75_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_11_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_10_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_11_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_10_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_75 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_74;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_75_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_74_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_75_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_74_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_10_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_9_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_10_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_9_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_74 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_73;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_74_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_73_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_74_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_73_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_9_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_8_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_9_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_8_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_73 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_72;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_73_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_72_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_73_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_72_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_8_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_7_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_8_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_7_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_72 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_71;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_72_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_71_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_72_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_71_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_7_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_6_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_7_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_6_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_71 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_70;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_71_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_70_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_71_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_70_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_6_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_5_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_6_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_5_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_70 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_69;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_70_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_69_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_70_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_69_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_5_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_4_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_5_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_4_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_69 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_68;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_69_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_68_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_69_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_68_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_4_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_3_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_4_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_3_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_68 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_67;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_68_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_67_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_68_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_67_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_3_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_2_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_3_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_2_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_67 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_66;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_67_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_66_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_67_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_66_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_2_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_1_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_2_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_1_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_66 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_65;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_66_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_65_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_66_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_65_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_1_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_1_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_65 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_64;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_65_imag = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_64_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_65_real = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_64_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_imag = vlSelfRef.FFT128_tb__DOT__io_in_imag;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_real = vlSelfRef.FFT128_tb__DOT__io_in_real;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_64 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_63;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_64_imag = (IData)(
                                                            (0xffffffffULL 
                                                             & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                                                 + 
                                                                 ((((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T))) 
                                                                  * 
                                                                  (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T))))) 
                                                                >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__r_64_real = (IData)(
                                                            (0xffffffffULL 
                                                             & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                                                 - 
                                                                 ((((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T))) 
                                                                  * 
                                                                  (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T))))) 
                                                                >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_63 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_62;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_62 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_61;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_61 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_60;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_60 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_59;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_59 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_58;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_58 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_57;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_57 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_56;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_56 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_55;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_55 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_54;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_54 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_53;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_53 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_52;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_52 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_51;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_51 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_50;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_50 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_49;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_49 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_48;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_48 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_47;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_47 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_46;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_46 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_45;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_45 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_44;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_44 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_43;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_43 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_42;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_42 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_41;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_41 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_40;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_40 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_39;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_39 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_38;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_38 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_37;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_37 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_36;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_36 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_35;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_35 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_34;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_34 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_33;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_33 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_32;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_32 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_31;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_31 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_30;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_30 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_29;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_29 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_28;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_28 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_27;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_27 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_26;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_26 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_25;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_25 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_24;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_24 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_23;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_23 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_22;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_22 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_21;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_21 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_20;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_20 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_19;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_19 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_18;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_18 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_17;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_17 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_16;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_16 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_15;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_15 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_14;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_14 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_13;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_13 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_12;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_12 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_11;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_11 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_10;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_10 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_9;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_9 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_8;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_8 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_7;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_7 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_6;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_6 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_5;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_5 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_4;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_4 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_3;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_3 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_2;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_2 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_1;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_1 
        = vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r;
    vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r 
        = vlSelfRef.FFT128_tb__DOT__io_in_valid;
}

VL_INLINE_OPT void Vfft128___024root___nba_sequent__TOP__1(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___nba_sequent__TOP__1\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k2_T 
        = (vlSelfRef.FFT128_tb__DOT__io_in_imag - vlSelfRef.FFT128_tb__DOT__io_in_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k3_T 
        = (vlSelfRef.FFT128_tb__DOT__io_in_imag + vlSelfRef.FFT128_tb__DOT__io_in_real);
}

VL_INLINE_OPT void Vfft128___024root___nba_comb__TOP__0(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___nba_comb__TOP__0\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k2_T;
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k2_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k3_T;
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k3_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k2_T;
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k2_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k3_T;
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k3_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k2_T;
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k2_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k3_T;
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k3_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k3_T;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k3_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k2_T;
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k2_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k3_T;
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k3_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T;
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T = 0;
    QData/*51:0*/ FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_imag_T;
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_imag_T = 0;
    IData/*31:0*/ FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T;
    FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    // Body
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__io_in_imag + vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__io_in_real + vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__io_in_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__io_in_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_real 
           - vlSelfRef.FFT128_tb__DOT__io_in_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_imag 
           - vlSelfRef.FFT128_tb__DOT__io_in_imag);
    if ((0x20U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_real;
    }
    FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__tmp_k1 
                                 + ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_h8abd5580_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x7ffU 
                                                                           & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x7ffU 
                                                                             & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_h8abd5580_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7ffU 
                                                                        & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_h8abd5580_0[
                                                                      (0x3fU 
                                                                       & (VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k2_T))))));
    FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_h16a5c00c_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x7ffU 
                                                                           & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x7ffU 
                                                                             & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_h16a5c00c_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7ffU 
                                                                        & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_h16a5c00c_0[
                                                                      (0x3fU 
                                                                       & (VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(11,11,32, 
                                                                                (0x3fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k3_T))))));
    FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k2_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag 
         - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k3_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag 
         + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T)))));
    if ((0x10U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_real;
    }
    FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T);
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__tmp_k1 
                                 + ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_hb3c963b9_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x3ffU 
                                                                           & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x3ffU 
                                                                             & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_hb3c963b9_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x3ffU 
                                                                        & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_hb3c963b9_0[
                                                                      (0x1fU 
                                                                       & (VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k2_T))))));
    FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_hffb3c89b_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x3ffU 
                                                                           & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x3ffU 
                                                                             & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_hffb3c89b_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x3ffU 
                                                                        & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_hffb3c89b_0[
                                                                      (0x1fU 
                                                                       & (VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(10,10,32, 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k3_T))))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k2_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
         - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k3_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag 
         + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real);
    if ((8U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_real;
    }
    FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T);
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__tmp_k1 
                                 + ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_h942db0a5_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x1ffU 
                                                                           & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x1ffU 
                                                                             & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_h942db0a5_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x1ffU 
                                                                        & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_h942db0a5_0[
                                                                      (0xfU 
                                                                       & (VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k2_T))))));
    FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_ha2844606_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x1ffU 
                                                                           & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x1ffU 
                                                                             & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_ha2844606_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x1ffU 
                                                                        & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_ha2844606_0[
                                                                      (0xfU 
                                                                       & (VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(9,9,32, 
                                                                                (0xfU 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k3_T))))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k2_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
         - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k3_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag 
         + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real);
    if ((4U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_real;
    }
    FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T);
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__tmp_k1 
                                 + ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_hfd15effc_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0xffU 
                                                                           & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0xffU 
                                                                             & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_hfd15effc_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xffU 
                                                                        & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_hfd15effc_0[
                                                                      (7U 
                                                                       & (VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k2_T))))));
    FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0xffU 
                                                                           & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0xffU 
                                                                             & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0xffU 
                                                                        & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                                                                      (7U 
                                                                       & (VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(8,8,32, 
                                                                                (7U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k3_T))))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
         - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k3_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag 
         + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real);
    if ((2U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_real;
    }
    FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T);
    __Vtemp_1[0U] = 0x100000U;
    __Vtemp_1[1U] = 0xb504fU;
    __Vtemp_1[2U] = 0U;
    __Vtemp_1[3U] = 0xfff4afb1U;
    __Vtemp_2[0U] = 0x100000U;
    __Vtemp_2[1U] = 0xb504fU;
    __Vtemp_2[2U] = 0U;
    __Vtemp_2[3U] = 0xfff4afb1U;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1 
                                 + ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (__Vtemp_1[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x7fU 
                                                                           & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x7fU 
                                                                             & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (__Vtemp_2[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7fU 
                                                                        & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (__Vtemp_2[
                                                                      (3U 
                                                                       & (VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T))))));
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0xfff4afb1U;
    __Vtemp_3[2U] = 0xfff00000U;
    __Vtemp_3[3U] = 0xfff4afb1U;
    __Vtemp_4[0U] = 0U;
    __Vtemp_4[1U] = 0xfff4afb1U;
    __Vtemp_4[2U] = 0xfff00000U;
    __Vtemp_4[3U] = 0xfff4afb1U;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (__Vtemp_3[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0x7fU 
                                                                           & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                         >> 5U)] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & ((IData)(0x1fU) 
                                                                            + 
                                                                            (0x7fU 
                                                                             & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                                                     ? 0U
                                                                     : 
                                                                    (__Vtemp_4[
                                                                     (((IData)(0x1fU) 
                                                                       + 
                                                                       (0x7fU 
                                                                        & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                                                      >> 5U)] 
                                                                     << 
                                                                     ((IData)(0x20U) 
                                                                      - 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                                                   | (__Vtemp_4[
                                                                      (3U 
                                                                       & (VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                                          >> 5U))] 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & VL_SHIFTL_III(7,7,32, 
                                                                                (3U 
                                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k3_T))))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_imag 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_imag 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_real 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_real 
           - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k2_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
         - vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k3_T = 
        (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag 
         + vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real);
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__tmp_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k1_T)))));
    if ((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))) {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_real;
    } else {
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_imag 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_imag;
        vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_real 
            = vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_real;
    }
    FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T);
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__tmp_k1 
                                 + ((QData)((IData)(
                                                    (0x100000U 
                                                     & ((~ (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)) 
                                                        << 0x14U)))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k2_T))))));
    FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  ((1U 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                                                    ? 0xfff00000U
                                                                    : 0U)))) 
                                    * (((QData)((IData)(
                                                        (0xfffffU 
                                                         & (- (IData)(
                                                                      (FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k3_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k3_T))))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (IData)(
                                                                            (FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T 
                                                                             >> 0x33U)))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               (FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T 
                                                                >> 0x14U)))) 
                                 * (((QData)((IData)(
                                                     (0xfffffU 
                                                      & (- (IData)(
                                                                   (FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T 
                                                                    >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k1_T)))));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_imag_T 
                    >> 0x14U)) - (IData)((FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T 
                                          >> 0x14U)));
    vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
        = ((IData)((FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_real_T 
                    >> 0x14U)) + (IData)((FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_c_imag_T 
                                          >> 0x14U)));
}

void Vfft128___024root___timing_resume(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___timing_resume\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vfft128___024root___eval_triggers__act(Vfft128___024root* vlSelf);

bool Vfft128___024root___eval_phase__act(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_phase__act\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfft128___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vfft128___024root___timing_resume(vlSelf);
        Vfft128___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfft128___024root___eval_phase__nba(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_phase__nba\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfft128___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft128___024root___dump_triggers__nba(Vfft128___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft128___024root___dump_triggers__act(Vfft128___024root* vlSelf);
#endif  // VL_DEBUG

void Vfft128___024root___eval(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vfft128___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fft128_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vfft128___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fft128_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vfft128___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vfft128___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfft128___024root___eval_debug_assertions(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_debug_assertions\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
