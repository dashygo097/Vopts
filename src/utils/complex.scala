package utils 

import scala.math._

import chisel3._

class ComplexOpIO extends Bundle with Config {
  val in_1 = Input(new Complex)
  val in_2 = Input(new Complex)
  val out = Output(new Complex)
}

class Complex(s_dataWidth: Int = 0, s_bp: Int = -1) extends Bundle with Config {
  val _dataWidth = if (s_dataWidth == 0) dataWidth else s_dataWidth
  val _bp = if (s_bp == -1) bp else s_bp

  val real = SInt(_dataWidth.W)
  val imag = SInt(_dataWidth.W)

  def +(that: Complex): Complex = {
    val c = Wire(new Complex)
    c.real := this.real + that.real
    c.imag := this.imag + that.imag
    c
  }

  def -(that: Complex): Complex = {
    val c = Wire(new Complex)
    c.real := this.real - that.real
    c.imag := this.imag - that.imag
    c
  }

  // Gaussian multiplication
  def *(that: Complex): Complex = {
    val c = Wire(new Complex)
    val k1 = that.real * (this.real + this.imag)
    val k2 = this.real * (that.imag - that.real)
    val k3 = this.imag * (that.real + that.imag)
    c.real := (k1 - k3) >> _bp
    c.imag := (k1 + k2) >> _bp
    c
  }

  def fromDouble(real: Double, imag: Double): Complex = {
    val scale = pow(2, _bp)
    val c = Wire(new Complex)
    c.real := (real * scale).toInt.S
    c.imag := (imag * scale).toInt.S
    c
  }
}

object Complex extends Config {
  def apply(real: Double, imag: Double): Complex = {
    (new Complex).fromDouble(real, imag)
  }
}

class ComplexAdd(width: Int, bp: Int) extends Module {
  val io = IO(new ComplexOpIO)
  io.out := io.in_1 + io.in_2
}

class ComplexSub(width: Int, bp: Int) extends Module {
  val io = IO(new ComplexOpIO)
  io.out := io.in_1 - io.in_2
}

class ComplexMul(width: Int, bp: Int) extends Module {
  val io = IO(new ComplexOpIO)
  io.out := io.in_1 * io.in_2
}

class ComplexMulTest(real1: Double, imag1: Double, real2: Double, imag2: Double) extends Module with Config {
  val io = IO(new Bundle {
    val out = Output(new Complex)
  })
  val complex1 = Complex(real1, imag1)
  val complex2 = Complex(real2, imag2)
  io.out := complex1 * complex2
}

