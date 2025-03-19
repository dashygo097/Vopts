// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfft128__Syms.h"


void Vfft128___024root__trace_chg_0_sub_0(Vfft128___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfft128___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root__trace_chg_0\n"); );
    // Init
    Vfft128___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft128___024root*>(voidSelf);
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfft128___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<64>/*2047:0*/ Vfft128__ConstPool__CONST_h8abd5580_0;
extern const VlWide<64>/*2047:0*/ Vfft128__ConstPool__CONST_h16a5c00c_0;
extern const VlWide<32>/*1023:0*/ Vfft128__ConstPool__CONST_hb3c963b9_0;
extern const VlWide<32>/*1023:0*/ Vfft128__ConstPool__CONST_hffb3c89b_0;
extern const VlWide<16>/*511:0*/ Vfft128__ConstPool__CONST_h942db0a5_0;
extern const VlWide<16>/*511:0*/ Vfft128__ConstPool__CONST_ha2844606_0;
extern const VlWide<8>/*255:0*/ Vfft128__ConstPool__CONST_hfd15effc_0;
extern const VlWide<8>/*255:0*/ Vfft128__ConstPool__CONST_h5ba1edbd_0;

void Vfft128___024root__trace_chg_0_sub_0(Vfft128___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root__trace_chg_0_sub_0\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.FFT128_tb__DOT__reset));
        bufp->chgIData(oldp+1,(vlSelfRef.FFT128_tb__DOT__io_in_real),32);
        bufp->chgIData(oldp+2,(vlSelfRef.FFT128_tb__DOT__io_in_imag),32);
        bufp->chgBit(oldp+3,(vlSelfRef.FFT128_tb__DOT__io_in_valid));
        bufp->chgIData(oldp+4,(vlSelfRef.FFT128_tb__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [3U] | vlSelfRef.__Vm_traceActivity
                       [4U]) | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgIData(oldp+5,(((0x20U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_real
                                 : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_real)),32);
        bufp->chgIData(oldp+6,(((0x20U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_imag
                                 : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_imag)),32);
        bufp->chgIData(oldp+7,(((0x10U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_real
                                 : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_real)),32);
        bufp->chgIData(oldp+8,(((0x10U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_imag
                                 : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_imag)),32);
        bufp->chgIData(oldp+9,(((8U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                 ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_real
                                 : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_real)),32);
        bufp->chgIData(oldp+10,(((8U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_imag
                                  : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_imag)),32);
        bufp->chgIData(oldp+11,(((4U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_real
                                  : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_real)),32);
        bufp->chgIData(oldp+12,(((4U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_imag
                                  : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_imag)),32);
        bufp->chgIData(oldp+13,(((2U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_real
                                  : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_real)),32);
        bufp->chgIData(oldp+14,(((2U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_imag
                                  : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_imag)),32);
        bufp->chgIData(oldp+15,(((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_real
                                  : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_real)),32);
        bufp->chgIData(oldp+16,(((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                  ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_imag
                                  : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_imag)),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgIData(oldp+17,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_real),32);
        bufp->chgIData(oldp+18,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_imag),32);
        bufp->chgIData(oldp+19,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real),32);
        bufp->chgIData(oldp+20,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag),32);
        bufp->chgIData(oldp+21,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_real),32);
        bufp->chgIData(oldp+22,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_imag),32);
        bufp->chgIData(oldp+23,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real),32);
        bufp->chgIData(oldp+24,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag),32);
        bufp->chgIData(oldp+25,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_real),32);
        bufp->chgIData(oldp+26,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_imag),32);
        bufp->chgIData(oldp+27,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real),32);
        bufp->chgIData(oldp+28,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag),32);
        bufp->chgIData(oldp+29,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_real),32);
        bufp->chgIData(oldp+30,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_imag),32);
        bufp->chgIData(oldp+31,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real),32);
        bufp->chgIData(oldp+32,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag),32);
        bufp->chgIData(oldp+33,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_real),32);
        bufp->chgIData(oldp+34,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_imag),32);
        bufp->chgIData(oldp+35,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real),32);
        bufp->chgIData(oldp+36,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag),32);
        bufp->chgIData(oldp+37,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_real),32);
        bufp->chgIData(oldp+38,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_imag),32);
        bufp->chgIData(oldp+39,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_real),32);
        bufp->chgIData(oldp+40,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_imag),32);
        bufp->chgIData(oldp+41,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+42,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgQData(oldp+43,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__tmp_k1),52);
        bufp->chgQData(oldp+45,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1),52);
        bufp->chgIData(oldp+47,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+48,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgQData(oldp+49,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__tmp_k1),52);
        bufp->chgQData(oldp+51,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1),52);
        bufp->chgIData(oldp+53,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+54,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgQData(oldp+55,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__tmp_k1),52);
        bufp->chgQData(oldp+57,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1),52);
        bufp->chgIData(oldp+59,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+60,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgQData(oldp+61,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__tmp_k1),52);
        bufp->chgQData(oldp+63,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1),52);
        bufp->chgIData(oldp+65,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+66,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgQData(oldp+67,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1),52);
        bufp->chgQData(oldp+69,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1),52);
        bufp->chgIData(oldp+71,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                             - ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgIData(oldp+72,((IData)((0xffffffffULL 
                                         & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                             + ((((QData)((IData)(
                                                                  (0xfffffU 
                                                                   & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
                                                                                >> 0x1fU)))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T))) 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T))))) 
                                            >> 0x14U)))),32);
        bufp->chgQData(oldp+73,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__tmp_k1),52);
        bufp->chgQData(oldp+75,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1),52);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+77,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out1_REG_real),32);
        bufp->chgIData(oldp+78,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out1_REG_imag),32);
        bufp->chgIData(oldp+79,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out2_REG_real),32);
        bufp->chgIData(oldp+80,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out2_REG_imag),32);
        bufp->chgBit(oldp+81,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_127));
        bufp->chgCData(oldp+82,(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt),7);
        bufp->chgIData(oldp+83,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_real),32);
        bufp->chgIData(oldp+84,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_imag),32);
        bufp->chgIData(oldp+85,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_1_real),32);
        bufp->chgIData(oldp+86,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_1_imag),32);
        bufp->chgIData(oldp+87,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_2_real),32);
        bufp->chgIData(oldp+88,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_2_imag),32);
        bufp->chgIData(oldp+89,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_3_real),32);
        bufp->chgIData(oldp+90,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_3_imag),32);
        bufp->chgIData(oldp+91,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_4_real),32);
        bufp->chgIData(oldp+92,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_4_imag),32);
        bufp->chgIData(oldp+93,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_5_real),32);
        bufp->chgIData(oldp+94,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_5_imag),32);
        bufp->chgIData(oldp+95,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_6_real),32);
        bufp->chgIData(oldp+96,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_6_imag),32);
        bufp->chgIData(oldp+97,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_7_real),32);
        bufp->chgIData(oldp+98,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_7_imag),32);
        bufp->chgIData(oldp+99,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_8_real),32);
        bufp->chgIData(oldp+100,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_8_imag),32);
        bufp->chgIData(oldp+101,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_9_real),32);
        bufp->chgIData(oldp+102,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_9_imag),32);
        bufp->chgIData(oldp+103,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_10_real),32);
        bufp->chgIData(oldp+104,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_10_imag),32);
        bufp->chgIData(oldp+105,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_11_real),32);
        bufp->chgIData(oldp+106,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_11_imag),32);
        bufp->chgIData(oldp+107,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_12_real),32);
        bufp->chgIData(oldp+108,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_12_imag),32);
        bufp->chgIData(oldp+109,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_13_real),32);
        bufp->chgIData(oldp+110,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_13_imag),32);
        bufp->chgIData(oldp+111,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_14_real),32);
        bufp->chgIData(oldp+112,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_14_imag),32);
        bufp->chgIData(oldp+113,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_15_real),32);
        bufp->chgIData(oldp+114,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_15_imag),32);
        bufp->chgIData(oldp+115,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_16_real),32);
        bufp->chgIData(oldp+116,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_16_imag),32);
        bufp->chgIData(oldp+117,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_17_real),32);
        bufp->chgIData(oldp+118,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_17_imag),32);
        bufp->chgIData(oldp+119,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_18_real),32);
        bufp->chgIData(oldp+120,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_18_imag),32);
        bufp->chgIData(oldp+121,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_19_real),32);
        bufp->chgIData(oldp+122,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_19_imag),32);
        bufp->chgIData(oldp+123,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_20_real),32);
        bufp->chgIData(oldp+124,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_20_imag),32);
        bufp->chgIData(oldp+125,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_21_real),32);
        bufp->chgIData(oldp+126,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_21_imag),32);
        bufp->chgIData(oldp+127,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_22_real),32);
        bufp->chgIData(oldp+128,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_22_imag),32);
        bufp->chgIData(oldp+129,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_23_real),32);
        bufp->chgIData(oldp+130,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_23_imag),32);
        bufp->chgIData(oldp+131,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_24_real),32);
        bufp->chgIData(oldp+132,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_24_imag),32);
        bufp->chgIData(oldp+133,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_25_real),32);
        bufp->chgIData(oldp+134,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_25_imag),32);
        bufp->chgIData(oldp+135,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_26_real),32);
        bufp->chgIData(oldp+136,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_26_imag),32);
        bufp->chgIData(oldp+137,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_27_real),32);
        bufp->chgIData(oldp+138,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_27_imag),32);
        bufp->chgIData(oldp+139,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_28_real),32);
        bufp->chgIData(oldp+140,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_28_imag),32);
        bufp->chgIData(oldp+141,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_29_real),32);
        bufp->chgIData(oldp+142,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_29_imag),32);
        bufp->chgIData(oldp+143,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_30_real),32);
        bufp->chgIData(oldp+144,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_30_imag),32);
        bufp->chgIData(oldp+145,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_31_real),32);
        bufp->chgIData(oldp+146,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_31_imag),32);
        bufp->chgIData(oldp+147,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_32_real),32);
        bufp->chgIData(oldp+148,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_32_imag),32);
        bufp->chgIData(oldp+149,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_33_real),32);
        bufp->chgIData(oldp+150,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_33_imag),32);
        bufp->chgIData(oldp+151,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_34_real),32);
        bufp->chgIData(oldp+152,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_34_imag),32);
        bufp->chgIData(oldp+153,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_35_real),32);
        bufp->chgIData(oldp+154,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_35_imag),32);
        bufp->chgIData(oldp+155,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_36_real),32);
        bufp->chgIData(oldp+156,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_36_imag),32);
        bufp->chgIData(oldp+157,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_37_real),32);
        bufp->chgIData(oldp+158,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_37_imag),32);
        bufp->chgIData(oldp+159,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_38_real),32);
        bufp->chgIData(oldp+160,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_38_imag),32);
        bufp->chgIData(oldp+161,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_39_real),32);
        bufp->chgIData(oldp+162,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_39_imag),32);
        bufp->chgIData(oldp+163,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_40_real),32);
        bufp->chgIData(oldp+164,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_40_imag),32);
        bufp->chgIData(oldp+165,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_41_real),32);
        bufp->chgIData(oldp+166,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_41_imag),32);
        bufp->chgIData(oldp+167,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_42_real),32);
        bufp->chgIData(oldp+168,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_42_imag),32);
        bufp->chgIData(oldp+169,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_43_real),32);
        bufp->chgIData(oldp+170,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_43_imag),32);
        bufp->chgIData(oldp+171,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_44_real),32);
        bufp->chgIData(oldp+172,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_44_imag),32);
        bufp->chgIData(oldp+173,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_45_real),32);
        bufp->chgIData(oldp+174,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_45_imag),32);
        bufp->chgIData(oldp+175,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_46_real),32);
        bufp->chgIData(oldp+176,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_46_imag),32);
        bufp->chgIData(oldp+177,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_47_real),32);
        bufp->chgIData(oldp+178,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_47_imag),32);
        bufp->chgIData(oldp+179,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_48_real),32);
        bufp->chgIData(oldp+180,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_48_imag),32);
        bufp->chgIData(oldp+181,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_49_real),32);
        bufp->chgIData(oldp+182,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_49_imag),32);
        bufp->chgIData(oldp+183,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_50_real),32);
        bufp->chgIData(oldp+184,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_50_imag),32);
        bufp->chgIData(oldp+185,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_51_real),32);
        bufp->chgIData(oldp+186,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_51_imag),32);
        bufp->chgIData(oldp+187,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_52_real),32);
        bufp->chgIData(oldp+188,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_52_imag),32);
        bufp->chgIData(oldp+189,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_53_real),32);
        bufp->chgIData(oldp+190,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_53_imag),32);
        bufp->chgIData(oldp+191,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_54_real),32);
        bufp->chgIData(oldp+192,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_54_imag),32);
        bufp->chgIData(oldp+193,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_55_real),32);
        bufp->chgIData(oldp+194,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_55_imag),32);
        bufp->chgIData(oldp+195,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_56_real),32);
        bufp->chgIData(oldp+196,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_56_imag),32);
        bufp->chgIData(oldp+197,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_57_real),32);
        bufp->chgIData(oldp+198,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_57_imag),32);
        bufp->chgIData(oldp+199,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_58_real),32);
        bufp->chgIData(oldp+200,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_58_imag),32);
        bufp->chgIData(oldp+201,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_59_real),32);
        bufp->chgIData(oldp+202,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_59_imag),32);
        bufp->chgIData(oldp+203,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_60_real),32);
        bufp->chgIData(oldp+204,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_60_imag),32);
        bufp->chgIData(oldp+205,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_61_real),32);
        bufp->chgIData(oldp+206,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_61_imag),32);
        bufp->chgIData(oldp+207,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_62_real),32);
        bufp->chgIData(oldp+208,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_62_imag),32);
        bufp->chgIData(oldp+209,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_real),32);
        bufp->chgIData(oldp+210,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_imag),32);
        bufp->chgIData(oldp+211,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_64_real),32);
        bufp->chgIData(oldp+212,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_64_imag),32);
        bufp->chgIData(oldp+213,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_65_real),32);
        bufp->chgIData(oldp+214,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_65_imag),32);
        bufp->chgIData(oldp+215,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_66_real),32);
        bufp->chgIData(oldp+216,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_66_imag),32);
        bufp->chgIData(oldp+217,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_67_real),32);
        bufp->chgIData(oldp+218,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_67_imag),32);
        bufp->chgIData(oldp+219,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_68_real),32);
        bufp->chgIData(oldp+220,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_68_imag),32);
        bufp->chgIData(oldp+221,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_69_real),32);
        bufp->chgIData(oldp+222,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_69_imag),32);
        bufp->chgIData(oldp+223,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_70_real),32);
        bufp->chgIData(oldp+224,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_70_imag),32);
        bufp->chgIData(oldp+225,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_71_real),32);
        bufp->chgIData(oldp+226,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_71_imag),32);
        bufp->chgIData(oldp+227,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_72_real),32);
        bufp->chgIData(oldp+228,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_72_imag),32);
        bufp->chgIData(oldp+229,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_73_real),32);
        bufp->chgIData(oldp+230,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_73_imag),32);
        bufp->chgIData(oldp+231,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_74_real),32);
        bufp->chgIData(oldp+232,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_74_imag),32);
        bufp->chgIData(oldp+233,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_75_real),32);
        bufp->chgIData(oldp+234,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_75_imag),32);
        bufp->chgIData(oldp+235,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_76_real),32);
        bufp->chgIData(oldp+236,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_76_imag),32);
        bufp->chgIData(oldp+237,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_77_real),32);
        bufp->chgIData(oldp+238,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_77_imag),32);
        bufp->chgIData(oldp+239,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_78_real),32);
        bufp->chgIData(oldp+240,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_78_imag),32);
        bufp->chgIData(oldp+241,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_79_real),32);
        bufp->chgIData(oldp+242,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_79_imag),32);
        bufp->chgIData(oldp+243,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_80_real),32);
        bufp->chgIData(oldp+244,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_80_imag),32);
        bufp->chgIData(oldp+245,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_81_real),32);
        bufp->chgIData(oldp+246,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_81_imag),32);
        bufp->chgIData(oldp+247,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_82_real),32);
        bufp->chgIData(oldp+248,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_82_imag),32);
        bufp->chgIData(oldp+249,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_83_real),32);
        bufp->chgIData(oldp+250,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_83_imag),32);
        bufp->chgIData(oldp+251,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_84_real),32);
        bufp->chgIData(oldp+252,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_84_imag),32);
        bufp->chgIData(oldp+253,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_85_real),32);
        bufp->chgIData(oldp+254,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_85_imag),32);
        bufp->chgIData(oldp+255,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_86_real),32);
        bufp->chgIData(oldp+256,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_86_imag),32);
        bufp->chgIData(oldp+257,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_87_real),32);
        bufp->chgIData(oldp+258,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_87_imag),32);
        bufp->chgIData(oldp+259,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_88_real),32);
        bufp->chgIData(oldp+260,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_88_imag),32);
        bufp->chgIData(oldp+261,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_89_real),32);
        bufp->chgIData(oldp+262,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_89_imag),32);
        bufp->chgIData(oldp+263,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_90_real),32);
        bufp->chgIData(oldp+264,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_90_imag),32);
        bufp->chgIData(oldp+265,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_91_real),32);
        bufp->chgIData(oldp+266,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_91_imag),32);
        bufp->chgIData(oldp+267,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_92_real),32);
        bufp->chgIData(oldp+268,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_92_imag),32);
        bufp->chgIData(oldp+269,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_93_real),32);
        bufp->chgIData(oldp+270,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_93_imag),32);
        bufp->chgIData(oldp+271,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_94_real),32);
        bufp->chgIData(oldp+272,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_94_imag),32);
        bufp->chgIData(oldp+273,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_real),32);
        bufp->chgIData(oldp+274,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_imag),32);
        bufp->chgIData(oldp+275,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_96_real),32);
        bufp->chgIData(oldp+276,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_96_imag),32);
        bufp->chgIData(oldp+277,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_97_real),32);
        bufp->chgIData(oldp+278,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_97_imag),32);
        bufp->chgIData(oldp+279,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_98_real),32);
        bufp->chgIData(oldp+280,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_98_imag),32);
        bufp->chgIData(oldp+281,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_99_real),32);
        bufp->chgIData(oldp+282,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_99_imag),32);
        bufp->chgIData(oldp+283,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_100_real),32);
        bufp->chgIData(oldp+284,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_100_imag),32);
        bufp->chgIData(oldp+285,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_101_real),32);
        bufp->chgIData(oldp+286,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_101_imag),32);
        bufp->chgIData(oldp+287,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_102_real),32);
        bufp->chgIData(oldp+288,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_102_imag),32);
        bufp->chgIData(oldp+289,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_103_real),32);
        bufp->chgIData(oldp+290,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_103_imag),32);
        bufp->chgIData(oldp+291,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_104_real),32);
        bufp->chgIData(oldp+292,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_104_imag),32);
        bufp->chgIData(oldp+293,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_105_real),32);
        bufp->chgIData(oldp+294,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_105_imag),32);
        bufp->chgIData(oldp+295,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_106_real),32);
        bufp->chgIData(oldp+296,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_106_imag),32);
        bufp->chgIData(oldp+297,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_107_real),32);
        bufp->chgIData(oldp+298,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_107_imag),32);
        bufp->chgIData(oldp+299,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_108_real),32);
        bufp->chgIData(oldp+300,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_108_imag),32);
        bufp->chgIData(oldp+301,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_109_real),32);
        bufp->chgIData(oldp+302,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_109_imag),32);
        bufp->chgIData(oldp+303,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_110_real),32);
        bufp->chgIData(oldp+304,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_110_imag),32);
        bufp->chgIData(oldp+305,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_111_real),32);
        bufp->chgIData(oldp+306,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_111_imag),32);
        bufp->chgIData(oldp+307,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_112_real),32);
        bufp->chgIData(oldp+308,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_112_imag),32);
        bufp->chgIData(oldp+309,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_113_real),32);
        bufp->chgIData(oldp+310,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_113_imag),32);
        bufp->chgIData(oldp+311,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_114_real),32);
        bufp->chgIData(oldp+312,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_114_imag),32);
        bufp->chgIData(oldp+313,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_115_real),32);
        bufp->chgIData(oldp+314,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_115_imag),32);
        bufp->chgIData(oldp+315,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_116_real),32);
        bufp->chgIData(oldp+316,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_116_imag),32);
        bufp->chgIData(oldp+317,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_117_real),32);
        bufp->chgIData(oldp+318,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_117_imag),32);
        bufp->chgIData(oldp+319,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_118_real),32);
        bufp->chgIData(oldp+320,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_118_imag),32);
        bufp->chgIData(oldp+321,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_119_real),32);
        bufp->chgIData(oldp+322,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_119_imag),32);
        bufp->chgIData(oldp+323,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_120_real),32);
        bufp->chgIData(oldp+324,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_120_imag),32);
        bufp->chgIData(oldp+325,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_121_real),32);
        bufp->chgIData(oldp+326,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_121_imag),32);
        bufp->chgIData(oldp+327,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_122_real),32);
        bufp->chgIData(oldp+328,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_122_imag),32);
        bufp->chgIData(oldp+329,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_123_real),32);
        bufp->chgIData(oldp+330,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_123_imag),32);
        bufp->chgIData(oldp+331,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_124_real),32);
        bufp->chgIData(oldp+332,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_124_imag),32);
        bufp->chgIData(oldp+333,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_125_real),32);
        bufp->chgIData(oldp+334,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_125_imag),32);
        bufp->chgIData(oldp+335,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_126_real),32);
        bufp->chgIData(oldp+336,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_126_imag),32);
        bufp->chgIData(oldp+337,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_real),32);
        bufp->chgIData(oldp+338,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_imag),32);
        bufp->chgIData(oldp+339,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_128_real),32);
        bufp->chgIData(oldp+340,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_128_imag),32);
        bufp->chgIData(oldp+341,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_129_real),32);
        bufp->chgIData(oldp+342,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_129_imag),32);
        bufp->chgIData(oldp+343,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_130_real),32);
        bufp->chgIData(oldp+344,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_130_imag),32);
        bufp->chgIData(oldp+345,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_131_real),32);
        bufp->chgIData(oldp+346,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_131_imag),32);
        bufp->chgIData(oldp+347,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_132_real),32);
        bufp->chgIData(oldp+348,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_132_imag),32);
        bufp->chgIData(oldp+349,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_133_real),32);
        bufp->chgIData(oldp+350,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_133_imag),32);
        bufp->chgIData(oldp+351,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_134_real),32);
        bufp->chgIData(oldp+352,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_134_imag),32);
        bufp->chgIData(oldp+353,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_135_real),32);
        bufp->chgIData(oldp+354,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_135_imag),32);
        bufp->chgIData(oldp+355,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_136_real),32);
        bufp->chgIData(oldp+356,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_136_imag),32);
        bufp->chgIData(oldp+357,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_137_real),32);
        bufp->chgIData(oldp+358,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_137_imag),32);
        bufp->chgIData(oldp+359,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_138_real),32);
        bufp->chgIData(oldp+360,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_138_imag),32);
        bufp->chgIData(oldp+361,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_139_real),32);
        bufp->chgIData(oldp+362,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_139_imag),32);
        bufp->chgIData(oldp+363,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_140_real),32);
        bufp->chgIData(oldp+364,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_140_imag),32);
        bufp->chgIData(oldp+365,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_141_real),32);
        bufp->chgIData(oldp+366,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_141_imag),32);
        bufp->chgIData(oldp+367,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_142_real),32);
        bufp->chgIData(oldp+368,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_142_imag),32);
        bufp->chgIData(oldp+369,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_real),32);
        bufp->chgIData(oldp+370,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_imag),32);
        bufp->chgIData(oldp+371,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_144_real),32);
        bufp->chgIData(oldp+372,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_144_imag),32);
        bufp->chgIData(oldp+373,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_145_real),32);
        bufp->chgIData(oldp+374,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_145_imag),32);
        bufp->chgIData(oldp+375,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_146_real),32);
        bufp->chgIData(oldp+376,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_146_imag),32);
        bufp->chgIData(oldp+377,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_147_real),32);
        bufp->chgIData(oldp+378,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_147_imag),32);
        bufp->chgIData(oldp+379,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_148_real),32);
        bufp->chgIData(oldp+380,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_148_imag),32);
        bufp->chgIData(oldp+381,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_149_real),32);
        bufp->chgIData(oldp+382,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_149_imag),32);
        bufp->chgIData(oldp+383,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_150_real),32);
        bufp->chgIData(oldp+384,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_150_imag),32);
        bufp->chgIData(oldp+385,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_151_real),32);
        bufp->chgIData(oldp+386,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_151_imag),32);
        bufp->chgIData(oldp+387,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_152_real),32);
        bufp->chgIData(oldp+388,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_152_imag),32);
        bufp->chgIData(oldp+389,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_153_real),32);
        bufp->chgIData(oldp+390,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_153_imag),32);
        bufp->chgIData(oldp+391,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_154_real),32);
        bufp->chgIData(oldp+392,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_154_imag),32);
        bufp->chgIData(oldp+393,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_155_real),32);
        bufp->chgIData(oldp+394,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_155_imag),32);
        bufp->chgIData(oldp+395,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_156_real),32);
        bufp->chgIData(oldp+396,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_156_imag),32);
        bufp->chgIData(oldp+397,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_157_real),32);
        bufp->chgIData(oldp+398,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_157_imag),32);
        bufp->chgIData(oldp+399,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_158_real),32);
        bufp->chgIData(oldp+400,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_158_imag),32);
        bufp->chgIData(oldp+401,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_real),32);
        bufp->chgIData(oldp+402,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_imag),32);
        bufp->chgIData(oldp+403,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_160_real),32);
        bufp->chgIData(oldp+404,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_160_imag),32);
        bufp->chgIData(oldp+405,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_161_real),32);
        bufp->chgIData(oldp+406,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_161_imag),32);
        bufp->chgIData(oldp+407,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_162_real),32);
        bufp->chgIData(oldp+408,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_162_imag),32);
        bufp->chgIData(oldp+409,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_163_real),32);
        bufp->chgIData(oldp+410,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_163_imag),32);
        bufp->chgIData(oldp+411,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_164_real),32);
        bufp->chgIData(oldp+412,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_164_imag),32);
        bufp->chgIData(oldp+413,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_165_real),32);
        bufp->chgIData(oldp+414,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_165_imag),32);
        bufp->chgIData(oldp+415,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_166_real),32);
        bufp->chgIData(oldp+416,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_166_imag),32);
        bufp->chgIData(oldp+417,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_real),32);
        bufp->chgIData(oldp+418,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_imag),32);
        bufp->chgIData(oldp+419,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_168_real),32);
        bufp->chgIData(oldp+420,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_168_imag),32);
        bufp->chgIData(oldp+421,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_169_real),32);
        bufp->chgIData(oldp+422,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_169_imag),32);
        bufp->chgIData(oldp+423,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_170_real),32);
        bufp->chgIData(oldp+424,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_170_imag),32);
        bufp->chgIData(oldp+425,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_171_real),32);
        bufp->chgIData(oldp+426,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_171_imag),32);
        bufp->chgIData(oldp+427,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_172_real),32);
        bufp->chgIData(oldp+428,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_172_imag),32);
        bufp->chgIData(oldp+429,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_173_real),32);
        bufp->chgIData(oldp+430,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_173_imag),32);
        bufp->chgIData(oldp+431,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_174_real),32);
        bufp->chgIData(oldp+432,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_174_imag),32);
        bufp->chgIData(oldp+433,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_real),32);
        bufp->chgIData(oldp+434,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_imag),32);
        bufp->chgIData(oldp+435,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_176_real),32);
        bufp->chgIData(oldp+436,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_176_imag),32);
        bufp->chgIData(oldp+437,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_177_real),32);
        bufp->chgIData(oldp+438,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_177_imag),32);
        bufp->chgIData(oldp+439,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_178_real),32);
        bufp->chgIData(oldp+440,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_178_imag),32);
        bufp->chgIData(oldp+441,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_real),32);
        bufp->chgIData(oldp+442,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_imag),32);
        bufp->chgIData(oldp+443,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_180_real),32);
        bufp->chgIData(oldp+444,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_180_imag),32);
        bufp->chgIData(oldp+445,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_181_real),32);
        bufp->chgIData(oldp+446,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_181_imag),32);
        bufp->chgIData(oldp+447,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_182_real),32);
        bufp->chgIData(oldp+448,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_182_imag),32);
        bufp->chgIData(oldp+449,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_real),32);
        bufp->chgIData(oldp+450,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_imag),32);
        bufp->chgIData(oldp+451,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_184_real),32);
        bufp->chgIData(oldp+452,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_184_imag),32);
        bufp->chgIData(oldp+453,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_real),32);
        bufp->chgIData(oldp+454,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_imag),32);
        bufp->chgIData(oldp+455,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_186_real),32);
        bufp->chgIData(oldp+456,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_186_imag),32);
        bufp->chgIData(oldp+457,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_real),32);
        bufp->chgIData(oldp+458,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_imag),32);
        bufp->chgIData(oldp+459,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_real),32);
        bufp->chgIData(oldp+460,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_imag),32);
        bufp->chgIData(oldp+461,(vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_real),32);
        bufp->chgIData(oldp+462,(vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_imag),32);
        bufp->chgBit(oldp+463,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r));
        bufp->chgBit(oldp+464,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_1));
        bufp->chgBit(oldp+465,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_2));
        bufp->chgBit(oldp+466,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_3));
        bufp->chgBit(oldp+467,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_4));
        bufp->chgBit(oldp+468,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_5));
        bufp->chgBit(oldp+469,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_6));
        bufp->chgBit(oldp+470,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_7));
        bufp->chgBit(oldp+471,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_8));
        bufp->chgBit(oldp+472,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_9));
        bufp->chgBit(oldp+473,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_10));
        bufp->chgBit(oldp+474,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_11));
        bufp->chgBit(oldp+475,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_12));
        bufp->chgBit(oldp+476,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_13));
        bufp->chgBit(oldp+477,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_14));
        bufp->chgBit(oldp+478,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_15));
        bufp->chgBit(oldp+479,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_16));
        bufp->chgBit(oldp+480,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_17));
        bufp->chgBit(oldp+481,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_18));
        bufp->chgBit(oldp+482,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_19));
        bufp->chgBit(oldp+483,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_20));
        bufp->chgBit(oldp+484,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_21));
        bufp->chgBit(oldp+485,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_22));
        bufp->chgBit(oldp+486,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_23));
        bufp->chgBit(oldp+487,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_24));
        bufp->chgBit(oldp+488,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_25));
        bufp->chgBit(oldp+489,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_26));
        bufp->chgBit(oldp+490,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_27));
        bufp->chgBit(oldp+491,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_28));
        bufp->chgBit(oldp+492,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_29));
        bufp->chgBit(oldp+493,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_30));
        bufp->chgBit(oldp+494,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_31));
        bufp->chgBit(oldp+495,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_32));
        bufp->chgBit(oldp+496,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_33));
        bufp->chgBit(oldp+497,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_34));
        bufp->chgBit(oldp+498,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_35));
        bufp->chgBit(oldp+499,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_36));
        bufp->chgBit(oldp+500,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_37));
        bufp->chgBit(oldp+501,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_38));
        bufp->chgBit(oldp+502,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_39));
        bufp->chgBit(oldp+503,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_40));
        bufp->chgBit(oldp+504,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_41));
        bufp->chgBit(oldp+505,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_42));
        bufp->chgBit(oldp+506,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_43));
        bufp->chgBit(oldp+507,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_44));
        bufp->chgBit(oldp+508,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_45));
        bufp->chgBit(oldp+509,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_46));
        bufp->chgBit(oldp+510,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_47));
        bufp->chgBit(oldp+511,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_48));
        bufp->chgBit(oldp+512,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_49));
        bufp->chgBit(oldp+513,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_50));
        bufp->chgBit(oldp+514,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_51));
        bufp->chgBit(oldp+515,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_52));
        bufp->chgBit(oldp+516,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_53));
        bufp->chgBit(oldp+517,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_54));
        bufp->chgBit(oldp+518,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_55));
        bufp->chgBit(oldp+519,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_56));
        bufp->chgBit(oldp+520,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_57));
        bufp->chgBit(oldp+521,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_58));
        bufp->chgBit(oldp+522,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_59));
        bufp->chgBit(oldp+523,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_60));
        bufp->chgBit(oldp+524,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_61));
        bufp->chgBit(oldp+525,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_62));
        bufp->chgBit(oldp+526,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_63));
        bufp->chgBit(oldp+527,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_64));
        bufp->chgBit(oldp+528,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_65));
        bufp->chgBit(oldp+529,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_66));
        bufp->chgBit(oldp+530,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_67));
        bufp->chgBit(oldp+531,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_68));
        bufp->chgBit(oldp+532,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_69));
        bufp->chgBit(oldp+533,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_70));
        bufp->chgBit(oldp+534,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_71));
        bufp->chgBit(oldp+535,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_72));
        bufp->chgBit(oldp+536,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_73));
        bufp->chgBit(oldp+537,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_74));
        bufp->chgBit(oldp+538,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_75));
        bufp->chgBit(oldp+539,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_76));
        bufp->chgBit(oldp+540,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_77));
        bufp->chgBit(oldp+541,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_78));
        bufp->chgBit(oldp+542,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_79));
        bufp->chgBit(oldp+543,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_80));
        bufp->chgBit(oldp+544,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_81));
        bufp->chgBit(oldp+545,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_82));
        bufp->chgBit(oldp+546,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_83));
        bufp->chgBit(oldp+547,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_84));
        bufp->chgBit(oldp+548,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_85));
        bufp->chgBit(oldp+549,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_86));
        bufp->chgBit(oldp+550,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_87));
        bufp->chgBit(oldp+551,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_88));
        bufp->chgBit(oldp+552,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_89));
        bufp->chgBit(oldp+553,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_90));
        bufp->chgBit(oldp+554,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_91));
        bufp->chgBit(oldp+555,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_92));
        bufp->chgBit(oldp+556,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_93));
        bufp->chgBit(oldp+557,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_94));
        bufp->chgBit(oldp+558,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_95));
        bufp->chgBit(oldp+559,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_96));
        bufp->chgBit(oldp+560,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_97));
        bufp->chgBit(oldp+561,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_98));
        bufp->chgBit(oldp+562,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_99));
        bufp->chgBit(oldp+563,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_100));
        bufp->chgBit(oldp+564,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_101));
        bufp->chgBit(oldp+565,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_102));
        bufp->chgBit(oldp+566,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_103));
        bufp->chgBit(oldp+567,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_104));
        bufp->chgBit(oldp+568,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_105));
        bufp->chgBit(oldp+569,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_106));
        bufp->chgBit(oldp+570,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_107));
        bufp->chgBit(oldp+571,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_108));
        bufp->chgBit(oldp+572,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_109));
        bufp->chgBit(oldp+573,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_110));
        bufp->chgBit(oldp+574,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_111));
        bufp->chgBit(oldp+575,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_112));
        bufp->chgBit(oldp+576,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_113));
        bufp->chgBit(oldp+577,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_114));
        bufp->chgBit(oldp+578,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_115));
        bufp->chgBit(oldp+579,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_116));
        bufp->chgBit(oldp+580,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_117));
        bufp->chgBit(oldp+581,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_118));
        bufp->chgBit(oldp+582,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_119));
        bufp->chgBit(oldp+583,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_120));
        bufp->chgBit(oldp+584,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_121));
        bufp->chgBit(oldp+585,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_122));
        bufp->chgBit(oldp+586,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_123));
        bufp->chgBit(oldp+587,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_124));
        bufp->chgBit(oldp+588,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_125));
        bufp->chgBit(oldp+589,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_126));
        bufp->chgBit(oldp+590,((1U & ((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt) 
                                      >> 5U))));
        bufp->chgBit(oldp+591,((1U & ((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt) 
                                      >> 4U))));
        bufp->chgBit(oldp+592,((1U & ((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt) 
                                      >> 3U))));
        bufp->chgBit(oldp+593,((1U & ((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt) 
                                      >> 2U))));
        bufp->chgBit(oldp+594,((1U & ((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt) 
                                      >> 1U))));
        bufp->chgBit(oldp+595,((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))));
        bufp->chgIData(oldp+596,((((0U == (0x1fU & 
                                           VL_SHIFTL_III(11,11,32, 
                                                         (0x3fU 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                    ? 0U : (Vfft128__ConstPool__CONST_h8abd5580_0[
                                            (((IData)(0x1fU) 
                                              + (0x7ffU 
                                                 & VL_SHIFTL_III(11,11,32, 
                                                                 (0x3fU 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(11,11,32, 
                                                                   (0x3fU 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                  | (Vfft128__ConstPool__CONST_h8abd5580_0[
                                     (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                                             (0x3fU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                               >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                               (0x3fU 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+597,((((0U == (0x1fU & 
                                           VL_SHIFTL_III(11,11,32, 
                                                         (0x3fU 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                    ? 0U : (Vfft128__ConstPool__CONST_h16a5c00c_0[
                                            (((IData)(0x1fU) 
                                              + (0x7ffU 
                                                 & VL_SHIFTL_III(11,11,32, 
                                                                 (0x3fU 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(11,11,32, 
                                                                   (0x3fU 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                  | (Vfft128__ConstPool__CONST_h16a5c00c_0[
                                     (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                                             (0x3fU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                               >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                               (0x3fU 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+598,((((0U == (0x1fU & 
                                           VL_SHIFTL_III(10,10,32, 
                                                         (0x1fU 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                    ? 0U : (Vfft128__ConstPool__CONST_hb3c963b9_0[
                                            (((IData)(0x1fU) 
                                              + (0x3ffU 
                                                 & VL_SHIFTL_III(10,10,32, 
                                                                 (0x1fU 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(10,10,32, 
                                                                   (0x1fU 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                  | (Vfft128__ConstPool__CONST_hb3c963b9_0[
                                     (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                                             (0x1fU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                               >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                               (0x1fU 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+599,((((0U == (0x1fU & 
                                           VL_SHIFTL_III(10,10,32, 
                                                         (0x1fU 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                    ? 0U : (Vfft128__ConstPool__CONST_hffb3c89b_0[
                                            (((IData)(0x1fU) 
                                              + (0x3ffU 
                                                 & VL_SHIFTL_III(10,10,32, 
                                                                 (0x1fU 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(10,10,32, 
                                                                   (0x1fU 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                  | (Vfft128__ConstPool__CONST_hffb3c89b_0[
                                     (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                                             (0x1fU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                               >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                               (0x1fU 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+600,((((0U == (0x1fU & 
                                           VL_SHIFTL_III(9,9,32, 
                                                         (0xfU 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                    ? 0U : (Vfft128__ConstPool__CONST_h942db0a5_0[
                                            (((IData)(0x1fU) 
                                              + (0x1ffU 
                                                 & VL_SHIFTL_III(9,9,32, 
                                                                 (0xfU 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(9,9,32, 
                                                                   (0xfU 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                  | (Vfft128__ConstPool__CONST_h942db0a5_0[
                                     (0xfU & (VL_SHIFTL_III(9,9,32, 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                              >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                               (0xfU 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+601,((((0U == (0x1fU & 
                                           VL_SHIFTL_III(9,9,32, 
                                                         (0xfU 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                    ? 0U : (Vfft128__ConstPool__CONST_ha2844606_0[
                                            (((IData)(0x1fU) 
                                              + (0x1ffU 
                                                 & VL_SHIFTL_III(9,9,32, 
                                                                 (0xfU 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(9,9,32, 
                                                                   (0xfU 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                  | (Vfft128__ConstPool__CONST_ha2844606_0[
                                     (0xfU & (VL_SHIFTL_III(9,9,32, 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                              >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                               (0xfU 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+602,((((0U == (0x1fU & 
                                           VL_SHIFTL_III(8,8,32, 
                                                         (7U 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                    ? 0U : (Vfft128__ConstPool__CONST_hfd15effc_0[
                                            (((IData)(0x1fU) 
                                              + (0xffU 
                                                 & VL_SHIFTL_III(8,8,32, 
                                                                 (7U 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(8,8,32, 
                                                                   (7U 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                  | (Vfft128__ConstPool__CONST_hfd15effc_0[
                                     (7U & (VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                            >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                               (7U 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+603,((((0U == (0x1fU & 
                                           VL_SHIFTL_III(8,8,32, 
                                                         (7U 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                    ? 0U : (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                                            (((IData)(0x1fU) 
                                              + (0xffU 
                                                 & VL_SHIFTL_III(8,8,32, 
                                                                 (7U 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(8,8,32, 
                                                                   (7U 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                  | (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                                     (7U & (VL_SHIFTL_III(8,8,32, 
                                                          (7U 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                            >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                               (7U 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        __Vtemp_1[0U] = 0x100000U;
        __Vtemp_1[1U] = 0xb504fU;
        __Vtemp_1[2U] = 0U;
        __Vtemp_1[3U] = 0xfff4afb1U;
        bufp->chgIData(oldp+604,((((0U == (0x1fU & 
                                           VL_SHIFTL_III(7,7,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                    ? 0U : (__Vtemp_1[
                                            (((IData)(0x1fU) 
                                              + (0x7fU 
                                                 & VL_SHIFTL_III(7,7,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(7,7,32, 
                                                                   (3U 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                  | (__Vtemp_1[(3U 
                                                & (VL_SHIFTL_III(7,7,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                   >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        __Vtemp_2[0U] = 0U;
        __Vtemp_2[1U] = 0xfff4afb1U;
        __Vtemp_2[2U] = 0xfff00000U;
        __Vtemp_2[3U] = 0xfff4afb1U;
        bufp->chgIData(oldp+605,((((0U == (0x1fU & 
                                           VL_SHIFTL_III(7,7,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                    ? 0U : (__Vtemp_2[
                                            (((IData)(0x1fU) 
                                              + (0x7fU 
                                                 & VL_SHIFTL_III(7,7,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(7,7,32, 
                                                                   (3U 
                                                                    & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                  | (__Vtemp_2[(3U 
                                                & (VL_SHIFTL_III(7,7,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                   >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
        bufp->chgIData(oldp+606,((0x100000U & ((~ (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)) 
                                               << 0x14U))),32);
        bufp->chgIData(oldp+607,(((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                   ? 0xfff00000U : 0U)),32);
    }
    bufp->chgBit(oldp+608,(vlSelfRef.FFT128_tb__DOT__clock));
}

void Vfft128___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root__trace_cleanup\n"); );
    // Init
    Vfft128___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft128___024root*>(voidSelf);
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
