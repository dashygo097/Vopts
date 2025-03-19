// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdds_trig__Syms.h"


VL_ATTR_COLD void Vdds_trig___024root__trace_init_sub__TOP__0(Vdds_trig___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_trig___024root__trace_init_sub__TOP__0\n"); );
    Vdds_trig__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("TrigDDS_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_mag_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"io_phase_delta",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+5,0,"io_out_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_mag_value",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"io_phase_delta",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+5,0,"io_out_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"phase",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vdds_trig___024root__trace_init_top(Vdds_trig___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_trig___024root__trace_init_top\n"); );
    Vdds_trig__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdds_trig___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdds_trig___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vdds_trig___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdds_trig___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdds_trig___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdds_trig___024root__trace_register(Vdds_trig___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_trig___024root__trace_register\n"); );
    Vdds_trig__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vdds_trig___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vdds_trig___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vdds_trig___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vdds_trig___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdds_trig___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_trig___024root__trace_const_0\n"); );
    // Init
    Vdds_trig___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdds_trig___024root*>(voidSelf);
    Vdds_trig__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vdds_trig___024root__trace_full_0_sub_0(Vdds_trig___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdds_trig___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_trig___024root__trace_full_0\n"); );
    // Init
    Vdds_trig___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdds_trig___024root*>(voidSelf);
    Vdds_trig__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdds_trig___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<256>/*8191:0*/ Vdds_trig__ConstPool__CONST_hfdda0392_0;

VL_ATTR_COLD void Vdds_trig___024root__trace_full_0_sub_0(Vdds_trig___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_trig___024root__trace_full_0_sub_0\n"); );
    Vdds_trig__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.TrigDDS_tb__DOT__clock));
    bufp->fullBit(oldp+2,(vlSelfRef.TrigDDS_tb__DOT__reset));
    bufp->fullIData(oldp+3,(vlSelfRef.TrigDDS_tb__DOT__io_mag_value),32);
    bufp->fullIData(oldp+4,(vlSelfRef.TrigDDS_tb__DOT__io_phase_delta),24);
    bufp->fullIData(oldp+5,((IData)((0xffffffffULL 
                                     & (((((QData)((IData)(
                                                           (0xfffffU 
                                                            & (- (IData)(
                                                                         (1U 
                                                                          & (Vdds_trig__ConstPool__CONST_hfdda0392_0[
                                                                             (((IData)(0x1fU) 
                                                                               + 
                                                                               (0x1fffU 
                                                                                & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.TrigDDS_tb__DOT__uut__DOT__phase 
                                                                                >> 0x10U)), 5U))) 
                                                                              >> 5U)] 
                                                                             >> 
                                                                             (0x1fU 
                                                                              & ((IData)(0x1fU) 
                                                                                + 
                                                                                (0x1fffU 
                                                                                & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.TrigDDS_tb__DOT__uut__DOT__phase 
                                                                                >> 0x10U)), 5U))))))))))) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            (((0U 
                                                               == 
                                                               (0x1fU 
                                                                & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.TrigDDS_tb__DOT__uut__DOT__phase 
                                                                                >> 0x10U)), 5U)))
                                                               ? 0U
                                                               : 
                                                              (Vdds_trig__ConstPool__CONST_hfdda0392_0[
                                                               (((IData)(0x1fU) 
                                                                 + 
                                                                 (0x1fffU 
                                                                  & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.TrigDDS_tb__DOT__uut__DOT__phase 
                                                                                >> 0x10U)), 5U))) 
                                                                >> 5U)] 
                                                               << 
                                                               ((IData)(0x20U) 
                                                                - 
                                                                (0x1fU 
                                                                 & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.TrigDDS_tb__DOT__uut__DOT__phase 
                                                                                >> 0x10U)), 5U))))) 
                                                             | (Vdds_trig__ConstPool__CONST_hfdda0392_0[
                                                                (0xffU 
                                                                 & (VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.TrigDDS_tb__DOT__uut__DOT__phase 
                                                                                >> 0x10U)), 5U) 
                                                                    >> 5U))] 
                                                                >> 
                                                                (0x1fU 
                                                                 & VL_SHIFTL_III(13,13,32, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.TrigDDS_tb__DOT__uut__DOT__phase 
                                                                                >> 0x10U)), 5U))))))) 
                                         * (((QData)((IData)(
                                                             (0xfffffU 
                                                              & (- (IData)(
                                                                           (vlSelfRef.TrigDDS_tb__DOT__io_mag_value 
                                                                            >> 0x1fU)))))) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelfRef.TrigDDS_tb__DOT__io_mag_value)))) 
                                        >> 0x14U)))),32);
    bufp->fullIData(oldp+6,(vlSelfRef.TrigDDS_tb__DOT__uut__DOT__phase),24);
}
