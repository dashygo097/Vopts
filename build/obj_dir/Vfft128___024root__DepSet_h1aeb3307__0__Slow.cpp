// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft128.h for the primary calling header

#include "Vfft128__pch.h"
#include "Vfft128___024root.h"

VL_ATTR_COLD void Vfft128___024root___eval_static(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_static\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfft128___024root___eval_final(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_final\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft128___024root___dump_triggers__stl(Vfft128___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfft128___024root___eval_phase__stl(Vfft128___024root* vlSelf);

VL_ATTR_COLD void Vfft128___024root___eval_settle(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_settle\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vfft128___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fft128_tb.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfft128___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft128___024root___dump_triggers__stl(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___dump_triggers__stl\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vfft128___024root___stl_sequent__TOP__0(Vfft128___024root* vlSelf);
VL_ATTR_COLD void Vfft128___024root____Vm_traceActivitySetAll(Vfft128___024root* vlSelf);

VL_ATTR_COLD void Vfft128___024root___eval_stl(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_stl\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vfft128___024root___stl_sequent__TOP__0(vlSelf);
        Vfft128___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

extern const VlWide<64>/*2047:0*/ Vfft128__ConstPool__CONST_h16a5c00c_0;
extern const VlWide<64>/*2047:0*/ Vfft128__ConstPool__CONST_h8abd5580_0;
extern const VlWide<32>/*1023:0*/ Vfft128__ConstPool__CONST_hffb3c89b_0;
extern const VlWide<32>/*1023:0*/ Vfft128__ConstPool__CONST_hb3c963b9_0;
extern const VlWide<16>/*511:0*/ Vfft128__ConstPool__CONST_ha2844606_0;
extern const VlWide<16>/*511:0*/ Vfft128__ConstPool__CONST_h942db0a5_0;
extern const VlWide<8>/*255:0*/ Vfft128__ConstPool__CONST_h5ba1edbd_0;
extern const VlWide<8>/*255:0*/ Vfft128__ConstPool__CONST_hfd15effc_0;

VL_ATTR_COLD void Vfft128___024root___stl_sequent__TOP__0(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___stl_sequent__TOP__0\n"); );
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
    VlWide<4>/*127:0*/ __Vtemp_5;
    VlWide<4>/*127:0*/ __Vtemp_6;
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
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_imag 
        = (vlSelfRef.FFT128_tb__DOT__io_in_imag + vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_imag);
    vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_real 
        = (vlSelfRef.FFT128_tb__DOT__io_in_real + vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_real);
    FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k1_T 
        = (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
           + vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T);
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
    __Vtemp_3[0U] = 0x100000U;
    __Vtemp_3[1U] = 0xb504fU;
    __Vtemp_3[2U] = 0U;
    __Vtemp_3[3U] = 0xfff4afb1U;
    __Vtemp_4[0U] = 0x100000U;
    __Vtemp_4[1U] = 0xb504fU;
    __Vtemp_4[2U] = 0U;
    __Vtemp_4[3U] = 0xfff4afb1U;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_imag_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1 
                                 + ((((QData)((IData)(
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
                                                                      (FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k2_T))))));
    __Vtemp_5[0U] = 0U;
    __Vtemp_5[1U] = 0xfff4afb1U;
    __Vtemp_5[2U] = 0xfff00000U;
    __Vtemp_5[3U] = 0xfff4afb1U;
    __Vtemp_6[0U] = 0U;
    __Vtemp_6[1U] = 0xfff4afb1U;
    __Vtemp_6[2U] = 0xfff00000U;
    __Vtemp_6[3U] = 0xfff4afb1U;
    FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_c_real_T 
        = (0xfffffffffffffULL & (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1 
                                 - ((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (__Vtemp_5[
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
                                                                    (__Vtemp_6[
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
                                                                   | (__Vtemp_6[
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

VL_ATTR_COLD void Vfft128___024root___eval_triggers__stl(Vfft128___024root* vlSelf);

VL_ATTR_COLD bool Vfft128___024root___eval_phase__stl(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_phase__stl\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfft128___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vfft128___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft128___024root___dump_triggers__act(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___dump_triggers__act\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge FFT128_tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft128___024root___dump_triggers__nba(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___dump_triggers__nba\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge FFT128_tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfft128___024root____Vm_traceActivitySetAll(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root____Vm_traceActivitySetAll\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vfft128___024root___ctor_var_reset(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___ctor_var_reset\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->FFT128_tb__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__io_in_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__io_in_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__io_in_valid = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_5_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_5_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_4_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_4_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_3_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_3_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_2_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_2_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_1_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_1_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT___m_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__cnt = VL_RAND_RESET_I(7);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_3_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_3_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_4_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_4_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_5_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_5_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_6_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_6_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_7_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_7_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_8_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_8_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_9_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_9_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_10_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_10_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_11_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_11_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_12_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_12_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_13_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_13_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_14_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_14_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_15_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_15_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_16_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_16_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_17_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_17_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_18_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_18_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_19_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_19_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_20_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_20_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_21_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_21_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_22_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_22_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_23_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_23_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_24_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_24_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_25_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_25_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_26_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_26_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_27_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_27_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_28_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_28_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_29_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_29_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_30_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_30_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_31_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_31_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_32_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_32_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_33_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_33_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_34_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_34_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_35_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_35_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_36_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_36_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_37_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_37_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_38_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_38_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_39_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_39_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_40_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_40_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_41_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_41_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_42_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_42_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_43_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_43_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_44_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_44_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_45_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_45_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_46_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_46_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_47_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_47_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_48_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_48_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_49_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_49_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_50_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_50_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_51_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_51_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_52_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_52_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_53_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_53_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_54_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_54_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_55_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_55_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_56_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_56_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_57_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_57_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_58_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_58_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_59_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_59_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_60_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_60_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_61_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_61_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_62_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_62_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_63_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_63_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_64_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_64_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_65_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_65_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_66_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_66_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_67_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_67_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_68_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_68_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_69_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_69_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_70_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_70_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_71_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_71_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_72_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_72_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_73_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_73_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_74_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_74_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_75_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_75_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_76_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_76_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_77_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_77_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_78_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_78_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_79_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_79_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_80_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_80_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_81_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_81_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_82_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_82_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_83_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_83_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_84_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_84_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_85_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_85_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_86_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_86_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_87_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_87_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_88_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_88_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_89_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_89_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_90_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_90_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_91_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_91_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_92_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_92_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_93_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_93_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_94_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_94_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_95_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_95_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_96_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_96_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_97_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_97_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_98_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_98_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_99_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_99_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_100_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_100_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_101_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_101_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_102_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_102_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_103_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_103_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_104_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_104_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_105_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_105_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_106_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_106_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_107_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_107_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_108_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_108_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_109_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_109_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_110_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_110_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_111_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_111_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_112_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_112_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_113_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_113_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_114_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_114_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_115_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_115_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_116_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_116_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_117_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_117_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_118_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_118_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_119_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_119_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_120_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_120_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_121_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_121_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_122_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_122_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_123_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_123_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_124_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_124_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_125_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_125_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_126_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_126_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_127_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_127_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_128_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_128_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_129_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_129_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_130_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_130_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_131_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_131_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_132_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_132_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_133_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_133_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_134_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_134_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_135_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_135_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_136_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_136_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_137_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_137_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_138_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_138_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_139_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_139_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_140_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_140_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_141_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_141_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_142_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_142_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_143_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_143_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_144_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_144_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_145_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_145_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_146_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_146_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_147_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_147_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_148_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_148_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_149_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_149_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_150_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_150_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_151_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_151_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_152_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_152_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_153_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_153_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_154_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_154_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_155_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_155_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_156_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_156_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_157_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_157_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_158_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_158_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_159_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_159_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_160_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_160_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_161_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_161_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_162_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_162_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_163_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_163_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_164_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_164_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_165_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_165_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_166_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_166_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_167_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_167_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_168_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_168_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_169_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_169_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_170_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_170_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_171_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_171_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_172_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_172_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_173_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_173_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_174_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_174_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_175_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_175_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_176_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_176_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_177_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_177_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_178_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_178_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_179_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_179_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_180_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_180_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_181_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_181_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_182_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_182_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_183_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_183_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_184_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_184_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_185_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_185_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_186_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_186_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_187_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_187_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_188_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__r_188_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out1_REG_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out1_REG_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out2_REG_real = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out2_REG_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_1 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_2 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_3 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_4 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_5 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_6 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_7 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_8 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_9 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_10 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_11 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_12 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_13 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_14 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_15 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_16 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_17 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_18 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_19 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_20 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_21 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_22 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_23 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_24 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_25 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_26 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_27 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_28 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_29 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_30 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_31 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_32 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_33 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_34 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_35 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_36 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_37 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_38 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_39 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_40 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_41 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_42 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_43 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_44 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_45 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_46 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_47 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_48 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_49 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_50 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_51 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_52 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_53 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_54 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_55 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_56 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_57 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_58 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_59 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_60 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_61 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_62 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_63 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_64 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_65 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_66 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_67 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_68 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_69 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_70 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_71 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_72 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_73 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_74 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_75 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_76 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_77 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_78 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_79 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_80 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_81 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_82 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_83 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_84 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_85 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_86 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_87 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_88 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_89 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_90 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_91 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_92 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_93 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_94 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_95 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_96 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_97 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_98 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_99 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_100 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_101 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_102 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_103 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_104 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_105 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_106 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_107 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_108 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_109 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_110 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_111 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_112 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_113 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_114 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_115 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_116 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_117 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_118 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_119 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_120 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_121 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_122 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_123 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_124 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_125 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_126 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__io_out_valid_r_127 = VL_RAND_RESET_I(1);
    vlSelf->FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k1_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m__DOT__tmp_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m__DOT___tmp_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_1__DOT___tmp_k1_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_1__DOT__tmp_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_2__DOT___tmp_k1_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_2__DOT__tmp_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_3__DOT___tmp_k1_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_3__DOT__tmp_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_4__DOT___tmp_k1_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_5__DOT___tmp_k1_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_5__DOT__tmp_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__FFT128_tb__DOT__clock__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
