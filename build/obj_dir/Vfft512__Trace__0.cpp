// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfft512__Syms.h"


void Vfft512___024root__trace_chg_0_sub_0(Vfft512___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfft512___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root__trace_chg_0\n"); );
    // Init
    Vfft512___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft512___024root*>(voidSelf);
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfft512___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<256>/*8191:0*/ Vfft512__ConstPool__CONST_h010c7fca_0;
extern const VlWide<256>/*8191:0*/ Vfft512__ConstPool__CONST_h15912bbd_0;
extern const VlWide<128>/*4095:0*/ Vfft512__ConstPool__CONST_hf3784b49_0;
extern const VlWide<128>/*4095:0*/ Vfft512__ConstPool__CONST_h944bc563_0;
extern const VlWide<64>/*2047:0*/ Vfft512__ConstPool__CONST_h8abd5580_0;
extern const VlWide<64>/*2047:0*/ Vfft512__ConstPool__CONST_h5478b25e_0;
extern const VlWide<32>/*1023:0*/ Vfft512__ConstPool__CONST_hb3c963b9_0;
extern const VlWide<32>/*1023:0*/ Vfft512__ConstPool__CONST_h35564355_0;
extern const VlWide<16>/*511:0*/ Vfft512__ConstPool__CONST_h942db0a5_0;
extern const VlWide<16>/*511:0*/ Vfft512__ConstPool__CONST_h0bfcbe7a_0;
extern const VlWide<8>/*255:0*/ Vfft512__ConstPool__CONST_hfd15effc_0;
extern const VlWide<8>/*255:0*/ Vfft512__ConstPool__CONST_h04042068_0;

void Vfft512___024root__trace_chg_0_sub_0(Vfft512___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root__trace_chg_0_sub_0\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.FFT512_tb__DOT__reset));
        bufp->chgIData(oldp+1,(vlSelfRef.FFT512_tb__DOT__io_in_real),32);
        bufp->chgIData(oldp+2,(vlSelfRef.FFT512_tb__DOT__io_in_imag),32);
        bufp->chgBit(oldp+3,(vlSelfRef.FFT512_tb__DOT__io_in_valid));
        bufp->chgIData(oldp+4,(vlSelfRef.FFT512_tb__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [3U] | vlSelfRef.__Vm_traceActivity
                       [4U]) | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgIData(oldp+5,(((0x80U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_real
                                 : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_real)),32);
        bufp->chgIData(oldp+6,(((0x80U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_imag
                                 : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_imag)),32);
        bufp->chgIData(oldp+7,(((0x40U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_real
                                 : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_real)),32);
        bufp->chgIData(oldp+8,(((0x40U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_imag
                                 : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_imag)),32);
        bufp->chgIData(oldp+9,(((0x20U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_real
                                 : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_real)),32);
        bufp->chgIData(oldp+10,(((0x20U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_imag
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_imag)),32);
        bufp->chgIData(oldp+11,(((0x10U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_real
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_real)),32);
        bufp->chgIData(oldp+12,(((0x10U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_imag
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_imag)),32);
        bufp->chgIData(oldp+13,(((8U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_real
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_real)),32);
        bufp->chgIData(oldp+14,(((8U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_imag
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_imag)),32);
        bufp->chgIData(oldp+15,(((4U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_real
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_real)),32);
        bufp->chgIData(oldp+16,(((4U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_imag
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_imag)),32);
        bufp->chgIData(oldp+17,(((2U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_real
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_real)),32);
        bufp->chgIData(oldp+18,(((2U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_imag
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_imag)),32);
        bufp->chgIData(oldp+19,(((1U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_real
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_real)),32);
        bufp->chgIData(oldp+20,(((1U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_imag
                                  : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_imag)),32);
        bufp->chgIData(oldp+21,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+22,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+23,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+24,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+25,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+26,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+27,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+28,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+29,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+30,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+31,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+32,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+33,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+34,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+35,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+36,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgIData(oldp+37,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_real),32);
        bufp->chgIData(oldp+38,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_imag),32);
        bufp->chgIData(oldp+39,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_real),32);
        bufp->chgIData(oldp+40,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag),32);
        bufp->chgIData(oldp+41,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_real),32);
        bufp->chgIData(oldp+42,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_imag),32);
        bufp->chgIData(oldp+43,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real),32);
        bufp->chgIData(oldp+44,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag),32);
        bufp->chgIData(oldp+45,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_real),32);
        bufp->chgIData(oldp+46,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_imag),32);
        bufp->chgIData(oldp+47,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real),32);
        bufp->chgIData(oldp+48,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag),32);
        bufp->chgIData(oldp+49,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_real),32);
        bufp->chgIData(oldp+50,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_imag),32);
        bufp->chgIData(oldp+51,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real),32);
        bufp->chgIData(oldp+52,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag),32);
        bufp->chgIData(oldp+53,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_real),32);
        bufp->chgIData(oldp+54,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_imag),32);
        bufp->chgIData(oldp+55,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real),32);
        bufp->chgIData(oldp+56,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag),32);
        bufp->chgIData(oldp+57,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_real),32);
        bufp->chgIData(oldp+58,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_imag),32);
        bufp->chgIData(oldp+59,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real),32);
        bufp->chgIData(oldp+60,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag),32);
        bufp->chgIData(oldp+61,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_real),32);
        bufp->chgIData(oldp+62,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_imag),32);
        bufp->chgIData(oldp+63,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real),32);
        bufp->chgIData(oldp+64,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag),32);
        bufp->chgIData(oldp+65,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_real),32);
        bufp->chgIData(oldp+66,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_imag),32);
        bufp->chgIData(oldp+67,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_real),32);
        bufp->chgIData(oldp+68,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_imag),32);
        bufp->chgQData(oldp+69,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+71,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+73,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+75,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+77,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+79,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+81,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+83,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1),52);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+85,(vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out1_REG_real),32);
        bufp->chgIData(oldp+86,(vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out1_REG_imag),32);
        bufp->chgIData(oldp+87,(vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out2_REG_real),32);
        bufp->chgIData(oldp+88,(vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out2_REG_imag),32);
        bufp->chgBit(oldp+89,(vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out_valid_REG));
        bufp->chgSData(oldp+90,(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt),10);
        bufp->chgIData(oldp+91,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_real),32);
        bufp->chgIData(oldp+92,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_imag),32);
        bufp->chgIData(oldp+93,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_1_real),32);
        bufp->chgIData(oldp+94,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_1_imag),32);
        bufp->chgIData(oldp+95,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_2_real),32);
        bufp->chgIData(oldp+96,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_2_imag),32);
        bufp->chgIData(oldp+97,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_3_real),32);
        bufp->chgIData(oldp+98,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_3_imag),32);
        bufp->chgIData(oldp+99,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_4_real),32);
        bufp->chgIData(oldp+100,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_4_imag),32);
        bufp->chgIData(oldp+101,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_5_real),32);
        bufp->chgIData(oldp+102,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_5_imag),32);
        bufp->chgIData(oldp+103,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_6_real),32);
        bufp->chgIData(oldp+104,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_6_imag),32);
        bufp->chgIData(oldp+105,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_7_real),32);
        bufp->chgIData(oldp+106,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_7_imag),32);
        bufp->chgIData(oldp+107,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_8_real),32);
        bufp->chgIData(oldp+108,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_8_imag),32);
        bufp->chgIData(oldp+109,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_9_real),32);
        bufp->chgIData(oldp+110,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_9_imag),32);
        bufp->chgIData(oldp+111,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_10_real),32);
        bufp->chgIData(oldp+112,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_10_imag),32);
        bufp->chgIData(oldp+113,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_11_real),32);
        bufp->chgIData(oldp+114,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_11_imag),32);
        bufp->chgIData(oldp+115,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_12_real),32);
        bufp->chgIData(oldp+116,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_12_imag),32);
        bufp->chgIData(oldp+117,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_13_real),32);
        bufp->chgIData(oldp+118,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_13_imag),32);
        bufp->chgIData(oldp+119,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_14_real),32);
        bufp->chgIData(oldp+120,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_14_imag),32);
        bufp->chgIData(oldp+121,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_15_real),32);
        bufp->chgIData(oldp+122,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_15_imag),32);
        bufp->chgIData(oldp+123,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_16_real),32);
        bufp->chgIData(oldp+124,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_16_imag),32);
        bufp->chgIData(oldp+125,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_17_real),32);
        bufp->chgIData(oldp+126,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_17_imag),32);
        bufp->chgIData(oldp+127,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_18_real),32);
        bufp->chgIData(oldp+128,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_18_imag),32);
        bufp->chgIData(oldp+129,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_19_real),32);
        bufp->chgIData(oldp+130,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_19_imag),32);
        bufp->chgIData(oldp+131,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_20_real),32);
        bufp->chgIData(oldp+132,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_20_imag),32);
        bufp->chgIData(oldp+133,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_21_real),32);
        bufp->chgIData(oldp+134,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_21_imag),32);
        bufp->chgIData(oldp+135,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_22_real),32);
        bufp->chgIData(oldp+136,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_22_imag),32);
        bufp->chgIData(oldp+137,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_23_real),32);
        bufp->chgIData(oldp+138,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_23_imag),32);
        bufp->chgIData(oldp+139,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_24_real),32);
        bufp->chgIData(oldp+140,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_24_imag),32);
        bufp->chgIData(oldp+141,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_25_real),32);
        bufp->chgIData(oldp+142,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_25_imag),32);
        bufp->chgIData(oldp+143,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_26_real),32);
        bufp->chgIData(oldp+144,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_26_imag),32);
        bufp->chgIData(oldp+145,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_27_real),32);
        bufp->chgIData(oldp+146,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_27_imag),32);
        bufp->chgIData(oldp+147,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_28_real),32);
        bufp->chgIData(oldp+148,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_28_imag),32);
        bufp->chgIData(oldp+149,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_29_real),32);
        bufp->chgIData(oldp+150,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_29_imag),32);
        bufp->chgIData(oldp+151,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_30_real),32);
        bufp->chgIData(oldp+152,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_30_imag),32);
        bufp->chgIData(oldp+153,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_31_real),32);
        bufp->chgIData(oldp+154,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_31_imag),32);
        bufp->chgIData(oldp+155,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_32_real),32);
        bufp->chgIData(oldp+156,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_32_imag),32);
        bufp->chgIData(oldp+157,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_33_real),32);
        bufp->chgIData(oldp+158,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_33_imag),32);
        bufp->chgIData(oldp+159,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_34_real),32);
        bufp->chgIData(oldp+160,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_34_imag),32);
        bufp->chgIData(oldp+161,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_35_real),32);
        bufp->chgIData(oldp+162,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_35_imag),32);
        bufp->chgIData(oldp+163,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_36_real),32);
        bufp->chgIData(oldp+164,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_36_imag),32);
        bufp->chgIData(oldp+165,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_37_real),32);
        bufp->chgIData(oldp+166,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_37_imag),32);
        bufp->chgIData(oldp+167,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_38_real),32);
        bufp->chgIData(oldp+168,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_38_imag),32);
        bufp->chgIData(oldp+169,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_39_real),32);
        bufp->chgIData(oldp+170,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_39_imag),32);
        bufp->chgIData(oldp+171,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_40_real),32);
        bufp->chgIData(oldp+172,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_40_imag),32);
        bufp->chgIData(oldp+173,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_41_real),32);
        bufp->chgIData(oldp+174,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_41_imag),32);
        bufp->chgIData(oldp+175,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_42_real),32);
        bufp->chgIData(oldp+176,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_42_imag),32);
        bufp->chgIData(oldp+177,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_43_real),32);
        bufp->chgIData(oldp+178,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_43_imag),32);
        bufp->chgIData(oldp+179,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_44_real),32);
        bufp->chgIData(oldp+180,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_44_imag),32);
        bufp->chgIData(oldp+181,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_45_real),32);
        bufp->chgIData(oldp+182,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_45_imag),32);
        bufp->chgIData(oldp+183,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_46_real),32);
        bufp->chgIData(oldp+184,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_46_imag),32);
        bufp->chgIData(oldp+185,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_47_real),32);
        bufp->chgIData(oldp+186,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_47_imag),32);
        bufp->chgIData(oldp+187,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_48_real),32);
        bufp->chgIData(oldp+188,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_48_imag),32);
        bufp->chgIData(oldp+189,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_49_real),32);
        bufp->chgIData(oldp+190,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_49_imag),32);
        bufp->chgIData(oldp+191,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_50_real),32);
        bufp->chgIData(oldp+192,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_50_imag),32);
        bufp->chgIData(oldp+193,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_51_real),32);
        bufp->chgIData(oldp+194,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_51_imag),32);
        bufp->chgIData(oldp+195,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_52_real),32);
        bufp->chgIData(oldp+196,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_52_imag),32);
        bufp->chgIData(oldp+197,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_53_real),32);
        bufp->chgIData(oldp+198,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_53_imag),32);
        bufp->chgIData(oldp+199,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_54_real),32);
        bufp->chgIData(oldp+200,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_54_imag),32);
        bufp->chgIData(oldp+201,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_55_real),32);
        bufp->chgIData(oldp+202,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_55_imag),32);
        bufp->chgIData(oldp+203,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_56_real),32);
        bufp->chgIData(oldp+204,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_56_imag),32);
        bufp->chgIData(oldp+205,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_57_real),32);
        bufp->chgIData(oldp+206,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_57_imag),32);
        bufp->chgIData(oldp+207,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_58_real),32);
        bufp->chgIData(oldp+208,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_58_imag),32);
        bufp->chgIData(oldp+209,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_59_real),32);
        bufp->chgIData(oldp+210,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_59_imag),32);
        bufp->chgIData(oldp+211,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_60_real),32);
        bufp->chgIData(oldp+212,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_60_imag),32);
        bufp->chgIData(oldp+213,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_61_real),32);
        bufp->chgIData(oldp+214,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_61_imag),32);
        bufp->chgIData(oldp+215,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_62_real),32);
        bufp->chgIData(oldp+216,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_62_imag),32);
        bufp->chgIData(oldp+217,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_63_real),32);
        bufp->chgIData(oldp+218,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_63_imag),32);
        bufp->chgIData(oldp+219,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_64_real),32);
        bufp->chgIData(oldp+220,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_64_imag),32);
        bufp->chgIData(oldp+221,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_65_real),32);
        bufp->chgIData(oldp+222,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_65_imag),32);
        bufp->chgIData(oldp+223,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_66_real),32);
        bufp->chgIData(oldp+224,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_66_imag),32);
        bufp->chgIData(oldp+225,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_67_real),32);
        bufp->chgIData(oldp+226,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_67_imag),32);
        bufp->chgIData(oldp+227,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_68_real),32);
        bufp->chgIData(oldp+228,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_68_imag),32);
        bufp->chgIData(oldp+229,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_69_real),32);
        bufp->chgIData(oldp+230,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_69_imag),32);
        bufp->chgIData(oldp+231,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_70_real),32);
        bufp->chgIData(oldp+232,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_70_imag),32);
        bufp->chgIData(oldp+233,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_71_real),32);
        bufp->chgIData(oldp+234,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_71_imag),32);
        bufp->chgIData(oldp+235,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_72_real),32);
        bufp->chgIData(oldp+236,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_72_imag),32);
        bufp->chgIData(oldp+237,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_73_real),32);
        bufp->chgIData(oldp+238,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_73_imag),32);
        bufp->chgIData(oldp+239,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_74_real),32);
        bufp->chgIData(oldp+240,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_74_imag),32);
        bufp->chgIData(oldp+241,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_75_real),32);
        bufp->chgIData(oldp+242,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_75_imag),32);
        bufp->chgIData(oldp+243,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_76_real),32);
        bufp->chgIData(oldp+244,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_76_imag),32);
        bufp->chgIData(oldp+245,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_77_real),32);
        bufp->chgIData(oldp+246,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_77_imag),32);
        bufp->chgIData(oldp+247,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_78_real),32);
        bufp->chgIData(oldp+248,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_78_imag),32);
        bufp->chgIData(oldp+249,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_79_real),32);
        bufp->chgIData(oldp+250,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_79_imag),32);
        bufp->chgIData(oldp+251,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_80_real),32);
        bufp->chgIData(oldp+252,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_80_imag),32);
        bufp->chgIData(oldp+253,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_81_real),32);
        bufp->chgIData(oldp+254,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_81_imag),32);
        bufp->chgIData(oldp+255,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_82_real),32);
        bufp->chgIData(oldp+256,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_82_imag),32);
        bufp->chgIData(oldp+257,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_83_real),32);
        bufp->chgIData(oldp+258,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_83_imag),32);
        bufp->chgIData(oldp+259,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_84_real),32);
        bufp->chgIData(oldp+260,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_84_imag),32);
        bufp->chgIData(oldp+261,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_85_real),32);
        bufp->chgIData(oldp+262,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_85_imag),32);
        bufp->chgIData(oldp+263,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_86_real),32);
        bufp->chgIData(oldp+264,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_86_imag),32);
        bufp->chgIData(oldp+265,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_87_real),32);
        bufp->chgIData(oldp+266,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_87_imag),32);
        bufp->chgIData(oldp+267,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_88_real),32);
        bufp->chgIData(oldp+268,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_88_imag),32);
        bufp->chgIData(oldp+269,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_89_real),32);
        bufp->chgIData(oldp+270,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_89_imag),32);
        bufp->chgIData(oldp+271,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_90_real),32);
        bufp->chgIData(oldp+272,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_90_imag),32);
        bufp->chgIData(oldp+273,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_91_real),32);
        bufp->chgIData(oldp+274,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_91_imag),32);
        bufp->chgIData(oldp+275,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_92_real),32);
        bufp->chgIData(oldp+276,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_92_imag),32);
        bufp->chgIData(oldp+277,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_93_real),32);
        bufp->chgIData(oldp+278,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_93_imag),32);
        bufp->chgIData(oldp+279,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_94_real),32);
        bufp->chgIData(oldp+280,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_94_imag),32);
        bufp->chgIData(oldp+281,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_95_real),32);
        bufp->chgIData(oldp+282,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_95_imag),32);
        bufp->chgIData(oldp+283,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_96_real),32);
        bufp->chgIData(oldp+284,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_96_imag),32);
        bufp->chgIData(oldp+285,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_97_real),32);
        bufp->chgIData(oldp+286,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_97_imag),32);
        bufp->chgIData(oldp+287,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_98_real),32);
        bufp->chgIData(oldp+288,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_98_imag),32);
        bufp->chgIData(oldp+289,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_99_real),32);
        bufp->chgIData(oldp+290,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_99_imag),32);
        bufp->chgIData(oldp+291,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_100_real),32);
        bufp->chgIData(oldp+292,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_100_imag),32);
        bufp->chgIData(oldp+293,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_101_real),32);
        bufp->chgIData(oldp+294,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_101_imag),32);
        bufp->chgIData(oldp+295,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_102_real),32);
        bufp->chgIData(oldp+296,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_102_imag),32);
        bufp->chgIData(oldp+297,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_103_real),32);
        bufp->chgIData(oldp+298,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_103_imag),32);
        bufp->chgIData(oldp+299,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_104_real),32);
        bufp->chgIData(oldp+300,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_104_imag),32);
        bufp->chgIData(oldp+301,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_105_real),32);
        bufp->chgIData(oldp+302,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_105_imag),32);
        bufp->chgIData(oldp+303,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_106_real),32);
        bufp->chgIData(oldp+304,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_106_imag),32);
        bufp->chgIData(oldp+305,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_107_real),32);
        bufp->chgIData(oldp+306,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_107_imag),32);
        bufp->chgIData(oldp+307,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_108_real),32);
        bufp->chgIData(oldp+308,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_108_imag),32);
        bufp->chgIData(oldp+309,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_109_real),32);
        bufp->chgIData(oldp+310,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_109_imag),32);
        bufp->chgIData(oldp+311,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_110_real),32);
        bufp->chgIData(oldp+312,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_110_imag),32);
        bufp->chgIData(oldp+313,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_111_real),32);
        bufp->chgIData(oldp+314,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_111_imag),32);
        bufp->chgIData(oldp+315,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_112_real),32);
        bufp->chgIData(oldp+316,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_112_imag),32);
        bufp->chgIData(oldp+317,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_113_real),32);
        bufp->chgIData(oldp+318,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_113_imag),32);
        bufp->chgIData(oldp+319,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_114_real),32);
        bufp->chgIData(oldp+320,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_114_imag),32);
        bufp->chgIData(oldp+321,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_115_real),32);
        bufp->chgIData(oldp+322,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_115_imag),32);
        bufp->chgIData(oldp+323,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_116_real),32);
        bufp->chgIData(oldp+324,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_116_imag),32);
        bufp->chgIData(oldp+325,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_117_real),32);
        bufp->chgIData(oldp+326,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_117_imag),32);
        bufp->chgIData(oldp+327,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_118_real),32);
        bufp->chgIData(oldp+328,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_118_imag),32);
        bufp->chgIData(oldp+329,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_119_real),32);
        bufp->chgIData(oldp+330,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_119_imag),32);
        bufp->chgIData(oldp+331,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_120_real),32);
        bufp->chgIData(oldp+332,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_120_imag),32);
        bufp->chgIData(oldp+333,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_121_real),32);
        bufp->chgIData(oldp+334,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_121_imag),32);
        bufp->chgIData(oldp+335,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_122_real),32);
        bufp->chgIData(oldp+336,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_122_imag),32);
        bufp->chgIData(oldp+337,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_123_real),32);
        bufp->chgIData(oldp+338,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_123_imag),32);
        bufp->chgIData(oldp+339,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_124_real),32);
        bufp->chgIData(oldp+340,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_124_imag),32);
        bufp->chgIData(oldp+341,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_125_real),32);
        bufp->chgIData(oldp+342,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_125_imag),32);
        bufp->chgIData(oldp+343,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_126_real),32);
        bufp->chgIData(oldp+344,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_126_imag),32);
        bufp->chgIData(oldp+345,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_127_real),32);
        bufp->chgIData(oldp+346,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_127_imag),32);
        bufp->chgIData(oldp+347,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_128_real),32);
        bufp->chgIData(oldp+348,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_128_imag),32);
        bufp->chgIData(oldp+349,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_129_real),32);
        bufp->chgIData(oldp+350,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_129_imag),32);
        bufp->chgIData(oldp+351,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_130_real),32);
        bufp->chgIData(oldp+352,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_130_imag),32);
        bufp->chgIData(oldp+353,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_131_real),32);
        bufp->chgIData(oldp+354,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_131_imag),32);
        bufp->chgIData(oldp+355,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_132_real),32);
        bufp->chgIData(oldp+356,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_132_imag),32);
        bufp->chgIData(oldp+357,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_133_real),32);
        bufp->chgIData(oldp+358,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_133_imag),32);
        bufp->chgIData(oldp+359,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_134_real),32);
        bufp->chgIData(oldp+360,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_134_imag),32);
        bufp->chgIData(oldp+361,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_135_real),32);
        bufp->chgIData(oldp+362,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_135_imag),32);
        bufp->chgIData(oldp+363,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_136_real),32);
        bufp->chgIData(oldp+364,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_136_imag),32);
        bufp->chgIData(oldp+365,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_137_real),32);
        bufp->chgIData(oldp+366,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_137_imag),32);
        bufp->chgIData(oldp+367,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_138_real),32);
        bufp->chgIData(oldp+368,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_138_imag),32);
        bufp->chgIData(oldp+369,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_139_real),32);
        bufp->chgIData(oldp+370,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_139_imag),32);
        bufp->chgIData(oldp+371,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_140_real),32);
        bufp->chgIData(oldp+372,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_140_imag),32);
        bufp->chgIData(oldp+373,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_141_real),32);
        bufp->chgIData(oldp+374,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_141_imag),32);
        bufp->chgIData(oldp+375,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_142_real),32);
        bufp->chgIData(oldp+376,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_142_imag),32);
        bufp->chgIData(oldp+377,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_143_real),32);
        bufp->chgIData(oldp+378,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_143_imag),32);
        bufp->chgIData(oldp+379,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_144_real),32);
        bufp->chgIData(oldp+380,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_144_imag),32);
        bufp->chgIData(oldp+381,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_145_real),32);
        bufp->chgIData(oldp+382,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_145_imag),32);
        bufp->chgIData(oldp+383,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_146_real),32);
        bufp->chgIData(oldp+384,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_146_imag),32);
        bufp->chgIData(oldp+385,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_147_real),32);
        bufp->chgIData(oldp+386,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_147_imag),32);
        bufp->chgIData(oldp+387,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_148_real),32);
        bufp->chgIData(oldp+388,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_148_imag),32);
        bufp->chgIData(oldp+389,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_149_real),32);
        bufp->chgIData(oldp+390,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_149_imag),32);
        bufp->chgIData(oldp+391,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_150_real),32);
        bufp->chgIData(oldp+392,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_150_imag),32);
        bufp->chgIData(oldp+393,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_151_real),32);
        bufp->chgIData(oldp+394,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_151_imag),32);
        bufp->chgIData(oldp+395,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_152_real),32);
        bufp->chgIData(oldp+396,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_152_imag),32);
        bufp->chgIData(oldp+397,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_153_real),32);
        bufp->chgIData(oldp+398,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_153_imag),32);
        bufp->chgIData(oldp+399,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_154_real),32);
        bufp->chgIData(oldp+400,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_154_imag),32);
        bufp->chgIData(oldp+401,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_155_real),32);
        bufp->chgIData(oldp+402,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_155_imag),32);
        bufp->chgIData(oldp+403,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_156_real),32);
        bufp->chgIData(oldp+404,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_156_imag),32);
        bufp->chgIData(oldp+405,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_157_real),32);
        bufp->chgIData(oldp+406,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_157_imag),32);
        bufp->chgIData(oldp+407,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_158_real),32);
        bufp->chgIData(oldp+408,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_158_imag),32);
        bufp->chgIData(oldp+409,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_159_real),32);
        bufp->chgIData(oldp+410,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_159_imag),32);
        bufp->chgIData(oldp+411,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_160_real),32);
        bufp->chgIData(oldp+412,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_160_imag),32);
        bufp->chgIData(oldp+413,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_161_real),32);
        bufp->chgIData(oldp+414,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_161_imag),32);
        bufp->chgIData(oldp+415,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_162_real),32);
        bufp->chgIData(oldp+416,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_162_imag),32);
        bufp->chgIData(oldp+417,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_163_real),32);
        bufp->chgIData(oldp+418,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_163_imag),32);
        bufp->chgIData(oldp+419,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_164_real),32);
        bufp->chgIData(oldp+420,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_164_imag),32);
        bufp->chgIData(oldp+421,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_165_real),32);
        bufp->chgIData(oldp+422,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_165_imag),32);
        bufp->chgIData(oldp+423,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_166_real),32);
        bufp->chgIData(oldp+424,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_166_imag),32);
        bufp->chgIData(oldp+425,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_167_real),32);
        bufp->chgIData(oldp+426,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_167_imag),32);
        bufp->chgIData(oldp+427,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_168_real),32);
        bufp->chgIData(oldp+428,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_168_imag),32);
        bufp->chgIData(oldp+429,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_169_real),32);
        bufp->chgIData(oldp+430,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_169_imag),32);
        bufp->chgIData(oldp+431,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_170_real),32);
        bufp->chgIData(oldp+432,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_170_imag),32);
        bufp->chgIData(oldp+433,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_171_real),32);
        bufp->chgIData(oldp+434,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_171_imag),32);
        bufp->chgIData(oldp+435,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_172_real),32);
        bufp->chgIData(oldp+436,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_172_imag),32);
        bufp->chgIData(oldp+437,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_173_real),32);
        bufp->chgIData(oldp+438,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_173_imag),32);
        bufp->chgIData(oldp+439,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_174_real),32);
        bufp->chgIData(oldp+440,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_174_imag),32);
        bufp->chgIData(oldp+441,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_175_real),32);
        bufp->chgIData(oldp+442,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_175_imag),32);
        bufp->chgIData(oldp+443,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_176_real),32);
        bufp->chgIData(oldp+444,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_176_imag),32);
        bufp->chgIData(oldp+445,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_177_real),32);
        bufp->chgIData(oldp+446,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_177_imag),32);
        bufp->chgIData(oldp+447,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_178_real),32);
        bufp->chgIData(oldp+448,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_178_imag),32);
        bufp->chgIData(oldp+449,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_179_real),32);
        bufp->chgIData(oldp+450,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_179_imag),32);
        bufp->chgIData(oldp+451,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_180_real),32);
        bufp->chgIData(oldp+452,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_180_imag),32);
        bufp->chgIData(oldp+453,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_181_real),32);
        bufp->chgIData(oldp+454,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_181_imag),32);
        bufp->chgIData(oldp+455,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_182_real),32);
        bufp->chgIData(oldp+456,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_182_imag),32);
        bufp->chgIData(oldp+457,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_183_real),32);
        bufp->chgIData(oldp+458,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_183_imag),32);
        bufp->chgIData(oldp+459,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_184_real),32);
        bufp->chgIData(oldp+460,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_184_imag),32);
        bufp->chgIData(oldp+461,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_185_real),32);
        bufp->chgIData(oldp+462,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_185_imag),32);
        bufp->chgIData(oldp+463,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_186_real),32);
        bufp->chgIData(oldp+464,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_186_imag),32);
        bufp->chgIData(oldp+465,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_187_real),32);
        bufp->chgIData(oldp+466,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_187_imag),32);
        bufp->chgIData(oldp+467,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_188_real),32);
        bufp->chgIData(oldp+468,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_188_imag),32);
        bufp->chgIData(oldp+469,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_189_real),32);
        bufp->chgIData(oldp+470,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_189_imag),32);
        bufp->chgIData(oldp+471,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_190_real),32);
        bufp->chgIData(oldp+472,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_190_imag),32);
        bufp->chgIData(oldp+473,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_191_real),32);
        bufp->chgIData(oldp+474,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_191_imag),32);
        bufp->chgIData(oldp+475,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_192_real),32);
        bufp->chgIData(oldp+476,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_192_imag),32);
        bufp->chgIData(oldp+477,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_193_real),32);
        bufp->chgIData(oldp+478,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_193_imag),32);
        bufp->chgIData(oldp+479,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_194_real),32);
        bufp->chgIData(oldp+480,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_194_imag),32);
        bufp->chgIData(oldp+481,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_195_real),32);
        bufp->chgIData(oldp+482,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_195_imag),32);
        bufp->chgIData(oldp+483,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_196_real),32);
        bufp->chgIData(oldp+484,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_196_imag),32);
        bufp->chgIData(oldp+485,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_197_real),32);
        bufp->chgIData(oldp+486,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_197_imag),32);
        bufp->chgIData(oldp+487,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_198_real),32);
        bufp->chgIData(oldp+488,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_198_imag),32);
        bufp->chgIData(oldp+489,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_199_real),32);
        bufp->chgIData(oldp+490,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_199_imag),32);
        bufp->chgIData(oldp+491,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_200_real),32);
        bufp->chgIData(oldp+492,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_200_imag),32);
        bufp->chgIData(oldp+493,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_201_real),32);
        bufp->chgIData(oldp+494,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_201_imag),32);
        bufp->chgIData(oldp+495,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_202_real),32);
        bufp->chgIData(oldp+496,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_202_imag),32);
        bufp->chgIData(oldp+497,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_203_real),32);
        bufp->chgIData(oldp+498,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_203_imag),32);
        bufp->chgIData(oldp+499,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_204_real),32);
        bufp->chgIData(oldp+500,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_204_imag),32);
        bufp->chgIData(oldp+501,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_205_real),32);
        bufp->chgIData(oldp+502,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_205_imag),32);
        bufp->chgIData(oldp+503,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_206_real),32);
        bufp->chgIData(oldp+504,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_206_imag),32);
        bufp->chgIData(oldp+505,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_207_real),32);
        bufp->chgIData(oldp+506,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_207_imag),32);
        bufp->chgIData(oldp+507,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_208_real),32);
        bufp->chgIData(oldp+508,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_208_imag),32);
        bufp->chgIData(oldp+509,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_209_real),32);
        bufp->chgIData(oldp+510,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_209_imag),32);
        bufp->chgIData(oldp+511,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_210_real),32);
        bufp->chgIData(oldp+512,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_210_imag),32);
        bufp->chgIData(oldp+513,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_211_real),32);
        bufp->chgIData(oldp+514,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_211_imag),32);
        bufp->chgIData(oldp+515,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_212_real),32);
        bufp->chgIData(oldp+516,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_212_imag),32);
        bufp->chgIData(oldp+517,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_213_real),32);
        bufp->chgIData(oldp+518,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_213_imag),32);
        bufp->chgIData(oldp+519,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_214_real),32);
        bufp->chgIData(oldp+520,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_214_imag),32);
        bufp->chgIData(oldp+521,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_215_real),32);
        bufp->chgIData(oldp+522,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_215_imag),32);
        bufp->chgIData(oldp+523,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_216_real),32);
        bufp->chgIData(oldp+524,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_216_imag),32);
        bufp->chgIData(oldp+525,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_217_real),32);
        bufp->chgIData(oldp+526,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_217_imag),32);
        bufp->chgIData(oldp+527,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_218_real),32);
        bufp->chgIData(oldp+528,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_218_imag),32);
        bufp->chgIData(oldp+529,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_219_real),32);
        bufp->chgIData(oldp+530,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_219_imag),32);
        bufp->chgIData(oldp+531,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_220_real),32);
        bufp->chgIData(oldp+532,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_220_imag),32);
        bufp->chgIData(oldp+533,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_221_real),32);
        bufp->chgIData(oldp+534,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_221_imag),32);
        bufp->chgIData(oldp+535,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_222_real),32);
        bufp->chgIData(oldp+536,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_222_imag),32);
        bufp->chgIData(oldp+537,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_223_real),32);
        bufp->chgIData(oldp+538,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_223_imag),32);
        bufp->chgIData(oldp+539,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_224_real),32);
        bufp->chgIData(oldp+540,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_224_imag),32);
        bufp->chgIData(oldp+541,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_225_real),32);
        bufp->chgIData(oldp+542,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_225_imag),32);
        bufp->chgIData(oldp+543,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_226_real),32);
        bufp->chgIData(oldp+544,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_226_imag),32);
        bufp->chgIData(oldp+545,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_227_real),32);
        bufp->chgIData(oldp+546,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_227_imag),32);
        bufp->chgIData(oldp+547,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_228_real),32);
        bufp->chgIData(oldp+548,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_228_imag),32);
        bufp->chgIData(oldp+549,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_229_real),32);
        bufp->chgIData(oldp+550,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_229_imag),32);
        bufp->chgIData(oldp+551,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_230_real),32);
        bufp->chgIData(oldp+552,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_230_imag),32);
        bufp->chgIData(oldp+553,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_231_real),32);
        bufp->chgIData(oldp+554,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_231_imag),32);
        bufp->chgIData(oldp+555,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_232_real),32);
        bufp->chgIData(oldp+556,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_232_imag),32);
        bufp->chgIData(oldp+557,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_233_real),32);
        bufp->chgIData(oldp+558,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_233_imag),32);
        bufp->chgIData(oldp+559,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_234_real),32);
        bufp->chgIData(oldp+560,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_234_imag),32);
        bufp->chgIData(oldp+561,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_235_real),32);
        bufp->chgIData(oldp+562,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_235_imag),32);
        bufp->chgIData(oldp+563,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_236_real),32);
        bufp->chgIData(oldp+564,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_236_imag),32);
        bufp->chgIData(oldp+565,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_237_real),32);
        bufp->chgIData(oldp+566,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_237_imag),32);
        bufp->chgIData(oldp+567,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_238_real),32);
        bufp->chgIData(oldp+568,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_238_imag),32);
        bufp->chgIData(oldp+569,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_239_real),32);
        bufp->chgIData(oldp+570,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_239_imag),32);
        bufp->chgIData(oldp+571,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_240_real),32);
        bufp->chgIData(oldp+572,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_240_imag),32);
        bufp->chgIData(oldp+573,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_241_real),32);
        bufp->chgIData(oldp+574,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_241_imag),32);
        bufp->chgIData(oldp+575,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_242_real),32);
        bufp->chgIData(oldp+576,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_242_imag),32);
        bufp->chgIData(oldp+577,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_243_real),32);
        bufp->chgIData(oldp+578,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_243_imag),32);
        bufp->chgIData(oldp+579,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_244_real),32);
        bufp->chgIData(oldp+580,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_244_imag),32);
        bufp->chgIData(oldp+581,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_245_real),32);
        bufp->chgIData(oldp+582,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_245_imag),32);
        bufp->chgIData(oldp+583,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_246_real),32);
        bufp->chgIData(oldp+584,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_246_imag),32);
        bufp->chgIData(oldp+585,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_247_real),32);
        bufp->chgIData(oldp+586,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_247_imag),32);
        bufp->chgIData(oldp+587,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_248_real),32);
        bufp->chgIData(oldp+588,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_248_imag),32);
        bufp->chgIData(oldp+589,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_249_real),32);
        bufp->chgIData(oldp+590,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_249_imag),32);
        bufp->chgIData(oldp+591,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_250_real),32);
        bufp->chgIData(oldp+592,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_250_imag),32);
        bufp->chgIData(oldp+593,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_251_real),32);
        bufp->chgIData(oldp+594,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_251_imag),32);
        bufp->chgIData(oldp+595,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_252_real),32);
        bufp->chgIData(oldp+596,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_252_imag),32);
        bufp->chgIData(oldp+597,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_253_real),32);
        bufp->chgIData(oldp+598,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_253_imag),32);
        bufp->chgIData(oldp+599,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_254_real),32);
        bufp->chgIData(oldp+600,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_254_imag),32);
        bufp->chgIData(oldp+601,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_real),32);
        bufp->chgIData(oldp+602,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_imag),32);
        bufp->chgIData(oldp+603,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_256_real),32);
        bufp->chgIData(oldp+604,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_256_imag),32);
        bufp->chgIData(oldp+605,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_257_real),32);
        bufp->chgIData(oldp+606,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_257_imag),32);
        bufp->chgIData(oldp+607,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_258_real),32);
        bufp->chgIData(oldp+608,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_258_imag),32);
        bufp->chgIData(oldp+609,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_259_real),32);
        bufp->chgIData(oldp+610,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_259_imag),32);
        bufp->chgIData(oldp+611,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_260_real),32);
        bufp->chgIData(oldp+612,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_260_imag),32);
        bufp->chgIData(oldp+613,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_261_real),32);
        bufp->chgIData(oldp+614,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_261_imag),32);
        bufp->chgIData(oldp+615,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_262_real),32);
        bufp->chgIData(oldp+616,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_262_imag),32);
        bufp->chgIData(oldp+617,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_263_real),32);
        bufp->chgIData(oldp+618,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_263_imag),32);
        bufp->chgIData(oldp+619,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_264_real),32);
        bufp->chgIData(oldp+620,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_264_imag),32);
        bufp->chgIData(oldp+621,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_265_real),32);
        bufp->chgIData(oldp+622,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_265_imag),32);
        bufp->chgIData(oldp+623,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_266_real),32);
        bufp->chgIData(oldp+624,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_266_imag),32);
        bufp->chgIData(oldp+625,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_267_real),32);
        bufp->chgIData(oldp+626,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_267_imag),32);
        bufp->chgIData(oldp+627,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_268_real),32);
        bufp->chgIData(oldp+628,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_268_imag),32);
        bufp->chgIData(oldp+629,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_269_real),32);
        bufp->chgIData(oldp+630,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_269_imag),32);
        bufp->chgIData(oldp+631,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_270_real),32);
        bufp->chgIData(oldp+632,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_270_imag),32);
        bufp->chgIData(oldp+633,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_271_real),32);
        bufp->chgIData(oldp+634,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_271_imag),32);
        bufp->chgIData(oldp+635,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_272_real),32);
        bufp->chgIData(oldp+636,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_272_imag),32);
        bufp->chgIData(oldp+637,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_273_real),32);
        bufp->chgIData(oldp+638,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_273_imag),32);
        bufp->chgIData(oldp+639,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_274_real),32);
        bufp->chgIData(oldp+640,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_274_imag),32);
        bufp->chgIData(oldp+641,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_275_real),32);
        bufp->chgIData(oldp+642,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_275_imag),32);
        bufp->chgIData(oldp+643,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_276_real),32);
        bufp->chgIData(oldp+644,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_276_imag),32);
        bufp->chgIData(oldp+645,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_277_real),32);
        bufp->chgIData(oldp+646,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_277_imag),32);
        bufp->chgIData(oldp+647,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_278_real),32);
        bufp->chgIData(oldp+648,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_278_imag),32);
        bufp->chgIData(oldp+649,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_279_real),32);
        bufp->chgIData(oldp+650,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_279_imag),32);
        bufp->chgIData(oldp+651,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_280_real),32);
        bufp->chgIData(oldp+652,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_280_imag),32);
        bufp->chgIData(oldp+653,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_281_real),32);
        bufp->chgIData(oldp+654,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_281_imag),32);
        bufp->chgIData(oldp+655,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_282_real),32);
        bufp->chgIData(oldp+656,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_282_imag),32);
        bufp->chgIData(oldp+657,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_283_real),32);
        bufp->chgIData(oldp+658,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_283_imag),32);
        bufp->chgIData(oldp+659,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_284_real),32);
        bufp->chgIData(oldp+660,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_284_imag),32);
        bufp->chgIData(oldp+661,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_285_real),32);
        bufp->chgIData(oldp+662,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_285_imag),32);
        bufp->chgIData(oldp+663,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_286_real),32);
        bufp->chgIData(oldp+664,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_286_imag),32);
        bufp->chgIData(oldp+665,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_287_real),32);
        bufp->chgIData(oldp+666,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_287_imag),32);
        bufp->chgIData(oldp+667,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_288_real),32);
        bufp->chgIData(oldp+668,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_288_imag),32);
        bufp->chgIData(oldp+669,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_289_real),32);
        bufp->chgIData(oldp+670,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_289_imag),32);
        bufp->chgIData(oldp+671,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_290_real),32);
        bufp->chgIData(oldp+672,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_290_imag),32);
        bufp->chgIData(oldp+673,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_291_real),32);
        bufp->chgIData(oldp+674,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_291_imag),32);
        bufp->chgIData(oldp+675,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_292_real),32);
        bufp->chgIData(oldp+676,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_292_imag),32);
        bufp->chgIData(oldp+677,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_293_real),32);
        bufp->chgIData(oldp+678,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_293_imag),32);
        bufp->chgIData(oldp+679,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_294_real),32);
        bufp->chgIData(oldp+680,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_294_imag),32);
        bufp->chgIData(oldp+681,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_295_real),32);
        bufp->chgIData(oldp+682,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_295_imag),32);
        bufp->chgIData(oldp+683,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_296_real),32);
        bufp->chgIData(oldp+684,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_296_imag),32);
        bufp->chgIData(oldp+685,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_297_real),32);
        bufp->chgIData(oldp+686,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_297_imag),32);
        bufp->chgIData(oldp+687,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_298_real),32);
        bufp->chgIData(oldp+688,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_298_imag),32);
        bufp->chgIData(oldp+689,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_299_real),32);
        bufp->chgIData(oldp+690,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_299_imag),32);
        bufp->chgIData(oldp+691,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_300_real),32);
        bufp->chgIData(oldp+692,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_300_imag),32);
        bufp->chgIData(oldp+693,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_301_real),32);
        bufp->chgIData(oldp+694,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_301_imag),32);
        bufp->chgIData(oldp+695,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_302_real),32);
        bufp->chgIData(oldp+696,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_302_imag),32);
        bufp->chgIData(oldp+697,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_303_real),32);
        bufp->chgIData(oldp+698,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_303_imag),32);
        bufp->chgIData(oldp+699,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_304_real),32);
        bufp->chgIData(oldp+700,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_304_imag),32);
        bufp->chgIData(oldp+701,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_305_real),32);
        bufp->chgIData(oldp+702,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_305_imag),32);
        bufp->chgIData(oldp+703,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_306_real),32);
        bufp->chgIData(oldp+704,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_306_imag),32);
        bufp->chgIData(oldp+705,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_307_real),32);
        bufp->chgIData(oldp+706,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_307_imag),32);
        bufp->chgIData(oldp+707,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_308_real),32);
        bufp->chgIData(oldp+708,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_308_imag),32);
        bufp->chgIData(oldp+709,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_309_real),32);
        bufp->chgIData(oldp+710,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_309_imag),32);
        bufp->chgIData(oldp+711,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_310_real),32);
        bufp->chgIData(oldp+712,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_310_imag),32);
        bufp->chgIData(oldp+713,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_311_real),32);
        bufp->chgIData(oldp+714,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_311_imag),32);
        bufp->chgIData(oldp+715,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_312_real),32);
        bufp->chgIData(oldp+716,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_312_imag),32);
        bufp->chgIData(oldp+717,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_313_real),32);
        bufp->chgIData(oldp+718,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_313_imag),32);
        bufp->chgIData(oldp+719,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_314_real),32);
        bufp->chgIData(oldp+720,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_314_imag),32);
        bufp->chgIData(oldp+721,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_315_real),32);
        bufp->chgIData(oldp+722,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_315_imag),32);
        bufp->chgIData(oldp+723,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_316_real),32);
        bufp->chgIData(oldp+724,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_316_imag),32);
        bufp->chgIData(oldp+725,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_317_real),32);
        bufp->chgIData(oldp+726,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_317_imag),32);
        bufp->chgIData(oldp+727,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_318_real),32);
        bufp->chgIData(oldp+728,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_318_imag),32);
        bufp->chgIData(oldp+729,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_319_real),32);
        bufp->chgIData(oldp+730,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_319_imag),32);
        bufp->chgIData(oldp+731,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_320_real),32);
        bufp->chgIData(oldp+732,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_320_imag),32);
        bufp->chgIData(oldp+733,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_321_real),32);
        bufp->chgIData(oldp+734,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_321_imag),32);
        bufp->chgIData(oldp+735,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_322_real),32);
        bufp->chgIData(oldp+736,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_322_imag),32);
        bufp->chgIData(oldp+737,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_323_real),32);
        bufp->chgIData(oldp+738,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_323_imag),32);
        bufp->chgIData(oldp+739,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_324_real),32);
        bufp->chgIData(oldp+740,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_324_imag),32);
        bufp->chgIData(oldp+741,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_325_real),32);
        bufp->chgIData(oldp+742,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_325_imag),32);
        bufp->chgIData(oldp+743,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_326_real),32);
        bufp->chgIData(oldp+744,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_326_imag),32);
        bufp->chgIData(oldp+745,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_327_real),32);
        bufp->chgIData(oldp+746,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_327_imag),32);
        bufp->chgIData(oldp+747,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_328_real),32);
        bufp->chgIData(oldp+748,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_328_imag),32);
        bufp->chgIData(oldp+749,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_329_real),32);
        bufp->chgIData(oldp+750,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_329_imag),32);
        bufp->chgIData(oldp+751,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_330_real),32);
        bufp->chgIData(oldp+752,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_330_imag),32);
        bufp->chgIData(oldp+753,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_331_real),32);
        bufp->chgIData(oldp+754,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_331_imag),32);
        bufp->chgIData(oldp+755,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_332_real),32);
        bufp->chgIData(oldp+756,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_332_imag),32);
        bufp->chgIData(oldp+757,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_333_real),32);
        bufp->chgIData(oldp+758,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_333_imag),32);
        bufp->chgIData(oldp+759,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_334_real),32);
        bufp->chgIData(oldp+760,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_334_imag),32);
        bufp->chgIData(oldp+761,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_335_real),32);
        bufp->chgIData(oldp+762,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_335_imag),32);
        bufp->chgIData(oldp+763,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_336_real),32);
        bufp->chgIData(oldp+764,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_336_imag),32);
        bufp->chgIData(oldp+765,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_337_real),32);
        bufp->chgIData(oldp+766,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_337_imag),32);
        bufp->chgIData(oldp+767,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_338_real),32);
        bufp->chgIData(oldp+768,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_338_imag),32);
        bufp->chgIData(oldp+769,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_339_real),32);
        bufp->chgIData(oldp+770,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_339_imag),32);
        bufp->chgIData(oldp+771,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_340_real),32);
        bufp->chgIData(oldp+772,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_340_imag),32);
        bufp->chgIData(oldp+773,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_341_real),32);
        bufp->chgIData(oldp+774,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_341_imag),32);
        bufp->chgIData(oldp+775,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_342_real),32);
        bufp->chgIData(oldp+776,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_342_imag),32);
        bufp->chgIData(oldp+777,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_343_real),32);
        bufp->chgIData(oldp+778,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_343_imag),32);
        bufp->chgIData(oldp+779,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_344_real),32);
        bufp->chgIData(oldp+780,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_344_imag),32);
        bufp->chgIData(oldp+781,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_345_real),32);
        bufp->chgIData(oldp+782,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_345_imag),32);
        bufp->chgIData(oldp+783,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_346_real),32);
        bufp->chgIData(oldp+784,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_346_imag),32);
        bufp->chgIData(oldp+785,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_347_real),32);
        bufp->chgIData(oldp+786,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_347_imag),32);
        bufp->chgIData(oldp+787,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_348_real),32);
        bufp->chgIData(oldp+788,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_348_imag),32);
        bufp->chgIData(oldp+789,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_349_real),32);
        bufp->chgIData(oldp+790,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_349_imag),32);
        bufp->chgIData(oldp+791,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_350_real),32);
        bufp->chgIData(oldp+792,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_350_imag),32);
        bufp->chgIData(oldp+793,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_351_real),32);
        bufp->chgIData(oldp+794,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_351_imag),32);
        bufp->chgIData(oldp+795,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_352_real),32);
        bufp->chgIData(oldp+796,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_352_imag),32);
        bufp->chgIData(oldp+797,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_353_real),32);
        bufp->chgIData(oldp+798,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_353_imag),32);
        bufp->chgIData(oldp+799,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_354_real),32);
        bufp->chgIData(oldp+800,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_354_imag),32);
        bufp->chgIData(oldp+801,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_355_real),32);
        bufp->chgIData(oldp+802,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_355_imag),32);
        bufp->chgIData(oldp+803,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_356_real),32);
        bufp->chgIData(oldp+804,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_356_imag),32);
        bufp->chgIData(oldp+805,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_357_real),32);
        bufp->chgIData(oldp+806,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_357_imag),32);
        bufp->chgIData(oldp+807,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_358_real),32);
        bufp->chgIData(oldp+808,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_358_imag),32);
        bufp->chgIData(oldp+809,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_359_real),32);
        bufp->chgIData(oldp+810,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_359_imag),32);
        bufp->chgIData(oldp+811,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_360_real),32);
        bufp->chgIData(oldp+812,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_360_imag),32);
        bufp->chgIData(oldp+813,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_361_real),32);
        bufp->chgIData(oldp+814,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_361_imag),32);
        bufp->chgIData(oldp+815,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_362_real),32);
        bufp->chgIData(oldp+816,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_362_imag),32);
        bufp->chgIData(oldp+817,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_363_real),32);
        bufp->chgIData(oldp+818,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_363_imag),32);
        bufp->chgIData(oldp+819,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_364_real),32);
        bufp->chgIData(oldp+820,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_364_imag),32);
        bufp->chgIData(oldp+821,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_365_real),32);
        bufp->chgIData(oldp+822,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_365_imag),32);
        bufp->chgIData(oldp+823,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_366_real),32);
        bufp->chgIData(oldp+824,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_366_imag),32);
        bufp->chgIData(oldp+825,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_367_real),32);
        bufp->chgIData(oldp+826,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_367_imag),32);
        bufp->chgIData(oldp+827,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_368_real),32);
        bufp->chgIData(oldp+828,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_368_imag),32);
        bufp->chgIData(oldp+829,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_369_real),32);
        bufp->chgIData(oldp+830,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_369_imag),32);
        bufp->chgIData(oldp+831,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_370_real),32);
        bufp->chgIData(oldp+832,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_370_imag),32);
        bufp->chgIData(oldp+833,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_371_real),32);
        bufp->chgIData(oldp+834,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_371_imag),32);
        bufp->chgIData(oldp+835,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_372_real),32);
        bufp->chgIData(oldp+836,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_372_imag),32);
        bufp->chgIData(oldp+837,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_373_real),32);
        bufp->chgIData(oldp+838,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_373_imag),32);
        bufp->chgIData(oldp+839,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_374_real),32);
        bufp->chgIData(oldp+840,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_374_imag),32);
        bufp->chgIData(oldp+841,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_375_real),32);
        bufp->chgIData(oldp+842,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_375_imag),32);
        bufp->chgIData(oldp+843,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_376_real),32);
        bufp->chgIData(oldp+844,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_376_imag),32);
        bufp->chgIData(oldp+845,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_377_real),32);
        bufp->chgIData(oldp+846,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_377_imag),32);
        bufp->chgIData(oldp+847,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_378_real),32);
        bufp->chgIData(oldp+848,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_378_imag),32);
        bufp->chgIData(oldp+849,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_379_real),32);
        bufp->chgIData(oldp+850,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_379_imag),32);
        bufp->chgIData(oldp+851,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_380_real),32);
        bufp->chgIData(oldp+852,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_380_imag),32);
        bufp->chgIData(oldp+853,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_381_real),32);
        bufp->chgIData(oldp+854,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_381_imag),32);
        bufp->chgIData(oldp+855,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_382_real),32);
        bufp->chgIData(oldp+856,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_382_imag),32);
        bufp->chgIData(oldp+857,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_real),32);
        bufp->chgIData(oldp+858,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_imag),32);
        bufp->chgIData(oldp+859,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_384_real),32);
        bufp->chgIData(oldp+860,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_384_imag),32);
        bufp->chgIData(oldp+861,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_385_real),32);
        bufp->chgIData(oldp+862,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_385_imag),32);
        bufp->chgIData(oldp+863,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_386_real),32);
        bufp->chgIData(oldp+864,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_386_imag),32);
        bufp->chgIData(oldp+865,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_387_real),32);
        bufp->chgIData(oldp+866,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_387_imag),32);
        bufp->chgIData(oldp+867,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_388_real),32);
        bufp->chgIData(oldp+868,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_388_imag),32);
        bufp->chgIData(oldp+869,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_389_real),32);
        bufp->chgIData(oldp+870,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_389_imag),32);
        bufp->chgIData(oldp+871,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_390_real),32);
        bufp->chgIData(oldp+872,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_390_imag),32);
        bufp->chgIData(oldp+873,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_391_real),32);
        bufp->chgIData(oldp+874,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_391_imag),32);
        bufp->chgIData(oldp+875,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_392_real),32);
        bufp->chgIData(oldp+876,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_392_imag),32);
        bufp->chgIData(oldp+877,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_393_real),32);
        bufp->chgIData(oldp+878,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_393_imag),32);
        bufp->chgIData(oldp+879,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_394_real),32);
        bufp->chgIData(oldp+880,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_394_imag),32);
        bufp->chgIData(oldp+881,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_395_real),32);
        bufp->chgIData(oldp+882,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_395_imag),32);
        bufp->chgIData(oldp+883,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_396_real),32);
        bufp->chgIData(oldp+884,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_396_imag),32);
        bufp->chgIData(oldp+885,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_397_real),32);
        bufp->chgIData(oldp+886,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_397_imag),32);
        bufp->chgIData(oldp+887,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_398_real),32);
        bufp->chgIData(oldp+888,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_398_imag),32);
        bufp->chgIData(oldp+889,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_399_real),32);
        bufp->chgIData(oldp+890,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_399_imag),32);
        bufp->chgIData(oldp+891,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_400_real),32);
        bufp->chgIData(oldp+892,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_400_imag),32);
        bufp->chgIData(oldp+893,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_401_real),32);
        bufp->chgIData(oldp+894,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_401_imag),32);
        bufp->chgIData(oldp+895,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_402_real),32);
        bufp->chgIData(oldp+896,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_402_imag),32);
        bufp->chgIData(oldp+897,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_403_real),32);
        bufp->chgIData(oldp+898,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_403_imag),32);
        bufp->chgIData(oldp+899,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_404_real),32);
        bufp->chgIData(oldp+900,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_404_imag),32);
        bufp->chgIData(oldp+901,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_405_real),32);
        bufp->chgIData(oldp+902,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_405_imag),32);
        bufp->chgIData(oldp+903,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_406_real),32);
        bufp->chgIData(oldp+904,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_406_imag),32);
        bufp->chgIData(oldp+905,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_407_real),32);
        bufp->chgIData(oldp+906,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_407_imag),32);
        bufp->chgIData(oldp+907,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_408_real),32);
        bufp->chgIData(oldp+908,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_408_imag),32);
        bufp->chgIData(oldp+909,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_409_real),32);
        bufp->chgIData(oldp+910,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_409_imag),32);
        bufp->chgIData(oldp+911,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_410_real),32);
        bufp->chgIData(oldp+912,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_410_imag),32);
        bufp->chgIData(oldp+913,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_411_real),32);
        bufp->chgIData(oldp+914,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_411_imag),32);
        bufp->chgIData(oldp+915,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_412_real),32);
        bufp->chgIData(oldp+916,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_412_imag),32);
        bufp->chgIData(oldp+917,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_413_real),32);
        bufp->chgIData(oldp+918,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_413_imag),32);
        bufp->chgIData(oldp+919,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_414_real),32);
        bufp->chgIData(oldp+920,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_414_imag),32);
        bufp->chgIData(oldp+921,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_415_real),32);
        bufp->chgIData(oldp+922,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_415_imag),32);
        bufp->chgIData(oldp+923,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_416_real),32);
        bufp->chgIData(oldp+924,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_416_imag),32);
        bufp->chgIData(oldp+925,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_417_real),32);
        bufp->chgIData(oldp+926,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_417_imag),32);
        bufp->chgIData(oldp+927,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_418_real),32);
        bufp->chgIData(oldp+928,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_418_imag),32);
        bufp->chgIData(oldp+929,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_419_real),32);
        bufp->chgIData(oldp+930,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_419_imag),32);
        bufp->chgIData(oldp+931,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_420_real),32);
        bufp->chgIData(oldp+932,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_420_imag),32);
        bufp->chgIData(oldp+933,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_421_real),32);
        bufp->chgIData(oldp+934,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_421_imag),32);
        bufp->chgIData(oldp+935,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_422_real),32);
        bufp->chgIData(oldp+936,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_422_imag),32);
        bufp->chgIData(oldp+937,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_423_real),32);
        bufp->chgIData(oldp+938,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_423_imag),32);
        bufp->chgIData(oldp+939,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_424_real),32);
        bufp->chgIData(oldp+940,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_424_imag),32);
        bufp->chgIData(oldp+941,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_425_real),32);
        bufp->chgIData(oldp+942,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_425_imag),32);
        bufp->chgIData(oldp+943,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_426_real),32);
        bufp->chgIData(oldp+944,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_426_imag),32);
        bufp->chgIData(oldp+945,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_427_real),32);
        bufp->chgIData(oldp+946,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_427_imag),32);
        bufp->chgIData(oldp+947,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_428_real),32);
        bufp->chgIData(oldp+948,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_428_imag),32);
        bufp->chgIData(oldp+949,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_429_real),32);
        bufp->chgIData(oldp+950,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_429_imag),32);
        bufp->chgIData(oldp+951,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_430_real),32);
        bufp->chgIData(oldp+952,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_430_imag),32);
        bufp->chgIData(oldp+953,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_431_real),32);
        bufp->chgIData(oldp+954,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_431_imag),32);
        bufp->chgIData(oldp+955,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_432_real),32);
        bufp->chgIData(oldp+956,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_432_imag),32);
        bufp->chgIData(oldp+957,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_433_real),32);
        bufp->chgIData(oldp+958,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_433_imag),32);
        bufp->chgIData(oldp+959,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_434_real),32);
        bufp->chgIData(oldp+960,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_434_imag),32);
        bufp->chgIData(oldp+961,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_435_real),32);
        bufp->chgIData(oldp+962,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_435_imag),32);
        bufp->chgIData(oldp+963,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_436_real),32);
        bufp->chgIData(oldp+964,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_436_imag),32);
        bufp->chgIData(oldp+965,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_437_real),32);
        bufp->chgIData(oldp+966,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_437_imag),32);
        bufp->chgIData(oldp+967,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_438_real),32);
        bufp->chgIData(oldp+968,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_438_imag),32);
        bufp->chgIData(oldp+969,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_439_real),32);
        bufp->chgIData(oldp+970,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_439_imag),32);
        bufp->chgIData(oldp+971,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_440_real),32);
        bufp->chgIData(oldp+972,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_440_imag),32);
        bufp->chgIData(oldp+973,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_441_real),32);
        bufp->chgIData(oldp+974,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_441_imag),32);
        bufp->chgIData(oldp+975,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_442_real),32);
        bufp->chgIData(oldp+976,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_442_imag),32);
        bufp->chgIData(oldp+977,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_443_real),32);
        bufp->chgIData(oldp+978,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_443_imag),32);
        bufp->chgIData(oldp+979,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_444_real),32);
        bufp->chgIData(oldp+980,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_444_imag),32);
        bufp->chgIData(oldp+981,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_445_real),32);
        bufp->chgIData(oldp+982,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_445_imag),32);
        bufp->chgIData(oldp+983,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_446_real),32);
        bufp->chgIData(oldp+984,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_446_imag),32);
        bufp->chgIData(oldp+985,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_447_real),32);
        bufp->chgIData(oldp+986,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_447_imag),32);
        bufp->chgIData(oldp+987,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_448_real),32);
        bufp->chgIData(oldp+988,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_448_imag),32);
        bufp->chgIData(oldp+989,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_449_real),32);
        bufp->chgIData(oldp+990,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_449_imag),32);
        bufp->chgIData(oldp+991,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_450_real),32);
        bufp->chgIData(oldp+992,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_450_imag),32);
        bufp->chgIData(oldp+993,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_451_real),32);
        bufp->chgIData(oldp+994,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_451_imag),32);
        bufp->chgIData(oldp+995,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_452_real),32);
        bufp->chgIData(oldp+996,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_452_imag),32);
        bufp->chgIData(oldp+997,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_453_real),32);
        bufp->chgIData(oldp+998,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_453_imag),32);
        bufp->chgIData(oldp+999,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_454_real),32);
        bufp->chgIData(oldp+1000,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_454_imag),32);
        bufp->chgIData(oldp+1001,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_455_real),32);
        bufp->chgIData(oldp+1002,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_455_imag),32);
        bufp->chgIData(oldp+1003,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_456_real),32);
        bufp->chgIData(oldp+1004,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_456_imag),32);
        bufp->chgIData(oldp+1005,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_457_real),32);
        bufp->chgIData(oldp+1006,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_457_imag),32);
        bufp->chgIData(oldp+1007,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_458_real),32);
        bufp->chgIData(oldp+1008,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_458_imag),32);
        bufp->chgIData(oldp+1009,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_459_real),32);
        bufp->chgIData(oldp+1010,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_459_imag),32);
        bufp->chgIData(oldp+1011,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_460_real),32);
        bufp->chgIData(oldp+1012,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_460_imag),32);
        bufp->chgIData(oldp+1013,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_461_real),32);
        bufp->chgIData(oldp+1014,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_461_imag),32);
        bufp->chgIData(oldp+1015,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_462_real),32);
        bufp->chgIData(oldp+1016,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_462_imag),32);
        bufp->chgIData(oldp+1017,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_463_real),32);
        bufp->chgIData(oldp+1018,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_463_imag),32);
        bufp->chgIData(oldp+1019,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_464_real),32);
        bufp->chgIData(oldp+1020,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_464_imag),32);
        bufp->chgIData(oldp+1021,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_465_real),32);
        bufp->chgIData(oldp+1022,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_465_imag),32);
        bufp->chgIData(oldp+1023,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_466_real),32);
        bufp->chgIData(oldp+1024,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_466_imag),32);
        bufp->chgIData(oldp+1025,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_467_real),32);
        bufp->chgIData(oldp+1026,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_467_imag),32);
        bufp->chgIData(oldp+1027,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_468_real),32);
        bufp->chgIData(oldp+1028,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_468_imag),32);
        bufp->chgIData(oldp+1029,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_469_real),32);
        bufp->chgIData(oldp+1030,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_469_imag),32);
        bufp->chgIData(oldp+1031,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_470_real),32);
        bufp->chgIData(oldp+1032,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_470_imag),32);
        bufp->chgIData(oldp+1033,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_471_real),32);
        bufp->chgIData(oldp+1034,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_471_imag),32);
        bufp->chgIData(oldp+1035,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_472_real),32);
        bufp->chgIData(oldp+1036,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_472_imag),32);
        bufp->chgIData(oldp+1037,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_473_real),32);
        bufp->chgIData(oldp+1038,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_473_imag),32);
        bufp->chgIData(oldp+1039,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_474_real),32);
        bufp->chgIData(oldp+1040,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_474_imag),32);
        bufp->chgIData(oldp+1041,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_475_real),32);
        bufp->chgIData(oldp+1042,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_475_imag),32);
        bufp->chgIData(oldp+1043,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_476_real),32);
        bufp->chgIData(oldp+1044,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_476_imag),32);
        bufp->chgIData(oldp+1045,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_477_real),32);
        bufp->chgIData(oldp+1046,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_477_imag),32);
        bufp->chgIData(oldp+1047,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_478_real),32);
        bufp->chgIData(oldp+1048,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_478_imag),32);
        bufp->chgIData(oldp+1049,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_479_real),32);
        bufp->chgIData(oldp+1050,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_479_imag),32);
        bufp->chgIData(oldp+1051,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_480_real),32);
        bufp->chgIData(oldp+1052,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_480_imag),32);
        bufp->chgIData(oldp+1053,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_481_real),32);
        bufp->chgIData(oldp+1054,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_481_imag),32);
        bufp->chgIData(oldp+1055,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_482_real),32);
        bufp->chgIData(oldp+1056,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_482_imag),32);
        bufp->chgIData(oldp+1057,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_483_real),32);
        bufp->chgIData(oldp+1058,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_483_imag),32);
        bufp->chgIData(oldp+1059,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_484_real),32);
        bufp->chgIData(oldp+1060,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_484_imag),32);
        bufp->chgIData(oldp+1061,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_485_real),32);
        bufp->chgIData(oldp+1062,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_485_imag),32);
        bufp->chgIData(oldp+1063,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_486_real),32);
        bufp->chgIData(oldp+1064,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_486_imag),32);
        bufp->chgIData(oldp+1065,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_487_real),32);
        bufp->chgIData(oldp+1066,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_487_imag),32);
        bufp->chgIData(oldp+1067,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_488_real),32);
        bufp->chgIData(oldp+1068,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_488_imag),32);
        bufp->chgIData(oldp+1069,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_489_real),32);
        bufp->chgIData(oldp+1070,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_489_imag),32);
        bufp->chgIData(oldp+1071,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_490_real),32);
        bufp->chgIData(oldp+1072,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_490_imag),32);
        bufp->chgIData(oldp+1073,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_491_real),32);
        bufp->chgIData(oldp+1074,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_491_imag),32);
        bufp->chgIData(oldp+1075,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_492_real),32);
        bufp->chgIData(oldp+1076,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_492_imag),32);
        bufp->chgIData(oldp+1077,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_493_real),32);
        bufp->chgIData(oldp+1078,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_493_imag),32);
        bufp->chgIData(oldp+1079,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_494_real),32);
        bufp->chgIData(oldp+1080,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_494_imag),32);
        bufp->chgIData(oldp+1081,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_495_real),32);
        bufp->chgIData(oldp+1082,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_495_imag),32);
        bufp->chgIData(oldp+1083,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_496_real),32);
        bufp->chgIData(oldp+1084,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_496_imag),32);
        bufp->chgIData(oldp+1085,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_497_real),32);
        bufp->chgIData(oldp+1086,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_497_imag),32);
        bufp->chgIData(oldp+1087,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_498_real),32);
        bufp->chgIData(oldp+1088,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_498_imag),32);
        bufp->chgIData(oldp+1089,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_499_real),32);
        bufp->chgIData(oldp+1090,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_499_imag),32);
        bufp->chgIData(oldp+1091,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_500_real),32);
        bufp->chgIData(oldp+1092,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_500_imag),32);
        bufp->chgIData(oldp+1093,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_501_real),32);
        bufp->chgIData(oldp+1094,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_501_imag),32);
        bufp->chgIData(oldp+1095,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_502_real),32);
        bufp->chgIData(oldp+1096,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_502_imag),32);
        bufp->chgIData(oldp+1097,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_503_real),32);
        bufp->chgIData(oldp+1098,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_503_imag),32);
        bufp->chgIData(oldp+1099,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_504_real),32);
        bufp->chgIData(oldp+1100,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_504_imag),32);
        bufp->chgIData(oldp+1101,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_505_real),32);
        bufp->chgIData(oldp+1102,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_505_imag),32);
        bufp->chgIData(oldp+1103,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_506_real),32);
        bufp->chgIData(oldp+1104,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_506_imag),32);
        bufp->chgIData(oldp+1105,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_507_real),32);
        bufp->chgIData(oldp+1106,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_507_imag),32);
        bufp->chgIData(oldp+1107,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_508_real),32);
        bufp->chgIData(oldp+1108,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_508_imag),32);
        bufp->chgIData(oldp+1109,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_509_real),32);
        bufp->chgIData(oldp+1110,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_509_imag),32);
        bufp->chgIData(oldp+1111,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_510_real),32);
        bufp->chgIData(oldp+1112,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_510_imag),32);
        bufp->chgIData(oldp+1113,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_real),32);
        bufp->chgIData(oldp+1114,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_imag),32);
        bufp->chgIData(oldp+1115,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_512_real),32);
        bufp->chgIData(oldp+1116,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_512_imag),32);
        bufp->chgIData(oldp+1117,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_513_real),32);
        bufp->chgIData(oldp+1118,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_513_imag),32);
        bufp->chgIData(oldp+1119,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_514_real),32);
        bufp->chgIData(oldp+1120,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_514_imag),32);
        bufp->chgIData(oldp+1121,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_515_real),32);
        bufp->chgIData(oldp+1122,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_515_imag),32);
        bufp->chgIData(oldp+1123,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_516_real),32);
        bufp->chgIData(oldp+1124,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_516_imag),32);
        bufp->chgIData(oldp+1125,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_517_real),32);
        bufp->chgIData(oldp+1126,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_517_imag),32);
        bufp->chgIData(oldp+1127,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_518_real),32);
        bufp->chgIData(oldp+1128,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_518_imag),32);
        bufp->chgIData(oldp+1129,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_519_real),32);
        bufp->chgIData(oldp+1130,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_519_imag),32);
        bufp->chgIData(oldp+1131,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_520_real),32);
        bufp->chgIData(oldp+1132,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_520_imag),32);
        bufp->chgIData(oldp+1133,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_521_real),32);
        bufp->chgIData(oldp+1134,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_521_imag),32);
        bufp->chgIData(oldp+1135,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_522_real),32);
        bufp->chgIData(oldp+1136,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_522_imag),32);
        bufp->chgIData(oldp+1137,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_523_real),32);
        bufp->chgIData(oldp+1138,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_523_imag),32);
        bufp->chgIData(oldp+1139,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_524_real),32);
        bufp->chgIData(oldp+1140,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_524_imag),32);
        bufp->chgIData(oldp+1141,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_525_real),32);
        bufp->chgIData(oldp+1142,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_525_imag),32);
        bufp->chgIData(oldp+1143,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_526_real),32);
        bufp->chgIData(oldp+1144,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_526_imag),32);
        bufp->chgIData(oldp+1145,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_527_real),32);
        bufp->chgIData(oldp+1146,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_527_imag),32);
        bufp->chgIData(oldp+1147,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_528_real),32);
        bufp->chgIData(oldp+1148,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_528_imag),32);
        bufp->chgIData(oldp+1149,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_529_real),32);
        bufp->chgIData(oldp+1150,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_529_imag),32);
        bufp->chgIData(oldp+1151,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_530_real),32);
        bufp->chgIData(oldp+1152,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_530_imag),32);
        bufp->chgIData(oldp+1153,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_531_real),32);
        bufp->chgIData(oldp+1154,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_531_imag),32);
        bufp->chgIData(oldp+1155,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_532_real),32);
        bufp->chgIData(oldp+1156,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_532_imag),32);
        bufp->chgIData(oldp+1157,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_533_real),32);
        bufp->chgIData(oldp+1158,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_533_imag),32);
        bufp->chgIData(oldp+1159,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_534_real),32);
        bufp->chgIData(oldp+1160,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_534_imag),32);
        bufp->chgIData(oldp+1161,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_535_real),32);
        bufp->chgIData(oldp+1162,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_535_imag),32);
        bufp->chgIData(oldp+1163,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_536_real),32);
        bufp->chgIData(oldp+1164,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_536_imag),32);
        bufp->chgIData(oldp+1165,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_537_real),32);
        bufp->chgIData(oldp+1166,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_537_imag),32);
        bufp->chgIData(oldp+1167,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_538_real),32);
        bufp->chgIData(oldp+1168,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_538_imag),32);
        bufp->chgIData(oldp+1169,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_539_real),32);
        bufp->chgIData(oldp+1170,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_539_imag),32);
        bufp->chgIData(oldp+1171,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_540_real),32);
        bufp->chgIData(oldp+1172,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_540_imag),32);
        bufp->chgIData(oldp+1173,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_541_real),32);
        bufp->chgIData(oldp+1174,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_541_imag),32);
        bufp->chgIData(oldp+1175,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_542_real),32);
        bufp->chgIData(oldp+1176,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_542_imag),32);
        bufp->chgIData(oldp+1177,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_543_real),32);
        bufp->chgIData(oldp+1178,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_543_imag),32);
        bufp->chgIData(oldp+1179,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_544_real),32);
        bufp->chgIData(oldp+1180,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_544_imag),32);
        bufp->chgIData(oldp+1181,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_545_real),32);
        bufp->chgIData(oldp+1182,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_545_imag),32);
        bufp->chgIData(oldp+1183,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_546_real),32);
        bufp->chgIData(oldp+1184,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_546_imag),32);
        bufp->chgIData(oldp+1185,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_547_real),32);
        bufp->chgIData(oldp+1186,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_547_imag),32);
        bufp->chgIData(oldp+1187,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_548_real),32);
        bufp->chgIData(oldp+1188,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_548_imag),32);
        bufp->chgIData(oldp+1189,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_549_real),32);
        bufp->chgIData(oldp+1190,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_549_imag),32);
        bufp->chgIData(oldp+1191,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_550_real),32);
        bufp->chgIData(oldp+1192,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_550_imag),32);
        bufp->chgIData(oldp+1193,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_551_real),32);
        bufp->chgIData(oldp+1194,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_551_imag),32);
        bufp->chgIData(oldp+1195,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_552_real),32);
        bufp->chgIData(oldp+1196,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_552_imag),32);
        bufp->chgIData(oldp+1197,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_553_real),32);
        bufp->chgIData(oldp+1198,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_553_imag),32);
        bufp->chgIData(oldp+1199,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_554_real),32);
        bufp->chgIData(oldp+1200,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_554_imag),32);
        bufp->chgIData(oldp+1201,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_555_real),32);
        bufp->chgIData(oldp+1202,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_555_imag),32);
        bufp->chgIData(oldp+1203,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_556_real),32);
        bufp->chgIData(oldp+1204,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_556_imag),32);
        bufp->chgIData(oldp+1205,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_557_real),32);
        bufp->chgIData(oldp+1206,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_557_imag),32);
        bufp->chgIData(oldp+1207,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_558_real),32);
        bufp->chgIData(oldp+1208,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_558_imag),32);
        bufp->chgIData(oldp+1209,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_559_real),32);
        bufp->chgIData(oldp+1210,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_559_imag),32);
        bufp->chgIData(oldp+1211,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_560_real),32);
        bufp->chgIData(oldp+1212,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_560_imag),32);
        bufp->chgIData(oldp+1213,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_561_real),32);
        bufp->chgIData(oldp+1214,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_561_imag),32);
        bufp->chgIData(oldp+1215,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_562_real),32);
        bufp->chgIData(oldp+1216,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_562_imag),32);
        bufp->chgIData(oldp+1217,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_563_real),32);
        bufp->chgIData(oldp+1218,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_563_imag),32);
        bufp->chgIData(oldp+1219,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_564_real),32);
        bufp->chgIData(oldp+1220,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_564_imag),32);
        bufp->chgIData(oldp+1221,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_565_real),32);
        bufp->chgIData(oldp+1222,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_565_imag),32);
        bufp->chgIData(oldp+1223,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_566_real),32);
        bufp->chgIData(oldp+1224,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_566_imag),32);
        bufp->chgIData(oldp+1225,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_567_real),32);
        bufp->chgIData(oldp+1226,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_567_imag),32);
        bufp->chgIData(oldp+1227,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_568_real),32);
        bufp->chgIData(oldp+1228,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_568_imag),32);
        bufp->chgIData(oldp+1229,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_569_real),32);
        bufp->chgIData(oldp+1230,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_569_imag),32);
        bufp->chgIData(oldp+1231,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_570_real),32);
        bufp->chgIData(oldp+1232,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_570_imag),32);
        bufp->chgIData(oldp+1233,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_571_real),32);
        bufp->chgIData(oldp+1234,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_571_imag),32);
        bufp->chgIData(oldp+1235,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_572_real),32);
        bufp->chgIData(oldp+1236,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_572_imag),32);
        bufp->chgIData(oldp+1237,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_573_real),32);
        bufp->chgIData(oldp+1238,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_573_imag),32);
        bufp->chgIData(oldp+1239,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_574_real),32);
        bufp->chgIData(oldp+1240,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_574_imag),32);
        bufp->chgIData(oldp+1241,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_real),32);
        bufp->chgIData(oldp+1242,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_imag),32);
        bufp->chgIData(oldp+1243,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_576_real),32);
        bufp->chgIData(oldp+1244,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_576_imag),32);
        bufp->chgIData(oldp+1245,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_577_real),32);
        bufp->chgIData(oldp+1246,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_577_imag),32);
        bufp->chgIData(oldp+1247,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_578_real),32);
        bufp->chgIData(oldp+1248,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_578_imag),32);
        bufp->chgIData(oldp+1249,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_579_real),32);
        bufp->chgIData(oldp+1250,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_579_imag),32);
        bufp->chgIData(oldp+1251,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_580_real),32);
        bufp->chgIData(oldp+1252,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_580_imag),32);
        bufp->chgIData(oldp+1253,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_581_real),32);
        bufp->chgIData(oldp+1254,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_581_imag),32);
        bufp->chgIData(oldp+1255,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_582_real),32);
        bufp->chgIData(oldp+1256,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_582_imag),32);
        bufp->chgIData(oldp+1257,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_583_real),32);
        bufp->chgIData(oldp+1258,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_583_imag),32);
        bufp->chgIData(oldp+1259,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_584_real),32);
        bufp->chgIData(oldp+1260,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_584_imag),32);
        bufp->chgIData(oldp+1261,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_585_real),32);
        bufp->chgIData(oldp+1262,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_585_imag),32);
        bufp->chgIData(oldp+1263,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_586_real),32);
        bufp->chgIData(oldp+1264,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_586_imag),32);
        bufp->chgIData(oldp+1265,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_587_real),32);
        bufp->chgIData(oldp+1266,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_587_imag),32);
        bufp->chgIData(oldp+1267,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_588_real),32);
        bufp->chgIData(oldp+1268,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_588_imag),32);
        bufp->chgIData(oldp+1269,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_589_real),32);
        bufp->chgIData(oldp+1270,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_589_imag),32);
        bufp->chgIData(oldp+1271,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_590_real),32);
        bufp->chgIData(oldp+1272,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_590_imag),32);
        bufp->chgIData(oldp+1273,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_591_real),32);
        bufp->chgIData(oldp+1274,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_591_imag),32);
        bufp->chgIData(oldp+1275,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_592_real),32);
        bufp->chgIData(oldp+1276,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_592_imag),32);
        bufp->chgIData(oldp+1277,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_593_real),32);
        bufp->chgIData(oldp+1278,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_593_imag),32);
        bufp->chgIData(oldp+1279,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_594_real),32);
        bufp->chgIData(oldp+1280,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_594_imag),32);
        bufp->chgIData(oldp+1281,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_595_real),32);
        bufp->chgIData(oldp+1282,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_595_imag),32);
        bufp->chgIData(oldp+1283,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_596_real),32);
        bufp->chgIData(oldp+1284,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_596_imag),32);
        bufp->chgIData(oldp+1285,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_597_real),32);
        bufp->chgIData(oldp+1286,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_597_imag),32);
        bufp->chgIData(oldp+1287,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_598_real),32);
        bufp->chgIData(oldp+1288,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_598_imag),32);
        bufp->chgIData(oldp+1289,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_599_real),32);
        bufp->chgIData(oldp+1290,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_599_imag),32);
        bufp->chgIData(oldp+1291,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_600_real),32);
        bufp->chgIData(oldp+1292,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_600_imag),32);
        bufp->chgIData(oldp+1293,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_601_real),32);
        bufp->chgIData(oldp+1294,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_601_imag),32);
        bufp->chgIData(oldp+1295,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_602_real),32);
        bufp->chgIData(oldp+1296,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_602_imag),32);
        bufp->chgIData(oldp+1297,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_603_real),32);
        bufp->chgIData(oldp+1298,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_603_imag),32);
        bufp->chgIData(oldp+1299,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_604_real),32);
        bufp->chgIData(oldp+1300,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_604_imag),32);
        bufp->chgIData(oldp+1301,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_605_real),32);
        bufp->chgIData(oldp+1302,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_605_imag),32);
        bufp->chgIData(oldp+1303,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_606_real),32);
        bufp->chgIData(oldp+1304,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_606_imag),32);
        bufp->chgIData(oldp+1305,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_607_real),32);
        bufp->chgIData(oldp+1306,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_607_imag),32);
        bufp->chgIData(oldp+1307,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_608_real),32);
        bufp->chgIData(oldp+1308,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_608_imag),32);
        bufp->chgIData(oldp+1309,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_609_real),32);
        bufp->chgIData(oldp+1310,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_609_imag),32);
        bufp->chgIData(oldp+1311,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_610_real),32);
        bufp->chgIData(oldp+1312,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_610_imag),32);
        bufp->chgIData(oldp+1313,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_611_real),32);
        bufp->chgIData(oldp+1314,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_611_imag),32);
        bufp->chgIData(oldp+1315,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_612_real),32);
        bufp->chgIData(oldp+1316,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_612_imag),32);
        bufp->chgIData(oldp+1317,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_613_real),32);
        bufp->chgIData(oldp+1318,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_613_imag),32);
        bufp->chgIData(oldp+1319,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_614_real),32);
        bufp->chgIData(oldp+1320,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_614_imag),32);
        bufp->chgIData(oldp+1321,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_615_real),32);
        bufp->chgIData(oldp+1322,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_615_imag),32);
        bufp->chgIData(oldp+1323,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_616_real),32);
        bufp->chgIData(oldp+1324,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_616_imag),32);
        bufp->chgIData(oldp+1325,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_617_real),32);
        bufp->chgIData(oldp+1326,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_617_imag),32);
        bufp->chgIData(oldp+1327,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_618_real),32);
        bufp->chgIData(oldp+1328,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_618_imag),32);
        bufp->chgIData(oldp+1329,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_619_real),32);
        bufp->chgIData(oldp+1330,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_619_imag),32);
        bufp->chgIData(oldp+1331,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_620_real),32);
        bufp->chgIData(oldp+1332,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_620_imag),32);
        bufp->chgIData(oldp+1333,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_621_real),32);
        bufp->chgIData(oldp+1334,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_621_imag),32);
        bufp->chgIData(oldp+1335,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_622_real),32);
        bufp->chgIData(oldp+1336,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_622_imag),32);
        bufp->chgIData(oldp+1337,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_623_real),32);
        bufp->chgIData(oldp+1338,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_623_imag),32);
        bufp->chgIData(oldp+1339,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_624_real),32);
        bufp->chgIData(oldp+1340,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_624_imag),32);
        bufp->chgIData(oldp+1341,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_625_real),32);
        bufp->chgIData(oldp+1342,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_625_imag),32);
        bufp->chgIData(oldp+1343,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_626_real),32);
        bufp->chgIData(oldp+1344,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_626_imag),32);
        bufp->chgIData(oldp+1345,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_627_real),32);
        bufp->chgIData(oldp+1346,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_627_imag),32);
        bufp->chgIData(oldp+1347,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_628_real),32);
        bufp->chgIData(oldp+1348,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_628_imag),32);
        bufp->chgIData(oldp+1349,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_629_real),32);
        bufp->chgIData(oldp+1350,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_629_imag),32);
        bufp->chgIData(oldp+1351,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_630_real),32);
        bufp->chgIData(oldp+1352,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_630_imag),32);
        bufp->chgIData(oldp+1353,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_631_real),32);
        bufp->chgIData(oldp+1354,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_631_imag),32);
        bufp->chgIData(oldp+1355,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_632_real),32);
        bufp->chgIData(oldp+1356,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_632_imag),32);
        bufp->chgIData(oldp+1357,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_633_real),32);
        bufp->chgIData(oldp+1358,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_633_imag),32);
        bufp->chgIData(oldp+1359,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_634_real),32);
        bufp->chgIData(oldp+1360,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_634_imag),32);
        bufp->chgIData(oldp+1361,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_635_real),32);
        bufp->chgIData(oldp+1362,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_635_imag),32);
        bufp->chgIData(oldp+1363,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_636_real),32);
        bufp->chgIData(oldp+1364,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_636_imag),32);
        bufp->chgIData(oldp+1365,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_637_real),32);
        bufp->chgIData(oldp+1366,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_637_imag),32);
        bufp->chgIData(oldp+1367,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_638_real),32);
        bufp->chgIData(oldp+1368,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_638_imag),32);
        bufp->chgIData(oldp+1369,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_real),32);
        bufp->chgIData(oldp+1370,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_imag),32);
        bufp->chgIData(oldp+1371,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_640_real),32);
        bufp->chgIData(oldp+1372,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_640_imag),32);
        bufp->chgIData(oldp+1373,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_641_real),32);
        bufp->chgIData(oldp+1374,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_641_imag),32);
        bufp->chgIData(oldp+1375,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_642_real),32);
        bufp->chgIData(oldp+1376,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_642_imag),32);
        bufp->chgIData(oldp+1377,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_643_real),32);
        bufp->chgIData(oldp+1378,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_643_imag),32);
        bufp->chgIData(oldp+1379,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_644_real),32);
        bufp->chgIData(oldp+1380,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_644_imag),32);
        bufp->chgIData(oldp+1381,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_645_real),32);
        bufp->chgIData(oldp+1382,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_645_imag),32);
        bufp->chgIData(oldp+1383,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_646_real),32);
        bufp->chgIData(oldp+1384,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_646_imag),32);
        bufp->chgIData(oldp+1385,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_647_real),32);
        bufp->chgIData(oldp+1386,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_647_imag),32);
        bufp->chgIData(oldp+1387,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_648_real),32);
        bufp->chgIData(oldp+1388,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_648_imag),32);
        bufp->chgIData(oldp+1389,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_649_real),32);
        bufp->chgIData(oldp+1390,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_649_imag),32);
        bufp->chgIData(oldp+1391,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_650_real),32);
        bufp->chgIData(oldp+1392,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_650_imag),32);
        bufp->chgIData(oldp+1393,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_651_real),32);
        bufp->chgIData(oldp+1394,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_651_imag),32);
        bufp->chgIData(oldp+1395,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_652_real),32);
        bufp->chgIData(oldp+1396,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_652_imag),32);
        bufp->chgIData(oldp+1397,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_653_real),32);
        bufp->chgIData(oldp+1398,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_653_imag),32);
        bufp->chgIData(oldp+1399,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_654_real),32);
        bufp->chgIData(oldp+1400,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_654_imag),32);
        bufp->chgIData(oldp+1401,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_655_real),32);
        bufp->chgIData(oldp+1402,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_655_imag),32);
        bufp->chgIData(oldp+1403,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_656_real),32);
        bufp->chgIData(oldp+1404,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_656_imag),32);
        bufp->chgIData(oldp+1405,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_657_real),32);
        bufp->chgIData(oldp+1406,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_657_imag),32);
        bufp->chgIData(oldp+1407,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_658_real),32);
        bufp->chgIData(oldp+1408,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_658_imag),32);
        bufp->chgIData(oldp+1409,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_659_real),32);
        bufp->chgIData(oldp+1410,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_659_imag),32);
        bufp->chgIData(oldp+1411,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_660_real),32);
        bufp->chgIData(oldp+1412,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_660_imag),32);
        bufp->chgIData(oldp+1413,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_661_real),32);
        bufp->chgIData(oldp+1414,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_661_imag),32);
        bufp->chgIData(oldp+1415,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_662_real),32);
        bufp->chgIData(oldp+1416,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_662_imag),32);
        bufp->chgIData(oldp+1417,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_663_real),32);
        bufp->chgIData(oldp+1418,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_663_imag),32);
        bufp->chgIData(oldp+1419,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_664_real),32);
        bufp->chgIData(oldp+1420,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_664_imag),32);
        bufp->chgIData(oldp+1421,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_665_real),32);
        bufp->chgIData(oldp+1422,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_665_imag),32);
        bufp->chgIData(oldp+1423,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_666_real),32);
        bufp->chgIData(oldp+1424,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_666_imag),32);
        bufp->chgIData(oldp+1425,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_667_real),32);
        bufp->chgIData(oldp+1426,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_667_imag),32);
        bufp->chgIData(oldp+1427,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_668_real),32);
        bufp->chgIData(oldp+1428,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_668_imag),32);
        bufp->chgIData(oldp+1429,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_669_real),32);
        bufp->chgIData(oldp+1430,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_669_imag),32);
        bufp->chgIData(oldp+1431,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_670_real),32);
        bufp->chgIData(oldp+1432,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_670_imag),32);
        bufp->chgIData(oldp+1433,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_real),32);
        bufp->chgIData(oldp+1434,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_imag),32);
        bufp->chgIData(oldp+1435,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_672_real),32);
        bufp->chgIData(oldp+1436,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_672_imag),32);
        bufp->chgIData(oldp+1437,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_673_real),32);
        bufp->chgIData(oldp+1438,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_673_imag),32);
        bufp->chgIData(oldp+1439,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_674_real),32);
        bufp->chgIData(oldp+1440,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_674_imag),32);
        bufp->chgIData(oldp+1441,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_675_real),32);
        bufp->chgIData(oldp+1442,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_675_imag),32);
        bufp->chgIData(oldp+1443,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_676_real),32);
        bufp->chgIData(oldp+1444,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_676_imag),32);
        bufp->chgIData(oldp+1445,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_677_real),32);
        bufp->chgIData(oldp+1446,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_677_imag),32);
        bufp->chgIData(oldp+1447,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_678_real),32);
        bufp->chgIData(oldp+1448,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_678_imag),32);
        bufp->chgIData(oldp+1449,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_679_real),32);
        bufp->chgIData(oldp+1450,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_679_imag),32);
        bufp->chgIData(oldp+1451,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_680_real),32);
        bufp->chgIData(oldp+1452,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_680_imag),32);
        bufp->chgIData(oldp+1453,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_681_real),32);
        bufp->chgIData(oldp+1454,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_681_imag),32);
        bufp->chgIData(oldp+1455,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_682_real),32);
        bufp->chgIData(oldp+1456,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_682_imag),32);
        bufp->chgIData(oldp+1457,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_683_real),32);
        bufp->chgIData(oldp+1458,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_683_imag),32);
        bufp->chgIData(oldp+1459,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_684_real),32);
        bufp->chgIData(oldp+1460,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_684_imag),32);
        bufp->chgIData(oldp+1461,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_685_real),32);
        bufp->chgIData(oldp+1462,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_685_imag),32);
        bufp->chgIData(oldp+1463,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_686_real),32);
        bufp->chgIData(oldp+1464,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_686_imag),32);
        bufp->chgIData(oldp+1465,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_687_real),32);
        bufp->chgIData(oldp+1466,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_687_imag),32);
        bufp->chgIData(oldp+1467,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_688_real),32);
        bufp->chgIData(oldp+1468,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_688_imag),32);
        bufp->chgIData(oldp+1469,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_689_real),32);
        bufp->chgIData(oldp+1470,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_689_imag),32);
        bufp->chgIData(oldp+1471,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_690_real),32);
        bufp->chgIData(oldp+1472,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_690_imag),32);
        bufp->chgIData(oldp+1473,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_691_real),32);
        bufp->chgIData(oldp+1474,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_691_imag),32);
        bufp->chgIData(oldp+1475,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_692_real),32);
        bufp->chgIData(oldp+1476,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_692_imag),32);
        bufp->chgIData(oldp+1477,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_693_real),32);
        bufp->chgIData(oldp+1478,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_693_imag),32);
        bufp->chgIData(oldp+1479,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_694_real),32);
        bufp->chgIData(oldp+1480,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_694_imag),32);
        bufp->chgIData(oldp+1481,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_695_real),32);
        bufp->chgIData(oldp+1482,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_695_imag),32);
        bufp->chgIData(oldp+1483,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_696_real),32);
        bufp->chgIData(oldp+1484,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_696_imag),32);
        bufp->chgIData(oldp+1485,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_697_real),32);
        bufp->chgIData(oldp+1486,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_697_imag),32);
        bufp->chgIData(oldp+1487,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_698_real),32);
        bufp->chgIData(oldp+1488,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_698_imag),32);
        bufp->chgIData(oldp+1489,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_699_real),32);
        bufp->chgIData(oldp+1490,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_699_imag),32);
        bufp->chgIData(oldp+1491,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_700_real),32);
        bufp->chgIData(oldp+1492,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_700_imag),32);
        bufp->chgIData(oldp+1493,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_701_real),32);
        bufp->chgIData(oldp+1494,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_701_imag),32);
        bufp->chgIData(oldp+1495,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_702_real),32);
        bufp->chgIData(oldp+1496,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_702_imag),32);
        bufp->chgIData(oldp+1497,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_real),32);
        bufp->chgIData(oldp+1498,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_imag),32);
        bufp->chgIData(oldp+1499,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_704_real),32);
        bufp->chgIData(oldp+1500,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_704_imag),32);
        bufp->chgIData(oldp+1501,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_705_real),32);
        bufp->chgIData(oldp+1502,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_705_imag),32);
        bufp->chgIData(oldp+1503,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_706_real),32);
        bufp->chgIData(oldp+1504,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_706_imag),32);
        bufp->chgIData(oldp+1505,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_707_real),32);
        bufp->chgIData(oldp+1506,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_707_imag),32);
        bufp->chgIData(oldp+1507,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_708_real),32);
        bufp->chgIData(oldp+1508,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_708_imag),32);
        bufp->chgIData(oldp+1509,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_709_real),32);
        bufp->chgIData(oldp+1510,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_709_imag),32);
        bufp->chgIData(oldp+1511,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_710_real),32);
        bufp->chgIData(oldp+1512,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_710_imag),32);
        bufp->chgIData(oldp+1513,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_711_real),32);
        bufp->chgIData(oldp+1514,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_711_imag),32);
        bufp->chgIData(oldp+1515,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_712_real),32);
        bufp->chgIData(oldp+1516,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_712_imag),32);
        bufp->chgIData(oldp+1517,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_713_real),32);
        bufp->chgIData(oldp+1518,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_713_imag),32);
        bufp->chgIData(oldp+1519,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_714_real),32);
        bufp->chgIData(oldp+1520,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_714_imag),32);
        bufp->chgIData(oldp+1521,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_715_real),32);
        bufp->chgIData(oldp+1522,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_715_imag),32);
        bufp->chgIData(oldp+1523,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_716_real),32);
        bufp->chgIData(oldp+1524,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_716_imag),32);
        bufp->chgIData(oldp+1525,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_717_real),32);
        bufp->chgIData(oldp+1526,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_717_imag),32);
        bufp->chgIData(oldp+1527,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_718_real),32);
        bufp->chgIData(oldp+1528,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_718_imag),32);
        bufp->chgIData(oldp+1529,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_real),32);
        bufp->chgIData(oldp+1530,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_imag),32);
        bufp->chgIData(oldp+1531,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_720_real),32);
        bufp->chgIData(oldp+1532,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_720_imag),32);
        bufp->chgIData(oldp+1533,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_721_real),32);
        bufp->chgIData(oldp+1534,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_721_imag),32);
        bufp->chgIData(oldp+1535,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_722_real),32);
        bufp->chgIData(oldp+1536,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_722_imag),32);
        bufp->chgIData(oldp+1537,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_723_real),32);
        bufp->chgIData(oldp+1538,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_723_imag),32);
        bufp->chgIData(oldp+1539,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_724_real),32);
        bufp->chgIData(oldp+1540,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_724_imag),32);
        bufp->chgIData(oldp+1541,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_725_real),32);
        bufp->chgIData(oldp+1542,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_725_imag),32);
        bufp->chgIData(oldp+1543,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_726_real),32);
        bufp->chgIData(oldp+1544,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_726_imag),32);
        bufp->chgIData(oldp+1545,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_727_real),32);
        bufp->chgIData(oldp+1546,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_727_imag),32);
        bufp->chgIData(oldp+1547,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_728_real),32);
        bufp->chgIData(oldp+1548,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_728_imag),32);
        bufp->chgIData(oldp+1549,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_729_real),32);
        bufp->chgIData(oldp+1550,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_729_imag),32);
        bufp->chgIData(oldp+1551,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_730_real),32);
        bufp->chgIData(oldp+1552,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_730_imag),32);
        bufp->chgIData(oldp+1553,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_731_real),32);
        bufp->chgIData(oldp+1554,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_731_imag),32);
        bufp->chgIData(oldp+1555,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_732_real),32);
        bufp->chgIData(oldp+1556,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_732_imag),32);
        bufp->chgIData(oldp+1557,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_733_real),32);
        bufp->chgIData(oldp+1558,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_733_imag),32);
        bufp->chgIData(oldp+1559,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_734_real),32);
        bufp->chgIData(oldp+1560,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_734_imag),32);
        bufp->chgIData(oldp+1561,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_real),32);
        bufp->chgIData(oldp+1562,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_imag),32);
        bufp->chgIData(oldp+1563,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_736_real),32);
        bufp->chgIData(oldp+1564,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_736_imag),32);
        bufp->chgIData(oldp+1565,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_737_real),32);
        bufp->chgIData(oldp+1566,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_737_imag),32);
        bufp->chgIData(oldp+1567,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_738_real),32);
        bufp->chgIData(oldp+1568,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_738_imag),32);
        bufp->chgIData(oldp+1569,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_739_real),32);
        bufp->chgIData(oldp+1570,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_739_imag),32);
        bufp->chgIData(oldp+1571,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_740_real),32);
        bufp->chgIData(oldp+1572,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_740_imag),32);
        bufp->chgIData(oldp+1573,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_741_real),32);
        bufp->chgIData(oldp+1574,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_741_imag),32);
        bufp->chgIData(oldp+1575,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_742_real),32);
        bufp->chgIData(oldp+1576,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_742_imag),32);
        bufp->chgIData(oldp+1577,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_real),32);
        bufp->chgIData(oldp+1578,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_imag),32);
        bufp->chgIData(oldp+1579,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_744_real),32);
        bufp->chgIData(oldp+1580,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_744_imag),32);
        bufp->chgIData(oldp+1581,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_745_real),32);
        bufp->chgIData(oldp+1582,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_745_imag),32);
        bufp->chgIData(oldp+1583,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_746_real),32);
        bufp->chgIData(oldp+1584,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_746_imag),32);
        bufp->chgIData(oldp+1585,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_747_real),32);
        bufp->chgIData(oldp+1586,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_747_imag),32);
        bufp->chgIData(oldp+1587,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_748_real),32);
        bufp->chgIData(oldp+1588,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_748_imag),32);
        bufp->chgIData(oldp+1589,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_749_real),32);
        bufp->chgIData(oldp+1590,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_749_imag),32);
        bufp->chgIData(oldp+1591,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_750_real),32);
        bufp->chgIData(oldp+1592,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_750_imag),32);
        bufp->chgIData(oldp+1593,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_real),32);
        bufp->chgIData(oldp+1594,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_imag),32);
        bufp->chgIData(oldp+1595,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_752_real),32);
        bufp->chgIData(oldp+1596,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_752_imag),32);
        bufp->chgIData(oldp+1597,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_753_real),32);
        bufp->chgIData(oldp+1598,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_753_imag),32);
        bufp->chgIData(oldp+1599,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_754_real),32);
        bufp->chgIData(oldp+1600,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_754_imag),32);
        bufp->chgIData(oldp+1601,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_real),32);
        bufp->chgIData(oldp+1602,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_imag),32);
        bufp->chgIData(oldp+1603,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_756_real),32);
        bufp->chgIData(oldp+1604,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_756_imag),32);
        bufp->chgIData(oldp+1605,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_757_real),32);
        bufp->chgIData(oldp+1606,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_757_imag),32);
        bufp->chgIData(oldp+1607,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_758_real),32);
        bufp->chgIData(oldp+1608,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_758_imag),32);
        bufp->chgIData(oldp+1609,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_real),32);
        bufp->chgIData(oldp+1610,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_imag),32);
        bufp->chgIData(oldp+1611,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_760_real),32);
        bufp->chgIData(oldp+1612,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_760_imag),32);
        bufp->chgIData(oldp+1613,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_real),32);
        bufp->chgIData(oldp+1614,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_imag),32);
        bufp->chgIData(oldp+1615,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_762_real),32);
        bufp->chgIData(oldp+1616,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_762_imag),32);
        bufp->chgIData(oldp+1617,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_real),32);
        bufp->chgIData(oldp+1618,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_imag),32);
        bufp->chgIData(oldp+1619,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_real),32);
        bufp->chgIData(oldp+1620,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_imag),32);
        bufp->chgIData(oldp+1621,(vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_real),32);
        bufp->chgIData(oldp+1622,(vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_imag),32);
        bufp->chgBit(oldp+1623,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                       >> 7U))));
        bufp->chgBit(oldp+1624,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                       >> 6U))));
        bufp->chgBit(oldp+1625,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                       >> 5U))));
        bufp->chgBit(oldp+1626,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                       >> 4U))));
        bufp->chgBit(oldp+1627,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                       >> 3U))));
        bufp->chgBit(oldp+1628,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                       >> 2U))));
        bufp->chgBit(oldp+1629,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                       >> 1U))));
        bufp->chgBit(oldp+1630,((1U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))));
        bufp->chgIData(oldp+1631,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(13,13,32, 
                                                          (0xffU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_h010c7fca_0[
                                             (((IData)(0x1fU) 
                                               + (0x1fffU 
                                                  & VL_SHIFTL_III(13,13,32, 
                                                                  (0xffU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(13,13,32, 
                                                                  (0xffU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_h010c7fca_0[
                                      (0xffU & (VL_SHIFTL_III(13,13,32, 
                                                              (0xffU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                                (0xffU 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1632,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(13,13,32, 
                                                          (0xffU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_h15912bbd_0[
                                             (((IData)(0x1fU) 
                                               + (0x1fffU 
                                                  & VL_SHIFTL_III(13,13,32, 
                                                                  (0xffU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(13,13,32, 
                                                                  (0xffU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_h15912bbd_0[
                                      (0xffU & (VL_SHIFTL_III(13,13,32, 
                                                              (0xffU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                                (0xffU 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1633,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(12,12,32, 
                                                          (0x7fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_hf3784b49_0[
                                             (((IData)(0x1fU) 
                                               + (0xfffU 
                                                  & VL_SHIFTL_III(12,12,32, 
                                                                  (0x7fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(12,12,32, 
                                                                  (0x7fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_hf3784b49_0[
                                      (0x7fU & (VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                                (0x7fU 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1634,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(12,12,32, 
                                                          (0x7fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_h944bc563_0[
                                             (((IData)(0x1fU) 
                                               + (0xfffU 
                                                  & VL_SHIFTL_III(12,12,32, 
                                                                  (0x7fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(12,12,32, 
                                                                  (0x7fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_h944bc563_0[
                                      (0x7fU & (VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                                (0x7fU 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1635,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_h8abd5580_0[
                                             (((IData)(0x1fU) 
                                               + (0x7ffU 
                                                  & VL_SHIFTL_III(11,11,32, 
                                                                  (0x3fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(11,11,32, 
                                                                  (0x3fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_h8abd5580_0[
                                      (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                                (0x3fU 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1636,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_h5478b25e_0[
                                             (((IData)(0x1fU) 
                                               + (0x7ffU 
                                                  & VL_SHIFTL_III(11,11,32, 
                                                                  (0x3fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(11,11,32, 
                                                                  (0x3fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_h5478b25e_0[
                                      (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                                (0x3fU 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1637,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_hb3c963b9_0[
                                             (((IData)(0x1fU) 
                                               + (0x3ffU 
                                                  & VL_SHIFTL_III(10,10,32, 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(10,10,32, 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_hb3c963b9_0[
                                      (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                                (0x1fU 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1638,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_h35564355_0[
                                             (((IData)(0x1fU) 
                                               + (0x3ffU 
                                                  & VL_SHIFTL_III(10,10,32, 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(10,10,32, 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_h35564355_0[
                                      (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                                (0x1fU 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1639,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_h942db0a5_0[
                                             (((IData)(0x1fU) 
                                               + (0x1ffU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0xfU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0xfU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_h942db0a5_0[
                                      (0xfU & (VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                               >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                                (0xfU 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1640,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_h0bfcbe7a_0[
                                             (((IData)(0x1fU) 
                                               + (0x1ffU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0xfU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0xfU 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_h0bfcbe7a_0[
                                      (0xfU & (VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                               >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                                (0xfU 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1641,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_hfd15effc_0[
                                             (((IData)(0x1fU) 
                                               + (0xffU 
                                                  & VL_SHIFTL_III(8,8,32, 
                                                                  (7U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(8,8,32, 
                                                                  (7U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_hfd15effc_0[
                                      (7U & (VL_SHIFTL_III(8,8,32, 
                                                           (7U 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                                (7U 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1642,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft512__ConstPool__CONST_h04042068_0[
                                             (((IData)(0x1fU) 
                                               + (0xffU 
                                                  & VL_SHIFTL_III(8,8,32, 
                                                                  (7U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(8,8,32, 
                                                                  (7U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft512__ConstPool__CONST_h04042068_0[
                                      (7U & (VL_SHIFTL_III(8,8,32, 
                                                           (7U 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                                (7U 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        __Vtemp_1[0U] = 0x100000U;
        __Vtemp_1[1U] = 0xb504fU;
        __Vtemp_1[2U] = 0U;
        __Vtemp_1[3U] = 0xfff4afb1U;
        bufp->chgIData(oldp+1643,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(7,7,32, 
                                                          (3U 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (__Vtemp_1[
                                             (((IData)(0x1fU) 
                                               + (0x7fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (__Vtemp_1[(3U 
                                                 & (VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                    >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                                (3U 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        __Vtemp_2[0U] = 0U;
        __Vtemp_2[1U] = 0xb504fU;
        __Vtemp_2[2U] = 0x100000U;
        __Vtemp_2[3U] = 0xb504fU;
        bufp->chgIData(oldp+1644,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(7,7,32, 
                                                          (3U 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (__Vtemp_2[
                                             (((IData)(0x1fU) 
                                               + (0x7fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (__Vtemp_2[(3U 
                                                 & (VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                                    >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                                (3U 
                                                                 & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1645,((0x100000U & ((~ (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)) 
                                                << 0x14U))),32);
        bufp->chgIData(oldp+1646,((0x100000U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                                << 0x14U))),32);
    }
    bufp->chgBit(oldp+1647,(vlSelfRef.FFT512_tb__DOT__clock));
}

void Vfft512___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root__trace_cleanup\n"); );
    // Init
    Vfft512___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft512___024root*>(voidSelf);
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
