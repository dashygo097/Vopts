// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfm_en__Syms.h"


void Vfm_en___024root__trace_chg_0_sub_0(Vfm_en___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfm_en___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root__trace_chg_0\n"); );
    // Init
    Vfm_en___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfm_en___024root*>(voidSelf);
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfm_en___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<256>/*8191:0*/ Vfm_en__ConstPool__CONST_hfdda0392_0;

void Vfm_en___024root__trace_chg_0_sub_0(Vfm_en___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root__trace_chg_0_sub_0\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
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
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(13,13,32, 
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
        bufp->chgIData(oldp+1,((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
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
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(13,13,32, 
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
        bufp->chgSData(oldp+2,(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase),16);
        bufp->chgSData(oldp+3,((0xffffU & (((0U == 
                                             (0x1fU 
                                              & ((IData)(0x10U) 
                                                 + 
                                                 (0x1fffU 
                                                  & VL_SHIFTL_III(13,13,32, 
                                                                  (0xffU 
                                                                   & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                      >> 8U)), 5U)))))
                                             ? 0U : 
                                            (Vfm_en__ConstPool__CONST_hfdda0392_0[
                                             (((IData)(0x1fU) 
                                               + (0x1fffU 
                                                  & VL_SHIFTL_III(13,13,32, 
                                                                  (0xffU 
                                                                   & ((IData)(vlSelfRef.FM_tb__DOT__uut__DOT__cw__DOT__phase) 
                                                                      >> 8U)), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
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
        bufp->chgSData(oldp+4,(vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase),16);
    }
    bufp->chgBit(oldp+5,(vlSelfRef.FM_tb__DOT__clock));
    bufp->chgBit(oldp+6,(vlSelfRef.FM_tb__DOT__reset));
}

void Vfm_en___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root__trace_cleanup\n"); );
    // Init
    Vfm_en___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfm_en___024root*>(voidSelf);
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
