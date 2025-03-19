// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfm_en.h for the primary calling header

#include "Vfm_en__pch.h"
#include "Vfm_en__Syms.h"
#include "Vfm_en___024root.h"

VL_INLINE_OPT VlCoroutine Vfm_en___024root___eval_initial__TOP__Vtiming__0(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x6d5f656eU;
    __Vtemp_1[2U] = 0x66U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.FM_tb__DOT__clock = 0U;
    vlSelfRef.FM_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x1e8480ULL, 
                                         nullptr, "fm_en_tb.sv", 
                                         28);
    VL_FINISH_MT("fm_en_tb.sv", 31, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm_en___024root___dump_triggers__act(Vfm_en___024root* vlSelf);
#endif  // VL_DEBUG

void Vfm_en___024root___eval_triggers__act(Vfm_en___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm_en___024root___eval_triggers__act\n"); );
    Vfm_en__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.FM_tb__DOT__clock) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__FM_tb__DOT__clock__0))));
    vlSelfRef.__VactTriggered.set(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__FM_tb__DOT__clock__0 
        = vlSelfRef.FM_tb__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfm_en___024root___dump_triggers__act(vlSelf);
    }
#endif
}
