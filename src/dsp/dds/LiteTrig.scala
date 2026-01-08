package vopts.dsp.dds

import vopts.utils._
import chisel3._
import chisel3.util._
import scala.math._

class LiteTrigIO[T <: Data](gen: T, phaseWidth: Int) extends Bundle {
  val mag        = Input(gen)
  val phaseDelta = Input(UInt(phaseWidth.W))
  val out        = Output(gen)
}

class LiteTrigDDS[T <: Data](gen: T, freq: Long, phaseWidth: Int, lutWidth: Int, clkFreq: Long)(implicit
  analog: Analog[T]
) extends Module {
  override def desiredName = s"dds_lite_f$freq"
  val io                   = IO(new LiteTrigIO(gen, phaseWidth)).suggestName("DDS_LiteTRI")
  val phase                = RegInit(0.U(phaseWidth.W))
  val lutAddr              = Wire(UInt(log2Ceil(lutWidth).W))

  val poff = (freq * (2 << phaseWidth) / clkFreq).toInt.U

  val sine_rom = VecInit(
    (0 until lutWidth).map { i =>
      val angle = 2 * Pi * i / lutWidth
      val value = sin(angle)
      gen.fromDouble(value)
    }
  )

  phase := phase + io.phaseDelta + poff

  lutAddr := phase(phaseWidth - 1, phaseWidth - log2Ceil(lutWidth))
  // FIXME: Multiplier IP Should be used for better timing
  io.out  := sine_rom(lutAddr) * io.mag
}
