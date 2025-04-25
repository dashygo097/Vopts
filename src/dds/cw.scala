package dds
import utils.{Float, Config}

import scala.math._

import chisel3._
import chisel3.util._

class CWIO extends Bundle {
  val out = Output(new Float)
}

class CWCore(mag : Double, freq: Int, pha: Double) extends Module with Config {
  val io = IO(new CWIO)
  val phase = RegInit(0.U(phaseWidth.W))
  val lutAddr = Wire(UInt(log2Ceil(lutWidth).W))
  val poff = (freq * pow(2.0, phaseWidth) / sampleFreq).toInt.U

  val sine_rom = VecInit(
    (0 until lutWidth).map { i => 
      val angle = 2 * Pi * i / lutWidth + pha * Pi / 180
      val value = sin(angle) * mag
      Float(value)
    }
  )

  phase := phase + poff
  lutAddr := phase(phaseWidth - 1, phaseWidth - log2Ceil(lutWidth))
  io.out := sine_rom(lutAddr)

}
