package vopts.math

import chisel3._
import chisel3.util._

class PartialProductGen(dw: Int) extends Module {
  override def desiredName: String = s"partial_product_gen_$dw"

  val totalWidth   = 2 * dw
  val isSignedA    = IO(Input(Bool()))
  val isSignedB    = IO(Input(Bool()))
  val multiplicand = IO(Input(UInt(dw.W)))
  val multiplier   = IO(Input(UInt(dw.W)))

  // (dw/2) 个编码器覆盖全部乘数位，+1 处理有符号数符号位扩展
  val numPPs          = (dw / 2) + 1
  val partialProducts = IO(Output(Vec(numPPs, UInt(totalWidth.W))))

  // 乘数符号扩展：有符号时扩展符号位，无符号时补 0
  // 宽度：2(扩展) + dw + 1(补零) = dw+3
  // 最高编码器 i=numPPs-1 读取 [i*2+2 : i*2]，最高索引为 dw+1，在范围内
  val mult_msb       = Mux(isSignedB, multiplier(dw - 1), 0.B)
  val multiplier_ext = Cat(mult_msb, mult_msb, multiplier, 0.U(1.W))

  val boothEncoders = Seq.fill(numPPs)(Module(new BoothRadix4()))

  for (i <- 0 until numPPs) {

    // -------------------------------------------------------
    // Booth 编码器输入选择
    // -------------------------------------------------------
    val boothBits = if (i == 0) {
      // 最低组：{multiplier[1:0], 0}
      multiplier_ext(2, 0)
    } else if (i == numPPs - 1) {
      // 最高编码器：
      //   有符号时用符号位扩展 {msb, msb, msb}，处理负权重
      //   无符号时强制 000 → zero=1，该 PP 贡献为 0
      Mux(
        isSignedB,
        Cat(multiplier(dw - 1), multiplier(dw - 1), multiplier(dw - 1)),
        0.U(3.W)
      )
    } else {
      // 普通组：overlapping 3-bit window
      multiplier_ext(i * 2 + 2, i * 2)
    }

    boothEncoders(i).y := boothBits

    // -------------------------------------------------------
    // 被乘数扩展（rawWidth = dw+2，留两位符号保护）
    // -------------------------------------------------------
    val rawWidth  = dw + 2
    val ppRaw     = Wire(UInt(rawWidth.W))
    val mcand_msb = Mux(isSignedA, multiplicand(dw - 1), 0.B)
    val m_ext_1   = Cat(mcand_msb, mcand_msb, multiplicand)        // ×1 用
    val m_ext_2   = Cat(mcand_msb, multiplicand, 0.U(1.W))         // ×2 用

    // -------------------------------------------------------
    // 部分积生成
    // -------------------------------------------------------
    when(boothEncoders(i).zero) {
      ppRaw := 0.U
    }.elsewhen(boothEncoders(i).one && !boothEncoders(i).two) {
      ppRaw := Mux(boothEncoders(i).neg, (~m_ext_1).asUInt + 1.U, m_ext_1)
    }.elsewhen(boothEncoders(i).two && !boothEncoders(i).one) {
      ppRaw := Mux(boothEncoders(i).neg, (~m_ext_2).asUInt + 1.U, m_ext_2)
    }.otherwise {
      ppRaw := 0.U
    }

    // -------------------------------------------------------
    // 符号扩展到 totalWidth，然后左移对齐
    // -------------------------------------------------------
    val signBit        = ppRaw(rawWidth - 1)
    val fillLen        = (totalWidth - rawWidth).max(0)
    val ppSignExtended = Cat(Fill(fillLen, signBit), ppRaw)

    partialProducts(i) := ppSignExtended << (2 * i).U
  }
}