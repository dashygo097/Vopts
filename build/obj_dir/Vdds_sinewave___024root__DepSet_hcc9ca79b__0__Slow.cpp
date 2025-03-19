// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdds_sinewave.h for the primary calling header

#include "Vdds_sinewave__pch.h"
#include "Vdds_sinewave__Syms.h"
#include "Vdds_sinewave___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdds_sinewave___024root___dump_triggers__stl(Vdds_sinewave___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdds_sinewave___024root___eval_triggers__stl(Vdds_sinewave___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_sinewave___024root___eval_triggers__stl\n"); );
    Vdds_sinewave__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdds_sinewave___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
