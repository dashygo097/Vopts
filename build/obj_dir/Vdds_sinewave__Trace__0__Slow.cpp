// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdds_sinewave__Syms.h"


VL_ATTR_COLD void Vdds_sinewave___024root__trace_init_sub__TOP__0(Vdds_sinewave___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root__trace_init_sub__TOP__0\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("SineWave_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_out_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_out_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"phase",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vdds_sinewave___024root__trace_init_top(Vdds_sinewave___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root__trace_init_top\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdds_sinewave___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdds_sinewave___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vdds_sinewave___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdds_sinewave___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdds_sinewave___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdds_sinewave___024root__trace_register(Vdds_sinewave___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root__trace_register\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vdds_sinewave___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vdds_sinewave___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vdds_sinewave___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vdds_sinewave___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdds_sinewave___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root__trace_const_0\n"); );
    // Init
    Vdds_sinewave___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdds_sinewave___024root*>(voidSelf);
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vdds_sinewave___024root__trace_full_0_sub_0(Vdds_sinewave___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdds_sinewave___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root__trace_full_0\n"); );
    // Init
    Vdds_sinewave___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdds_sinewave___024root*>(voidSelf);
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdds_sinewave___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<256>/*8191:0*/ Vdds_sinewave__ConstPool__CONST_h0a54ad8e_0;

VL_ATTR_COLD void Vdds_sinewave___024root__trace_full_0_sub_0(Vdds_sinewave___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root__trace_full_0_sub_0\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.SineWave_tb__DOT__clock));
    bufp->fullBit(oldp+2,(vlSelfRef.SineWave_tb__DOT__reset));
    bufp->fullIData(oldp+3,((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & ((IData)(vlSelfRef.SineWave_tb__DOT__uut__DOT__phase) 
                                                                >> 8U)), 5U)))
                               ? 0U : (Vdds_sinewave__ConstPool__CONST_h0a54ad8e_0[
                                       (((IData)(0x1fU) 
                                         + (0x1fffU 
                                            & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & ((IData)(vlSelfRef.SineWave_tb__DOT__uut__DOT__phase) 
                                                                >> 8U)), 5U))) 
                                        >> 5U)] << 
                                       ((IData)(0x20U) 
                                        - (0x1fU & 
                                           VL_SHIFTL_III(13,13,32, 
                                                         (0xffU 
                                                          & ((IData)(vlSelfRef.SineWave_tb__DOT__uut__DOT__phase) 
                                                             >> 8U)), 5U))))) 
                             | (Vdds_sinewave__ConstPool__CONST_h0a54ad8e_0[
                                (0xffU & (VL_SHIFTL_III(13,13,32, 
                                                        (0xffU 
                                                         & ((IData)(vlSelfRef.SineWave_tb__DOT__uut__DOT__phase) 
                                                            >> 8U)), 5U) 
                                          >> 5U))] 
                                >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                          (0xffU 
                                                           & ((IData)(vlSelfRef.SineWave_tb__DOT__uut__DOT__phase) 
                                                              >> 8U)), 5U))))),32);
    bufp->fullSData(oldp+4,(vlSelfRef.SineWave_tb__DOT__uut__DOT__phase),16);
}
