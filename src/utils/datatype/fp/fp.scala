package utils 

import scala.math.pow
import chisel3._

class FP(s_dataWidth: Int = 0, s_binaryPoint: Int = -1) extends Bundle with Config with FPOps {
  var _dw: Int = if (s_dataWidth == 0) dataWidth else s_dataWidth
  var _bp: Int = if (s_binaryPoint == -1) binaryPoint else s_binaryPoint

  val value: SInt = SInt(_dw.W)

  def dw(): Int = _dw
  def bp(): Int = _bp
  def scale(): Int = pow(2, _bp).toInt

  def apply(idx: Int): Bool = {
    require(idx >= 0 && idx < _dw, s"Index {$idx} out of bounds for dataWidth ${_dw}")
    value(idx)
  }

  def update(idx: Int, b: Bool): Unit = {
    require(idx >= 0 && idx < _dw, s"Index {$idx} out of bounds for dataWidth ${_dw}")
    value(idx) := b
  }

  def isCompatible(that: FP): Boolean = {
    this.dataWidth == that.dataWidth && this.binaryPoint == that.binaryPoint
  }

  def requireCompatible(that: FP): Unit = {
      require(isCompatible(that),
        s"FP operations require matching formats: " +
        s"FP(${this.dataWidth}, ${this.binaryPoint}) vs FP(${that.dataWidth}, ${that.binaryPoint})")
    }

  def newInstance(): FP = new FP(_dw, _bp)

  def fromDouble(value: Double): FP = {
    val fl = Wire(new FP(_dw, _bp))
    fl.value := (value * scale()).toInt.S
    fl
  }

  def fromSInt(value: SInt): FP = {
    val fl = Wire(new FP(_dw, _bp))
    fl.value := value
    fl
  }

  def mapDouble(x: Double): FP = {
    this.fromDouble(x)
  }

  def mapSInt(x: SInt): FP = {
    val fl = Wire(new FP(_dw, _bp))
    fl.value := x << _bp
    fl
  }
}

object FP extends Config {
  def apply() : FP = {
    new FP().fromSInt(0.S)
  }
  def apply(value: Double): FP = {
    new FP().fromDouble(value)
  }
  def apply(value: SInt): FP = {
    new FP().fromSInt(value)
  }
}

trait FPOps {
  // NOTE: Note that +-* etc. for FP and FP only support same (dataWidth, bp)-typed Float.
  self: FP =>
 
  def +(that: FP): FP = {
    this.requireCompatible(that)
    val fl = this.newInstance().fromSInt(0.S)
    fl.value := this.value + that.value
    fl
  }
  def +(that: Double): FP = this + FP(that)
  def +(that: SInt): FP = this + FP(that)
  def +(that: UInt): FP = this + FP(that.asSInt)

  def -(that: FP): FP = {
    this.requireCompatible(that)
    val fl = this.newInstance().fromSInt(0.S)
    fl.value := this.value - that.value
    fl
  }
  def -(that: Double): FP = this - FP(that)
  def -(that: SInt): FP = this - FP(that)
  def -(that: UInt): FP = this - FP(that.asSInt)

  def *(that: FP): FP = {
    this.requireCompatible(that)
    val fl = this.newInstance().fromSInt(0.S)
    if (this.dw() >= 16) {
      val highxhigh = Reg(SInt(((dw() - bp()) * 2).W))
      val highxlow = Reg(SInt(dw().W))
      val lowxhigh = Reg(SInt(dw().W))
      val lowxlow = Reg(SInt((bp() * 2).W))
      highxhigh := RegNext((this.value(dw() - 1, bp()) * that.value(dw() - 1, bp())).asSInt)
      lowxlow := RegNext((this.value(bp() - 1, 0) * that.value(bp() - 1, 0)).asSInt)
      highxlow := RegNext(RegNext((this.value(dw() - 1, bp()) * that.value(bp() - 1, 0)).asSInt))
      lowxhigh := RegNext(RegNext((this.value(bp() - 1, 0) * that.value(dw() - 1, bp())).asSInt))

      fl.value := (highxhigh << bp()) + (highxlow + lowxhigh) + (lowxlow >> bp())
    } else {
      fl.value := (this.value * that.value) >> bp()
    }
    fl
  }
  def *(that: Double): FP = this * FP(that)
  def *(that: SInt): FP = this * FP(that)
  def *(that: UInt): FP = this * FP(that.asSInt)

  def /(that: FP): FP = {
    this.requireCompatible(that)
    val fl = this.newInstance().fromSInt(0.S)
    fl.value := (this.value << bp()) / that.value
    fl
  }
  def /(that: Double): FP = this / FP(that)
  def /(that: SInt): FP = this / FP(that)
  def /(that: UInt): FP = this / FP(that.asSInt)

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

  def <(that: FP): Bool = {
    this.requireCompatible(that)
    this.value < that.value
  }
  def <(that: Double): Bool = this < FP(that)
  def <(that: SInt): Bool = this < FP(that)
  def <(that: UInt): Bool = this < FP(that.asSInt)

  def ===(that: FP): Bool = {
    this.requireCompatible(that)
    this.value === that.value
  }
  def ===(that: Double): Bool = this === FP(that)
  def ===(that: SInt): Bool = this === FP(that)
  def ===(that: UInt): Bool = this === FP(that.asSInt)

  def =/=(that: FP): Bool = {
    this.requireCompatible(that)
    !(this === that)
  }
  def =/=(that: Double): Bool = !(this === FP(that))
  def =/=(that: SInt): Bool = !(this === FP(that))
  def =/=(that: UInt): Bool = !(this === FP(that.asSInt))

  def <=(that: FP): Bool = this === that || this < that
  def <=(that: Double): Bool = this < FP(that) || this === FP(that)
  def <=(that: SInt): Bool = this < FP(that) || this === FP(that)
  def <=(that: UInt): Bool = this < FP(that.asSInt) || this === FP(that.asSInt)

  def >(that: FP): Bool = !(this <= that)
  def >(that: Double): Bool = !(this <= FP(that))
  def >(that: SInt): Bool = !(this <= FP(that))
  def >(that: UInt): Bool = !(this <= FP(that.asSInt))

  def >=(that: FP): Bool = !(this < that)
  def >=(that: Double): Bool = !(this < FP(that))
  def >=(that: SInt): Bool = !(this < FP(that))
  def >=(that: UInt): Bool = !(this < FP(that.asSInt))
}
