package math

import utils._
import chisel3._

class ComparatorIO[T <: Data](gen: T) extends Bundle {
  val in = Input(gen)
  val out = Output(Bool())
}

class Comparator[T <: Data](gen: T, threshold: AnyVal)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]) extends Module {
  override def desiredName: String = s"comparator_${gen.toString().toLowerCase()}"
  val io = IO(new ComparatorIO(gen)).suggestName("COMPARATOR")

  val thresholdValue = threshold match {
    case int: Int => gen.fromInt(int)
    case double: Double => gen.fromDouble(double)
    case _ => throw new IllegalArgumentException("Unsupported threshold type")
  }

  io.out := io.in > thresholdValue
}

class Maximum[T <: Data](gen: T, ins: Int)(implicit ord: PartialOrdered[T]) extends Module {
  override def desiredName: String = s"maximum_${gen.toString().toLowerCase()}"
  require(ins > 0, "Number of inputs must be greater than zero")
  val io = IO(new MISO(gen, ins))
  val out = io.in.reduce((a, b) => Mux(a > b, a, b))
  io.out := out
}

class Minimum[T <: Data](gen: T, ins: Int)(implicit ord: PartialOrdered[T]) extends Module {
  override def desiredName: String = s"minimum_${gen.toString().toLowerCase()}"
  require(ins > 0, "Number of inputs must be greater than zero")
  val io = IO(new MISO(gen, ins))
  val out = io.in.reduce((a, b) => Mux(a < b, a, b))
  io.out := out
}
