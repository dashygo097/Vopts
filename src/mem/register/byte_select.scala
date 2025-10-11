package mem.register

import chisel3._

class ByteSelectIO(dataWidth: Int) extends Bundle {
  val in   = Input(UInt(dataWidth.W))
  val strb = Input(UInt((dataWidth / 8).W))
  val out  = Output(UInt(dataWidth.W))
}

class ByteSelect(dataWidth: Int) extends Module {
  override def desiredName: String = s"byteselect_x$dataWidth"
  require(dataWidth % 8 == 0, "dataWidth must be a multiple of 8")
  val byteWidth                    = dataWidth / 8
  val io                           = IO(new ByteSelectIO(dataWidth))

  val out_reg = RegInit(0.U(dataWidth.W))
  io.out := out_reg

  for (i <- 0 until byteWidth)
    when(io.strb(i)) {
      out_reg((i + 1) * 8 - 1, i * 8) := io.in((i + 1) * 8 - 1, i * 8)
    }
}
