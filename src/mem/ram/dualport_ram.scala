package mem.ram

import chisel3._
import chisel3.util._

class DualPortByteRAMIO(size: Int) extends Bundle {
  val addrWidth = log2Ceil(size)
  val dataIn = Input(UInt(32.W))
  val rdAddr = Input(UInt(addrWidth.W))
  val wrAddr = Input(UInt(addrWidth.W))
  val dataOut = Output(UInt(32.W))

  val byteena_a = Input(UInt(4.W))
  val we = Input(Bool())
  val wclk = Input(Clock())
  val rclk = Input(Clock())
}

class DualPortByteRAM(size: Int) extends Module {
  override def desiredName = s"a_ram_dual_bytes_x${size}"
  val io = IO(new DualPortByteRAMIO(size)).suggestName("RAM_DUAL")

  val mem = SyncReadMem(size, UInt(32.W))
  val tmpOut = RegInit(0.U(32.W))
  val tmpIn = Wire(UInt(32.W))

  io.dataOut := DontCare
  tmpIn := Cat(
    Mux(io.byteena_a(3), io.dataIn(31, 24), tmpOut(31, 24)),
    Mux(io.byteena_a(2), io.dataIn(23, 16), tmpOut(23, 16)),
    Mux(io.byteena_a(1), io.dataIn(15, 8), tmpOut(15, 8)),
    Mux(io.byteena_a(0), io.dataIn(7, 0), tmpOut(7, 0))
  )

  when(io.we) {
    tmpOut := mem.read(io.wrAddr, io.rclk)
    mem.write(io.wrAddr, tmpIn, io.wclk)
  } .otherwise {
    io.dataOut := mem.read(io.rdAddr, io.rclk)
  }
}
