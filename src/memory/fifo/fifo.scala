package mem.fifo

import chisel3._
import chisel3.util._

class SyncFIFOIO[T <: Data](gen: T) extends Bundle {
  val enq   = Flipped(Decoupled(gen))
  val deq   = Decoupled(gen)
  val empty = Output(Bool())
  val full  = Output(Bool())
}

class SyncFIFO[T <: Data](gen: T, depth: Int) extends Module {
  require(isPow2(depth), "FIFO depth must be a power of 2")

  override def desiredName: String = s"sync_fifo_${depth}x${gen.getWidth}"
  val io                           = IO(new SyncFIFOIO(gen)).suggestName("S_FIFO")

  val ptrWidth = log2Ceil(depth + 1)

  val mem          = SyncReadMem(depth, gen)
  val enqPtr       = RegInit(0.U(ptrWidth.W))
  val deqPtr       = RegInit(0.U(ptrWidth.W))
  val maybeFullReg = RegInit(false.B)

  val empty = enqPtr === deqPtr && !maybeFullReg
  val full  = enqPtr === deqPtr && maybeFullReg

  // I/O Connections
  io.enq.ready := !full
  io.deq.valid := !empty
  io.full      := full
  io.empty     := empty

  // W
  when(io.enq.fire) {
    mem.write(enqPtr(log2Ceil(depth) - 1, 0), io.enq.bits)
    enqPtr := Mux(enqPtr === (depth - 1).U, 0.U, enqPtr + 1.U)
  }

  // R
  val deqPtrNext = Mux(deqPtr === (depth - 1).U, 0.U, deqPtr + 1.U)
  when(io.deq.fire) {
    deqPtr := deqPtrNext
  }
  io.deq.bits := mem.read(deqPtr(log2Ceil(depth) - 1, 0))

  // Full/Empty
  when(io.enq.fire =/= io.deq.fire) {
    maybeFullReg := io.enq.fire
  }
}
