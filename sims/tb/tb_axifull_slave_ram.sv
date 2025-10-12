`timescale 1ns / 1ps
`include "../../build/axi_full_slave_ram.sv"

module axifull_slave_tb;

  // Parameters
  parameter integer C_S_AXI_ID_WIDTH = 4;
  parameter integer C_S_AXI_DATA_WIDTH = 32;
  parameter integer C_S_AXI_ADDR_WIDTH = 32;
  parameter integer C_S_AXI_AWUSER_WIDTH = 1;
  parameter integer C_S_AXI_ARUSER_WIDTH = 1;
  parameter integer C_S_AXI_WUSER_WIDTH = 1;
  parameter integer C_S_AXI_RUSER_WIDTH = 1;
  parameter integer C_S_AXI_BUSER_WIDTH = 1;

  // Clock and Reset
  reg S_AXI_ACLK;
  reg S_AXI_ARESETN;

  // Write Address Channel
  reg [C_S_AXI_ID_WIDTH-1:0] S_AXI_AWID;
  reg [C_S_AXI_ADDR_WIDTH-1:0] S_AXI_AWADDR;
  reg [7:0] S_AXI_AWLEN;
  reg [2:0] S_AXI_AWSIZE;
  reg [1:0] S_AXI_AWBURST;
  reg S_AXI_AWLOCK;
  reg [3:0] S_AXI_AWCACHE;
  reg [2:0] S_AXI_AWPROT;
  reg [3:0] S_AXI_AWQOS;
  reg [3:0] S_AXI_AWREGION;
  reg [C_S_AXI_AWUSER_WIDTH-1:0] S_AXI_AWUSER;
  reg S_AXI_AWVALID;
  wire S_AXI_AWREADY;

  // Write Data Channel
  reg [C_S_AXI_ID_WIDTH-1:0] S_AXI_WID;
  reg [C_S_AXI_DATA_WIDTH-1:0] S_AXI_WDATA;
  reg [(C_S_AXI_DATA_WIDTH/8)-1:0] S_AXI_WSTRB;
  reg S_AXI_WLAST;
  reg [C_S_AXI_WUSER_WIDTH-1:0] S_AXI_WUSER;
  reg S_AXI_WVALID;
  wire S_AXI_WREADY;

  // Write Response Channel
  wire [C_S_AXI_ID_WIDTH-1:0] S_AXI_BID;
  wire [1:0] S_AXI_BRESP;
  wire [C_S_AXI_BUSER_WIDTH-1:0] S_AXI_BUSER;
  wire S_AXI_BVALID;
  reg S_AXI_BREADY;

  // Read Address Channel
  reg [C_S_AXI_ID_WIDTH-1:0] S_AXI_ARID;
  reg [C_S_AXI_ADDR_WIDTH-1:0] S_AXI_ARADDR;
  reg [7:0] S_AXI_ARLEN;
  reg [2:0] S_AXI_ARSIZE;
  reg [1:0] S_AXI_ARBURST;
  reg S_AXI_ARLOCK;
  reg [3:0] S_AXI_ARCACHE;
  reg [2:0] S_AXI_ARPROT;
  reg [3:0] S_AXI_ARQOS;
  reg [3:0] S_AXI_ARREGION;
  reg [C_S_AXI_ARUSER_WIDTH-1:0] S_AXI_ARUSER;
  reg S_AXI_ARVALID;
  wire S_AXI_ARREADY;

  // Read Data Channel
  wire [C_S_AXI_ID_WIDTH-1:0] S_AXI_RID;
  wire [C_S_AXI_DATA_WIDTH-1:0] S_AXI_RDATA;
  wire [1:0] S_AXI_RRESP;
  wire S_AXI_RLAST;
  wire [C_S_AXI_RUSER_WIDTH-1:0] S_AXI_RUSER;
  wire S_AXI_RVALID;
  reg S_AXI_RREADY;

  // Clock generation
  initial begin
    S_AXI_ACLK = 0;
    forever #5 S_AXI_ACLK = ~S_AXI_ACLK;  // 100MHz clock
  end

  // DUT instantiation
  axifull_slave_ram_8x32x32_i4_u1 dut (
      .clock(S_AXI_ACLK),
      .reset(!S_AXI_ARESETN),
      .S_AXI_AWID(S_AXI_AWID),
      .S_AXI_AWADDR(S_AXI_AWADDR),
      .S_AXI_AWLEN(S_AXI_AWLEN),
      .S_AXI_AWSIZE(S_AXI_AWSIZE),
      .S_AXI_AWBURST(S_AXI_AWBURST),
      .S_AXI_AWLOCK(S_AXI_AWLOCK),
      .S_AXI_AWCACHE(S_AXI_AWCACHE),
      .S_AXI_AWPROT(S_AXI_AWPROT),
      .S_AXI_AWQOS(S_AXI_AWQOS),
      .S_AXI_AWREGION(S_AXI_AWREGION),
      .S_AXI_AWUSER(S_AXI_AWUSER),
      .S_AXI_AWVALID(S_AXI_AWVALID),
      .S_AXI_AWREADY(S_AXI_AWREADY),
      .S_AXI_WDATA(S_AXI_WDATA),
      .S_AXI_WSTRB(S_AXI_WSTRB),
      .S_AXI_WLAST(S_AXI_WLAST),
      .S_AXI_WUSER(S_AXI_WUSER),
      .S_AXI_WVALID(S_AXI_WVALID),
      .S_AXI_WREADY(S_AXI_WREADY),
      .S_AXI_WID(S_AXI_WID),
      .S_AXI_BID(S_AXI_BID),
      .S_AXI_BRESP(S_AXI_BRESP),
      .S_AXI_BUSER(S_AXI_BUSER),
      .S_AXI_BVALID(S_AXI_BVALID),
      .S_AXI_BREADY(S_AXI_BREADY),
      .S_AXI_ARID(S_AXI_ARID),
      .S_AXI_ARADDR(S_AXI_ARADDR),
      .S_AXI_ARLEN(S_AXI_ARLEN),
      .S_AXI_ARSIZE(S_AXI_ARSIZE),
      .S_AXI_ARBURST(S_AXI_ARBURST),
      .S_AXI_ARLOCK(S_AXI_ARLOCK),
      .S_AXI_ARCACHE(S_AXI_ARCACHE),
      .S_AXI_ARPROT(S_AXI_ARPROT),
      .S_AXI_ARQOS(S_AXI_ARQOS),
      .S_AXI_ARREGION(S_AXI_ARREGION),
      .S_AXI_ARUSER(S_AXI_ARUSER),
      .S_AXI_ARVALID(S_AXI_ARVALID),
      .S_AXI_ARREADY(S_AXI_ARREADY),
      .S_AXI_RID(S_AXI_RID),
      .S_AXI_RDATA(S_AXI_RDATA),
      .S_AXI_RRESP(S_AXI_RRESP),
      .S_AXI_RLAST(S_AXI_RLAST),
      .S_AXI_RUSER(S_AXI_RUSER),
      .S_AXI_RVALID(S_AXI_RVALID),
      .S_AXI_RREADY(S_AXI_RREADY)
  );

  // Test variables
  reg [31:0] expected_data;
  integer i;

  // Initialize signals
  initial begin
    $dumpfile("axifull_slave_ram_tb.vcd");
    $dumpvars(0, axifull_slave_tb);
    // Initialize all inputs
    S_AXI_ARESETN = 0;
    S_AXI_AWID = 0;
    S_AXI_AWADDR = 0;
    S_AXI_AWLEN = 0;
    S_AXI_AWSIZE = 3'b010;  // 4 bytes
    S_AXI_AWBURST = 0;
    S_AXI_AWLOCK = 0;
    S_AXI_AWCACHE = 0;
    S_AXI_AWPROT = 0;
    S_AXI_AWQOS = 0;
    S_AXI_AWREGION = 0;
    S_AXI_AWUSER = 0;
    S_AXI_AWVALID = 0;
    S_AXI_WDATA = 0;
    S_AXI_WSTRB = 0;
    S_AXI_WLAST = 0;
    S_AXI_WUSER = 0;
    S_AXI_WVALID = 0;
    S_AXI_BREADY = 1;
    S_AXI_ARID = 0;
    S_AXI_ARADDR = 0;
    S_AXI_ARLEN = 0;
    S_AXI_ARSIZE = 3'b010;  // 4 bytes
    S_AXI_ARBURST = 0;
    S_AXI_ARLOCK = 0;
    S_AXI_ARCACHE = 0;
    S_AXI_ARPROT = 0;
    S_AXI_ARQOS = 0;
    S_AXI_ARREGION = 0;
    S_AXI_ARUSER = 0;
    S_AXI_ARVALID = 0;
    S_AXI_RREADY = 1;

    // Reset sequence
    #100;
    S_AXI_ARESETN = 1;
    #100;

    $display("Starting AXI4-Full Slave Testbench");

    // Test 1: Single Write Transaction
    $display("\n=== Test 1: Single Write Transaction ===");
    axi_write_single(32'h00010000, 32'hDEADBEEF, 4'hF);

    // Test 2: Single Read Transaction
    $display("\n=== Test 2: Single Read Transaction ===");
    axi_read_single(32'h00010000, 32'hDEADBEEF);

    // Test 3: Burst Write Transaction (Incremental)
    $display("\n=== Test 3: Burst Write Transaction (Incremental) ===");
    axi_write_burst_incr(32'h00010000, 4);
    axi_read_single(32'h00010000, 32'h1000);
    axi_read_single(32'h00010004, 32'h1001);
    axi_read_single(32'h00010008, 32'h1002);
    axi_read_single(32'h0001000C, 32'h1003);

    // Test 4: Burst Read Transaction (Incremental)
    $display("\n=== Test 4: Burst Read Transaction (Incremental) ===");
    axi_read_burst_incr(32'h00010000, 4);

    // Test 5: Fixed Burst Write
    $display("\n=== Test 5: Fixed Burst Write ===");
    axi_write_burst_fixed(32'h00010010, 3);
    axi_read_single(32'h00010010, 32'h2003);

    // Test 6: Fixed Burst Read
    $display("\n=== Test 6: Fixed Burst Read ===");
    axi_read_burst_fixed(32'h00010010, 3);

    $display("\n=== All Tests Completed ===");
    #1000;
    $finish;
  end

  // Task: Single Write Transaction
  task axi_write_single;
    input [31:0] addr;
    input [31:0] data;
    input [3:0] strb;
    begin
      $display("Writing 0x%08h to address 0x%08h", data, addr);

      @(posedge S_AXI_ACLK);
      S_AXI_AWADDR  = addr;
      S_AXI_AWLEN   = 0;  // Single transfer
      S_AXI_AWBURST = 2'b01;  // INCR
      S_AXI_AWVALID = 1;
      S_AXI_WDATA   = data;
      S_AXI_WSTRB   = strb;
      S_AXI_WLAST   = 1;
      S_AXI_WVALID  = 1;

      // Wait for address and data acceptance
      wait (S_AXI_AWREADY);
      @(posedge S_AXI_ACLK);
      S_AXI_AWVALID = 0;

      wait (S_AXI_WREADY);
      @(posedge S_AXI_ACLK);

      // Wait for write response
      wait (S_AXI_BVALID);
      @(posedge S_AXI_ACLK);
      $display("Write completed with response: %02b", S_AXI_BRESP);
    end
  endtask

  // Task: Single Read Transaction
  task axi_read_single;
    input [31:0] addr;
    input [31:0] expected;
    begin
      $display("Reading from address 0x%08h, expecting 0x%08h", addr, expected);

      @(posedge S_AXI_ACLK);
      S_AXI_ARADDR  = addr;
      S_AXI_ARLEN   = 0;  // Single transfer
      S_AXI_ARBURST = 2'b01;  // INCR
      S_AXI_ARVALID = 1;

      // Wait for address acceptance
      wait (S_AXI_ARREADY);
      @(posedge S_AXI_ACLK);
      S_AXI_ARVALID = 0;

      // Wait for read data
      wait (S_AXI_RVALID);
      @(posedge S_AXI_ACLK);

      if (S_AXI_RDATA == expected) $display("Read successful: Got 0x%08h", S_AXI_RDATA);
      else $display("Read mismatch: Expected 0x%08h, Got 0x%08h", expected, S_AXI_RDATA);
    end
  endtask

  // Task: Burst Write Transaction (Incremental)
  task axi_write_burst_incr;
    input [31:0] start_addr;
    input [7:0] burst_len;
    begin
      $display("Burst write: %d transfers starting at 0x%08h", burst_len + 1, start_addr);

      @(posedge S_AXI_ACLK);
      S_AXI_AWADDR  = start_addr;
      S_AXI_AWLEN   = burst_len;
      S_AXI_AWBURST = 2'b01;  // INCR
      S_AXI_AWVALID = 1;

      // Wait for address acceptance
      wait (S_AXI_AWREADY);
      @(posedge S_AXI_ACLK);
      S_AXI_AWVALID = 0;

      // Send data beats
      for (integer i = 0; i <= burst_len; i = i + 1) begin
        @(posedge S_AXI_ACLK);
        S_AXI_WDATA  = 32'h1000 + i;
        S_AXI_WSTRB  = 4'hF;
        S_AXI_WVALID = 1;
        S_AXI_WLAST  = (8'(i) == burst_len);

        wait (S_AXI_WREADY);
        $display("  Beat %d: Writing 0x%08h", i, S_AXI_WDATA);
      end

      @(posedge S_AXI_ACLK);
      S_AXI_WVALID = 0;

      // Wait for write response
      wait (S_AXI_BVALID);
      @(posedge S_AXI_ACLK);
      $display("Burst write completed");
    end
  endtask

  // Task: Burst Read Transaction (Incremental)
  task axi_read_burst_incr;
    input [31:0] start_addr;
    input [7:0] burst_len;
    begin
      $display("Burst read: %d transfers starting at 0x%08h", burst_len + 1, start_addr);

      @(posedge S_AXI_ACLK);
      S_AXI_ARADDR  = start_addr;
      S_AXI_ARLEN   = burst_len;
      S_AXI_ARBURST = 2'b01;  // INCR
      S_AXI_ARVALID = 1;

      // Wait for address acceptance
      wait (S_AXI_ARREADY);
      @(posedge S_AXI_ACLK);
      S_AXI_ARVALID = 0;

      @(posedge S_AXI_ACLK);
      // Receive data beats
      for (i = 0; i <= burst_len; i = i + 1) begin
        wait (S_AXI_RVALID);
        $display("  Beat %d: Read 0x%08h, RLAST=%b", i, S_AXI_RDATA, S_AXI_RLAST);
        @(posedge S_AXI_ACLK);
        @(posedge S_AXI_ACLK);
      end

      $display("Burst read completed");
    end
  endtask

  // Task: Burst Write Transaction (Fixed)
  task axi_write_burst_fixed;
    input [31:0] addr;
    input [7:0] burst_len;
    begin
      $display("Fixed burst write: %d transfers to address 0x%08h", burst_len + 1, addr);

      @(posedge S_AXI_ACLK);
      S_AXI_AWADDR  = addr;
      S_AXI_AWLEN   = burst_len;
      S_AXI_AWBURST = 2'b00;  // FIXED
      S_AXI_AWVALID = 1;

      // Wait for address acceptance
      wait (S_AXI_AWREADY);
      @(posedge S_AXI_ACLK);
      S_AXI_AWVALID = 0;

      // Send data beats
      for (integer i = 0; i <= burst_len; i = i + 1) begin
        @(posedge S_AXI_ACLK);
        S_AXI_WDATA  = 32'h2000 + i;
        S_AXI_WSTRB  = 4'hF;
        S_AXI_WVALID = 1;
        S_AXI_WLAST  = (8'(i) == burst_len);

        wait (S_AXI_WREADY);
        $display("  Beat %d: Writing 0x%08h to fixed address", i, S_AXI_WDATA);
      end

      @(posedge S_AXI_ACLK);
      S_AXI_WVALID = 0;
      S_AXI_WLAST  = 0;

      // Wait for write response
      wait (S_AXI_BVALID);
      @(posedge S_AXI_ACLK);
      $display("Fixed burst write completed");
    end
  endtask

  // Task: Burst Read Transaction (Fixed)
  task axi_read_burst_fixed;
    input [31:0] addr;
    input [7:0] burst_len;
    begin
      $display("Fixed burst read: %d transfers from address 0x%08h", burst_len + 1, addr);

      @(posedge S_AXI_ACLK);
      S_AXI_ARADDR  = addr;
      S_AXI_ARLEN   = burst_len;
      S_AXI_ARBURST = 2'b00;  // FIXED
      S_AXI_ARVALID = 1;

      // Wait for address acceptance
      wait (S_AXI_ARREADY);
      @(posedge S_AXI_ACLK);
      S_AXI_ARVALID = 0;

      // Receive data beats
      @(posedge S_AXI_ACLK);
      for (i = 0; i <= burst_len; i = i + 1) begin
        wait (S_AXI_RVALID);
        $display("  Beat %d: Read 0x%08h from fixed address, RLAST=%b", i, S_AXI_RDATA,
                 S_AXI_RLAST);
        @(posedge S_AXI_ACLK);
        @(posedge S_AXI_ACLK);
      end

      $display("Fixed burst read completed");
    end
  endtask

  // Monitor for debugging
  initial begin
    $monitor(
        "Time: %0t | AWVALID: %b | AWREADY: %b | WVALID: %b | WREADY: %b | BVALID: %b | ARVALID: %b | ARREADY: %b | RVALID: %b | RREADY: %b",
        $time, S_AXI_AWVALID, S_AXI_AWREADY, S_AXI_WVALID, S_AXI_WREADY, S_AXI_BVALID,
        S_AXI_ARVALID, S_AXI_ARREADY, S_AXI_RVALID, S_AXI_RREADY);
  end

endmodule
