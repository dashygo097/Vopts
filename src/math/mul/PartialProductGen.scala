package vopts.math

import chisel3._
import chisel3.util._

class PartialProductGen(dw: Int) extends Module {
  override def desiredName: String = s"partial_product_gen_$dw"

  val multiplicand    = IO(Input(UInt(dw.W)))
  val multiplier      = IO(Input(UInt(dw.W)))
  val partialProducts = IO(Output(Vec((dw + 1) / 2, UInt((dw + 3).W))))

  val x_ext = Cat(multiplicand(dw - 1), multiplicand).asSInt
  val x_2   = (x_ext << 1).asUInt

  val y_ext = Cat(multiplier, 0.U(1.W))

  val encoders = Seq.fill((dw + 1) / 2)(Module(new BoothRadix4))

  for (i <- 0 until (dw + 1) / 2) {
    val y_bits = y_ext(2 * i + 2, 2 * i)
    encoders(i).y := y_bits

    val pp_raw = Wire(UInt((dw + 1).W))
    pp_raw := MuxCase(
      0.U,
      Seq(
        encoders(i).zero -> 0.U,
        encoders(i).one  -> x_ext.asUInt,
        encoders(i).two  -> x_2
      )
    )

    val pp_final = Mux(encoders(i).neg, (~pp_raw).asUInt + 1.U, pp_raw)

    val pp_shifted = Cat(
      Fill(2, pp_final(dw)),
      pp_final,
      0.U((2 * i).W)
    )

    partialProducts(i) := pp_shifted
  }
}
