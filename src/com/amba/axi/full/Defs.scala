package vopts.com.amba

import chisel3._

object AXIBurstType extends ChiselEnum {
  val FIXED = 0.U(2.W)
  val INCR  = 1.U(2.W)
  val WRAP  = 2.U(2.W)
}
