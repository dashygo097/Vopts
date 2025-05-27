package func.common

import utils._
import utils.PartialOrderedSyntax._
import utils.ArithmeticSyntax._
import chisel3._

class ComparatorIO[T <: Data](gen: T) extends Bundle {
  val in = Input(gen)
  val out = Output(Bool())
}

class ComparatorCore[T <: Data](gen: T, threshold: AnyVal)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]) extends Module {
  val io = IO(new ComparatorIO(gen))

  val thresholdValue = threshold match {
    case int: Int => gen.fromInt(int)
    case double: Double => gen.fromDouble(double)
    case _ => throw new IllegalArgumentException("Unsupported threshold type")
  }

  io.out := io.in > thresholdValue
}
