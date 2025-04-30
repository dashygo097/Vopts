package dds.trig
import utils._

import datatype.fp._

import scala.math._

import chisel3._
import chisel3.util._

class BaseTrigIO extends Bundle with Config {
  val mag = Input(new FP)
  val phaseDelta = Input(UInt(phaseWidth.W))
  val out = Output(new FP)
}

class BaseTrigCore(freq: Int) extends Module with Config {
  val io = IO(new BaseTrigIO)
  val phase = RegInit(0.U(phaseWidth.W))
  val lutAddr = Wire(UInt(log2Ceil(lutWidth).W))

  val poff = (freq * pow(2.0, phaseWidth) / sampleFreq).toInt.U

  val sine_rom = VecInit(
    (0 until lutWidth).map { i => 
      val angle = 2 * Pi * i / lutWidth
      val value = sin(angle)
      FP(value)
    }
  )

  phase := phase + io.phaseDelta + poff

  lutAddr := phase(phaseWidth - 1, phaseWidth - log2Ceil(lutWidth))
  io.out := sine_rom(lutAddr) * io.mag
}
