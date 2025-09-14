package utils

import chisel3._

class FPUpSamplerIO(inDataWidth: Int, inBp: Int) extends Bundle {
  val in = Input(new FP(inDataWidth, inBp))
  val out = Output(new FP) 
}

class FPScaledUpSamplerIO(inDataWidth: Int, inBp: Int, ctrlWidth: Int) extends Bundle with Config {
  val ctrl = Input(UInt(ctrlWidth.W))
  val in = Input(new FP(inDataWidth, inBp))
  val out = Output(new FP)
}

class FPUpSampler(inDataWidth: Int, inBp: Int) extends Module with Config {
  override def desiredName = s"fp_upsampler_${inDataWidth}w${inBp}b"
  val io = IO(new FPUpSamplerIO(inDataWidth, inBp))
  val converter = Module(new FPConverter(inDataWidth, inBp, dataWidth, binaryPoint))
  converter.io.in := io.in
  io.out := converter.io.out
}

class FPScaledUpSampler(inDataWidth: Int, inBp: Int, ctrlWidth: Int) extends Module with Config {
  override def desiredName = s"fp_upsampler_s${ctrlWidth}_${inDataWidth}w${inBp}b"
  val io = IO(new FPScaledUpSamplerIO(inDataWidth, inBp, ctrlWidth))
  val converter = Module(new FPConverter(inDataWidth, inBp, dataWidth, binaryPoint))
  converter.io.in := io.in * (io.ctrl + 1.U)
  io.out := converter.io.out
}

object FPUpSample {
  def apply(in: FP): FP = {
    val sampler = Module(new FPUpSampler(in.dw(), in.bp()))
    sampler.io.in := in
    sampler.io.out
  }
}

object FPScaledUpSample {
  def apply(in: FP, ctrl: UInt): FP = {
    val sampler = Module(new FPScaledUpSampler(in.dw(), in.bp(), ctrl.getWidth))
    sampler.io.in := in
    sampler.io.ctrl := ctrl
    sampler.io.out
  }
}
