package func.common

import utils._
import chisel3._

class LimiterCore[T <: Data](gen: T, threshold: AnyVal)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]) extends Module {
  val io = IO(new SISO(gen))
  val thresholdValue = threshold match {
    case int: Int => gen.fromInt(int)
    case double: Double => gen.fromDouble(double)
    case _ => throw new IllegalArgumentException("Unsupported threshold type")
  }

  val zero = gen.zero()
  io.out := Mux(io.in > thresholdValue, thresholdValue, Mux(io.in < zero - thresholdValue, zero - thresholdValue, io.in))
} 
