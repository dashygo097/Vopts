// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfir__Syms.h"


VL_ATTR_COLD void Vfir___024root__trace_init_sub__TOP__0(Vfir___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root__trace_init_sub__TOP__0\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("FIR_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+18,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"io_in_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"io_out_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+21,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+18,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"io_in_value",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"io_out_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"regs_0_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"regs_1_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"regs_2_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"regs_3_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"regs_4_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"regs_5_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"regs_6_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"regs_7_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"regs_8_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"regs_9_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"regs_10_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"regs_11_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"regs_12_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"regs_13_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"regs_14_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"regs_15_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfir___024root__trace_init_top(Vfir___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root__trace_init_top\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vfir___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vfir___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vfir___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfir___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfir___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vfir___024root__trace_register(Vfir___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root__trace_register\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vfir___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vfir___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vfir___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vfir___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vfir___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root__trace_const_0\n"); );
    // Init
    Vfir___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfir___024root*>(voidSelf);
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vfir___024root__trace_full_0_sub_0(Vfir___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vfir___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root__trace_full_0\n"); );
    // Init
    Vfir___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfir___024root*>(voidSelf);
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vfir___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vfir___024root__trace_full_0_sub_0(Vfir___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root__trace_full_0_sub_0\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(((IData)((0xffffffffULL 
                                      & ((0x280eULL 
                                          * (((QData)((IData)(
                                                              (0xfffffU 
                                                               & (- (IData)(
                                                                            (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_0_value 
                                                                             >> 0x1fU)))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_0_value)))) 
                                         >> 0x14U))) 
                             + ((IData)((0xffffffffULL 
                                         & ((0x3bf8ULL 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_1_value 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_1_value)))) 
                                            >> 0x14U))) 
                                + ((IData)((0xffffffffULL 
                                            & ((0x7445ULL 
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_2_value 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_2_value)))) 
                                               >> 0x14U))) 
                                   + ((IData)((0xffffffffULL 
                                               & ((0xc737ULL 
                                                   * 
                                                   (((QData)((IData)(
                                                                     (0xfffffU 
                                                                      & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_3_value 
                                                                                >> 0x1fU)))))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_3_value)))) 
                                                  >> 0x14U))) 
                                      + ((IData)((0xffffffffULL 
                                                  & ((0x12679ULL 
                                                      * 
                                                      (((QData)((IData)(
                                                                        (0xfffffU 
                                                                         & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_4_value 
                                                                                >> 0x1fU)))))) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_4_value)))) 
                                                     >> 0x14U))) 
                                         + ((IData)(
                                                    (0xffffffffULL 
                                                     & ((0x18190ULL 
                                                         * 
                                                         (((QData)((IData)(
                                                                           (0xfffffU 
                                                                            & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_5_value 
                                                                                >> 0x1fU)))))) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_5_value)))) 
                                                        >> 0x14U))) 
                                            + ((IData)(
                                                       (0xffffffffULL 
                                                        & ((0x1c8beULL 
                                                            * 
                                                            (((QData)((IData)(
                                                                              (0xfffffU 
                                                                               & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_6_value 
                                                                                >> 0x1fU)))))) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_6_value)))) 
                                                           >> 0x14U))) 
                                               + ((IData)(
                                                          (0xffffffffULL 
                                                           & ((0x1efb3ULL 
                                                               * 
                                                               (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_7_value 
                                                                                >> 0x1fU)))))) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_7_value)))) 
                                                              >> 0x14U))) 
                                                  + 
                                                  ((IData)(
                                                           (0xffffffffULL 
                                                            & ((0x1efb3ULL 
                                                                * 
                                                                (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_8_value 
                                                                                >> 0x1fU)))))) 
                                                                  << 0x20U) 
                                                                 | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_8_value)))) 
                                                               >> 0x14U))) 
                                                   + 
                                                   ((IData)(
                                                            (0xffffffffULL 
                                                             & ((0x1c8beULL 
                                                                 * 
                                                                 (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_9_value 
                                                                                >> 0x1fU)))))) 
                                                                   << 0x20U) 
                                                                  | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_9_value)))) 
                                                                >> 0x14U))) 
                                                    + 
                                                    ((IData)(
                                                             (0xffffffffULL 
                                                              & ((0x18190ULL 
                                                                  * 
                                                                  (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_10_value 
                                                                                >> 0x1fU)))))) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_10_value)))) 
                                                                 >> 0x14U))) 
                                                     + 
                                                     ((IData)(
                                                              (0xffffffffULL 
                                                               & ((0x12679ULL 
                                                                   * 
                                                                   (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_11_value 
                                                                                >> 0x1fU)))))) 
                                                                     << 0x20U) 
                                                                    | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_11_value)))) 
                                                                  >> 0x14U))) 
                                                      + 
                                                      ((IData)(
                                                               (0xffffffffULL 
                                                                & ((0xc737ULL 
                                                                    * 
                                                                    (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_12_value 
                                                                                >> 0x1fU)))))) 
                                                                      << 0x20U) 
                                                                     | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_12_value)))) 
                                                                   >> 0x14U))) 
                                                       + 
                                                       ((IData)(
                                                                (0xffffffffULL 
                                                                 & ((0x7445ULL 
                                                                     * 
                                                                     (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_13_value 
                                                                                >> 0x1fU)))))) 
                                                                       << 0x20U) 
                                                                      | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_13_value)))) 
                                                                    >> 0x14U))) 
                                                        + 
                                                        ((IData)(
                                                                 (0xffffffffULL 
                                                                  & ((0x3bf8ULL 
                                                                      * 
                                                                      (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_14_value 
                                                                                >> 0x1fU)))))) 
                                                                        << 0x20U) 
                                                                       | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_14_value)))) 
                                                                     >> 0x14U))) 
                                                         + (IData)(
                                                                   (0xffffffffULL 
                                                                    & ((0x280eULL 
                                                                        * 
                                                                        (((QData)((IData)(
                                                                                (0xfffffU 
                                                                                & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_15_value 
                                                                                >> 0x1fU)))))) 
                                                                          << 0x20U) 
                                                                         | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_15_value)))) 
                                                                       >> 0x14U))))))))))))))))))),32);
    bufp->fullIData(oldp+2,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_0_value),32);
    bufp->fullIData(oldp+3,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_1_value),32);
    bufp->fullIData(oldp+4,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_2_value),32);
    bufp->fullIData(oldp+5,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_3_value),32);
    bufp->fullIData(oldp+6,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_4_value),32);
    bufp->fullIData(oldp+7,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_5_value),32);
    bufp->fullIData(oldp+8,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_6_value),32);
    bufp->fullIData(oldp+9,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_7_value),32);
    bufp->fullIData(oldp+10,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_8_value),32);
    bufp->fullIData(oldp+11,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_9_value),32);
    bufp->fullIData(oldp+12,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_10_value),32);
    bufp->fullIData(oldp+13,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_11_value),32);
    bufp->fullIData(oldp+14,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_12_value),32);
    bufp->fullIData(oldp+15,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_13_value),32);
    bufp->fullIData(oldp+16,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_14_value),32);
    bufp->fullIData(oldp+17,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_15_value),32);
    bufp->fullBit(oldp+18,(vlSelfRef.FIR_tb__DOT__clock));
    bufp->fullBit(oldp+19,(vlSelfRef.FIR_tb__DOT__reset));
    bufp->fullIData(oldp+20,(vlSelfRef.FIR_tb__DOT__io_in_value),32);
    bufp->fullIData(oldp+21,(vlSelfRef.FIR_tb__DOT__unnamedblk1__DOT__i),32);
}
