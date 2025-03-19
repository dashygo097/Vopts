// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfm__Syms.h"


void Vfm___024root__trace_chg_0_sub_0(Vfm___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfm___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root__trace_chg_0\n"); );
    // Init
    Vfm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfm___024root*>(voidSelf);
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfm___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<256>/*8191:0*/ Vfm__ConstPool__CONST_hfdda0392_0;

void Vfm___024root__trace_chg_0_sub_0(Vfm___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root__trace_chg_0_sub_0\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.FM_tb__DOT__clock));
    bufp->chgBit(oldp+1,(vlSelfRef.FM_tb__DOT__reset));
    bufp->chgIData(oldp+2,(vlSelfRef.FM_tb__DOT__io_in_value),32);
    bufp->chgIData(oldp+3,((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
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
                                       >> 5U)] << ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(13,13,32, 
                                                                    (0xffU 
                                                                     & (vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
                                                                        >> 0x10U)), 5U))))) 
                            | (Vfm__ConstPool__CONST_hfdda0392_0[
                               (0xffU & (VL_SHIFTL_III(13,13,32, 
                                                       (0xffU 
                                                        & (vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
                                                           >> 0x10U)), 5U) 
                                         >> 5U))] >> 
                               (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                      (0xffU 
                                                       & (vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase 
                                                          >> 0x10U)), 5U))))),32);
    bufp->chgIData(oldp+4,(vlSelfRef.FM_tb__DOT__unnamedblk1__DOT__i),32);
    bufp->chgIData(oldp+5,((0xffffffU & (IData)((0xfffffffffffffULL 
                                                 & VL_DIVS_QQQ(52, 
                                                               (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.FM_tb__DOT__uut__DOT___trig_io_phase_delta_T 
                                                                                >> 0x32U))))) 
                                                                 << 0x33U) 
                                                                | vlSelfRef.FM_tb__DOT__uut__DOT___trig_io_phase_delta_T), 0x100000ULL))))),24);
    bufp->chgIData(oldp+6,(vlSelfRef.FM_tb__DOT__uut__DOT__trig__DOT__phase),24);
}

void Vfm___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root__trace_cleanup\n"); );
    // Init
    Vfm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfm___024root*>(voidSelf);
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
