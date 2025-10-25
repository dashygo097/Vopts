package math.resample

import utils._
import chisel3._

class AutoLinearInterpolator[T <: Data](gen: T)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]) extends Module {
  override def desiredName = s"interpolate_autolinear_${gen.toString.toLowerCase()}"
  val io                   = IO(new SISO(gen)).suggestName("INTERPOLATOR")

  val prev = Reg(gen)
  val next = Reg(gen)

  val counter      = RegInit(0.U(32.W))
  val clkDivision  = RegInit(1.U(32.W))
  val safeDivision = RegInit(1.U(32.W))

  val changed = io.in =/= next

  counter      := Mux(changed, 0.U, counter + 1.U)
  clkDivision  := Mux(changed, counter, clkDivision)
  safeDivision := Mux(clkDivision === 0.U, 1.U, clkDivision)

  when(changed) {
    prev   := next
    next   := io.in
    io.out := next
  }.otherwise {
    io.out := prev + ((next - prev) * gen.mapUInt(counter)) / gen.mapUInt(safeDivision)
  }
}
