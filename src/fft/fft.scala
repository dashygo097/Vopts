package fft
import utils.{Complex, Config}

import scala.math._

import chisel3._
import chisel3.util._

class MDCIO extends Bundle with Config {
  val in = Input(new Complex)
  val in_valid = Input(Bool())
  val out1 = Output(new Complex)
  val out2 = Output(new Complex)
  val out_valid = Output(Bool())
}

class CommutatorIO extends Bundle {
  val in1 = Input(new Complex)
  val in2 = Input(new Complex)
  val sel = Input(Bool())
  val out1 = Output(new Complex)
  val out2 = Output(new Complex)
}

class Commutator extends Module {
  val io = IO(new CommutatorIO)
  io.out1 := Mux(io.sel, io.in2, io.in1)
  io.out2 := Mux(io.sel, io.in1, io.in2)
}

object Commutator {
  def apply(in1: Complex, in2: Complex, sel: Bool): (Complex, Complex) = {
    val commutator = Module(new Commutator)
    commutator.io.in1 := in1
    commutator.io.in2 := in2
    commutator.io.sel := sel
    (commutator.io.out1 , commutator.io.out2)
  }
}

class MDCCore(fftSize: Int) extends Module with Config {

  val io = IO(new MDCIO)

  val num_stages = log2Ceil(fftSize)
  val cnt = RegInit(0.U((1 + num_stages).W))
  val busy = cnt =/= 0.U

  val twiddle_rom = (0 until num_stages).map { stage =>
    val rom = (0 until fftSize / 2 by pow(2, stage).toInt).map { i =>
      val angle = 2 * Pi * i / fftSize
      val real = cos(angle)
      val imag = sin(angle)
      Complex(real, imag)
    }
    rom
  }

  def twiddle(stage: Int, i: UInt): Complex = {
    val tw = VecInit(twiddle_rom(stage).map(x => x))
    tw(i)
  }

  val out_buffers = VecInit(Seq.fill(num_stages)
    (VecInit(Seq.fill(2)
      (Complex(0.0, 0.0))
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
