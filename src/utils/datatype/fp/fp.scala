package utils

import scala.math.pow
import chisel3._

class FP(dw: Int, bp: Int) extends Bundle with FPOps {
  val value: SInt = SInt(dw.W)

  def dw(): Int    = dw
  def bp(): Int    = bp
  def scale(): Int = pow(2, bp).toInt

  def apply(idx: Int): Bool = {
    require(idx >= 0 && idx < dw, s"Index {$idx} out of bounds for dataWidth $dw")
    value(idx)
  }

  def apply(high: Int, low: Int): UInt = {
    require(high >= low && high < dw, s"Index {$high, $low} out of bounds for dataWidth $dw")
    value(high, low)
  }

  def update(idx: Int, b: Bool): Unit = {
    require(idx >= 0 && idx < dw, s"Index {$idx} out of bounds for dataWidth $dw")
    value(idx) := b
  }

  def isCompatible(that: FP): Boolean =
    this.dw() == that.dw() && this.bp() == that.bp()

  def requireCompatible(that: FP): Unit =
    require(
      isCompatible(that),
      s"FP operations require matching formats: " +
        s"FP(${this.dw()}, ${this.bp()}) vs FP(${that.dw()}, ${that.bp()})"
    )

  def newInstance(): FP = new FP(dw, bp)

  def fromDouble(value: Double): FP = {
    val fp = this.newInstance()
    fp.value := (value * scale()).toInt.S
    fp
  }

  def fromSInt(value: SInt): FP = {
    val fl = Wire(new FP(dw, bp))
    fl.value := value
    fl
  }

  def mapDouble(x: Double): FP =
    this.fromDouble(x)

  def mapSInt(x: SInt): FP = {
    val fl = Wire(new FP(dw, bp))
    fl.value := x << bp
    fl
  }
}

object FP {
  def apply(dw: Int, bp: Int): FP                = new FP(dw, bp)
  def apply(dw: Int, bp: Int, value: Int): FP    =
    FP(dw, bp).fromDouble(value.toDouble)
  def apply(dw: Int, bp: Int, value: Double): FP =
    FP(dw, bp).fromDouble(value)
  def apply(dw: Int, bp: Int, value: SInt): FP   =
    FP(dw, bp).mapSInt(value)
}

trait FPOps {
  // NOTE: Note that +-* etc. for FP and FP only support same (dataWidth, bp)-typed Float.
  self: FP =>
  def +(that: FP): FP     = {
    this.requireCompatible(that)
    val fl = this.newInstance().fromSInt(0.S)
    fl.value := this.value + that.value
    fl
  }
  def +(that: Double): FP = this + FP(dw(), bp(), that)
  def +(that: SInt): FP   = this + FP(dw(), bp(), that)
  def +(that: UInt): FP   = this + FP(dw(), bp(), that.asSInt)

  def -(that: FP): FP     = {
    this.requireCompatible(that)
    val fl = this.newInstance().fromSInt(0.S)
    fl.value := this.value - that.value
    fl
  }
  def -(that: Double): FP = this - FP(dw(), bp(), that)
  def -(that: SInt): FP   = this - FP(dw(), bp(), that)
  def -(that: UInt): FP   = this - FP(dw(), bp(), that.asSInt)

  def *(that: FP): FP     = {
    this.requireCompatible(that)
    val fl = this.newInstance().fromSInt(0.S)
    fl.value := (this.value * that.value) >> bp()
    fl
  }
  def *(that: Double): FP = this * FP(dw(), bp(), that)
  def *(that: SInt): FP   = this * FP(dw(), bp(), that)
  def *(that: UInt): FP   = this * FP(dw(), bp(), that.asSInt)

  def /(that: FP): FP     = {
    this.requireCompatible(that)
    val fl = this.newInstance().fromSInt(0.S)
    fl.value := (this.value << bp()) / that.value
    fl
  }
  def /(that: Double): FP = this / FP(dw(), bp(), that)
  def /(that: SInt): FP   = this / FP(dw(), bp(), that)
  def /(that: UInt): FP   = this / FP(dw(), bp(), that.asSInt)

  def shiftleft(that: UInt): FP = {
    val fl = this.newInstance().fromSInt(0.S)
    fl.value := this.value << that
    fl
  }

  def shiftright(that: UInt): FP = {
    val fl = this.newInstance().fromSInt(0.S)
    fl.value := this.value >> that
    fl
  }

  def <(that: FP): Bool     = {
    this.requireCompatible(that)
    this.value < that.value
  }
  def <(that: Double): Bool = this < FP(dw(), bp(), that)
  def <(that: SInt): Bool   = this < FP(dw(), bp(), that)
  def <(that: UInt): Bool   = this < FP(dw(), bp(), that.asSInt)

  def ===(that: FP): Bool     = {
    this.requireCompatible(that)
    this.value === that.value
  }
  def ===(that: Double): Bool = this === FP(dw(), bp(), that)
  def ===(that: SInt): Bool   = this === FP(dw(), bp(), that)
  def ===(that: UInt): Bool   = this === FP(dw(), bp(), that.asSInt)

  def =/=(that: FP): Bool     = {
    this.requireCompatible(that)
    !(this === that)
  }
  def =/=(that: Double): Bool = this =/= FP(dw(), bp(), that)
  def =/=(that: SInt): Bool   = this =/= FP(dw(), bp(), that)
  def =/=(that: UInt): Bool   = this =/= FP(dw(), bp(), that.asSInt)

  def <=(that: FP): Bool     = this === that || this < that
  def <=(that: Double): Bool = this <= FP(dw(), bp(), that)
  def <=(that: SInt): Bool   = this <= FP(dw(), bp(), that)
  def <=(that: UInt): Bool   = this <= FP(dw(), bp(), that.asSInt)

  def >(that: FP): Bool     = !(this <= that)
  def >(that: Double): Bool = !(this <= FP(dw(), bp(), that))
  def >(that: SInt): Bool   = !(this <= FP(dw(), bp(), that))
  def >(that: UInt): Bool   = !(this <= FP(dw(), bp(), that.asSInt))

  def >=(that: FP): Bool     = !(this < that)
  def >=(that: Double): Bool = !(this < FP(dw(), bp(), that))
  def >=(that: SInt): Bool   = !(this < FP(dw(), bp(), that))
  def >=(that: UInt): Bool   = !(this < FP(dw(), bp(), that.asSInt))
}
