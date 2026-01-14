package vopts.math

import chisel3._
import chisel3.util._

class BoothRadix4 extends Module {
  override def desiredName: String = "booth_radix4"

  val y    = IO(Input(UInt(3.W)))
  val neg  = IO(Output(Bool()))
  val zero = IO(Output(Bool()))
  val one  = IO(Output(Bool()))
  val two  = IO(Output(Bool()))

  // Booth encoding table
  val encoding = MuxLookup(y, "b0100".U)(
    Seq(
      1.U -> "b0010".U, // 001: +1
      2.U -> "b0010".U, // 010: +1
      3.U -> "b0001".U, // 011: +2
      4.U -> "b1001".U, // 100: -2
      5.U -> "b1010".U, // 101: -1
      6.U -> "b1010".U, // 110: -1
    )
  )

  neg  := encoding(3)
  zero := encoding(2)
  one  := encoding(1)
  two  := encoding(0)
}
