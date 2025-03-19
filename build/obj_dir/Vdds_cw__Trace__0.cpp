// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdds_cw__Syms.h"


void Vdds_cw___024root__trace_chg_0_sub_0(Vdds_cw___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdds_cw___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root__trace_chg_0\n"); );
    // Init
    Vdds_cw___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdds_cw___024root*>(voidSelf);
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdds_cw___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<256>/*8191:0*/ Vdds_cw__ConstPool__CONST_h0a54ad8e_0;

void Vdds_cw___024root__trace_chg_0_sub_0(Vdds_cw___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root__trace_chg_0_sub_0\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.CW_tb__DOT__clock));
    bufp->chgBit(oldp+1,(vlSelfRef.CW_tb__DOT__reset));
    bufp->chgIData(oldp+2,((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                           (0xffU 
                                                            & (vlSelfRef.CW_tb__DOT__uut__DOT__phase 
                                                               >> 0x10U)), 5U)))
                              ? 0U : (Vdds_cw__ConstPool__CONST_h0a54ad8e_0[
                                      (((IData)(0x1fU) 
                                        + (0x1fffU 
                                           & VL_SHIFTL_III(13,13,32, 
                                                           (0xffU 
                                                            & (vlSelfRef.CW_tb__DOT__uut__DOT__phase 
                                                               >> 0x10U)), 5U))) 
                                       >> 5U)] << ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(13,13,32, 
                                                                    (0xffU 
                                                                     & (vlSelfRef.CW_tb__DOT__uut__DOT__phase 
                                                                        >> 0x10U)), 5U))))) 
                            | (Vdds_cw__ConstPool__CONST_h0a54ad8e_0[
                               (0xffU & (VL_SHIFTL_III(13,13,32, 
                                                       (0xffU 
                                                        & (vlSelfRef.CW_tb__DOT__uut__DOT__phase 
                                                           >> 0x10U)), 5U) 
                                         >> 5U))] >> 
                               (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                      (0xffU 
                                                       & (vlSelfRef.CW_tb__DOT__uut__DOT__phase 
                                                          >> 0x10U)), 5U))))),32);
    bufp->chgIData(oldp+3,(vlSelfRef.CW_tb__DOT__uut__DOT__phase),24);
}

void Vdds_cw___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root__trace_cleanup\n"); );
    // Init
    Vdds_cw___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdds_cw___024root*>(voidSelf);
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
