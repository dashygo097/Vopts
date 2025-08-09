package utils 

import scala.math._
import chisel3._


class FPComplex(s_dataWidth: Int = 0, s_binaryPoint: Int = -1) extends Bundle with Config {
  val _dataWidth = if (s_dataWidth == 0) dataWidth else s_dataWidth
  val _bp = if (s_binaryPoint == -1) binaryPoint else s_binaryPoint

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

object FPComplex extends Config {
  def apply(real: Double, imag: Double): FPComplex = {
    (new FPComplex).fromDouble(real, imag)
  }
}

