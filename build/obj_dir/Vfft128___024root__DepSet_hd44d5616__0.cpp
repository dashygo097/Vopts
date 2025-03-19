// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft128.h for the primary calling header

#include "Vfft128__pch.h"
#include "Vfft128__Syms.h"
#include "Vfft128___024root.h"

VL_INLINE_OPT VlCoroutine Vfft128___024root___eval_initial__TOP__Vtiming__0(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x74313238U;
    __Vtemp_1[2U] = 0x6666U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.FFT128_tb__DOT__clock = 0U;
    vlSelfRef.FFT128_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x4e20ULL, 
                                         nullptr, "fft128_tb.sv", 
                                         40);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.FFT128_tb__DOT__reset = 0U;
    vlSelfRef.FFT128_tb__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x80U, vlSelfRef.FFT128_tb__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.FFT128_tb__DOT__io_in_real = VL_RTOI_I_D(
                                                           (1.04857600000000000e+06 
                                                            * 
                                                            sin(
                                                                ((6.28318530717958623e+00 
                                                                  * 
                                                                  VL_ISTOR_D_I(32, vlSelfRef.FFT128_tb__DOT__unnamedblk1__DOT__i)) 
                                                                 / 128.0))));
        vlSelfRef.FFT128_tb__DOT__io_in_imag = 0U;
        vlSelfRef.FFT128_tb__DOT__io_in_valid = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                             nullptr, 
                                             "fft128_tb.sv", 
                                             47);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.FFT128_tb__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.FFT128_tb__DOT__unnamedblk1__DOT__i);
    }
    co_await vlSelfRef.__VdlySched.delay(0x271000ULL, 
                                         nullptr, "fft128_tb.sv", 
                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("fft128_tb.sv", 54, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft128___024root___dump_triggers__act(Vfft128___024root* vlSelf);
#endif  // VL_DEBUG

void Vfft128___024root___eval_triggers__act(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_triggers__act\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.FFT128_tb__DOT__clock) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__FFT128_tb__DOT__clock__0))));
    vlSelfRef.__VactTriggered.set(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__FFT128_tb__DOT__clock__0 
        = vlSelfRef.FFT128_tb__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfft128___024root___dump_triggers__act(vlSelf);
    }
#endif
}
