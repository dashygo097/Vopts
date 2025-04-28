package data.fp 
import utils._

import chisel3._

class UpSamplerIO(inDataWidth: Int, inBp: Int) extends Bundle {
  val in = Input(new FP(inDataWidth, inBp))
  val out = Output(new FP) 
}

class ScaledUpSamplerIO(inDataWidth: Int, inBp: Int, ctrlWidth: Int) extends Bundle with Config {
  val ctrl = Input(UInt(ctrlWidth.W))
  val in = Input(new FP(inDataWidth, inBp))
  val out = Output(new FP)
}

class UpSamplerCore(inDataWidth: Int, inBp: Int) extends Module with Config {
  val io = IO(new UpSamplerIO(inDataWidth, inBp))
  val converter = Module(new FPConverterCore(inDataWidth, inBp, dataWidth, bp))
  converter.io.in := io.in
  io.out := converter.io.out
}

class ScaledUpSamplerCore(inDataWidth: Int, inBp: Int, ctrlWidth: Int) extends Module with Config {
  val io = IO(new ScaledUpSamplerIO(inDataWidth, inBp, ctrlWidth))
  val converter = Module(new FPConverterCore(inDataWidth, inBp, dataWidth, bp))
  converter.io.in := io.in * (io.ctrl + 1.U)
  io.out := converter.io.out
}

object UpSample {
  def apply(in: FP): FP = {
    val sampler = Module(new UpSamplerCore(in.get_datawidth(), in.get_bp()))
    sampler.io.in := in
    sampler.io.out
  }
}

object ScaledUpSample {
  def apply(in: FP, ctrl: UInt): FP = {
    val sampler = Module(new ScaledUpSamplerCore(in.get_datawidth(), in.get_bp(), ctrl.getWidth))
    sampler.io.in := in
    sampler.io.ctrl := ctrl
    sampler.io.out
  }
}
