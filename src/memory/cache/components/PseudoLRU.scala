package vopts.mem.cache

import chisel3._
import chisel3.util._

class PseudoLRUState(numLines: Int) extends ReplacementPolicyState(numLines) {
  val counterWidth = 64
  val counter      = RegInit(0.U(counterWidth.W))
  val lastUsed     = RegInit(VecInit(Seq.fill(numLines)(0.U(counterWidth.W))))

  override def getVictim(): UInt = {
    val minValue = lastUsed.reduce((a, b) => Mux(a < b, a, b))
    PriorityEncoder(lastUsed.map(_ === minValue))
  }

  override def update(accessedIndex: UInt, isHit: Bool): Unit = {
    lastUsed(accessedIndex) := counter
    counter                 := counter + 1.U
  }

  override def reset(): Unit = {
    counter  := 0.U
    lastUsed := VecInit(Seq.fill(numLines)(0.U(counterWidth.W)))
  }
}
