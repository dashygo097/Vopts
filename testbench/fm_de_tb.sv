`timescale 1ns / 1ps

module DeFM_tb;
  reg clock;
  reg reset;
  reg [31:0] io_in_value;
  reg [31:0] io_in_fm_value;
  wire [31:0] io_out_value;

  FMCore uut_1 (
      .clock(clock),
      .reset(reset),
      .io_in_value(io_in_value),
      .io_out_value(io_in_fm_value)
  );

  // Instantiate the SineWave module
  DeFMCore uut_2 (
      .clock(clock),
      .reset(reset),
      .io_in_value(io_in_fm_value),
      .io_out_value(io_out_value)
  );

  // Clock generation
  always #5 clock = ~clock;  // 10ns period -> 100MHz clock

  initial begin
    $dumpfile("fm_de.vcd");
    $dumpvars(0, DeFM_tb);
    // Initialize signals
    clock = 0;
    reset = 1;

    // Apply reset
    #20;
    reset = 0;
    // Sinewave input
    for (int i = 0; i < 2000; i++) begin
      io_in_value = $rtoi($sin(2.0 * $acos(-1) * i / 500) * $pow(2, 20));
      #10;
    end

    // End simulation
    $finish;
  end


endmodule
