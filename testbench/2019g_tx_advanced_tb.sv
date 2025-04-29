`timescale 1ns / 1ps
`include "../build/2019g_tx_advanced.sv"

module Tx_tb;
  reg clock;
  reg reset;
  reg [3:0] io_ctrl;
  reg [11:0] io_mod;
  reg [11:0] io_in;
  wire [13:0] io_out;

  // Instantiate the SineWave module
  TxCore_Advanced uut (
      .clock(clock),
      .reset(reset),
      .io_ctrl(io_ctrl),
      .io_mod_value(io_mod),
      .io_in_value(io_in),
      .io_out_value(io_out)
  );

  // Clock generation
  always #5 clock = ~clock;  // 10ns period -> 100MHz clock

  initial begin
    $dumpfile("asd.vcd");
    $dumpvars(0, Tx_tb);
    // Initialize signals
    clock = 0;
    reset = 1;

    // Apply reset
    #20;
    reset   = 0;
    io_ctrl = 0;
    io_mod = 0;

    for (int i = 0; i < 2048; i = i + 1) begin
      io_in = 12'($rtoi($sin(2.0 * $acos(-1) * i / 128.0) * $pow(2, 11)));
      if (i == 1024) begin
        io_mod += 12'($rtoi(-0.8 * $pow(2, 11)));
      end
      #10;
    end

    // Run for some cycles
    reset = 1;
    #1000;

    // End simulation
    $finish;
  end


endmodule
