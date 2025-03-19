`timescale 1ns / 1ps

module TrigDDS_tb;
  reg clock;
  reg reset;
  reg [31:0] io_mag_value;
  reg [23:0] io_phase_delta;
  wire [31:0] io_out_value;

  // Instantiate the SineWave module
  TrigCore uut (
      .clock(clock),
      .reset(reset),
      .io_mag_value(io_mag_value),
      .io_phase_delta(io_phase_delta),
      .io_out_value(io_out_value)
  );

  // Clock generation
  always #5 clock = ~clock;  // 10ns period -> 100MHz clock

  initial begin
    $dumpfile("dds_trig.vcd");
    $dumpvars(0, TrigDDS_tb);
    // Initialize signals
    clock = 0;
    reset = 1;

    // Apply reset
    #20;
    reset = 0;
    io_mag_value = 32'h100000;
    io_phase_delta = 24'h0000;
    #200000;
    io_mag_value   = 32'h200000;
    io_phase_delta = 24'h0000;
    #200000;
    io_mag_value   = 32'h200000;
    io_phase_delta = 24'h1000;
    #200000

    // End simulation
    $finish;
  end


endmodule
