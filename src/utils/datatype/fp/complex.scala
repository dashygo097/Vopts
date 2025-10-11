package utils

import scala.math._
import chisel3._

class FPComplex(dw: Int, bp: Int) extends Bundle {
  val real = SInt(dw.W)
  val imag = SInt(bp.W)

  def dw(): Int = dw
  def bp(): Int = bp

  def +(that: FPComplex): FPComplex = {
    val c = this.newInstance()
    c.real := this.real + that.real
    c.imag := this.imag + that.imag
    c
  }

  def -(that: FPComplex): FPComplex = {
    val c = this.newInstance()
    c.real := this.real - that.real
    c.imag := this.imag - that.imag
    c
  }

  // Gaussian multiplication
  def *(that: FPComplex): FPComplex = {
    val c  = this.newInstance()
    val k1 = that.real * (this.real + this.imag)
    val k2 = this.real * (that.imag - that.real)
    val k3 = this.imag * (that.real + that.imag)
    c.real := (k1 - k3) >> bp
    c.imag := (k1 + k2) >> bp
    c
  }

  def fromDouble(real: Double, imag: Double): FPComplex = {
    val scale = pow(2, bp)
    val c     = this.newInstance()
    c.real := (real * scale).toInt.S
    c.imag := (imag * scale).toInt.S
    c
  }

  def isCompatible(that: FPComplex): Boolean =
    this.dw() == that.dw() && this.bp() == that.bp()

  def requireCompatible(that: FPComplex): Unit =
    require(
      isCompatible(that),
      s"FPComplex operations require matching formats: " +
        s"FPComplex(${this.dw()}, ${this.bp()}) vs FPComplex(${that.dw()}, ${that.bp()})"
    )

  def newInstance(): FPComplex = new FPComplex(dw, bp)
}

object FPComplex {
  def apply(dw: Int, bp: Int): FPComplex                             =
    new FPComplex(dw, bp)
  def apply(c: FPComplex): FPComplex                                 =
    new FPComplex(c.dw(), c.bp())
  def apply(real: Double, imag: Double, dw: Int, bp: Int): FPComplex = {
    val c = new FPComplex(dw, bp)
    c.fromDouble(real, imag)
  }
}
