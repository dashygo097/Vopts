package vopts.math

import chisel3._
import chisel3.util._

class PartialProductGen(dw: Int) extends Module {
  override def desiredName: String = s"partial_product_gen_$dw"
  val totalWidth      = 2 * dw
  val isSignedA       = IO(Input(Bool())) // 控制被乘数 (multiplicand)
  val isSignedB       = IO(Input(Bool())) // 控制乘数 (multiplier)
  val multiplicand    = IO(Input(UInt(dw.W)))
  val multiplier      = IO(Input(UInt(dw.W)))
  // Output width is 2 * dw to accommodate full alignment
  val numPPs = (dw / 2) + 1  //在做无符号大数的时候，必须再扩展一位
  val partialProducts = IO(Output(Vec(numPPs, UInt(totalWidth.W))))   
  //val multiplier_ext = Cat(0.U(2.W), multiplier, 0.U(1.W)) 

 

  val mult_msb = Mux(isSignedB, multiplier(dw - 1), 0.B)               //决定有无符号位的扩展
  val multiplier_ext = Cat(mult_msb,mult_msb,mult_msb, multiplier, 0.U(1.W))   //扩展后的数           
  val boothEncoders  = Seq.fill(numPPs)(Module(new BoothRadix4()))           //生成相应的booth译码机

  for (i <- 0 until numPPs) {
    val boothBits = if (i == 0) multiplier_ext(2, 0) else multiplier_ext(i * 2 + 2, i * 2)  //booth译码器每次看三位

    boothEncoders(i).y := boothBits     //作为输入给booth译码机

    val rawWidth = dw + 2
    val ppRaw    = Wire(UInt(rawWidth.W))     //部分积
    /*被乘数扩展逻辑*/
    val mcand_msb = Mux(isSignedA, multiplicand(dw - 1), 0.B)

    val m_ext_1 = Cat(mcand_msb, mcand_msb, multiplicand)
    val m_ext_2 = Cat(mcand_msb, multiplicand, 0.U(1.W))

    // Generate Partial Product based on Booth Encodings
   when(boothEncoders(i).zero) {
      ppRaw := 0.U
    }.elsewhen(boothEncoders(i).one && !boothEncoders(i).two) {
      ppRaw := Mux(boothEncoders(i).neg, (~m_ext_1).asUInt + 1.U, m_ext_1)
    }.elsewhen(boothEncoders(i).two && !boothEncoders(i).one) {
      ppRaw := Mux(boothEncoders(i).neg, (~m_ext_2).asUInt + 1.U, m_ext_2)
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
