// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfft128.h for the primary calling header

#include "Vfft128__pch.h"
#include "Vfft128__Syms.h"
#include "Vfft128___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfft128___024root___dump_triggers__stl(Vfft128___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfft128___024root___eval_triggers__stl(Vfft128___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root___eval_triggers__stl\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfft128___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
