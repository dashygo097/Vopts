package dsp.fft

import scala.math._
import utils._
import chisel3._
import chisel3.util._

class MDCIO extends Bundle with Config {
  val in = Input(new FPComplex)
  val in_valid = Input(Bool())
  val out1 = Output(new FPComplex)
  val out2 = Output(new FPComplex)
  val out_valid = Output(Bool())
}

class MDCCore(fftSize: Int) extends Module with Config {

  val io = IO(new MDCIO).suggestName("MDC")

  val num_stages = log2Ceil(fftSize)
  val cnt = RegInit(0.U((1 + num_stages).W))
  val busy = cnt =/= 0.U

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

  val out1 = RegNext(out_buffers(num_stages - 1)(0))

  when (io.in_valid || busy) {
    cnt := Mux(cnt === (fftSize * 3 / 2 - 1).U, 0.U, cnt + 1.U)
  }

  io.out1 := RegNext(out1 + out_buffers(num_stages - 1)(1))
  io.out2 := RegNext(out1 - out_buffers(num_stages - 1)(1))
  io.out_valid := RegNext(cnt === (fftSize - 1).U)
}

object MDC extends Config {
  var _fftSize: Int = defaultFFTSize

  def apply(in: FPComplex): (FPComplex, FPComplex) = {
    val mdc = Module(new MDCCore(_fftSize))
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


