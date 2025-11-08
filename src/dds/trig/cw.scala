package dds.trig

import scala.math._
import utils._
import chisel3._
import chisel3.util._

class CWDDS[T <: Data](
  gen: T,
  mag: Double,
  freq: Int,
  pha: Double,
  phaseWidth: Int,
  lutWidth: Int,
  clkFreq: Int
)(implicit analog: Analog[T])
    extends Module {
  override def desiredName = s"dds_cw_m${(mag * 1000).toInt}_f${freq}_p${(pha * 180 / Pi).toInt}"
  val io                   = IO(new SO(gen)).suggestName("DDS_CW")
  val phase                = RegInit(0.U(phaseWidth.W))
  val lutAddr              = Wire(UInt(log2Ceil(lutWidth).W))
  val poff                 = (freq * (2 << phaseWidth) / clkFreq).toInt.U

  val sine_rom = VecInit(
    (0 until lutWidth).map { i =>
      val angle = 2 * Pi * i / lutWidth + pha * Pi / 180
      val value = sin(angle)
      gen.fromDouble(value)
    }
  )

  phase   := phase + poff
  lutAddr := phase(phaseWidth - 1, phaseWidth - log2Ceil(lutWidth))
  io.out  := sine_rom(lutAddr) * gen.fromDouble(mag)
}

class MultiCWDDS[T <: Data](
  gen: T,
  mags: Seq[Double],
  freqs: Seq[Int],
  phas: Seq[Double],
  phaseWidth: Int,
  lutWidth: Int,
  clkFreq: Int
)(implicit analog: Analog[T])
    extends Module {
  override def desiredName = s"dds_multi_cw_x${mags.length}"
  val nChannels            = mags.length
  require(freqs.length == nChannels && phas.length == nChannels)

  val io = IO(new MO(gen, mags.length)).suggestName("DDS_MultiCW")

  val sine_rom = VecInit((0 until lutWidth).map { i =>
    val angle = 2 * Pi * i / lutWidth
    val value = sin(angle)
    gen.fromDouble(value)
  })

  for (ch <- 0 until nChannels) {
    val phase      = RegInit(0.U(phaseWidth.W))
    val poff       = (freqs(ch) * (2 << phaseWidth) / clkFreq).toInt.U
    val pha_offset = ((phas(ch) / 360.0) * (2 << phaseWidth)).toInt.U

    phase := phase + poff
    val addr = (phase + pha_offset)(phaseWidth - 1, phaseWidth - log2Ceil(lutWidth)).asUInt
    io.out(ch) := sine_rom(addr) * gen.fromDouble(mags(ch))
  }
}

object CWDDS {
  def apply[T <: Data](
    gen: T,
    mag: Double,
    freq: Int,
    pha: Double,
    phaseWidth: Int,
    lutWidth: Int,
    clkFreq: Int
  )(implicit analog: Analog[T]): T = {
    val dds = Module(new CWDDS(gen, mag, freq, pha, phaseWidth, lutWidth, clkFreq))
    dds.io.out
  }
}

object MultiCWDDS {
  def apply[T <: Data](
    gen: T,
    mags: Seq[Double],
    freqs: Seq[Int],
    phas: Seq[Double],
    phaseWidth: Int,
    lutWidth: Int,
    clkFreq: Int
  )(implicit analog: Analog[T]): Seq[T] = {
    val dds = Module(new MultiCWDDS(gen, mags, freqs, phas, phaseWidth, lutWidth, clkFreq))
    dds.io.out
  }
}
