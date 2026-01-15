package vopts.math

import chisel3._
import chisel3.util._

class PartialProductGen(dw: Int) extends Module {
  override def desiredName: String = s"partial_product_gen_$dw"

  val totalWidth = 2 * dw

  val multiplicand    = IO(Input(UInt(dw.W)))
  val multiplier      = IO(Input(UInt(dw.W)))
  // Output width is 2 * dw to accommodate full alignment
  val partialProducts = IO(Output(Vec((dw + 1) / 2, UInt(totalWidth.W))))

  val multiplier_ext = Cat(0.U(2.W), multiplier, 0.U(1.W))
  val boothEncoders  = Seq.fill((dw + 1) / 2)(Module(new BoothRadix4()))

  for (i <- 0 until (dw + 1) / 2) {
    val boothBits = if (i == 0) multiplier_ext(2, 0) else multiplier_ext(i * 2 + 2, i * 2)

    boothEncoders(i).y := boothBits

    val rawWidth = dw + 2
    val ppRaw    = Wire(UInt(rawWidth.W))

    // Generate Partial Product based on Booth Encodings
    when(boothEncoders(i).zero) {
      ppRaw := 0.U
    }.elsewhen(boothEncoders(i).one && !boothEncoders(i).two) {
      // +/- 1 * M
      ppRaw := Mux(boothEncoders(i).neg, (~Cat(0.U(2.W), multiplicand)).asUInt + 1.U, Cat(0.U(2.W), multiplicand))
    }.elsewhen(boothEncoders(i).two && !boothEncoders(i).one) {
      // +/- 2 * M (Shift left by 1)
      ppRaw := Mux(boothEncoders(i).neg, (~Cat(0.U(1.W), multiplicand, 0.U(1.W))).asUInt + 1.U, Cat(0.U(1.W), multiplicand, 0.U(1.W)))
    }.otherwise {
      ppRaw := 0.U
    }

    // Sign Extension Logic
    val signBit        = ppRaw(rawWidth - 1)
    val ppSignExtended = Wire(UInt(totalWidth.W))
    val fillLen        = (totalWidth - rawWidth).max(0)
    ppSignExtended := Cat(Fill(fillLen, signBit), ppRaw)

    partialProducts(i) := ppSignExtended << (2 * i).U
  }
}
