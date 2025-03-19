// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfir.h for the primary calling header

#ifndef VERILATED_VFIR___024ROOT_H_
#define VERILATED_VFIR___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vfir__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfir___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ FIR_tb__DOT__clock;
    CData/*0:0*/ FIR_tb__DOT__reset;
    CData/*0:0*/ __Vtrigprevexpr___TOP__FIR_tb__DOT__clock__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ FIR_tb__DOT__io_in_value;
    IData/*31:0*/ FIR_tb__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_0_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_1_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_2_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_3_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_4_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_5_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_6_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_7_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_8_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_9_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_10_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_11_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_12_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_13_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_14_value;
    IData/*31:0*/ FIR_tb__DOT__uut__DOT__regs_15_value;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfir__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfir___024root(Vfir__Syms* symsp, const char* v__name);
    ~Vfir___024root();
    VL_UNCOPYABLE(Vfir___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
