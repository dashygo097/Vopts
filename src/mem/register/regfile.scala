package mem.register

import utils._
import chisel3._
import chisel3.util._

class RegFileIO[T <: Data](gen: T, size: Int) extends Bundle {
  val raddr = Input(UInt(log2Ceil(size).W))
  val waddr = Input(UInt(log2Ceil(size).W))
  val we = Input(Bool())
  val wdata = Input(gen)
  val rdata = Output(gen)
}

class DualReadRegFileIO[T <: Data](gen: T, size: Int) extends Bundle {
  val raddr1 = Input(UInt(log2Ceil(size).W))
  val raddr2 = Input(UInt(log2Ceil(size).W))
  val waddr = Input(UInt(log2Ceil(size).W))
  val we = Input(Bool())
  val wdata = Input(gen)
  val rdata1 = Output(gen)
  val rdata2 = Output(gen)
}

class RegFileCore[T <: Data](gen: T, size: Int)(implicit ev: Arithmetic[T]) extends Module {
  val io = IO(new RegFileIO(gen, size)).suggestName("REGFILE")
  val regFile = RegInit(VecInit(Seq.fill(size)(gen.zero())))
  when(io.we) {
    regFile(io.waddr) := io.wdata
  }
  io.rdata := regFile(io.raddr)
}

class DualReadRegFileCore[T <: Data](gen: T, size: Int)(implicit ev: Arithmetic[T]) extends Module {
  val io = IO(new DualReadRegFileIO(gen, size)).suggestName("REGFILE")
  val regFile = RegInit(VecInit(Seq.fill(size)(gen.zero())))
  when(io.we) {
    regFile(io.waddr) := io.wdata
  }
  io.rdata1 := regFile(io.raddr1)
  io.rdata2 := regFile(io.raddr2)
}



