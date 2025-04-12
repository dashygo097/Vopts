package pwm
import global.Config

import chisel3._
import chisel3.util._

class PWMCoreIO extends Bundle {
  val dutyCycle = Input(UInt(6.W)) 
  val pwmOut = Output(Bool())
}

class PWMCore(freq: Int) extends Module with Config {
  val io = IO(new PWMCoreIO)
  val freqDivider = clkFreq / freq
  val counter = RegInit(0.U(6.W))
  val pwmReg = RegInit(false.B)

  when(counter === (freqDivider - 1).U) {
    counter := 0.U
    pwmReg := !pwmReg
  } .otherwise {
    counter := counter + 1.U
  }

  io.pwmOut := Mux(counter < io.dutyCycle, true.B, false.B)
}
