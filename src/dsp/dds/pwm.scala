package dsp.dds

import chisel3._
import chisel3.util._

class PWMIO extends Bundle {
  val out = Output(Bool())
}

class PWMDDS(freq: Int, dutyCycle: Double, clkFreq: Int) extends Module {
  override def desiredName: String = s"pwd_f${freq}_d${(dutyCycle * 100).toInt}"
  val io                           = IO(new PWMIO).suggestName("DDS_PWM")

  val freqDivider = (clkFreq / freq).toInt
  val duty        = (freqDivider * dutyCycle).toInt.U
  val counter     = RegInit(0.U(log2Ceil(freqDivider).W))
  val pwmOut      = RegInit(false.B)

  counter := Mux(counter === (freqDivider - 1).U, 0.U, counter + 1.U)
  when(counter < duty) {
    pwmOut := true.B
  }.otherwise {
    pwmOut := false.B
  }

  io.out := pwmOut
}

object PWMDDS {
  def apply(freq: Int, dutyCycle: Double, clkFreq: Int): Bool = {
    val pwm = Module(new PWMDDS(freq, dutyCycle, clkFreq))
    pwm.io.out
  }
}
