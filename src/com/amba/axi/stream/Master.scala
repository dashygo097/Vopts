package vopts.com.amba

import chisel3._
import chisel3.util._

class AXIStreamMasterIO(dataWidth: Int, idWidth: Int, destWidth: Int, userWidth: Int) extends Bundle {
  val dWidth  = dataWidth
  val iWidth  = idWidth
  val deWidth = destWidth
  val uWidth  = userWidth

  val t = Decoupled(new AXIStreamIO(dataWidth, idWidth, destWidth, userWidth))

  override def clone = new AXIStreamMasterIO(dataWidth, idWidth, destWidth, userWidth).asInstanceOf[this.type]
}

class AXIStreamMasterExtIO(dataWidth: Int, idWidth: Int, destWidth: Int, userWidth: Int) extends Bundle {
  val dWidth  = dataWidth
  val iWidth  = idWidth
  val deWidth = destWidth
  val uWidth  = userWidth

  val TDATA  = Output(UInt(dataWidth.W))
  val TKEEP  = Output(UInt((dataWidth / 8).W))
  val TSTRB  = Output(UInt((dataWidth / 8).W))
  val TLAST  = Output(Bool())
  val TID    = Output(UInt(idWidth.W))
  val TDEST  = Output(UInt(idWidth.W))
  val TUSER  = Output(UInt(userWidth.W))
  val TVALID = Output(Bool())
  val TREADY = Input(Bool())

  def connect(intf: AXIStreamMasterIO): Unit = {
    require(intf.dWidth == this.dWidth, "Data width mismatch")
    require(intf.iWidth == this.iWidth, "ID width mismatch")
    require(intf.deWidth == this.deWidth, "Dest width mismatch")
    require(intf.uWidth == this.uWidth, "User width mismatch")

    this.TDATA   := intf.t.bits.data
    this.TKEEP   := intf.t.bits.keep
    this.TSTRB   := intf.t.bits.strb
    this.TLAST   := intf.t.bits.last
    this.TID     := intf.t.bits.id
    this.TDEST   := intf.t.bits.dest
    this.TUSER   := intf.t.bits.user
    this.TVALID  := intf.t.valid
    intf.t.ready := this.TREADY
  }
}
