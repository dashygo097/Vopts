package dsp.fft

import scala.math._
import utils._
import chisel3._
import chisel3.util._

class R2MDCFFTIO extends Bundle with Config {
  val in = Input(new FPComplex)
  val in_valid = Input(Bool())
  val out1 = Output(new FPComplex)
  val out2 = Output(new FPComplex)
  val out_valid = Output(Bool())
  val busy = Output(Bool())
}

class R2MDCFFTCore(fftSize: Int) extends Module with Config {
  override def desiredName = s"fft_radix2_mdc_n${fftSize}"
  val io = IO(new R2MDCFFTIO).suggestName("FFT")

  val num_stages = log2Ceil(fftSize)
  val cnt = RegInit(0.U((1 + num_stages).W))
  val busy = cnt =/= 0.U

  when (io.in_valid || busy) {
    cnt := Mux(cnt === (fftSize * 3 / 2 - 1).U, 0.U, cnt + 1.U)
  }
  io.busy := busy

  val twiddle_rom = (0 until num_stages).map { stage =>
    val rom = (0 until fftSize / 2 by pow(2, stage).toInt).map { i =>
      val angle = 2 * Pi * i / fftSize
      val real = cos(angle)
      val imag = sin(angle)
      FPComplex(real, imag)
    }
    rom
  }

  def twiddle(stage: Int, i: UInt): FPComplex = {
    val tw = VecInit(twiddle_rom(stage).map(x => x))
    tw(i)
  }


  val out_buffers = VecInit(Seq.fill(num_stages)
    (VecInit(Seq.fill(2)
      (FPComplex(0.0, 0.0))
      )
    )
  )

  out_buffers(0)(0) := io.in
  out_buffers(0)(1) := io.in

  for (stage <- 1 until num_stages) {
    val delay = fftSize / pow(2, stage).toInt
    val wn = twiddle(stage - 1, cnt(num_stages - stage - 1, 0)) 
    val (bf_1, bf_2) = Butterfly(ShiftRegister(out_buffers(stage - 1)(0), delay), out_buffers(stage - 1)(1), wn)
    val (cm1, cm2) = Commutator(bf_1, ShiftRegister(bf_2, delay / 2), cnt(num_stages - stage - 1))
    out_buffers(stage)(0) := cm1
    out_buffers(stage)(1) := cm2
  }

  val outLast = RegNext(out_buffers(num_stages - 1)(0))
  val out1 = RegNext(outLast + out_buffers(num_stages - 1)(1))
  val out2 = RegNext(outLast - out_buffers(num_stages - 1)(1))
  val outValid = busy & (RegNext(cnt) >= (fftSize - 1).U)

  io.out1 := Mux(outValid, out1, 0.U.asTypeOf(new FPComplex))
  io.out2 := Mux(outValid, out2, 0.U.asTypeOf(new FPComplex))
  io.out_valid := outValid 
}

object R2MDCFFT extends Config {
  var _fftSize: Int = defaultFFTSize

  def apply(in: FPComplex): (FPComplex, FPComplex) = {
    val mdc = Module(new R2MDCFFTCore(_fftSize))
    mdc.io.in := in
    mdc.io.in_valid := true.B
    (mdc.io.out1, mdc.io.out2)
  }

  def withFFTSize(fftSize: Int): Unit = {
    _fftSize = fftSize
  }

  def withConfig(fftSize: Int): Unit = {
    this.withFFTSize(fftSize)
  }
}


