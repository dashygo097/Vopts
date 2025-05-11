package mem.sram

import chisel3._
import chisel3.util._

class RWIO extends Bundle {
  val we = Input(Bool())
  val re = Input(Bool())
}

class SyncRAMIO[T <: Data](gen: T, size: Int) extends Bundle {
  val addr = Input(UInt(log2Ceil(size).W))
  val dataIn = Input(gen)
  val dataOut = Output(gen)

  val en = new RWIO
}

class SyncRAMCore[T <: Data](gen: T, size: Int) extends Module {
  val io = IO(new SyncRAMIO(gen, size))

  val mem = SyncReadMem(size, gen)
  io.dataOut := DontCare

  when(io.en.we) {
    mem.write(io.addr, io.dataIn)
  }

  when (io.en.re) {
    io.dataOut := mem.read(io.addr)
  }
}

