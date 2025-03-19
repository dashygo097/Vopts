// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft512.h for the primary calling header

#include "Vfft512__pch.h"
#include "Vfft512___024root.h"

VL_ATTR_COLD void Vfft512___024root___eval_static(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_static\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfft512___024root___eval_final(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_final\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft512___024root___dump_triggers__stl(Vfft512___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfft512___024root___eval_phase__stl(Vfft512___024root* vlSelf);

VL_ATTR_COLD void Vfft512___024root___eval_settle(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_settle\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vfft512___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fft512_tb.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfft512___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft512___024root___dump_triggers__stl(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___dump_triggers__stl\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vfft512___024root___stl_sequent__TOP__0(Vfft512___024root* vlSelf);
VL_ATTR_COLD void Vfft512___024root____Vm_traceActivitySetAll(Vfft512___024root* vlSelf);

VL_ATTR_COLD void Vfft512___024root___eval_stl(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_stl\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vfft512___024root___stl_sequent__TOP__0(vlSelf);
        Vfft512___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

extern const VlWide<256>/*8191:0*/ Vfft512__ConstPool__CONST_h15912bbd_0;
extern const VlWide<256>/*8191:0*/ Vfft512__ConstPool__CONST_h010c7fca_0;
extern const VlWide<128>/*4095:0*/ Vfft512__ConstPool__CONST_h944bc563_0;
extern const VlWide<128>/*4095:0*/ Vfft512__ConstPool__CONST_hf3784b49_0;
extern const VlWide<64>/*2047:0*/ Vfft512__ConstPool__CONST_h5478b25e_0;
extern const VlWide<64>/*2047:0*/ Vfft512__ConstPool__CONST_h8abd5580_0;
extern const VlWide<32>/*1023:0*/ Vfft512__ConstPool__CONST_h35564355_0;
extern const VlWide<32>/*1023:0*/ Vfft512__ConstPool__CONST_hb3c963b9_0;
extern const VlWide<16>/*511:0*/ Vfft512__ConstPool__CONST_h0bfcbe7a_0;
extern const VlWide<16>/*511:0*/ Vfft512__ConstPool__CONST_h942db0a5_0;
extern const VlWide<8>/*255:0*/ Vfft512__ConstPool__CONST_h04042068_0;
extern const VlWide<8>/*255:0*/ Vfft512__ConstPool__CONST_hfd15effc_0;

VL_ATTR_COLD void Vfft512___024root___stl_sequent__TOP__0(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___stl_sequent__TOP__0\n"); );
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
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_5;
    VlWide<4>/*127:0*/ __Vtemp_6;
    // Body
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
    __Vtemp_5[0U] = 0x100000U;
    __Vtemp_5[1U] = 0xb504fU;
    __Vtemp_5[2U] = 0U;
    __Vtemp_5[3U] = 0xfff4afb1U;
    __Vtemp_6[0U] = 0x100000U;
    __Vtemp_6[1U] = 0xb504fU;
    __Vtemp_6[2U] = 0U;
    __Vtemp_6[3U] = 0xfff4afb1U;
    vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
        = (0xfffffffffffffULL & ((((QData)((IData)(
                                                   (0xfffffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (__Vtemp_5[
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
                                                                 (__Vtemp_6[
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
                                                                | (__Vtemp_6[
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

VL_ATTR_COLD void Vfft512___024root___eval_triggers__stl(Vfft512___024root* vlSelf);

VL_ATTR_COLD bool Vfft512___024root___eval_phase__stl(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___eval_phase__stl\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfft512___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vfft512___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft512___024root___dump_triggers__act(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___dump_triggers__act\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge FFT512_tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft512___024root___dump_triggers__nba(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___dump_triggers__nba\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge FFT512_tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfft512___024root____Vm_traceActivitySetAll(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root____Vm_traceActivitySetAll\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vfft512___024root___ctor_var_reset(Vfft512___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root___ctor_var_reset\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->FFT512_tb__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->FFT512_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->FFT512_tb__DOT__io_in_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__io_in_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__io_in_valid = VL_RAND_RESET_I(1);
    vlSelf->FFT512_tb__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_7_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_7_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_6_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_6_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_5_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_5_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_4_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_4_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_3_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_3_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_2_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_2_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_1_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_1_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_io_out2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_io_out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT___m_io_out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__cnt = VL_RAND_RESET_I(10);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_2_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_2_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_3_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_3_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_4_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_4_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_5_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_5_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_6_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_6_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_7_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_7_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_8_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_8_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_9_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_9_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_10_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_10_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_11_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_11_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_12_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_12_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_13_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_13_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_14_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_14_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_15_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_15_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_16_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_16_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_17_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_17_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_18_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_18_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_19_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_19_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_20_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_20_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_21_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_21_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_22_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_22_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_23_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_23_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_24_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_24_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_25_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_25_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_26_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_26_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_27_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_27_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_28_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_28_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_29_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_29_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_30_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_30_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_31_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_31_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_32_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_32_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_33_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_33_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_34_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_34_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_35_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_35_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_36_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_36_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_37_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_37_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_38_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_38_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_39_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_39_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_40_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_40_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_41_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_41_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_42_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_42_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_43_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_43_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_44_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_44_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_45_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_45_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_46_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_46_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_47_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_47_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_48_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_48_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_49_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_49_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_50_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_50_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_51_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_51_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_52_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_52_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_53_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_53_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_54_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_54_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_55_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_55_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_56_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_56_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_57_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_57_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_58_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_58_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_59_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_59_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_60_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_60_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_61_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_61_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_62_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_62_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_63_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_63_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_64_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_64_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_65_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_65_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_66_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_66_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_67_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_67_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_68_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_68_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_69_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_69_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_70_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_70_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_71_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_71_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_72_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_72_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_73_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_73_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_74_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_74_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_75_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_75_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_76_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_76_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_77_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_77_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_78_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_78_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_79_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_79_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_80_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_80_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_81_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_81_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_82_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_82_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_83_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_83_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_84_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_84_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_85_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_85_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_86_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_86_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_87_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_87_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_88_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_88_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_89_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_89_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_90_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_90_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_91_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_91_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_92_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_92_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_93_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_93_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_94_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_94_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_95_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_95_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_96_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_96_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_97_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_97_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_98_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_98_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_99_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_99_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_100_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_100_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_101_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_101_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_102_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_102_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_103_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_103_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_104_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_104_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_105_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_105_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_106_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_106_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_107_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_107_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_108_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_108_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_109_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_109_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_110_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_110_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_111_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_111_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_112_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_112_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_113_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_113_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_114_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_114_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_115_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_115_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_116_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_116_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_117_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_117_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_118_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_118_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_119_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_119_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_120_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_120_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_121_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_121_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_122_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_122_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_123_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_123_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_124_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_124_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_125_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_125_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_126_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_126_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_127_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_127_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_128_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_128_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_129_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_129_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_130_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_130_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_131_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_131_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_132_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_132_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_133_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_133_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_134_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_134_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_135_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_135_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_136_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_136_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_137_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_137_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_138_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_138_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_139_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_139_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_140_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_140_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_141_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_141_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_142_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_142_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_143_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_143_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_144_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_144_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_145_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_145_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_146_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_146_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_147_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_147_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_148_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_148_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_149_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_149_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_150_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_150_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_151_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_151_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_152_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_152_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_153_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_153_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_154_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_154_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_155_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_155_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_156_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_156_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_157_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_157_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_158_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_158_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_159_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_159_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_160_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_160_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_161_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_161_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_162_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_162_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_163_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_163_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_164_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_164_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_165_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_165_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_166_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_166_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_167_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_167_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_168_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_168_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_169_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_169_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_170_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_170_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_171_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_171_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_172_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_172_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_173_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_173_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_174_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_174_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_175_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_175_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_176_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_176_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_177_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_177_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_178_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_178_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_179_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_179_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_180_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_180_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_181_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_181_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_182_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_182_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_183_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_183_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_184_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_184_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_185_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_185_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_186_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_186_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_187_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_187_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_188_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_188_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_189_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_189_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_190_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_190_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_191_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_191_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_192_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_192_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_193_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_193_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_194_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_194_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_195_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_195_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_196_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_196_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_197_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_197_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_198_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_198_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_199_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_199_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_200_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_200_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_201_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_201_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_202_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_202_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_203_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_203_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_204_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_204_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_205_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_205_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_206_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_206_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_207_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_207_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_208_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_208_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_209_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_209_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_210_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_210_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_211_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_211_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_212_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_212_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_213_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_213_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_214_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_214_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_215_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_215_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_216_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_216_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_217_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_217_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_218_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_218_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_219_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_219_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_220_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_220_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_221_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_221_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_222_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_222_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_223_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_223_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_224_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_224_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_225_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_225_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_226_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_226_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_227_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_227_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_228_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_228_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_229_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_229_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_230_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_230_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_231_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_231_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_232_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_232_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_233_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_233_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_234_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_234_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_235_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_235_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_236_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_236_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_237_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_237_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_238_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_238_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_239_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_239_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_240_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_240_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_241_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_241_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_242_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_242_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_243_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_243_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_244_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_244_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_245_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_245_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_246_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_246_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_247_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_247_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_248_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_248_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_249_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_249_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_250_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_250_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_251_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_251_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_252_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_252_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_253_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_253_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_254_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_254_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_255_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_255_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_256_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_256_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_257_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_257_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_258_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_258_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_259_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_259_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_260_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_260_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_261_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_261_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_262_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_262_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_263_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_263_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_264_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_264_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_265_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_265_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_266_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_266_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_267_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_267_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_268_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_268_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_269_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_269_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_270_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_270_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_271_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_271_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_272_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_272_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_273_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_273_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_274_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_274_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_275_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_275_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_276_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_276_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_277_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_277_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_278_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_278_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_279_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_279_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_280_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_280_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_281_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_281_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_282_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_282_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_283_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_283_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_284_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_284_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_285_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_285_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_286_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_286_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_287_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_287_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_288_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_288_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_289_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_289_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_290_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_290_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_291_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_291_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_292_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_292_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_293_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_293_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_294_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_294_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_295_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_295_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_296_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_296_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_297_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_297_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_298_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_298_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_299_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_299_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_300_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_300_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_301_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_301_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_302_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_302_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_303_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_303_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_304_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_304_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_305_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_305_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_306_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_306_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_307_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_307_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_308_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_308_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_309_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_309_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_310_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_310_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_311_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_311_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_312_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_312_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_313_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_313_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_314_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_314_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_315_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_315_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_316_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_316_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_317_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_317_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_318_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_318_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_319_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_319_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_320_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_320_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_321_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_321_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_322_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_322_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_323_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_323_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_324_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_324_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_325_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_325_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_326_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_326_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_327_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_327_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_328_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_328_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_329_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_329_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_330_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_330_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_331_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_331_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_332_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_332_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_333_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_333_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_334_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_334_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_335_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_335_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_336_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_336_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_337_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_337_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_338_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_338_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_339_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_339_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_340_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_340_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_341_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_341_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_342_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_342_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_343_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_343_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_344_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_344_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_345_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_345_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_346_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_346_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_347_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_347_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_348_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_348_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_349_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_349_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_350_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_350_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_351_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_351_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_352_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_352_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_353_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_353_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_354_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_354_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_355_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_355_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_356_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_356_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_357_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_357_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_358_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_358_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_359_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_359_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_360_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_360_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_361_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_361_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_362_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_362_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_363_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_363_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_364_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_364_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_365_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_365_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_366_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_366_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_367_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_367_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_368_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_368_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_369_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_369_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_370_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_370_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_371_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_371_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_372_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_372_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_373_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_373_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_374_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_374_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_375_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_375_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_376_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_376_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_377_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_377_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_378_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_378_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_379_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_379_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_380_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_380_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_381_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_381_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_382_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_382_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_383_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_383_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_384_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_384_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_385_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_385_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_386_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_386_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_387_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_387_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_388_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_388_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_389_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_389_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_390_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_390_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_391_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_391_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_392_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_392_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_393_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_393_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_394_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_394_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_395_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_395_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_396_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_396_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_397_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_397_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_398_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_398_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_399_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_399_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_400_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_400_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_401_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_401_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_402_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_402_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_403_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_403_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_404_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_404_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_405_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_405_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_406_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_406_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_407_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_407_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_408_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_408_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_409_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_409_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_410_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_410_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_411_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_411_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_412_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_412_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_413_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_413_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_414_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_414_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_415_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_415_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_416_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_416_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_417_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_417_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_418_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_418_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_419_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_419_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_420_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_420_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_421_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_421_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_422_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_422_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_423_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_423_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_424_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_424_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_425_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_425_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_426_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_426_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_427_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_427_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_428_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_428_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_429_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_429_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_430_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_430_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_431_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_431_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_432_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_432_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_433_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_433_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_434_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_434_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_435_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_435_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_436_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_436_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_437_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_437_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_438_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_438_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_439_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_439_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_440_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_440_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_441_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_441_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_442_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_442_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_443_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_443_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_444_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_444_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_445_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_445_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_446_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_446_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_447_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_447_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_448_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_448_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_449_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_449_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_450_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_450_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_451_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_451_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_452_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_452_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_453_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_453_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_454_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_454_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_455_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_455_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_456_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_456_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_457_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_457_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_458_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_458_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_459_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_459_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_460_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_460_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_461_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_461_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_462_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_462_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_463_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_463_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_464_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_464_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_465_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_465_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_466_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_466_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_467_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_467_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_468_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_468_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_469_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_469_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_470_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_470_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_471_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_471_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_472_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_472_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_473_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_473_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_474_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_474_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_475_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_475_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_476_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_476_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_477_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_477_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_478_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_478_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_479_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_479_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_480_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_480_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_481_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_481_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_482_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_482_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_483_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_483_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_484_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_484_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_485_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_485_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_486_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_486_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_487_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_487_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_488_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_488_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_489_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_489_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_490_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_490_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_491_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_491_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_492_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_492_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_493_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_493_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_494_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_494_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_495_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_495_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_496_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_496_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_497_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_497_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_498_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_498_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_499_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_499_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_500_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_500_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_501_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_501_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_502_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_502_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_503_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_503_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_504_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_504_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_505_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_505_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_506_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_506_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_507_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_507_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_508_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_508_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_509_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_509_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_510_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_510_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_511_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_511_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_512_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_512_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_513_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_513_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_514_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_514_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_515_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_515_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_516_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_516_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_517_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_517_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_518_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_518_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_519_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_519_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_520_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_520_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_521_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_521_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_522_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_522_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_523_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_523_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_524_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_524_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_525_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_525_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_526_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_526_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_527_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_527_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_528_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_528_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_529_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_529_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_530_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_530_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_531_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_531_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_532_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_532_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_533_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_533_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_534_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_534_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_535_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_535_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_536_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_536_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_537_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_537_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_538_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_538_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_539_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_539_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_540_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_540_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_541_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_541_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_542_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_542_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_543_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_543_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_544_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_544_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_545_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_545_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_546_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_546_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_547_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_547_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_548_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_548_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_549_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_549_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_550_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_550_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_551_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_551_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_552_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_552_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_553_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_553_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_554_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_554_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_555_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_555_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_556_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_556_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_557_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_557_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_558_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_558_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_559_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_559_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_560_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_560_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_561_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_561_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_562_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_562_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_563_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_563_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_564_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_564_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_565_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_565_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_566_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_566_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_567_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_567_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_568_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_568_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_569_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_569_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_570_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_570_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_571_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_571_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_572_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_572_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_573_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_573_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_574_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_574_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_575_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_575_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_576_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_576_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_577_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_577_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_578_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_578_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_579_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_579_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_580_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_580_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_581_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_581_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_582_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_582_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_583_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_583_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_584_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_584_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_585_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_585_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_586_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_586_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_587_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_587_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_588_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_588_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_589_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_589_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_590_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_590_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_591_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_591_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_592_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_592_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_593_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_593_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_594_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_594_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_595_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_595_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_596_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_596_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_597_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_597_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_598_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_598_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_599_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_599_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_600_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_600_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_601_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_601_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_602_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_602_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_603_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_603_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_604_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_604_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_605_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_605_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_606_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_606_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_607_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_607_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_608_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_608_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_609_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_609_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_610_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_610_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_611_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_611_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_612_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_612_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_613_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_613_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_614_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_614_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_615_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_615_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_616_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_616_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_617_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_617_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_618_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_618_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_619_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_619_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_620_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_620_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_621_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_621_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_622_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_622_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_623_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_623_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_624_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_624_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_625_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_625_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_626_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_626_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_627_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_627_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_628_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_628_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_629_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_629_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_630_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_630_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_631_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_631_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_632_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_632_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_633_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_633_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_634_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_634_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_635_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_635_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_636_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_636_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_637_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_637_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_638_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_638_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_639_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_639_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_640_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_640_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_641_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_641_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_642_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_642_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_643_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_643_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_644_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_644_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_645_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_645_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_646_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_646_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_647_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_647_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_648_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_648_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_649_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_649_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_650_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_650_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_651_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_651_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_652_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_652_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_653_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_653_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_654_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_654_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_655_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_655_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_656_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_656_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_657_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_657_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_658_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_658_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_659_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_659_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_660_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_660_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_661_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_661_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_662_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_662_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_663_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_663_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_664_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_664_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_665_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_665_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_666_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_666_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_667_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_667_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_668_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_668_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_669_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_669_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_670_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_670_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_671_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_671_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_672_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_672_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_673_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_673_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_674_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_674_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_675_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_675_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_676_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_676_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_677_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_677_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_678_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_678_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_679_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_679_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_680_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_680_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_681_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_681_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_682_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_682_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_683_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_683_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_684_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_684_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_685_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_685_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_686_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_686_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_687_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_687_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_688_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_688_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_689_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_689_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_690_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_690_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_691_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_691_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_692_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_692_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_693_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_693_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_694_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_694_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_695_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_695_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_696_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_696_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_697_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_697_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_698_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_698_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_699_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_699_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_700_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_700_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_701_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_701_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_702_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_702_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_703_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_703_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_704_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_704_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_705_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_705_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_706_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_706_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_707_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_707_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_708_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_708_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_709_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_709_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_710_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_710_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_711_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_711_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_712_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_712_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_713_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_713_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_714_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_714_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_715_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_715_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_716_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_716_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_717_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_717_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_718_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_718_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_719_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_719_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_720_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_720_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_721_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_721_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_722_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_722_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_723_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_723_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_724_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_724_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_725_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_725_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_726_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_726_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_727_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_727_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_728_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_728_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_729_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_729_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_730_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_730_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_731_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_731_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_732_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_732_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_733_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_733_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_734_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_734_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_735_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_735_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_736_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_736_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_737_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_737_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_738_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_738_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_739_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_739_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_740_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_740_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_741_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_741_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_742_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_742_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_743_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_743_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_744_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_744_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_745_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_745_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_746_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_746_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_747_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_747_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_748_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_748_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_749_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_749_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_750_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_750_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_751_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_751_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_752_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_752_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_753_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_753_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_754_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_754_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_755_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_755_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_756_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_756_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_757_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_757_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_758_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_758_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_759_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_759_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_760_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_760_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_761_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_761_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_762_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_762_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_763_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_763_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_764_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__r_764_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__out1_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__out1_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__io_out1_REG_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__io_out1_REG_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__io_out2_REG_real = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__io_out2_REG_imag = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__io_out_valid_REG = VL_RAND_RESET_I(1);
    vlSelf->FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1 = VL_RAND_RESET_Q(52);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k2_T = VL_RAND_RESET_I(32);
    vlSelf->FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k3_T = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__FFT512_tb__DOT__clock__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
