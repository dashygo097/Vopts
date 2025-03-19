// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfft128__Syms.h"


VL_ATTR_COLD void Vfft128___024root__trace_init_sub__TOP__0(Vfft128___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root__trace_init_sub__TOP__0\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("FFT128_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+609,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"io_in_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"io_in_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"io_in_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"io_out1_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"io_out1_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,0,"io_out2_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"io_out2_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+82,0,"io_out_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+5,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+609,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"io_in_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"io_in_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"io_in_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+82,0,"io_out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+83,0,"cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+84,0,"r_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"r_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"r_1_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"r_1_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"r_2_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"r_2_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"r_3_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"r_3_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"r_4_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"r_4_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"r_5_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"r_5_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"r_6_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"r_6_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"r_7_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"r_7_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"r_8_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"r_8_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"r_9_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"r_9_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"r_10_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+105,0,"r_10_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"r_11_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"r_11_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"r_12_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"r_12_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"r_13_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"r_13_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"r_14_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"r_14_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"r_15_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"r_15_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"r_16_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"r_16_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"r_17_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"r_17_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+120,0,"r_18_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"r_18_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"r_19_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"r_19_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+124,0,"r_20_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+125,0,"r_20_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"r_21_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"r_21_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"r_22_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+129,0,"r_22_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"r_23_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"r_23_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+132,0,"r_24_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+133,0,"r_24_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"r_25_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"r_25_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"r_26_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"r_26_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"r_27_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"r_27_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"r_28_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"r_28_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+142,0,"r_29_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+143,0,"r_29_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+144,0,"r_30_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"r_30_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"r_31_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"r_31_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+148,0,"r_32_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+149,0,"r_32_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"r_33_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"r_33_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"r_34_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"r_34_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+154,0,"r_35_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+155,0,"r_35_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+156,0,"r_36_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+157,0,"r_36_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+158,0,"r_37_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+159,0,"r_37_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"r_38_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"r_38_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"r_39_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"r_39_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+164,0,"r_40_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"r_40_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"r_41_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"r_41_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"r_42_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"r_42_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"r_43_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"r_43_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"r_44_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"r_44_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"r_45_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"r_45_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"r_46_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"r_46_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"r_47_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"r_47_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"r_48_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+181,0,"r_48_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+182,0,"r_49_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"r_49_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"r_50_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"r_50_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+186,0,"r_51_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"r_51_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+188,0,"r_52_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"r_52_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+190,0,"r_53_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"r_53_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+192,0,"r_54_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+193,0,"r_54_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+194,0,"r_55_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+195,0,"r_55_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+196,0,"r_56_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"r_56_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+198,0,"r_57_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"r_57_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+200,0,"r_58_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+201,0,"r_58_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+202,0,"r_59_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+203,0,"r_59_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"r_60_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+205,0,"r_60_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+206,0,"r_61_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"r_61_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"r_62_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+209,0,"r_62_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"r_63_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"r_63_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"r_64_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+213,0,"r_64_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+214,0,"r_65_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+215,0,"r_65_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+216,0,"r_66_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+217,0,"r_66_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+218,0,"r_67_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+219,0,"r_67_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+220,0,"r_68_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+221,0,"r_68_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+222,0,"r_69_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+223,0,"r_69_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+224,0,"r_70_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+225,0,"r_70_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+226,0,"r_71_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+227,0,"r_71_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+228,0,"r_72_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+229,0,"r_72_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"r_73_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+231,0,"r_73_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+232,0,"r_74_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+233,0,"r_74_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"r_75_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+235,0,"r_75_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+236,0,"r_76_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+237,0,"r_76_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"r_77_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+239,0,"r_77_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+240,0,"r_78_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+241,0,"r_78_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"r_79_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+243,0,"r_79_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+244,0,"r_80_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+245,0,"r_80_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+246,0,"r_81_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+247,0,"r_81_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+248,0,"r_82_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+249,0,"r_82_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+250,0,"r_83_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+251,0,"r_83_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"r_84_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+253,0,"r_84_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"r_85_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+255,0,"r_85_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+256,0,"r_86_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+257,0,"r_86_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+258,0,"r_87_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+259,0,"r_87_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+260,0,"r_88_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+261,0,"r_88_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+262,0,"r_89_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+263,0,"r_89_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+264,0,"r_90_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+265,0,"r_90_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+266,0,"r_91_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+267,0,"r_91_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"r_92_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"r_92_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+270,0,"r_93_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+271,0,"r_93_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+272,0,"r_94_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"r_94_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"r_95_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"r_95_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"r_96_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+277,0,"r_96_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+278,0,"r_97_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+279,0,"r_97_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+280,0,"r_98_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+281,0,"r_98_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+282,0,"r_99_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+283,0,"r_99_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+284,0,"r_100_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+285,0,"r_100_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+286,0,"r_101_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+287,0,"r_101_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+288,0,"r_102_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+289,0,"r_102_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+290,0,"r_103_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+291,0,"r_103_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+292,0,"r_104_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+293,0,"r_104_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+294,0,"r_105_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+295,0,"r_105_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+296,0,"r_106_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+297,0,"r_106_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+298,0,"r_107_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+299,0,"r_107_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+300,0,"r_108_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+301,0,"r_108_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+302,0,"r_109_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"r_109_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+304,0,"r_110_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+305,0,"r_110_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+306,0,"r_111_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+307,0,"r_111_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+308,0,"r_112_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+309,0,"r_112_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+310,0,"r_113_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+311,0,"r_113_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+312,0,"r_114_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+313,0,"r_114_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+314,0,"r_115_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+315,0,"r_115_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+316,0,"r_116_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+317,0,"r_116_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+318,0,"r_117_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+319,0,"r_117_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+320,0,"r_118_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+321,0,"r_118_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+322,0,"r_119_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+323,0,"r_119_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+324,0,"r_120_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+325,0,"r_120_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+326,0,"r_121_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+327,0,"r_121_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+328,0,"r_122_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+329,0,"r_122_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+330,0,"r_123_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+331,0,"r_123_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+332,0,"r_124_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+333,0,"r_124_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+334,0,"r_125_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+335,0,"r_125_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+336,0,"r_126_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+337,0,"r_126_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+338,0,"r_127_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+339,0,"r_127_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+340,0,"r_128_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+341,0,"r_128_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+342,0,"r_129_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+343,0,"r_129_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+344,0,"r_130_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+345,0,"r_130_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+346,0,"r_131_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+347,0,"r_131_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+348,0,"r_132_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+349,0,"r_132_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+350,0,"r_133_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+351,0,"r_133_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+352,0,"r_134_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+353,0,"r_134_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+354,0,"r_135_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+355,0,"r_135_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+356,0,"r_136_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+357,0,"r_136_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+358,0,"r_137_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+359,0,"r_137_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+360,0,"r_138_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+361,0,"r_138_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+362,0,"r_139_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+363,0,"r_139_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+364,0,"r_140_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+365,0,"r_140_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+366,0,"r_141_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+367,0,"r_141_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+368,0,"r_142_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+369,0,"r_142_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+370,0,"r_143_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+371,0,"r_143_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+372,0,"r_144_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+373,0,"r_144_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+374,0,"r_145_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+375,0,"r_145_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+376,0,"r_146_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+377,0,"r_146_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+378,0,"r_147_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+379,0,"r_147_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+380,0,"r_148_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+381,0,"r_148_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+382,0,"r_149_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+383,0,"r_149_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+384,0,"r_150_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+385,0,"r_150_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+386,0,"r_151_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+387,0,"r_151_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+388,0,"r_152_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+389,0,"r_152_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+390,0,"r_153_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+391,0,"r_153_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+392,0,"r_154_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+393,0,"r_154_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+394,0,"r_155_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+395,0,"r_155_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+396,0,"r_156_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+397,0,"r_156_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+398,0,"r_157_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+399,0,"r_157_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+400,0,"r_158_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+401,0,"r_158_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+402,0,"r_159_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+403,0,"r_159_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+404,0,"r_160_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+405,0,"r_160_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+406,0,"r_161_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+407,0,"r_161_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+408,0,"r_162_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+409,0,"r_162_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+410,0,"r_163_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+411,0,"r_163_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+412,0,"r_164_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+413,0,"r_164_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+414,0,"r_165_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+415,0,"r_165_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+416,0,"r_166_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+417,0,"r_166_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+418,0,"r_167_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+419,0,"r_167_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+420,0,"r_168_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+421,0,"r_168_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+422,0,"r_169_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+423,0,"r_169_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+424,0,"r_170_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+425,0,"r_170_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+426,0,"r_171_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+427,0,"r_171_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+428,0,"r_172_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+429,0,"r_172_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+430,0,"r_173_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+431,0,"r_173_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+432,0,"r_174_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+433,0,"r_174_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+434,0,"r_175_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+435,0,"r_175_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+436,0,"r_176_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+437,0,"r_176_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+438,0,"r_177_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+439,0,"r_177_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+440,0,"r_178_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+441,0,"r_178_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+442,0,"r_179_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+443,0,"r_179_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+444,0,"r_180_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+445,0,"r_180_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+446,0,"r_181_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+447,0,"r_181_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+448,0,"r_182_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+449,0,"r_182_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+450,0,"r_183_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+451,0,"r_183_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+452,0,"r_184_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+453,0,"r_184_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+454,0,"r_185_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+455,0,"r_185_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+456,0,"r_186_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+457,0,"r_186_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+458,0,"r_187_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+459,0,"r_187_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+460,0,"r_188_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+461,0,"r_188_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+462,0,"out1_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+463,0,"out1_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"io_out1_REG_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"io_out1_REG_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,0,"io_out2_REG_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"io_out2_REG_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+464,0,"io_out_valid_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+465,0,"io_out_valid_r_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+466,0,"io_out_valid_r_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+467,0,"io_out_valid_r_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+468,0,"io_out_valid_r_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+469,0,"io_out_valid_r_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+470,0,"io_out_valid_r_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+471,0,"io_out_valid_r_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+472,0,"io_out_valid_r_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+473,0,"io_out_valid_r_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+474,0,"io_out_valid_r_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+475,0,"io_out_valid_r_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+476,0,"io_out_valid_r_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+477,0,"io_out_valid_r_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+478,0,"io_out_valid_r_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+479,0,"io_out_valid_r_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+480,0,"io_out_valid_r_16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+481,0,"io_out_valid_r_17",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+482,0,"io_out_valid_r_18",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+483,0,"io_out_valid_r_19",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+484,0,"io_out_valid_r_20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+485,0,"io_out_valid_r_21",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+486,0,"io_out_valid_r_22",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+487,0,"io_out_valid_r_23",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+488,0,"io_out_valid_r_24",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+489,0,"io_out_valid_r_25",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+490,0,"io_out_valid_r_26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+491,0,"io_out_valid_r_27",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+492,0,"io_out_valid_r_28",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+493,0,"io_out_valid_r_29",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+494,0,"io_out_valid_r_30",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+495,0,"io_out_valid_r_31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+496,0,"io_out_valid_r_32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+497,0,"io_out_valid_r_33",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+498,0,"io_out_valid_r_34",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+499,0,"io_out_valid_r_35",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+500,0,"io_out_valid_r_36",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+501,0,"io_out_valid_r_37",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+502,0,"io_out_valid_r_38",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+503,0,"io_out_valid_r_39",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"io_out_valid_r_40",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"io_out_valid_r_41",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+506,0,"io_out_valid_r_42",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+507,0,"io_out_valid_r_43",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+508,0,"io_out_valid_r_44",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+509,0,"io_out_valid_r_45",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+510,0,"io_out_valid_r_46",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+511,0,"io_out_valid_r_47",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+512,0,"io_out_valid_r_48",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+513,0,"io_out_valid_r_49",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+514,0,"io_out_valid_r_50",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+515,0,"io_out_valid_r_51",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+516,0,"io_out_valid_r_52",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+517,0,"io_out_valid_r_53",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+518,0,"io_out_valid_r_54",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+519,0,"io_out_valid_r_55",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+520,0,"io_out_valid_r_56",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+521,0,"io_out_valid_r_57",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+522,0,"io_out_valid_r_58",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+523,0,"io_out_valid_r_59",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+524,0,"io_out_valid_r_60",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+525,0,"io_out_valid_r_61",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+526,0,"io_out_valid_r_62",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+527,0,"io_out_valid_r_63",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+528,0,"io_out_valid_r_64",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+529,0,"io_out_valid_r_65",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+530,0,"io_out_valid_r_66",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+531,0,"io_out_valid_r_67",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+532,0,"io_out_valid_r_68",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+533,0,"io_out_valid_r_69",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+534,0,"io_out_valid_r_70",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+535,0,"io_out_valid_r_71",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+536,0,"io_out_valid_r_72",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+537,0,"io_out_valid_r_73",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+538,0,"io_out_valid_r_74",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+539,0,"io_out_valid_r_75",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+540,0,"io_out_valid_r_76",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+541,0,"io_out_valid_r_77",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+542,0,"io_out_valid_r_78",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+543,0,"io_out_valid_r_79",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+544,0,"io_out_valid_r_80",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+545,0,"io_out_valid_r_81",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+546,0,"io_out_valid_r_82",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+547,0,"io_out_valid_r_83",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+548,0,"io_out_valid_r_84",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+549,0,"io_out_valid_r_85",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+550,0,"io_out_valid_r_86",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+551,0,"io_out_valid_r_87",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+552,0,"io_out_valid_r_88",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+553,0,"io_out_valid_r_89",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+554,0,"io_out_valid_r_90",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+555,0,"io_out_valid_r_91",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+556,0,"io_out_valid_r_92",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+557,0,"io_out_valid_r_93",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+558,0,"io_out_valid_r_94",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+559,0,"io_out_valid_r_95",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+560,0,"io_out_valid_r_96",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+561,0,"io_out_valid_r_97",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+562,0,"io_out_valid_r_98",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+563,0,"io_out_valid_r_99",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+564,0,"io_out_valid_r_100",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+565,0,"io_out_valid_r_101",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"io_out_valid_r_102",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+567,0,"io_out_valid_r_103",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+568,0,"io_out_valid_r_104",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+569,0,"io_out_valid_r_105",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+570,0,"io_out_valid_r_106",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+571,0,"io_out_valid_r_107",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+572,0,"io_out_valid_r_108",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+573,0,"io_out_valid_r_109",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+574,0,"io_out_valid_r_110",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+575,0,"io_out_valid_r_111",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+576,0,"io_out_valid_r_112",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+577,0,"io_out_valid_r_113",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+578,0,"io_out_valid_r_114",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+579,0,"io_out_valid_r_115",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+580,0,"io_out_valid_r_116",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+581,0,"io_out_valid_r_117",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+582,0,"io_out_valid_r_118",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+583,0,"io_out_valid_r_119",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+584,0,"io_out_valid_r_120",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+585,0,"io_out_valid_r_121",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+586,0,"io_out_valid_r_122",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+587,0,"io_out_valid_r_123",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+588,0,"io_out_valid_r_124",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+589,0,"io_out_valid_r_125",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+590,0,"io_out_valid_r_126",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"io_out_valid_r_127",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("commutator", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+18,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+591,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+22,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+370,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+371,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+592,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+26,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+418,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+419,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+593,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+30,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+442,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+443,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+594,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+34,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+454,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+455,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+595,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+14,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+38,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+460,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+461,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+596,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("m", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+210,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+597,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+598,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+44,0,"tmp_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->declQuad(c+46,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+338,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+339,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+599,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+600,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+50,0,"tmp_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->declQuad(c+52,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+402,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+403,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+601,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+602,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+56,0,"tmp_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->declQuad(c+58,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+434,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+435,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+603,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+604,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+62,0,"tmp_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->declQuad(c+64,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+450,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+451,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+605,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+606,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+68,0,"tmp_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->declQuad(c+70,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+458,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+459,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+607,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+608,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+74,0,"tmp_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->declQuad(c+76,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfft128___024root__trace_init_top(Vfft128___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root__trace_init_top\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vfft128___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vfft128___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vfft128___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfft128___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfft128___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vfft128___024root__trace_register(Vfft128___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root__trace_register\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vfft128___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vfft128___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vfft128___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vfft128___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vfft128___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root__trace_const_0\n"); );
    // Init
    Vfft128___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft128___024root*>(voidSelf);
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vfft128___024root__trace_full_0_sub_0(Vfft128___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vfft128___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root__trace_full_0\n"); );
    // Init
    Vfft128___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft128___024root*>(voidSelf);
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vfft128___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<64>/*2047:0*/ Vfft128__ConstPool__CONST_h8abd5580_0;
extern const VlWide<64>/*2047:0*/ Vfft128__ConstPool__CONST_h16a5c00c_0;
extern const VlWide<32>/*1023:0*/ Vfft128__ConstPool__CONST_hb3c963b9_0;
extern const VlWide<32>/*1023:0*/ Vfft128__ConstPool__CONST_hffb3c89b_0;
extern const VlWide<16>/*511:0*/ Vfft128__ConstPool__CONST_h942db0a5_0;
extern const VlWide<16>/*511:0*/ Vfft128__ConstPool__CONST_ha2844606_0;
extern const VlWide<8>/*255:0*/ Vfft128__ConstPool__CONST_hfd15effc_0;
extern const VlWide<8>/*255:0*/ Vfft128__ConstPool__CONST_h5ba1edbd_0;

VL_ATTR_COLD void Vfft128___024root__trace_full_0_sub_0(Vfft128___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft128___024root__trace_full_0_sub_0\n"); );
    Vfft128__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.FFT128_tb__DOT__reset));
    bufp->fullIData(oldp+2,(vlSelfRef.FFT128_tb__DOT__io_in_real),32);
    bufp->fullIData(oldp+3,(vlSelfRef.FFT128_tb__DOT__io_in_imag),32);
    bufp->fullBit(oldp+4,(vlSelfRef.FFT128_tb__DOT__io_in_valid));
    bufp->fullIData(oldp+5,(vlSelfRef.FFT128_tb__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+6,(((0x20U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                              ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_real
                              : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_real)),32);
    bufp->fullIData(oldp+7,(((0x20U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                              ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_imag
                              : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_imag)),32);
    bufp->fullIData(oldp+8,(((0x10U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                              ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_real
                              : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_real)),32);
    bufp->fullIData(oldp+9,(((0x10U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                              ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_imag
                              : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_imag)),32);
    bufp->fullIData(oldp+10,(((8U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_real
                               : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_real)),32);
    bufp->fullIData(oldp+11,(((8U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_imag
                               : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_imag)),32);
    bufp->fullIData(oldp+12,(((4U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_real
                               : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_real)),32);
    bufp->fullIData(oldp+13,(((4U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_imag
                               : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_imag)),32);
    bufp->fullIData(oldp+14,(((2U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_real
                               : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_real)),32);
    bufp->fullIData(oldp+15,(((2U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_imag
                               : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_imag)),32);
    bufp->fullIData(oldp+16,(((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_real
                               : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_real)),32);
    bufp->fullIData(oldp+17,(((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_imag
                               : vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_imag)),32);
    bufp->fullIData(oldp+18,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_real),32);
    bufp->fullIData(oldp+19,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_io_out1_imag),32);
    bufp->fullIData(oldp+20,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_real),32);
    bufp->fullIData(oldp+21,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_io_out2_imag),32);
    bufp->fullIData(oldp+22,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_real),32);
    bufp->fullIData(oldp+23,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_1_io_out1_imag),32);
    bufp->fullIData(oldp+24,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_real),32);
    bufp->fullIData(oldp+25,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_1_io_out2_imag),32);
    bufp->fullIData(oldp+26,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_real),32);
    bufp->fullIData(oldp+27,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_2_io_out1_imag),32);
    bufp->fullIData(oldp+28,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_real),32);
    bufp->fullIData(oldp+29,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_2_io_out2_imag),32);
    bufp->fullIData(oldp+30,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_real),32);
    bufp->fullIData(oldp+31,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_3_io_out1_imag),32);
    bufp->fullIData(oldp+32,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_real),32);
    bufp->fullIData(oldp+33,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_3_io_out2_imag),32);
    bufp->fullIData(oldp+34,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_real),32);
    bufp->fullIData(oldp+35,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_4_io_out1_imag),32);
    bufp->fullIData(oldp+36,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_real),32);
    bufp->fullIData(oldp+37,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_4_io_out2_imag),32);
    bufp->fullIData(oldp+38,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_real),32);
    bufp->fullIData(oldp+39,(vlSelfRef.FFT128_tb__DOT__uut__DOT___m_5_io_out1_imag),32);
    bufp->fullIData(oldp+40,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_real),32);
    bufp->fullIData(oldp+41,(vlSelfRef.FFT128_tb__DOT__uut__DOT___commutator_5_io_out2_imag),32);
    bufp->fullIData(oldp+42,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+43,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullQData(oldp+44,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__tmp_k1),52);
    bufp->fullQData(oldp+46,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m__DOT__io_out2_k1),52);
    bufp->fullIData(oldp+48,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+49,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullQData(oldp+50,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__tmp_k1),52);
    bufp->fullQData(oldp+52,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1),52);
    bufp->fullIData(oldp+54,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+55,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullQData(oldp+56,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__tmp_k1),52);
    bufp->fullQData(oldp+58,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1),52);
    bufp->fullIData(oldp+60,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+61,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullQData(oldp+62,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__tmp_k1),52);
    bufp->fullQData(oldp+64,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1),52);
    bufp->fullIData(oldp+66,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+67,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullQData(oldp+68,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__tmp_k1),52);
    bufp->fullQData(oldp+70,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1),52);
    bufp->fullIData(oldp+72,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+73,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullQData(oldp+74,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__tmp_k1),52);
    bufp->fullQData(oldp+76,(vlSelfRef.FFT128_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1),52);
    bufp->fullIData(oldp+78,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out1_REG_real),32);
    bufp->fullIData(oldp+79,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out1_REG_imag),32);
    bufp->fullIData(oldp+80,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out2_REG_real),32);
    bufp->fullIData(oldp+81,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out2_REG_imag),32);
    bufp->fullBit(oldp+82,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_127));
    bufp->fullCData(oldp+83,(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt),7);
    bufp->fullIData(oldp+84,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_real),32);
    bufp->fullIData(oldp+85,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_imag),32);
    bufp->fullIData(oldp+86,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_1_real),32);
    bufp->fullIData(oldp+87,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_1_imag),32);
    bufp->fullIData(oldp+88,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_2_real),32);
    bufp->fullIData(oldp+89,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_2_imag),32);
    bufp->fullIData(oldp+90,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_3_real),32);
    bufp->fullIData(oldp+91,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_3_imag),32);
    bufp->fullIData(oldp+92,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_4_real),32);
    bufp->fullIData(oldp+93,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_4_imag),32);
    bufp->fullIData(oldp+94,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_5_real),32);
    bufp->fullIData(oldp+95,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_5_imag),32);
    bufp->fullIData(oldp+96,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_6_real),32);
    bufp->fullIData(oldp+97,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_6_imag),32);
    bufp->fullIData(oldp+98,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_7_real),32);
    bufp->fullIData(oldp+99,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_7_imag),32);
    bufp->fullIData(oldp+100,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_8_real),32);
    bufp->fullIData(oldp+101,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_8_imag),32);
    bufp->fullIData(oldp+102,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_9_real),32);
    bufp->fullIData(oldp+103,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_9_imag),32);
    bufp->fullIData(oldp+104,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_10_real),32);
    bufp->fullIData(oldp+105,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_10_imag),32);
    bufp->fullIData(oldp+106,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_11_real),32);
    bufp->fullIData(oldp+107,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_11_imag),32);
    bufp->fullIData(oldp+108,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_12_real),32);
    bufp->fullIData(oldp+109,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_12_imag),32);
    bufp->fullIData(oldp+110,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_13_real),32);
    bufp->fullIData(oldp+111,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_13_imag),32);
    bufp->fullIData(oldp+112,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_14_real),32);
    bufp->fullIData(oldp+113,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_14_imag),32);
    bufp->fullIData(oldp+114,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_15_real),32);
    bufp->fullIData(oldp+115,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_15_imag),32);
    bufp->fullIData(oldp+116,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_16_real),32);
    bufp->fullIData(oldp+117,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_16_imag),32);
    bufp->fullIData(oldp+118,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_17_real),32);
    bufp->fullIData(oldp+119,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_17_imag),32);
    bufp->fullIData(oldp+120,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_18_real),32);
    bufp->fullIData(oldp+121,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_18_imag),32);
    bufp->fullIData(oldp+122,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_19_real),32);
    bufp->fullIData(oldp+123,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_19_imag),32);
    bufp->fullIData(oldp+124,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_20_real),32);
    bufp->fullIData(oldp+125,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_20_imag),32);
    bufp->fullIData(oldp+126,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_21_real),32);
    bufp->fullIData(oldp+127,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_21_imag),32);
    bufp->fullIData(oldp+128,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_22_real),32);
    bufp->fullIData(oldp+129,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_22_imag),32);
    bufp->fullIData(oldp+130,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_23_real),32);
    bufp->fullIData(oldp+131,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_23_imag),32);
    bufp->fullIData(oldp+132,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_24_real),32);
    bufp->fullIData(oldp+133,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_24_imag),32);
    bufp->fullIData(oldp+134,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_25_real),32);
    bufp->fullIData(oldp+135,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_25_imag),32);
    bufp->fullIData(oldp+136,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_26_real),32);
    bufp->fullIData(oldp+137,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_26_imag),32);
    bufp->fullIData(oldp+138,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_27_real),32);
    bufp->fullIData(oldp+139,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_27_imag),32);
    bufp->fullIData(oldp+140,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_28_real),32);
    bufp->fullIData(oldp+141,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_28_imag),32);
    bufp->fullIData(oldp+142,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_29_real),32);
    bufp->fullIData(oldp+143,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_29_imag),32);
    bufp->fullIData(oldp+144,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_30_real),32);
    bufp->fullIData(oldp+145,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_30_imag),32);
    bufp->fullIData(oldp+146,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_31_real),32);
    bufp->fullIData(oldp+147,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_31_imag),32);
    bufp->fullIData(oldp+148,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_32_real),32);
    bufp->fullIData(oldp+149,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_32_imag),32);
    bufp->fullIData(oldp+150,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_33_real),32);
    bufp->fullIData(oldp+151,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_33_imag),32);
    bufp->fullIData(oldp+152,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_34_real),32);
    bufp->fullIData(oldp+153,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_34_imag),32);
    bufp->fullIData(oldp+154,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_35_real),32);
    bufp->fullIData(oldp+155,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_35_imag),32);
    bufp->fullIData(oldp+156,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_36_real),32);
    bufp->fullIData(oldp+157,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_36_imag),32);
    bufp->fullIData(oldp+158,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_37_real),32);
    bufp->fullIData(oldp+159,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_37_imag),32);
    bufp->fullIData(oldp+160,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_38_real),32);
    bufp->fullIData(oldp+161,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_38_imag),32);
    bufp->fullIData(oldp+162,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_39_real),32);
    bufp->fullIData(oldp+163,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_39_imag),32);
    bufp->fullIData(oldp+164,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_40_real),32);
    bufp->fullIData(oldp+165,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_40_imag),32);
    bufp->fullIData(oldp+166,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_41_real),32);
    bufp->fullIData(oldp+167,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_41_imag),32);
    bufp->fullIData(oldp+168,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_42_real),32);
    bufp->fullIData(oldp+169,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_42_imag),32);
    bufp->fullIData(oldp+170,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_43_real),32);
    bufp->fullIData(oldp+171,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_43_imag),32);
    bufp->fullIData(oldp+172,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_44_real),32);
    bufp->fullIData(oldp+173,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_44_imag),32);
    bufp->fullIData(oldp+174,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_45_real),32);
    bufp->fullIData(oldp+175,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_45_imag),32);
    bufp->fullIData(oldp+176,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_46_real),32);
    bufp->fullIData(oldp+177,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_46_imag),32);
    bufp->fullIData(oldp+178,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_47_real),32);
    bufp->fullIData(oldp+179,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_47_imag),32);
    bufp->fullIData(oldp+180,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_48_real),32);
    bufp->fullIData(oldp+181,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_48_imag),32);
    bufp->fullIData(oldp+182,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_49_real),32);
    bufp->fullIData(oldp+183,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_49_imag),32);
    bufp->fullIData(oldp+184,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_50_real),32);
    bufp->fullIData(oldp+185,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_50_imag),32);
    bufp->fullIData(oldp+186,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_51_real),32);
    bufp->fullIData(oldp+187,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_51_imag),32);
    bufp->fullIData(oldp+188,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_52_real),32);
    bufp->fullIData(oldp+189,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_52_imag),32);
    bufp->fullIData(oldp+190,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_53_real),32);
    bufp->fullIData(oldp+191,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_53_imag),32);
    bufp->fullIData(oldp+192,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_54_real),32);
    bufp->fullIData(oldp+193,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_54_imag),32);
    bufp->fullIData(oldp+194,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_55_real),32);
    bufp->fullIData(oldp+195,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_55_imag),32);
    bufp->fullIData(oldp+196,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_56_real),32);
    bufp->fullIData(oldp+197,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_56_imag),32);
    bufp->fullIData(oldp+198,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_57_real),32);
    bufp->fullIData(oldp+199,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_57_imag),32);
    bufp->fullIData(oldp+200,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_58_real),32);
    bufp->fullIData(oldp+201,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_58_imag),32);
    bufp->fullIData(oldp+202,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_59_real),32);
    bufp->fullIData(oldp+203,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_59_imag),32);
    bufp->fullIData(oldp+204,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_60_real),32);
    bufp->fullIData(oldp+205,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_60_imag),32);
    bufp->fullIData(oldp+206,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_61_real),32);
    bufp->fullIData(oldp+207,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_61_imag),32);
    bufp->fullIData(oldp+208,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_62_real),32);
    bufp->fullIData(oldp+209,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_62_imag),32);
    bufp->fullIData(oldp+210,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_real),32);
    bufp->fullIData(oldp+211,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_63_imag),32);
    bufp->fullIData(oldp+212,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_64_real),32);
    bufp->fullIData(oldp+213,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_64_imag),32);
    bufp->fullIData(oldp+214,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_65_real),32);
    bufp->fullIData(oldp+215,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_65_imag),32);
    bufp->fullIData(oldp+216,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_66_real),32);
    bufp->fullIData(oldp+217,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_66_imag),32);
    bufp->fullIData(oldp+218,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_67_real),32);
    bufp->fullIData(oldp+219,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_67_imag),32);
    bufp->fullIData(oldp+220,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_68_real),32);
    bufp->fullIData(oldp+221,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_68_imag),32);
    bufp->fullIData(oldp+222,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_69_real),32);
    bufp->fullIData(oldp+223,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_69_imag),32);
    bufp->fullIData(oldp+224,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_70_real),32);
    bufp->fullIData(oldp+225,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_70_imag),32);
    bufp->fullIData(oldp+226,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_71_real),32);
    bufp->fullIData(oldp+227,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_71_imag),32);
    bufp->fullIData(oldp+228,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_72_real),32);
    bufp->fullIData(oldp+229,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_72_imag),32);
    bufp->fullIData(oldp+230,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_73_real),32);
    bufp->fullIData(oldp+231,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_73_imag),32);
    bufp->fullIData(oldp+232,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_74_real),32);
    bufp->fullIData(oldp+233,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_74_imag),32);
    bufp->fullIData(oldp+234,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_75_real),32);
    bufp->fullIData(oldp+235,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_75_imag),32);
    bufp->fullIData(oldp+236,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_76_real),32);
    bufp->fullIData(oldp+237,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_76_imag),32);
    bufp->fullIData(oldp+238,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_77_real),32);
    bufp->fullIData(oldp+239,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_77_imag),32);
    bufp->fullIData(oldp+240,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_78_real),32);
    bufp->fullIData(oldp+241,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_78_imag),32);
    bufp->fullIData(oldp+242,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_79_real),32);
    bufp->fullIData(oldp+243,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_79_imag),32);
    bufp->fullIData(oldp+244,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_80_real),32);
    bufp->fullIData(oldp+245,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_80_imag),32);
    bufp->fullIData(oldp+246,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_81_real),32);
    bufp->fullIData(oldp+247,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_81_imag),32);
    bufp->fullIData(oldp+248,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_82_real),32);
    bufp->fullIData(oldp+249,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_82_imag),32);
    bufp->fullIData(oldp+250,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_83_real),32);
    bufp->fullIData(oldp+251,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_83_imag),32);
    bufp->fullIData(oldp+252,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_84_real),32);
    bufp->fullIData(oldp+253,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_84_imag),32);
    bufp->fullIData(oldp+254,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_85_real),32);
    bufp->fullIData(oldp+255,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_85_imag),32);
    bufp->fullIData(oldp+256,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_86_real),32);
    bufp->fullIData(oldp+257,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_86_imag),32);
    bufp->fullIData(oldp+258,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_87_real),32);
    bufp->fullIData(oldp+259,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_87_imag),32);
    bufp->fullIData(oldp+260,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_88_real),32);
    bufp->fullIData(oldp+261,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_88_imag),32);
    bufp->fullIData(oldp+262,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_89_real),32);
    bufp->fullIData(oldp+263,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_89_imag),32);
    bufp->fullIData(oldp+264,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_90_real),32);
    bufp->fullIData(oldp+265,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_90_imag),32);
    bufp->fullIData(oldp+266,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_91_real),32);
    bufp->fullIData(oldp+267,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_91_imag),32);
    bufp->fullIData(oldp+268,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_92_real),32);
    bufp->fullIData(oldp+269,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_92_imag),32);
    bufp->fullIData(oldp+270,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_93_real),32);
    bufp->fullIData(oldp+271,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_93_imag),32);
    bufp->fullIData(oldp+272,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_94_real),32);
    bufp->fullIData(oldp+273,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_94_imag),32);
    bufp->fullIData(oldp+274,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_real),32);
    bufp->fullIData(oldp+275,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_95_imag),32);
    bufp->fullIData(oldp+276,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_96_real),32);
    bufp->fullIData(oldp+277,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_96_imag),32);
    bufp->fullIData(oldp+278,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_97_real),32);
    bufp->fullIData(oldp+279,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_97_imag),32);
    bufp->fullIData(oldp+280,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_98_real),32);
    bufp->fullIData(oldp+281,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_98_imag),32);
    bufp->fullIData(oldp+282,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_99_real),32);
    bufp->fullIData(oldp+283,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_99_imag),32);
    bufp->fullIData(oldp+284,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_100_real),32);
    bufp->fullIData(oldp+285,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_100_imag),32);
    bufp->fullIData(oldp+286,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_101_real),32);
    bufp->fullIData(oldp+287,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_101_imag),32);
    bufp->fullIData(oldp+288,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_102_real),32);
    bufp->fullIData(oldp+289,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_102_imag),32);
    bufp->fullIData(oldp+290,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_103_real),32);
    bufp->fullIData(oldp+291,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_103_imag),32);
    bufp->fullIData(oldp+292,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_104_real),32);
    bufp->fullIData(oldp+293,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_104_imag),32);
    bufp->fullIData(oldp+294,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_105_real),32);
    bufp->fullIData(oldp+295,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_105_imag),32);
    bufp->fullIData(oldp+296,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_106_real),32);
    bufp->fullIData(oldp+297,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_106_imag),32);
    bufp->fullIData(oldp+298,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_107_real),32);
    bufp->fullIData(oldp+299,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_107_imag),32);
    bufp->fullIData(oldp+300,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_108_real),32);
    bufp->fullIData(oldp+301,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_108_imag),32);
    bufp->fullIData(oldp+302,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_109_real),32);
    bufp->fullIData(oldp+303,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_109_imag),32);
    bufp->fullIData(oldp+304,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_110_real),32);
    bufp->fullIData(oldp+305,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_110_imag),32);
    bufp->fullIData(oldp+306,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_111_real),32);
    bufp->fullIData(oldp+307,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_111_imag),32);
    bufp->fullIData(oldp+308,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_112_real),32);
    bufp->fullIData(oldp+309,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_112_imag),32);
    bufp->fullIData(oldp+310,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_113_real),32);
    bufp->fullIData(oldp+311,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_113_imag),32);
    bufp->fullIData(oldp+312,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_114_real),32);
    bufp->fullIData(oldp+313,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_114_imag),32);
    bufp->fullIData(oldp+314,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_115_real),32);
    bufp->fullIData(oldp+315,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_115_imag),32);
    bufp->fullIData(oldp+316,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_116_real),32);
    bufp->fullIData(oldp+317,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_116_imag),32);
    bufp->fullIData(oldp+318,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_117_real),32);
    bufp->fullIData(oldp+319,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_117_imag),32);
    bufp->fullIData(oldp+320,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_118_real),32);
    bufp->fullIData(oldp+321,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_118_imag),32);
    bufp->fullIData(oldp+322,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_119_real),32);
    bufp->fullIData(oldp+323,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_119_imag),32);
    bufp->fullIData(oldp+324,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_120_real),32);
    bufp->fullIData(oldp+325,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_120_imag),32);
    bufp->fullIData(oldp+326,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_121_real),32);
    bufp->fullIData(oldp+327,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_121_imag),32);
    bufp->fullIData(oldp+328,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_122_real),32);
    bufp->fullIData(oldp+329,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_122_imag),32);
    bufp->fullIData(oldp+330,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_123_real),32);
    bufp->fullIData(oldp+331,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_123_imag),32);
    bufp->fullIData(oldp+332,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_124_real),32);
    bufp->fullIData(oldp+333,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_124_imag),32);
    bufp->fullIData(oldp+334,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_125_real),32);
    bufp->fullIData(oldp+335,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_125_imag),32);
    bufp->fullIData(oldp+336,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_126_real),32);
    bufp->fullIData(oldp+337,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_126_imag),32);
    bufp->fullIData(oldp+338,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_real),32);
    bufp->fullIData(oldp+339,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_127_imag),32);
    bufp->fullIData(oldp+340,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_128_real),32);
    bufp->fullIData(oldp+341,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_128_imag),32);
    bufp->fullIData(oldp+342,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_129_real),32);
    bufp->fullIData(oldp+343,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_129_imag),32);
    bufp->fullIData(oldp+344,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_130_real),32);
    bufp->fullIData(oldp+345,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_130_imag),32);
    bufp->fullIData(oldp+346,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_131_real),32);
    bufp->fullIData(oldp+347,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_131_imag),32);
    bufp->fullIData(oldp+348,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_132_real),32);
    bufp->fullIData(oldp+349,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_132_imag),32);
    bufp->fullIData(oldp+350,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_133_real),32);
    bufp->fullIData(oldp+351,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_133_imag),32);
    bufp->fullIData(oldp+352,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_134_real),32);
    bufp->fullIData(oldp+353,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_134_imag),32);
    bufp->fullIData(oldp+354,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_135_real),32);
    bufp->fullIData(oldp+355,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_135_imag),32);
    bufp->fullIData(oldp+356,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_136_real),32);
    bufp->fullIData(oldp+357,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_136_imag),32);
    bufp->fullIData(oldp+358,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_137_real),32);
    bufp->fullIData(oldp+359,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_137_imag),32);
    bufp->fullIData(oldp+360,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_138_real),32);
    bufp->fullIData(oldp+361,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_138_imag),32);
    bufp->fullIData(oldp+362,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_139_real),32);
    bufp->fullIData(oldp+363,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_139_imag),32);
    bufp->fullIData(oldp+364,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_140_real),32);
    bufp->fullIData(oldp+365,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_140_imag),32);
    bufp->fullIData(oldp+366,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_141_real),32);
    bufp->fullIData(oldp+367,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_141_imag),32);
    bufp->fullIData(oldp+368,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_142_real),32);
    bufp->fullIData(oldp+369,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_142_imag),32);
    bufp->fullIData(oldp+370,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_real),32);
    bufp->fullIData(oldp+371,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_143_imag),32);
    bufp->fullIData(oldp+372,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_144_real),32);
    bufp->fullIData(oldp+373,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_144_imag),32);
    bufp->fullIData(oldp+374,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_145_real),32);
    bufp->fullIData(oldp+375,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_145_imag),32);
    bufp->fullIData(oldp+376,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_146_real),32);
    bufp->fullIData(oldp+377,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_146_imag),32);
    bufp->fullIData(oldp+378,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_147_real),32);
    bufp->fullIData(oldp+379,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_147_imag),32);
    bufp->fullIData(oldp+380,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_148_real),32);
    bufp->fullIData(oldp+381,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_148_imag),32);
    bufp->fullIData(oldp+382,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_149_real),32);
    bufp->fullIData(oldp+383,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_149_imag),32);
    bufp->fullIData(oldp+384,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_150_real),32);
    bufp->fullIData(oldp+385,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_150_imag),32);
    bufp->fullIData(oldp+386,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_151_real),32);
    bufp->fullIData(oldp+387,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_151_imag),32);
    bufp->fullIData(oldp+388,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_152_real),32);
    bufp->fullIData(oldp+389,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_152_imag),32);
    bufp->fullIData(oldp+390,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_153_real),32);
    bufp->fullIData(oldp+391,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_153_imag),32);
    bufp->fullIData(oldp+392,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_154_real),32);
    bufp->fullIData(oldp+393,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_154_imag),32);
    bufp->fullIData(oldp+394,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_155_real),32);
    bufp->fullIData(oldp+395,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_155_imag),32);
    bufp->fullIData(oldp+396,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_156_real),32);
    bufp->fullIData(oldp+397,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_156_imag),32);
    bufp->fullIData(oldp+398,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_157_real),32);
    bufp->fullIData(oldp+399,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_157_imag),32);
    bufp->fullIData(oldp+400,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_158_real),32);
    bufp->fullIData(oldp+401,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_158_imag),32);
    bufp->fullIData(oldp+402,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_real),32);
    bufp->fullIData(oldp+403,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_159_imag),32);
    bufp->fullIData(oldp+404,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_160_real),32);
    bufp->fullIData(oldp+405,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_160_imag),32);
    bufp->fullIData(oldp+406,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_161_real),32);
    bufp->fullIData(oldp+407,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_161_imag),32);
    bufp->fullIData(oldp+408,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_162_real),32);
    bufp->fullIData(oldp+409,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_162_imag),32);
    bufp->fullIData(oldp+410,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_163_real),32);
    bufp->fullIData(oldp+411,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_163_imag),32);
    bufp->fullIData(oldp+412,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_164_real),32);
    bufp->fullIData(oldp+413,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_164_imag),32);
    bufp->fullIData(oldp+414,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_165_real),32);
    bufp->fullIData(oldp+415,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_165_imag),32);
    bufp->fullIData(oldp+416,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_166_real),32);
    bufp->fullIData(oldp+417,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_166_imag),32);
    bufp->fullIData(oldp+418,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_real),32);
    bufp->fullIData(oldp+419,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_167_imag),32);
    bufp->fullIData(oldp+420,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_168_real),32);
    bufp->fullIData(oldp+421,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_168_imag),32);
    bufp->fullIData(oldp+422,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_169_real),32);
    bufp->fullIData(oldp+423,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_169_imag),32);
    bufp->fullIData(oldp+424,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_170_real),32);
    bufp->fullIData(oldp+425,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_170_imag),32);
    bufp->fullIData(oldp+426,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_171_real),32);
    bufp->fullIData(oldp+427,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_171_imag),32);
    bufp->fullIData(oldp+428,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_172_real),32);
    bufp->fullIData(oldp+429,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_172_imag),32);
    bufp->fullIData(oldp+430,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_173_real),32);
    bufp->fullIData(oldp+431,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_173_imag),32);
    bufp->fullIData(oldp+432,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_174_real),32);
    bufp->fullIData(oldp+433,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_174_imag),32);
    bufp->fullIData(oldp+434,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_real),32);
    bufp->fullIData(oldp+435,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_175_imag),32);
    bufp->fullIData(oldp+436,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_176_real),32);
    bufp->fullIData(oldp+437,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_176_imag),32);
    bufp->fullIData(oldp+438,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_177_real),32);
    bufp->fullIData(oldp+439,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_177_imag),32);
    bufp->fullIData(oldp+440,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_178_real),32);
    bufp->fullIData(oldp+441,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_178_imag),32);
    bufp->fullIData(oldp+442,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_real),32);
    bufp->fullIData(oldp+443,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_179_imag),32);
    bufp->fullIData(oldp+444,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_180_real),32);
    bufp->fullIData(oldp+445,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_180_imag),32);
    bufp->fullIData(oldp+446,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_181_real),32);
    bufp->fullIData(oldp+447,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_181_imag),32);
    bufp->fullIData(oldp+448,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_182_real),32);
    bufp->fullIData(oldp+449,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_182_imag),32);
    bufp->fullIData(oldp+450,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_real),32);
    bufp->fullIData(oldp+451,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_183_imag),32);
    bufp->fullIData(oldp+452,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_184_real),32);
    bufp->fullIData(oldp+453,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_184_imag),32);
    bufp->fullIData(oldp+454,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_real),32);
    bufp->fullIData(oldp+455,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_185_imag),32);
    bufp->fullIData(oldp+456,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_186_real),32);
    bufp->fullIData(oldp+457,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_186_imag),32);
    bufp->fullIData(oldp+458,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_real),32);
    bufp->fullIData(oldp+459,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_187_imag),32);
    bufp->fullIData(oldp+460,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_real),32);
    bufp->fullIData(oldp+461,(vlSelfRef.FFT128_tb__DOT__uut__DOT__r_188_imag),32);
    bufp->fullIData(oldp+462,(vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_real),32);
    bufp->fullIData(oldp+463,(vlSelfRef.FFT128_tb__DOT__uut__DOT__out1_imag),32);
    bufp->fullBit(oldp+464,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r));
    bufp->fullBit(oldp+465,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_1));
    bufp->fullBit(oldp+466,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_2));
    bufp->fullBit(oldp+467,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_3));
    bufp->fullBit(oldp+468,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_4));
    bufp->fullBit(oldp+469,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_5));
    bufp->fullBit(oldp+470,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_6));
    bufp->fullBit(oldp+471,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_7));
    bufp->fullBit(oldp+472,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_8));
    bufp->fullBit(oldp+473,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_9));
    bufp->fullBit(oldp+474,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_10));
    bufp->fullBit(oldp+475,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_11));
    bufp->fullBit(oldp+476,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_12));
    bufp->fullBit(oldp+477,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_13));
    bufp->fullBit(oldp+478,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_14));
    bufp->fullBit(oldp+479,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_15));
    bufp->fullBit(oldp+480,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_16));
    bufp->fullBit(oldp+481,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_17));
    bufp->fullBit(oldp+482,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_18));
    bufp->fullBit(oldp+483,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_19));
    bufp->fullBit(oldp+484,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_20));
    bufp->fullBit(oldp+485,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_21));
    bufp->fullBit(oldp+486,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_22));
    bufp->fullBit(oldp+487,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_23));
    bufp->fullBit(oldp+488,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_24));
    bufp->fullBit(oldp+489,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_25));
    bufp->fullBit(oldp+490,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_26));
    bufp->fullBit(oldp+491,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_27));
    bufp->fullBit(oldp+492,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_28));
    bufp->fullBit(oldp+493,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_29));
    bufp->fullBit(oldp+494,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_30));
    bufp->fullBit(oldp+495,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_31));
    bufp->fullBit(oldp+496,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_32));
    bufp->fullBit(oldp+497,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_33));
    bufp->fullBit(oldp+498,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_34));
    bufp->fullBit(oldp+499,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_35));
    bufp->fullBit(oldp+500,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_36));
    bufp->fullBit(oldp+501,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_37));
    bufp->fullBit(oldp+502,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_38));
    bufp->fullBit(oldp+503,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_39));
    bufp->fullBit(oldp+504,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_40));
    bufp->fullBit(oldp+505,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_41));
    bufp->fullBit(oldp+506,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_42));
    bufp->fullBit(oldp+507,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_43));
    bufp->fullBit(oldp+508,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_44));
    bufp->fullBit(oldp+509,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_45));
    bufp->fullBit(oldp+510,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_46));
    bufp->fullBit(oldp+511,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_47));
    bufp->fullBit(oldp+512,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_48));
    bufp->fullBit(oldp+513,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_49));
    bufp->fullBit(oldp+514,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_50));
    bufp->fullBit(oldp+515,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_51));
    bufp->fullBit(oldp+516,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_52));
    bufp->fullBit(oldp+517,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_53));
    bufp->fullBit(oldp+518,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_54));
    bufp->fullBit(oldp+519,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_55));
    bufp->fullBit(oldp+520,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_56));
    bufp->fullBit(oldp+521,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_57));
    bufp->fullBit(oldp+522,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_58));
    bufp->fullBit(oldp+523,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_59));
    bufp->fullBit(oldp+524,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_60));
    bufp->fullBit(oldp+525,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_61));
    bufp->fullBit(oldp+526,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_62));
    bufp->fullBit(oldp+527,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_63));
    bufp->fullBit(oldp+528,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_64));
    bufp->fullBit(oldp+529,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_65));
    bufp->fullBit(oldp+530,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_66));
    bufp->fullBit(oldp+531,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_67));
    bufp->fullBit(oldp+532,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_68));
    bufp->fullBit(oldp+533,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_69));
    bufp->fullBit(oldp+534,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_70));
    bufp->fullBit(oldp+535,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_71));
    bufp->fullBit(oldp+536,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_72));
    bufp->fullBit(oldp+537,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_73));
    bufp->fullBit(oldp+538,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_74));
    bufp->fullBit(oldp+539,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_75));
    bufp->fullBit(oldp+540,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_76));
    bufp->fullBit(oldp+541,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_77));
    bufp->fullBit(oldp+542,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_78));
    bufp->fullBit(oldp+543,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_79));
    bufp->fullBit(oldp+544,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_80));
    bufp->fullBit(oldp+545,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_81));
    bufp->fullBit(oldp+546,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_82));
    bufp->fullBit(oldp+547,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_83));
    bufp->fullBit(oldp+548,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_84));
    bufp->fullBit(oldp+549,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_85));
    bufp->fullBit(oldp+550,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_86));
    bufp->fullBit(oldp+551,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_87));
    bufp->fullBit(oldp+552,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_88));
    bufp->fullBit(oldp+553,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_89));
    bufp->fullBit(oldp+554,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_90));
    bufp->fullBit(oldp+555,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_91));
    bufp->fullBit(oldp+556,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_92));
    bufp->fullBit(oldp+557,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_93));
    bufp->fullBit(oldp+558,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_94));
    bufp->fullBit(oldp+559,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_95));
    bufp->fullBit(oldp+560,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_96));
    bufp->fullBit(oldp+561,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_97));
    bufp->fullBit(oldp+562,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_98));
    bufp->fullBit(oldp+563,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_99));
    bufp->fullBit(oldp+564,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_100));
    bufp->fullBit(oldp+565,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_101));
    bufp->fullBit(oldp+566,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_102));
    bufp->fullBit(oldp+567,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_103));
    bufp->fullBit(oldp+568,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_104));
    bufp->fullBit(oldp+569,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_105));
    bufp->fullBit(oldp+570,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_106));
    bufp->fullBit(oldp+571,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_107));
    bufp->fullBit(oldp+572,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_108));
    bufp->fullBit(oldp+573,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_109));
    bufp->fullBit(oldp+574,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_110));
    bufp->fullBit(oldp+575,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_111));
    bufp->fullBit(oldp+576,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_112));
    bufp->fullBit(oldp+577,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_113));
    bufp->fullBit(oldp+578,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_114));
    bufp->fullBit(oldp+579,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_115));
    bufp->fullBit(oldp+580,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_116));
    bufp->fullBit(oldp+581,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_117));
    bufp->fullBit(oldp+582,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_118));
    bufp->fullBit(oldp+583,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_119));
    bufp->fullBit(oldp+584,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_120));
    bufp->fullBit(oldp+585,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_121));
    bufp->fullBit(oldp+586,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_122));
    bufp->fullBit(oldp+587,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_123));
    bufp->fullBit(oldp+588,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_124));
    bufp->fullBit(oldp+589,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_125));
    bufp->fullBit(oldp+590,(vlSelfRef.FFT128_tb__DOT__uut__DOT__io_out_valid_r_126));
    bufp->fullBit(oldp+591,((1U & ((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt) 
                                   >> 5U))));
    bufp->fullBit(oldp+592,((1U & ((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt) 
                                   >> 4U))));
    bufp->fullBit(oldp+593,((1U & ((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt) 
                                   >> 3U))));
    bufp->fullBit(oldp+594,((1U & ((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt) 
                                   >> 2U))));
    bufp->fullBit(oldp+595,((1U & ((IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt) 
                                   >> 1U))));
    bufp->fullBit(oldp+596,((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))));
    bufp->fullIData(oldp+597,((((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                 ? 0U : (Vfft128__ConstPool__CONST_h8abd5580_0[
                                         (((IData)(0x1fU) 
                                           + (0x7ffU 
                                              & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(11,11,32, 
                                                             (0x3fU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                               | (Vfft128__ConstPool__CONST_h8abd5580_0[
                                  (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                            >> 5U))] 
                                  >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+598,((((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                 ? 0U : (Vfft128__ConstPool__CONST_h16a5c00c_0[
                                         (((IData)(0x1fU) 
                                           + (0x7ffU 
                                              & VL_SHIFTL_III(11,11,32, 
                                                              (0x3fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(11,11,32, 
                                                             (0x3fU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                               | (Vfft128__ConstPool__CONST_h16a5c00c_0[
                                  (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                            >> 5U))] 
                                  >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                            (0x3fU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+599,((((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                 ? 0U : (Vfft128__ConstPool__CONST_hb3c963b9_0[
                                         (((IData)(0x1fU) 
                                           + (0x3ffU 
                                              & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(10,10,32, 
                                                             (0x1fU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                               | (Vfft128__ConstPool__CONST_hb3c963b9_0[
                                  (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                            >> 5U))] 
                                  >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+600,((((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                 ? 0U : (Vfft128__ConstPool__CONST_hffb3c89b_0[
                                         (((IData)(0x1fU) 
                                           + (0x3ffU 
                                              & VL_SHIFTL_III(10,10,32, 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(10,10,32, 
                                                             (0x1fU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                               | (Vfft128__ConstPool__CONST_hffb3c89b_0[
                                  (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                            >> 5U))] 
                                  >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+601,((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                 ? 0U : (Vfft128__ConstPool__CONST_h942db0a5_0[
                                         (((IData)(0x1fU) 
                                           + (0x1ffU 
                                              & VL_SHIFTL_III(9,9,32, 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                               | (Vfft128__ConstPool__CONST_h942db0a5_0[
                                  (0xfU & (VL_SHIFTL_III(9,9,32, 
                                                         (0xfU 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                           >> 5U))] 
                                  >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+602,((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                 ? 0U : (Vfft128__ConstPool__CONST_ha2844606_0[
                                         (((IData)(0x1fU) 
                                           + (0x1ffU 
                                              & VL_SHIFTL_III(9,9,32, 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                               | (Vfft128__ConstPool__CONST_ha2844606_0[
                                  (0xfU & (VL_SHIFTL_III(9,9,32, 
                                                         (0xfU 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                           >> 5U))] 
                                  >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+603,((((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                              (7U 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                 ? 0U : (Vfft128__ConstPool__CONST_hfd15effc_0[
                                         (((IData)(0x1fU) 
                                           + (0xffU 
                                              & VL_SHIFTL_III(8,8,32, 
                                                              (7U 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(8,8,32, 
                                                             (7U 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                               | (Vfft128__ConstPool__CONST_hfd15effc_0[
                                  (7U & (VL_SHIFTL_III(8,8,32, 
                                                       (7U 
                                                        & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                         >> 5U))] >> 
                                  (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                         (7U 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+604,((((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                              (7U 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                 ? 0U : (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                                         (((IData)(0x1fU) 
                                           + (0xffU 
                                              & VL_SHIFTL_III(8,8,32, 
                                                              (7U 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(8,8,32, 
                                                             (7U 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                               | (Vfft128__ConstPool__CONST_h5ba1edbd_0[
                                  (7U & (VL_SHIFTL_III(8,8,32, 
                                                       (7U 
                                                        & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                         >> 5U))] >> 
                                  (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                         (7U 
                                                          & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    __Vtemp_1[0U] = 0x100000U;
    __Vtemp_1[1U] = 0xb504fU;
    __Vtemp_1[2U] = 0U;
    __Vtemp_1[3U] = 0xfff4afb1U;
    bufp->fullIData(oldp+605,((((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                              (3U 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                 ? 0U : (__Vtemp_1[
                                         (((IData)(0x1fU) 
                                           + (0x7fU 
                                              & VL_SHIFTL_III(7,7,32, 
                                                              (3U 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                               | (__Vtemp_1[(3U & (
                                                   VL_SHIFTL_III(7,7,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                   >> 5U))] 
                                  >> (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                            (3U 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    __Vtemp_2[0U] = 0U;
    __Vtemp_2[1U] = 0xfff4afb1U;
    __Vtemp_2[2U] = 0xfff00000U;
    __Vtemp_2[3U] = 0xfff4afb1U;
    bufp->fullIData(oldp+606,((((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                              (3U 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U)))
                                 ? 0U : (__Vtemp_2[
                                         (((IData)(0x1fU) 
                                           + (0x7fU 
                                              & VL_SHIFTL_III(7,7,32, 
                                                              (3U 
                                                               & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))) 
                               | (__Vtemp_2[(3U & (
                                                   VL_SHIFTL_III(7,7,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U) 
                                                   >> 5U))] 
                                  >> (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                            (3U 
                                                             & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+607,((0x100000U & ((~ (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt)) 
                                            << 0x14U))),32);
    bufp->fullIData(oldp+608,(((1U & (IData)(vlSelfRef.FFT128_tb__DOT__uut__DOT__cnt))
                                ? 0xfff00000U : 0U)),32);
    bufp->fullBit(oldp+609,(vlSelfRef.FFT128_tb__DOT__clock));
}
