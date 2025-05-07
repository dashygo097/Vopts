package com.fifo

import chisel3._
import chisel3.util._

class QueueIO[T <: Data](gen: T) extends Bundle {
  val enq = Flipped(Decoupled(gen))
  val deq = Decoupled(gen)
}

class Queue[T <: Data](gen: T, depth: Int) extends Module {
  val io = IO(new QueueIO(gen))

  val queue = RegInit(VecInit(Seq.fill(depth)(0.U.asTypeOf(gen))))
  val writePtr = RegInit(0.U(log2Ceil(depth).W))
  val readPtr = RegInit(0.U(log2Ceil(depth).W))
  val count = RegInit(0.U(log2Ceil(depth + 1).W))

  io.enq.ready := count < depth.U
  when(io.enq.fire) {
    queue(writePtr) := io.enq.bits
    writePtr := writePtr + 1.U
    count := count + 1.U
  }
  io.deq.valid := count > 0.U
  io.deq.bits := queue(readPtr)
  when(io.deq.fire) {
    readPtr := readPtr + 1.U
    count := count - 1.U
  }
}
