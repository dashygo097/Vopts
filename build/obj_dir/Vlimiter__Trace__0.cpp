// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlimiter__Syms.h"


void Vlimiter___024root__trace_chg_0_sub_0(Vlimiter___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vlimiter___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root__trace_chg_0\n"); );
    // Init
    Vlimiter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlimiter___024root*>(voidSelf);
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vlimiter___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vlimiter___024root__trace_chg_0_sub_0(Vlimiter___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root__trace_chg_0_sub_0\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.Limiter_tb__DOT__clock));
    bufp->chgBit(oldp+1,(vlSelfRef.Limiter_tb__DOT__reset));
    bufp->chgIData(oldp+2,(vlSelfRef.Limiter_tb__DOT__io_in_value),32);
    bufp->chgIData(oldp+3,((VL_LTS_III(32, 0x80000U, vlSelfRef.Limiter_tb__DOT__io_in_value)
                             ? 0x80000U : (VL_GTS_III(32, 0xfff80000U, vlSelfRef.Limiter_tb__DOT__io_in_value)
                                            ? 0xfff80000U
                                            : vlSelfRef.Limiter_tb__DOT__io_in_value))),32);
    bufp->chgIData(oldp+4,(vlSelfRef.Limiter_tb__DOT__unnamedblk1__DOT__i),32);
}

void Vlimiter___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root__trace_cleanup\n"); );
    // Init
    Vlimiter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlimiter___024root*>(voidSelf);
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
