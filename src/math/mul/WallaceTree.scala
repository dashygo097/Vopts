package vopts.math

import chisel3._
import chisel3.util._
import scala.collection.mutable.ArrayBuffer

class WallaceTree(dw: Int) extends Module {
  override def desiredName: String = s"wallace_${dw}"

  val partialProducts = IO(Input(Vec((dw + 1) / 2, UInt((dw + 3).W))))
  val sum             = IO(Output(UInt((2 * dw).W)))
  val carry           = IO(Output(UInt((2 * dw).W)))

  // Full Adder
  def FA(a: Bool, b: Bool, c: Bool): (Bool, Bool) = {
    val sum   = a ^ b ^ c
    val carry = (a & b) | (b & c) | (a & c)
    (sum, carry)
  }

  // Half Adder
  def HA(a: Bool, b: Bool): (Bool, Bool) =
    (a ^ b, a & b)

  val alignedPPs = partialProducts.map(pp => Cat(Fill(2 * dw - pp.getWidth, pp(pp.getWidth - 1)), pp))

  var currentLevel = alignedPPs.toSeq

  while (currentLevel.length > 2) {
    val nextLevel = ArrayBuffer[UInt]()
    var i         = 0

    while (i < currentLevel.length)
      if (i + 2 < currentLevel.length) {
        // Use full adders for groups of 3
        val sum   = Wire(UInt((2 * dw).W))
        val carry = Wire(UInt((2 * dw).W))

        val sumBits   = Wire(Vec(2 * dw, Bool()))
        val carryBits = Wire(Vec(2 * dw, Bool()))

        for (bit <- 0 until (2 * dw)) {
          val (s, c) = FA(
            currentLevel(i)(bit),
            currentLevel(i + 1)(bit),
            currentLevel(i + 2)(bit)
          )
          sumBits(bit)   := s
          carryBits(bit) := c
        }

        sum   := sumBits.asUInt
        carry := Cat(carryBits.asUInt(2 * dw - 2, 0), 0.U(1.W))

        nextLevel += sum
        nextLevel += carry
        i += 3
      } else if (i + 1 < currentLevel.length) {
        // Use half adders for groups of 2
        val sum   = Wire(UInt((2 * dw).W))
        val carry = Wire(UInt((2 * dw).W))

        val sumBits   = Wire(Vec(2 * dw, Bool()))
        val carryBits = Wire(Vec(2 * dw, Bool()))

        for (bit <- 0 until (2 * dw)) {
          val (s, c) = HA(currentLevel(i)(bit), currentLevel(i + 1)(bit))
          sumBits(bit)   := s
          carryBits(bit) := c
        }

        sum   := sumBits.asUInt
        carry := Cat(carryBits.asUInt(2 * dw - 2, 0), 0.U(1.W))

        nextLevel += sum
        nextLevel += carry
        i += 2
      } else {
        // Pass through single element
        nextLevel += currentLevel(i)
        i += 1
      }

      currentLevel = nextLevel.toIndexedSeq
  }

  sum := currentLevel(0)
  if (currentLevel.length > 1) {
    carry := currentLevel(1)
  } else {
    carry := 0.U
  }
}
