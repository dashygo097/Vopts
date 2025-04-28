`timescale 1 ns / 1 ps

module SRAM_tb;
  reg clock;
  reg reset;
  reg [3:0] io_addr;
  reg [15:0] io_dataIn;
  reg io_we;
  reg io_re;
  wire [15:0] io_dataOut;

  SRAMCore sram (
      .clock(clock),
      .reset(reset),
      .io_addr(io_addr),
      .io_dataIn(io_dataIn),
      .io_dataOut(io_dataOut),
      .io_en_we(io_we),
      .io_en_re(io_re)
  );


  task write_data;
    input [3:0] addr;
    input [15:0] data;

    begin
      io_addr = addr;
      io_dataIn = data;
      io_we = 1;
      #10 io_we = 0;
    end
  endtask

  task read_data;
    input [3:0] addr;
    begin
      io_addr = addr;
      io_re   = 1;
      #10 io_re = 0;
    end
  endtask

  always #5 clock = ~clock;
  initial begin
    $dumpfile("sram.vcd");
    $dumpvars(0, SRAM_tb);
    clock = 0;
    reset = 1;
    io_addr = 4'b0000;
    io_dataIn = 16'h0000;
    io_we = 0;
    io_re = 0;
    #10 reset = 0;
    write_data(4'b0000, 16'h1234);
    write_data(4'b0001, 16'hABCD);
    read_data(4'b0000);
    // Check output
    if (io_dataOut !== 16'hABCD) begin
      $display("Test failed: Expected %h, got %h", 16'hABCD, io_dataOut);
      $finish;
    end else begin
      $display("Test passed: Expected %h, got %h", 16'hABCD, io_dataOut);
    end
    // Finish simulation
    #10 $finish;
  end
endmodule
