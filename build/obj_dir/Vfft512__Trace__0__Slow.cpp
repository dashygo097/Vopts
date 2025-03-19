// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfft512__Syms.h"


VL_ATTR_COLD void Vfft512___024root__trace_init_sub__TOP__0(Vfft512___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root__trace_init_sub__TOP__0\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("FFT512_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1648,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"io_in_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"io_in_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"io_in_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"io_out1_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"io_out1_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"io_out2_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"io_out2_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+90,0,"io_out_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+5,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1648,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"io_in_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"io_in_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"io_in_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+90,0,"io_out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+92,0,"r_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"r_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"r_1_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"r_1_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"r_2_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"r_2_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"r_3_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"r_3_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"r_4_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"r_4_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"r_5_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"r_5_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"r_6_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+105,0,"r_6_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"r_7_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"r_7_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"r_8_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"r_8_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"r_9_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"r_9_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"r_10_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"r_10_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"r_11_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"r_11_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"r_12_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"r_12_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"r_13_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"r_13_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+120,0,"r_14_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"r_14_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"r_15_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"r_15_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+124,0,"r_16_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+125,0,"r_16_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"r_17_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"r_17_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"r_18_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+129,0,"r_18_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"r_19_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"r_19_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+132,0,"r_20_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+133,0,"r_20_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"r_21_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"r_21_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"r_22_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"r_22_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"r_23_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"r_23_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"r_24_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"r_24_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+142,0,"r_25_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+143,0,"r_25_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+144,0,"r_26_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"r_26_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"r_27_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"r_27_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+148,0,"r_28_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+149,0,"r_28_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"r_29_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"r_29_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"r_30_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"r_30_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+154,0,"r_31_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+155,0,"r_31_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+156,0,"r_32_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+157,0,"r_32_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+158,0,"r_33_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+159,0,"r_33_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"r_34_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"r_34_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"r_35_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"r_35_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+164,0,"r_36_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"r_36_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"r_37_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"r_37_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"r_38_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"r_38_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"r_39_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"r_39_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"r_40_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"r_40_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"r_41_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"r_41_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"r_42_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"r_42_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"r_43_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"r_43_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"r_44_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+181,0,"r_44_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+182,0,"r_45_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"r_45_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"r_46_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"r_46_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+186,0,"r_47_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"r_47_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+188,0,"r_48_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"r_48_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+190,0,"r_49_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"r_49_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+192,0,"r_50_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+193,0,"r_50_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+194,0,"r_51_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+195,0,"r_51_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+196,0,"r_52_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"r_52_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+198,0,"r_53_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"r_53_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+200,0,"r_54_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+201,0,"r_54_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+202,0,"r_55_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+203,0,"r_55_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"r_56_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+205,0,"r_56_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+206,0,"r_57_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"r_57_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"r_58_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+209,0,"r_58_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"r_59_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"r_59_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"r_60_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+213,0,"r_60_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+214,0,"r_61_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+215,0,"r_61_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+216,0,"r_62_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+217,0,"r_62_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+218,0,"r_63_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+219,0,"r_63_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+220,0,"r_64_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+221,0,"r_64_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+222,0,"r_65_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+223,0,"r_65_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+224,0,"r_66_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+225,0,"r_66_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+226,0,"r_67_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+227,0,"r_67_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+228,0,"r_68_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+229,0,"r_68_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"r_69_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+231,0,"r_69_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+232,0,"r_70_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+233,0,"r_70_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"r_71_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+235,0,"r_71_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+236,0,"r_72_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+237,0,"r_72_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"r_73_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+239,0,"r_73_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+240,0,"r_74_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+241,0,"r_74_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"r_75_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+243,0,"r_75_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+244,0,"r_76_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+245,0,"r_76_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+246,0,"r_77_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+247,0,"r_77_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+248,0,"r_78_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+249,0,"r_78_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+250,0,"r_79_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+251,0,"r_79_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"r_80_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+253,0,"r_80_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"r_81_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+255,0,"r_81_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+256,0,"r_82_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+257,0,"r_82_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+258,0,"r_83_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+259,0,"r_83_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+260,0,"r_84_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+261,0,"r_84_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+262,0,"r_85_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+263,0,"r_85_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+264,0,"r_86_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+265,0,"r_86_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+266,0,"r_87_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+267,0,"r_87_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"r_88_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"r_88_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+270,0,"r_89_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+271,0,"r_89_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+272,0,"r_90_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"r_90_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"r_91_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"r_91_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"r_92_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+277,0,"r_92_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+278,0,"r_93_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+279,0,"r_93_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+280,0,"r_94_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+281,0,"r_94_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+282,0,"r_95_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+283,0,"r_95_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+284,0,"r_96_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+285,0,"r_96_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+286,0,"r_97_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+287,0,"r_97_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+288,0,"r_98_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+289,0,"r_98_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+290,0,"r_99_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+291,0,"r_99_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+292,0,"r_100_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+293,0,"r_100_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+294,0,"r_101_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+295,0,"r_101_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+296,0,"r_102_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+297,0,"r_102_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+298,0,"r_103_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+299,0,"r_103_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+300,0,"r_104_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+301,0,"r_104_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+302,0,"r_105_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"r_105_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+304,0,"r_106_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+305,0,"r_106_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+306,0,"r_107_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+307,0,"r_107_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+308,0,"r_108_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+309,0,"r_108_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+310,0,"r_109_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+311,0,"r_109_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+312,0,"r_110_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+313,0,"r_110_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+314,0,"r_111_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+315,0,"r_111_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+316,0,"r_112_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+317,0,"r_112_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+318,0,"r_113_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+319,0,"r_113_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+320,0,"r_114_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+321,0,"r_114_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+322,0,"r_115_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+323,0,"r_115_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+324,0,"r_116_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+325,0,"r_116_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+326,0,"r_117_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+327,0,"r_117_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+328,0,"r_118_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+329,0,"r_118_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+330,0,"r_119_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+331,0,"r_119_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+332,0,"r_120_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+333,0,"r_120_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+334,0,"r_121_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+335,0,"r_121_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+336,0,"r_122_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+337,0,"r_122_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+338,0,"r_123_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+339,0,"r_123_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+340,0,"r_124_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+341,0,"r_124_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+342,0,"r_125_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+343,0,"r_125_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+344,0,"r_126_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+345,0,"r_126_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+346,0,"r_127_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+347,0,"r_127_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+348,0,"r_128_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+349,0,"r_128_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+350,0,"r_129_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+351,0,"r_129_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+352,0,"r_130_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+353,0,"r_130_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+354,0,"r_131_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+355,0,"r_131_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+356,0,"r_132_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+357,0,"r_132_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+358,0,"r_133_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+359,0,"r_133_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+360,0,"r_134_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+361,0,"r_134_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+362,0,"r_135_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+363,0,"r_135_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+364,0,"r_136_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+365,0,"r_136_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+366,0,"r_137_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+367,0,"r_137_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+368,0,"r_138_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+369,0,"r_138_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+370,0,"r_139_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+371,0,"r_139_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+372,0,"r_140_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+373,0,"r_140_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+374,0,"r_141_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+375,0,"r_141_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+376,0,"r_142_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+377,0,"r_142_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+378,0,"r_143_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+379,0,"r_143_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+380,0,"r_144_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+381,0,"r_144_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+382,0,"r_145_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+383,0,"r_145_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+384,0,"r_146_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+385,0,"r_146_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+386,0,"r_147_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+387,0,"r_147_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+388,0,"r_148_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+389,0,"r_148_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+390,0,"r_149_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+391,0,"r_149_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+392,0,"r_150_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+393,0,"r_150_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+394,0,"r_151_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+395,0,"r_151_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+396,0,"r_152_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+397,0,"r_152_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+398,0,"r_153_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+399,0,"r_153_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+400,0,"r_154_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+401,0,"r_154_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+402,0,"r_155_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+403,0,"r_155_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+404,0,"r_156_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+405,0,"r_156_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+406,0,"r_157_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+407,0,"r_157_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+408,0,"r_158_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+409,0,"r_158_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+410,0,"r_159_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+411,0,"r_159_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+412,0,"r_160_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+413,0,"r_160_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+414,0,"r_161_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+415,0,"r_161_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+416,0,"r_162_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+417,0,"r_162_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+418,0,"r_163_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+419,0,"r_163_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+420,0,"r_164_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+421,0,"r_164_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+422,0,"r_165_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+423,0,"r_165_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+424,0,"r_166_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+425,0,"r_166_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+426,0,"r_167_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+427,0,"r_167_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+428,0,"r_168_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+429,0,"r_168_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+430,0,"r_169_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+431,0,"r_169_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+432,0,"r_170_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+433,0,"r_170_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+434,0,"r_171_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+435,0,"r_171_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+436,0,"r_172_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+437,0,"r_172_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+438,0,"r_173_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+439,0,"r_173_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+440,0,"r_174_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+441,0,"r_174_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+442,0,"r_175_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+443,0,"r_175_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+444,0,"r_176_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+445,0,"r_176_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+446,0,"r_177_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+447,0,"r_177_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+448,0,"r_178_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+449,0,"r_178_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+450,0,"r_179_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+451,0,"r_179_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+452,0,"r_180_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+453,0,"r_180_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+454,0,"r_181_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+455,0,"r_181_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+456,0,"r_182_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+457,0,"r_182_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+458,0,"r_183_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+459,0,"r_183_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+460,0,"r_184_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+461,0,"r_184_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+462,0,"r_185_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+463,0,"r_185_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+464,0,"r_186_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+465,0,"r_186_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+466,0,"r_187_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+467,0,"r_187_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+468,0,"r_188_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+469,0,"r_188_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+470,0,"r_189_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+471,0,"r_189_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+472,0,"r_190_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+473,0,"r_190_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+474,0,"r_191_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+475,0,"r_191_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+476,0,"r_192_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+477,0,"r_192_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+478,0,"r_193_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+479,0,"r_193_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+480,0,"r_194_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+481,0,"r_194_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+482,0,"r_195_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+483,0,"r_195_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+484,0,"r_196_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+485,0,"r_196_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+486,0,"r_197_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+487,0,"r_197_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+488,0,"r_198_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+489,0,"r_198_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+490,0,"r_199_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+491,0,"r_199_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+492,0,"r_200_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+493,0,"r_200_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+494,0,"r_201_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+495,0,"r_201_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+496,0,"r_202_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+497,0,"r_202_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+498,0,"r_203_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+499,0,"r_203_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+500,0,"r_204_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+501,0,"r_204_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+502,0,"r_205_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+503,0,"r_205_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+504,0,"r_206_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+505,0,"r_206_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+506,0,"r_207_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+507,0,"r_207_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+508,0,"r_208_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+509,0,"r_208_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+510,0,"r_209_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+511,0,"r_209_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+512,0,"r_210_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+513,0,"r_210_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+514,0,"r_211_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+515,0,"r_211_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+516,0,"r_212_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+517,0,"r_212_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+518,0,"r_213_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+519,0,"r_213_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+520,0,"r_214_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+521,0,"r_214_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+522,0,"r_215_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+523,0,"r_215_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+524,0,"r_216_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+525,0,"r_216_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+526,0,"r_217_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+527,0,"r_217_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+528,0,"r_218_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+529,0,"r_218_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+530,0,"r_219_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+531,0,"r_219_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+532,0,"r_220_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+533,0,"r_220_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+534,0,"r_221_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+535,0,"r_221_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+536,0,"r_222_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+537,0,"r_222_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+538,0,"r_223_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+539,0,"r_223_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+540,0,"r_224_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+541,0,"r_224_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+542,0,"r_225_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+543,0,"r_225_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+544,0,"r_226_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+545,0,"r_226_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+546,0,"r_227_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+547,0,"r_227_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+548,0,"r_228_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+549,0,"r_228_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+550,0,"r_229_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+551,0,"r_229_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+552,0,"r_230_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+553,0,"r_230_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+554,0,"r_231_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+555,0,"r_231_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+556,0,"r_232_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+557,0,"r_232_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+558,0,"r_233_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+559,0,"r_233_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+560,0,"r_234_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+561,0,"r_234_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+562,0,"r_235_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+563,0,"r_235_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+564,0,"r_236_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+565,0,"r_236_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+566,0,"r_237_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+567,0,"r_237_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+568,0,"r_238_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+569,0,"r_238_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+570,0,"r_239_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+571,0,"r_239_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+572,0,"r_240_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+573,0,"r_240_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+574,0,"r_241_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+575,0,"r_241_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+576,0,"r_242_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+577,0,"r_242_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+578,0,"r_243_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+579,0,"r_243_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+580,0,"r_244_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+581,0,"r_244_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+582,0,"r_245_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+583,0,"r_245_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+584,0,"r_246_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+585,0,"r_246_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+586,0,"r_247_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+587,0,"r_247_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+588,0,"r_248_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+589,0,"r_248_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+590,0,"r_249_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+591,0,"r_249_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+592,0,"r_250_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+593,0,"r_250_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+594,0,"r_251_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+595,0,"r_251_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+596,0,"r_252_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+597,0,"r_252_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+598,0,"r_253_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+599,0,"r_253_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+600,0,"r_254_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+601,0,"r_254_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+602,0,"r_255_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+603,0,"r_255_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+604,0,"r_256_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+605,0,"r_256_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+606,0,"r_257_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+607,0,"r_257_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+608,0,"r_258_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+609,0,"r_258_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+610,0,"r_259_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+611,0,"r_259_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+612,0,"r_260_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+613,0,"r_260_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+614,0,"r_261_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+615,0,"r_261_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+616,0,"r_262_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+617,0,"r_262_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+618,0,"r_263_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+619,0,"r_263_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+620,0,"r_264_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+621,0,"r_264_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+622,0,"r_265_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+623,0,"r_265_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+624,0,"r_266_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+625,0,"r_266_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+626,0,"r_267_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+627,0,"r_267_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+628,0,"r_268_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+629,0,"r_268_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+630,0,"r_269_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+631,0,"r_269_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+632,0,"r_270_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+633,0,"r_270_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+634,0,"r_271_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+635,0,"r_271_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+636,0,"r_272_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+637,0,"r_272_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+638,0,"r_273_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+639,0,"r_273_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+640,0,"r_274_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+641,0,"r_274_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+642,0,"r_275_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+643,0,"r_275_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+644,0,"r_276_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+645,0,"r_276_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+646,0,"r_277_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+647,0,"r_277_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+648,0,"r_278_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+649,0,"r_278_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+650,0,"r_279_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+651,0,"r_279_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+652,0,"r_280_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+653,0,"r_280_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+654,0,"r_281_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+655,0,"r_281_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+656,0,"r_282_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+657,0,"r_282_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+658,0,"r_283_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+659,0,"r_283_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+660,0,"r_284_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+661,0,"r_284_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+662,0,"r_285_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+663,0,"r_285_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+664,0,"r_286_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+665,0,"r_286_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+666,0,"r_287_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+667,0,"r_287_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+668,0,"r_288_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+669,0,"r_288_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+670,0,"r_289_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+671,0,"r_289_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+672,0,"r_290_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+673,0,"r_290_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+674,0,"r_291_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+675,0,"r_291_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+676,0,"r_292_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+677,0,"r_292_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+678,0,"r_293_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+679,0,"r_293_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+680,0,"r_294_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+681,0,"r_294_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+682,0,"r_295_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+683,0,"r_295_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+684,0,"r_296_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+685,0,"r_296_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+686,0,"r_297_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+687,0,"r_297_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+688,0,"r_298_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+689,0,"r_298_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+690,0,"r_299_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+691,0,"r_299_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+692,0,"r_300_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+693,0,"r_300_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+694,0,"r_301_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+695,0,"r_301_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+696,0,"r_302_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+697,0,"r_302_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+698,0,"r_303_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+699,0,"r_303_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+700,0,"r_304_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+701,0,"r_304_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+702,0,"r_305_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+703,0,"r_305_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+704,0,"r_306_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+705,0,"r_306_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+706,0,"r_307_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+707,0,"r_307_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+708,0,"r_308_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+709,0,"r_308_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+710,0,"r_309_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+711,0,"r_309_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+712,0,"r_310_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+713,0,"r_310_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+714,0,"r_311_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+715,0,"r_311_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+716,0,"r_312_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+717,0,"r_312_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+718,0,"r_313_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+719,0,"r_313_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+720,0,"r_314_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+721,0,"r_314_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+722,0,"r_315_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+723,0,"r_315_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+724,0,"r_316_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+725,0,"r_316_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+726,0,"r_317_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+727,0,"r_317_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+728,0,"r_318_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+729,0,"r_318_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+730,0,"r_319_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+731,0,"r_319_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+732,0,"r_320_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+733,0,"r_320_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+734,0,"r_321_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+735,0,"r_321_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+736,0,"r_322_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+737,0,"r_322_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+738,0,"r_323_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+739,0,"r_323_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+740,0,"r_324_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+741,0,"r_324_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+742,0,"r_325_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+743,0,"r_325_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+744,0,"r_326_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+745,0,"r_326_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+746,0,"r_327_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+747,0,"r_327_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+748,0,"r_328_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+749,0,"r_328_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+750,0,"r_329_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+751,0,"r_329_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+752,0,"r_330_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+753,0,"r_330_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+754,0,"r_331_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+755,0,"r_331_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+756,0,"r_332_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+757,0,"r_332_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+758,0,"r_333_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+759,0,"r_333_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+760,0,"r_334_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+761,0,"r_334_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+762,0,"r_335_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+763,0,"r_335_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+764,0,"r_336_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+765,0,"r_336_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,0,"r_337_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+767,0,"r_337_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+768,0,"r_338_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+769,0,"r_338_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+770,0,"r_339_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+771,0,"r_339_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+772,0,"r_340_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+773,0,"r_340_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+774,0,"r_341_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+775,0,"r_341_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+776,0,"r_342_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+777,0,"r_342_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+778,0,"r_343_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+779,0,"r_343_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+780,0,"r_344_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+781,0,"r_344_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+782,0,"r_345_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+783,0,"r_345_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+784,0,"r_346_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+785,0,"r_346_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+786,0,"r_347_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+787,0,"r_347_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+788,0,"r_348_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+789,0,"r_348_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+790,0,"r_349_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+791,0,"r_349_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+792,0,"r_350_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+793,0,"r_350_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+794,0,"r_351_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+795,0,"r_351_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+796,0,"r_352_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+797,0,"r_352_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+798,0,"r_353_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+799,0,"r_353_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+800,0,"r_354_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+801,0,"r_354_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+802,0,"r_355_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+803,0,"r_355_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+804,0,"r_356_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+805,0,"r_356_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+806,0,"r_357_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+807,0,"r_357_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+808,0,"r_358_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+809,0,"r_358_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+810,0,"r_359_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+811,0,"r_359_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+812,0,"r_360_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+813,0,"r_360_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+814,0,"r_361_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+815,0,"r_361_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+816,0,"r_362_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+817,0,"r_362_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+818,0,"r_363_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+819,0,"r_363_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+820,0,"r_364_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+821,0,"r_364_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+822,0,"r_365_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+823,0,"r_365_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+824,0,"r_366_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+825,0,"r_366_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+826,0,"r_367_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+827,0,"r_367_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"r_368_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+829,0,"r_368_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+830,0,"r_369_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+831,0,"r_369_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+832,0,"r_370_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+833,0,"r_370_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+834,0,"r_371_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+835,0,"r_371_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+836,0,"r_372_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+837,0,"r_372_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+838,0,"r_373_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+839,0,"r_373_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+840,0,"r_374_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+841,0,"r_374_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+842,0,"r_375_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+843,0,"r_375_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+844,0,"r_376_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+845,0,"r_376_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+846,0,"r_377_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+847,0,"r_377_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+848,0,"r_378_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+849,0,"r_378_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+850,0,"r_379_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+851,0,"r_379_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+852,0,"r_380_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+853,0,"r_380_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+854,0,"r_381_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+855,0,"r_381_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+856,0,"r_382_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+857,0,"r_382_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+858,0,"r_383_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+859,0,"r_383_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+860,0,"r_384_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+861,0,"r_384_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+862,0,"r_385_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+863,0,"r_385_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+864,0,"r_386_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+865,0,"r_386_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+866,0,"r_387_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+867,0,"r_387_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+868,0,"r_388_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+869,0,"r_388_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+870,0,"r_389_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+871,0,"r_389_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+872,0,"r_390_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+873,0,"r_390_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+874,0,"r_391_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+875,0,"r_391_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+876,0,"r_392_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+877,0,"r_392_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+878,0,"r_393_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+879,0,"r_393_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+880,0,"r_394_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+881,0,"r_394_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+882,0,"r_395_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+883,0,"r_395_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+884,0,"r_396_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+885,0,"r_396_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+886,0,"r_397_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+887,0,"r_397_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+888,0,"r_398_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+889,0,"r_398_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+890,0,"r_399_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+891,0,"r_399_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+892,0,"r_400_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+893,0,"r_400_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+894,0,"r_401_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+895,0,"r_401_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+896,0,"r_402_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+897,0,"r_402_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+898,0,"r_403_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+899,0,"r_403_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+900,0,"r_404_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+901,0,"r_404_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+902,0,"r_405_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+903,0,"r_405_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+904,0,"r_406_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+905,0,"r_406_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+906,0,"r_407_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+907,0,"r_407_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+908,0,"r_408_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+909,0,"r_408_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+910,0,"r_409_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+911,0,"r_409_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+912,0,"r_410_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+913,0,"r_410_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+914,0,"r_411_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+915,0,"r_411_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+916,0,"r_412_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+917,0,"r_412_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+918,0,"r_413_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+919,0,"r_413_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+920,0,"r_414_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+921,0,"r_414_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+922,0,"r_415_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+923,0,"r_415_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+924,0,"r_416_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+925,0,"r_416_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+926,0,"r_417_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"r_417_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"r_418_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+929,0,"r_418_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+930,0,"r_419_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+931,0,"r_419_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+932,0,"r_420_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"r_420_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+934,0,"r_421_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+935,0,"r_421_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+936,0,"r_422_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+937,0,"r_422_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+938,0,"r_423_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+939,0,"r_423_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+940,0,"r_424_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+941,0,"r_424_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+942,0,"r_425_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+943,0,"r_425_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+944,0,"r_426_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+945,0,"r_426_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+946,0,"r_427_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+947,0,"r_427_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+948,0,"r_428_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+949,0,"r_428_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"r_429_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+951,0,"r_429_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+952,0,"r_430_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+953,0,"r_430_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+954,0,"r_431_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+955,0,"r_431_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+956,0,"r_432_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+957,0,"r_432_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+958,0,"r_433_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+959,0,"r_433_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+960,0,"r_434_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+961,0,"r_434_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+962,0,"r_435_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+963,0,"r_435_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+964,0,"r_436_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+965,0,"r_436_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+966,0,"r_437_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+967,0,"r_437_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+968,0,"r_438_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+969,0,"r_438_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+970,0,"r_439_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+971,0,"r_439_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+972,0,"r_440_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+973,0,"r_440_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+974,0,"r_441_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+975,0,"r_441_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+976,0,"r_442_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+977,0,"r_442_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+978,0,"r_443_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+979,0,"r_443_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+980,0,"r_444_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+981,0,"r_444_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+982,0,"r_445_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+983,0,"r_445_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+984,0,"r_446_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+985,0,"r_446_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+986,0,"r_447_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+987,0,"r_447_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+988,0,"r_448_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+989,0,"r_448_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+990,0,"r_449_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+991,0,"r_449_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+992,0,"r_450_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+993,0,"r_450_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+994,0,"r_451_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+995,0,"r_451_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+996,0,"r_452_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+997,0,"r_452_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+998,0,"r_453_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+999,0,"r_453_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1000,0,"r_454_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1001,0,"r_454_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1002,0,"r_455_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1003,0,"r_455_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1004,0,"r_456_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1005,0,"r_456_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1006,0,"r_457_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1007,0,"r_457_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1008,0,"r_458_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1009,0,"r_458_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1010,0,"r_459_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1011,0,"r_459_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1012,0,"r_460_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1013,0,"r_460_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1014,0,"r_461_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1015,0,"r_461_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1016,0,"r_462_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1017,0,"r_462_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1018,0,"r_463_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1019,0,"r_463_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1020,0,"r_464_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1021,0,"r_464_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1022,0,"r_465_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1023,0,"r_465_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1024,0,"r_466_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1025,0,"r_466_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1026,0,"r_467_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1027,0,"r_467_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1028,0,"r_468_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1029,0,"r_468_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1030,0,"r_469_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1031,0,"r_469_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1032,0,"r_470_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1033,0,"r_470_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1034,0,"r_471_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1035,0,"r_471_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1036,0,"r_472_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1037,0,"r_472_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1038,0,"r_473_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1039,0,"r_473_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1040,0,"r_474_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1041,0,"r_474_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1042,0,"r_475_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1043,0,"r_475_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1044,0,"r_476_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1045,0,"r_476_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1046,0,"r_477_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1047,0,"r_477_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1048,0,"r_478_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1049,0,"r_478_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1050,0,"r_479_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1051,0,"r_479_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1052,0,"r_480_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1053,0,"r_480_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1054,0,"r_481_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1055,0,"r_481_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1056,0,"r_482_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1057,0,"r_482_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1058,0,"r_483_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1059,0,"r_483_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1060,0,"r_484_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1061,0,"r_484_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1062,0,"r_485_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1063,0,"r_485_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1064,0,"r_486_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1065,0,"r_486_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1066,0,"r_487_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1067,0,"r_487_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1068,0,"r_488_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1069,0,"r_488_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1070,0,"r_489_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1071,0,"r_489_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1072,0,"r_490_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1073,0,"r_490_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1074,0,"r_491_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1075,0,"r_491_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1076,0,"r_492_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1077,0,"r_492_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1078,0,"r_493_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1079,0,"r_493_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1080,0,"r_494_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1081,0,"r_494_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1082,0,"r_495_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1083,0,"r_495_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1084,0,"r_496_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1085,0,"r_496_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1086,0,"r_497_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1087,0,"r_497_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1088,0,"r_498_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1089,0,"r_498_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1090,0,"r_499_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1091,0,"r_499_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1092,0,"r_500_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1093,0,"r_500_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1094,0,"r_501_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1095,0,"r_501_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1096,0,"r_502_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1097,0,"r_502_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1098,0,"r_503_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1099,0,"r_503_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1100,0,"r_504_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1101,0,"r_504_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1102,0,"r_505_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1103,0,"r_505_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1104,0,"r_506_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1105,0,"r_506_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1106,0,"r_507_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1107,0,"r_507_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1108,0,"r_508_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1109,0,"r_508_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1110,0,"r_509_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1111,0,"r_509_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1112,0,"r_510_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1113,0,"r_510_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1114,0,"r_511_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1115,0,"r_511_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1116,0,"r_512_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1117,0,"r_512_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1118,0,"r_513_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1119,0,"r_513_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1120,0,"r_514_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1121,0,"r_514_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1122,0,"r_515_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1123,0,"r_515_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1124,0,"r_516_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1125,0,"r_516_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1126,0,"r_517_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1127,0,"r_517_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1128,0,"r_518_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1129,0,"r_518_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1130,0,"r_519_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1131,0,"r_519_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1132,0,"r_520_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1133,0,"r_520_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1134,0,"r_521_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1135,0,"r_521_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1136,0,"r_522_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1137,0,"r_522_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1138,0,"r_523_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1139,0,"r_523_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1140,0,"r_524_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1141,0,"r_524_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1142,0,"r_525_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1143,0,"r_525_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1144,0,"r_526_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1145,0,"r_526_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"r_527_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1147,0,"r_527_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1148,0,"r_528_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1149,0,"r_528_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1150,0,"r_529_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1151,0,"r_529_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1152,0,"r_530_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1153,0,"r_530_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1154,0,"r_531_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1155,0,"r_531_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1156,0,"r_532_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1157,0,"r_532_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1158,0,"r_533_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1159,0,"r_533_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1160,0,"r_534_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1161,0,"r_534_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1162,0,"r_535_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1163,0,"r_535_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1164,0,"r_536_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1165,0,"r_536_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1166,0,"r_537_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1167,0,"r_537_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1168,0,"r_538_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1169,0,"r_538_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1170,0,"r_539_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1171,0,"r_539_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1172,0,"r_540_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1173,0,"r_540_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1174,0,"r_541_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1175,0,"r_541_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1176,0,"r_542_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1177,0,"r_542_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1178,0,"r_543_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1179,0,"r_543_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1180,0,"r_544_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1181,0,"r_544_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1182,0,"r_545_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1183,0,"r_545_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1184,0,"r_546_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1185,0,"r_546_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1186,0,"r_547_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1187,0,"r_547_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1188,0,"r_548_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1189,0,"r_548_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1190,0,"r_549_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1191,0,"r_549_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1192,0,"r_550_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1193,0,"r_550_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1194,0,"r_551_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1195,0,"r_551_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1196,0,"r_552_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1197,0,"r_552_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1198,0,"r_553_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1199,0,"r_553_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1200,0,"r_554_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1201,0,"r_554_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1202,0,"r_555_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1203,0,"r_555_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1204,0,"r_556_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1205,0,"r_556_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1206,0,"r_557_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1207,0,"r_557_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1208,0,"r_558_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1209,0,"r_558_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1210,0,"r_559_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1211,0,"r_559_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1212,0,"r_560_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1213,0,"r_560_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1214,0,"r_561_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1215,0,"r_561_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1216,0,"r_562_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1217,0,"r_562_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1218,0,"r_563_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1219,0,"r_563_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1220,0,"r_564_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1221,0,"r_564_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1222,0,"r_565_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1223,0,"r_565_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1224,0,"r_566_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1225,0,"r_566_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1226,0,"r_567_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1227,0,"r_567_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1228,0,"r_568_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1229,0,"r_568_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1230,0,"r_569_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1231,0,"r_569_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1232,0,"r_570_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1233,0,"r_570_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1234,0,"r_571_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1235,0,"r_571_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1236,0,"r_572_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1237,0,"r_572_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1238,0,"r_573_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1239,0,"r_573_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1240,0,"r_574_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1241,0,"r_574_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1242,0,"r_575_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1243,0,"r_575_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1244,0,"r_576_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1245,0,"r_576_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1246,0,"r_577_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1247,0,"r_577_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1248,0,"r_578_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1249,0,"r_578_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1250,0,"r_579_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1251,0,"r_579_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1252,0,"r_580_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1253,0,"r_580_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1254,0,"r_581_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1255,0,"r_581_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1256,0,"r_582_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1257,0,"r_582_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1258,0,"r_583_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1259,0,"r_583_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1260,0,"r_584_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1261,0,"r_584_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1262,0,"r_585_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1263,0,"r_585_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1264,0,"r_586_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1265,0,"r_586_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1266,0,"r_587_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1267,0,"r_587_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1268,0,"r_588_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1269,0,"r_588_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1270,0,"r_589_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1271,0,"r_589_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1272,0,"r_590_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1273,0,"r_590_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1274,0,"r_591_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1275,0,"r_591_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1276,0,"r_592_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1277,0,"r_592_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1278,0,"r_593_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1279,0,"r_593_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1280,0,"r_594_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1281,0,"r_594_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1282,0,"r_595_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1283,0,"r_595_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1284,0,"r_596_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1285,0,"r_596_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1286,0,"r_597_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1287,0,"r_597_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1288,0,"r_598_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1289,0,"r_598_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1290,0,"r_599_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1291,0,"r_599_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1292,0,"r_600_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1293,0,"r_600_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1294,0,"r_601_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1295,0,"r_601_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1296,0,"r_602_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1297,0,"r_602_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1298,0,"r_603_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1299,0,"r_603_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1300,0,"r_604_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1301,0,"r_604_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1302,0,"r_605_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1303,0,"r_605_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1304,0,"r_606_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1305,0,"r_606_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1306,0,"r_607_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1307,0,"r_607_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1308,0,"r_608_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1309,0,"r_608_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1310,0,"r_609_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1311,0,"r_609_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1312,0,"r_610_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1313,0,"r_610_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1314,0,"r_611_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1315,0,"r_611_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1316,0,"r_612_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1317,0,"r_612_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1318,0,"r_613_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1319,0,"r_613_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1320,0,"r_614_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1321,0,"r_614_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1322,0,"r_615_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1323,0,"r_615_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1324,0,"r_616_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1325,0,"r_616_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1326,0,"r_617_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1327,0,"r_617_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1328,0,"r_618_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1329,0,"r_618_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1330,0,"r_619_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1331,0,"r_619_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1332,0,"r_620_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1333,0,"r_620_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1334,0,"r_621_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1335,0,"r_621_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1336,0,"r_622_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1337,0,"r_622_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1338,0,"r_623_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1339,0,"r_623_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1340,0,"r_624_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1341,0,"r_624_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1342,0,"r_625_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1343,0,"r_625_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1344,0,"r_626_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1345,0,"r_626_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1346,0,"r_627_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1347,0,"r_627_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1348,0,"r_628_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1349,0,"r_628_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1350,0,"r_629_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1351,0,"r_629_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1352,0,"r_630_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1353,0,"r_630_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1354,0,"r_631_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1355,0,"r_631_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1356,0,"r_632_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1357,0,"r_632_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1358,0,"r_633_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1359,0,"r_633_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1360,0,"r_634_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1361,0,"r_634_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1362,0,"r_635_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1363,0,"r_635_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1364,0,"r_636_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1365,0,"r_636_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1366,0,"r_637_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1367,0,"r_637_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1368,0,"r_638_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1369,0,"r_638_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1370,0,"r_639_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1371,0,"r_639_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1372,0,"r_640_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1373,0,"r_640_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1374,0,"r_641_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1375,0,"r_641_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1376,0,"r_642_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1377,0,"r_642_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1378,0,"r_643_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1379,0,"r_643_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1380,0,"r_644_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1381,0,"r_644_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1382,0,"r_645_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1383,0,"r_645_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1384,0,"r_646_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1385,0,"r_646_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1386,0,"r_647_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1387,0,"r_647_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1388,0,"r_648_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1389,0,"r_648_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1390,0,"r_649_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1391,0,"r_649_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1392,0,"r_650_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1393,0,"r_650_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1394,0,"r_651_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1395,0,"r_651_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1396,0,"r_652_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1397,0,"r_652_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1398,0,"r_653_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1399,0,"r_653_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1400,0,"r_654_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1401,0,"r_654_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1402,0,"r_655_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1403,0,"r_655_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1404,0,"r_656_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1405,0,"r_656_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1406,0,"r_657_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1407,0,"r_657_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1408,0,"r_658_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1409,0,"r_658_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1410,0,"r_659_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1411,0,"r_659_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1412,0,"r_660_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1413,0,"r_660_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1414,0,"r_661_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1415,0,"r_661_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1416,0,"r_662_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1417,0,"r_662_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1418,0,"r_663_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1419,0,"r_663_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1420,0,"r_664_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1421,0,"r_664_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1422,0,"r_665_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1423,0,"r_665_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1424,0,"r_666_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1425,0,"r_666_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1426,0,"r_667_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1427,0,"r_667_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1428,0,"r_668_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1429,0,"r_668_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1430,0,"r_669_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1431,0,"r_669_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1432,0,"r_670_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1433,0,"r_670_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1434,0,"r_671_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1435,0,"r_671_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1436,0,"r_672_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1437,0,"r_672_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1438,0,"r_673_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1439,0,"r_673_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1440,0,"r_674_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1441,0,"r_674_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1442,0,"r_675_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1443,0,"r_675_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1444,0,"r_676_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1445,0,"r_676_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1446,0,"r_677_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1447,0,"r_677_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1448,0,"r_678_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1449,0,"r_678_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1450,0,"r_679_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1451,0,"r_679_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1452,0,"r_680_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1453,0,"r_680_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1454,0,"r_681_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1455,0,"r_681_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1456,0,"r_682_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1457,0,"r_682_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1458,0,"r_683_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1459,0,"r_683_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1460,0,"r_684_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1461,0,"r_684_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1462,0,"r_685_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1463,0,"r_685_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1464,0,"r_686_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1465,0,"r_686_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1466,0,"r_687_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1467,0,"r_687_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1468,0,"r_688_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1469,0,"r_688_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1470,0,"r_689_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1471,0,"r_689_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1472,0,"r_690_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1473,0,"r_690_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1474,0,"r_691_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1475,0,"r_691_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1476,0,"r_692_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1477,0,"r_692_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1478,0,"r_693_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1479,0,"r_693_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1480,0,"r_694_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1481,0,"r_694_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1482,0,"r_695_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1483,0,"r_695_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1484,0,"r_696_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1485,0,"r_696_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1486,0,"r_697_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1487,0,"r_697_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1488,0,"r_698_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1489,0,"r_698_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1490,0,"r_699_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1491,0,"r_699_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1492,0,"r_700_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1493,0,"r_700_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1494,0,"r_701_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1495,0,"r_701_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1496,0,"r_702_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1497,0,"r_702_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1498,0,"r_703_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1499,0,"r_703_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1500,0,"r_704_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1501,0,"r_704_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1502,0,"r_705_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1503,0,"r_705_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1504,0,"r_706_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1505,0,"r_706_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1506,0,"r_707_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1507,0,"r_707_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1508,0,"r_708_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1509,0,"r_708_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1510,0,"r_709_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1511,0,"r_709_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1512,0,"r_710_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1513,0,"r_710_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1514,0,"r_711_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1515,0,"r_711_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1516,0,"r_712_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1517,0,"r_712_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1518,0,"r_713_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1519,0,"r_713_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1520,0,"r_714_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1521,0,"r_714_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1522,0,"r_715_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1523,0,"r_715_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1524,0,"r_716_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1525,0,"r_716_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1526,0,"r_717_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1527,0,"r_717_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1528,0,"r_718_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1529,0,"r_718_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1530,0,"r_719_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1531,0,"r_719_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1532,0,"r_720_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1533,0,"r_720_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1534,0,"r_721_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1535,0,"r_721_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1536,0,"r_722_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1537,0,"r_722_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1538,0,"r_723_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1539,0,"r_723_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1540,0,"r_724_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1541,0,"r_724_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1542,0,"r_725_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1543,0,"r_725_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1544,0,"r_726_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1545,0,"r_726_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1546,0,"r_727_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1547,0,"r_727_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1548,0,"r_728_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1549,0,"r_728_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1550,0,"r_729_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1551,0,"r_729_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1552,0,"r_730_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1553,0,"r_730_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1554,0,"r_731_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1555,0,"r_731_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1556,0,"r_732_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1557,0,"r_732_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1558,0,"r_733_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1559,0,"r_733_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1560,0,"r_734_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1561,0,"r_734_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1562,0,"r_735_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1563,0,"r_735_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1564,0,"r_736_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1565,0,"r_736_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1566,0,"r_737_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1567,0,"r_737_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1568,0,"r_738_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1569,0,"r_738_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1570,0,"r_739_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1571,0,"r_739_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1572,0,"r_740_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1573,0,"r_740_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1574,0,"r_741_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1575,0,"r_741_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1576,0,"r_742_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1577,0,"r_742_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1578,0,"r_743_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1579,0,"r_743_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1580,0,"r_744_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1581,0,"r_744_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1582,0,"r_745_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1583,0,"r_745_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1584,0,"r_746_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1585,0,"r_746_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1586,0,"r_747_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1587,0,"r_747_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1588,0,"r_748_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1589,0,"r_748_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1590,0,"r_749_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1591,0,"r_749_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1592,0,"r_750_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1593,0,"r_750_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1594,0,"r_751_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1595,0,"r_751_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1596,0,"r_752_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1597,0,"r_752_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1598,0,"r_753_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1599,0,"r_753_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1600,0,"r_754_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1601,0,"r_754_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1602,0,"r_755_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1603,0,"r_755_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1604,0,"r_756_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1605,0,"r_756_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1606,0,"r_757_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1607,0,"r_757_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1608,0,"r_758_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1609,0,"r_758_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1610,0,"r_759_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1611,0,"r_759_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1612,0,"r_760_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1613,0,"r_760_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1614,0,"r_761_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1615,0,"r_761_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1616,0,"r_762_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1617,0,"r_762_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1618,0,"r_763_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1619,0,"r_763_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1620,0,"r_764_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1621,0,"r_764_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1622,0,"out1_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1623,0,"out1_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"io_out1_REG_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"io_out1_REG_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"io_out2_REG_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"io_out2_REG_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+90,0,"io_out_valid_REG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("commutator", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+38,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+858,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+859,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1624,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+42,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1242,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1243,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1625,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+46,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1434,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1435,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1626,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+50,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1530,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1531,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1627,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+54,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1578,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1579,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1628,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+14,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+58,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1602,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1603,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1629,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+62,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1614,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1615,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1630,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("commutator_7", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+66,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1620,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1621,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"io_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("m", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+602,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+603,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1632,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1633,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+70,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1114,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1115,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1634,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1635,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+72,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1370,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1371,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1636,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1637,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+74,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1498,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1499,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1638,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1639,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+76,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1562,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1563,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1640,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1641,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+78,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1594,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1595,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1642,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1643,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+80,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1610,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1611,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1644,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1645,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+82,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("m_7", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1618,0,"io_in1_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1619,0,"io_in1_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"io_in2_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"io_in2_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1646,0,"io_wn_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1647,0,"io_wn_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"io_out1_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"io_out1_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"io_out2_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"io_out2_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+84,0,"io_out2_k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfft512___024root__trace_init_top(Vfft512___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root__trace_init_top\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vfft512___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vfft512___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vfft512___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfft512___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfft512___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vfft512___024root__trace_register(Vfft512___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root__trace_register\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vfft512___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vfft512___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vfft512___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vfft512___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vfft512___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root__trace_const_0\n"); );
    // Init
    Vfft512___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft512___024root*>(voidSelf);
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vfft512___024root__trace_full_0_sub_0(Vfft512___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vfft512___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root__trace_full_0\n"); );
    // Init
    Vfft512___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfft512___024root*>(voidSelf);
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vfft512___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<256>/*8191:0*/ Vfft512__ConstPool__CONST_h010c7fca_0;
extern const VlWide<256>/*8191:0*/ Vfft512__ConstPool__CONST_h15912bbd_0;
extern const VlWide<128>/*4095:0*/ Vfft512__ConstPool__CONST_hf3784b49_0;
extern const VlWide<128>/*4095:0*/ Vfft512__ConstPool__CONST_h944bc563_0;
extern const VlWide<64>/*2047:0*/ Vfft512__ConstPool__CONST_h8abd5580_0;
extern const VlWide<64>/*2047:0*/ Vfft512__ConstPool__CONST_h5478b25e_0;
extern const VlWide<32>/*1023:0*/ Vfft512__ConstPool__CONST_hb3c963b9_0;
extern const VlWide<32>/*1023:0*/ Vfft512__ConstPool__CONST_h35564355_0;
extern const VlWide<16>/*511:0*/ Vfft512__ConstPool__CONST_h942db0a5_0;
extern const VlWide<16>/*511:0*/ Vfft512__ConstPool__CONST_h0bfcbe7a_0;
extern const VlWide<8>/*255:0*/ Vfft512__ConstPool__CONST_hfd15effc_0;
extern const VlWide<8>/*255:0*/ Vfft512__ConstPool__CONST_h04042068_0;

VL_ATTR_COLD void Vfft512___024root__trace_full_0_sub_0(Vfft512___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfft512___024root__trace_full_0_sub_0\n"); );
    Vfft512__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.FFT512_tb__DOT__reset));
    bufp->fullIData(oldp+2,(vlSelfRef.FFT512_tb__DOT__io_in_real),32);
    bufp->fullIData(oldp+3,(vlSelfRef.FFT512_tb__DOT__io_in_imag),32);
    bufp->fullBit(oldp+4,(vlSelfRef.FFT512_tb__DOT__io_in_valid));
    bufp->fullIData(oldp+5,(vlSelfRef.FFT512_tb__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+6,(((0x80U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                              ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_real
                              : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_real)),32);
    bufp->fullIData(oldp+7,(((0x80U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                              ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_imag
                              : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_imag)),32);
    bufp->fullIData(oldp+8,(((0x40U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                              ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_real
                              : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_real)),32);
    bufp->fullIData(oldp+9,(((0x40U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                              ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_imag
                              : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_imag)),32);
    bufp->fullIData(oldp+10,(((0x20U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_real
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_real)),32);
    bufp->fullIData(oldp+11,(((0x20U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_imag
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_imag)),32);
    bufp->fullIData(oldp+12,(((0x10U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_real
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_real)),32);
    bufp->fullIData(oldp+13,(((0x10U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_imag
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_imag)),32);
    bufp->fullIData(oldp+14,(((8U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_real
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_real)),32);
    bufp->fullIData(oldp+15,(((8U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_imag
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_imag)),32);
    bufp->fullIData(oldp+16,(((4U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_real
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_real)),32);
    bufp->fullIData(oldp+17,(((4U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_imag
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_imag)),32);
    bufp->fullIData(oldp+18,(((2U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_real
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_real)),32);
    bufp->fullIData(oldp+19,(((2U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_imag
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_imag)),32);
    bufp->fullIData(oldp+20,(((1U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_real
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_real)),32);
    bufp->fullIData(oldp+21,(((1U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))
                               ? vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_imag
                               : vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_imag)),32);
    bufp->fullIData(oldp+22,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+23,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+24,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+25,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+26,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+27,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+28,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+29,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+30,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+31,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+32,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+33,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+34,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+35,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+36,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1 
                                          - ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_imag_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k3_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k3_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+37,((IData)((0xffffffffULL 
                                      & ((vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1 
                                          + ((((QData)((IData)(
                                                               (0xfffffU 
                                                                & (- (IData)(
                                                                             (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T 
                                                                              >> 0x1fU)))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_c_real_T))) 
                                             * (((QData)((IData)(
                                                                 (0xfffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k2_T 
                                                                                >> 0x1fU)))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT___io_out2_k2_T))))) 
                                         >> 0x14U)))),32);
    bufp->fullIData(oldp+38,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_real),32);
    bufp->fullIData(oldp+39,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_io_out1_imag),32);
    bufp->fullIData(oldp+40,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_real),32);
    bufp->fullIData(oldp+41,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_io_out2_imag),32);
    bufp->fullIData(oldp+42,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_real),32);
    bufp->fullIData(oldp+43,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_1_io_out1_imag),32);
    bufp->fullIData(oldp+44,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_real),32);
    bufp->fullIData(oldp+45,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_1_io_out2_imag),32);
    bufp->fullIData(oldp+46,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_real),32);
    bufp->fullIData(oldp+47,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_2_io_out1_imag),32);
    bufp->fullIData(oldp+48,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_real),32);
    bufp->fullIData(oldp+49,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_2_io_out2_imag),32);
    bufp->fullIData(oldp+50,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_real),32);
    bufp->fullIData(oldp+51,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_3_io_out1_imag),32);
    bufp->fullIData(oldp+52,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_real),32);
    bufp->fullIData(oldp+53,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_3_io_out2_imag),32);
    bufp->fullIData(oldp+54,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_real),32);
    bufp->fullIData(oldp+55,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_4_io_out1_imag),32);
    bufp->fullIData(oldp+56,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_real),32);
    bufp->fullIData(oldp+57,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_4_io_out2_imag),32);
    bufp->fullIData(oldp+58,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_real),32);
    bufp->fullIData(oldp+59,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_5_io_out1_imag),32);
    bufp->fullIData(oldp+60,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_real),32);
    bufp->fullIData(oldp+61,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_5_io_out2_imag),32);
    bufp->fullIData(oldp+62,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_real),32);
    bufp->fullIData(oldp+63,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_6_io_out1_imag),32);
    bufp->fullIData(oldp+64,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_real),32);
    bufp->fullIData(oldp+65,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_6_io_out2_imag),32);
    bufp->fullIData(oldp+66,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_real),32);
    bufp->fullIData(oldp+67,(vlSelfRef.FFT512_tb__DOT__uut__DOT___m_7_io_out1_imag),32);
    bufp->fullIData(oldp+68,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_real),32);
    bufp->fullIData(oldp+69,(vlSelfRef.FFT512_tb__DOT__uut__DOT___commutator_7_io_out2_imag),32);
    bufp->fullQData(oldp+70,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m__DOT__io_out2_k1),52);
    bufp->fullQData(oldp+72,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_1__DOT__io_out2_k1),52);
    bufp->fullQData(oldp+74,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_2__DOT__io_out2_k1),52);
    bufp->fullQData(oldp+76,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_3__DOT__io_out2_k1),52);
    bufp->fullQData(oldp+78,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_4__DOT__io_out2_k1),52);
    bufp->fullQData(oldp+80,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_5__DOT__io_out2_k1),52);
    bufp->fullQData(oldp+82,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_6__DOT__io_out2_k1),52);
    bufp->fullQData(oldp+84,(vlSelfRef.FFT512_tb__DOT__uut__DOT__m_7__DOT__io_out2_k1),52);
    bufp->fullIData(oldp+86,(vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out1_REG_real),32);
    bufp->fullIData(oldp+87,(vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out1_REG_imag),32);
    bufp->fullIData(oldp+88,(vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out2_REG_real),32);
    bufp->fullIData(oldp+89,(vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out2_REG_imag),32);
    bufp->fullBit(oldp+90,(vlSelfRef.FFT512_tb__DOT__uut__DOT__io_out_valid_REG));
    bufp->fullSData(oldp+91,(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt),10);
    bufp->fullIData(oldp+92,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_real),32);
    bufp->fullIData(oldp+93,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_imag),32);
    bufp->fullIData(oldp+94,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_1_real),32);
    bufp->fullIData(oldp+95,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_1_imag),32);
    bufp->fullIData(oldp+96,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_2_real),32);
    bufp->fullIData(oldp+97,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_2_imag),32);
    bufp->fullIData(oldp+98,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_3_real),32);
    bufp->fullIData(oldp+99,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_3_imag),32);
    bufp->fullIData(oldp+100,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_4_real),32);
    bufp->fullIData(oldp+101,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_4_imag),32);
    bufp->fullIData(oldp+102,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_5_real),32);
    bufp->fullIData(oldp+103,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_5_imag),32);
    bufp->fullIData(oldp+104,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_6_real),32);
    bufp->fullIData(oldp+105,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_6_imag),32);
    bufp->fullIData(oldp+106,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_7_real),32);
    bufp->fullIData(oldp+107,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_7_imag),32);
    bufp->fullIData(oldp+108,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_8_real),32);
    bufp->fullIData(oldp+109,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_8_imag),32);
    bufp->fullIData(oldp+110,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_9_real),32);
    bufp->fullIData(oldp+111,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_9_imag),32);
    bufp->fullIData(oldp+112,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_10_real),32);
    bufp->fullIData(oldp+113,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_10_imag),32);
    bufp->fullIData(oldp+114,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_11_real),32);
    bufp->fullIData(oldp+115,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_11_imag),32);
    bufp->fullIData(oldp+116,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_12_real),32);
    bufp->fullIData(oldp+117,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_12_imag),32);
    bufp->fullIData(oldp+118,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_13_real),32);
    bufp->fullIData(oldp+119,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_13_imag),32);
    bufp->fullIData(oldp+120,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_14_real),32);
    bufp->fullIData(oldp+121,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_14_imag),32);
    bufp->fullIData(oldp+122,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_15_real),32);
    bufp->fullIData(oldp+123,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_15_imag),32);
    bufp->fullIData(oldp+124,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_16_real),32);
    bufp->fullIData(oldp+125,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_16_imag),32);
    bufp->fullIData(oldp+126,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_17_real),32);
    bufp->fullIData(oldp+127,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_17_imag),32);
    bufp->fullIData(oldp+128,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_18_real),32);
    bufp->fullIData(oldp+129,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_18_imag),32);
    bufp->fullIData(oldp+130,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_19_real),32);
    bufp->fullIData(oldp+131,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_19_imag),32);
    bufp->fullIData(oldp+132,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_20_real),32);
    bufp->fullIData(oldp+133,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_20_imag),32);
    bufp->fullIData(oldp+134,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_21_real),32);
    bufp->fullIData(oldp+135,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_21_imag),32);
    bufp->fullIData(oldp+136,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_22_real),32);
    bufp->fullIData(oldp+137,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_22_imag),32);
    bufp->fullIData(oldp+138,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_23_real),32);
    bufp->fullIData(oldp+139,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_23_imag),32);
    bufp->fullIData(oldp+140,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_24_real),32);
    bufp->fullIData(oldp+141,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_24_imag),32);
    bufp->fullIData(oldp+142,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_25_real),32);
    bufp->fullIData(oldp+143,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_25_imag),32);
    bufp->fullIData(oldp+144,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_26_real),32);
    bufp->fullIData(oldp+145,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_26_imag),32);
    bufp->fullIData(oldp+146,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_27_real),32);
    bufp->fullIData(oldp+147,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_27_imag),32);
    bufp->fullIData(oldp+148,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_28_real),32);
    bufp->fullIData(oldp+149,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_28_imag),32);
    bufp->fullIData(oldp+150,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_29_real),32);
    bufp->fullIData(oldp+151,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_29_imag),32);
    bufp->fullIData(oldp+152,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_30_real),32);
    bufp->fullIData(oldp+153,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_30_imag),32);
    bufp->fullIData(oldp+154,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_31_real),32);
    bufp->fullIData(oldp+155,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_31_imag),32);
    bufp->fullIData(oldp+156,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_32_real),32);
    bufp->fullIData(oldp+157,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_32_imag),32);
    bufp->fullIData(oldp+158,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_33_real),32);
    bufp->fullIData(oldp+159,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_33_imag),32);
    bufp->fullIData(oldp+160,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_34_real),32);
    bufp->fullIData(oldp+161,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_34_imag),32);
    bufp->fullIData(oldp+162,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_35_real),32);
    bufp->fullIData(oldp+163,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_35_imag),32);
    bufp->fullIData(oldp+164,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_36_real),32);
    bufp->fullIData(oldp+165,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_36_imag),32);
    bufp->fullIData(oldp+166,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_37_real),32);
    bufp->fullIData(oldp+167,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_37_imag),32);
    bufp->fullIData(oldp+168,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_38_real),32);
    bufp->fullIData(oldp+169,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_38_imag),32);
    bufp->fullIData(oldp+170,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_39_real),32);
    bufp->fullIData(oldp+171,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_39_imag),32);
    bufp->fullIData(oldp+172,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_40_real),32);
    bufp->fullIData(oldp+173,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_40_imag),32);
    bufp->fullIData(oldp+174,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_41_real),32);
    bufp->fullIData(oldp+175,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_41_imag),32);
    bufp->fullIData(oldp+176,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_42_real),32);
    bufp->fullIData(oldp+177,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_42_imag),32);
    bufp->fullIData(oldp+178,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_43_real),32);
    bufp->fullIData(oldp+179,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_43_imag),32);
    bufp->fullIData(oldp+180,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_44_real),32);
    bufp->fullIData(oldp+181,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_44_imag),32);
    bufp->fullIData(oldp+182,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_45_real),32);
    bufp->fullIData(oldp+183,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_45_imag),32);
    bufp->fullIData(oldp+184,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_46_real),32);
    bufp->fullIData(oldp+185,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_46_imag),32);
    bufp->fullIData(oldp+186,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_47_real),32);
    bufp->fullIData(oldp+187,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_47_imag),32);
    bufp->fullIData(oldp+188,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_48_real),32);
    bufp->fullIData(oldp+189,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_48_imag),32);
    bufp->fullIData(oldp+190,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_49_real),32);
    bufp->fullIData(oldp+191,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_49_imag),32);
    bufp->fullIData(oldp+192,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_50_real),32);
    bufp->fullIData(oldp+193,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_50_imag),32);
    bufp->fullIData(oldp+194,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_51_real),32);
    bufp->fullIData(oldp+195,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_51_imag),32);
    bufp->fullIData(oldp+196,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_52_real),32);
    bufp->fullIData(oldp+197,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_52_imag),32);
    bufp->fullIData(oldp+198,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_53_real),32);
    bufp->fullIData(oldp+199,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_53_imag),32);
    bufp->fullIData(oldp+200,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_54_real),32);
    bufp->fullIData(oldp+201,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_54_imag),32);
    bufp->fullIData(oldp+202,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_55_real),32);
    bufp->fullIData(oldp+203,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_55_imag),32);
    bufp->fullIData(oldp+204,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_56_real),32);
    bufp->fullIData(oldp+205,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_56_imag),32);
    bufp->fullIData(oldp+206,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_57_real),32);
    bufp->fullIData(oldp+207,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_57_imag),32);
    bufp->fullIData(oldp+208,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_58_real),32);
    bufp->fullIData(oldp+209,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_58_imag),32);
    bufp->fullIData(oldp+210,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_59_real),32);
    bufp->fullIData(oldp+211,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_59_imag),32);
    bufp->fullIData(oldp+212,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_60_real),32);
    bufp->fullIData(oldp+213,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_60_imag),32);
    bufp->fullIData(oldp+214,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_61_real),32);
    bufp->fullIData(oldp+215,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_61_imag),32);
    bufp->fullIData(oldp+216,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_62_real),32);
    bufp->fullIData(oldp+217,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_62_imag),32);
    bufp->fullIData(oldp+218,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_63_real),32);
    bufp->fullIData(oldp+219,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_63_imag),32);
    bufp->fullIData(oldp+220,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_64_real),32);
    bufp->fullIData(oldp+221,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_64_imag),32);
    bufp->fullIData(oldp+222,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_65_real),32);
    bufp->fullIData(oldp+223,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_65_imag),32);
    bufp->fullIData(oldp+224,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_66_real),32);
    bufp->fullIData(oldp+225,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_66_imag),32);
    bufp->fullIData(oldp+226,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_67_real),32);
    bufp->fullIData(oldp+227,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_67_imag),32);
    bufp->fullIData(oldp+228,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_68_real),32);
    bufp->fullIData(oldp+229,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_68_imag),32);
    bufp->fullIData(oldp+230,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_69_real),32);
    bufp->fullIData(oldp+231,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_69_imag),32);
    bufp->fullIData(oldp+232,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_70_real),32);
    bufp->fullIData(oldp+233,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_70_imag),32);
    bufp->fullIData(oldp+234,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_71_real),32);
    bufp->fullIData(oldp+235,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_71_imag),32);
    bufp->fullIData(oldp+236,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_72_real),32);
    bufp->fullIData(oldp+237,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_72_imag),32);
    bufp->fullIData(oldp+238,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_73_real),32);
    bufp->fullIData(oldp+239,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_73_imag),32);
    bufp->fullIData(oldp+240,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_74_real),32);
    bufp->fullIData(oldp+241,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_74_imag),32);
    bufp->fullIData(oldp+242,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_75_real),32);
    bufp->fullIData(oldp+243,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_75_imag),32);
    bufp->fullIData(oldp+244,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_76_real),32);
    bufp->fullIData(oldp+245,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_76_imag),32);
    bufp->fullIData(oldp+246,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_77_real),32);
    bufp->fullIData(oldp+247,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_77_imag),32);
    bufp->fullIData(oldp+248,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_78_real),32);
    bufp->fullIData(oldp+249,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_78_imag),32);
    bufp->fullIData(oldp+250,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_79_real),32);
    bufp->fullIData(oldp+251,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_79_imag),32);
    bufp->fullIData(oldp+252,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_80_real),32);
    bufp->fullIData(oldp+253,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_80_imag),32);
    bufp->fullIData(oldp+254,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_81_real),32);
    bufp->fullIData(oldp+255,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_81_imag),32);
    bufp->fullIData(oldp+256,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_82_real),32);
    bufp->fullIData(oldp+257,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_82_imag),32);
    bufp->fullIData(oldp+258,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_83_real),32);
    bufp->fullIData(oldp+259,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_83_imag),32);
    bufp->fullIData(oldp+260,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_84_real),32);
    bufp->fullIData(oldp+261,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_84_imag),32);
    bufp->fullIData(oldp+262,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_85_real),32);
    bufp->fullIData(oldp+263,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_85_imag),32);
    bufp->fullIData(oldp+264,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_86_real),32);
    bufp->fullIData(oldp+265,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_86_imag),32);
    bufp->fullIData(oldp+266,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_87_real),32);
    bufp->fullIData(oldp+267,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_87_imag),32);
    bufp->fullIData(oldp+268,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_88_real),32);
    bufp->fullIData(oldp+269,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_88_imag),32);
    bufp->fullIData(oldp+270,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_89_real),32);
    bufp->fullIData(oldp+271,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_89_imag),32);
    bufp->fullIData(oldp+272,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_90_real),32);
    bufp->fullIData(oldp+273,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_90_imag),32);
    bufp->fullIData(oldp+274,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_91_real),32);
    bufp->fullIData(oldp+275,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_91_imag),32);
    bufp->fullIData(oldp+276,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_92_real),32);
    bufp->fullIData(oldp+277,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_92_imag),32);
    bufp->fullIData(oldp+278,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_93_real),32);
    bufp->fullIData(oldp+279,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_93_imag),32);
    bufp->fullIData(oldp+280,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_94_real),32);
    bufp->fullIData(oldp+281,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_94_imag),32);
    bufp->fullIData(oldp+282,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_95_real),32);
    bufp->fullIData(oldp+283,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_95_imag),32);
    bufp->fullIData(oldp+284,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_96_real),32);
    bufp->fullIData(oldp+285,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_96_imag),32);
    bufp->fullIData(oldp+286,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_97_real),32);
    bufp->fullIData(oldp+287,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_97_imag),32);
    bufp->fullIData(oldp+288,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_98_real),32);
    bufp->fullIData(oldp+289,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_98_imag),32);
    bufp->fullIData(oldp+290,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_99_real),32);
    bufp->fullIData(oldp+291,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_99_imag),32);
    bufp->fullIData(oldp+292,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_100_real),32);
    bufp->fullIData(oldp+293,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_100_imag),32);
    bufp->fullIData(oldp+294,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_101_real),32);
    bufp->fullIData(oldp+295,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_101_imag),32);
    bufp->fullIData(oldp+296,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_102_real),32);
    bufp->fullIData(oldp+297,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_102_imag),32);
    bufp->fullIData(oldp+298,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_103_real),32);
    bufp->fullIData(oldp+299,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_103_imag),32);
    bufp->fullIData(oldp+300,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_104_real),32);
    bufp->fullIData(oldp+301,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_104_imag),32);
    bufp->fullIData(oldp+302,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_105_real),32);
    bufp->fullIData(oldp+303,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_105_imag),32);
    bufp->fullIData(oldp+304,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_106_real),32);
    bufp->fullIData(oldp+305,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_106_imag),32);
    bufp->fullIData(oldp+306,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_107_real),32);
    bufp->fullIData(oldp+307,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_107_imag),32);
    bufp->fullIData(oldp+308,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_108_real),32);
    bufp->fullIData(oldp+309,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_108_imag),32);
    bufp->fullIData(oldp+310,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_109_real),32);
    bufp->fullIData(oldp+311,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_109_imag),32);
    bufp->fullIData(oldp+312,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_110_real),32);
    bufp->fullIData(oldp+313,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_110_imag),32);
    bufp->fullIData(oldp+314,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_111_real),32);
    bufp->fullIData(oldp+315,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_111_imag),32);
    bufp->fullIData(oldp+316,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_112_real),32);
    bufp->fullIData(oldp+317,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_112_imag),32);
    bufp->fullIData(oldp+318,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_113_real),32);
    bufp->fullIData(oldp+319,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_113_imag),32);
    bufp->fullIData(oldp+320,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_114_real),32);
    bufp->fullIData(oldp+321,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_114_imag),32);
    bufp->fullIData(oldp+322,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_115_real),32);
    bufp->fullIData(oldp+323,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_115_imag),32);
    bufp->fullIData(oldp+324,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_116_real),32);
    bufp->fullIData(oldp+325,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_116_imag),32);
    bufp->fullIData(oldp+326,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_117_real),32);
    bufp->fullIData(oldp+327,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_117_imag),32);
    bufp->fullIData(oldp+328,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_118_real),32);
    bufp->fullIData(oldp+329,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_118_imag),32);
    bufp->fullIData(oldp+330,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_119_real),32);
    bufp->fullIData(oldp+331,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_119_imag),32);
    bufp->fullIData(oldp+332,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_120_real),32);
    bufp->fullIData(oldp+333,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_120_imag),32);
    bufp->fullIData(oldp+334,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_121_real),32);
    bufp->fullIData(oldp+335,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_121_imag),32);
    bufp->fullIData(oldp+336,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_122_real),32);
    bufp->fullIData(oldp+337,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_122_imag),32);
    bufp->fullIData(oldp+338,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_123_real),32);
    bufp->fullIData(oldp+339,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_123_imag),32);
    bufp->fullIData(oldp+340,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_124_real),32);
    bufp->fullIData(oldp+341,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_124_imag),32);
    bufp->fullIData(oldp+342,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_125_real),32);
    bufp->fullIData(oldp+343,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_125_imag),32);
    bufp->fullIData(oldp+344,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_126_real),32);
    bufp->fullIData(oldp+345,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_126_imag),32);
    bufp->fullIData(oldp+346,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_127_real),32);
    bufp->fullIData(oldp+347,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_127_imag),32);
    bufp->fullIData(oldp+348,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_128_real),32);
    bufp->fullIData(oldp+349,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_128_imag),32);
    bufp->fullIData(oldp+350,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_129_real),32);
    bufp->fullIData(oldp+351,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_129_imag),32);
    bufp->fullIData(oldp+352,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_130_real),32);
    bufp->fullIData(oldp+353,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_130_imag),32);
    bufp->fullIData(oldp+354,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_131_real),32);
    bufp->fullIData(oldp+355,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_131_imag),32);
    bufp->fullIData(oldp+356,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_132_real),32);
    bufp->fullIData(oldp+357,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_132_imag),32);
    bufp->fullIData(oldp+358,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_133_real),32);
    bufp->fullIData(oldp+359,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_133_imag),32);
    bufp->fullIData(oldp+360,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_134_real),32);
    bufp->fullIData(oldp+361,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_134_imag),32);
    bufp->fullIData(oldp+362,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_135_real),32);
    bufp->fullIData(oldp+363,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_135_imag),32);
    bufp->fullIData(oldp+364,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_136_real),32);
    bufp->fullIData(oldp+365,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_136_imag),32);
    bufp->fullIData(oldp+366,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_137_real),32);
    bufp->fullIData(oldp+367,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_137_imag),32);
    bufp->fullIData(oldp+368,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_138_real),32);
    bufp->fullIData(oldp+369,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_138_imag),32);
    bufp->fullIData(oldp+370,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_139_real),32);
    bufp->fullIData(oldp+371,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_139_imag),32);
    bufp->fullIData(oldp+372,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_140_real),32);
    bufp->fullIData(oldp+373,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_140_imag),32);
    bufp->fullIData(oldp+374,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_141_real),32);
    bufp->fullIData(oldp+375,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_141_imag),32);
    bufp->fullIData(oldp+376,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_142_real),32);
    bufp->fullIData(oldp+377,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_142_imag),32);
    bufp->fullIData(oldp+378,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_143_real),32);
    bufp->fullIData(oldp+379,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_143_imag),32);
    bufp->fullIData(oldp+380,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_144_real),32);
    bufp->fullIData(oldp+381,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_144_imag),32);
    bufp->fullIData(oldp+382,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_145_real),32);
    bufp->fullIData(oldp+383,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_145_imag),32);
    bufp->fullIData(oldp+384,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_146_real),32);
    bufp->fullIData(oldp+385,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_146_imag),32);
    bufp->fullIData(oldp+386,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_147_real),32);
    bufp->fullIData(oldp+387,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_147_imag),32);
    bufp->fullIData(oldp+388,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_148_real),32);
    bufp->fullIData(oldp+389,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_148_imag),32);
    bufp->fullIData(oldp+390,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_149_real),32);
    bufp->fullIData(oldp+391,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_149_imag),32);
    bufp->fullIData(oldp+392,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_150_real),32);
    bufp->fullIData(oldp+393,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_150_imag),32);
    bufp->fullIData(oldp+394,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_151_real),32);
    bufp->fullIData(oldp+395,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_151_imag),32);
    bufp->fullIData(oldp+396,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_152_real),32);
    bufp->fullIData(oldp+397,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_152_imag),32);
    bufp->fullIData(oldp+398,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_153_real),32);
    bufp->fullIData(oldp+399,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_153_imag),32);
    bufp->fullIData(oldp+400,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_154_real),32);
    bufp->fullIData(oldp+401,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_154_imag),32);
    bufp->fullIData(oldp+402,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_155_real),32);
    bufp->fullIData(oldp+403,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_155_imag),32);
    bufp->fullIData(oldp+404,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_156_real),32);
    bufp->fullIData(oldp+405,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_156_imag),32);
    bufp->fullIData(oldp+406,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_157_real),32);
    bufp->fullIData(oldp+407,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_157_imag),32);
    bufp->fullIData(oldp+408,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_158_real),32);
    bufp->fullIData(oldp+409,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_158_imag),32);
    bufp->fullIData(oldp+410,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_159_real),32);
    bufp->fullIData(oldp+411,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_159_imag),32);
    bufp->fullIData(oldp+412,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_160_real),32);
    bufp->fullIData(oldp+413,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_160_imag),32);
    bufp->fullIData(oldp+414,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_161_real),32);
    bufp->fullIData(oldp+415,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_161_imag),32);
    bufp->fullIData(oldp+416,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_162_real),32);
    bufp->fullIData(oldp+417,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_162_imag),32);
    bufp->fullIData(oldp+418,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_163_real),32);
    bufp->fullIData(oldp+419,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_163_imag),32);
    bufp->fullIData(oldp+420,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_164_real),32);
    bufp->fullIData(oldp+421,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_164_imag),32);
    bufp->fullIData(oldp+422,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_165_real),32);
    bufp->fullIData(oldp+423,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_165_imag),32);
    bufp->fullIData(oldp+424,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_166_real),32);
    bufp->fullIData(oldp+425,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_166_imag),32);
    bufp->fullIData(oldp+426,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_167_real),32);
    bufp->fullIData(oldp+427,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_167_imag),32);
    bufp->fullIData(oldp+428,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_168_real),32);
    bufp->fullIData(oldp+429,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_168_imag),32);
    bufp->fullIData(oldp+430,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_169_real),32);
    bufp->fullIData(oldp+431,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_169_imag),32);
    bufp->fullIData(oldp+432,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_170_real),32);
    bufp->fullIData(oldp+433,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_170_imag),32);
    bufp->fullIData(oldp+434,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_171_real),32);
    bufp->fullIData(oldp+435,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_171_imag),32);
    bufp->fullIData(oldp+436,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_172_real),32);
    bufp->fullIData(oldp+437,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_172_imag),32);
    bufp->fullIData(oldp+438,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_173_real),32);
    bufp->fullIData(oldp+439,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_173_imag),32);
    bufp->fullIData(oldp+440,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_174_real),32);
    bufp->fullIData(oldp+441,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_174_imag),32);
    bufp->fullIData(oldp+442,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_175_real),32);
    bufp->fullIData(oldp+443,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_175_imag),32);
    bufp->fullIData(oldp+444,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_176_real),32);
    bufp->fullIData(oldp+445,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_176_imag),32);
    bufp->fullIData(oldp+446,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_177_real),32);
    bufp->fullIData(oldp+447,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_177_imag),32);
    bufp->fullIData(oldp+448,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_178_real),32);
    bufp->fullIData(oldp+449,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_178_imag),32);
    bufp->fullIData(oldp+450,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_179_real),32);
    bufp->fullIData(oldp+451,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_179_imag),32);
    bufp->fullIData(oldp+452,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_180_real),32);
    bufp->fullIData(oldp+453,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_180_imag),32);
    bufp->fullIData(oldp+454,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_181_real),32);
    bufp->fullIData(oldp+455,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_181_imag),32);
    bufp->fullIData(oldp+456,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_182_real),32);
    bufp->fullIData(oldp+457,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_182_imag),32);
    bufp->fullIData(oldp+458,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_183_real),32);
    bufp->fullIData(oldp+459,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_183_imag),32);
    bufp->fullIData(oldp+460,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_184_real),32);
    bufp->fullIData(oldp+461,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_184_imag),32);
    bufp->fullIData(oldp+462,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_185_real),32);
    bufp->fullIData(oldp+463,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_185_imag),32);
    bufp->fullIData(oldp+464,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_186_real),32);
    bufp->fullIData(oldp+465,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_186_imag),32);
    bufp->fullIData(oldp+466,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_187_real),32);
    bufp->fullIData(oldp+467,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_187_imag),32);
    bufp->fullIData(oldp+468,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_188_real),32);
    bufp->fullIData(oldp+469,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_188_imag),32);
    bufp->fullIData(oldp+470,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_189_real),32);
    bufp->fullIData(oldp+471,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_189_imag),32);
    bufp->fullIData(oldp+472,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_190_real),32);
    bufp->fullIData(oldp+473,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_190_imag),32);
    bufp->fullIData(oldp+474,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_191_real),32);
    bufp->fullIData(oldp+475,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_191_imag),32);
    bufp->fullIData(oldp+476,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_192_real),32);
    bufp->fullIData(oldp+477,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_192_imag),32);
    bufp->fullIData(oldp+478,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_193_real),32);
    bufp->fullIData(oldp+479,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_193_imag),32);
    bufp->fullIData(oldp+480,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_194_real),32);
    bufp->fullIData(oldp+481,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_194_imag),32);
    bufp->fullIData(oldp+482,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_195_real),32);
    bufp->fullIData(oldp+483,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_195_imag),32);
    bufp->fullIData(oldp+484,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_196_real),32);
    bufp->fullIData(oldp+485,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_196_imag),32);
    bufp->fullIData(oldp+486,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_197_real),32);
    bufp->fullIData(oldp+487,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_197_imag),32);
    bufp->fullIData(oldp+488,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_198_real),32);
    bufp->fullIData(oldp+489,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_198_imag),32);
    bufp->fullIData(oldp+490,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_199_real),32);
    bufp->fullIData(oldp+491,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_199_imag),32);
    bufp->fullIData(oldp+492,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_200_real),32);
    bufp->fullIData(oldp+493,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_200_imag),32);
    bufp->fullIData(oldp+494,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_201_real),32);
    bufp->fullIData(oldp+495,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_201_imag),32);
    bufp->fullIData(oldp+496,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_202_real),32);
    bufp->fullIData(oldp+497,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_202_imag),32);
    bufp->fullIData(oldp+498,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_203_real),32);
    bufp->fullIData(oldp+499,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_203_imag),32);
    bufp->fullIData(oldp+500,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_204_real),32);
    bufp->fullIData(oldp+501,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_204_imag),32);
    bufp->fullIData(oldp+502,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_205_real),32);
    bufp->fullIData(oldp+503,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_205_imag),32);
    bufp->fullIData(oldp+504,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_206_real),32);
    bufp->fullIData(oldp+505,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_206_imag),32);
    bufp->fullIData(oldp+506,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_207_real),32);
    bufp->fullIData(oldp+507,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_207_imag),32);
    bufp->fullIData(oldp+508,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_208_real),32);
    bufp->fullIData(oldp+509,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_208_imag),32);
    bufp->fullIData(oldp+510,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_209_real),32);
    bufp->fullIData(oldp+511,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_209_imag),32);
    bufp->fullIData(oldp+512,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_210_real),32);
    bufp->fullIData(oldp+513,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_210_imag),32);
    bufp->fullIData(oldp+514,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_211_real),32);
    bufp->fullIData(oldp+515,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_211_imag),32);
    bufp->fullIData(oldp+516,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_212_real),32);
    bufp->fullIData(oldp+517,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_212_imag),32);
    bufp->fullIData(oldp+518,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_213_real),32);
    bufp->fullIData(oldp+519,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_213_imag),32);
    bufp->fullIData(oldp+520,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_214_real),32);
    bufp->fullIData(oldp+521,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_214_imag),32);
    bufp->fullIData(oldp+522,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_215_real),32);
    bufp->fullIData(oldp+523,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_215_imag),32);
    bufp->fullIData(oldp+524,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_216_real),32);
    bufp->fullIData(oldp+525,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_216_imag),32);
    bufp->fullIData(oldp+526,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_217_real),32);
    bufp->fullIData(oldp+527,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_217_imag),32);
    bufp->fullIData(oldp+528,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_218_real),32);
    bufp->fullIData(oldp+529,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_218_imag),32);
    bufp->fullIData(oldp+530,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_219_real),32);
    bufp->fullIData(oldp+531,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_219_imag),32);
    bufp->fullIData(oldp+532,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_220_real),32);
    bufp->fullIData(oldp+533,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_220_imag),32);
    bufp->fullIData(oldp+534,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_221_real),32);
    bufp->fullIData(oldp+535,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_221_imag),32);
    bufp->fullIData(oldp+536,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_222_real),32);
    bufp->fullIData(oldp+537,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_222_imag),32);
    bufp->fullIData(oldp+538,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_223_real),32);
    bufp->fullIData(oldp+539,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_223_imag),32);
    bufp->fullIData(oldp+540,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_224_real),32);
    bufp->fullIData(oldp+541,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_224_imag),32);
    bufp->fullIData(oldp+542,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_225_real),32);
    bufp->fullIData(oldp+543,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_225_imag),32);
    bufp->fullIData(oldp+544,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_226_real),32);
    bufp->fullIData(oldp+545,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_226_imag),32);
    bufp->fullIData(oldp+546,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_227_real),32);
    bufp->fullIData(oldp+547,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_227_imag),32);
    bufp->fullIData(oldp+548,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_228_real),32);
    bufp->fullIData(oldp+549,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_228_imag),32);
    bufp->fullIData(oldp+550,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_229_real),32);
    bufp->fullIData(oldp+551,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_229_imag),32);
    bufp->fullIData(oldp+552,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_230_real),32);
    bufp->fullIData(oldp+553,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_230_imag),32);
    bufp->fullIData(oldp+554,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_231_real),32);
    bufp->fullIData(oldp+555,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_231_imag),32);
    bufp->fullIData(oldp+556,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_232_real),32);
    bufp->fullIData(oldp+557,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_232_imag),32);
    bufp->fullIData(oldp+558,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_233_real),32);
    bufp->fullIData(oldp+559,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_233_imag),32);
    bufp->fullIData(oldp+560,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_234_real),32);
    bufp->fullIData(oldp+561,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_234_imag),32);
    bufp->fullIData(oldp+562,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_235_real),32);
    bufp->fullIData(oldp+563,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_235_imag),32);
    bufp->fullIData(oldp+564,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_236_real),32);
    bufp->fullIData(oldp+565,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_236_imag),32);
    bufp->fullIData(oldp+566,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_237_real),32);
    bufp->fullIData(oldp+567,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_237_imag),32);
    bufp->fullIData(oldp+568,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_238_real),32);
    bufp->fullIData(oldp+569,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_238_imag),32);
    bufp->fullIData(oldp+570,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_239_real),32);
    bufp->fullIData(oldp+571,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_239_imag),32);
    bufp->fullIData(oldp+572,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_240_real),32);
    bufp->fullIData(oldp+573,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_240_imag),32);
    bufp->fullIData(oldp+574,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_241_real),32);
    bufp->fullIData(oldp+575,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_241_imag),32);
    bufp->fullIData(oldp+576,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_242_real),32);
    bufp->fullIData(oldp+577,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_242_imag),32);
    bufp->fullIData(oldp+578,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_243_real),32);
    bufp->fullIData(oldp+579,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_243_imag),32);
    bufp->fullIData(oldp+580,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_244_real),32);
    bufp->fullIData(oldp+581,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_244_imag),32);
    bufp->fullIData(oldp+582,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_245_real),32);
    bufp->fullIData(oldp+583,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_245_imag),32);
    bufp->fullIData(oldp+584,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_246_real),32);
    bufp->fullIData(oldp+585,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_246_imag),32);
    bufp->fullIData(oldp+586,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_247_real),32);
    bufp->fullIData(oldp+587,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_247_imag),32);
    bufp->fullIData(oldp+588,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_248_real),32);
    bufp->fullIData(oldp+589,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_248_imag),32);
    bufp->fullIData(oldp+590,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_249_real),32);
    bufp->fullIData(oldp+591,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_249_imag),32);
    bufp->fullIData(oldp+592,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_250_real),32);
    bufp->fullIData(oldp+593,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_250_imag),32);
    bufp->fullIData(oldp+594,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_251_real),32);
    bufp->fullIData(oldp+595,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_251_imag),32);
    bufp->fullIData(oldp+596,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_252_real),32);
    bufp->fullIData(oldp+597,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_252_imag),32);
    bufp->fullIData(oldp+598,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_253_real),32);
    bufp->fullIData(oldp+599,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_253_imag),32);
    bufp->fullIData(oldp+600,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_254_real),32);
    bufp->fullIData(oldp+601,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_254_imag),32);
    bufp->fullIData(oldp+602,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_real),32);
    bufp->fullIData(oldp+603,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_255_imag),32);
    bufp->fullIData(oldp+604,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_256_real),32);
    bufp->fullIData(oldp+605,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_256_imag),32);
    bufp->fullIData(oldp+606,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_257_real),32);
    bufp->fullIData(oldp+607,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_257_imag),32);
    bufp->fullIData(oldp+608,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_258_real),32);
    bufp->fullIData(oldp+609,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_258_imag),32);
    bufp->fullIData(oldp+610,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_259_real),32);
    bufp->fullIData(oldp+611,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_259_imag),32);
    bufp->fullIData(oldp+612,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_260_real),32);
    bufp->fullIData(oldp+613,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_260_imag),32);
    bufp->fullIData(oldp+614,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_261_real),32);
    bufp->fullIData(oldp+615,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_261_imag),32);
    bufp->fullIData(oldp+616,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_262_real),32);
    bufp->fullIData(oldp+617,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_262_imag),32);
    bufp->fullIData(oldp+618,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_263_real),32);
    bufp->fullIData(oldp+619,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_263_imag),32);
    bufp->fullIData(oldp+620,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_264_real),32);
    bufp->fullIData(oldp+621,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_264_imag),32);
    bufp->fullIData(oldp+622,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_265_real),32);
    bufp->fullIData(oldp+623,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_265_imag),32);
    bufp->fullIData(oldp+624,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_266_real),32);
    bufp->fullIData(oldp+625,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_266_imag),32);
    bufp->fullIData(oldp+626,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_267_real),32);
    bufp->fullIData(oldp+627,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_267_imag),32);
    bufp->fullIData(oldp+628,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_268_real),32);
    bufp->fullIData(oldp+629,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_268_imag),32);
    bufp->fullIData(oldp+630,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_269_real),32);
    bufp->fullIData(oldp+631,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_269_imag),32);
    bufp->fullIData(oldp+632,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_270_real),32);
    bufp->fullIData(oldp+633,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_270_imag),32);
    bufp->fullIData(oldp+634,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_271_real),32);
    bufp->fullIData(oldp+635,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_271_imag),32);
    bufp->fullIData(oldp+636,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_272_real),32);
    bufp->fullIData(oldp+637,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_272_imag),32);
    bufp->fullIData(oldp+638,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_273_real),32);
    bufp->fullIData(oldp+639,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_273_imag),32);
    bufp->fullIData(oldp+640,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_274_real),32);
    bufp->fullIData(oldp+641,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_274_imag),32);
    bufp->fullIData(oldp+642,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_275_real),32);
    bufp->fullIData(oldp+643,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_275_imag),32);
    bufp->fullIData(oldp+644,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_276_real),32);
    bufp->fullIData(oldp+645,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_276_imag),32);
    bufp->fullIData(oldp+646,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_277_real),32);
    bufp->fullIData(oldp+647,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_277_imag),32);
    bufp->fullIData(oldp+648,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_278_real),32);
    bufp->fullIData(oldp+649,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_278_imag),32);
    bufp->fullIData(oldp+650,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_279_real),32);
    bufp->fullIData(oldp+651,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_279_imag),32);
    bufp->fullIData(oldp+652,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_280_real),32);
    bufp->fullIData(oldp+653,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_280_imag),32);
    bufp->fullIData(oldp+654,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_281_real),32);
    bufp->fullIData(oldp+655,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_281_imag),32);
    bufp->fullIData(oldp+656,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_282_real),32);
    bufp->fullIData(oldp+657,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_282_imag),32);
    bufp->fullIData(oldp+658,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_283_real),32);
    bufp->fullIData(oldp+659,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_283_imag),32);
    bufp->fullIData(oldp+660,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_284_real),32);
    bufp->fullIData(oldp+661,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_284_imag),32);
    bufp->fullIData(oldp+662,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_285_real),32);
    bufp->fullIData(oldp+663,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_285_imag),32);
    bufp->fullIData(oldp+664,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_286_real),32);
    bufp->fullIData(oldp+665,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_286_imag),32);
    bufp->fullIData(oldp+666,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_287_real),32);
    bufp->fullIData(oldp+667,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_287_imag),32);
    bufp->fullIData(oldp+668,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_288_real),32);
    bufp->fullIData(oldp+669,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_288_imag),32);
    bufp->fullIData(oldp+670,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_289_real),32);
    bufp->fullIData(oldp+671,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_289_imag),32);
    bufp->fullIData(oldp+672,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_290_real),32);
    bufp->fullIData(oldp+673,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_290_imag),32);
    bufp->fullIData(oldp+674,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_291_real),32);
    bufp->fullIData(oldp+675,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_291_imag),32);
    bufp->fullIData(oldp+676,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_292_real),32);
    bufp->fullIData(oldp+677,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_292_imag),32);
    bufp->fullIData(oldp+678,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_293_real),32);
    bufp->fullIData(oldp+679,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_293_imag),32);
    bufp->fullIData(oldp+680,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_294_real),32);
    bufp->fullIData(oldp+681,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_294_imag),32);
    bufp->fullIData(oldp+682,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_295_real),32);
    bufp->fullIData(oldp+683,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_295_imag),32);
    bufp->fullIData(oldp+684,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_296_real),32);
    bufp->fullIData(oldp+685,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_296_imag),32);
    bufp->fullIData(oldp+686,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_297_real),32);
    bufp->fullIData(oldp+687,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_297_imag),32);
    bufp->fullIData(oldp+688,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_298_real),32);
    bufp->fullIData(oldp+689,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_298_imag),32);
    bufp->fullIData(oldp+690,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_299_real),32);
    bufp->fullIData(oldp+691,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_299_imag),32);
    bufp->fullIData(oldp+692,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_300_real),32);
    bufp->fullIData(oldp+693,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_300_imag),32);
    bufp->fullIData(oldp+694,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_301_real),32);
    bufp->fullIData(oldp+695,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_301_imag),32);
    bufp->fullIData(oldp+696,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_302_real),32);
    bufp->fullIData(oldp+697,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_302_imag),32);
    bufp->fullIData(oldp+698,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_303_real),32);
    bufp->fullIData(oldp+699,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_303_imag),32);
    bufp->fullIData(oldp+700,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_304_real),32);
    bufp->fullIData(oldp+701,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_304_imag),32);
    bufp->fullIData(oldp+702,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_305_real),32);
    bufp->fullIData(oldp+703,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_305_imag),32);
    bufp->fullIData(oldp+704,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_306_real),32);
    bufp->fullIData(oldp+705,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_306_imag),32);
    bufp->fullIData(oldp+706,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_307_real),32);
    bufp->fullIData(oldp+707,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_307_imag),32);
    bufp->fullIData(oldp+708,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_308_real),32);
    bufp->fullIData(oldp+709,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_308_imag),32);
    bufp->fullIData(oldp+710,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_309_real),32);
    bufp->fullIData(oldp+711,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_309_imag),32);
    bufp->fullIData(oldp+712,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_310_real),32);
    bufp->fullIData(oldp+713,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_310_imag),32);
    bufp->fullIData(oldp+714,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_311_real),32);
    bufp->fullIData(oldp+715,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_311_imag),32);
    bufp->fullIData(oldp+716,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_312_real),32);
    bufp->fullIData(oldp+717,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_312_imag),32);
    bufp->fullIData(oldp+718,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_313_real),32);
    bufp->fullIData(oldp+719,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_313_imag),32);
    bufp->fullIData(oldp+720,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_314_real),32);
    bufp->fullIData(oldp+721,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_314_imag),32);
    bufp->fullIData(oldp+722,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_315_real),32);
    bufp->fullIData(oldp+723,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_315_imag),32);
    bufp->fullIData(oldp+724,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_316_real),32);
    bufp->fullIData(oldp+725,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_316_imag),32);
    bufp->fullIData(oldp+726,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_317_real),32);
    bufp->fullIData(oldp+727,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_317_imag),32);
    bufp->fullIData(oldp+728,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_318_real),32);
    bufp->fullIData(oldp+729,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_318_imag),32);
    bufp->fullIData(oldp+730,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_319_real),32);
    bufp->fullIData(oldp+731,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_319_imag),32);
    bufp->fullIData(oldp+732,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_320_real),32);
    bufp->fullIData(oldp+733,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_320_imag),32);
    bufp->fullIData(oldp+734,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_321_real),32);
    bufp->fullIData(oldp+735,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_321_imag),32);
    bufp->fullIData(oldp+736,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_322_real),32);
    bufp->fullIData(oldp+737,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_322_imag),32);
    bufp->fullIData(oldp+738,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_323_real),32);
    bufp->fullIData(oldp+739,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_323_imag),32);
    bufp->fullIData(oldp+740,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_324_real),32);
    bufp->fullIData(oldp+741,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_324_imag),32);
    bufp->fullIData(oldp+742,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_325_real),32);
    bufp->fullIData(oldp+743,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_325_imag),32);
    bufp->fullIData(oldp+744,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_326_real),32);
    bufp->fullIData(oldp+745,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_326_imag),32);
    bufp->fullIData(oldp+746,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_327_real),32);
    bufp->fullIData(oldp+747,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_327_imag),32);
    bufp->fullIData(oldp+748,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_328_real),32);
    bufp->fullIData(oldp+749,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_328_imag),32);
    bufp->fullIData(oldp+750,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_329_real),32);
    bufp->fullIData(oldp+751,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_329_imag),32);
    bufp->fullIData(oldp+752,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_330_real),32);
    bufp->fullIData(oldp+753,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_330_imag),32);
    bufp->fullIData(oldp+754,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_331_real),32);
    bufp->fullIData(oldp+755,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_331_imag),32);
    bufp->fullIData(oldp+756,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_332_real),32);
    bufp->fullIData(oldp+757,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_332_imag),32);
    bufp->fullIData(oldp+758,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_333_real),32);
    bufp->fullIData(oldp+759,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_333_imag),32);
    bufp->fullIData(oldp+760,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_334_real),32);
    bufp->fullIData(oldp+761,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_334_imag),32);
    bufp->fullIData(oldp+762,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_335_real),32);
    bufp->fullIData(oldp+763,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_335_imag),32);
    bufp->fullIData(oldp+764,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_336_real),32);
    bufp->fullIData(oldp+765,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_336_imag),32);
    bufp->fullIData(oldp+766,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_337_real),32);
    bufp->fullIData(oldp+767,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_337_imag),32);
    bufp->fullIData(oldp+768,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_338_real),32);
    bufp->fullIData(oldp+769,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_338_imag),32);
    bufp->fullIData(oldp+770,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_339_real),32);
    bufp->fullIData(oldp+771,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_339_imag),32);
    bufp->fullIData(oldp+772,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_340_real),32);
    bufp->fullIData(oldp+773,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_340_imag),32);
    bufp->fullIData(oldp+774,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_341_real),32);
    bufp->fullIData(oldp+775,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_341_imag),32);
    bufp->fullIData(oldp+776,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_342_real),32);
    bufp->fullIData(oldp+777,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_342_imag),32);
    bufp->fullIData(oldp+778,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_343_real),32);
    bufp->fullIData(oldp+779,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_343_imag),32);
    bufp->fullIData(oldp+780,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_344_real),32);
    bufp->fullIData(oldp+781,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_344_imag),32);
    bufp->fullIData(oldp+782,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_345_real),32);
    bufp->fullIData(oldp+783,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_345_imag),32);
    bufp->fullIData(oldp+784,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_346_real),32);
    bufp->fullIData(oldp+785,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_346_imag),32);
    bufp->fullIData(oldp+786,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_347_real),32);
    bufp->fullIData(oldp+787,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_347_imag),32);
    bufp->fullIData(oldp+788,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_348_real),32);
    bufp->fullIData(oldp+789,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_348_imag),32);
    bufp->fullIData(oldp+790,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_349_real),32);
    bufp->fullIData(oldp+791,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_349_imag),32);
    bufp->fullIData(oldp+792,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_350_real),32);
    bufp->fullIData(oldp+793,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_350_imag),32);
    bufp->fullIData(oldp+794,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_351_real),32);
    bufp->fullIData(oldp+795,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_351_imag),32);
    bufp->fullIData(oldp+796,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_352_real),32);
    bufp->fullIData(oldp+797,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_352_imag),32);
    bufp->fullIData(oldp+798,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_353_real),32);
    bufp->fullIData(oldp+799,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_353_imag),32);
    bufp->fullIData(oldp+800,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_354_real),32);
    bufp->fullIData(oldp+801,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_354_imag),32);
    bufp->fullIData(oldp+802,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_355_real),32);
    bufp->fullIData(oldp+803,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_355_imag),32);
    bufp->fullIData(oldp+804,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_356_real),32);
    bufp->fullIData(oldp+805,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_356_imag),32);
    bufp->fullIData(oldp+806,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_357_real),32);
    bufp->fullIData(oldp+807,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_357_imag),32);
    bufp->fullIData(oldp+808,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_358_real),32);
    bufp->fullIData(oldp+809,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_358_imag),32);
    bufp->fullIData(oldp+810,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_359_real),32);
    bufp->fullIData(oldp+811,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_359_imag),32);
    bufp->fullIData(oldp+812,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_360_real),32);
    bufp->fullIData(oldp+813,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_360_imag),32);
    bufp->fullIData(oldp+814,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_361_real),32);
    bufp->fullIData(oldp+815,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_361_imag),32);
    bufp->fullIData(oldp+816,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_362_real),32);
    bufp->fullIData(oldp+817,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_362_imag),32);
    bufp->fullIData(oldp+818,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_363_real),32);
    bufp->fullIData(oldp+819,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_363_imag),32);
    bufp->fullIData(oldp+820,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_364_real),32);
    bufp->fullIData(oldp+821,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_364_imag),32);
    bufp->fullIData(oldp+822,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_365_real),32);
    bufp->fullIData(oldp+823,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_365_imag),32);
    bufp->fullIData(oldp+824,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_366_real),32);
    bufp->fullIData(oldp+825,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_366_imag),32);
    bufp->fullIData(oldp+826,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_367_real),32);
    bufp->fullIData(oldp+827,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_367_imag),32);
    bufp->fullIData(oldp+828,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_368_real),32);
    bufp->fullIData(oldp+829,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_368_imag),32);
    bufp->fullIData(oldp+830,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_369_real),32);
    bufp->fullIData(oldp+831,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_369_imag),32);
    bufp->fullIData(oldp+832,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_370_real),32);
    bufp->fullIData(oldp+833,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_370_imag),32);
    bufp->fullIData(oldp+834,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_371_real),32);
    bufp->fullIData(oldp+835,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_371_imag),32);
    bufp->fullIData(oldp+836,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_372_real),32);
    bufp->fullIData(oldp+837,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_372_imag),32);
    bufp->fullIData(oldp+838,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_373_real),32);
    bufp->fullIData(oldp+839,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_373_imag),32);
    bufp->fullIData(oldp+840,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_374_real),32);
    bufp->fullIData(oldp+841,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_374_imag),32);
    bufp->fullIData(oldp+842,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_375_real),32);
    bufp->fullIData(oldp+843,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_375_imag),32);
    bufp->fullIData(oldp+844,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_376_real),32);
    bufp->fullIData(oldp+845,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_376_imag),32);
    bufp->fullIData(oldp+846,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_377_real),32);
    bufp->fullIData(oldp+847,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_377_imag),32);
    bufp->fullIData(oldp+848,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_378_real),32);
    bufp->fullIData(oldp+849,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_378_imag),32);
    bufp->fullIData(oldp+850,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_379_real),32);
    bufp->fullIData(oldp+851,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_379_imag),32);
    bufp->fullIData(oldp+852,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_380_real),32);
    bufp->fullIData(oldp+853,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_380_imag),32);
    bufp->fullIData(oldp+854,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_381_real),32);
    bufp->fullIData(oldp+855,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_381_imag),32);
    bufp->fullIData(oldp+856,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_382_real),32);
    bufp->fullIData(oldp+857,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_382_imag),32);
    bufp->fullIData(oldp+858,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_real),32);
    bufp->fullIData(oldp+859,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_383_imag),32);
    bufp->fullIData(oldp+860,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_384_real),32);
    bufp->fullIData(oldp+861,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_384_imag),32);
    bufp->fullIData(oldp+862,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_385_real),32);
    bufp->fullIData(oldp+863,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_385_imag),32);
    bufp->fullIData(oldp+864,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_386_real),32);
    bufp->fullIData(oldp+865,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_386_imag),32);
    bufp->fullIData(oldp+866,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_387_real),32);
    bufp->fullIData(oldp+867,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_387_imag),32);
    bufp->fullIData(oldp+868,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_388_real),32);
    bufp->fullIData(oldp+869,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_388_imag),32);
    bufp->fullIData(oldp+870,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_389_real),32);
    bufp->fullIData(oldp+871,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_389_imag),32);
    bufp->fullIData(oldp+872,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_390_real),32);
    bufp->fullIData(oldp+873,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_390_imag),32);
    bufp->fullIData(oldp+874,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_391_real),32);
    bufp->fullIData(oldp+875,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_391_imag),32);
    bufp->fullIData(oldp+876,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_392_real),32);
    bufp->fullIData(oldp+877,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_392_imag),32);
    bufp->fullIData(oldp+878,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_393_real),32);
    bufp->fullIData(oldp+879,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_393_imag),32);
    bufp->fullIData(oldp+880,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_394_real),32);
    bufp->fullIData(oldp+881,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_394_imag),32);
    bufp->fullIData(oldp+882,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_395_real),32);
    bufp->fullIData(oldp+883,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_395_imag),32);
    bufp->fullIData(oldp+884,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_396_real),32);
    bufp->fullIData(oldp+885,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_396_imag),32);
    bufp->fullIData(oldp+886,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_397_real),32);
    bufp->fullIData(oldp+887,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_397_imag),32);
    bufp->fullIData(oldp+888,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_398_real),32);
    bufp->fullIData(oldp+889,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_398_imag),32);
    bufp->fullIData(oldp+890,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_399_real),32);
    bufp->fullIData(oldp+891,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_399_imag),32);
    bufp->fullIData(oldp+892,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_400_real),32);
    bufp->fullIData(oldp+893,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_400_imag),32);
    bufp->fullIData(oldp+894,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_401_real),32);
    bufp->fullIData(oldp+895,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_401_imag),32);
    bufp->fullIData(oldp+896,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_402_real),32);
    bufp->fullIData(oldp+897,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_402_imag),32);
    bufp->fullIData(oldp+898,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_403_real),32);
    bufp->fullIData(oldp+899,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_403_imag),32);
    bufp->fullIData(oldp+900,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_404_real),32);
    bufp->fullIData(oldp+901,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_404_imag),32);
    bufp->fullIData(oldp+902,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_405_real),32);
    bufp->fullIData(oldp+903,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_405_imag),32);
    bufp->fullIData(oldp+904,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_406_real),32);
    bufp->fullIData(oldp+905,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_406_imag),32);
    bufp->fullIData(oldp+906,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_407_real),32);
    bufp->fullIData(oldp+907,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_407_imag),32);
    bufp->fullIData(oldp+908,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_408_real),32);
    bufp->fullIData(oldp+909,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_408_imag),32);
    bufp->fullIData(oldp+910,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_409_real),32);
    bufp->fullIData(oldp+911,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_409_imag),32);
    bufp->fullIData(oldp+912,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_410_real),32);
    bufp->fullIData(oldp+913,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_410_imag),32);
    bufp->fullIData(oldp+914,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_411_real),32);
    bufp->fullIData(oldp+915,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_411_imag),32);
    bufp->fullIData(oldp+916,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_412_real),32);
    bufp->fullIData(oldp+917,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_412_imag),32);
    bufp->fullIData(oldp+918,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_413_real),32);
    bufp->fullIData(oldp+919,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_413_imag),32);
    bufp->fullIData(oldp+920,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_414_real),32);
    bufp->fullIData(oldp+921,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_414_imag),32);
    bufp->fullIData(oldp+922,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_415_real),32);
    bufp->fullIData(oldp+923,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_415_imag),32);
    bufp->fullIData(oldp+924,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_416_real),32);
    bufp->fullIData(oldp+925,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_416_imag),32);
    bufp->fullIData(oldp+926,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_417_real),32);
    bufp->fullIData(oldp+927,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_417_imag),32);
    bufp->fullIData(oldp+928,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_418_real),32);
    bufp->fullIData(oldp+929,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_418_imag),32);
    bufp->fullIData(oldp+930,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_419_real),32);
    bufp->fullIData(oldp+931,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_419_imag),32);
    bufp->fullIData(oldp+932,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_420_real),32);
    bufp->fullIData(oldp+933,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_420_imag),32);
    bufp->fullIData(oldp+934,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_421_real),32);
    bufp->fullIData(oldp+935,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_421_imag),32);
    bufp->fullIData(oldp+936,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_422_real),32);
    bufp->fullIData(oldp+937,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_422_imag),32);
    bufp->fullIData(oldp+938,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_423_real),32);
    bufp->fullIData(oldp+939,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_423_imag),32);
    bufp->fullIData(oldp+940,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_424_real),32);
    bufp->fullIData(oldp+941,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_424_imag),32);
    bufp->fullIData(oldp+942,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_425_real),32);
    bufp->fullIData(oldp+943,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_425_imag),32);
    bufp->fullIData(oldp+944,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_426_real),32);
    bufp->fullIData(oldp+945,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_426_imag),32);
    bufp->fullIData(oldp+946,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_427_real),32);
    bufp->fullIData(oldp+947,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_427_imag),32);
    bufp->fullIData(oldp+948,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_428_real),32);
    bufp->fullIData(oldp+949,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_428_imag),32);
    bufp->fullIData(oldp+950,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_429_real),32);
    bufp->fullIData(oldp+951,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_429_imag),32);
    bufp->fullIData(oldp+952,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_430_real),32);
    bufp->fullIData(oldp+953,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_430_imag),32);
    bufp->fullIData(oldp+954,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_431_real),32);
    bufp->fullIData(oldp+955,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_431_imag),32);
    bufp->fullIData(oldp+956,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_432_real),32);
    bufp->fullIData(oldp+957,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_432_imag),32);
    bufp->fullIData(oldp+958,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_433_real),32);
    bufp->fullIData(oldp+959,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_433_imag),32);
    bufp->fullIData(oldp+960,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_434_real),32);
    bufp->fullIData(oldp+961,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_434_imag),32);
    bufp->fullIData(oldp+962,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_435_real),32);
    bufp->fullIData(oldp+963,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_435_imag),32);
    bufp->fullIData(oldp+964,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_436_real),32);
    bufp->fullIData(oldp+965,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_436_imag),32);
    bufp->fullIData(oldp+966,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_437_real),32);
    bufp->fullIData(oldp+967,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_437_imag),32);
    bufp->fullIData(oldp+968,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_438_real),32);
    bufp->fullIData(oldp+969,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_438_imag),32);
    bufp->fullIData(oldp+970,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_439_real),32);
    bufp->fullIData(oldp+971,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_439_imag),32);
    bufp->fullIData(oldp+972,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_440_real),32);
    bufp->fullIData(oldp+973,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_440_imag),32);
    bufp->fullIData(oldp+974,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_441_real),32);
    bufp->fullIData(oldp+975,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_441_imag),32);
    bufp->fullIData(oldp+976,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_442_real),32);
    bufp->fullIData(oldp+977,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_442_imag),32);
    bufp->fullIData(oldp+978,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_443_real),32);
    bufp->fullIData(oldp+979,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_443_imag),32);
    bufp->fullIData(oldp+980,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_444_real),32);
    bufp->fullIData(oldp+981,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_444_imag),32);
    bufp->fullIData(oldp+982,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_445_real),32);
    bufp->fullIData(oldp+983,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_445_imag),32);
    bufp->fullIData(oldp+984,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_446_real),32);
    bufp->fullIData(oldp+985,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_446_imag),32);
    bufp->fullIData(oldp+986,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_447_real),32);
    bufp->fullIData(oldp+987,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_447_imag),32);
    bufp->fullIData(oldp+988,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_448_real),32);
    bufp->fullIData(oldp+989,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_448_imag),32);
    bufp->fullIData(oldp+990,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_449_real),32);
    bufp->fullIData(oldp+991,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_449_imag),32);
    bufp->fullIData(oldp+992,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_450_real),32);
    bufp->fullIData(oldp+993,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_450_imag),32);
    bufp->fullIData(oldp+994,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_451_real),32);
    bufp->fullIData(oldp+995,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_451_imag),32);
    bufp->fullIData(oldp+996,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_452_real),32);
    bufp->fullIData(oldp+997,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_452_imag),32);
    bufp->fullIData(oldp+998,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_453_real),32);
    bufp->fullIData(oldp+999,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_453_imag),32);
    bufp->fullIData(oldp+1000,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_454_real),32);
    bufp->fullIData(oldp+1001,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_454_imag),32);
    bufp->fullIData(oldp+1002,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_455_real),32);
    bufp->fullIData(oldp+1003,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_455_imag),32);
    bufp->fullIData(oldp+1004,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_456_real),32);
    bufp->fullIData(oldp+1005,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_456_imag),32);
    bufp->fullIData(oldp+1006,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_457_real),32);
    bufp->fullIData(oldp+1007,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_457_imag),32);
    bufp->fullIData(oldp+1008,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_458_real),32);
    bufp->fullIData(oldp+1009,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_458_imag),32);
    bufp->fullIData(oldp+1010,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_459_real),32);
    bufp->fullIData(oldp+1011,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_459_imag),32);
    bufp->fullIData(oldp+1012,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_460_real),32);
    bufp->fullIData(oldp+1013,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_460_imag),32);
    bufp->fullIData(oldp+1014,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_461_real),32);
    bufp->fullIData(oldp+1015,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_461_imag),32);
    bufp->fullIData(oldp+1016,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_462_real),32);
    bufp->fullIData(oldp+1017,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_462_imag),32);
    bufp->fullIData(oldp+1018,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_463_real),32);
    bufp->fullIData(oldp+1019,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_463_imag),32);
    bufp->fullIData(oldp+1020,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_464_real),32);
    bufp->fullIData(oldp+1021,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_464_imag),32);
    bufp->fullIData(oldp+1022,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_465_real),32);
    bufp->fullIData(oldp+1023,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_465_imag),32);
    bufp->fullIData(oldp+1024,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_466_real),32);
    bufp->fullIData(oldp+1025,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_466_imag),32);
    bufp->fullIData(oldp+1026,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_467_real),32);
    bufp->fullIData(oldp+1027,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_467_imag),32);
    bufp->fullIData(oldp+1028,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_468_real),32);
    bufp->fullIData(oldp+1029,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_468_imag),32);
    bufp->fullIData(oldp+1030,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_469_real),32);
    bufp->fullIData(oldp+1031,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_469_imag),32);
    bufp->fullIData(oldp+1032,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_470_real),32);
    bufp->fullIData(oldp+1033,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_470_imag),32);
    bufp->fullIData(oldp+1034,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_471_real),32);
    bufp->fullIData(oldp+1035,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_471_imag),32);
    bufp->fullIData(oldp+1036,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_472_real),32);
    bufp->fullIData(oldp+1037,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_472_imag),32);
    bufp->fullIData(oldp+1038,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_473_real),32);
    bufp->fullIData(oldp+1039,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_473_imag),32);
    bufp->fullIData(oldp+1040,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_474_real),32);
    bufp->fullIData(oldp+1041,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_474_imag),32);
    bufp->fullIData(oldp+1042,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_475_real),32);
    bufp->fullIData(oldp+1043,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_475_imag),32);
    bufp->fullIData(oldp+1044,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_476_real),32);
    bufp->fullIData(oldp+1045,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_476_imag),32);
    bufp->fullIData(oldp+1046,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_477_real),32);
    bufp->fullIData(oldp+1047,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_477_imag),32);
    bufp->fullIData(oldp+1048,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_478_real),32);
    bufp->fullIData(oldp+1049,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_478_imag),32);
    bufp->fullIData(oldp+1050,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_479_real),32);
    bufp->fullIData(oldp+1051,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_479_imag),32);
    bufp->fullIData(oldp+1052,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_480_real),32);
    bufp->fullIData(oldp+1053,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_480_imag),32);
    bufp->fullIData(oldp+1054,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_481_real),32);
    bufp->fullIData(oldp+1055,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_481_imag),32);
    bufp->fullIData(oldp+1056,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_482_real),32);
    bufp->fullIData(oldp+1057,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_482_imag),32);
    bufp->fullIData(oldp+1058,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_483_real),32);
    bufp->fullIData(oldp+1059,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_483_imag),32);
    bufp->fullIData(oldp+1060,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_484_real),32);
    bufp->fullIData(oldp+1061,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_484_imag),32);
    bufp->fullIData(oldp+1062,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_485_real),32);
    bufp->fullIData(oldp+1063,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_485_imag),32);
    bufp->fullIData(oldp+1064,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_486_real),32);
    bufp->fullIData(oldp+1065,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_486_imag),32);
    bufp->fullIData(oldp+1066,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_487_real),32);
    bufp->fullIData(oldp+1067,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_487_imag),32);
    bufp->fullIData(oldp+1068,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_488_real),32);
    bufp->fullIData(oldp+1069,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_488_imag),32);
    bufp->fullIData(oldp+1070,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_489_real),32);
    bufp->fullIData(oldp+1071,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_489_imag),32);
    bufp->fullIData(oldp+1072,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_490_real),32);
    bufp->fullIData(oldp+1073,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_490_imag),32);
    bufp->fullIData(oldp+1074,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_491_real),32);
    bufp->fullIData(oldp+1075,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_491_imag),32);
    bufp->fullIData(oldp+1076,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_492_real),32);
    bufp->fullIData(oldp+1077,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_492_imag),32);
    bufp->fullIData(oldp+1078,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_493_real),32);
    bufp->fullIData(oldp+1079,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_493_imag),32);
    bufp->fullIData(oldp+1080,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_494_real),32);
    bufp->fullIData(oldp+1081,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_494_imag),32);
    bufp->fullIData(oldp+1082,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_495_real),32);
    bufp->fullIData(oldp+1083,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_495_imag),32);
    bufp->fullIData(oldp+1084,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_496_real),32);
    bufp->fullIData(oldp+1085,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_496_imag),32);
    bufp->fullIData(oldp+1086,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_497_real),32);
    bufp->fullIData(oldp+1087,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_497_imag),32);
    bufp->fullIData(oldp+1088,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_498_real),32);
    bufp->fullIData(oldp+1089,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_498_imag),32);
    bufp->fullIData(oldp+1090,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_499_real),32);
    bufp->fullIData(oldp+1091,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_499_imag),32);
    bufp->fullIData(oldp+1092,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_500_real),32);
    bufp->fullIData(oldp+1093,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_500_imag),32);
    bufp->fullIData(oldp+1094,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_501_real),32);
    bufp->fullIData(oldp+1095,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_501_imag),32);
    bufp->fullIData(oldp+1096,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_502_real),32);
    bufp->fullIData(oldp+1097,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_502_imag),32);
    bufp->fullIData(oldp+1098,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_503_real),32);
    bufp->fullIData(oldp+1099,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_503_imag),32);
    bufp->fullIData(oldp+1100,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_504_real),32);
    bufp->fullIData(oldp+1101,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_504_imag),32);
    bufp->fullIData(oldp+1102,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_505_real),32);
    bufp->fullIData(oldp+1103,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_505_imag),32);
    bufp->fullIData(oldp+1104,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_506_real),32);
    bufp->fullIData(oldp+1105,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_506_imag),32);
    bufp->fullIData(oldp+1106,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_507_real),32);
    bufp->fullIData(oldp+1107,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_507_imag),32);
    bufp->fullIData(oldp+1108,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_508_real),32);
    bufp->fullIData(oldp+1109,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_508_imag),32);
    bufp->fullIData(oldp+1110,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_509_real),32);
    bufp->fullIData(oldp+1111,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_509_imag),32);
    bufp->fullIData(oldp+1112,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_510_real),32);
    bufp->fullIData(oldp+1113,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_510_imag),32);
    bufp->fullIData(oldp+1114,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_real),32);
    bufp->fullIData(oldp+1115,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_511_imag),32);
    bufp->fullIData(oldp+1116,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_512_real),32);
    bufp->fullIData(oldp+1117,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_512_imag),32);
    bufp->fullIData(oldp+1118,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_513_real),32);
    bufp->fullIData(oldp+1119,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_513_imag),32);
    bufp->fullIData(oldp+1120,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_514_real),32);
    bufp->fullIData(oldp+1121,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_514_imag),32);
    bufp->fullIData(oldp+1122,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_515_real),32);
    bufp->fullIData(oldp+1123,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_515_imag),32);
    bufp->fullIData(oldp+1124,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_516_real),32);
    bufp->fullIData(oldp+1125,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_516_imag),32);
    bufp->fullIData(oldp+1126,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_517_real),32);
    bufp->fullIData(oldp+1127,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_517_imag),32);
    bufp->fullIData(oldp+1128,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_518_real),32);
    bufp->fullIData(oldp+1129,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_518_imag),32);
    bufp->fullIData(oldp+1130,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_519_real),32);
    bufp->fullIData(oldp+1131,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_519_imag),32);
    bufp->fullIData(oldp+1132,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_520_real),32);
    bufp->fullIData(oldp+1133,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_520_imag),32);
    bufp->fullIData(oldp+1134,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_521_real),32);
    bufp->fullIData(oldp+1135,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_521_imag),32);
    bufp->fullIData(oldp+1136,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_522_real),32);
    bufp->fullIData(oldp+1137,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_522_imag),32);
    bufp->fullIData(oldp+1138,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_523_real),32);
    bufp->fullIData(oldp+1139,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_523_imag),32);
    bufp->fullIData(oldp+1140,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_524_real),32);
    bufp->fullIData(oldp+1141,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_524_imag),32);
    bufp->fullIData(oldp+1142,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_525_real),32);
    bufp->fullIData(oldp+1143,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_525_imag),32);
    bufp->fullIData(oldp+1144,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_526_real),32);
    bufp->fullIData(oldp+1145,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_526_imag),32);
    bufp->fullIData(oldp+1146,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_527_real),32);
    bufp->fullIData(oldp+1147,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_527_imag),32);
    bufp->fullIData(oldp+1148,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_528_real),32);
    bufp->fullIData(oldp+1149,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_528_imag),32);
    bufp->fullIData(oldp+1150,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_529_real),32);
    bufp->fullIData(oldp+1151,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_529_imag),32);
    bufp->fullIData(oldp+1152,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_530_real),32);
    bufp->fullIData(oldp+1153,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_530_imag),32);
    bufp->fullIData(oldp+1154,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_531_real),32);
    bufp->fullIData(oldp+1155,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_531_imag),32);
    bufp->fullIData(oldp+1156,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_532_real),32);
    bufp->fullIData(oldp+1157,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_532_imag),32);
    bufp->fullIData(oldp+1158,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_533_real),32);
    bufp->fullIData(oldp+1159,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_533_imag),32);
    bufp->fullIData(oldp+1160,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_534_real),32);
    bufp->fullIData(oldp+1161,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_534_imag),32);
    bufp->fullIData(oldp+1162,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_535_real),32);
    bufp->fullIData(oldp+1163,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_535_imag),32);
    bufp->fullIData(oldp+1164,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_536_real),32);
    bufp->fullIData(oldp+1165,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_536_imag),32);
    bufp->fullIData(oldp+1166,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_537_real),32);
    bufp->fullIData(oldp+1167,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_537_imag),32);
    bufp->fullIData(oldp+1168,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_538_real),32);
    bufp->fullIData(oldp+1169,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_538_imag),32);
    bufp->fullIData(oldp+1170,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_539_real),32);
    bufp->fullIData(oldp+1171,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_539_imag),32);
    bufp->fullIData(oldp+1172,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_540_real),32);
    bufp->fullIData(oldp+1173,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_540_imag),32);
    bufp->fullIData(oldp+1174,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_541_real),32);
    bufp->fullIData(oldp+1175,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_541_imag),32);
    bufp->fullIData(oldp+1176,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_542_real),32);
    bufp->fullIData(oldp+1177,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_542_imag),32);
    bufp->fullIData(oldp+1178,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_543_real),32);
    bufp->fullIData(oldp+1179,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_543_imag),32);
    bufp->fullIData(oldp+1180,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_544_real),32);
    bufp->fullIData(oldp+1181,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_544_imag),32);
    bufp->fullIData(oldp+1182,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_545_real),32);
    bufp->fullIData(oldp+1183,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_545_imag),32);
    bufp->fullIData(oldp+1184,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_546_real),32);
    bufp->fullIData(oldp+1185,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_546_imag),32);
    bufp->fullIData(oldp+1186,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_547_real),32);
    bufp->fullIData(oldp+1187,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_547_imag),32);
    bufp->fullIData(oldp+1188,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_548_real),32);
    bufp->fullIData(oldp+1189,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_548_imag),32);
    bufp->fullIData(oldp+1190,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_549_real),32);
    bufp->fullIData(oldp+1191,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_549_imag),32);
    bufp->fullIData(oldp+1192,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_550_real),32);
    bufp->fullIData(oldp+1193,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_550_imag),32);
    bufp->fullIData(oldp+1194,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_551_real),32);
    bufp->fullIData(oldp+1195,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_551_imag),32);
    bufp->fullIData(oldp+1196,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_552_real),32);
    bufp->fullIData(oldp+1197,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_552_imag),32);
    bufp->fullIData(oldp+1198,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_553_real),32);
    bufp->fullIData(oldp+1199,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_553_imag),32);
    bufp->fullIData(oldp+1200,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_554_real),32);
    bufp->fullIData(oldp+1201,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_554_imag),32);
    bufp->fullIData(oldp+1202,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_555_real),32);
    bufp->fullIData(oldp+1203,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_555_imag),32);
    bufp->fullIData(oldp+1204,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_556_real),32);
    bufp->fullIData(oldp+1205,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_556_imag),32);
    bufp->fullIData(oldp+1206,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_557_real),32);
    bufp->fullIData(oldp+1207,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_557_imag),32);
    bufp->fullIData(oldp+1208,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_558_real),32);
    bufp->fullIData(oldp+1209,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_558_imag),32);
    bufp->fullIData(oldp+1210,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_559_real),32);
    bufp->fullIData(oldp+1211,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_559_imag),32);
    bufp->fullIData(oldp+1212,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_560_real),32);
    bufp->fullIData(oldp+1213,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_560_imag),32);
    bufp->fullIData(oldp+1214,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_561_real),32);
    bufp->fullIData(oldp+1215,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_561_imag),32);
    bufp->fullIData(oldp+1216,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_562_real),32);
    bufp->fullIData(oldp+1217,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_562_imag),32);
    bufp->fullIData(oldp+1218,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_563_real),32);
    bufp->fullIData(oldp+1219,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_563_imag),32);
    bufp->fullIData(oldp+1220,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_564_real),32);
    bufp->fullIData(oldp+1221,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_564_imag),32);
    bufp->fullIData(oldp+1222,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_565_real),32);
    bufp->fullIData(oldp+1223,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_565_imag),32);
    bufp->fullIData(oldp+1224,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_566_real),32);
    bufp->fullIData(oldp+1225,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_566_imag),32);
    bufp->fullIData(oldp+1226,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_567_real),32);
    bufp->fullIData(oldp+1227,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_567_imag),32);
    bufp->fullIData(oldp+1228,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_568_real),32);
    bufp->fullIData(oldp+1229,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_568_imag),32);
    bufp->fullIData(oldp+1230,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_569_real),32);
    bufp->fullIData(oldp+1231,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_569_imag),32);
    bufp->fullIData(oldp+1232,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_570_real),32);
    bufp->fullIData(oldp+1233,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_570_imag),32);
    bufp->fullIData(oldp+1234,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_571_real),32);
    bufp->fullIData(oldp+1235,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_571_imag),32);
    bufp->fullIData(oldp+1236,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_572_real),32);
    bufp->fullIData(oldp+1237,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_572_imag),32);
    bufp->fullIData(oldp+1238,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_573_real),32);
    bufp->fullIData(oldp+1239,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_573_imag),32);
    bufp->fullIData(oldp+1240,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_574_real),32);
    bufp->fullIData(oldp+1241,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_574_imag),32);
    bufp->fullIData(oldp+1242,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_real),32);
    bufp->fullIData(oldp+1243,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_575_imag),32);
    bufp->fullIData(oldp+1244,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_576_real),32);
    bufp->fullIData(oldp+1245,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_576_imag),32);
    bufp->fullIData(oldp+1246,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_577_real),32);
    bufp->fullIData(oldp+1247,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_577_imag),32);
    bufp->fullIData(oldp+1248,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_578_real),32);
    bufp->fullIData(oldp+1249,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_578_imag),32);
    bufp->fullIData(oldp+1250,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_579_real),32);
    bufp->fullIData(oldp+1251,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_579_imag),32);
    bufp->fullIData(oldp+1252,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_580_real),32);
    bufp->fullIData(oldp+1253,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_580_imag),32);
    bufp->fullIData(oldp+1254,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_581_real),32);
    bufp->fullIData(oldp+1255,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_581_imag),32);
    bufp->fullIData(oldp+1256,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_582_real),32);
    bufp->fullIData(oldp+1257,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_582_imag),32);
    bufp->fullIData(oldp+1258,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_583_real),32);
    bufp->fullIData(oldp+1259,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_583_imag),32);
    bufp->fullIData(oldp+1260,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_584_real),32);
    bufp->fullIData(oldp+1261,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_584_imag),32);
    bufp->fullIData(oldp+1262,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_585_real),32);
    bufp->fullIData(oldp+1263,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_585_imag),32);
    bufp->fullIData(oldp+1264,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_586_real),32);
    bufp->fullIData(oldp+1265,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_586_imag),32);
    bufp->fullIData(oldp+1266,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_587_real),32);
    bufp->fullIData(oldp+1267,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_587_imag),32);
    bufp->fullIData(oldp+1268,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_588_real),32);
    bufp->fullIData(oldp+1269,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_588_imag),32);
    bufp->fullIData(oldp+1270,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_589_real),32);
    bufp->fullIData(oldp+1271,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_589_imag),32);
    bufp->fullIData(oldp+1272,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_590_real),32);
    bufp->fullIData(oldp+1273,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_590_imag),32);
    bufp->fullIData(oldp+1274,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_591_real),32);
    bufp->fullIData(oldp+1275,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_591_imag),32);
    bufp->fullIData(oldp+1276,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_592_real),32);
    bufp->fullIData(oldp+1277,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_592_imag),32);
    bufp->fullIData(oldp+1278,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_593_real),32);
    bufp->fullIData(oldp+1279,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_593_imag),32);
    bufp->fullIData(oldp+1280,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_594_real),32);
    bufp->fullIData(oldp+1281,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_594_imag),32);
    bufp->fullIData(oldp+1282,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_595_real),32);
    bufp->fullIData(oldp+1283,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_595_imag),32);
    bufp->fullIData(oldp+1284,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_596_real),32);
    bufp->fullIData(oldp+1285,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_596_imag),32);
    bufp->fullIData(oldp+1286,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_597_real),32);
    bufp->fullIData(oldp+1287,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_597_imag),32);
    bufp->fullIData(oldp+1288,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_598_real),32);
    bufp->fullIData(oldp+1289,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_598_imag),32);
    bufp->fullIData(oldp+1290,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_599_real),32);
    bufp->fullIData(oldp+1291,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_599_imag),32);
    bufp->fullIData(oldp+1292,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_600_real),32);
    bufp->fullIData(oldp+1293,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_600_imag),32);
    bufp->fullIData(oldp+1294,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_601_real),32);
    bufp->fullIData(oldp+1295,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_601_imag),32);
    bufp->fullIData(oldp+1296,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_602_real),32);
    bufp->fullIData(oldp+1297,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_602_imag),32);
    bufp->fullIData(oldp+1298,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_603_real),32);
    bufp->fullIData(oldp+1299,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_603_imag),32);
    bufp->fullIData(oldp+1300,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_604_real),32);
    bufp->fullIData(oldp+1301,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_604_imag),32);
    bufp->fullIData(oldp+1302,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_605_real),32);
    bufp->fullIData(oldp+1303,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_605_imag),32);
    bufp->fullIData(oldp+1304,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_606_real),32);
    bufp->fullIData(oldp+1305,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_606_imag),32);
    bufp->fullIData(oldp+1306,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_607_real),32);
    bufp->fullIData(oldp+1307,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_607_imag),32);
    bufp->fullIData(oldp+1308,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_608_real),32);
    bufp->fullIData(oldp+1309,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_608_imag),32);
    bufp->fullIData(oldp+1310,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_609_real),32);
    bufp->fullIData(oldp+1311,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_609_imag),32);
    bufp->fullIData(oldp+1312,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_610_real),32);
    bufp->fullIData(oldp+1313,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_610_imag),32);
    bufp->fullIData(oldp+1314,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_611_real),32);
    bufp->fullIData(oldp+1315,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_611_imag),32);
    bufp->fullIData(oldp+1316,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_612_real),32);
    bufp->fullIData(oldp+1317,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_612_imag),32);
    bufp->fullIData(oldp+1318,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_613_real),32);
    bufp->fullIData(oldp+1319,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_613_imag),32);
    bufp->fullIData(oldp+1320,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_614_real),32);
    bufp->fullIData(oldp+1321,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_614_imag),32);
    bufp->fullIData(oldp+1322,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_615_real),32);
    bufp->fullIData(oldp+1323,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_615_imag),32);
    bufp->fullIData(oldp+1324,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_616_real),32);
    bufp->fullIData(oldp+1325,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_616_imag),32);
    bufp->fullIData(oldp+1326,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_617_real),32);
    bufp->fullIData(oldp+1327,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_617_imag),32);
    bufp->fullIData(oldp+1328,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_618_real),32);
    bufp->fullIData(oldp+1329,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_618_imag),32);
    bufp->fullIData(oldp+1330,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_619_real),32);
    bufp->fullIData(oldp+1331,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_619_imag),32);
    bufp->fullIData(oldp+1332,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_620_real),32);
    bufp->fullIData(oldp+1333,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_620_imag),32);
    bufp->fullIData(oldp+1334,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_621_real),32);
    bufp->fullIData(oldp+1335,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_621_imag),32);
    bufp->fullIData(oldp+1336,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_622_real),32);
    bufp->fullIData(oldp+1337,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_622_imag),32);
    bufp->fullIData(oldp+1338,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_623_real),32);
    bufp->fullIData(oldp+1339,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_623_imag),32);
    bufp->fullIData(oldp+1340,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_624_real),32);
    bufp->fullIData(oldp+1341,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_624_imag),32);
    bufp->fullIData(oldp+1342,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_625_real),32);
    bufp->fullIData(oldp+1343,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_625_imag),32);
    bufp->fullIData(oldp+1344,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_626_real),32);
    bufp->fullIData(oldp+1345,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_626_imag),32);
    bufp->fullIData(oldp+1346,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_627_real),32);
    bufp->fullIData(oldp+1347,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_627_imag),32);
    bufp->fullIData(oldp+1348,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_628_real),32);
    bufp->fullIData(oldp+1349,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_628_imag),32);
    bufp->fullIData(oldp+1350,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_629_real),32);
    bufp->fullIData(oldp+1351,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_629_imag),32);
    bufp->fullIData(oldp+1352,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_630_real),32);
    bufp->fullIData(oldp+1353,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_630_imag),32);
    bufp->fullIData(oldp+1354,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_631_real),32);
    bufp->fullIData(oldp+1355,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_631_imag),32);
    bufp->fullIData(oldp+1356,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_632_real),32);
    bufp->fullIData(oldp+1357,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_632_imag),32);
    bufp->fullIData(oldp+1358,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_633_real),32);
    bufp->fullIData(oldp+1359,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_633_imag),32);
    bufp->fullIData(oldp+1360,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_634_real),32);
    bufp->fullIData(oldp+1361,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_634_imag),32);
    bufp->fullIData(oldp+1362,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_635_real),32);
    bufp->fullIData(oldp+1363,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_635_imag),32);
    bufp->fullIData(oldp+1364,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_636_real),32);
    bufp->fullIData(oldp+1365,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_636_imag),32);
    bufp->fullIData(oldp+1366,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_637_real),32);
    bufp->fullIData(oldp+1367,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_637_imag),32);
    bufp->fullIData(oldp+1368,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_638_real),32);
    bufp->fullIData(oldp+1369,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_638_imag),32);
    bufp->fullIData(oldp+1370,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_real),32);
    bufp->fullIData(oldp+1371,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_639_imag),32);
    bufp->fullIData(oldp+1372,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_640_real),32);
    bufp->fullIData(oldp+1373,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_640_imag),32);
    bufp->fullIData(oldp+1374,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_641_real),32);
    bufp->fullIData(oldp+1375,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_641_imag),32);
    bufp->fullIData(oldp+1376,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_642_real),32);
    bufp->fullIData(oldp+1377,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_642_imag),32);
    bufp->fullIData(oldp+1378,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_643_real),32);
    bufp->fullIData(oldp+1379,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_643_imag),32);
    bufp->fullIData(oldp+1380,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_644_real),32);
    bufp->fullIData(oldp+1381,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_644_imag),32);
    bufp->fullIData(oldp+1382,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_645_real),32);
    bufp->fullIData(oldp+1383,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_645_imag),32);
    bufp->fullIData(oldp+1384,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_646_real),32);
    bufp->fullIData(oldp+1385,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_646_imag),32);
    bufp->fullIData(oldp+1386,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_647_real),32);
    bufp->fullIData(oldp+1387,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_647_imag),32);
    bufp->fullIData(oldp+1388,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_648_real),32);
    bufp->fullIData(oldp+1389,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_648_imag),32);
    bufp->fullIData(oldp+1390,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_649_real),32);
    bufp->fullIData(oldp+1391,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_649_imag),32);
    bufp->fullIData(oldp+1392,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_650_real),32);
    bufp->fullIData(oldp+1393,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_650_imag),32);
    bufp->fullIData(oldp+1394,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_651_real),32);
    bufp->fullIData(oldp+1395,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_651_imag),32);
    bufp->fullIData(oldp+1396,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_652_real),32);
    bufp->fullIData(oldp+1397,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_652_imag),32);
    bufp->fullIData(oldp+1398,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_653_real),32);
    bufp->fullIData(oldp+1399,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_653_imag),32);
    bufp->fullIData(oldp+1400,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_654_real),32);
    bufp->fullIData(oldp+1401,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_654_imag),32);
    bufp->fullIData(oldp+1402,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_655_real),32);
    bufp->fullIData(oldp+1403,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_655_imag),32);
    bufp->fullIData(oldp+1404,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_656_real),32);
    bufp->fullIData(oldp+1405,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_656_imag),32);
    bufp->fullIData(oldp+1406,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_657_real),32);
    bufp->fullIData(oldp+1407,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_657_imag),32);
    bufp->fullIData(oldp+1408,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_658_real),32);
    bufp->fullIData(oldp+1409,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_658_imag),32);
    bufp->fullIData(oldp+1410,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_659_real),32);
    bufp->fullIData(oldp+1411,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_659_imag),32);
    bufp->fullIData(oldp+1412,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_660_real),32);
    bufp->fullIData(oldp+1413,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_660_imag),32);
    bufp->fullIData(oldp+1414,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_661_real),32);
    bufp->fullIData(oldp+1415,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_661_imag),32);
    bufp->fullIData(oldp+1416,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_662_real),32);
    bufp->fullIData(oldp+1417,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_662_imag),32);
    bufp->fullIData(oldp+1418,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_663_real),32);
    bufp->fullIData(oldp+1419,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_663_imag),32);
    bufp->fullIData(oldp+1420,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_664_real),32);
    bufp->fullIData(oldp+1421,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_664_imag),32);
    bufp->fullIData(oldp+1422,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_665_real),32);
    bufp->fullIData(oldp+1423,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_665_imag),32);
    bufp->fullIData(oldp+1424,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_666_real),32);
    bufp->fullIData(oldp+1425,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_666_imag),32);
    bufp->fullIData(oldp+1426,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_667_real),32);
    bufp->fullIData(oldp+1427,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_667_imag),32);
    bufp->fullIData(oldp+1428,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_668_real),32);
    bufp->fullIData(oldp+1429,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_668_imag),32);
    bufp->fullIData(oldp+1430,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_669_real),32);
    bufp->fullIData(oldp+1431,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_669_imag),32);
    bufp->fullIData(oldp+1432,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_670_real),32);
    bufp->fullIData(oldp+1433,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_670_imag),32);
    bufp->fullIData(oldp+1434,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_real),32);
    bufp->fullIData(oldp+1435,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_671_imag),32);
    bufp->fullIData(oldp+1436,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_672_real),32);
    bufp->fullIData(oldp+1437,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_672_imag),32);
    bufp->fullIData(oldp+1438,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_673_real),32);
    bufp->fullIData(oldp+1439,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_673_imag),32);
    bufp->fullIData(oldp+1440,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_674_real),32);
    bufp->fullIData(oldp+1441,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_674_imag),32);
    bufp->fullIData(oldp+1442,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_675_real),32);
    bufp->fullIData(oldp+1443,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_675_imag),32);
    bufp->fullIData(oldp+1444,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_676_real),32);
    bufp->fullIData(oldp+1445,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_676_imag),32);
    bufp->fullIData(oldp+1446,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_677_real),32);
    bufp->fullIData(oldp+1447,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_677_imag),32);
    bufp->fullIData(oldp+1448,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_678_real),32);
    bufp->fullIData(oldp+1449,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_678_imag),32);
    bufp->fullIData(oldp+1450,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_679_real),32);
    bufp->fullIData(oldp+1451,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_679_imag),32);
    bufp->fullIData(oldp+1452,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_680_real),32);
    bufp->fullIData(oldp+1453,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_680_imag),32);
    bufp->fullIData(oldp+1454,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_681_real),32);
    bufp->fullIData(oldp+1455,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_681_imag),32);
    bufp->fullIData(oldp+1456,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_682_real),32);
    bufp->fullIData(oldp+1457,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_682_imag),32);
    bufp->fullIData(oldp+1458,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_683_real),32);
    bufp->fullIData(oldp+1459,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_683_imag),32);
    bufp->fullIData(oldp+1460,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_684_real),32);
    bufp->fullIData(oldp+1461,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_684_imag),32);
    bufp->fullIData(oldp+1462,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_685_real),32);
    bufp->fullIData(oldp+1463,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_685_imag),32);
    bufp->fullIData(oldp+1464,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_686_real),32);
    bufp->fullIData(oldp+1465,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_686_imag),32);
    bufp->fullIData(oldp+1466,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_687_real),32);
    bufp->fullIData(oldp+1467,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_687_imag),32);
    bufp->fullIData(oldp+1468,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_688_real),32);
    bufp->fullIData(oldp+1469,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_688_imag),32);
    bufp->fullIData(oldp+1470,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_689_real),32);
    bufp->fullIData(oldp+1471,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_689_imag),32);
    bufp->fullIData(oldp+1472,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_690_real),32);
    bufp->fullIData(oldp+1473,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_690_imag),32);
    bufp->fullIData(oldp+1474,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_691_real),32);
    bufp->fullIData(oldp+1475,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_691_imag),32);
    bufp->fullIData(oldp+1476,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_692_real),32);
    bufp->fullIData(oldp+1477,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_692_imag),32);
    bufp->fullIData(oldp+1478,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_693_real),32);
    bufp->fullIData(oldp+1479,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_693_imag),32);
    bufp->fullIData(oldp+1480,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_694_real),32);
    bufp->fullIData(oldp+1481,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_694_imag),32);
    bufp->fullIData(oldp+1482,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_695_real),32);
    bufp->fullIData(oldp+1483,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_695_imag),32);
    bufp->fullIData(oldp+1484,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_696_real),32);
    bufp->fullIData(oldp+1485,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_696_imag),32);
    bufp->fullIData(oldp+1486,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_697_real),32);
    bufp->fullIData(oldp+1487,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_697_imag),32);
    bufp->fullIData(oldp+1488,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_698_real),32);
    bufp->fullIData(oldp+1489,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_698_imag),32);
    bufp->fullIData(oldp+1490,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_699_real),32);
    bufp->fullIData(oldp+1491,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_699_imag),32);
    bufp->fullIData(oldp+1492,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_700_real),32);
    bufp->fullIData(oldp+1493,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_700_imag),32);
    bufp->fullIData(oldp+1494,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_701_real),32);
    bufp->fullIData(oldp+1495,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_701_imag),32);
    bufp->fullIData(oldp+1496,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_702_real),32);
    bufp->fullIData(oldp+1497,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_702_imag),32);
    bufp->fullIData(oldp+1498,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_real),32);
    bufp->fullIData(oldp+1499,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_703_imag),32);
    bufp->fullIData(oldp+1500,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_704_real),32);
    bufp->fullIData(oldp+1501,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_704_imag),32);
    bufp->fullIData(oldp+1502,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_705_real),32);
    bufp->fullIData(oldp+1503,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_705_imag),32);
    bufp->fullIData(oldp+1504,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_706_real),32);
    bufp->fullIData(oldp+1505,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_706_imag),32);
    bufp->fullIData(oldp+1506,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_707_real),32);
    bufp->fullIData(oldp+1507,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_707_imag),32);
    bufp->fullIData(oldp+1508,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_708_real),32);
    bufp->fullIData(oldp+1509,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_708_imag),32);
    bufp->fullIData(oldp+1510,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_709_real),32);
    bufp->fullIData(oldp+1511,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_709_imag),32);
    bufp->fullIData(oldp+1512,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_710_real),32);
    bufp->fullIData(oldp+1513,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_710_imag),32);
    bufp->fullIData(oldp+1514,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_711_real),32);
    bufp->fullIData(oldp+1515,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_711_imag),32);
    bufp->fullIData(oldp+1516,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_712_real),32);
    bufp->fullIData(oldp+1517,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_712_imag),32);
    bufp->fullIData(oldp+1518,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_713_real),32);
    bufp->fullIData(oldp+1519,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_713_imag),32);
    bufp->fullIData(oldp+1520,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_714_real),32);
    bufp->fullIData(oldp+1521,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_714_imag),32);
    bufp->fullIData(oldp+1522,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_715_real),32);
    bufp->fullIData(oldp+1523,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_715_imag),32);
    bufp->fullIData(oldp+1524,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_716_real),32);
    bufp->fullIData(oldp+1525,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_716_imag),32);
    bufp->fullIData(oldp+1526,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_717_real),32);
    bufp->fullIData(oldp+1527,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_717_imag),32);
    bufp->fullIData(oldp+1528,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_718_real),32);
    bufp->fullIData(oldp+1529,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_718_imag),32);
    bufp->fullIData(oldp+1530,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_real),32);
    bufp->fullIData(oldp+1531,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_719_imag),32);
    bufp->fullIData(oldp+1532,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_720_real),32);
    bufp->fullIData(oldp+1533,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_720_imag),32);
    bufp->fullIData(oldp+1534,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_721_real),32);
    bufp->fullIData(oldp+1535,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_721_imag),32);
    bufp->fullIData(oldp+1536,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_722_real),32);
    bufp->fullIData(oldp+1537,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_722_imag),32);
    bufp->fullIData(oldp+1538,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_723_real),32);
    bufp->fullIData(oldp+1539,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_723_imag),32);
    bufp->fullIData(oldp+1540,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_724_real),32);
    bufp->fullIData(oldp+1541,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_724_imag),32);
    bufp->fullIData(oldp+1542,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_725_real),32);
    bufp->fullIData(oldp+1543,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_725_imag),32);
    bufp->fullIData(oldp+1544,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_726_real),32);
    bufp->fullIData(oldp+1545,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_726_imag),32);
    bufp->fullIData(oldp+1546,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_727_real),32);
    bufp->fullIData(oldp+1547,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_727_imag),32);
    bufp->fullIData(oldp+1548,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_728_real),32);
    bufp->fullIData(oldp+1549,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_728_imag),32);
    bufp->fullIData(oldp+1550,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_729_real),32);
    bufp->fullIData(oldp+1551,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_729_imag),32);
    bufp->fullIData(oldp+1552,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_730_real),32);
    bufp->fullIData(oldp+1553,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_730_imag),32);
    bufp->fullIData(oldp+1554,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_731_real),32);
    bufp->fullIData(oldp+1555,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_731_imag),32);
    bufp->fullIData(oldp+1556,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_732_real),32);
    bufp->fullIData(oldp+1557,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_732_imag),32);
    bufp->fullIData(oldp+1558,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_733_real),32);
    bufp->fullIData(oldp+1559,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_733_imag),32);
    bufp->fullIData(oldp+1560,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_734_real),32);
    bufp->fullIData(oldp+1561,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_734_imag),32);
    bufp->fullIData(oldp+1562,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_real),32);
    bufp->fullIData(oldp+1563,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_735_imag),32);
    bufp->fullIData(oldp+1564,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_736_real),32);
    bufp->fullIData(oldp+1565,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_736_imag),32);
    bufp->fullIData(oldp+1566,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_737_real),32);
    bufp->fullIData(oldp+1567,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_737_imag),32);
    bufp->fullIData(oldp+1568,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_738_real),32);
    bufp->fullIData(oldp+1569,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_738_imag),32);
    bufp->fullIData(oldp+1570,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_739_real),32);
    bufp->fullIData(oldp+1571,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_739_imag),32);
    bufp->fullIData(oldp+1572,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_740_real),32);
    bufp->fullIData(oldp+1573,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_740_imag),32);
    bufp->fullIData(oldp+1574,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_741_real),32);
    bufp->fullIData(oldp+1575,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_741_imag),32);
    bufp->fullIData(oldp+1576,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_742_real),32);
    bufp->fullIData(oldp+1577,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_742_imag),32);
    bufp->fullIData(oldp+1578,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_real),32);
    bufp->fullIData(oldp+1579,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_743_imag),32);
    bufp->fullIData(oldp+1580,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_744_real),32);
    bufp->fullIData(oldp+1581,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_744_imag),32);
    bufp->fullIData(oldp+1582,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_745_real),32);
    bufp->fullIData(oldp+1583,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_745_imag),32);
    bufp->fullIData(oldp+1584,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_746_real),32);
    bufp->fullIData(oldp+1585,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_746_imag),32);
    bufp->fullIData(oldp+1586,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_747_real),32);
    bufp->fullIData(oldp+1587,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_747_imag),32);
    bufp->fullIData(oldp+1588,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_748_real),32);
    bufp->fullIData(oldp+1589,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_748_imag),32);
    bufp->fullIData(oldp+1590,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_749_real),32);
    bufp->fullIData(oldp+1591,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_749_imag),32);
    bufp->fullIData(oldp+1592,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_750_real),32);
    bufp->fullIData(oldp+1593,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_750_imag),32);
    bufp->fullIData(oldp+1594,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_real),32);
    bufp->fullIData(oldp+1595,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_751_imag),32);
    bufp->fullIData(oldp+1596,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_752_real),32);
    bufp->fullIData(oldp+1597,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_752_imag),32);
    bufp->fullIData(oldp+1598,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_753_real),32);
    bufp->fullIData(oldp+1599,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_753_imag),32);
    bufp->fullIData(oldp+1600,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_754_real),32);
    bufp->fullIData(oldp+1601,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_754_imag),32);
    bufp->fullIData(oldp+1602,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_real),32);
    bufp->fullIData(oldp+1603,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_755_imag),32);
    bufp->fullIData(oldp+1604,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_756_real),32);
    bufp->fullIData(oldp+1605,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_756_imag),32);
    bufp->fullIData(oldp+1606,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_757_real),32);
    bufp->fullIData(oldp+1607,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_757_imag),32);
    bufp->fullIData(oldp+1608,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_758_real),32);
    bufp->fullIData(oldp+1609,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_758_imag),32);
    bufp->fullIData(oldp+1610,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_real),32);
    bufp->fullIData(oldp+1611,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_759_imag),32);
    bufp->fullIData(oldp+1612,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_760_real),32);
    bufp->fullIData(oldp+1613,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_760_imag),32);
    bufp->fullIData(oldp+1614,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_real),32);
    bufp->fullIData(oldp+1615,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_761_imag),32);
    bufp->fullIData(oldp+1616,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_762_real),32);
    bufp->fullIData(oldp+1617,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_762_imag),32);
    bufp->fullIData(oldp+1618,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_real),32);
    bufp->fullIData(oldp+1619,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_763_imag),32);
    bufp->fullIData(oldp+1620,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_real),32);
    bufp->fullIData(oldp+1621,(vlSelfRef.FFT512_tb__DOT__uut__DOT__r_764_imag),32);
    bufp->fullIData(oldp+1622,(vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_real),32);
    bufp->fullIData(oldp+1623,(vlSelfRef.FFT512_tb__DOT__uut__DOT__out1_imag),32);
    bufp->fullBit(oldp+1624,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                    >> 7U))));
    bufp->fullBit(oldp+1625,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                    >> 6U))));
    bufp->fullBit(oldp+1626,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                    >> 5U))));
    bufp->fullBit(oldp+1627,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                    >> 4U))));
    bufp->fullBit(oldp+1628,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                    >> 3U))));
    bufp->fullBit(oldp+1629,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                    >> 2U))));
    bufp->fullBit(oldp+1630,((1U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                    >> 1U))));
    bufp->fullBit(oldp+1631,((1U & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt))));
    bufp->fullIData(oldp+1632,((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                               (0xffU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_h010c7fca_0[
                                          (((IData)(0x1fU) 
                                            + (0x1fffU 
                                               & VL_SHIFTL_III(13,13,32, 
                                                               (0xffU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(13,13,32, 
                                                                 (0xffU 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_h010c7fca_0[
                                   (0xffU & (VL_SHIFTL_III(13,13,32, 
                                                           (0xffU 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                             (0xffU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1633,((((0U == (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                               (0xffU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_h15912bbd_0[
                                          (((IData)(0x1fU) 
                                            + (0x1fffU 
                                               & VL_SHIFTL_III(13,13,32, 
                                                               (0xffU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(13,13,32, 
                                                                 (0xffU 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_h15912bbd_0[
                                   (0xffU & (VL_SHIFTL_III(13,13,32, 
                                                           (0xffU 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(13,13,32, 
                                                             (0xffU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1634,((((0U == (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                               (0x7fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_hf3784b49_0[
                                          (((IData)(0x1fU) 
                                            + (0xfffU 
                                               & VL_SHIFTL_III(12,12,32, 
                                                               (0x7fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(12,12,32, 
                                                                 (0x7fU 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_hf3784b49_0[
                                   (0x7fU & (VL_SHIFTL_III(12,12,32, 
                                                           (0x7fU 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                             (0x7fU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1635,((((0U == (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                               (0x7fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_h944bc563_0[
                                          (((IData)(0x1fU) 
                                            + (0xfffU 
                                               & VL_SHIFTL_III(12,12,32, 
                                                               (0x7fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(12,12,32, 
                                                                 (0x7fU 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_h944bc563_0[
                                   (0x7fU & (VL_SHIFTL_III(12,12,32, 
                                                           (0x7fU 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(12,12,32, 
                                                             (0x7fU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1636,((((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                               (0x3fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_h8abd5580_0[
                                          (((IData)(0x1fU) 
                                            + (0x7ffU 
                                               & VL_SHIFTL_III(11,11,32, 
                                                               (0x3fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(11,11,32, 
                                                                 (0x3fU 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_h8abd5580_0[
                                   (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                                           (0x3fU 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                             (0x3fU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1637,((((0U == (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                               (0x3fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_h5478b25e_0[
                                          (((IData)(0x1fU) 
                                            + (0x7ffU 
                                               & VL_SHIFTL_III(11,11,32, 
                                                               (0x3fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(11,11,32, 
                                                                 (0x3fU 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_h5478b25e_0[
                                   (0x3fU & (VL_SHIFTL_III(11,11,32, 
                                                           (0x3fU 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(11,11,32, 
                                                             (0x3fU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1638,((((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                               (0x1fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_hb3c963b9_0[
                                          (((IData)(0x1fU) 
                                            + (0x3ffU 
                                               & VL_SHIFTL_III(10,10,32, 
                                                               (0x1fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(10,10,32, 
                                                                 (0x1fU 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_hb3c963b9_0[
                                   (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                                           (0x1fU 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                             (0x1fU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1639,((((0U == (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                               (0x1fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_h35564355_0[
                                          (((IData)(0x1fU) 
                                            + (0x3ffU 
                                               & VL_SHIFTL_III(10,10,32, 
                                                               (0x1fU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(10,10,32, 
                                                                 (0x1fU 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_h35564355_0[
                                   (0x1fU & (VL_SHIFTL_III(10,10,32, 
                                                           (0x1fU 
                                                            & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                             >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(10,10,32, 
                                                             (0x1fU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1640,((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                               (0xfU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_h942db0a5_0[
                                          (((IData)(0x1fU) 
                                            + (0x1ffU 
                                               & VL_SHIFTL_III(9,9,32, 
                                                               (0xfU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(9,9,32, 
                                                                 (0xfU 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_h942db0a5_0[
                                   (0xfU & (VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                            >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1641,((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                               (0xfU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_h0bfcbe7a_0[
                                          (((IData)(0x1fU) 
                                            + (0x1ffU 
                                               & VL_SHIFTL_III(9,9,32, 
                                                               (0xfU 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(9,9,32, 
                                                                 (0xfU 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_h0bfcbe7a_0[
                                   (0xfU & (VL_SHIFTL_III(9,9,32, 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                            >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1642,((((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                               (7U 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_hfd15effc_0[
                                          (((IData)(0x1fU) 
                                            + (0xffU 
                                               & VL_SHIFTL_III(8,8,32, 
                                                               (7U 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(8,8,32, 
                                                                 (7U 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_hfd15effc_0[
                                   (7U & (VL_SHIFTL_III(8,8,32, 
                                                        (7U 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                          >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                             (7U 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1643,((((0U == (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                               (7U 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (Vfft512__ConstPool__CONST_h04042068_0[
                                          (((IData)(0x1fU) 
                                            + (0xffU 
                                               & VL_SHIFTL_III(8,8,32, 
                                                               (7U 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(8,8,32, 
                                                                 (7U 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (Vfft512__ConstPool__CONST_h04042068_0[
                                   (7U & (VL_SHIFTL_III(8,8,32, 
                                                        (7U 
                                                         & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                          >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(8,8,32, 
                                                             (7U 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    __Vtemp_1[0U] = 0x100000U;
    __Vtemp_1[1U] = 0xb504fU;
    __Vtemp_1[2U] = 0U;
    __Vtemp_1[3U] = 0xfff4afb1U;
    bufp->fullIData(oldp+1644,((((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (__Vtemp_1[
                                          (((IData)(0x1fU) 
                                            + (0x7fU 
                                               & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(7,7,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (__Vtemp_1[(3U & 
                                              (VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                               >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    __Vtemp_2[0U] = 0U;
    __Vtemp_2[1U] = 0xb504fU;
    __Vtemp_2[2U] = 0x100000U;
    __Vtemp_2[3U] = 0xb504fU;
    bufp->fullIData(oldp+1645,((((0U == (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U)))
                                  ? 0U : (__Vtemp_2[
                                          (((IData)(0x1fU) 
                                            + (0x7fU 
                                               & VL_SHIFTL_III(7,7,32, 
                                                               (3U 
                                                                & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(7,7,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))) 
                                | (__Vtemp_2[(3U & 
                                              (VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U) 
                                               >> 5U))] 
                                   >> (0x1fU & VL_SHIFTL_III(7,7,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)), 5U))))),32);
    bufp->fullIData(oldp+1646,((0x100000U & ((~ (IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt)) 
                                             << 0x14U))),32);
    bufp->fullIData(oldp+1647,((0x100000U & ((IData)(vlSelfRef.FFT512_tb__DOT__uut__DOT__cnt) 
                                             << 0x14U))),32);
    bufp->fullBit(oldp+1648,(vlSelfRef.FFT512_tb__DOT__clock));
}
