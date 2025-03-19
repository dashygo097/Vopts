// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdds_trig.h for the primary calling header

#include "Vdds_trig__pch.h"
#include "Vdds_trig__Syms.h"
#include "Vdds_trig___024root.h"

VL_INLINE_OPT VlCoroutine Vdds_trig___024root___eval_initial__TOP__Vtiming__0(Vdds_trig___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_trig___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vdds_trig__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x74726967U;
    __Vtemp_1[2U] = 0x6464735fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.TrigDDS_tb__DOT__clock = 0U;
    vlSelfRef.TrigDDS_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x4e20ULL, 
                                         nullptr, "dds_trig_tb.v", 
                                         30);
    vlSelfRef.TrigDDS_tb__DOT__reset = 0U;
    vlSelfRef.TrigDDS_tb__DOT__io_mag_value = 0x100000U;
    vlSelfRef.TrigDDS_tb__DOT__io_phase_delta = 0U;
    co_await vlSelfRef.__VdlySched.delay(0xbebc200ULL, 
                                         nullptr, "dds_trig_tb.v", 
                                         34);
    vlSelfRef.TrigDDS_tb__DOT__io_mag_value = 0x200000U;
    vlSelfRef.TrigDDS_tb__DOT__io_phase_delta = 0U;
    co_await vlSelfRef.__VdlySched.delay(0xbebc200ULL, 
                                         nullptr, "dds_trig_tb.v", 
                                         37);
    vlSelfRef.TrigDDS_tb__DOT__io_mag_value = 0x200000U;
    vlSelfRef.TrigDDS_tb__DOT__io_phase_delta = 0x1000U;
    co_await vlSelfRef.__VdlySched.delay(0xbebc200ULL, 
                                         nullptr, "dds_trig_tb.v", 
                                         40);
    VL_FINISH_MT("dds_trig_tb.v", 43, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdds_trig___024root___dump_triggers__act(Vdds_trig___024root* vlSelf);
#endif  // VL_DEBUG

void Vdds_trig___024root___eval_triggers__act(Vdds_trig___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdds_trig___024root___eval_triggers__act\n"); );
    Vdds_trig__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.TrigDDS_tb__DOT__clock) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__TrigDDS_tb__DOT__clock__0))));
    vlSelfRef.__VactTriggered.set(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__TrigDDS_tb__DOT__clock__0 
        = vlSelfRef.TrigDDS_tb__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdds_trig___024root___dump_triggers__act(vlSelf);
    }
#endif
}
