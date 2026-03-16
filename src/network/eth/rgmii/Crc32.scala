package vopts.net.eth

import chisel3._

class CRC32 extends Module {
  override def desiredName: String =
    s"crc32"
  val io                           = IO(new Bundle {
    val data  = Input(UInt(8.W))
    val valid = Input(Bool())
    val reset = Input(Bool())
    val crc   = Output(UInt(32.W))
  })

  val crcReg = RegInit("hFFFFFFFF".U(32.W))

  when(io.reset) {
    crcReg := "hFFFFFFFF".U(32.W)
  }.elsewhen(io.valid) {
    var crcNext = crcReg

    for (i <- 0 until 8) {
      val bit = io.data(i) ^ crcNext(0)
      crcNext = Mux(
        bit,
        (crcNext >> 1) ^ "hEDB88320".U(32.W), // Reversed polynomial
        crcNext >> 1
      )
    }

    crcReg := crcNext
  }

  // Invert the CRC using XOR with all 1's
  io.crc := crcReg ^ "hFFFFFFFF".U(32.W)
}
