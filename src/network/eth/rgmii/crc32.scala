package net.eth

import chisel3._

class CRC32 extends Module {
  val io = IO(new Bundle {
    val data = Input(UInt(8.W))
    val valid = Input(Bool())
    val reset = Input(Bool())
    val crc = Output(UInt(32.W))
  })

  val crcReg = RegInit(0xFFFFFFFF.U(32.W))

  when(io.reset) {
    crcReg := 0xFFFFFFFF.U
  }.elsewhen(io.valid) {
    val crcNext = Wire(UInt(32.W))
    crcNext := crcReg
    
    for (i <- 0 until 8) {
      val bit = io.data(i) ^ crcNext(0)
      val temp = Mux(bit, 
        (crcNext >> 1) ^ 0xEDB88320L.U(32.W),
        crcNext >> 1
      )
      crcNext := temp
    }
    
    crcReg := crcNext
  }

  io.crc := ~crcReg 
}
