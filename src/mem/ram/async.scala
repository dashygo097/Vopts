package mem.ram

import chisel3._
import chisel3.util._

class AsyncRAMIO[T <: Data](gen: T, size: Int) extends Bundle {
  val addr    = Input(UInt(log2Ceil(size).W))
  val dataIn  = Input(gen)
  val dataOut = Output(gen)

  val we   = Input(Bool())
  val re   = Input(Bool())
  val wclk = Input(Clock())
  val rclk = Input(Clock())
}

class AsyncRAM[T <: Data](gen: T, size: Int) extends Module {
  override def desiredName = s"a_ram_${gen.toString.toLowerCase()}_x$size"
  val io                   = IO(new AsyncRAMIO(gen, size)).suggestName("A_RAM")

  val mem   = SyncReadMem(size, gen)
  val rdata = Reg(gen)
  io.dataOut := DontCare

  when(io.we) {
    mem.write(io.addr, io.dataIn, io.wclk)
  }
  when(io.re) {
    io.dataOut := mem.read(io.addr, io.rclk)
  }
}
