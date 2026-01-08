package vopts.com.amba

import chisel3._
import chisel3.util._

class AXILiteSlaveIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")
  val aWidth = addrWidth
  val dWidth = dataWidth

  val aw = Flipped(Decoupled(new AXILiteAddrIO(addrWidth)))
  val w  = Flipped(Decoupled(new AXILiteWriteIO(dataWidth)))
  val b  = Decoupled(new AXILiteWriteRespIO)
  val ar = Flipped(Decoupled(new AXILiteAddrIO(addrWidth)))
  val r  = Decoupled(new AXILiteReadIO(dataWidth))

  override def clone = new AXILiteSlaveIO(dataWidth, addrWidth).asInstanceOf[this.type]
}

object AXILiteSlaveIO {
  def apply(addrWidth: Int, dataWidth: Int): AXILiteSlaveIO =
    new AXILiteSlaveIO(addrWidth, dataWidth)
}

class AXILiteSlaveExtIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val AWADDR  = Input(UInt(addrWidth.W))
  val AWPROT  = Input(UInt(3.W))
  val AWVALID = Input(Bool())
  val AWREADY = Output(Bool())

  val WDATA  = Input(UInt(dataWidth.W))
  val WSTRB  = Input(UInt((dataWidth / 8).W))
  val WVALID = Input(Bool())
  val WREADY = Output(Bool())

  val BRESP  = Output(UInt(2.W))
  val BVALID = Output(Bool())
  val BREADY = Input(Bool())

  val ARADDR  = Input(UInt(addrWidth.W))
  val ARPROT  = Input(UInt(3.W))
  val ARVALID = Input(Bool())
  val ARREADY = Output(Bool())

  val RDATA  = Output(UInt(dataWidth.W))
  val RRESP  = Output(UInt(2.W))
  val RVALID = Output(Bool())
  val RREADY = Input(Bool())

  def connect(inst: AXILiteSlaveIO): Unit = {
    require(inst.dWidth == dataWidth, "Data width mismatch")
    require(inst.aWidth == addrWidth, "Address width mismatch")

    inst.aw.bits.addr := this.AWADDR
    inst.aw.bits.prot := this.AWPROT
    inst.aw.valid     := this.AWVALID
    this.AWREADY      := inst.aw.ready

    inst.w.bits.data := this.WDATA
    inst.w.bits.strb := this.WSTRB
    inst.w.valid     := this.WVALID
    this.WREADY      := inst.w.ready

    this.BRESP   := inst.b.bits.resp
    this.BVALID  := inst.b.valid
    inst.b.ready := this.BREADY

    inst.ar.bits.addr := this.ARADDR
    inst.ar.bits.prot := this.ARPROT
    inst.ar.valid     := this.ARVALID
    this.ARREADY      := inst.ar.ready

    this.RDATA   := inst.r.bits.data
    this.RRESP   := inst.r.bits.resp
    this.RVALID  := inst.r.valid
    inst.r.ready := this.RREADY
  }

  def connect(inst: AXILiteMasterExtIO): Unit = {
    inst.AWADDR  := this.AWADDR
    inst.AWPROT  := this.AWPROT
    inst.AWVALID := this.AWVALID
    this.AWREADY := inst.AWREADY

    inst.WDATA  := this.WDATA
    inst.WSTRB  := this.WSTRB
    inst.WVALID := this.WVALID
    this.WREADY := inst.WREADY

    this.BRESP  := inst.BRESP
    this.BVALID := inst.BVALID
    inst.BREADY := this.BREADY

    inst.ARADDR  := this.ARADDR
    inst.ARPROT  := this.ARPROT
    inst.ARVALID := this.ARVALID
    this.ARREADY := inst.ARREADY

    this.RDATA  := inst.RDATA
    this.RRESP  := inst.RRESP
    this.RVALID := inst.RVALID
    inst.RREADY := this.RREADY
  }
}
