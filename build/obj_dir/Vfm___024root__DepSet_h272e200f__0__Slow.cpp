// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfm.h for the primary calling header

#include "Vfm__pch.h"
#include "Vfm__Syms.h"
#include "Vfm___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfm___024root___dump_triggers__stl(Vfm___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfm___024root___eval_triggers__stl(Vfm___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfm___024root___eval_triggers__stl\n"); );
    Vfm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfm___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
