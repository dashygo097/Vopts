package utils

import hardfloat._
import scala.math._
import chisel3._
import chisel3.util._

class Float(expWidth: Int, sigWidth: Int) extends Bundle with FloatOps {
  val value: UInt = UInt((expWidth + sigWidth + 1).W)
  
  def totalWidth(): Int = expWidth + sigWidth + 1
  def expWidth(): Int = expWidth
  def sigWidth(): Int = sigWidth
  def bias(): Int = (1 << (expWidth - 1)) - 1
  
  def sign(): Bool = value(totalWidth() - 1).asBool
  def exponent(): UInt = value(totalWidth() - 2, sigWidth)
  def fraction(): UInt = value(sigWidth - 1, 0)
  def mantissa(): UInt = fraction()
  def significant(): UInt = mantissa()

  def apply(idx: Int): Bool = {
    require(idx >= 0 && idx < totalWidth(), s"Index {$idx} out of bounds for dataWidth ${totalWidth()}")
    value(idx)
  }

  def apply(high: Int, low: Int): UInt = {
    require(high >= low && high < totalWidth() && low >= 0,
      s"Index range {$high, $low} out of bounds for dataWidth ${totalWidth()}")
    value(high, low)
  }

  def update(idx: Int, b: Bool): Unit = {
    require(idx >= 0 && idx < totalWidth(), s"Index {$idx} out of bounds for dataWidth ${totalWidth()}")
    value(idx) := b
  }
  
  def newInstance(): Float = new Float(expWidth, sigWidth)
  
  def fromDouble(value: Double): Float = {
    val fl = Wire(this.newInstance())
    val signBit = (value < 0).B
    if (value == 0.0) {
      fl.value := 0.U
    } else {
      val absValue = math.abs(value)
      val expValue = math.floor(math.log(absValue) / math.log(2)).toInt + bias()
      val normValue = absValue / pow(2, expValue - bias())
      val fractionValue = ((normValue - 1.0) * pow(2, sigWidth)).toLong
      fl.value := Cat(signBit, expValue.U(expWidth.W), fractionValue.U(sigWidth.W))
    }
    fl
  }
  
  def fromInt(value: Int): Float = {
    fromDouble(value.toDouble)
  }
  
  def Zero(): Float = {
    val fl = Wire(this.newInstance())
    fl.value := 0.U
    fl
  }
  
  def NaN(): Float = {
    val fl = Wire(this.newInstance())
    fl.value := Cat(0.U(1.W), ((1 << expWidth) - 1).U(expWidth.W), 1.U(sigWidth.W))
    fl
  }
  
  def Inf(): Float = {
    val fl = Wire(this.newInstance())
    fl.value := Cat(0.U(1.W), ((1 << expWidth) - 1).U(expWidth.W), 0.U(sigWidth.W))
    fl
  }
}

object Float {
  def apply(expWidth: Int, sigWidth: Int): Float = new Float(expWidth, sigWidth)
  def apply(expWidth: Int, sigWidth: Int, value: Int): Float = {
    val fl = new Float(expWidth, sigWidth)
    fl.fromInt(value)
  }
  def apply(expWidth: Int, sigWidth: Int, value: Double): Float = {
    val fl = new Float(expWidth, sigWidth)
    fl.fromDouble(value)
  }
}

trait FloatOps {
  self: Float =>
  
  def unpack(): (Bool, UInt, UInt) = (sign(), exponent(), fraction())
  
  def isNaN(): Bool = {
    val maxExp = ((1 << expWidth()) - 1).U
    (exponent() === maxExp) && (fraction() =/= 0.U)
  }
  
  def isInf(): Bool = {
    val maxExp = ((1 << expWidth()) - 1).U
    (exponent() === maxExp) && (fraction() === 0.U)
  }
  
  def isZero(): Bool = (exponent() === 0.U) && (fraction() === 0.U)
  
  def +(that: Float): Float = {
    require(this.expWidth() == that.expWidth() && this.sigWidth() == that.sigWidth(),
      s"Float operations require matching formats: " +
      s"Float(${this.expWidth()}, ${this.sigWidth()}) vs Float(${that.expWidth()}, ${that.sigWidth()})")
    val result = Wire(this.newInstance())
    val adder = Module(new AddRecFN(expWidth(), sigWidth()))
    adder.io.subOp := false.B
    adder.io.a := this.value
    adder.io.b := that.value
    adder.io.roundingMode := 0.U
    adder.io.detectTininess := false.B
    result.value := adder.io.out
    result
  }
  def +(that: Int): Float = this + that.toDouble
  def +(that: Double): Float = this + that
  
  def -(that: Float): Float = {
    require(this.expWidth() == that.expWidth() && this.sigWidth() == that.sigWidth(),
      s"Float operations require matching formats")
    val result = Wire(this.newInstance())
    val adder = Module(new AddRecFN(expWidth(), sigWidth()))
    adder.io.subOp := true.B
    adder.io.a := this.value
    adder.io.b := that.value
    adder.io.roundingMode := 0.U
    adder.io.detectTininess := false.B
    result.value := adder.io.out
    result
  }
  def -(that: Int): Float = this - that.toDouble
  def -(that: Double): Float = this - that
  
  def *(that: Float): Float = {
    require(this.expWidth() == that.expWidth() && this.sigWidth() == that.sigWidth(),
      s"Float operations require matching formats")
    val result = Wire(this.newInstance())
    val multiplier = Module(new MulRecFN(expWidth(), sigWidth()))
    multiplier.io.a := this.value
    multiplier.io.b := that.value
    multiplier.io.roundingMode := 0.U
    multiplier.io.detectTininess := false.B
    result.value := multiplier.io.out
    result
  }
  def *(that: Int): Float = this * that.toDouble
  def *(that: Double): Float = this * that
  
  def /(that: Float): Float = {
    require(this.expWidth() == that.expWidth() && this.sigWidth() == that.sigWidth(),
      s"Float operations require matching formats")
    val result = Wire(this.newInstance())
    val divider = Module(new DivSqrtRecFN_small(expWidth(), sigWidth(), 0))
    divider.io.inValid := true.B
    divider.io.sqrtOp := false.B
    divider.io.a := this.value
    divider.io.b := that.value
    divider.io.roundingMode := 0.U
    divider.io.detectTininess := false.B
    result.value := divider.io.out
    result
  }
  def /(that: Int): Float = this / that.toDouble
  def /(that: Double): Float = this / that
  
  def <(that: Float): Bool = {
    require(this.expWidth() == that.expWidth() && this.sigWidth() == that.sigWidth(),
      s"Float operations require matching formats")
    val comparator = Module(new CompareRecFN(expWidth(), sigWidth()))
    comparator.io.a := this.value
    comparator.io.b := that.value
    comparator.io.signaling := false.B
    comparator.io.lt
  }
  def <(that: Int): Bool = this < that.toDouble
  def <(that: Double): Bool = this < that
  
  def ===(that: Float): Bool = {
    require(this.expWidth() == that.expWidth() && this.sigWidth() == that.sigWidth(),
      s"Float operations require matching formats")
    val comparator = Module(new CompareRecFN(expWidth(), sigWidth()))
    comparator.io.a := this.value
    comparator.io.b := that.value
    comparator.io.signaling := false.B
    comparator.io.eq
  }
  def ===(that: Int): Bool = this === that.toDouble
  def ===(that: Double): Bool = this === that
  
  def =/=(that: Float): Bool = !(this === that)
  def =/=(that: Int): Bool = this =/= that.toDouble
  def =/=(that: Double): Bool = this =/= that
  
  def <=(that: Float): Bool = {
    require(this.expWidth() == that.expWidth() && this.sigWidth() == that.sigWidth(),
      s"Float operations require matching formats")
    val comparator = Module(new CompareRecFN(expWidth(), sigWidth()))
    comparator.io.a := this.value
    comparator.io.b := that.value
    comparator.io.signaling := false.B
    comparator.io.lt || comparator.io.eq
  }
  def <=(that: Int): Bool = this <= that.toDouble
  def <=(that: Double): Bool = this <= that
  
  def >(that: Float): Bool = !(this <= that)
  def >(that: Int): Bool = this > that.toDouble
  def >(that: Double): Bool = this > that

  def >=(that: Float): Bool = !(this < that)
  def >=(that: Int): Bool = this >= that.toDouble
  def >=(that: Double): Bool = this >= that
}
