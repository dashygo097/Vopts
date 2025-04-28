`timescale 1ns / 1ps

module PWM_tb;
  reg  clock;
  reg  reset;
  wire io_out;

  // Instantiate the SineWave module
  PWMCore uut (
      .clock (clock),
      .reset (reset),
      .io_out(io_out)
  );

  // Clock generation
  always #5 clock = ~clock;  // 10ns period -> 100MHz clock

  initial begin
    $dumpfile("pwm.vcd");
    $dumpvars(0, CW_tb);
    // Initialize signals
    clock = 0;
    reset = 1;

    // Apply reset
    #20;
    reset = 0;
    #20000;

    // End simulation
    $finish;
  end


endmodule
