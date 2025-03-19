// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfft256__Syms.h"


void Vfft256___024root__trace_chg_0_sub_0(Vfft256___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfft256___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root__trace_chg_0\n"); );
    // Init
    Vfft256___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft256___024root*>(voidSelf);
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfft256___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<128>/*4095:0*/ Vfft256__ConstPool__CONST_hf3784b49_0;
extern const VlWide<128>/*4095:0*/ Vfft256__ConstPool__CONST_h944bc563_0;
extern const VlWide<64>/*2047:0*/ Vfft256__ConstPool__CONST_h8abd5580_0;
extern const VlWide<64>/*2047:0*/ Vfft256__ConstPool__CONST_h5478b25e_0;
extern const VlWide<32>/*1023:0*/ Vfft256__ConstPool__CONST_hb3c963b9_0;
extern const VlWide<32>/*1023:0*/ Vfft256__ConstPool__CONST_h35564355_0;
extern const VlWide<16>/*511:0*/ Vfft256__ConstPool__CONST_h942db0a5_0;
extern const VlWide<16>/*511:0*/ Vfft256__ConstPool__CONST_h0bfcbe7a_0;
extern const VlWide<8>/*255:0*/ Vfft256__ConstPool__CONST_hfd15effc_0;
extern const VlWide<8>/*255:0*/ Vfft256__ConstPool__CONST_h04042068_0;

void Vfft256___024root__trace_chg_0_sub_0(Vfft256___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root__trace_chg_0_sub_0\n"); );
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.FFT256_tb__DOT__reset));
        bufp->chgIData(oldp+1,(vlSelfRef.FFT256_tb__DOT__io_in_real),32);
        bufp->chgIData(oldp+2,(vlSelfRef.FFT256_tb__DOT__io_in_imag),32);
        bufp->chgBit(oldp+3,(vlSelfRef.FFT256_tb__DOT__io_in_valid));
        bufp->chgIData(oldp+4,(vlSelfRef.FFT256_tb__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [3U] | vlSelfRef.__Vm_traceActivity
                       [4U]) | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgIData(oldp+5,(((0x40U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_real
                                 : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_real)),32);
        bufp->chgIData(oldp+6,(((0x40U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_imag
                                 : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_imag)),32);
        bufp->chgIData(oldp+7,(((0x20U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_real
                                 : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_real)),32);
        bufp->chgIData(oldp+8,(((0x20U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_imag
                                 : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_imag)),32);
        bufp->chgIData(oldp+9,(((0x10U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_real
                                 : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_real)),32);
        bufp->chgIData(oldp+10,(((0x10U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_imag
                                  : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_imag)),32);
        bufp->chgIData(oldp+11,(((8U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_real
                                  : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_real)),32);
        bufp->chgIData(oldp+12,(((8U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_imag
                                  : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_imag)),32);
        bufp->chgIData(oldp+13,(((4U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_real
                                  : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_real)),32);
        bufp->chgIData(oldp+14,(((4U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_imag
                                  : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_imag)),32);
        bufp->chgIData(oldp+15,(((2U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_real
                                  : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_real)),32);
        bufp->chgIData(oldp+16,(((2U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_imag
                                  : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_imag)),32);
        bufp->chgIData(oldp+17,(((1U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_real
                                  : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_real)),32);
        bufp->chgIData(oldp+18,(((1U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_imag
                                  : vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_imag)),32);
        bufp->chgIData(oldp+19,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+20,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+21,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+22,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+23,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+24,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+25,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+26,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+27,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+28,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+29,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+30,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+31,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+32,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgIData(oldp+33,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_real),32);
        bufp->chgIData(oldp+34,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_io_out1_imag),32);
        bufp->chgIData(oldp+35,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_real),32);
        bufp->chgIData(oldp+36,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_io_out2_imag),32);
        bufp->chgIData(oldp+37,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_real),32);
        bufp->chgIData(oldp+38,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_1_io_out1_imag),32);
        bufp->chgIData(oldp+39,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_real),32);
        bufp->chgIData(oldp+40,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_1_io_out2_imag),32);
        bufp->chgIData(oldp+41,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_real),32);
        bufp->chgIData(oldp+42,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_2_io_out1_imag),32);
        bufp->chgIData(oldp+43,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_real),32);
        bufp->chgIData(oldp+44,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_2_io_out2_imag),32);
        bufp->chgIData(oldp+45,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_real),32);
        bufp->chgIData(oldp+46,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_3_io_out1_imag),32);
        bufp->chgIData(oldp+47,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_real),32);
        bufp->chgIData(oldp+48,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_3_io_out2_imag),32);
        bufp->chgIData(oldp+49,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_real),32);
        bufp->chgIData(oldp+50,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_4_io_out1_imag),32);
        bufp->chgIData(oldp+51,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_real),32);
        bufp->chgIData(oldp+52,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_4_io_out2_imag),32);
        bufp->chgIData(oldp+53,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_real),32);
        bufp->chgIData(oldp+54,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_5_io_out1_imag),32);
        bufp->chgIData(oldp+55,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_real),32);
        bufp->chgIData(oldp+56,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_5_io_out2_imag),32);
        bufp->chgIData(oldp+57,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_real),32);
        bufp->chgIData(oldp+58,(vlSelfRef.FFT256_tb__DOT__uut__DOT___m_6_io_out1_imag),32);
        bufp->chgIData(oldp+59,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_real),32);
        bufp->chgIData(oldp+60,(vlSelfRef.FFT256_tb__DOT__uut__DOT___commutator_6_io_out2_imag),32);
        bufp->chgQData(oldp+61,(vlSelfRef.FFT256_tb__DOT__uut__DOT__m__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+63,(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+65,(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+67,(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+69,(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+71,(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1),52);
        bufp->chgQData(oldp+73,(vlSelfRef.FFT256_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1),52);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+75,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out1_REG_real),32);
        bufp->chgIData(oldp+76,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out1_REG_imag),32);
        bufp->chgIData(oldp+77,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out2_REG_real),32);
        bufp->chgIData(oldp+78,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out2_REG_imag),32);
        bufp->chgBit(oldp+79,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_255));
        bufp->chgCData(oldp+80,(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt),8);
        bufp->chgIData(oldp+81,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_real),32);
        bufp->chgIData(oldp+82,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_imag),32);
        bufp->chgIData(oldp+83,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_1_real),32);
        bufp->chgIData(oldp+84,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_1_imag),32);
        bufp->chgIData(oldp+85,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_2_real),32);
        bufp->chgIData(oldp+86,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_2_imag),32);
        bufp->chgIData(oldp+87,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_3_real),32);
        bufp->chgIData(oldp+88,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_3_imag),32);
        bufp->chgIData(oldp+89,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_4_real),32);
        bufp->chgIData(oldp+90,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_4_imag),32);
        bufp->chgIData(oldp+91,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_5_real),32);
        bufp->chgIData(oldp+92,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_5_imag),32);
        bufp->chgIData(oldp+93,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_6_real),32);
        bufp->chgIData(oldp+94,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_6_imag),32);
        bufp->chgIData(oldp+95,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_7_real),32);
        bufp->chgIData(oldp+96,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_7_imag),32);
        bufp->chgIData(oldp+97,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_8_real),32);
        bufp->chgIData(oldp+98,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_8_imag),32);
        bufp->chgIData(oldp+99,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_9_real),32);
        bufp->chgIData(oldp+100,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_9_imag),32);
        bufp->chgIData(oldp+101,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_10_real),32);
        bufp->chgIData(oldp+102,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_10_imag),32);
        bufp->chgIData(oldp+103,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_11_real),32);
        bufp->chgIData(oldp+104,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_11_imag),32);
        bufp->chgIData(oldp+105,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_12_real),32);
        bufp->chgIData(oldp+106,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_12_imag),32);
        bufp->chgIData(oldp+107,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_13_real),32);
        bufp->chgIData(oldp+108,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_13_imag),32);
        bufp->chgIData(oldp+109,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_14_real),32);
        bufp->chgIData(oldp+110,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_14_imag),32);
        bufp->chgIData(oldp+111,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_15_real),32);
        bufp->chgIData(oldp+112,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_15_imag),32);
        bufp->chgIData(oldp+113,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_16_real),32);
        bufp->chgIData(oldp+114,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_16_imag),32);
        bufp->chgIData(oldp+115,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_17_real),32);
        bufp->chgIData(oldp+116,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_17_imag),32);
        bufp->chgIData(oldp+117,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_18_real),32);
        bufp->chgIData(oldp+118,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_18_imag),32);
        bufp->chgIData(oldp+119,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_19_real),32);
        bufp->chgIData(oldp+120,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_19_imag),32);
        bufp->chgIData(oldp+121,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_20_real),32);
        bufp->chgIData(oldp+122,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_20_imag),32);
        bufp->chgIData(oldp+123,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_21_real),32);
        bufp->chgIData(oldp+124,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_21_imag),32);
        bufp->chgIData(oldp+125,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_22_real),32);
        bufp->chgIData(oldp+126,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_22_imag),32);
        bufp->chgIData(oldp+127,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_23_real),32);
        bufp->chgIData(oldp+128,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_23_imag),32);
        bufp->chgIData(oldp+129,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_24_real),32);
        bufp->chgIData(oldp+130,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_24_imag),32);
        bufp->chgIData(oldp+131,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_25_real),32);
        bufp->chgIData(oldp+132,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_25_imag),32);
        bufp->chgIData(oldp+133,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_26_real),32);
        bufp->chgIData(oldp+134,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_26_imag),32);
        bufp->chgIData(oldp+135,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_27_real),32);
        bufp->chgIData(oldp+136,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_27_imag),32);
        bufp->chgIData(oldp+137,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_28_real),32);
        bufp->chgIData(oldp+138,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_28_imag),32);
        bufp->chgIData(oldp+139,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_29_real),32);
        bufp->chgIData(oldp+140,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_29_imag),32);
        bufp->chgIData(oldp+141,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_30_real),32);
        bufp->chgIData(oldp+142,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_30_imag),32);
        bufp->chgIData(oldp+143,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_31_real),32);
        bufp->chgIData(oldp+144,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_31_imag),32);
        bufp->chgIData(oldp+145,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_32_real),32);
        bufp->chgIData(oldp+146,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_32_imag),32);
        bufp->chgIData(oldp+147,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_33_real),32);
        bufp->chgIData(oldp+148,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_33_imag),32);
        bufp->chgIData(oldp+149,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_34_real),32);
        bufp->chgIData(oldp+150,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_34_imag),32);
        bufp->chgIData(oldp+151,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_35_real),32);
        bufp->chgIData(oldp+152,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_35_imag),32);
        bufp->chgIData(oldp+153,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_36_real),32);
        bufp->chgIData(oldp+154,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_36_imag),32);
        bufp->chgIData(oldp+155,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_37_real),32);
        bufp->chgIData(oldp+156,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_37_imag),32);
        bufp->chgIData(oldp+157,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_38_real),32);
        bufp->chgIData(oldp+158,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_38_imag),32);
        bufp->chgIData(oldp+159,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_39_real),32);
        bufp->chgIData(oldp+160,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_39_imag),32);
        bufp->chgIData(oldp+161,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_40_real),32);
        bufp->chgIData(oldp+162,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_40_imag),32);
        bufp->chgIData(oldp+163,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_41_real),32);
        bufp->chgIData(oldp+164,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_41_imag),32);
        bufp->chgIData(oldp+165,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_42_real),32);
        bufp->chgIData(oldp+166,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_42_imag),32);
        bufp->chgIData(oldp+167,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_43_real),32);
        bufp->chgIData(oldp+168,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_43_imag),32);
        bufp->chgIData(oldp+169,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_44_real),32);
        bufp->chgIData(oldp+170,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_44_imag),32);
        bufp->chgIData(oldp+171,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_45_real),32);
        bufp->chgIData(oldp+172,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_45_imag),32);
        bufp->chgIData(oldp+173,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_46_real),32);
        bufp->chgIData(oldp+174,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_46_imag),32);
        bufp->chgIData(oldp+175,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_47_real),32);
        bufp->chgIData(oldp+176,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_47_imag),32);
        bufp->chgIData(oldp+177,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_48_real),32);
        bufp->chgIData(oldp+178,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_48_imag),32);
        bufp->chgIData(oldp+179,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_49_real),32);
        bufp->chgIData(oldp+180,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_49_imag),32);
        bufp->chgIData(oldp+181,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_50_real),32);
        bufp->chgIData(oldp+182,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_50_imag),32);
        bufp->chgIData(oldp+183,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_51_real),32);
        bufp->chgIData(oldp+184,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_51_imag),32);
        bufp->chgIData(oldp+185,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_52_real),32);
        bufp->chgIData(oldp+186,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_52_imag),32);
        bufp->chgIData(oldp+187,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_53_real),32);
        bufp->chgIData(oldp+188,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_53_imag),32);
        bufp->chgIData(oldp+189,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_54_real),32);
        bufp->chgIData(oldp+190,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_54_imag),32);
        bufp->chgIData(oldp+191,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_55_real),32);
        bufp->chgIData(oldp+192,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_55_imag),32);
        bufp->chgIData(oldp+193,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_56_real),32);
        bufp->chgIData(oldp+194,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_56_imag),32);
        bufp->chgIData(oldp+195,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_57_real),32);
        bufp->chgIData(oldp+196,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_57_imag),32);
        bufp->chgIData(oldp+197,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_58_real),32);
        bufp->chgIData(oldp+198,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_58_imag),32);
        bufp->chgIData(oldp+199,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_59_real),32);
        bufp->chgIData(oldp+200,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_59_imag),32);
        bufp->chgIData(oldp+201,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_60_real),32);
        bufp->chgIData(oldp+202,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_60_imag),32);
        bufp->chgIData(oldp+203,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_61_real),32);
        bufp->chgIData(oldp+204,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_61_imag),32);
        bufp->chgIData(oldp+205,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_62_real),32);
        bufp->chgIData(oldp+206,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_62_imag),32);
        bufp->chgIData(oldp+207,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_63_real),32);
        bufp->chgIData(oldp+208,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_63_imag),32);
        bufp->chgIData(oldp+209,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_64_real),32);
        bufp->chgIData(oldp+210,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_64_imag),32);
        bufp->chgIData(oldp+211,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_65_real),32);
        bufp->chgIData(oldp+212,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_65_imag),32);
        bufp->chgIData(oldp+213,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_66_real),32);
        bufp->chgIData(oldp+214,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_66_imag),32);
        bufp->chgIData(oldp+215,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_67_real),32);
        bufp->chgIData(oldp+216,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_67_imag),32);
        bufp->chgIData(oldp+217,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_68_real),32);
        bufp->chgIData(oldp+218,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_68_imag),32);
        bufp->chgIData(oldp+219,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_69_real),32);
        bufp->chgIData(oldp+220,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_69_imag),32);
        bufp->chgIData(oldp+221,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_70_real),32);
        bufp->chgIData(oldp+222,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_70_imag),32);
        bufp->chgIData(oldp+223,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_71_real),32);
        bufp->chgIData(oldp+224,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_71_imag),32);
        bufp->chgIData(oldp+225,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_72_real),32);
        bufp->chgIData(oldp+226,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_72_imag),32);
        bufp->chgIData(oldp+227,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_73_real),32);
        bufp->chgIData(oldp+228,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_73_imag),32);
        bufp->chgIData(oldp+229,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_74_real),32);
        bufp->chgIData(oldp+230,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_74_imag),32);
        bufp->chgIData(oldp+231,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_75_real),32);
        bufp->chgIData(oldp+232,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_75_imag),32);
        bufp->chgIData(oldp+233,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_76_real),32);
        bufp->chgIData(oldp+234,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_76_imag),32);
        bufp->chgIData(oldp+235,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_77_real),32);
        bufp->chgIData(oldp+236,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_77_imag),32);
        bufp->chgIData(oldp+237,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_78_real),32);
        bufp->chgIData(oldp+238,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_78_imag),32);
        bufp->chgIData(oldp+239,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_79_real),32);
        bufp->chgIData(oldp+240,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_79_imag),32);
        bufp->chgIData(oldp+241,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_80_real),32);
        bufp->chgIData(oldp+242,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_80_imag),32);
        bufp->chgIData(oldp+243,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_81_real),32);
        bufp->chgIData(oldp+244,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_81_imag),32);
        bufp->chgIData(oldp+245,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_82_real),32);
        bufp->chgIData(oldp+246,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_82_imag),32);
        bufp->chgIData(oldp+247,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_83_real),32);
        bufp->chgIData(oldp+248,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_83_imag),32);
        bufp->chgIData(oldp+249,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_84_real),32);
        bufp->chgIData(oldp+250,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_84_imag),32);
        bufp->chgIData(oldp+251,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_85_real),32);
        bufp->chgIData(oldp+252,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_85_imag),32);
        bufp->chgIData(oldp+253,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_86_real),32);
        bufp->chgIData(oldp+254,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_86_imag),32);
        bufp->chgIData(oldp+255,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_87_real),32);
        bufp->chgIData(oldp+256,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_87_imag),32);
        bufp->chgIData(oldp+257,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_88_real),32);
        bufp->chgIData(oldp+258,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_88_imag),32);
        bufp->chgIData(oldp+259,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_89_real),32);
        bufp->chgIData(oldp+260,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_89_imag),32);
        bufp->chgIData(oldp+261,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_90_real),32);
        bufp->chgIData(oldp+262,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_90_imag),32);
        bufp->chgIData(oldp+263,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_91_real),32);
        bufp->chgIData(oldp+264,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_91_imag),32);
        bufp->chgIData(oldp+265,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_92_real),32);
        bufp->chgIData(oldp+266,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_92_imag),32);
        bufp->chgIData(oldp+267,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_93_real),32);
        bufp->chgIData(oldp+268,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_93_imag),32);
        bufp->chgIData(oldp+269,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_94_real),32);
        bufp->chgIData(oldp+270,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_94_imag),32);
        bufp->chgIData(oldp+271,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_95_real),32);
        bufp->chgIData(oldp+272,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_95_imag),32);
        bufp->chgIData(oldp+273,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_96_real),32);
        bufp->chgIData(oldp+274,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_96_imag),32);
        bufp->chgIData(oldp+275,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_97_real),32);
        bufp->chgIData(oldp+276,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_97_imag),32);
        bufp->chgIData(oldp+277,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_98_real),32);
        bufp->chgIData(oldp+278,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_98_imag),32);
        bufp->chgIData(oldp+279,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_99_real),32);
        bufp->chgIData(oldp+280,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_99_imag),32);
        bufp->chgIData(oldp+281,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_100_real),32);
        bufp->chgIData(oldp+282,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_100_imag),32);
        bufp->chgIData(oldp+283,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_101_real),32);
        bufp->chgIData(oldp+284,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_101_imag),32);
        bufp->chgIData(oldp+285,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_102_real),32);
        bufp->chgIData(oldp+286,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_102_imag),32);
        bufp->chgIData(oldp+287,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_103_real),32);
        bufp->chgIData(oldp+288,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_103_imag),32);
        bufp->chgIData(oldp+289,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_104_real),32);
        bufp->chgIData(oldp+290,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_104_imag),32);
        bufp->chgIData(oldp+291,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_105_real),32);
        bufp->chgIData(oldp+292,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_105_imag),32);
        bufp->chgIData(oldp+293,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_106_real),32);
        bufp->chgIData(oldp+294,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_106_imag),32);
        bufp->chgIData(oldp+295,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_107_real),32);
        bufp->chgIData(oldp+296,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_107_imag),32);
        bufp->chgIData(oldp+297,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_108_real),32);
        bufp->chgIData(oldp+298,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_108_imag),32);
        bufp->chgIData(oldp+299,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_109_real),32);
        bufp->chgIData(oldp+300,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_109_imag),32);
        bufp->chgIData(oldp+301,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_110_real),32);
        bufp->chgIData(oldp+302,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_110_imag),32);
        bufp->chgIData(oldp+303,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_111_real),32);
        bufp->chgIData(oldp+304,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_111_imag),32);
        bufp->chgIData(oldp+305,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_112_real),32);
        bufp->chgIData(oldp+306,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_112_imag),32);
        bufp->chgIData(oldp+307,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_113_real),32);
        bufp->chgIData(oldp+308,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_113_imag),32);
        bufp->chgIData(oldp+309,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_114_real),32);
        bufp->chgIData(oldp+310,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_114_imag),32);
        bufp->chgIData(oldp+311,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_115_real),32);
        bufp->chgIData(oldp+312,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_115_imag),32);
        bufp->chgIData(oldp+313,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_116_real),32);
        bufp->chgIData(oldp+314,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_116_imag),32);
        bufp->chgIData(oldp+315,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_117_real),32);
        bufp->chgIData(oldp+316,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_117_imag),32);
        bufp->chgIData(oldp+317,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_118_real),32);
        bufp->chgIData(oldp+318,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_118_imag),32);
        bufp->chgIData(oldp+319,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_119_real),32);
        bufp->chgIData(oldp+320,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_119_imag),32);
        bufp->chgIData(oldp+321,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_120_real),32);
        bufp->chgIData(oldp+322,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_120_imag),32);
        bufp->chgIData(oldp+323,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_121_real),32);
        bufp->chgIData(oldp+324,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_121_imag),32);
        bufp->chgIData(oldp+325,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_122_real),32);
        bufp->chgIData(oldp+326,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_122_imag),32);
        bufp->chgIData(oldp+327,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_123_real),32);
        bufp->chgIData(oldp+328,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_123_imag),32);
        bufp->chgIData(oldp+329,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_124_real),32);
        bufp->chgIData(oldp+330,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_124_imag),32);
        bufp->chgIData(oldp+331,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_125_real),32);
        bufp->chgIData(oldp+332,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_125_imag),32);
        bufp->chgIData(oldp+333,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_126_real),32);
        bufp->chgIData(oldp+334,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_126_imag),32);
        bufp->chgIData(oldp+335,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_real),32);
        bufp->chgIData(oldp+336,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_127_imag),32);
        bufp->chgIData(oldp+337,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_128_real),32);
        bufp->chgIData(oldp+338,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_128_imag),32);
        bufp->chgIData(oldp+339,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_129_real),32);
        bufp->chgIData(oldp+340,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_129_imag),32);
        bufp->chgIData(oldp+341,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_130_real),32);
        bufp->chgIData(oldp+342,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_130_imag),32);
        bufp->chgIData(oldp+343,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_131_real),32);
        bufp->chgIData(oldp+344,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_131_imag),32);
        bufp->chgIData(oldp+345,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_132_real),32);
        bufp->chgIData(oldp+346,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_132_imag),32);
        bufp->chgIData(oldp+347,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_133_real),32);
        bufp->chgIData(oldp+348,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_133_imag),32);
        bufp->chgIData(oldp+349,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_134_real),32);
        bufp->chgIData(oldp+350,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_134_imag),32);
        bufp->chgIData(oldp+351,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_135_real),32);
        bufp->chgIData(oldp+352,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_135_imag),32);
        bufp->chgIData(oldp+353,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_136_real),32);
        bufp->chgIData(oldp+354,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_136_imag),32);
        bufp->chgIData(oldp+355,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_137_real),32);
        bufp->chgIData(oldp+356,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_137_imag),32);
        bufp->chgIData(oldp+357,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_138_real),32);
        bufp->chgIData(oldp+358,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_138_imag),32);
        bufp->chgIData(oldp+359,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_139_real),32);
        bufp->chgIData(oldp+360,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_139_imag),32);
        bufp->chgIData(oldp+361,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_140_real),32);
        bufp->chgIData(oldp+362,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_140_imag),32);
        bufp->chgIData(oldp+363,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_141_real),32);
        bufp->chgIData(oldp+364,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_141_imag),32);
        bufp->chgIData(oldp+365,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_142_real),32);
        bufp->chgIData(oldp+366,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_142_imag),32);
        bufp->chgIData(oldp+367,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_143_real),32);
        bufp->chgIData(oldp+368,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_143_imag),32);
        bufp->chgIData(oldp+369,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_144_real),32);
        bufp->chgIData(oldp+370,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_144_imag),32);
        bufp->chgIData(oldp+371,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_145_real),32);
        bufp->chgIData(oldp+372,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_145_imag),32);
        bufp->chgIData(oldp+373,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_146_real),32);
        bufp->chgIData(oldp+374,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_146_imag),32);
        bufp->chgIData(oldp+375,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_147_real),32);
        bufp->chgIData(oldp+376,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_147_imag),32);
        bufp->chgIData(oldp+377,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_148_real),32);
        bufp->chgIData(oldp+378,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_148_imag),32);
        bufp->chgIData(oldp+379,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_149_real),32);
        bufp->chgIData(oldp+380,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_149_imag),32);
        bufp->chgIData(oldp+381,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_150_real),32);
        bufp->chgIData(oldp+382,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_150_imag),32);
        bufp->chgIData(oldp+383,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_151_real),32);
        bufp->chgIData(oldp+384,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_151_imag),32);
        bufp->chgIData(oldp+385,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_152_real),32);
        bufp->chgIData(oldp+386,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_152_imag),32);
        bufp->chgIData(oldp+387,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_153_real),32);
        bufp->chgIData(oldp+388,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_153_imag),32);
        bufp->chgIData(oldp+389,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_154_real),32);
        bufp->chgIData(oldp+390,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_154_imag),32);
        bufp->chgIData(oldp+391,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_155_real),32);
        bufp->chgIData(oldp+392,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_155_imag),32);
        bufp->chgIData(oldp+393,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_156_real),32);
        bufp->chgIData(oldp+394,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_156_imag),32);
        bufp->chgIData(oldp+395,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_157_real),32);
        bufp->chgIData(oldp+396,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_157_imag),32);
        bufp->chgIData(oldp+397,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_158_real),32);
        bufp->chgIData(oldp+398,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_158_imag),32);
        bufp->chgIData(oldp+399,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_159_real),32);
        bufp->chgIData(oldp+400,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_159_imag),32);
        bufp->chgIData(oldp+401,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_160_real),32);
        bufp->chgIData(oldp+402,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_160_imag),32);
        bufp->chgIData(oldp+403,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_161_real),32);
        bufp->chgIData(oldp+404,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_161_imag),32);
        bufp->chgIData(oldp+405,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_162_real),32);
        bufp->chgIData(oldp+406,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_162_imag),32);
        bufp->chgIData(oldp+407,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_163_real),32);
        bufp->chgIData(oldp+408,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_163_imag),32);
        bufp->chgIData(oldp+409,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_164_real),32);
        bufp->chgIData(oldp+410,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_164_imag),32);
        bufp->chgIData(oldp+411,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_165_real),32);
        bufp->chgIData(oldp+412,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_165_imag),32);
        bufp->chgIData(oldp+413,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_166_real),32);
        bufp->chgIData(oldp+414,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_166_imag),32);
        bufp->chgIData(oldp+415,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_167_real),32);
        bufp->chgIData(oldp+416,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_167_imag),32);
        bufp->chgIData(oldp+417,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_168_real),32);
        bufp->chgIData(oldp+418,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_168_imag),32);
        bufp->chgIData(oldp+419,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_169_real),32);
        bufp->chgIData(oldp+420,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_169_imag),32);
        bufp->chgIData(oldp+421,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_170_real),32);
        bufp->chgIData(oldp+422,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_170_imag),32);
        bufp->chgIData(oldp+423,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_171_real),32);
        bufp->chgIData(oldp+424,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_171_imag),32);
        bufp->chgIData(oldp+425,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_172_real),32);
        bufp->chgIData(oldp+426,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_172_imag),32);
        bufp->chgIData(oldp+427,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_173_real),32);
        bufp->chgIData(oldp+428,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_173_imag),32);
        bufp->chgIData(oldp+429,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_174_real),32);
        bufp->chgIData(oldp+430,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_174_imag),32);
        bufp->chgIData(oldp+431,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_175_real),32);
        bufp->chgIData(oldp+432,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_175_imag),32);
        bufp->chgIData(oldp+433,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_176_real),32);
        bufp->chgIData(oldp+434,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_176_imag),32);
        bufp->chgIData(oldp+435,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_177_real),32);
        bufp->chgIData(oldp+436,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_177_imag),32);
        bufp->chgIData(oldp+437,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_178_real),32);
        bufp->chgIData(oldp+438,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_178_imag),32);
        bufp->chgIData(oldp+439,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_179_real),32);
        bufp->chgIData(oldp+440,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_179_imag),32);
        bufp->chgIData(oldp+441,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_180_real),32);
        bufp->chgIData(oldp+442,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_180_imag),32);
        bufp->chgIData(oldp+443,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_181_real),32);
        bufp->chgIData(oldp+444,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_181_imag),32);
        bufp->chgIData(oldp+445,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_182_real),32);
        bufp->chgIData(oldp+446,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_182_imag),32);
        bufp->chgIData(oldp+447,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_183_real),32);
        bufp->chgIData(oldp+448,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_183_imag),32);
        bufp->chgIData(oldp+449,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_184_real),32);
        bufp->chgIData(oldp+450,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_184_imag),32);
        bufp->chgIData(oldp+451,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_185_real),32);
        bufp->chgIData(oldp+452,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_185_imag),32);
        bufp->chgIData(oldp+453,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_186_real),32);
        bufp->chgIData(oldp+454,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_186_imag),32);
        bufp->chgIData(oldp+455,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_187_real),32);
        bufp->chgIData(oldp+456,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_187_imag),32);
        bufp->chgIData(oldp+457,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_188_real),32);
        bufp->chgIData(oldp+458,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_188_imag),32);
        bufp->chgIData(oldp+459,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_189_real),32);
        bufp->chgIData(oldp+460,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_189_imag),32);
        bufp->chgIData(oldp+461,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_190_real),32);
        bufp->chgIData(oldp+462,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_190_imag),32);
        bufp->chgIData(oldp+463,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_real),32);
        bufp->chgIData(oldp+464,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_191_imag),32);
        bufp->chgIData(oldp+465,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_192_real),32);
        bufp->chgIData(oldp+466,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_192_imag),32);
        bufp->chgIData(oldp+467,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_193_real),32);
        bufp->chgIData(oldp+468,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_193_imag),32);
        bufp->chgIData(oldp+469,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_194_real),32);
        bufp->chgIData(oldp+470,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_194_imag),32);
        bufp->chgIData(oldp+471,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_195_real),32);
        bufp->chgIData(oldp+472,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_195_imag),32);
        bufp->chgIData(oldp+473,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_196_real),32);
        bufp->chgIData(oldp+474,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_196_imag),32);
        bufp->chgIData(oldp+475,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_197_real),32);
        bufp->chgIData(oldp+476,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_197_imag),32);
        bufp->chgIData(oldp+477,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_198_real),32);
        bufp->chgIData(oldp+478,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_198_imag),32);
        bufp->chgIData(oldp+479,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_199_real),32);
        bufp->chgIData(oldp+480,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_199_imag),32);
        bufp->chgIData(oldp+481,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_200_real),32);
        bufp->chgIData(oldp+482,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_200_imag),32);
        bufp->chgIData(oldp+483,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_201_real),32);
        bufp->chgIData(oldp+484,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_201_imag),32);
        bufp->chgIData(oldp+485,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_202_real),32);
        bufp->chgIData(oldp+486,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_202_imag),32);
        bufp->chgIData(oldp+487,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_203_real),32);
        bufp->chgIData(oldp+488,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_203_imag),32);
        bufp->chgIData(oldp+489,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_204_real),32);
        bufp->chgIData(oldp+490,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_204_imag),32);
        bufp->chgIData(oldp+491,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_205_real),32);
        bufp->chgIData(oldp+492,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_205_imag),32);
        bufp->chgIData(oldp+493,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_206_real),32);
        bufp->chgIData(oldp+494,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_206_imag),32);
        bufp->chgIData(oldp+495,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_207_real),32);
        bufp->chgIData(oldp+496,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_207_imag),32);
        bufp->chgIData(oldp+497,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_208_real),32);
        bufp->chgIData(oldp+498,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_208_imag),32);
        bufp->chgIData(oldp+499,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_209_real),32);
        bufp->chgIData(oldp+500,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_209_imag),32);
        bufp->chgIData(oldp+501,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_210_real),32);
        bufp->chgIData(oldp+502,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_210_imag),32);
        bufp->chgIData(oldp+503,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_211_real),32);
        bufp->chgIData(oldp+504,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_211_imag),32);
        bufp->chgIData(oldp+505,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_212_real),32);
        bufp->chgIData(oldp+506,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_212_imag),32);
        bufp->chgIData(oldp+507,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_213_real),32);
        bufp->chgIData(oldp+508,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_213_imag),32);
        bufp->chgIData(oldp+509,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_214_real),32);
        bufp->chgIData(oldp+510,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_214_imag),32);
        bufp->chgIData(oldp+511,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_215_real),32);
        bufp->chgIData(oldp+512,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_215_imag),32);
        bufp->chgIData(oldp+513,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_216_real),32);
        bufp->chgIData(oldp+514,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_216_imag),32);
        bufp->chgIData(oldp+515,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_217_real),32);
        bufp->chgIData(oldp+516,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_217_imag),32);
        bufp->chgIData(oldp+517,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_218_real),32);
        bufp->chgIData(oldp+518,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_218_imag),32);
        bufp->chgIData(oldp+519,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_219_real),32);
        bufp->chgIData(oldp+520,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_219_imag),32);
        bufp->chgIData(oldp+521,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_220_real),32);
        bufp->chgIData(oldp+522,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_220_imag),32);
        bufp->chgIData(oldp+523,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_221_real),32);
        bufp->chgIData(oldp+524,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_221_imag),32);
        bufp->chgIData(oldp+525,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_222_real),32);
        bufp->chgIData(oldp+526,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_222_imag),32);
        bufp->chgIData(oldp+527,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_223_real),32);
        bufp->chgIData(oldp+528,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_223_imag),32);
        bufp->chgIData(oldp+529,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_224_real),32);
        bufp->chgIData(oldp+530,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_224_imag),32);
        bufp->chgIData(oldp+531,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_225_real),32);
        bufp->chgIData(oldp+532,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_225_imag),32);
        bufp->chgIData(oldp+533,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_226_real),32);
        bufp->chgIData(oldp+534,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_226_imag),32);
        bufp->chgIData(oldp+535,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_227_real),32);
        bufp->chgIData(oldp+536,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_227_imag),32);
        bufp->chgIData(oldp+537,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_228_real),32);
        bufp->chgIData(oldp+538,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_228_imag),32);
        bufp->chgIData(oldp+539,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_229_real),32);
        bufp->chgIData(oldp+540,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_229_imag),32);
        bufp->chgIData(oldp+541,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_230_real),32);
        bufp->chgIData(oldp+542,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_230_imag),32);
        bufp->chgIData(oldp+543,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_231_real),32);
        bufp->chgIData(oldp+544,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_231_imag),32);
        bufp->chgIData(oldp+545,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_232_real),32);
        bufp->chgIData(oldp+546,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_232_imag),32);
        bufp->chgIData(oldp+547,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_233_real),32);
        bufp->chgIData(oldp+548,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_233_imag),32);
        bufp->chgIData(oldp+549,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_234_real),32);
        bufp->chgIData(oldp+550,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_234_imag),32);
        bufp->chgIData(oldp+551,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_235_real),32);
        bufp->chgIData(oldp+552,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_235_imag),32);
        bufp->chgIData(oldp+553,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_236_real),32);
        bufp->chgIData(oldp+554,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_236_imag),32);
        bufp->chgIData(oldp+555,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_237_real),32);
        bufp->chgIData(oldp+556,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_237_imag),32);
        bufp->chgIData(oldp+557,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_238_real),32);
        bufp->chgIData(oldp+558,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_238_imag),32);
        bufp->chgIData(oldp+559,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_239_real),32);
        bufp->chgIData(oldp+560,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_239_imag),32);
        bufp->chgIData(oldp+561,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_240_real),32);
        bufp->chgIData(oldp+562,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_240_imag),32);
        bufp->chgIData(oldp+563,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_241_real),32);
        bufp->chgIData(oldp+564,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_241_imag),32);
        bufp->chgIData(oldp+565,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_242_real),32);
        bufp->chgIData(oldp+566,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_242_imag),32);
        bufp->chgIData(oldp+567,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_243_real),32);
        bufp->chgIData(oldp+568,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_243_imag),32);
        bufp->chgIData(oldp+569,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_244_real),32);
        bufp->chgIData(oldp+570,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_244_imag),32);
        bufp->chgIData(oldp+571,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_245_real),32);
        bufp->chgIData(oldp+572,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_245_imag),32);
        bufp->chgIData(oldp+573,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_246_real),32);
        bufp->chgIData(oldp+574,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_246_imag),32);
        bufp->chgIData(oldp+575,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_247_real),32);
        bufp->chgIData(oldp+576,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_247_imag),32);
        bufp->chgIData(oldp+577,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_248_real),32);
        bufp->chgIData(oldp+578,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_248_imag),32);
        bufp->chgIData(oldp+579,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_249_real),32);
        bufp->chgIData(oldp+580,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_249_imag),32);
        bufp->chgIData(oldp+581,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_250_real),32);
        bufp->chgIData(oldp+582,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_250_imag),32);
        bufp->chgIData(oldp+583,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_251_real),32);
        bufp->chgIData(oldp+584,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_251_imag),32);
        bufp->chgIData(oldp+585,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_252_real),32);
        bufp->chgIData(oldp+586,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_252_imag),32);
        bufp->chgIData(oldp+587,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_253_real),32);
        bufp->chgIData(oldp+588,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_253_imag),32);
        bufp->chgIData(oldp+589,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_254_real),32);
        bufp->chgIData(oldp+590,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_254_imag),32);
        bufp->chgIData(oldp+591,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_real),32);
        bufp->chgIData(oldp+592,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_255_imag),32);
        bufp->chgIData(oldp+593,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_256_real),32);
        bufp->chgIData(oldp+594,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_256_imag),32);
        bufp->chgIData(oldp+595,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_257_real),32);
        bufp->chgIData(oldp+596,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_257_imag),32);
        bufp->chgIData(oldp+597,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_258_real),32);
        bufp->chgIData(oldp+598,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_258_imag),32);
        bufp->chgIData(oldp+599,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_259_real),32);
        bufp->chgIData(oldp+600,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_259_imag),32);
        bufp->chgIData(oldp+601,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_260_real),32);
        bufp->chgIData(oldp+602,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_260_imag),32);
        bufp->chgIData(oldp+603,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_261_real),32);
        bufp->chgIData(oldp+604,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_261_imag),32);
        bufp->chgIData(oldp+605,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_262_real),32);
        bufp->chgIData(oldp+606,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_262_imag),32);
        bufp->chgIData(oldp+607,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_263_real),32);
        bufp->chgIData(oldp+608,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_263_imag),32);
        bufp->chgIData(oldp+609,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_264_real),32);
        bufp->chgIData(oldp+610,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_264_imag),32);
        bufp->chgIData(oldp+611,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_265_real),32);
        bufp->chgIData(oldp+612,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_265_imag),32);
        bufp->chgIData(oldp+613,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_266_real),32);
        bufp->chgIData(oldp+614,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_266_imag),32);
        bufp->chgIData(oldp+615,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_267_real),32);
        bufp->chgIData(oldp+616,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_267_imag),32);
        bufp->chgIData(oldp+617,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_268_real),32);
        bufp->chgIData(oldp+618,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_268_imag),32);
        bufp->chgIData(oldp+619,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_269_real),32);
        bufp->chgIData(oldp+620,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_269_imag),32);
        bufp->chgIData(oldp+621,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_270_real),32);
        bufp->chgIData(oldp+622,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_270_imag),32);
        bufp->chgIData(oldp+623,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_271_real),32);
        bufp->chgIData(oldp+624,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_271_imag),32);
        bufp->chgIData(oldp+625,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_272_real),32);
        bufp->chgIData(oldp+626,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_272_imag),32);
        bufp->chgIData(oldp+627,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_273_real),32);
        bufp->chgIData(oldp+628,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_273_imag),32);
        bufp->chgIData(oldp+629,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_274_real),32);
        bufp->chgIData(oldp+630,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_274_imag),32);
        bufp->chgIData(oldp+631,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_275_real),32);
        bufp->chgIData(oldp+632,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_275_imag),32);
        bufp->chgIData(oldp+633,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_276_real),32);
        bufp->chgIData(oldp+634,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_276_imag),32);
        bufp->chgIData(oldp+635,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_277_real),32);
        bufp->chgIData(oldp+636,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_277_imag),32);
        bufp->chgIData(oldp+637,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_278_real),32);
        bufp->chgIData(oldp+638,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_278_imag),32);
        bufp->chgIData(oldp+639,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_279_real),32);
        bufp->chgIData(oldp+640,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_279_imag),32);
        bufp->chgIData(oldp+641,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_280_real),32);
        bufp->chgIData(oldp+642,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_280_imag),32);
        bufp->chgIData(oldp+643,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_281_real),32);
        bufp->chgIData(oldp+644,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_281_imag),32);
        bufp->chgIData(oldp+645,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_282_real),32);
        bufp->chgIData(oldp+646,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_282_imag),32);
        bufp->chgIData(oldp+647,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_283_real),32);
        bufp->chgIData(oldp+648,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_283_imag),32);
        bufp->chgIData(oldp+649,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_284_real),32);
        bufp->chgIData(oldp+650,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_284_imag),32);
        bufp->chgIData(oldp+651,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_285_real),32);
        bufp->chgIData(oldp+652,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_285_imag),32);
        bufp->chgIData(oldp+653,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_286_real),32);
        bufp->chgIData(oldp+654,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_286_imag),32);
        bufp->chgIData(oldp+655,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_real),32);
        bufp->chgIData(oldp+656,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_287_imag),32);
        bufp->chgIData(oldp+657,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_288_real),32);
        bufp->chgIData(oldp+658,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_288_imag),32);
        bufp->chgIData(oldp+659,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_289_real),32);
        bufp->chgIData(oldp+660,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_289_imag),32);
        bufp->chgIData(oldp+661,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_290_real),32);
        bufp->chgIData(oldp+662,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_290_imag),32);
        bufp->chgIData(oldp+663,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_291_real),32);
        bufp->chgIData(oldp+664,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_291_imag),32);
        bufp->chgIData(oldp+665,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_292_real),32);
        bufp->chgIData(oldp+666,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_292_imag),32);
        bufp->chgIData(oldp+667,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_293_real),32);
        bufp->chgIData(oldp+668,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_293_imag),32);
        bufp->chgIData(oldp+669,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_294_real),32);
        bufp->chgIData(oldp+670,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_294_imag),32);
        bufp->chgIData(oldp+671,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_295_real),32);
        bufp->chgIData(oldp+672,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_295_imag),32);
        bufp->chgIData(oldp+673,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_296_real),32);
        bufp->chgIData(oldp+674,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_296_imag),32);
        bufp->chgIData(oldp+675,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_297_real),32);
        bufp->chgIData(oldp+676,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_297_imag),32);
        bufp->chgIData(oldp+677,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_298_real),32);
        bufp->chgIData(oldp+678,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_298_imag),32);
        bufp->chgIData(oldp+679,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_299_real),32);
        bufp->chgIData(oldp+680,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_299_imag),32);
        bufp->chgIData(oldp+681,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_300_real),32);
        bufp->chgIData(oldp+682,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_300_imag),32);
        bufp->chgIData(oldp+683,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_301_real),32);
        bufp->chgIData(oldp+684,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_301_imag),32);
        bufp->chgIData(oldp+685,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_302_real),32);
        bufp->chgIData(oldp+686,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_302_imag),32);
        bufp->chgIData(oldp+687,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_303_real),32);
        bufp->chgIData(oldp+688,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_303_imag),32);
        bufp->chgIData(oldp+689,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_304_real),32);
        bufp->chgIData(oldp+690,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_304_imag),32);
        bufp->chgIData(oldp+691,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_305_real),32);
        bufp->chgIData(oldp+692,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_305_imag),32);
        bufp->chgIData(oldp+693,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_306_real),32);
        bufp->chgIData(oldp+694,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_306_imag),32);
        bufp->chgIData(oldp+695,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_307_real),32);
        bufp->chgIData(oldp+696,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_307_imag),32);
        bufp->chgIData(oldp+697,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_308_real),32);
        bufp->chgIData(oldp+698,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_308_imag),32);
        bufp->chgIData(oldp+699,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_309_real),32);
        bufp->chgIData(oldp+700,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_309_imag),32);
        bufp->chgIData(oldp+701,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_310_real),32);
        bufp->chgIData(oldp+702,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_310_imag),32);
        bufp->chgIData(oldp+703,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_311_real),32);
        bufp->chgIData(oldp+704,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_311_imag),32);
        bufp->chgIData(oldp+705,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_312_real),32);
        bufp->chgIData(oldp+706,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_312_imag),32);
        bufp->chgIData(oldp+707,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_313_real),32);
        bufp->chgIData(oldp+708,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_313_imag),32);
        bufp->chgIData(oldp+709,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_314_real),32);
        bufp->chgIData(oldp+710,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_314_imag),32);
        bufp->chgIData(oldp+711,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_315_real),32);
        bufp->chgIData(oldp+712,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_315_imag),32);
        bufp->chgIData(oldp+713,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_316_real),32);
        bufp->chgIData(oldp+714,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_316_imag),32);
        bufp->chgIData(oldp+715,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_317_real),32);
        bufp->chgIData(oldp+716,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_317_imag),32);
        bufp->chgIData(oldp+717,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_318_real),32);
        bufp->chgIData(oldp+718,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_318_imag),32);
        bufp->chgIData(oldp+719,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_real),32);
        bufp->chgIData(oldp+720,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_319_imag),32);
        bufp->chgIData(oldp+721,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_320_real),32);
        bufp->chgIData(oldp+722,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_320_imag),32);
        bufp->chgIData(oldp+723,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_321_real),32);
        bufp->chgIData(oldp+724,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_321_imag),32);
        bufp->chgIData(oldp+725,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_322_real),32);
        bufp->chgIData(oldp+726,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_322_imag),32);
        bufp->chgIData(oldp+727,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_323_real),32);
        bufp->chgIData(oldp+728,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_323_imag),32);
        bufp->chgIData(oldp+729,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_324_real),32);
        bufp->chgIData(oldp+730,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_324_imag),32);
        bufp->chgIData(oldp+731,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_325_real),32);
        bufp->chgIData(oldp+732,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_325_imag),32);
        bufp->chgIData(oldp+733,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_326_real),32);
        bufp->chgIData(oldp+734,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_326_imag),32);
        bufp->chgIData(oldp+735,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_327_real),32);
        bufp->chgIData(oldp+736,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_327_imag),32);
        bufp->chgIData(oldp+737,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_328_real),32);
        bufp->chgIData(oldp+738,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_328_imag),32);
        bufp->chgIData(oldp+739,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_329_real),32);
        bufp->chgIData(oldp+740,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_329_imag),32);
        bufp->chgIData(oldp+741,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_330_real),32);
        bufp->chgIData(oldp+742,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_330_imag),32);
        bufp->chgIData(oldp+743,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_331_real),32);
        bufp->chgIData(oldp+744,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_331_imag),32);
        bufp->chgIData(oldp+745,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_332_real),32);
        bufp->chgIData(oldp+746,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_332_imag),32);
        bufp->chgIData(oldp+747,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_333_real),32);
        bufp->chgIData(oldp+748,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_333_imag),32);
        bufp->chgIData(oldp+749,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_334_real),32);
        bufp->chgIData(oldp+750,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_334_imag),32);
        bufp->chgIData(oldp+751,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_real),32);
        bufp->chgIData(oldp+752,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_335_imag),32);
        bufp->chgIData(oldp+753,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_336_real),32);
        bufp->chgIData(oldp+754,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_336_imag),32);
        bufp->chgIData(oldp+755,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_337_real),32);
        bufp->chgIData(oldp+756,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_337_imag),32);
        bufp->chgIData(oldp+757,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_338_real),32);
        bufp->chgIData(oldp+758,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_338_imag),32);
        bufp->chgIData(oldp+759,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_339_real),32);
        bufp->chgIData(oldp+760,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_339_imag),32);
        bufp->chgIData(oldp+761,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_340_real),32);
        bufp->chgIData(oldp+762,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_340_imag),32);
        bufp->chgIData(oldp+763,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_341_real),32);
        bufp->chgIData(oldp+764,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_341_imag),32);
        bufp->chgIData(oldp+765,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_342_real),32);
        bufp->chgIData(oldp+766,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_342_imag),32);
        bufp->chgIData(oldp+767,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_343_real),32);
        bufp->chgIData(oldp+768,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_343_imag),32);
        bufp->chgIData(oldp+769,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_344_real),32);
        bufp->chgIData(oldp+770,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_344_imag),32);
        bufp->chgIData(oldp+771,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_345_real),32);
        bufp->chgIData(oldp+772,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_345_imag),32);
        bufp->chgIData(oldp+773,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_346_real),32);
        bufp->chgIData(oldp+774,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_346_imag),32);
        bufp->chgIData(oldp+775,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_347_real),32);
        bufp->chgIData(oldp+776,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_347_imag),32);
        bufp->chgIData(oldp+777,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_348_real),32);
        bufp->chgIData(oldp+778,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_348_imag),32);
        bufp->chgIData(oldp+779,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_349_real),32);
        bufp->chgIData(oldp+780,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_349_imag),32);
        bufp->chgIData(oldp+781,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_350_real),32);
        bufp->chgIData(oldp+782,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_350_imag),32);
        bufp->chgIData(oldp+783,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_real),32);
        bufp->chgIData(oldp+784,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_351_imag),32);
        bufp->chgIData(oldp+785,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_352_real),32);
        bufp->chgIData(oldp+786,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_352_imag),32);
        bufp->chgIData(oldp+787,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_353_real),32);
        bufp->chgIData(oldp+788,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_353_imag),32);
        bufp->chgIData(oldp+789,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_354_real),32);
        bufp->chgIData(oldp+790,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_354_imag),32);
        bufp->chgIData(oldp+791,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_355_real),32);
        bufp->chgIData(oldp+792,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_355_imag),32);
        bufp->chgIData(oldp+793,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_356_real),32);
        bufp->chgIData(oldp+794,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_356_imag),32);
        bufp->chgIData(oldp+795,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_357_real),32);
        bufp->chgIData(oldp+796,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_357_imag),32);
        bufp->chgIData(oldp+797,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_358_real),32);
        bufp->chgIData(oldp+798,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_358_imag),32);
        bufp->chgIData(oldp+799,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_real),32);
        bufp->chgIData(oldp+800,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_359_imag),32);
        bufp->chgIData(oldp+801,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_360_real),32);
        bufp->chgIData(oldp+802,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_360_imag),32);
        bufp->chgIData(oldp+803,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_361_real),32);
        bufp->chgIData(oldp+804,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_361_imag),32);
        bufp->chgIData(oldp+805,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_362_real),32);
        bufp->chgIData(oldp+806,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_362_imag),32);
        bufp->chgIData(oldp+807,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_363_real),32);
        bufp->chgIData(oldp+808,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_363_imag),32);
        bufp->chgIData(oldp+809,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_364_real),32);
        bufp->chgIData(oldp+810,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_364_imag),32);
        bufp->chgIData(oldp+811,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_365_real),32);
        bufp->chgIData(oldp+812,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_365_imag),32);
        bufp->chgIData(oldp+813,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_366_real),32);
        bufp->chgIData(oldp+814,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_366_imag),32);
        bufp->chgIData(oldp+815,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_real),32);
        bufp->chgIData(oldp+816,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_367_imag),32);
        bufp->chgIData(oldp+817,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_368_real),32);
        bufp->chgIData(oldp+818,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_368_imag),32);
        bufp->chgIData(oldp+819,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_369_real),32);
        bufp->chgIData(oldp+820,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_369_imag),32);
        bufp->chgIData(oldp+821,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_370_real),32);
        bufp->chgIData(oldp+822,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_370_imag),32);
        bufp->chgIData(oldp+823,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_real),32);
        bufp->chgIData(oldp+824,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_371_imag),32);
        bufp->chgIData(oldp+825,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_372_real),32);
        bufp->chgIData(oldp+826,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_372_imag),32);
        bufp->chgIData(oldp+827,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_373_real),32);
        bufp->chgIData(oldp+828,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_373_imag),32);
        bufp->chgIData(oldp+829,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_374_real),32);
        bufp->chgIData(oldp+830,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_374_imag),32);
        bufp->chgIData(oldp+831,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_real),32);
        bufp->chgIData(oldp+832,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_375_imag),32);
        bufp->chgIData(oldp+833,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_376_real),32);
        bufp->chgIData(oldp+834,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_376_imag),32);
        bufp->chgIData(oldp+835,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_real),32);
        bufp->chgIData(oldp+836,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_377_imag),32);
        bufp->chgIData(oldp+837,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_378_real),32);
        bufp->chgIData(oldp+838,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_378_imag),32);
        bufp->chgIData(oldp+839,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_real),32);
        bufp->chgIData(oldp+840,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_379_imag),32);
        bufp->chgIData(oldp+841,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_real),32);
        bufp->chgIData(oldp+842,(vlSelfRef.FFT256_tb__DOT__uut__DOT__r_380_imag),32);
        bufp->chgIData(oldp+843,(vlSelfRef.FFT256_tb__DOT__uut__DOT__out1_real),32);
        bufp->chgIData(oldp+844,(vlSelfRef.FFT256_tb__DOT__uut__DOT__out1_imag),32);
        bufp->chgBit(oldp+845,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r));
        bufp->chgBit(oldp+846,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_1));
        bufp->chgBit(oldp+847,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_2));
        bufp->chgBit(oldp+848,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_3));
        bufp->chgBit(oldp+849,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_4));
        bufp->chgBit(oldp+850,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_5));
        bufp->chgBit(oldp+851,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_6));
        bufp->chgBit(oldp+852,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_7));
        bufp->chgBit(oldp+853,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_8));
        bufp->chgBit(oldp+854,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_9));
        bufp->chgBit(oldp+855,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_10));
        bufp->chgBit(oldp+856,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_11));
        bufp->chgBit(oldp+857,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_12));
        bufp->chgBit(oldp+858,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_13));
        bufp->chgBit(oldp+859,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_14));
        bufp->chgBit(oldp+860,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_15));
        bufp->chgBit(oldp+861,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_16));
        bufp->chgBit(oldp+862,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_17));
        bufp->chgBit(oldp+863,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_18));
        bufp->chgBit(oldp+864,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_19));
        bufp->chgBit(oldp+865,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_20));
        bufp->chgBit(oldp+866,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_21));
        bufp->chgBit(oldp+867,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_22));
        bufp->chgBit(oldp+868,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_23));
        bufp->chgBit(oldp+869,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_24));
        bufp->chgBit(oldp+870,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_25));
        bufp->chgBit(oldp+871,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_26));
        bufp->chgBit(oldp+872,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_27));
        bufp->chgBit(oldp+873,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_28));
        bufp->chgBit(oldp+874,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_29));
        bufp->chgBit(oldp+875,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_30));
        bufp->chgBit(oldp+876,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_31));
        bufp->chgBit(oldp+877,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_32));
        bufp->chgBit(oldp+878,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_33));
        bufp->chgBit(oldp+879,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_34));
        bufp->chgBit(oldp+880,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_35));
        bufp->chgBit(oldp+881,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_36));
        bufp->chgBit(oldp+882,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_37));
        bufp->chgBit(oldp+883,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_38));
        bufp->chgBit(oldp+884,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_39));
        bufp->chgBit(oldp+885,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_40));
        bufp->chgBit(oldp+886,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_41));
        bufp->chgBit(oldp+887,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_42));
        bufp->chgBit(oldp+888,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_43));
        bufp->chgBit(oldp+889,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_44));
        bufp->chgBit(oldp+890,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_45));
        bufp->chgBit(oldp+891,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_46));
        bufp->chgBit(oldp+892,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_47));
        bufp->chgBit(oldp+893,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_48));
        bufp->chgBit(oldp+894,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_49));
        bufp->chgBit(oldp+895,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_50));
        bufp->chgBit(oldp+896,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_51));
        bufp->chgBit(oldp+897,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_52));
        bufp->chgBit(oldp+898,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_53));
        bufp->chgBit(oldp+899,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_54));
        bufp->chgBit(oldp+900,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_55));
        bufp->chgBit(oldp+901,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_56));
        bufp->chgBit(oldp+902,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_57));
        bufp->chgBit(oldp+903,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_58));
        bufp->chgBit(oldp+904,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_59));
        bufp->chgBit(oldp+905,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_60));
        bufp->chgBit(oldp+906,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_61));
        bufp->chgBit(oldp+907,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_62));
        bufp->chgBit(oldp+908,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_63));
        bufp->chgBit(oldp+909,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_64));
        bufp->chgBit(oldp+910,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_65));
        bufp->chgBit(oldp+911,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_66));
        bufp->chgBit(oldp+912,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_67));
        bufp->chgBit(oldp+913,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_68));
        bufp->chgBit(oldp+914,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_69));
        bufp->chgBit(oldp+915,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_70));
        bufp->chgBit(oldp+916,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_71));
        bufp->chgBit(oldp+917,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_72));
        bufp->chgBit(oldp+918,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_73));
        bufp->chgBit(oldp+919,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_74));
        bufp->chgBit(oldp+920,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_75));
        bufp->chgBit(oldp+921,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_76));
        bufp->chgBit(oldp+922,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_77));
        bufp->chgBit(oldp+923,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_78));
        bufp->chgBit(oldp+924,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_79));
        bufp->chgBit(oldp+925,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_80));
        bufp->chgBit(oldp+926,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_81));
        bufp->chgBit(oldp+927,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_82));
        bufp->chgBit(oldp+928,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_83));
        bufp->chgBit(oldp+929,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_84));
        bufp->chgBit(oldp+930,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_85));
        bufp->chgBit(oldp+931,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_86));
        bufp->chgBit(oldp+932,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_87));
        bufp->chgBit(oldp+933,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_88));
        bufp->chgBit(oldp+934,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_89));
        bufp->chgBit(oldp+935,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_90));
        bufp->chgBit(oldp+936,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_91));
        bufp->chgBit(oldp+937,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_92));
        bufp->chgBit(oldp+938,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_93));
        bufp->chgBit(oldp+939,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_94));
        bufp->chgBit(oldp+940,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_95));
        bufp->chgBit(oldp+941,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_96));
        bufp->chgBit(oldp+942,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_97));
        bufp->chgBit(oldp+943,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_98));
        bufp->chgBit(oldp+944,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_99));
        bufp->chgBit(oldp+945,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_100));
        bufp->chgBit(oldp+946,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_101));
        bufp->chgBit(oldp+947,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_102));
        bufp->chgBit(oldp+948,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_103));
        bufp->chgBit(oldp+949,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_104));
        bufp->chgBit(oldp+950,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_105));
        bufp->chgBit(oldp+951,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_106));
        bufp->chgBit(oldp+952,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_107));
        bufp->chgBit(oldp+953,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_108));
        bufp->chgBit(oldp+954,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_109));
        bufp->chgBit(oldp+955,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_110));
        bufp->chgBit(oldp+956,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_111));
        bufp->chgBit(oldp+957,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_112));
        bufp->chgBit(oldp+958,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_113));
        bufp->chgBit(oldp+959,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_114));
        bufp->chgBit(oldp+960,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_115));
        bufp->chgBit(oldp+961,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_116));
        bufp->chgBit(oldp+962,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_117));
        bufp->chgBit(oldp+963,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_118));
        bufp->chgBit(oldp+964,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_119));
        bufp->chgBit(oldp+965,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_120));
        bufp->chgBit(oldp+966,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_121));
        bufp->chgBit(oldp+967,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_122));
        bufp->chgBit(oldp+968,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_123));
        bufp->chgBit(oldp+969,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_124));
        bufp->chgBit(oldp+970,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_125));
        bufp->chgBit(oldp+971,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_126));
        bufp->chgBit(oldp+972,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_127));
        bufp->chgBit(oldp+973,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_128));
        bufp->chgBit(oldp+974,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_129));
        bufp->chgBit(oldp+975,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_130));
        bufp->chgBit(oldp+976,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_131));
        bufp->chgBit(oldp+977,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_132));
        bufp->chgBit(oldp+978,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_133));
        bufp->chgBit(oldp+979,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_134));
        bufp->chgBit(oldp+980,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_135));
        bufp->chgBit(oldp+981,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_136));
        bufp->chgBit(oldp+982,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_137));
        bufp->chgBit(oldp+983,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_138));
        bufp->chgBit(oldp+984,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_139));
        bufp->chgBit(oldp+985,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_140));
        bufp->chgBit(oldp+986,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_141));
        bufp->chgBit(oldp+987,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_142));
        bufp->chgBit(oldp+988,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_143));
        bufp->chgBit(oldp+989,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_144));
        bufp->chgBit(oldp+990,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_145));
        bufp->chgBit(oldp+991,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_146));
        bufp->chgBit(oldp+992,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_147));
        bufp->chgBit(oldp+993,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_148));
        bufp->chgBit(oldp+994,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_149));
        bufp->chgBit(oldp+995,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_150));
        bufp->chgBit(oldp+996,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_151));
        bufp->chgBit(oldp+997,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_152));
        bufp->chgBit(oldp+998,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_153));
        bufp->chgBit(oldp+999,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_154));
        bufp->chgBit(oldp+1000,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_155));
        bufp->chgBit(oldp+1001,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_156));
        bufp->chgBit(oldp+1002,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_157));
        bufp->chgBit(oldp+1003,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_158));
        bufp->chgBit(oldp+1004,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_159));
        bufp->chgBit(oldp+1005,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_160));
        bufp->chgBit(oldp+1006,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_161));
        bufp->chgBit(oldp+1007,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_162));
        bufp->chgBit(oldp+1008,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_163));
        bufp->chgBit(oldp+1009,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_164));
        bufp->chgBit(oldp+1010,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_165));
        bufp->chgBit(oldp+1011,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_166));
        bufp->chgBit(oldp+1012,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_167));
        bufp->chgBit(oldp+1013,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_168));
        bufp->chgBit(oldp+1014,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_169));
        bufp->chgBit(oldp+1015,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_170));
        bufp->chgBit(oldp+1016,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_171));
        bufp->chgBit(oldp+1017,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_172));
        bufp->chgBit(oldp+1018,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_173));
        bufp->chgBit(oldp+1019,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_174));
        bufp->chgBit(oldp+1020,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_175));
        bufp->chgBit(oldp+1021,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_176));
        bufp->chgBit(oldp+1022,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_177));
        bufp->chgBit(oldp+1023,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_178));
        bufp->chgBit(oldp+1024,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_179));
        bufp->chgBit(oldp+1025,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_180));
        bufp->chgBit(oldp+1026,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_181));
        bufp->chgBit(oldp+1027,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_182));
        bufp->chgBit(oldp+1028,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_183));
        bufp->chgBit(oldp+1029,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_184));
        bufp->chgBit(oldp+1030,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_185));
        bufp->chgBit(oldp+1031,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_186));
        bufp->chgBit(oldp+1032,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_187));
        bufp->chgBit(oldp+1033,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_188));
        bufp->chgBit(oldp+1034,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_189));
        bufp->chgBit(oldp+1035,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_190));
        bufp->chgBit(oldp+1036,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_191));
        bufp->chgBit(oldp+1037,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_192));
        bufp->chgBit(oldp+1038,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_193));
        bufp->chgBit(oldp+1039,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_194));
        bufp->chgBit(oldp+1040,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_195));
        bufp->chgBit(oldp+1041,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_196));
        bufp->chgBit(oldp+1042,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_197));
        bufp->chgBit(oldp+1043,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_198));
        bufp->chgBit(oldp+1044,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_199));
        bufp->chgBit(oldp+1045,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_200));
        bufp->chgBit(oldp+1046,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_201));
        bufp->chgBit(oldp+1047,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_202));
        bufp->chgBit(oldp+1048,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_203));
        bufp->chgBit(oldp+1049,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_204));
        bufp->chgBit(oldp+1050,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_205));
        bufp->chgBit(oldp+1051,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_206));
        bufp->chgBit(oldp+1052,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_207));
        bufp->chgBit(oldp+1053,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_208));
        bufp->chgBit(oldp+1054,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_209));
        bufp->chgBit(oldp+1055,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_210));
        bufp->chgBit(oldp+1056,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_211));
        bufp->chgBit(oldp+1057,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_212));
        bufp->chgBit(oldp+1058,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_213));
        bufp->chgBit(oldp+1059,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_214));
        bufp->chgBit(oldp+1060,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_215));
        bufp->chgBit(oldp+1061,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_216));
        bufp->chgBit(oldp+1062,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_217));
        bufp->chgBit(oldp+1063,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_218));
        bufp->chgBit(oldp+1064,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_219));
        bufp->chgBit(oldp+1065,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_220));
        bufp->chgBit(oldp+1066,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_221));
        bufp->chgBit(oldp+1067,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_222));
        bufp->chgBit(oldp+1068,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_223));
        bufp->chgBit(oldp+1069,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_224));
        bufp->chgBit(oldp+1070,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_225));
        bufp->chgBit(oldp+1071,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_226));
        bufp->chgBit(oldp+1072,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_227));
        bufp->chgBit(oldp+1073,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_228));
        bufp->chgBit(oldp+1074,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_229));
        bufp->chgBit(oldp+1075,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_230));
        bufp->chgBit(oldp+1076,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_231));
        bufp->chgBit(oldp+1077,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_232));
        bufp->chgBit(oldp+1078,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_233));
        bufp->chgBit(oldp+1079,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_234));
        bufp->chgBit(oldp+1080,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_235));
        bufp->chgBit(oldp+1081,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_236));
        bufp->chgBit(oldp+1082,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_237));
        bufp->chgBit(oldp+1083,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_238));
        bufp->chgBit(oldp+1084,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_239));
        bufp->chgBit(oldp+1085,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_240));
        bufp->chgBit(oldp+1086,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_241));
        bufp->chgBit(oldp+1087,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_242));
        bufp->chgBit(oldp+1088,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_243));
        bufp->chgBit(oldp+1089,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_244));
        bufp->chgBit(oldp+1090,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_245));
        bufp->chgBit(oldp+1091,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_246));
        bufp->chgBit(oldp+1092,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_247));
        bufp->chgBit(oldp+1093,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_248));
        bufp->chgBit(oldp+1094,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_249));
        bufp->chgBit(oldp+1095,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_250));
        bufp->chgBit(oldp+1096,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_251));
        bufp->chgBit(oldp+1097,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_252));
        bufp->chgBit(oldp+1098,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_253));
        bufp->chgBit(oldp+1099,(vlSelfRef.FFT256_tb__DOT__uut__DOT__io_out_valid_r_254));
        bufp->chgBit(oldp+1100,((1U & ((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt) 
                                       >> 6U))));
        bufp->chgBit(oldp+1101,((1U & ((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt) 
                                       >> 5U))));
        bufp->chgBit(oldp+1102,((1U & ((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt) 
                                       >> 4U))));
        bufp->chgBit(oldp+1103,((1U & ((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt) 
                                       >> 3U))));
        bufp->chgBit(oldp+1104,((1U & ((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt) 
                                       >> 2U))));
        bufp->chgBit(oldp+1105,((1U & ((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt) 
                                       >> 1U))));
        bufp->chgBit(oldp+1106,((1U & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt))));
        bufp->chgIData(oldp+1107,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(12,12,32, 
                                                          (0x7fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft256__ConstPool__CONST_hf3784b49_0[
                                             (((IData)(0x1fU) 
                                               + (0xfffU 
                                                  & VL_SHIFTL_III(12,12,32, 
                                                                  (0x7fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(12,12,32, 
                                                                  (0x7fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft256__ConstPool__CONST_hf3784b49_0[
                                      (0x7fU & (VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                                (0x7fU 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1108,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(12,12,32, 
                                                          (0x7fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft256__ConstPool__CONST_h944bc563_0[
                                             (((IData)(0x1fU) 
                                               + (0xfffU 
                                                  & VL_SHIFTL_III(12,12,32, 
                                                                  (0x7fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(12,12,32, 
                                                                  (0x7fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft256__ConstPool__CONST_h944bc563_0[
                                      (0x7fU & (VL_SHIFTL_III(12,12,32, 
                                                              (0x7fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                                (0x7fU 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1109,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft256__ConstPool__CONST_h8abd5580_0[
                                             (((IData)(0x1fU) 
                                               + (0x7ffU 
                                                  & VL_SHIFTL_III(11,11,32, 
                                                                  (0x3fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(11,11,32, 
                                                                  (0x3fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft256__ConstPool__CONST_h8abd5580_0[
                                      (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                                (0x3fU 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1110,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft256__ConstPool__CONST_h5478b25e_0[
                                             (((IData)(0x1fU) 
                                               + (0x7ffU 
                                                  & VL_SHIFTL_III(11,11,32, 
                                                                  (0x3fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(11,11,32, 
                                                                  (0x3fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft256__ConstPool__CONST_h5478b25e_0[
                                      (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                                (0x3fU 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1111,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft256__ConstPool__CONST_hb3c963b9_0[
                                             (((IData)(0x1fU) 
                                               + (0x3ffU 
                                                  & VL_SHIFTL_III(10,10,32, 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(10,10,32, 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft256__ConstPool__CONST_hb3c963b9_0[
                                      (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                                (0x1fU 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1112,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft256__ConstPool__CONST_h35564355_0[
                                             (((IData)(0x1fU) 
                                               + (0x3ffU 
                                                  & VL_SHIFTL_III(10,10,32, 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(10,10,32, 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft256__ConstPool__CONST_h35564355_0[
                                      (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                                (0x1fU 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1113,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft256__ConstPool__CONST_h942db0a5_0[
                                             (((IData)(0x1fU) 
                                               + (0x1ffU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0xfU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0xfU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft256__ConstPool__CONST_h942db0a5_0[
                                      (0xfU & (VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                               >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                                (0xfU 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1114,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft256__ConstPool__CONST_h0bfcbe7a_0[
                                             (((IData)(0x1fU) 
                                               + (0x1ffU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0xfU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0xfU 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft256__ConstPool__CONST_h0bfcbe7a_0[
                                      (0xfU & (VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                               >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                                (0xfU 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1115,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft256__ConstPool__CONST_hfd15effc_0[
                                             (((IData)(0x1fU) 
                                               + (0xffU 
                                                  & VL_SHIFTL_III(8,8,32, 
                                                                  (7U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(8,8,32, 
                                                                  (7U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft256__ConstPool__CONST_hfd15effc_0[
                                      (7U & (VL_SHIFTL_III(8,8,32, 
                                                           (7U 
                                                            & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                                (7U 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1116,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (Vfft256__ConstPool__CONST_h04042068_0[
                                             (((IData)(0x1fU) 
                                               + (0xffU 
                                                  & VL_SHIFTL_III(8,8,32, 
                                                                  (7U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(8,8,32, 
                                                                  (7U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (Vfft256__ConstPool__CONST_h04042068_0[
                                      (7U & (VL_SHIFTL_III(8,8,32, 
                                                           (7U 
                                                            & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                                (7U 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        __Vtemp_1[0U] = 0x100000U;
        __Vtemp_1[1U] = 0xb504fU;
        __Vtemp_1[2U] = 0U;
        __Vtemp_1[3U] = 0xfff4afb1U;
        bufp->chgIData(oldp+1117,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(7,7,32, 
                                                          (3U 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (__Vtemp_1[
                                             (((IData)(0x1fU) 
                                               + (0x7fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (__Vtemp_1[(3U 
                                                 & (VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                    >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                                (3U 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        __Vtemp_2[0U] = 0U;
        __Vtemp_2[1U] = 0xb504fU;
        __Vtemp_2[2U] = 0x100000U;
        __Vtemp_2[3U] = 0xb504fU;
        bufp->chgIData(oldp+1118,((((0U == (0x1fU & 
                                            VL_SHIFTL_III(7,7,32, 
                                                          (3U 
                                                           & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U)))
                                     ? 0U : (__Vtemp_2[
                                             (((IData)(0x1fU) 
                                               + (0x7fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                   | (__Vtemp_2[(3U 
                                                 & (VL_SHIFTL_III(7,7,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U) 
                                                    >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                                (3U 
                                                                 & (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+1119,((0x100000U & ((~ (IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt)) 
                                                << 0x14U))),32);
        bufp->chgIData(oldp+1120,((0x100000U & ((IData)(vlSelfRef.FFT256_tb__DOT__uut__DOT__cnt) 
                                                << 0x14U))),32);
    }
    bufp->chgBit(oldp+1121,(vlSelfRef.FFT256_tb__DOT__clock));
}

void Vfft256___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft256___024root__trace_cleanup\n"); );
    // Init
    Vfft256___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft256___024root*>(voidSelf);
    Vfft256__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
