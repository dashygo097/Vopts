package vopts.math

import chisel3._
import chisel3.util._

class PartialProductGen(dw: Int) extends Module {
  override def desiredName: String = s"partial_product_gen_$dw"

  val total_width = 2 * dw

  val multiplicand        = IO(Input(UInt(dw.W)))
  val multiplier          = IO(Input(UInt(dw.W)))
  val multiplicand_signed  = IO(Input(Bool()))
  val multiplier_signed    = IO(Input(Bool()))
  // Output width is 2 * dw for full alignment
  val partial_products = IO(Output(Vec((dw + 1) / 2, UInt(total_width.W))))

  val multiplier_sign = Mux(multiplier_signed, multiplier(dw - 1), 0.U(1.W))
  val multiplier_ext  = Cat(Fill(2, multiplier_sign), multiplier, 0.U(1.W))
  val booth_encoders  = Seq.fill((dw + 1) / 2)(Module(new BoothRadix4()))

  val multiplicand_sign      = Mux(multiplicand_signed, multiplicand(dw - 1), 0.U(1.W))
  val multiplicand_ext       = Cat(Fill(2, multiplicand_sign), multiplicand)
  val multiplicand_ext_shift1 = Cat(Fill(1, multiplicand_sign), multiplicand, 0.U(1.W))

  for (i <- 0 until (dw + 1) / 2) {
    val booth_bits = if (i == 0) multiplier_ext(2, 0) else multiplier_ext(i * 2 + 2, i * 2)

    booth_encoders(i).y := booth_bits

    val raw_width = dw + 2
    val pp_raw   = Wire(UInt(raw_width.W))

    // Generate partial product from Booth encoding
    when(booth_encoders(i).zero) {
      pp_raw := 0.U
    }.elsewhen(booth_encoders(i).one && !booth_encoders(i).two) {
      // +/- 1 * M
      pp_raw := Mux(booth_encoders(i).neg, (~multiplicand_ext).asUInt + 1.U, multiplicand_ext)
    }.elsewhen(booth_encoders(i).two && !booth_encoders(i).one) {
      // +/- 2 * M (shift left by 1)
      pp_raw := Mux(booth_encoders(i).neg, (~multiplicand_ext_shift1).asUInt + 1.U, multiplicand_ext_shift1)
    }.otherwise {
      pp_raw := 0.U
    }

    // Sign extension to full width
    val sign_bit        = pp_raw(raw_width - 1)
    val pp_sign_extended = Wire(UInt(total_width.W))
    val fill_len        = (total_width - raw_width).max(0)
    pp_sign_extended := Cat(Fill(fill_len, sign_bit), pp_raw)

    partial_products(i) := pp_sign_extended << (2 * i).U
  }
}
