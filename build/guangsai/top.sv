/*

<<<<<<<<<<<Top Module Checkpoint>>>>>>>>>>>

*/

`timescale 1ns / 1ps
module Top (
    input clock,
    input sclk,
    input reset,

    output DFB1_ADC_SCLK,
    output DFB1_ADC_CS,
    input  DFB1_ADC_DOUT,

    output DFB2_ADC_SCLK,
    output DFB2_ADC_CS,
    input  DFB2_ADC_DOUT,

    output DFB3_ADC_SCLK,
    output DFB3_ADC_CS,
    input  DFB3_ADC_DOUT,

    output DFB4_ADC_SCLK,
    output DFB4_ADC_CS,
    input  DFB4_ADC_DOUT,

    output TEC1_ADC_SCLK,
    output TEC1_ADC_CS,
    input  TEC1_ADC_DOUT,

    output TEC2_ADC_SCLK,
    output TEC2_ADC_CS,
    input  TEC2_ADC_DOUT,

    output TEC3_ADC_SCLK,
    output TEC3_ADC_CS,
    input  TEC3_ADC_DOUT,

    output TEC4_ADC_SCLK,
    output TEC4_ADC_CS,
    input  TEC4_ADC_DOUT,

    output DFB1_DAC_SCK,
    output DFB1_DAC_CS,
    output DFB1_DAC_SDI,
    output DFB1_DAC_LDAC,

    output DFB2_DAC_SCK,
    output DFB2_DAC_CS,
    output DFB2_DAC_SDI,
    output DFB2_DAC_LDAC,

    output DFB3_DAC_SCK,
    output DFB3_DAC_CS,
    output DFB3_DAC_SDI,
    output DFB3_DAC_LDAC,

    output DFB4_DAC_SCK,
    output DFB4_DAC_CS,
    output DFB4_DAC_SDI,
    output DFB4_DAC_LDAC,

    output DFBM1_DAC_SCK,
    output DFBM1_DAC_CS,
    output DFBM1_DAC_SDI,
    output DFBM1_DAC_LDAC,

    output DFBM2_DAC_SCK,
    output DFBM2_DAC_CS,
    output DFBM2_DAC_SDI,
    output DFBM2_DAC_LDAC,

    output DFBM3_DAC_SCK,
    output DFBM3_DAC_CS,
    output DFBM3_DAC_SDI,
    output DFBM3_DAC_LDAC,

    output DFBM4_DAC_SCK,
    output DFBM4_DAC_CS,
    output DFBM4_DAC_SDI,
    output DFBM4_DAC_LDAC,

    output TEC1_DAC_SCK,
    output TEC1_DAC_CS,
    output TEC1_DAC_SDI,
    output TEC1_DAC_LDAC,

    output TEC2_DAC_SCK,
    output TEC2_DAC_CS,
    output TEC2_DAC_SDI,
    output TEC2_DAC_LDAC,

    output TEC3_DAC_SCK,
    output TEC3_DAC_CS,
    output TEC3_DAC_SDI,
    output TEC3_DAC_LDAC,

    output TEC4_DAC_SCK,
    output TEC4_DAC_CS,
    output TEC4_DAC_SDI,
    output TEC4_DAC_LDAC,

    output UART_TX,
    input  UART_RX

);

  reg [7:0] UART_TX_CHANNEL_bits;
  reg UART_TX_CHANNEL_valid;
  wire UART_TX_CHANNEL_ready;
  wire UART_TX_BUSY;

  reg [7:0] UART_RX_CHANNEL_bits;
  reg UART_RX_CHANNEL_valid;
  wire UART_RX_CHANNEL_ready;
  wire UART_RX_ERROR;

  reg DFB1_DAC_EN;
  reg DFB2_DAC_EN;
  reg DFB3_DAC_EN;
  reg DFB4_DAC_EN;
  reg DFBM1_DAC_EN;
  reg DFBM2_DAC_EN;
  reg DFBM3_DAC_EN;
  reg DFBM4_DAC_EN;
  reg TEC1_DAC_EN;
  reg TEC2_DAC_EN;
  reg TEC3_DAC_EN;
  reg TEC4_DAC_EN;

  assign DFB1_ADC_SCLK = sclk;
  assign DFB2_ADC_SCLK = sclk;
  assign DFB3_ADC_SCLK = sclk;
  assign DFB4_ADC_SCLK = sclk;
  assign TEC1_ADC_SCLK = sclk;
  assign TEC2_ADC_SCLK = sclk;
  assign TEC3_ADC_SCLK = sclk;
  assign TEC4_ADC_SCLK = sclk;
  assign DFB1_DAC_SCK = sclk;
  assign DFB2_DAC_SCK = sclk;
  assign DFB3_DAC_SCK = sclk;
  assign DFB4_DAC_SCK = sclk;
  assign DFBM1_DAC_SCK = sclk;
  assign DFBM2_DAC_SCK = sclk;
  assign DFBM3_DAC_SCK = sclk;
  assign DFBM4_DAC_SCK = sclk;
  assign TEC1_DAC_SCK = sclk;
  assign TEC2_DAC_SCK = sclk;
  assign TEC3_DAC_SCK = sclk;
  assign TEC4_DAC_SCK = sclk;


  // Control Panel
  assign {DFB1_ADC_CS, DFB2_ADC_CS, DFB3_ADC_CS, DFB4_ADC_CS,
        TEC1_ADC_CS, TEC2_ADC_CS, TEC3_ADC_CS, TEC4_ADC_CS} = 8'b00000000;

  always @(posedge clock or posedge reset) begin
    if (reset) begin
      DFB1_DAC_EN  <= 1'b0;
      DFB2_DAC_EN  <= 1'b0;
      DFB3_DAC_EN  <= 1'b0;
      DFB4_DAC_EN  <= 1'b0;
      DFBM1_DAC_EN <= 1'b0;
      DFBM2_DAC_EN <= 1'b0;
      DFBM3_DAC_EN <= 1'b0;
      DFBM4_DAC_EN <= 1'b0;
      TEC1_DAC_EN  <= 1'b0;
      TEC2_DAC_EN  <= 1'b0;
      TEC3_DAC_EN  <= 1'b0;
      TEC4_DAC_EN  <= 1'b0;
    end else begin
      DFB1_DAC_EN  <= 1'b1;
      DFB2_DAC_EN  <= 1'b1;
      DFB3_DAC_EN  <= 1'b1;
      DFB4_DAC_EN  <= 1'b1;
      DFBM1_DAC_EN <= 1'b1;
      DFBM2_DAC_EN <= 1'b1;
      DFBM3_DAC_EN <= 1'b1;
      DFBM4_DAC_EN <= 1'b1;
      TEC1_DAC_EN  <= 1'b1;
      TEC2_DAC_EN  <= 1'b1;
      TEC3_DAC_EN  <= 1'b1;
      TEC4_DAC_EN  <= 1'b1;
    end
  end

  TopModule top_module (
      .clock(clock),
      .reset(reset),
      // UART
      .UART_TX(UART_TX),
      .UART_TX_CHANNEL_ready(UART_TX_CHANNEL_ready),
      .UART_TX_CHANNEL_valid(UART_TX_CHANNEL_valid),
      .UART_TX_CHANNEL_bits(UART_TX_CHANNEL_bits),
      .UART_TX_BUSY(UART_TX_BUSY),
      .UART_RX(UART_RX),
      .UART_RX_CHANNEL_ready(UART_RX_CHANNEL_ready),
      .UART_RX_CHANNEL_valid(UART_RX_CHANNEL_valid),
      .UART_RX_CHANNEL_bits(UART_RX_CHANNEL_bits),
      .UART_RX_ERROR(UART_RX_ERROR),
      // ADCs
      .DFB1_ADC_SCLK(DFB1_ADC_SCLK),
      .DFB1_ADC_CS(DFB1_ADC_CS),
      .DFB1_ADC_DOUT(DFB1_ADC_DOUT),
      .DFB1_ADC_GATE_IN(1'b1),
      .DFB1_ADC_GATE_OUT(1'b1),
      .DFB2_ADC_SCLK(DFB2_ADC_SCLK),
      .DFB2_ADC_CS(DFB2_ADC_CS),
      .DFB2_ADC_DOUT(DFB2_ADC_DOUT),
      .DFB2_ADC_GATE_IN(1'b1),
      .DFB2_ADC_GATE_OUT(1'b1),
      .DFB3_ADC_SCLK(DFB3_ADC_SCLK),
      .DFB3_ADC_CS(DFB3_ADC_CS),
      .DFB3_ADC_DOUT(DFB3_ADC_DOUT),
      .DFB3_ADC_GATE_IN(1'b1),
      .DFB3_ADC_GATE_OUT(1'b1),
      .DFB4_ADC_SCLK(DFB4_ADC_SCLK),
      .DFB4_ADC_CS(DFB4_ADC_CS),
      .DFB4_ADC_DOUT(DFB4_ADC_DOUT),
      .DFB4_ADC_GATE_IN(1'b1),
      .DFB4_ADC_GATE_OUT(1'b1),
      .TEC1_ADC_SCLK(TEC1_ADC_SCLK),
      .TEC1_ADC_CS(TEC1_ADC_CS),
      .TEC1_ADC_DOUT(TEC1_ADC_DOUT),
      .TEC1_ADC_GATE_IN(1'b1),
      .TEC1_ADC_GATE_OUT(1'b1),
      .TEC2_ADC_SCLK(TEC2_ADC_SCLK),
      .TEC2_ADC_CS(TEC2_ADC_CS),
      .TEC2_ADC_DOUT(TEC2_ADC_DOUT),
      .TEC2_ADC_GATE_IN(1'b1),
      .TEC2_ADC_GATE_OUT(1'b1),
      .TEC3_ADC_SCLK(TEC3_ADC_SCLK),
      .TEC3_ADC_CS(TEC3_ADC_CS),
      .TEC3_ADC_DOUT(TEC3_ADC_DOUT),
      .TEC3_ADC_GATE_IN(1'b1),
      .TEC3_ADC_GATE_OUT(1'b1),
      .TEC4_ADC_SCLK(TEC4_ADC_SCLK),
      .TEC4_ADC_CS(TEC4_ADC_CS),
      .TEC4_ADC_DOUT(TEC4_ADC_DOUT),
      .TEC4_ADC_GATE_IN(1'b1),
      .TEC4_ADC_GATE_OUT(1'b1),
      // DACs
      .DFB1_DAC_EN(DFB1_DAC_EN),
      .DFB1_DAC_SCK(DFB1_DAC_SCK),
      .DFB1_DAC_CS(DFB1_DAC_CS),
      .DFB1_DAC_SDI(DFB1_DAC_SDI),
      .DFB1_DAC_LDAC(DFB1_DAC_LDAC),
      .DFB2_DAC_EN(DFB2_DAC_EN),
      .DFB2_DAC_SCK(DFB2_DAC_SCK),
      .DFB2_DAC_CS(DFB2_DAC_CS),
      .DFB2_DAC_SDI(DFB2_DAC_SDI),
      .DFB2_DAC_LDAC(DFB2_DAC_LDAC),
      .DFB3_DAC_EN(DFB3_DAC_EN),
      .DFB3_DAC_SCK(DFB3_DAC_SCK),
      .DFB3_DAC_CS(DFB3_DAC_CS),
      .DFB3_DAC_SDI(DFB3_DAC_SDI),
      .DFB3_DAC_LDAC(DFB3_DAC_LDAC),
      .DFB4_DAC_EN(DFB4_DAC_EN),
      .DFB4_DAC_SCK(DFB4_DAC_SCK),
      .DFB4_DAC_CS(DFB4_DAC_CS),
      .DFB4_DAC_SDI(DFB4_DAC_SDI),
      .DFB4_DAC_LDAC(DFB4_DAC_LDAC),
      .DFBM1_DAC_EN(DFBM1_DAC_EN),
      .DFBM1_DAC_SCK(DFBM1_DAC_SCK),
      .DFBM1_DAC_CS(DFBM1_DAC_CS),
      .DFBM1_DAC_SDI(DFBM1_DAC_SDI),
      .DFBM1_DAC_LDAC(DFBM1_DAC_LDAC),
      .DFBM2_DAC_EN(DFBM2_DAC_EN),
      .DFBM2_DAC_SCK(DFBM2_DAC_SCK),
      .DFBM2_DAC_CS(DFBM2_DAC_CS),
      .DFBM2_DAC_SDI(DFBM2_DAC_SDI),
      .DFBM2_DAC_LDAC(DFBM2_DAC_LDAC),
      .DFBM3_DAC_EN(DFBM3_DAC_EN),
      .DFBM3_DAC_SCK(DFBM3_DAC_SCK),
      .DFBM3_DAC_CS(DFBM3_DAC_CS),
      .DFBM3_DAC_SDI(DFBM3_DAC_SDI),
      .DFBM3_DAC_LDAC(DFBM3_DAC_LDAC),
      .DFBM4_DAC_EN(DFBM4_DAC_EN),
      .DFBM4_DAC_SCK(DFBM4_DAC_SCK),
      .DFBM4_DAC_CS(DFBM4_DAC_CS),
      .DFBM4_DAC_SDI(DFBM4_DAC_SDI),
      .DFBM4_DAC_LDAC(DFBM4_DAC_LDAC),
      .TEC1_DAC_EN(TEC1_DAC_EN),
      .TEC1_DAC_SCK(TEC1_DAC_SCK),
      .TEC1_DAC_CS(TEC1_DAC_CS),
      .TEC1_DAC_SDI(TEC1_DAC_SDI),
      .TEC1_DAC_LDAC(TEC1_DAC_LDAC),
      .TEC2_DAC_EN(TEC2_DAC_EN),
      .TEC2_DAC_SCK(TEC2_DAC_SCK),
      .TEC2_DAC_CS(TEC2_DAC_CS),
      .TEC2_DAC_SDI(TEC2_DAC_SDI),
      .TEC2_DAC_LDAC(TEC2_DAC_LDAC),
      .TEC3_DAC_EN(TEC3_DAC_EN),
      .TEC3_DAC_SCK(TEC3_DAC_SCK),
      .TEC3_DAC_CS(TEC3_DAC_CS),
      .TEC3_DAC_SDI(TEC3_DAC_SDI),
      .TEC3_DAC_LDAC(TEC3_DAC_LDAC),
      .TEC4_DAC_EN(TEC4_DAC_EN),
      .TEC4_DAC_SCK(TEC4_DAC_SCK),
      .TEC4_DAC_CS(TEC4_DAC_CS),
      .TEC4_DAC_SDI(TEC4_DAC_SDI),
      .TEC4_DAC_LDAC(TEC4_DAC_LDAC)
  );



endmodule
