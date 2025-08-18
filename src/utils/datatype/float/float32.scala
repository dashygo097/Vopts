package utils

import scala.math.pow

import chisel3._
import chisel3.util._


class Float32 extends Bundle with Float32Ops {
  val value = UInt(32.W)
  
  def sign(): Bool = value(31).asBool
  def exponent(): UInt = value(30, 23)
  def fraction(): UInt = value(22, 0)
  def mantissa(): UInt = fraction()
  def significant(): UInt = mantissa()
  
  private val bias = 127
  
  def fromDouble(value: Double): Float32 = {
    val fl = Wire(new Float32)
    
    val signBit = (value < 0).B
    
    if (value == 0.0) {
      fl.value := 0.U
    } else {
      val absValue = math.abs(value)
      
      val expValue = math.floor(math.log(absValue) / math.log(2)).toInt + bias
      
      val normValue = absValue / pow(2, expValue - bias)
      val fractionValue = ((normValue - 1.0) * pow(2, 23)).toLong
      
      fl.value := Cat(signBit, expValue.U(8.W), fractionValue.U(23.W))
    }
    
    fl
  }

  def fromUInt(value: UInt): Float32 = {
    val fl = Wire(new Float32)
    fl.value := value
    fl
  }

  def fromSInt(value: SInt) : Float32 = {
    val fl = Wire(new Float32)
    fl.value := value.asUInt
    fl
  }

  def Zero(): Float32 = {
    val fl = Wire(new Float32)
    fl.value := 0.U
    fl
  }

  def NaN(): Float32 = {
    val fl = Wire(new Float32)
    fl.value(30, 23) := 255.U
    fl.value(23, 0) := 1.U 
    fl
  }

  def Inf(): Float32 = {
    val fl = Wire(new Float32)
    fl.value(30, 23) := 255.U
    fl.value(22, 0) := 0.U 
    fl
  }
}

object Float32 {
  def apply(value: Double): Float32 = {
    (new Float32).fromDouble(value)
  }
  def apply(value: UInt): Float32 = {
    (new Float32).fromUInt(value)
  }
  def apply(value: SInt): Float32 = {
    (new Float32).fromSInt(value)
  }
}

trait Float32Ops {
  self: Float32 => 

  def unpack(): (Bool, UInt, UInt) = (sign(), exponent(), fraction())

  def isNaN(): Bool = (exponent() === "hFF".U) && (fraction() =/= 0.U)
  def isInf(): Bool = (exponent() === "hFF".U) && (fraction() === 0.U)
  def isZero(): Bool = (exponent() === 0.U) && (fraction() === 0.U)


  //
  //   val thisSign = this.sign()
  //   val thatSign = that.sign()
  //   val thisExp = this.exponent()
  //   val thatExp = that.exponent()
  //   val thisFrac = Cat(1.U, this.fraction())
  //   val thatFrac = Cat(1.U, that.fraction())
  //
  //   when(this.isNaN() || that.isNaN()) {
  //     result := (new Float32).NaN()
  //   } .elsewhen(this.isInf() && that.isInf() && (thisSign =/= thatSign)) {
  //     result := (new Float32).NaN()
  //   } .elsewhen(this.isInf()) {
  //     result := this
  //   }.elsewhen(that.isInf()) {
  //     result := that
  //   } .otherwise {
  //     // stage1
  //     val expDiff = (thisExp - thatExp).asSInt
  //     val swap = expDiff < 0.S
  //     val alignedExp = Mux(swap, thatExp, thisExp)
  //     val expDiffAbs = Mux(swap, -expDiff, expDiff).asUInt
  //
  //     val largerFrac = Mux(swap, thatFrac, thisFrac)
  //     val smallerFrac = Mux(swap, thisFrac, thatFrac)
  //     val largerSign = Mux(swap, thatSign, thisSign)
  //     val smallerSign = Mux(swap, thisSign, thatSign)
  //
  //     val shiftedSmallerFrac = (smallerFrac >> expDiffAbs).asUInt
  //     val guardBit = (smallerFrac >> (expDiffAbs - 1.U))(0)
  //     val roundBit = (smallerFrac >> (expDiffAbs - 2.U))(0)
  //
  //     // stage2
  //     
  //     // stage3
  //
  //   }
  //
  //
  //   result
  // } 

  def ===(that: Float32): Bool = this.value === that.value
  def ===(that: Double): Bool = this === Float32(that)
  def ===(that: UInt): Bool = this === Float32(that)
  def ===(that: SInt): Bool = this === Float32(that.asUInt)

  def =/=(that: Float32): Bool = !(this === that)
  def =/=(that: Double): Bool = !(this === Float32(that))
  def =/=(that: UInt): Bool = !(this === Float32(that))
  def =/=(that: SInt): Bool = !(this === Float32(that.asUInt))
  
}
