`timescale 1ns / 1ps
`include "../build/iir.sv"

module IIR_tb;
  reg clock;
  reg reset;
  reg [31:0] io_in_value;
  wire [31:0] io_out_value;

  // Instantiate the SineWave module
  IIR uut (
      .clock(clock),
      .reset(reset),
      .io_in_value(io_in_value),
      .io_out_value(io_out_value)
  );

  // Clock generation
  always #5 clock = ~clock;  // 10ns period -> 100MHz clock

  initial begin
    $dumpfile("fir.vcd");
    $dumpvars(0, FIR_tb);
    // Initialize signals
    clock = 0;
    reset = 1;

    // Apply reset
    #20;
    reset = 0;
    // Sinewave input
    for (int i = 0; i < 20000; i++) begin
      io_in_value = 32'($rtoi($sin(2.0 * $acos(-1) * i / 10) * $pow(2, 20))) +
          32'($rtoi($sin(2.0 * $acos(-1) * i / 1000) * $pow(2, 20)));
      #10;
    end

    // End simulation
    $finish;
  end


endmodule
