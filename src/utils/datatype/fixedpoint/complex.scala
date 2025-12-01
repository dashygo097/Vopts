package utils

import scala.math._
import chisel3._

class FPComplex(dw: Int, bp: Int) extends Bundle with FPComplexOps {
  val real: SInt = SInt(dw.W)
  val imag: SInt = SInt(dw.W)

  def dw(): Int    = dw
  def bp(): Int    = bp
  def scale(): Int = pow(2, bp).toInt

  def isCompatible(that: FPComplex): Boolean =
    this.dw() == that.dw() && this.bp() == that.bp()

  def requireCompatible(that: FPComplex): Unit =
    require(
      isCompatible(that),
      s"FPComplex operations require matching formats: " +
        s"FPComplex(${this.dw()}, ${this.bp()}) vs FPComplex(${that.dw()}, ${that.bp()})"
    )

  def newInstance(): FPComplex = new FPComplex(dw, bp)

  def fromDouble(realVal: Double, imagVal: Double): FPComplex = {
    val fpc = Wire(this.newInstance())
    fpc.real := (realVal * scale()).toInt.S
    fpc.imag := (imagVal * scale()).toInt.S
    fpc
  }
}

object FPComplex {
  def apply(dw: Int, bp: Int): FPComplex = new FPComplex(dw, bp)

  def apply(dw: Int, bp: Int, real: Double, imag: Double): FPComplex =
    FPComplex(dw, bp).fromDouble(real, imag)
}

trait FPComplexOps {
  self: FPComplex =>

  def +(that: FPComplex): FPComplex = {
    this.requireCompatible(that)
    val fpc = Wire(this.newInstance())
    fpc.real := this.real + that.real
    fpc.imag := this.imag + that.imag
    fpc
  }

  def +(real: Double, imag: Double): FPComplex =
    this + FPComplex(dw(), bp(), real, imag)

  def -(that: FPComplex): FPComplex = {
    this.requireCompatible(that)
    val fpc = Wire(this.newInstance())
    fpc.real := this.real - that.real
    fpc.imag := this.imag - that.imag
    fpc
  }

  def -(real: Double, imag: Double): FPComplex =
    this - FPComplex(dw(), bp(), real, imag)

  // Gaussian multiplication: (a+bi)(c+di) using 3 multiplications
  // k1 = c(a+b), k2 = a(d-c), k3 = b(c+d)
  // real = k1 - k3, imag = k1 + k2
  def *(that: FPComplex): FPComplex = {
    this.requireCompatible(that)
    val fpc = Wire(this.newInstance())
    val k1  = that.real * (this.real + this.imag)
    val k2  = this.real * (that.imag - that.real)
    val k3  = this.imag * (that.real + that.imag)
    fpc.real := (k1 - k3) >> bp()
    fpc.imag := (k1 + k2) >> bp()
    fpc
  }

  def *(real: Double, imag: Double): FPComplex =
    this * FPComplex(dw(), bp(), real, imag)

  def ===(that: FPComplex): Bool = {
    this.requireCompatible(that)
    (this.real === that.real) && (this.imag === that.imag)
  }

  def ===(real: Double, imag: Double): Bool =
    this === FPComplex(dw(), bp(), real, imag)

  def =/=(that: FPComplex): Bool = {
    this.requireCompatible(that)
    !(this === that)
  }

  def =/=(real: Double, imag: Double): Bool =
    this =/= FPComplex(dw(), bp(), real, imag)

  def conjugate(): FPComplex = {
    val fpc = Wire(this.newInstance())
    fpc.real := this.real
    fpc.imag := -this.imag
    fpc
  }

  def shiftleft(that: UInt): FPComplex = {
    val fpc = Wire(this.newInstance())
    fpc.real := this.real << that
    fpc.imag := this.imag << that
    fpc
  }

  def shiftright(that: UInt): FPComplex = {
    val fpc = Wire(this.newInstance())
    fpc.real := this.real >> that
    fpc.imag := this.imag >> that
    fpc
  }
}
