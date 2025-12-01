package object utils {
  import scala.language.implicitConversions
  import chisel3._

  implicit val uintPartialOrdered: PartialOrdered[UInt]   = PartialOrderedInstances.uintPartialOrdered
  implicit val sintPartialOrdered: PartialOrdered[SInt]   = PartialOrderedInstances.sintPartialOrdered
  implicit val fpPartialOrdered: PartialOrdered[FP]       = PartialOrderedInstances.fpPartialOrdered
  implicit val floatPartialOrdered: PartialOrdered[Float] = PartialOrderedInstances.floatPartialOrdered

  implicit val uintArithmetic: Arithmetic[UInt]   = ArithmeticInstances.uintArithmetic
  implicit val sintArithmetic: Arithmetic[SInt]   = ArithmeticInstances.sintArithmetic
  implicit val fpArithmetic: Arithmetic[FP]       = ArithmeticInstances.fpArithmetic
  implicit val floatArithmetic: Arithmetic[Float] = ArithmeticInstances.floatArithmetic

  implicit def partialOrderedSyntax[T <: Data](x: T): PartialOrderedSyntax.PartialOrderedOps[T] =
    new PartialOrderedSyntax.PartialOrderedOps(x)

  implicit def arithmeticSyntax[T <: Data](x: T): ArithmeticSyntax.ArithmeticOps[T] =
    new ArithmeticSyntax.ArithmeticOps(x)
}
