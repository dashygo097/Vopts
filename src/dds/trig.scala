package dds
import utils.{Float, Config}

import scala.math._

import chisel3._
import chisel3.util._

class TrigIO extends Bundle with Config {
  val mag = Input(new Float)
  val phaseDelta = Input(UInt(phaseWidth.W))
  val out = Output(new Float)
}

class TrigCore(freq: Int) extends Module with Config {
  val io = IO(new TrigIO)
  val phase = RegInit(0.U(phaseWidth.W))
  val lutAddr = Wire(UInt(log2Ceil(lutWidth).W))
  val poff = (freq * pow(2.0, phaseWidth) / sampleFreq).toInt.U

  val sine_rom = VecInit(
    (0 until lutWidth).map { i => 
      val angle = 2 * Pi * i / lutWidth
      val value = sin(angle)
      Float(value)
    }
  )

  phase := phase + io.phaseDelta + poff

  lutAddr := phase(phaseWidth - 1, phaseWidth - log2Ceil(lutWidth))
  io.out := sine_rom(lutAddr) * io.mag

}
