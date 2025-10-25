package mem.fifo

import utils._
import chisel3._
import chisel3.util._

class SyncFIFOIO[T <: Data](gen: T, depth: Int) extends Bundle {
  val enq   = Flipped(Decoupled(gen))
  val deq   = Decoupled(gen)
  val empty = Output(Bool())
  val full  = Output(Bool())
}

class SyncFIFO[T <: Data](gen: T, depth: Int) extends Module {
  override def desiredName: String =
    s"sync_fifo_${depth}x${gen.getWidth}"
  val io                           = IO(new SyncFIFOIO(gen, depth)).suggestName("S_FIFO")

  val queue  = Module(new Queue(gen, depth, pipe = false, flow = false))
  val enqPtr = RegInit(0.U(log2Ceil(depth).W))
  val deqPtr = RegInit(0.U(log2Ceil(depth).W))
  val full   = RegInit(false.B)
  val empty  = RegInit(true.B)

  io.enq.ready      := !full
  io.deq.valid      := !empty
  io.deq.bits       := queue.io.deq.bits
  io.full           := full
  io.empty          := empty
  queue.io.enq.bits := io.enq.bits

  when(io.enq.valid && io.enq.ready) {
    queue.io.enq.valid := true.B
    enqPtr             := Mux(enqPtr === (depth - 1).U, 0.U, enqPtr + 1.U)
    when(enqPtr + 1.U === deqPtr) {
      full := true.B
    }
    empty              := false.B
  }.otherwise {
    queue.io.enq.valid := false.B
  }
  when(io.deq.valid && io.deq.ready) {
    queue.io.deq.ready := true.B
    deqPtr             := Mux(deqPtr === (depth - 1).U, 0.U, deqPtr + 1.U)
    when(deqPtr + 1.U === enqPtr) {
      empty := true.B
    }
    full               := false.B
  }.otherwise {
    queue.io.deq.ready := false.B
  }
}

object TestSyncFIFO extends App {
  VerilogEmitter.parse(new SyncFIFO(UInt(32.W), 16), "sync_fifo.sv", info = true)
}
