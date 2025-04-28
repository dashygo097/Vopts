`timescale 1ns / 1ps

module ModPWM_tb;
  reg clock;
  reg reset;
  reg [6:0] dutyCycle;
  wire io_out;


  // Instantiate the SineWave module
  ModPWMCore uut (
      .clock(clock),
      .reset(reset),
      .io_out(io_out),
      .io_dutyCycle(dutyCycle)
  );

  // Clock generation
  always #5 clock = ~clock;  // 10ns period -> 100MHz clock

  initial begin
    $dumpfile("mod_pwm.vcd");
    $dumpvars(0, CW_tb);
    // Initialize signals
    clock = 0;
    reset = 1;
    dutyCycle = 7'h0;

    // Apply reset
    #20;
    reset = 0;
    for (int i = 0; i < 10; i = i + 1) begin
      dutyCycle += 7'd10;
      #2000;
    end

    // End simulation
    $finish;
  end


endmodule
