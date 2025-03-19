// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfir__Syms.h"


void Vfir___024root__trace_chg_0_sub_0(Vfir___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfir___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root__trace_chg_0\n"); );
    // Init
    Vfir___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfir___024root*>(voidSelf);
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfir___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vfir___024root__trace_chg_0_sub_0(Vfir___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root__trace_chg_0_sub_0\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(((IData)((0xffffffffULL 
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
                                                * (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelfRef.FIR_tb__DOT__uut__DOT__regs_1_value 
                                                                                >> 0x1fU)))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_1_value)))) 
                                               >> 0x14U))) 
                                   + ((IData)((0xffffffffULL 
                                               & ((0x7445ULL 
                                                   * 
                                                   (((QData)((IData)(
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
                                         + ((IData)(
                                                    (0xffffffffULL 
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
                                                  + 
                                                  ((IData)(
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
        bufp->chgIData(oldp+1,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_0_value),32);
        bufp->chgIData(oldp+2,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_1_value),32);
        bufp->chgIData(oldp+3,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_2_value),32);
        bufp->chgIData(oldp+4,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_3_value),32);
        bufp->chgIData(oldp+5,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_4_value),32);
        bufp->chgIData(oldp+6,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_5_value),32);
        bufp->chgIData(oldp+7,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_6_value),32);
        bufp->chgIData(oldp+8,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_7_value),32);
        bufp->chgIData(oldp+9,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_8_value),32);
        bufp->chgIData(oldp+10,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_9_value),32);
        bufp->chgIData(oldp+11,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_10_value),32);
        bufp->chgIData(oldp+12,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_11_value),32);
        bufp->chgIData(oldp+13,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_12_value),32);
        bufp->chgIData(oldp+14,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_13_value),32);
        bufp->chgIData(oldp+15,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_14_value),32);
        bufp->chgIData(oldp+16,(vlSelfRef.FIR_tb__DOT__uut__DOT__regs_15_value),32);
    }
    bufp->chgBit(oldp+17,(vlSelfRef.FIR_tb__DOT__clock));
    bufp->chgBit(oldp+18,(vlSelfRef.FIR_tb__DOT__reset));
    bufp->chgIData(oldp+19,(vlSelfRef.FIR_tb__DOT__io_in_value),32);
    bufp->chgIData(oldp+20,(vlSelfRef.FIR_tb__DOT__unnamedblk1__DOT__i),32);
}

void Vfir___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root__trace_cleanup\n"); );
    // Init
    Vfir___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfir___024root*>(voidSelf);
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
