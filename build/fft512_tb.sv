`timescale 1ns / 1ps

module FFT512_tb;
  reg clock;
  reg reset;
  reg [31:0] io_in_real;
  reg [31:0] io_in_imag;
  reg io_in_valid;
  reg [31:0] io_out1_real;
  reg [31:0] io_out1_imag;
  reg [31:0] io_out2_real;
  reg [31:0] io_out2_imag;
  reg io_out_valid;

  // Instantiate the SineWave module
  MDCCore uut (
      .clock(clock),
      .reset(reset),
      .io_in_real(io_in_real),
      .io_in_imag(io_in_imag),
      .io_in_valid(io_in_valid),
      .io_out1_real(io_out1_real),
      .io_out1_imag(io_out1_imag),
      .io_out2_real(io_out2_real),
      .io_out2_imag(io_out2_imag),
      .io_out_valid(io_out_valid)
  );

  // Clock generation
  always #5 clock = ~clock;  // 10ns period -> 100MHz clock

  initial begin
    $dumpfile("fft512.vcd");
    $dumpvars(0, FFT512_tb);
    // Initialize signals
    clock = 0;
    reset = 1;

    // Apply reset
    #20;
    reset = 0;

    for (int i = 0; i < 512; i = i + 1) begin
      io_in_real  = $rtoi($sin(2.0 * $acos(-1) * i / 128.0) * $pow(2, 20));
      io_in_imag  = 32'h00000000;
      io_in_valid = 1;
      #10;
    end
    io_in_valid = 0;

    // Run for some cycles
    #10240;

    // End simulation
    $finish;
  end


endmodule
