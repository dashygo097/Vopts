package utils 

import scala.math.pow

import chisel3._

class FP(s_dataWidth: Int = 0, s_bp: Int = -1) extends Bundle with Config with FPOps {
  var _dataWidth: Int = if (s_dataWidth == 0) dataWidth else s_dataWidth
  var _bp: Int = if (s_bp == -1) bp else s_bp

  val value: SInt = SInt(_dataWidth.W)

  def get_dw(): Int = {
    _dataWidth
  }

  def get_bp(): Int = {
    _bp
  }

  def fromDouble(value: Double): FP = {
    val scale = pow(2, _bp).toInt
    val fl = Wire(new FP(_dataWidth, _bp))
    fl.value := (value * scale).toInt.S
    fl
  }

  def fromSInt(value: SInt): FP = {
    val fl = Wire(new FP(_dataWidth, _bp))
    fl.value := value
    fl
  }

  def mapDouble(x: Double): FP = {
    this.fromDouble(x)
  }

  def mapSInt(x: SInt): FP = {
    val scale = pow(2, _bp).toInt
    val fl = Wire(new FP(_dataWidth, _bp))
    fl.value := x * scale.S
    fl
  }

  def _match(that: FP): Unit = {
    require(this.get_dw() == that.get_dw() && this.get_bp() == that.get_bp(),
      s"FP match requires same dataWidth and bp: (${this.get_dw()}, ${this.get_bp()}) vs (${that.get_dw()}, ${that.get_bp()})")
  }
}

object FP extends Config {
  def apply(value: Double): FP = {
    (new FP).fromDouble(value)
  }
  def apply(value: SInt): FP = {
    new FP().fromSInt(value)
  }
}

trait FPOps {
  // NOTE: Note that +-* etc. for FP and FP only support same (dataWidth, bp)-typed Float.
  self: FP =>
 
  def +(that: FP): FP = {
    this._match(that)
    val fl = Wire(new FP(this.get_dw(), this.get_bp()))
    fl.value := this.value + that.value
    fl
  }
  def +(that: Double): FP = this + FP(that)
  def +(that: SInt): FP = this + FP(that)
  def +(that: UInt): FP = this + FP(that.asSInt)

  def -(that: FP): FP = {
    this._match(that)
    val fl = Wire(new FP(this.get_dw(), this.get_bp()))
    fl.value := this.value - that.value
    fl
  }
  def -(that: Double): FP = this - FP(that)
  def -(that: SInt): FP = this - FP(that)
  def -(that: UInt): FP = this - FP(that.asSInt)

  def *(that: FP): FP = {
    this._match(that)
    val fl = Wire(new FP(this.get_dw(), this.get_bp()))
    fl.value := (this.value * that.value) >> _bp
    fl
  }
  def *(that: Double): FP = this * FP(that)
  def *(that: SInt): FP = this * FP(that)
  def *(that: UInt): FP = this * FP(that.asSInt)

  def /(that: FP): FP = {
    this._match(that)
    val fl = Wire(new FP(this.get_dw(), this.get_bp()))
    fl.value := (this.value << _bp) / that.value
    fl
  }
  def /(that: Double): FP = this / FP(that)
  def /(that: SInt): FP = this / FP(that)
  def /(that: UInt): FP = this / FP(that.asSInt)

  def shiftleft(that: UInt): FP = {
    val fl = Wire(new FP(this.get_dw(), this.get_bp()))
    fl.value := this.value << that
    fl
  }

  def shiftright(that: UInt): FP = {
    val fl = Wire(new FP)
    fl.value := this.value >> that
    fl
  }

  def <(that: FP): Bool = {
    this._match(that)
    this.value < that.value
  }
  def <(that: Double): Bool = this < FP(that)
  def <(that: SInt): Bool = this < FP(that)
  def <(that: UInt): Bool = this < FP(that.asSInt)

  def ===(that: FP): Bool = {
    this._match(that)
    this.value === that.value
  }
  def ===(that: Double): Bool = this === FP(that)
  def ===(that: SInt): Bool = this === FP(that)
  def ===(that: UInt): Bool = this === FP(that.asSInt)

  def =/=(that: FP): Bool = {
    this._match(that)
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
