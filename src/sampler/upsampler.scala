package sampler 
import utils.{Float, Config, FloatConverterCore}

import math.pow

import chisel3._
import chisel3.util._

class UpSamplerIO(inDataWidth: Int, inBp: Int) extends Bundle {
  val in = Input(new Float(inDataWidth, inBp))
  val out = Output(new Float) 
}

class ScaledUpSamplerIO(inDataWidth: Int, inBp: Int, ctrlWidth: Int) extends Bundle with Config {
  val ctrl = Input(UInt(ctrlWidth.W))
  val in = Input(new Float(inDataWidth, inBp))
  val out = Output(new Float)
}

class UpSamplerCore(inDataWidth: Int, inBp: Int) extends Module with Config {
  val io = IO(new UpSamplerIO(inDataWidth, inBp))
  val converter = Module(new FloatConverterCore(inDataWidth, inBp, dataWidth, bp))
  converter.io.in := io.in
  io.out := converter.io.out
}

class ScaledUpSamplerCore(inDataWidth: Int, inBp: Int, ctrlWidth: Int) extends Module with Config {
  val io = IO(new ScaledUpSamplerIO(inDataWidth, inBp, ctrlWidth))
  val converter = Module(new FloatConverterCore(inDataWidth, inBp, dataWidth, bp))
  converter.io.in := io.in * (io.ctrl + 1.U)
  io.out := converter.io.out
}

object UpSample {
  def apply(in: Float): Float = {
    val sampler = Module(new UpSamplerCore(in.get_datawidth(), in.get_bp()))
    sampler.io.in := in
    sampler.io.out
  }
}

object ScaledUpSample {
  def apply(in: Float, ctrl: UInt): Float = {
    val sampler = Module(new ScaledUpSamplerCore(in.get_datawidth(), in.get_bp(), ctrl.getWidth))
    sampler.io.in := in
    sampler.io.ctrl := ctrl
    sampler.io.out
  }
}
