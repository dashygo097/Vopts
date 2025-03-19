// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfm__Syms.h"


VL_ATTR_COLD void Vfm___024root__trace_init_sub__TOP__0(Vfm___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root__trace_init_sub__TOP__0\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("FM_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_in_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"io_out_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+5,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_in_value",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"io_out_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("trig", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"io_phase_delta",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+4,0,"io_out_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"phase",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfm___024root__trace_init_top(Vfm___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root__trace_init_top\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vfm___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vfm___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vfm___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfm___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfm___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vfm___024root__trace_register(Vfm___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root__trace_register\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vfm___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vfm___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vfm___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vfm___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vfm___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root__trace_const_0\n"); );
    // Init
    Vfm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfm___024root*>(voidSelf);
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vfm___024root__trace_full_0_sub_0(Vfm___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vfm___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root__trace_full_0\n"); );
    // Init
    Vfm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfm___024root*>(voidSelf);
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vfm___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<256>/*8191:0*/ Vfm__ConstPool__CONST_hfdda0392_0;

VL_ATTR_COLD void Vfm___024root__trace_full_0_sub_0(Vfm___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root__trace_full_0_sub_0\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.FM_tb__DOT__clock));
    bufp->fullBit(oldp+2,(vlSelfRef.FM_tb__DOT__reset));
    bufp->fullIData(oldp+3,(vlSelfRef.FM_tb__DOT__io_in_value),32);
    bufp->fullIData(oldp+4,((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & (vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
                                                                >> 0x10U)), 5U)))
                               ? 0U : (Vfm__ConstPool__CONST_hfdda0392_0[
                                       (((IData)(0x1fU) 
                                         + (0x1fffU 
                                            & VL_SHIFTL_III(13,13,32, 
                                                            (0xffU 
                                                             & (vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
                                                                >> 0x10U)), 5U))) 
                                        >> 5U)] << 
                                       ((IData)(0x20U) 
                                        - (0x1fU & 
                                           VL_SHIFTL_III(13,13,32, 
                                                         (0xffU 
                                                          & (vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
                                                             >> 0x10U)), 5U))))) 
                             | (Vfm__ConstPool__CONST_hfdda0392_0[
                                (0xffU & (VL_SHIFTL_III(13,13,32, 
                                                        (0xffU 
                                                         & (vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
                                                            >> 0x10U)), 5U) 
                                          >> 5U))] 
                                >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                          (0xffU 
                                                           & (vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
                                                              >> 0x10U)), 5U))))),32);
    bufp->fullIData(oldp+5,(vlSelfRef.FM_tb__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+6,((0xffffffU & (IData)((0xfffffffffffffULL 
                                                  & VL_DIVS_QQQ(52, 
                                                                (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.FM_tb__DOT__uut__DOT___trig_io_phase_delta_T 
                                                                                >> 0x32U))))) 
                                                                  << 0x33U) 
                                                                 | vlSelfRef.FM_tb__DOT__uut__DOT___trig_io_phase_delta_T), 0x100000ULL))))),24);
    bufp->fullIData(oldp+7,(vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase),24);
}
