`timescale 1ns / 1ps
// Generated by CIRCT firtool-1.62.1-1-gdf5ed6ea5
module AsyncFIFOCtrlCore(
  input        reset,
  output [2:0] io_waddr,
               io_raddr,
  input        io_wr,
               io_rd,
  output       io_empty,
               io_full,
  input        io_wclk,
               io_rclk
);

  reg  [3:0] wPtr;
  reg  [3:0] wPtrGrayReg;
  reg  [3:0] rPtrGraySync_sync1;
  reg  [3:0] rPtrGraySync;
  wire [3:0] _wPtrPlus1_T_5 = wPtr + 4'h1;
  wire [3:0] wPtrPlus1 = (&(wPtr[2:0])) ? {~(wPtr[3]), 3'h0} : _wPtrPlus1_T_5;
  wire       io_full_0 = ({1'h0, wPtrPlus1[3:1]} ^ wPtrPlus1) == rPtrGraySync;
  wire [3:0] _io_waddr_T_1 = {1'h0, wPtr[2:0]} % 4'h8;
  reg  [3:0] rPtr;
  reg  [3:0] rPtrGrayReg;
  reg  [3:0] wPtrGraySync_sync1;
  reg  [3:0] wPtrGraySync;
  wire       io_empty_0 = rPtrGrayReg == wPtrGraySync;
  wire [3:0] _io_raddr_T_1 = {1'h0, rPtr[2:0]} % 4'h8;
  always @(posedge io_wclk) begin
    if (reset) begin
      wPtr <= 4'h0;
      wPtrGrayReg <= 4'h0;
    end
    else begin
      automatic logic       _wPtrNext_T_1 = io_wr & ~io_full_0;
      automatic logic [3:0] wPtrNext = _wPtrNext_T_1 ? _wPtrPlus1_T_5 : wPtr;
      if (_wPtrNext_T_1)
        wPtr <= _wPtrPlus1_T_5;
      wPtrGrayReg <= {1'h0, wPtrNext[3:1]} ^ wPtrNext;
    end
    rPtrGraySync_sync1 <= rPtrGrayReg;
    rPtrGraySync <= rPtrGraySync_sync1;
  end // always @(posedge)
  always @(posedge io_rclk) begin
    if (reset) begin
      rPtr <= 4'h0;
      rPtrGrayReg <= 4'h0;
    end
    else begin
      automatic logic [3:0] _rPtrBinIncr_T;
      automatic logic       _rPtrNext_T_1 = io_rd & ~io_empty_0;
      automatic logic [3:0] rPtrNext;
      _rPtrBinIncr_T = rPtr + 4'h1;
      rPtrNext = _rPtrNext_T_1 ? _rPtrBinIncr_T : rPtr;
      if (_rPtrNext_T_1)
        rPtr <= _rPtrBinIncr_T;
      rPtrGrayReg <= {1'h0, rPtrNext[3:1]} ^ rPtrNext;
    end
    wPtrGraySync_sync1 <= wPtrGrayReg;
    wPtrGraySync <= wPtrGraySync_sync1;
  end // always @(posedge)
  assign io_waddr = _io_waddr_T_1[2:0];
  assign io_raddr = _io_raddr_T_1[2:0];
  assign io_empty = io_empty_0;
  assign io_full = io_full_0;
endmodule

module RegisterFileCore(
  input         clock,
                reset,
  input  [2:0]  io_raddr,
                io_waddr,
  input         io_we,
  input  [11:0] io_wdata_value,
  output [11:0] io_rdata_value
);

  reg  [11:0]      regFile_0_value;
  reg  [11:0]      regFile_1_value;
  reg  [11:0]      regFile_2_value;
  reg  [11:0]      regFile_3_value;
  reg  [11:0]      regFile_4_value;
  reg  [11:0]      regFile_5_value;
  reg  [11:0]      regFile_6_value;
  reg  [11:0]      regFile_7_value;
  wire [7:0][11:0] _GEN =
    {{regFile_7_value},
     {regFile_6_value},
     {regFile_5_value},
     {regFile_4_value},
     {regFile_3_value},
     {regFile_2_value},
     {regFile_1_value},
     {regFile_0_value}};
  always @(posedge clock) begin
    if (reset) begin
      regFile_0_value <= 12'h0;
      regFile_1_value <= 12'h0;
      regFile_2_value <= 12'h0;
      regFile_3_value <= 12'h0;
      regFile_4_value <= 12'h0;
      regFile_5_value <= 12'h0;
      regFile_6_value <= 12'h0;
      regFile_7_value <= 12'h0;
    end
    else begin
      if (io_we & io_waddr == 3'h0)
        regFile_0_value <= io_wdata_value;
      if (io_we & io_waddr == 3'h1)
        regFile_1_value <= io_wdata_value;
      if (io_we & io_waddr == 3'h2)
        regFile_2_value <= io_wdata_value;
      if (io_we & io_waddr == 3'h3)
        regFile_3_value <= io_wdata_value;
      if (io_we & io_waddr == 3'h4)
        regFile_4_value <= io_wdata_value;
      if (io_we & io_waddr == 3'h5)
        regFile_5_value <= io_wdata_value;
      if (io_we & io_waddr == 3'h6)
        regFile_6_value <= io_wdata_value;
      if (io_we & (&io_waddr))
        regFile_7_value <= io_wdata_value;
    end
  end // always @(posedge)
  assign io_rdata_value = _GEN[io_raddr];
endmodule

module AsyncFIFOCore(
  input         clock,
                reset,
  input  [11:0] io_wdata_value,
  output [11:0] io_rdata_value,
  input         io_wr,
                io_rd,
  output        io_empty,
                io_full,
  input         io_wclk,
                io_rclk
);

  wire [2:0] _control_io_waddr;
  wire [2:0] _control_io_raddr;
  wire       _control_io_full;
  AsyncFIFOCtrlCore control (
    .reset    (reset),
    .io_waddr (_control_io_waddr),
    .io_raddr (_control_io_raddr),
    .io_wr    (io_wr),
    .io_rd    (io_rd),
    .io_empty (io_empty),
    .io_full  (_control_io_full),
    .io_wclk  (io_wclk),
    .io_rclk  (io_rclk)
  );
  RegisterFileCore register (
    .clock          (clock),
    .reset          (reset),
    .io_raddr       (_control_io_raddr),
    .io_waddr       (_control_io_waddr),
    .io_we          (io_wr & ~_control_io_full),
    .io_wdata_value (io_wdata_value),
    .io_rdata_value (io_rdata_value)
  );
  assign io_full = _control_io_full;
endmodule

module ADC122S625Core(
  input         clock,
                reset,
                io_sclk,
                io_sdo,
                io_cs_n,
                io_gateIn,
                io_gateOut,
  output [11:0] io_dataA_value,
                io_dataB_value,
  output        io_fullA,
                io_fullB,
                io_emptyA,
                io_emptyB
);

  reg  [4:0]  csCounter;
  reg         onSamplingA;
  reg         onSamplingB;
  reg  [11:0] shiftRegA;
  reg  [3:0]  bitCounterA;
  reg  [11:0] shiftRegB;
  reg  [3:0]  bitCounterB;
  wire        _GEN = io_gateIn & io_gateOut;
  wire        _fifoA_io_rd_T = bitCounterA == 4'hB;
  wire        _fifoB_io_rd_T = bitCounterB == 4'hB;
  wire        _GEN_0 = io_gateIn & ~io_gateOut;
  wire        _GEN_1 = ~_GEN_0 & ~io_gateIn & io_gateOut;
  always @(posedge io_sclk) begin
    if (reset) begin
      csCounter <= 5'h0;
      onSamplingA <= 1'h0;
      onSamplingB <= 1'h0;
      shiftRegA <= 12'h0;
      bitCounterA <= 4'h0;
      shiftRegB <= 12'h0;
      bitCounterB <= 4'h0;
    end
    else begin
      if (io_cs_n)
        csCounter <= 5'h0;
      else
        csCounter <= csCounter + 5'h1;
      onSamplingA <= (|(csCounter[4:2])) & ~(csCounter[4]);
      onSamplingB <= csCounter > 5'h13;
      if (~io_cs_n & onSamplingA)
        shiftRegA <= {io_sdo, shiftRegA[11:1]};
      if (onSamplingA)
        bitCounterA <= bitCounterA + 4'h1;
      else
        bitCounterA <= 4'h0;
      if (~io_cs_n & onSamplingB)
        shiftRegB <= {io_sdo, shiftRegB[11:1]};
      if (onSamplingB)
        bitCounterB <= bitCounterB + 4'h1;
      else
        bitCounterB <= 4'h0;
    end
  end // always @(posedge)
  AsyncFIFOCore fifoA (
    .clock          (clock),
    .reset          (reset),
    .io_wdata_value (shiftRegA),
    .io_rdata_value (io_dataA_value),
    .io_wr          (_GEN ? _fifoA_io_rd_T : _GEN_0 & bitCounterA == 4'hB),
    .io_rd          (_GEN ? _fifoA_io_rd_T : _GEN_1),
    .io_empty       (io_emptyA),
    .io_full        (io_fullA),
    .io_wclk        (io_sclk),
    .io_rclk        (clock)
  );
  AsyncFIFOCore fifoB (
    .clock          (clock),
    .reset          (reset),
    .io_wdata_value (shiftRegB),
    .io_rdata_value (io_dataB_value),
    .io_wr          (_GEN ? _fifoB_io_rd_T : _GEN_0 & bitCounterB == 4'hB),
    .io_rd          (_GEN ? _fifoB_io_rd_T : _GEN_1),
    .io_empty       (io_emptyB),
    .io_full        (io_fullB),
    .io_wclk        (io_sclk),
    .io_rclk        (clock)
  );
endmodule

