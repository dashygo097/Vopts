package mem.register

import chisel3._
import chisel3.util._

class RegisterFileIO[T <: Data](gen: T, size: Int) extends Bundle {
  val raddr = Input(UInt(log2Ceil(size).W))
  val waddr = Input(UInt(log2Ceil(size).W))
  val we = Input(Bool())
  val wdata = Input(gen)
  val rdata = Output(gen)
}

class RegisterFileCore[T <: Data](gen: T, size: Int) extends Module {
  val io = IO(new RegisterFileIO(gen, size))
  val regFile = RegInit(VecInit(Seq.fill(size)(0.U.asTypeOf(gen))))
  when(io.we) {
    regFile(io.waddr) := io.wdata
  }
  io.rdata := regFile(io.raddr)
}
