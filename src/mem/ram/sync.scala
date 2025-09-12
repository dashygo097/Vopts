package mem.ram

import chisel3._
import chisel3.util._

class SyncRAMIO[T <: Data](gen: T, size: Int) extends Bundle {
  val addr = Input(UInt(log2Ceil(size).W))
  val dataIn = Input(gen)
  val dataOut = Output(gen)

  val we = Input(Bool())
  val re = Input(Bool())
}

class SyncRAMCore[T <: Data](gen: T, size: Int) extends Module {
  override def desiredName = s"s_ram_${gen.toString().toLowerCase()}_x${size}"
  val io = IO(new SyncRAMIO(gen, size)).suggestName("S_RAM")

  val mem = SyncReadMem(size, gen)
  io.dataOut := DontCare

  when(io.we) {
    mem.write(io.addr, io.dataIn)
  }
  when (io.re) {
    io.dataOut := mem.read(io.addr)
  }
}

