package utils 

import scala.math._

import chisel3._


class FPComplex(s_dataWidth: Int = 0, s_bp: Int = -1) extends Bundle with Config {
  val _dataWidth = if (s_dataWidth == 0) dataWidth else s_dataWidth
  val _bp = if (s_bp == -1) bp else s_bp

  val real = SInt(_dataWidth.W)
  val imag = SInt(_dataWidth.W)

  def +(that: FPComplex): FPComplex = {
    val c = Wire(new FPComplex)
    c.real := this.real + that.real
    c.imag := this.imag + that.imag
    c
  }

  def -(that: FPComplex): FPComplex = {
    val c = Wire(new FPComplex)
    c.real := this.real - that.real
    c.imag := this.imag - that.imag
    c
  }

  // Gaussian multiplication
  def *(that: FPComplex): FPComplex = {
    val c = Wire(new FPComplex)
    val k1 = that.real * (this.real + this.imag)
    val k2 = this.real * (that.imag - that.real)
    val k3 = this.imag * (that.real + that.imag)
    c.real := (k1 - k3) >> _bp
    c.imag := (k1 + k2) >> _bp
    c
  }

  def fromDouble(real: Double, imag: Double): FPComplex = {
    val scale = pow(2, _bp)
    val c = Wire(new FPComplex)
    c.real := (real * scale).toInt.S
    c.imag := (imag * scale).toInt.S
    c
  }
}

class FPComplexOpIO extends Bundle with Config {
  val in_1 = Input(new FPComplex)
  val in_2 = Input(new FPComplex)
  val out = Output(new FPComplex)
}

object FPComplex extends Config {
  def apply(real: Double, imag: Double): FPComplex = {
    (new FPComplex).fromDouble(real, imag)
  }
}

class FPComplexAdd(width: Int, bp: Int) extends Module {
  val io = IO(new FPComplexOpIO)
  io.out := io.in_1 + io.in_2
}

class FPComplexSub(width: Int, bp: Int) extends Module {
  val io = IO(new FPComplexOpIO)
  io.out := io.in_1 - io.in_2
}

class FPComplexMul(width: Int, bp: Int) extends Module {
  val io = IO(new FPComplexOpIO)
  io.out := io.in_1 * io.in_2
}

class FPComplexMulTest(real1: Double, imag1: Double, real2: Double, imag2: Double) extends Module with Config {
  val io = IO(new Bundle {
    val out = Output(new FPComplex)
  })
  val complex1 = FPComplex(real1, imag1)
  val complex2 = FPComplex(real2, imag2)
  io.out := complex1 * complex2
}

