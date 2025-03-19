`timescale 1ns / 1ps
// Generated by CIRCT firtool-1.62.1-1-gdf5ed6ea5
module FIRCore(
  input         clock,
                reset,
  input  [31:0] io_in_value,
  output [31:0] io_out_value
);

  reg  [31:0] regs_0_value;
  reg  [31:0] regs_1_value;
  reg  [31:0] regs_2_value;
  reg  [31:0] regs_3_value;
  reg  [31:0] regs_4_value;
  reg  [31:0] regs_5_value;
  reg  [31:0] regs_6_value;
  reg  [31:0] regs_7_value;
  reg  [31:0] regs_8_value;
  reg  [31:0] regs_9_value;
  reg  [31:0] regs_10_value;
  reg  [31:0] regs_11_value;
  reg  [31:0] regs_12_value;
  reg  [31:0] regs_13_value;
  reg  [31:0] regs_14_value;
  reg  [31:0] regs_15_value;
  wire [51:0] _io_out_fl_value_T = {{20{regs_0_value[31]}}, regs_0_value} * 52'h280E;
  wire [51:0] _io_out_fl_value_T_2 = {{20{regs_1_value[31]}}, regs_1_value} * 52'h3BF8;
  wire [51:0] _io_out_fl_value_T_4 = {{20{regs_2_value[31]}}, regs_2_value} * 52'h7445;
  wire [51:0] _io_out_fl_value_T_6 = {{20{regs_3_value[31]}}, regs_3_value} * 52'hC737;
  wire [51:0] _io_out_fl_value_T_8 = {{20{regs_4_value[31]}}, regs_4_value} * 52'h12679;
  wire [51:0] _io_out_fl_value_T_10 = {{20{regs_5_value[31]}}, regs_5_value} * 52'h18190;
  wire [51:0] _io_out_fl_value_T_12 = {{20{regs_6_value[31]}}, regs_6_value} * 52'h1C8BE;
  wire [51:0] _io_out_fl_value_T_14 = {{20{regs_7_value[31]}}, regs_7_value} * 52'h1EFB3;
  wire [51:0] _io_out_fl_value_T_16 = {{20{regs_8_value[31]}}, regs_8_value} * 52'h1EFB3;
  wire [51:0] _io_out_fl_value_T_18 = {{20{regs_9_value[31]}}, regs_9_value} * 52'h1C8BE;
  wire [51:0] _io_out_fl_value_T_20 =
    {{20{regs_10_value[31]}}, regs_10_value} * 52'h18190;
  wire [51:0] _io_out_fl_value_T_22 =
    {{20{regs_11_value[31]}}, regs_11_value} * 52'h12679;
  wire [51:0] _io_out_fl_value_T_24 = {{20{regs_12_value[31]}}, regs_12_value} * 52'hC737;
  wire [51:0] _io_out_fl_value_T_26 = {{20{regs_13_value[31]}}, regs_13_value} * 52'h7445;
  wire [51:0] _io_out_fl_value_T_28 = {{20{regs_14_value[31]}}, regs_14_value} * 52'h3BF8;
  wire [51:0] _io_out_fl_value_T_30 = {{20{regs_15_value[31]}}, regs_15_value} * 52'h280E;
  always @(posedge clock) begin
    if (reset) begin
      regs_0_value <= 32'h0;
      regs_1_value <= 32'h0;
      regs_2_value <= 32'h0;
      regs_3_value <= 32'h0;
      regs_4_value <= 32'h0;
      regs_5_value <= 32'h0;
      regs_6_value <= 32'h0;
      regs_7_value <= 32'h0;
      regs_8_value <= 32'h0;
      regs_9_value <= 32'h0;
      regs_10_value <= 32'h0;
      regs_11_value <= 32'h0;
      regs_12_value <= 32'h0;
      regs_13_value <= 32'h0;
      regs_14_value <= 32'h0;
      regs_15_value <= 32'h0;
    end
    else begin
      regs_0_value <= io_in_value;
      regs_1_value <= regs_0_value;
      regs_2_value <= regs_1_value;
      regs_3_value <= regs_2_value;
      regs_4_value <= regs_3_value;
      regs_5_value <= regs_4_value;
      regs_6_value <= regs_5_value;
      regs_7_value <= regs_6_value;
      regs_8_value <= regs_7_value;
      regs_9_value <= regs_8_value;
      regs_10_value <= regs_9_value;
      regs_11_value <= regs_10_value;
      regs_12_value <= regs_11_value;
      regs_13_value <= regs_12_value;
      regs_14_value <= regs_13_value;
      regs_15_value <= regs_14_value;
    end
  end // always @(posedge)
  assign io_out_value =
    _io_out_fl_value_T[51:20] + _io_out_fl_value_T_2[51:20] + _io_out_fl_value_T_4[51:20]
    + _io_out_fl_value_T_6[51:20] + _io_out_fl_value_T_8[51:20]
    + _io_out_fl_value_T_10[51:20] + _io_out_fl_value_T_12[51:20]
    + _io_out_fl_value_T_14[51:20] + _io_out_fl_value_T_16[51:20]
    + _io_out_fl_value_T_18[51:20] + _io_out_fl_value_T_20[51:20]
    + _io_out_fl_value_T_22[51:20] + _io_out_fl_value_T_24[51:20]
    + _io_out_fl_value_T_26[51:20] + _io_out_fl_value_T_28[51:20]
    + _io_out_fl_value_T_30[51:20];
endmodule

