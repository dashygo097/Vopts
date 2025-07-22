package mem.register

import chisel3._

class CSRBusIO(busWidth: Int, addrWidth: Int) extends Bundle {
  val addr = Input(UInt(addrWidth.W))
  val dataIn = Output(UInt(busWidth.W))
  val dataOut = Input(UInt(busWidth.W))
  val we = Input(Bool())
  val re = Input(Bool())
}
