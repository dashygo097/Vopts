package mem.sram

import chisel3._

class RWIO extends Bundle {
  val we = Input(Bool())
  val re = Input(Bool())
}

class SyncSRAMIO[T <: Data](gen: T, addrWidth: Int) extends Bundle {
  val addr = Input(UInt(addrWidth.W))
  val dataIn = Input(gen)
  val dataOut = Output(gen)

  val en = new RWIO
}

class SyncSRAMCore[T <: Data](gen: T, addrWidth: Int) extends Module {
  val io = IO(new SyncSRAMIO(gen, addrWidth))

  val mem = SyncReadMem(1 << addrWidth, gen)

  when(io.en.we) {
    mem.write(io.addr, io.dataIn)
  }

  when (io.en.re) {
    io.dataOut := mem.read(io.addr)
  } .otherwise {
    io.dataOut := 0.U.asTypeOf(gen)
  }
}

