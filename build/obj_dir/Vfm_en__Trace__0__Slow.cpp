// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfm_en__Syms.h"


VL_ATTR_COLD void Vfm_en___024root__trace_init_sub__TOP__0(Vfm_en___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root__trace_init_sub__TOP__0\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("FM_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+6,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"io_ori_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"io_out_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+6,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"io_ori_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"io_out_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("cw", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+6,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"io_out_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"phase",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("trig", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+6,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"io_phase_delta",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+2,0,"io_out_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"phase",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfm_en___024root__trace_init_top(Vfm_en___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root__trace_init_top\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vfm_en___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vfm_en___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vfm_en___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfm_en___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfm_en___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vfm_en___024root__trace_register(Vfm_en___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root__trace_register\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vfm_en___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vfm_en___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vfm_en___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vfm_en___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vfm_en___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root__trace_const_0\n"); );
    // Init
    Vfm_en___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfm_en___024root*>(voidSelf);
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vfm_en___024root__trace_full_0_sub_0(Vfm_en___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vfm_en___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root__trace_full_0\n"); );
    // Init
    Vfm_en___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfm_en___024root*>(voidSelf);
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vfm_en___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<256>/*8191:0*/ Vfm_en__ConstPool__CONST_hfdda0392_0;

VL_ATTR_COLD void Vfm_en___024root__trace_full_0_sub_0(Vfm_en___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root__trace_full_0_sub_0\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                >> 8U)), 5U)))
                               ? 0U : (Vfm_en__ConstPool__CONST_hfdda0392_0[
                                       (((IData)(0x1fU) 
                                         + (0x1fffU 
                                            & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                >> 8U)), 5U))) 
                                        >> 5U)] << 
                                       ((IData)(0x20U) 
                                        - (0x1fU & 
                                           VL_SHIFTL_III(13,13,32, 
                                                         (0xffU 
                                                          & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                             >> 8U)), 5U))))) 
                             | (Vfm_en__ConstPool__CONST_hfdda0392_0[
                                (0xffU & (VL_SHIFTL_III(13,13,32, 
                                                        (0xffU 
                                                         & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                            >> 8U)), 5U) 
                                          >> 5U))] 
                                >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                          (0xffU 
                                                           & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                              >> 8U)), 5U))))),32);
    bufp->fullIData(oldp+2,((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase) 
                                                                >> 8U)), 5U)))
                               ? 0U : (Vfm_en__ConstPool__CONST_hfdda0392_0[
                                       (((IData)(0x1fU) 
                                         + (0x1fffU 
                                            & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase) 
                                                                >> 8U)), 5U))) 
                                        >> 5U)] << 
                                       ((IData)(0x20U) 
                                        - (0x1fU & 
                                           VL_SHIFTL_III(13,13,32, 
                                                         (0xffU 
                                                          & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase) 
                                                             >> 8U)), 5U))))) 
                             | (Vfm_en__ConstPool__CONST_hfdda0392_0[
                                (0xffU & (VL_SHIFTL_III(13,13,32, 
                                                        (0xffU 
                                                         & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase) 
                                                            >> 8U)), 5U) 
                                          >> 5U))] 
                                >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                          (0xffU 
                                                           & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase) 
                                                              >> 8U)), 5U))))),32);
    bufp->fullSData(oldp+3,(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase),16);
    bufp->fullSData(oldp+4,((0xffffU & (((0U == (0x1fU 
                                                 & ((IData)(0x10U) 
                                                    + 
                                                    (0x1fffU 
                                                     & VL_SHIFTL_III(13,13,32, 
                                                                     (0xffU 
                                                                      & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                         >> 8U)), 5U)))))
                                          ? 0U : (Vfm_en__ConstPool__CONST_hfdda0392_0[
                                                  (((IData)(0x1fU) 
                                                    + 
                                                    (0x1fffU 
                                                     & VL_SHIFTL_III(13,13,32, 
                                                                     (0xffU 
                                                                      & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                         >> 8U)), 5U))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x10U) 
                                                       + 
                                                       (0x1fffU 
                                                        & VL_SHIFTL_III(13,13,32, 
                                                                        (0xffU 
                                                                         & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                            >> 8U)), 5U))))))) 
                                        | (Vfm_en__ConstPool__CONST_hfdda0392_0[
                                           (((IData)(0x10U) 
                                             + (0x1fffU 
                                                & VL_SHIFTL_III(13,13,32, 
                                                                (0xffU 
                                                                 & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                    >> 8U)), 5U))) 
                                            >> 5U)] 
                                           >> (0x1fU 
                                               & ((IData)(0x10U) 
                                                  + 
                                                  (0x1fffU 
                                                   & VL_SHIFTL_III(13,13,32, 
                                                                   (0xffU 
                                                                    & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                       >> 8U)), 5U)))))))),16);
    bufp->fullSData(oldp+5,(vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase),16);
    bufp->fullBit(oldp+6,(vlSelfRef.FM_tb__DOT__clock));
    bufp->fullBit(oldp+7,(vlSelfRef.FM_tb__DOT__reset));
}
