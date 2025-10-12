`timescale 1ns / 1ps
`include "../../build/axi_lite_slave_mmap.sv"

module tb_axi_slave ();

  // Parameters
  parameter integer C_S_AXI_DATA_WIDTH = 32;
  parameter integer C_S_AXI_ADDR_WIDTH = 32;

  // Clock and Reset
  reg S_AXI_ACLK;
  reg S_AXI_ARESETN;

  // Write Address Channel
  reg [C_S_AXI_ADDR_WIDTH-1:0] S_AXI_AWADDR;
  reg [2:0] S_AXI_AWPROT;
  reg S_AXI_AWVALID;
  wire S_AXI_AWREADY;

  // Write Data Channel
  reg [C_S_AXI_DATA_WIDTH-1:0] S_AXI_WDATA;
  reg [(C_S_AXI_DATA_WIDTH/8)-1:0] S_AXI_WSTRB;
  reg S_AXI_WVALID;
  wire S_AXI_WREADY;

  // Write Response Channel
  wire [1:0] S_AXI_BRESP;
  wire S_AXI_BVALID;
  reg S_AXI_BREADY;

  // Read Address Channel
  reg [C_S_AXI_ADDR_WIDTH-1:0] S_AXI_ARADDR;
  reg [2:0] S_AXI_ARPROT;
  reg S_AXI_ARVALID;
  wire S_AXI_ARREADY;

  // Read Data Channel
  wire [C_S_AXI_DATA_WIDTH-1:0] S_AXI_RDATA;
  wire [1:0] S_AXI_RRESP;
  wire S_AXI_RVALID;
  reg S_AXI_RREADY;

  // Test variables
  reg [31:0] expected_data;
  reg [31:0] read_data;
  integer error_count = 0;
  integer test_count = 0;

  // Instantiate the AXI Slave
  axilite_slave_mmap_4x32x32_r4 uut (
      .clock(S_AXI_ACLK),
      .reset(!S_AXI_ARESETN),
      .S_AXI_AWADDR(S_AXI_AWADDR),
      .S_AXI_AWPROT(S_AXI_AWPROT),
      .S_AXI_AWVALID(S_AXI_AWVALID),
      .S_AXI_AWREADY(S_AXI_AWREADY),
      .S_AXI_WDATA(S_AXI_WDATA),
      .S_AXI_WSTRB(S_AXI_WSTRB),
      .S_AXI_WVALID(S_AXI_WVALID),
      .S_AXI_WREADY(S_AXI_WREADY),
      .S_AXI_BRESP(S_AXI_BRESP),
      .S_AXI_BVALID(S_AXI_BVALID),
      .S_AXI_BREADY(S_AXI_BREADY),
      .S_AXI_ARADDR(S_AXI_ARADDR),
      .S_AXI_ARPROT(S_AXI_ARPROT),
      .S_AXI_ARVALID(S_AXI_ARVALID),
      .S_AXI_ARREADY(S_AXI_ARREADY),
      .S_AXI_RDATA(S_AXI_RDATA),
      .S_AXI_RRESP(S_AXI_RRESP),
      .S_AXI_RVALID(S_AXI_RVALID),
      .S_AXI_RREADY(S_AXI_RREADY)
  );

  // Clock generation
  always #5 S_AXI_ACLK = ~S_AXI_ACLK;

  // Task to perform AXI write transaction
  task axi_write;
    input [C_S_AXI_ADDR_WIDTH-1:0] addr;
    input [C_S_AXI_DATA_WIDTH-1:0] data;
    input [(C_S_AXI_DATA_WIDTH/8)-1:0] strb;
    begin
      @(posedge S_AXI_ACLK);

      // Start write address and data phases simultaneously
      S_AXI_AWADDR  = addr;
      S_AXI_AWPROT  = 3'b000;
      S_AXI_AWVALID = 1'b1;
      S_AXI_WDATA   = data;
      S_AXI_WSTRB   = strb;
      S_AXI_WVALID  = 1'b1;
      S_AXI_BREADY  = 1'b1;

      // Wait for address and data ready
      while (!(S_AXI_AWREADY && S_AXI_WREADY)) begin
        @(posedge S_AXI_ACLK);
      end

      @(posedge S_AXI_ACLK);
      S_AXI_AWVALID = 1'b0;
      S_AXI_WVALID  = 1'b0;

      // Wait for write response
      while (!S_AXI_BVALID) begin
        @(posedge S_AXI_ACLK);
      end

      @(posedge S_AXI_ACLK);
      S_AXI_BREADY = 1'b0;

      $display("Write completed: Addr=0x%h, Data=0x%h, Strb=0x%h", addr, data, strb);
    end
  endtask

  // Task to perform AXI read transaction
  task axi_read;
    input [C_S_AXI_ADDR_WIDTH-1:0] addr;
    output [C_S_AXI_DATA_WIDTH-1:0] data;
    begin
      @(posedge S_AXI_ACLK);

      // Start read address phase
      S_AXI_ARADDR  = addr;
      S_AXI_ARPROT  = 3'b000;
      S_AXI_ARVALID = 1'b1;
      S_AXI_RREADY  = 1'b1;

      // Wait for address ready
      while (!S_AXI_ARREADY) begin
        @(posedge S_AXI_ACLK);
      end

      @(posedge S_AXI_ACLK);
      S_AXI_ARVALID = 1'b0;

      // Wait for read data
      while (!S_AXI_RVALID) begin
        @(posedge S_AXI_ACLK);
      end

      data = S_AXI_RDATA;

      @(posedge S_AXI_ACLK);
      S_AXI_RREADY = 1'b0;

      $display("Read completed: Addr=0x%h, Data=0x%h", addr, data);
    end
  endtask

  // Task to check read data against expected value
  task check_read_data;
    input [C_S_AXI_ADDR_WIDTH-1:0] addr;
    input [C_S_AXI_DATA_WIDTH-1:0] expected;
    begin
      axi_read(addr, read_data);
      test_count = test_count + 1;

      if (read_data !== expected) begin
        $display("ERROR: Address 0x%h - Expected: 0x%h, Got: 0x%h", addr, expected, read_data);
        error_count = error_count + 1;
      end else begin
        $display("PASS: Address 0x%h - Data: 0x%h", addr, read_data);
      end
    end
  endtask

  // Initialize signals
  initial begin
    S_AXI_ACLK = 0;
    S_AXI_ARESETN = 0;
    S_AXI_AWADDR = 0;
    S_AXI_AWPROT = 0;
    S_AXI_AWVALID = 0;
    S_AXI_WDATA = 0;
    S_AXI_WSTRB = 0;
    S_AXI_WVALID = 0;
    S_AXI_BREADY = 0;
    S_AXI_ARADDR = 0;
    S_AXI_ARPROT = 0;
    S_AXI_ARVALID = 0;
    S_AXI_RREADY = 0;
  end

  // Main test sequence
  initial begin
    $display("Starting AXI4-Lite Slave Testbench");
    $display("=====================================");
    $dumpfile("axilite_slave_mmap.vcd");
    $dumpvars(0, tb_axi_slave);

    // Reset sequence
    #100;
    S_AXI_ARESETN = 1;
    #100;  // Increased delay after reset to ensure proper initialization

    // Test 1: Check initial reset values
    $display("\nTest 1: Checking initial reset values");
    check_read_data(32'h10000, 32'h00000000);  // slv_reg0
    check_read_data(32'h14000, 32'h00000000);  // slv_reg1
    check_read_data(32'h18000, 32'h00000000);  // slv_reg2
    check_read_data(32'h1C000, 32'h00000000);  // slv_reg3

    // Test 2: Basic write and read operations
    $display("\nTest 2: Basic write and read operations");
    axi_write(32'h10000, 32'hDEADBEEF, 4'hF);  // Write to slv_reg0
    check_read_data(32'h10000, 32'hDEADBEEF);

    axi_write(32'h14000, 32'h12345678, 4'hF);  // Write to slv_reg1
    check_read_data(32'h14000, 32'h12345678);

    axi_write(32'h18000, 32'hABCDEF01, 4'hF);  // Write to slv_reg2
    check_read_data(32'h18000, 32'hABCDEF01);

    axi_write(32'h1C000, 32'h87654321, 4'hF);  // Write to slv_reg3
    check_read_data(32'h1C000, 32'h87654321);

    // Test 3: Byte-level write operations using write strobes
    $display("\nTest 3: Byte-level write operations");

    // Write only lower byte of reg0
    axi_write(32'h10000, 32'h000000FF, 4'h1);

    // Write only upper byte of reg1
    axi_write(32'h14000, 32'hAA000000, 4'h8);

    // Write middle two bytes of reg2
    axi_write(32'h18000, 32'h0000FFFF, 4'h6);

    // write no bytes of reg3
    axi_write(32'h1C000, 32'hFFFFFFFF, 4'h0);

    // Verify existing registers
    check_read_data(32'h10000, 32'hDEADBEFF);
    check_read_data(32'h14000, 32'hAA345678);
    check_read_data(32'h18000, 32'hAB00FF01);
    check_read_data(32'h1C000, 32'h87654321);

    // Test 4: Reset functionality
    $display("\nTest 4: Reset functionality");
    S_AXI_ARESETN = 0;
    #50;
    S_AXI_ARESETN = 1;
    #50;

    // Check all registers are reset to 0
    check_read_data(32'h10000, 32'h00000000);
    check_read_data(32'h14000, 32'h00000000);
    check_read_data(32'h18000, 32'h00000000);
    check_read_data(32'h1C000, 32'h00000000);

    // Test 7: Pattern tests
    $display("\nTest 5: Pattern tests");
    axi_write(32'h10000, 32'hAAAAAAAA, 4'hF);
    check_read_data(32'h10000, 32'hAAAAAAAA);

    axi_write(32'h14000, 32'h55555555, 4'hF);
    check_read_data(32'h14000, 32'h55555555);

    axi_write(32'h18000, 32'hFFFFFFFF, 4'hF);
    check_read_data(32'h18000, 32'hFFFFFFFF);

    axi_write(32'h1C000, 32'h00000000, 4'hF);
    check_read_data(32'h1C000, 32'h00000000);

    // Test Summary
    $display("\n=====================================");
    $display("Test Summary:");
    $display("Total Tests: %d", test_count);
    $display("Errors: %d", error_count);

    if (error_count == 0) begin
      $display("ALL TESTS PASSED!");
    end else begin
      $display("TESTS FAILED!");
    end

    $display("=====================================");

    // Close log file
    #100;
  end

  // Monitor for debugging
  initial begin
    $monitor(
        "Time=%t, ARESETN=%b, AWVALID=%b, AWREADY=%b, WVALID=%b, WREADY=%b, BVALID=%b, BREADY=%b, ARVALID=%b, ARREADY=%b, RVALID=%b, RREADY=%b",
        $time, S_AXI_ARESETN, S_AXI_AWVALID, S_AXI_AWREADY, S_AXI_WVALID, S_AXI_WREADY,
        S_AXI_BVALID, S_AXI_BREADY, S_AXI_ARVALID, S_AXI_ARREADY, S_AXI_RVALID, S_AXI_RREADY);
  end

  // Timeout protection
  initial begin
    #2500;
    $display("ERROR: Simulation timeout!");
    $finish;
  end

endmodule
