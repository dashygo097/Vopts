package dsp.fft

import scala.math._
import utils._
import chisel3._
import chisel3.util._

class R2MDCFFTIO(dw: Int, bp: Int) extends Bundle {
  val in        = Input(new FPComplex(dw, bp))
  val in_valid  = Input(Bool())
  val out1      = Output(new FPComplex(dw, bp))
  val out2      = Output(new FPComplex(dw, bp))
  val out_valid = Output(Bool())
  val busy      = Output(Bool())
}

class R2MDCFFT(fftLength: Int, dw: Int, bp: Int) extends Module {
  override def desiredName = s"fft_radix2_mdc_n$fftLength"
  val io                   = IO(new R2MDCFFTIO(dw, bp)).suggestName("FFT")

  val num_stages = log2Ceil(fftLength)
  val cnt        = RegInit(0.U((1 + num_stages).W))
  val busy       = cnt =/= 0.U

  when(io.in_valid || busy) {
    cnt := Mux(cnt === (fftLength * 3 / 2 - 1).U, 0.U, cnt + 1.U)
  }
  io.busy := busy

  val twiddle_rom = (0 until num_stages).map { stage =>
    val rom = (0 until fftLength / 2 by pow(2, stage).toInt).map { i =>
      val angle = 2 * Pi * i / fftLength
      val real  = cos(angle)
      val imag  = sin(angle)
      FPComplex(dw, bp, real, imag)
    }
    rom
  }

  def twiddle(stage: Int, i: UInt): FPComplex = {
    val tw = VecInit(twiddle_rom(stage).map(x => x))
    tw(i)
  }

  val out_buffers = VecInit(Seq.fill(num_stages)(VecInit(Seq.fill(2)(FPComplex(dw, bp, 0.0, 0.0)))))

  out_buffers(0)(0) := io.in
  out_buffers(0)(1) := io.in

  for (stage <- 1 until num_stages) {
    val delay        = fftLength / pow(2, stage).toInt
    val wn           = twiddle(stage - 1, cnt(num_stages - stage - 1, 0))
    val (bf_1, bf_2) =
      Butterfly(ShiftRegister(out_buffers(stage - 1)(0), delay), out_buffers(stage - 1)(1), wn)
    val (cm1, cm2)   = Commutator(bf_1, ShiftRegister(bf_2, delay / 2), cnt(num_stages - stage - 1))
    out_buffers(stage)(0) := cm1
    out_buffers(stage)(1) := cm2
  }

  val outLast  = RegNext(out_buffers(num_stages - 1)(0))
  val out1     = RegNext(outLast + out_buffers(num_stages - 1)(1))
  val out2     = RegNext(outLast - out_buffers(num_stages - 1)(1))
  val outValid = busy & (RegNext(cnt) >= (fftLength - 1).U)

  io.out1      := Mux(outValid, out1, 0.U.asTypeOf(new FPComplex(dw, bp)))
  io.out2      := Mux(outValid, out2, 0.U.asTypeOf(new FPComplex(dw, bp)))
  io.out_valid := outValid
}
