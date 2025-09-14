package dds.trig

import scala.math._
import utils._
import chisel3._
import chisel3.util._

class LiteTrigIO extends Bundle with Config {
  val mag = Input(new FP)
  val phaseDelta = Input(UInt(phaseWidth.W))
  val out = Output(new FP)
}

class LiteTrigDDS(freq: Int) extends Module with Config {
  override def desiredName = s"dds_lite_f${freq}"
  val io = IO(new LiteTrigIO).suggestName("DDS_LiteTRI")
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
