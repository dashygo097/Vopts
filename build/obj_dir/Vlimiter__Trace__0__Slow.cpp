// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlimiter__Syms.h"


VL_ATTR_COLD void Vlimiter___024root__trace_init_sub__TOP__0(Vlimiter___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root__trace_init_sub__TOP__0\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("Limiter_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_in_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"io_out_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+5,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_in_value",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"io_out_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vlimiter___024root__trace_init_top(Vlimiter___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root__trace_init_top\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vlimiter___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vlimiter___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vlimiter___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vlimiter___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vlimiter___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vlimiter___024root__trace_register(Vlimiter___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root__trace_register\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vlimiter___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vlimiter___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vlimiter___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vlimiter___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vlimiter___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root__trace_const_0\n"); );
    // Init
    Vlimiter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlimiter___024root*>(voidSelf);
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vlimiter___024root__trace_full_0_sub_0(Vlimiter___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vlimiter___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root__trace_full_0\n"); );
    // Init
    Vlimiter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlimiter___024root*>(voidSelf);
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vlimiter___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vlimiter___024root__trace_full_0_sub_0(Vlimiter___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlimiter___024root__trace_full_0_sub_0\n"); );
    Vlimiter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.Limiter_tb__DOT__clock));
    bufp->fullBit(oldp+2,(vlSelfRef.Limiter_tb__DOT__reset));
    bufp->fullIData(oldp+3,(vlSelfRef.Limiter_tb__DOT__io_in_value),32);
    bufp->fullIData(oldp+4,((VL_LTS_III(32, 0x80000U, vlSelfRef.Limiter_tb__DOT__io_in_value)
                              ? 0x80000U : (VL_GTS_III(32, 0xfff80000U, vlSelfRef.Limiter_tb__DOT__io_in_value)
                                             ? 0xfff80000U
                                             : vlSelfRef.Limiter_tb__DOT__io_in_value))),32);
    bufp->fullIData(oldp+5,(vlSelfRef.Limiter_tb__DOT__unnamedblk1__DOT__i),32);
}
