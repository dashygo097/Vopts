package vopts.mem.cache

import chisel3._
import chisel3.util._

class FIFOState(numLines: Int) extends ReplacementPolicyState(numLines) {
  val pointer = RegInit(0.U(log2Ceil(numLines).W))

  override def getVictim(): UInt = pointer

  override def update(accessedIndex: UInt, isHit: Bool): Unit =
    when(!isHit) {
      pointer := Mux(pointer === (numLines - 1).U, 0.U, pointer + 1.U)
    }

  override def reset(): Unit =
    pointer := 0.U
}
