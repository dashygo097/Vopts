package utils

import chisel3._

object Zero {
  def apply[T <: Data](gen: T): T = {
    val zero = Wire(gen)
    gen match {
      case _: UInt => zero := 0.U
      case _: SInt => zero := 0.S
      case fp: FP => zero := new FP(fp.get_dw(), fp.get_bp()).fromDouble(0.0).asTypeOf(gen)
      case _: Float32 => zero := Float32(0.0)
      case _ => throw new IllegalArgumentException(s"Unsupported type for zero: ${gen.getClass}")
    }
    zero
  }
}
