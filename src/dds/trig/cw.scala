package dds.trig
import utils._

import datatype.fp.FP

import scala.math._

import chisel3._
import chisel3.util._

class CWIO extends Bundle {
  val out = Output(new FP)
}

class CWCore(mag : Double, freq: Int, pha: Double) extends Module with Config {
  val io = IO(new CWIO)
  val phase = RegInit(0.U(phaseWidth.W))
  val lutAddr = Wire(UInt(log2Ceil(lutWidth).W))
  val poff = (freq * pow(2.0, phaseWidth) / sampleFreq).toInt.U

  val sine_rom = VecInit(
    (0 until lutWidth).map { i => 
      val angle = 2 * Pi * i / lutWidth + pha * Pi / 180
      val value = sin(angle) 
      FP(value)
    }
  )

  phase := phase + poff
  lutAddr := phase(phaseWidth - 1, phaseWidth - log2Ceil(lutWidth))
  io.out := sine_rom(lutAddr) * mag
}

 class MultiCWCore(mags: Seq[Double], freqs: Seq[Int], phas: Seq[Double]) extends Module with Config {
  val nChannels = mags.length
  require(freqs.length == nChannels && phas.length == nChannels)

  val io = IO(Vec(nChannels, new CWIO))

  val sine_rom = VecInit((0 until lutWidth).map { i =>
    val angle = 2 * Pi * i / lutWidth
    val value = sin(angle)
    FP(value)
  })

  for (ch <- 0 until nChannels) {
    val phase = RegInit(0.U(phaseWidth.W))
    val poff = (freqs(ch) * pow(2.0, phaseWidth) / sampleFreq).toInt.U
    val pha_offset = ((phas(ch) / 360.0) * pow(2.0, phaseWidth)).toInt.U

    phase := phase + poff
    val addr = ((phase + pha_offset)(phaseWidth - 1, phaseWidth - log2Ceil(lutWidth))).asUInt
    io(ch).out := sine_rom(addr) * mags(ch)
  }
}
