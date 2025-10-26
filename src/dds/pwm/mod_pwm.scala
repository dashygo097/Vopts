package dds.pwm

import chisel3._
import chisel3.util._

class ModPWMIO extends Bundle {
  val dutyCycle = Input(UInt(7.W))
  val out       = Output(Bool())
}

class ModPWMDDS(freq: Int, clkFreq: Int) extends Module {
  override def desiredName: String = s"pwd_mod_f$freq"
  val io                           = IO(new ModPWMIO).suggestName("DDS_ModPWM")
  val freqDivider                  = (clkFreq / freq).toInt

  val counter = RegInit(0.U(log2Ceil(freqDivider).W))
  val duty    = RegInit(0.U(log2Ceil(freqDivider).W + 7.W))
  val pwmOut  = RegInit(false.B)

  duty := (freqDivider.asUInt * io.dutyCycle) / 100.U

  counter := Mux(counter === (freqDivider - 1).U, 0.U, counter + 1.U)
  when(counter < duty) {
    pwmOut := true.B
  }.otherwise {
    pwmOut := false.B
  }

  io.out := pwmOut
}

object ModPWMDDS {
  def apply(freq: Int, clkFreq: Int, dutyCycle: UInt): Bool = {
    val modPWM = Module(new ModPWMDDS(freq, clkFreq))
    modPWM.io.dutyCycle := dutyCycle
    modPWM.io.out
  }
}
