`timescale 1ns / 1ps

module CW_tb;
  reg clock;
  reg reset;
  wire [31:0] io_out_value;

  // Instantiate the SineWave module
  CWCore uut (
      .clock(clock),
      .reset(reset),
      .io_out_value(io_out_value)
  );

  // Clock generation
  always #5 clock = ~clock;  // 10ns period -> 100MHz clock

  initial begin
    $dumpfile("dds_cw.vcd");
    $dumpvars(0, CW_tb);
    // Initialize signals
    clock = 0;
    reset = 1;

    // Apply reset
    #20;
    reset = 0;
    #200000;

    // End simulation
    $finish;
  end


endmodule
