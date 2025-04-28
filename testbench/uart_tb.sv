`timescale 1ns / 1ps

module uart_tb;
  // Clock and reset
  reg clk = 0;
  reg reset = 1;

  // UART signals
  wire txd;
  wire rxd;
  wire tx_busy;
  wire rx_error;
  wire tx_tick;
  wire rx_tick;

  // Data channels
  reg [7:0] tx_data = 0;
  reg tx_valid = 0;
  wire tx_ready;

  wire [7:0] rx_data;
  wire rx_valid;
  reg rx_ready = 0;

  // Loop back for testing
  assign rxd = txd;

  // DUT instantiation - adjust port names to match your actual RTL
  UartCore dut (
      .clock(clk),
      .reset(reset),

      // TX connections
      .io_tx_txd(txd),
      .io_tx_channel_bits(tx_data),
      .io_tx_channel_valid(tx_valid),
      .io_tx_channel_ready(tx_ready),
      .io_tx_tick(tx_tick),
      .io_tx_busy(tx_busy),

      // RX connections
      .io_rx_rxd(rxd),
      .io_rx_channel_bits(rx_data),
      .io_rx_channel_valid(rx_valid),
      .io_rx_channel_ready(rx_ready),
      .io_rx_tick(rx_tick),
      .io_rx_error(rx_error)
  );

  // Clock generation - use always block for Verilator compatibility
  always #5 clk = ~clk;

  // For Verilator, we need a simpler test approach
  reg [7:0] received_data = 0;
  integer test_phase = 0;
  integer i = 0;
  reg [7:0] test_data[0:3];
  reg [7:0] rx_test_data[0:3];

  // Test sequence using always block for Verilator
  always @(posedge clk) begin
    case (test_phase)
      0: begin
        // Initialize test data
        test_data[0] = 8'h55;
        test_data[1] = 8'hAA;
        test_data[2] = 8'h33;
        test_data[3] = 8'hCC;
        reset <= 1;
        if (i >= 5) begin
          reset <= 0;
          test_phase <= 1;
          i <= 0;
        end else i <= i + 1;
      end

      1: begin
        // Wait for stable state
        if (i >= 10) begin
          test_phase <= 2;
          i <= 0;
        end else i <= i + 1;
      end

      2: begin
        // Send test byte 0xA5
        tx_data  <= 8'hA5;
        tx_valid <= 1;
        if (tx_ready) begin
          test_phase <= 3;
        end
      end

      3: begin
        // Wait for TX to complete
        tx_valid <= 0;
        if (!tx_busy) begin
          test_phase <= 4;
        end
      end

      4: begin
        // Receive byte
        rx_ready <= 1;
        if (rx_valid) begin
          received_data <= rx_data;
          test_phase <= 5;
        end
      end

      5: begin
        // Check received data
        rx_ready <= 0;
        $display("Test 1: Sent 0xA5, Received 0x%h", received_data);
        test_phase <= 6;
        i <= 0;
      end

      6: begin
        // Multiple byte test setup
        $display("Test 2: Multiple byte transfer");
        test_phase <= 7;
      end

      7: begin
        // Send test byte i
        tx_data  <= test_data[i];
        tx_valid <= 1;
        if (tx_ready) begin
          test_phase <= 8;
        end
      end

      8: begin
        // Wait for TX to complete
        tx_valid <= 0;
        if (!tx_busy) begin
          test_phase <= 9;
        end
      end

      9: begin
        // Receive byte
        rx_ready <= 1;
        if (rx_valid) begin
          rx_test_data[i] <= rx_data;
          test_phase <= 10;
        end
      end

      10: begin
        // Check received data
        rx_ready <= 0;
        $display("Test 2.%0d: Sent 0x%h, Received 0x%h", i, test_data[i], rx_test_data[i]);

        if (i == 3) begin
          test_phase <= 11;
          i <= 0;
        end else begin
          i <= i + 1;
          test_phase <= 7;
        end
      end

      11: begin
        // Test complete
        $display("All tests completed");
        $finish;
      end

      default: begin
        test_phase <= 11;
      end
    endcase
  end

  // Waveform dump for Verilator
  initial begin
    $dumpfile("uart.vcd");
    $dumpvars(0, uart_tb);
  end
endmodule
