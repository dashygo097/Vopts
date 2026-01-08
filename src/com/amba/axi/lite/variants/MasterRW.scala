package vopts.com.amba

import vopts.utils._
import chisel3._

class AXILiteMasterRW(
  addrWidth: Int,
  dataWidth: Int
) extends AXILiteMaster(addrWidth, dataWidth) {
  override def desiredName: String =
    s"axilite_master_rw_${addrWidth}x$dataWidth"

  // User interface
  val write_data = IO(Input(UInt(dataWidth.W))).suggestName("W_DATA")
  val write_addr = IO(Input(UInt(addrWidth.W))).suggestName("W_ADDR")
  val write_en   = IO(Input(Bool())).suggestName("W_EN")
  val write_done = IO(Output(Bool())).suggestName("W_DONE")
  val write_resp = IO(Output(UInt(2.W))).suggestName("W_RESP")

  val read_data = IO(Output(UInt(dataWidth.W))).suggestName("R_DATA")
  val read_addr = IO(Input(UInt(addrWidth.W))).suggestName("R_ADDR")
  val read_en   = IO(Input(Bool())).suggestName("R_EN")
  val read_done = IO(Output(Bool())).suggestName("R_DONE")
  val read_resp = IO(Output(UInt(2.W))).suggestName("R_RESP")

  val busy = IO(Output(Bool())).suggestName("BUSY")

  // User-facing outputs
  write_done := false.B
  read_done  := false.B
  write_resp := 0.U
  read_resp  := 0.U
  read_data  := axi.r.bits.data
  busy       := state =/= IDLE

  override protected def onIDLE(): Unit =
    when(write_en) {
      state       := WRITE_ADDR
      axi_awaddr  := write_addr
      axi_wdata   := write_data
      axi_awvalid := true.B
    }.elsewhen(read_en) {
      state       := READ_ADDR
      axi_araddr  := read_addr
      axi_arvalid := true.B
    }

  override protected def onWriteResp(): Unit = {
    write_done := true.B
    write_resp := axi.b.bits.resp
  }

  override protected def onReadData(): Unit = {
    read_done := true.B
    read_resp := axi.r.bits.resp
  }

  setup()
}

object TestAXILiteMasterRW extends App {
  VerilogEmitter.parse(new AXILiteMasterRW(32, 32), "axilite_master_rw.sv", info = true)
}
