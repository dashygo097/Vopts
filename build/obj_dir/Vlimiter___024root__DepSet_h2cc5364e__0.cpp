// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlimiter.h for the primary calling header

#include "Vlimiter__pch.h"
#include "Vlimiter__Syms.h"
#include "Vlimiter___024root.h"

VL_INLINE_OPT VlCoroutine Vlimiter___024root___eval_initial__TOP__Vtiming__0(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x69746572U;
    __Vtemp_1[2U] = 0x6c696dU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.Limiter_tb__DOT__clock = 0U;
    vlSelfRef.Limiter_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x4e20ULL, 
                                         nullptr, "limiter_tb.sv", 
                                         28);
    vlSelfRef.Limiter_tb__DOT__reset = 0U;
    vlSelfRef.Limiter_tb__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x7d0U, vlSelfRef.Limiter_tb__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.Limiter_tb__DOT__io_in_value = VL_RTOI_I_D(
                                                             (1.04857600000000000e+06 
                                                              * 
                                                              sin(
                                                                  ((6.28318530717958623e+00 
                                                                    * 
                                                                    VL_ISTOR_D_I(32, vlSelfRef.Limiter_tb__DOT__unnamedblk1__DOT__i)) 
                                                                   / 100.0))));
        co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                             nullptr, 
                                             "limiter_tb.sv", 
                                             33);
        vlSelfRef.Limiter_tb__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.Limiter_tb__DOT__unnamedblk1__DOT__i);
    }
    VL_FINISH_MT("limiter_tb.sv", 37, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlimiter___024root___dump_triggers__act(Vlimiter___024root* vlSelf);
#endif  // VL_DEBUG

void Vlimiter___024root___eval_triggers__act(Vlimiter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root___eval_triggers__act\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, vlSelfRef.__VdlySched.awaitingCurrentTime());
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vlimiter___024root___dump_triggers__act(vlSelf);
    }
#endif
}
