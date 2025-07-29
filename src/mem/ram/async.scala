package mem.sram

import chisel3._
import chisel3.util._

class AsyncRWIO extends Bundle {
  val we = Input(Bool())
  val re = Input(Bool())

  val rd_clk = Input(Clock())
  val wr_clk = Input(Clock())
}

class AsyncRAMIO[T <: Data](gen: T, size: Int) extends Bundle {
  val addr = Input(UInt(log2Ceil(size).W))
  val dataIn = Input(gen)
  val dataOut = Output(gen)

  val en = new AsyncRWIO
}

class AsyncRAMCore[T <: Data](gen: T, size: Int) extends Module {
  val io = IO(new AsyncRAMIO(gen, size)).suggestName("A_RAM")

  val mem = SyncReadMem(size, gen)
  val rdata = Reg(gen)
  io.dataOut := DontCare

  when(io.en.we) {
    mem.write(io.addr, io.dataIn, io.en.wr_clk)
  }

  when (io.en.re) {
    io.dataOut := mem.read(io.addr, io.en.rd_clk)
  } 
}
 
