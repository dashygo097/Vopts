package datatype.float

import scala.math.pow
import chisel3._
import chisel3.util._


class Float32 extends Bundle with Float32Ops {
  val value = UInt(32.W)
  
  def sign: Bool = value(31).asBool
  def exponent: UInt = value(30, 23)
  def mantissa: UInt = value(22, 0)
  
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
      val mantissaValue = ((normValue - 1.0) * pow(2, 23)).toLong
      
      fl.value := Cat(signBit, expValue.U(8.W), mantissaValue.U(23.W))
    }
    
    fl
  }
}

object Float32 {
  def apply(value: Double): Float32 = {
    (new Float32).fromDouble(value)
  }
}

trait Float32Ops {
  self: Float32 =>

   def ===(that: Float32): Bool = {
    this.value === that.value
  }
  
  def ===(that: Double): Bool = {
    val fl = Wire(new Float32).fromDouble(that)
    this === fl
  }

  def =/=(that: Float32): Bool = {
    this.value =/= that.value
  }

  def =/=(that: Double): Bool = {
    val fl = Wire(new Float32).fromDouble(that)
    this =/= fl
  }
}
