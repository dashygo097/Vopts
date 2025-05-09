package mem.sram

import chisel3._

class AsyncRWIO extends Bundle {
  val we = Input(Bool())
  val re = Input(Bool())

  val rd_clk = Input(Clock())
  val wr_clk = Input(Clock())
}

class AsyncSRAMIO[T <: Data](gen: T, addrWidth: Int) extends Bundle {
  val addr = Input(UInt(addrWidth.W))
  val dataIn = Input(gen)
  val dataOut = Output(gen)

  val en = new AsyncRWIO
}

class AsyncSRAMCore[T <: Data](gen: T, addrWidth: Int) extends Module {
  val io = IO(new AsyncSRAMIO(gen, addrWidth))

  val mem = SyncReadMem(1 << addrWidth, gen)

  when(io.en.we) {
    mem.write(io.addr, io.dataIn, io.en.wr_clk)
  }

  when (io.en.re) {
    io.dataOut := mem.read(io.addr, io.en.rd_clk)
  } .otherwise {
    io.dataOut := 0.U.asTypeOf(gen)
  }
}
 
