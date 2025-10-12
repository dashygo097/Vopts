`timescale 1ns / 1ps
`include "../../build/task2.v"

module tb_signal_measure_ctrl;

  // 时钟与复位信号
  reg clk;
  reg rst_n;

  // 控制与输入信号
  reg enable;
  reg sig_in;

  // 输出信号
  wire busy;
  wire finish;
  wire [25:0] freq;
  wire [7:0] duty;
  wire [19:0] high_time;
  wire [19:0] low_time;

  // 系统时钟：50MHz -> 20ns 周期
  initial clk = 0;
  always #10 clk = ~clk;

  // 被测模块实例化
  signal_measure_ctrl #(
      .CLK_FREQ(50_000_000)
  ) dut (
      .clk(clk),
      .rst_n(rst_n),
      .enable(enable),
      .sig_in(sig_in),
      .busy(busy),
      .finish(finish),
      .freq(freq),
      .duty(duty),
      .high_time(high_time),
      .low_time(low_time)
  );

  // 输入信号：可调频率与占空比
  reg [19:0] period_ns = 2000;  // 输入信号周期（单位：ns）=> 500kHz
  reg [19:0] duty_percent = 40;  // 占空比40%
  real high_ns, low_ns;

  initial begin
    high_ns = period_ns * duty_percent / 100.0;
    low_ns  = period_ns - high_ns;
  end

  // 模拟信号产生器
  initial begin
    sig_in = 0;
    forever begin
      #(high_ns) sig_in = 1;
      #(low_ns) sig_in = 0;
    end
  end

  // 主仿真过程
  initial begin
    $display("==== Signal Measure Test Start ====");
    $dumpfile("signal_measure_ctrl.vcd");
    $dumpvars(0, tb_signal_measure_ctrl);

    // 初始化
    rst_n  = 0;
    enable = 0;
    #200;
    rst_n = 1;

    // 启动测量
    #1000;
    enable = 1;  // 启动测量
    #20;
    enable = 0;  // 保持一个时钟周期

    // 等待完成
    wait (finish == 1);
    #50;

    $display(">>> 测量完成: freq=%d Hz, duty=%d%%, high_time=%d, low_time=%d", freq, duty,
             high_time, low_time);

    // 改变输入信号（占空比50%，周期1000ns => 1MHz）
    period_ns = 1000;
    duty_percent = 50;
    high_ns = period_ns * duty_percent / 100.0;
    low_ns = period_ns - high_ns;

    #20000;
    enable = 1;
    #20;
    enable = 0;
    wait (finish == 1);
    #50;

    $display(">>> 测量完成: freq=%d Hz, duty=%d%%, high_time=%d, low_time=%d", freq, duty,
             high_time, low_time);

    #10000;
    $display("==== Simulation End ====");
    $finish;
  end

endmodule
