// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdds_cw.h for the primary calling header

#include "Vdds_cw__pch.h"
#include "Vdds_cw__Syms.h"
#include "Vdds_cw___024root.h"

VL_INLINE_OPT VlCoroutine Vdds_cw___024root___eval_initial__TOP__Vtiming__0(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x735f6377U;
    __Vtemp_1[2U] = 0x6464U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.CW_tb__DOT__clock = 0U;
    vlSelfRef.CW_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x4e20ULL, 
                                         nullptr, "dds_cw_tb.sv", 
                                         26);
    vlSelfRef.CW_tb__DOT__reset = 0U;
    co_await vlSelfRef.__VdlySched.delay(0xbebc200ULL, 
                                         nullptr, "dds_cw_tb.sv", 
                                         28);
    VL_FINISH_MT("dds_cw_tb.sv", 31, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdds_cw___024root___dump_triggers__act(Vdds_cw___024root* vlSelf);
#endif  // VL_DEBUG

void Vdds_cw___024root___eval_triggers__act(Vdds_cw___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_cw___024root___eval_triggers__act\n"); );
    Vdds_cw__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.CW_tb__DOT__clock) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CW_tb__DOT__clock__0))));
    vlSelfRef.__VactTriggered.set(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__CW_tb__DOT__clock__0 
        = vlSelfRef.CW_tb__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdds_cw___024root___dump_triggers__act(vlSelf);
    }
#endif
}
