package peripheral

import utils._
import chisel3._

class SegmentCore extends Module {
  val io = IO(new DSISO(UInt(4.W), UInt(7.W)))
  val segmentMap = VecInit(
    "b00111111".U, // 0
    "b00000110".U, // 1
    "b01011011".U, // 2
    "b01001111".U, // 3
    "b01100110".U, // 4
    "b01101101".U, // 5
    "b01111101".U, // 6
    "b00000111".U, // 7
    "b01111111".U, // 8
    "b01101111".U  // 9
  )
  io.out := segmentMap(io.in)
}

class MultiSegmentCore(num: Int) extends Module {
  val io = IO(new DMIMO((UInt(4.W), num), (UInt(7.W), num)))
  val segmentMap = VecInit(
    "b00111111".U, // 0
    "b00000110".U, // 1
    "b01011011".U, // 2
    "b01001111".U, // 3
    "b01100110".U, // 4
    "b01101101".U, // 5
    "b01111101".U, // 6
    "b00000111".U, // 7
    "b01111111".U, // 8
    "b01101111".U  // 9
  )

  for (i <- 0 until num) {
    io.out(i) := segmentMap(io.in(i))
  }
}
