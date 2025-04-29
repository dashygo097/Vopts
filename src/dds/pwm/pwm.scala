package dds.pwm
import utils._

import chisel3._
import chisel3.util._

class PWMIO extends Bundle {
  val out = Output(Bool())
}

class PWMCore(freq: Int, dutyCycle: Double) extends Module with Config {
  val io = IO(new PWMIO)

  val freqDivider = (clkFreq / freq).toInt
  val duty = (freqDivider * dutyCycle).toInt.U
  val counter = RegInit(0.U(log2Ceil(freqDivider).W))
  val pwmOut = RegInit(false.B)

  counter := Mux(counter === (freqDivider - 1).U, 0.U, counter + 1.U)
  when(counter < duty) {
    pwmOut := true.B
  } .otherwise {
    pwmOut := false.B
  }

  io.out := pwmOut
}


