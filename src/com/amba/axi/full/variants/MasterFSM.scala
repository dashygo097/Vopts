package vopts.com.amba

import vopts.utils._
import chisel3._
import chisel3.util._

class AXIFullMasterFSM(
  addrWidth: Int,
  dataWidth: Int,
  idWidth: Int,
  userWidth: Int = 0
) extends AXIFullMasterBaseFSM(addrWidth, dataWidth, idWidth, userWidth) {
  override def desiredName: String =
    s"axifull_master_fsm_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"

  // User Interface
  val write_data  = IO(Input(UInt(dataWidth.W))).suggestName("W_DATA")
  val write_addr  = IO(Input(UInt(addrWidth.W))).suggestName("W_ADDR")
  val write_strb  = IO(Input(UInt((dataWidth / 8).W))).suggestName("W_STRB")
  val write_len   = IO(Input(UInt(8.W))).suggestName("W_LEN")
  val write_burst = IO(Input(UInt(2.W))).suggestName("W_BURST")
  val write_id    = IO(Input(UInt(idWidth.W))).suggestName("W_ID")
  val write_en    = IO(Input(Bool())).suggestName("W_EN")
  val write_done  = IO(Output(Bool())).suggestName("W_DONE")
  val write_resp  = IO(Output(UInt(2.W))).suggestName("W_RESP")
  val write_bid   = IO(Output(UInt(idWidth.W))).suggestName("W_BID")

  val read_addr  = IO(Input(UInt(addrWidth.W))).suggestName("R_ADDR")
  val read_len   = IO(Input(UInt(8.W))).suggestName("R_LEN")
  val read_burst = IO(Input(UInt(2.W))).suggestName("R_BURST")
  val read_id    = IO(Input(UInt(idWidth.W))).suggestName("R_ID")
  val read_en    = IO(Input(Bool())).suggestName("R_EN")
  val read_done  = IO(Output(Bool())).suggestName("R_DONE")
  val read_data  = IO(Output(UInt(dataWidth.W))).suggestName("R_DATA")
  val read_resp  = IO(Output(UInt(2.W))).suggestName("R_RESP")
  val read_rid   = IO(Output(UInt(idWidth.W))).suggestName("R_RID")
  val read_last  = IO(Output(Bool())).suggestName("R_LAST")

  val busy = IO(Output(Bool())).suggestName("BUSY")

  // Default outputs
  write_done := false.B
  write_resp := 0.U
  write_bid  := 0.U
  read_done  := false.B
  read_data  := axi.r.bits.data
  read_resp  := axi.r.bits.resp
  read_rid   := axi.r.bits.id
  read_last  := axi.r.bits.last
  busy       := state =/= IDLE

  override protected def onIDLE(): Unit =
    when(write_en) {
      state       := WRITE_ADDR
      axi_awaddr  := write_addr
      axi_awid    := write_id
      axi_awlen   := write_len
      axi_awsize  := log2Ceil(dataWidth / 8).U
      axi_awburst := write_burst
      axi_awvalid := true.B
      // Capture first beat
      axi_wdata   := write_data
      axi_wstrb   := write_strb
      axi_wid     := write_id
      axi_wlast   := (write_len === 0.U)
    }.elsewhen(read_en) {
      state       := READ_ADDR
      axi_araddr  := read_addr
      axi_arid    := read_id
      axi_arlen   := read_len
      axi_arsize  := log2Ceil(dataWidth / 8).U
      axi_arburst := read_burst
      axi_arvalid := true.B
    }

  // Continuously sample write_data during burst
  override protected def onWriteData(): Unit = {
    // FIXME: FSM introduces a 2-cycle latency for write data
    // This is a temporary solution
    axi_wdata := RegNext(RegNext(write_data))
    axi_wstrb := RegNext(RegNext(write_strb))
  }

  override protected def onWriteResp(): Unit = {
    write_done := true.B
    write_resp := axi.b.bits.resp
    write_bid  := axi.b.bits.id
  }

  override protected def onReadData(): Unit =
    when(axi.r.bits.last && axi.r.valid) {
      read_done := true.B
    }

  setup()
}

object TestAXIFullMasterFSM extends App {
  VerilogEmitter.parse(
    new AXIFullMasterFSM(32, 32, 4, 1),
    "axifull_master_rw.sv",
    info = true
  )
}
