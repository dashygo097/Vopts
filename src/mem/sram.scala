package mem

import chisel3._
import chisel3.util._

class RWIO extends Bundle {
  val we = Input(Bool())
  val re = Input(Bool())
}

class SRAMIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val addr = Input(UInt(addrWidth.W))
  val dataIn = Input(UInt(dataWidth.W))
  val dataOut = Output(UInt(dataWidth.W))

  val en = new RWIO
}

class SRAMCore(addrWidth: Int, dataWidth: Int) extends Module {
  val io = IO(new SRAMIO(addrWidth, dataWidth))

  val mem = SyncReadMem(1 << addrWidth, UInt(dataWidth.W))

  when(io.en.we) {
    mem.write(io.addr, io.dataIn)
  }

  when (io.en.re) {
    io.dataOut := mem.read(io.addr)
  } .otherwise {
    io.dataOut := 0.U
  }
}

