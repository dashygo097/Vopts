// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfir.h for the primary calling header

#include "Vfir__pch.h"
#include "Vfir__Syms.h"
#include "Vfir___024root.h"

VL_INLINE_OPT VlCoroutine Vfir___024root___eval_initial__TOP__Vtiming__0(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"fir.vcd"});
    vlSymsp->_traceDumpOpen();
    vlSelfRef.FIR_tb__DOT__clock = 0U;
    vlSelfRef.FIR_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x4e20ULL, 
                                         nullptr, "fir_tb.sv", 
                                         28);
    vlSelfRef.FIR_tb__DOT__reset = 0U;
    vlSelfRef.FIR_tb__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x4e20U, vlSelfRef.FIR_tb__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.FIR_tb__DOT__io_in_value = (VL_RTOI_I_D(
                                                          (1.04857600000000000e+06 
                                                           * 
                                                           sin(
                                                               ((6.28318530717958623e+00 
                                                                 * 
                                                                 VL_ISTOR_D_I(32, vlSelfRef.FIR_tb__DOT__unnamedblk1__DOT__i)) 
                                                                / 10.0)))) 
                                              + VL_RTOI_I_D(
                                                            (1.04857600000000000e+06 
                                                             * 
                                                             sin(
                                                                 ((6.28318530717958623e+00 
                                                                   * 
                                                                   VL_ISTOR_D_I(32, vlSelfRef.FIR_tb__DOT__unnamedblk1__DOT__i)) 
                                                                  / 1.00000000000000000e+03)))));
        co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                             nullptr, 
                                             "fir_tb.sv", 
                                             34);
        vlSelfRef.FIR_tb__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.FIR_tb__DOT__unnamedblk1__DOT__i);
    }
    VL_FINISH_MT("fir_tb.sv", 38, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfir___024root___dump_triggers__act(Vfir___024root* vlSelf);
#endif  // VL_DEBUG

void Vfir___024root___eval_triggers__act(Vfir___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfir___024root___eval_triggers__act\n"); );
    Vfir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.FIR_tb__DOT__clock) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__FIR_tb__DOT__clock__0))));
    vlSelfRef.__VactTriggered.set(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__FIR_tb__DOT__clock__0 
        = vlSelfRef.FIR_tb__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfir___024root___dump_triggers__act(vlSelf);
    }
#endif
}
