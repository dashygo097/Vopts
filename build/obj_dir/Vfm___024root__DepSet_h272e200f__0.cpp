// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfm.h for the primary calling header

#include "Vfm__pch.h"
#include "Vfm__Syms.h"
#include "Vfm___024root.h"

VL_INLINE_OPT VlCoroutine Vfm___024root___eval_initial__TOP__Vtiming__0(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"fm.vcd"});
    vlSymsp->_traceDumpOpen();
    vlSelfRef.FM_tb__DOT__clock = 0U;
    vlSelfRef.FM_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x4e20ULL, 
                                         nullptr, "fm_tb.sv", 
                                         28);
    vlSelfRef.FM_tb__DOT__reset = 0U;
    vlSelfRef.FM_tb__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x7d0U, vlSelfRef.FM_tb__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.FM_tb__DOT__io_in_value = VL_RTOI_I_D(
                                                        (1.04857600000000000e+06 
                                                         * 
                                                         sin(
                                                             ((6.28318530717958623e+00 
                                                               * 
                                                               VL_ISTOR_D_I(32, vlSelfRef.FM_tb__DOT__unnamedblk1__DOT__i)) 
                                                              / 100.0))));
        co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                             nullptr, 
                                             "fm_tb.sv", 
                                             33);
        vlSelfRef.FM_tb__DOT__unnamedblk1__DOT__i = 
            ((IData)(1U) + vlSelfRef.FM_tb__DOT__unnamedblk1__DOT__i);
    }
    VL_FINISH_MT("fm_tb.sv", 37, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm___024root___dump_triggers__act(Vfm___024root* vlSelf);
#endif  // VL_DEBUG

void Vfm___024root___eval_triggers__act(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_triggers__act\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.FM_tb__DOT__clock) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__FM_tb__DOT__clock__0))));
    vlSelfRef.__VactTriggered.set(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__FM_tb__DOT__clock__0 
        = vlSelfRef.FM_tb__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfm___024root___dump_triggers__act(vlSelf);
    }
#endif
}
