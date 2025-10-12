package com.axi

import chisel3._
import chisel3.util._
import scala.math.BigInt

class AXIFullSlaveIO(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0)
    extends Bundle {
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")
  val aWidth = addrWidth
  val dWidth = dataWidth
  val iWidth = idWidth
  val uWidth = userWidth

  val aw = Flipped(Decoupled(new AXIFullAddrIO(addrWidth, idWidth, userWidth)))
  val w  = Flipped(Decoupled(new AXIFullWriteIO(dataWidth, idWidth, userWidth)))
  val b  = Decoupled(new AXIFullWriteRespIO(idWidth, userWidth))
  val ar = Flipped(Decoupled(new AXIFullAddrIO(addrWidth, idWidth, userWidth)))
  val r  = Decoupled(new AXIFullReadIO(dataWidth, idWidth, userWidth))

  override def clone =
    new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth).asInstanceOf[this.type]

}

object AXIFullSlaveIO {
  def apply(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0): AXIFullSlaveIO =
    new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth)
}

class AXIFullSlaveExternalIO(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0)
    extends Bundle {
  val AWADDR   = Input(UInt(addrWidth.W))
  val AWPROT   = Input(UInt(3.W))
  val AWVALID  = Input(Bool())
  val AWREADY  = Output(Bool())
  val AWID     = Input(UInt(idWidth.W))
  val AWLEN    = Input(UInt(8.W))
  val AWSIZE   = Input(UInt(3.W))
  val AWBURST  = Input(UInt(2.W))
  val AWLOCK   = Input(Bool())
  val AWCACHE  = Input(UInt(4.W))
  val AWQOS    = Input(UInt(4.W))
  val AWREGION = Input(UInt(4.W))
  val AWUSER   = Input(UInt(userWidth.W))

  val WDATA  = Input(UInt(dataWidth.W))
  val WSTRB  = Input(UInt((dataWidth / 8).W))
  val WVALID = Input(Bool())
  val WREADY = Output(Bool())
  val WLAST  = Input(Bool())
  val WID    = Input(UInt(idWidth.W))
  val WUSER  = Input(UInt(userWidth.W))

  val BREADY = Input(Bool())
  val BRESP  = Output(UInt(2.W))
  val BVALID = Output(Bool())
  val BID    = Output(UInt(idWidth.W))
  val BUSER  = Output(UInt(userWidth.W))

  val ARADDR   = Input(UInt(addrWidth.W))
  val ARPROT   = Input(UInt(3.W))
  val ARVALID  = Input(Bool())
  val ARREADY  = Output(Bool())
  val ARID     = Input(UInt(idWidth.W))
  val ARLEN    = Input(UInt(8.W))
  val ARSIZE   = Input(UInt(3.W))
  val ARBURST  = Input(UInt(2.W))
  val ARLOCK   = Input(Bool())
  val ARCACHE  = Input(UInt(4.W))
  val ARQOS    = Input(UInt(4.W))
  val ARREGION = Input(UInt(4.W))
  val ARUSER   = Input(UInt(userWidth.W))

  val RREADY = Input(Bool())
  val RDATA  = Output(UInt(dataWidth.W))
  val RRESP  = Output(UInt(2.W))
  val RVALID = Output(Bool())
  val RLAST  = Output(Bool())
  val RID    = Output(UInt(idWidth.W))
  val RUSER  = Output(UInt(userWidth.W))

  def connect(intf: AXIFullSlaveIO): Unit = {
    require(intf.aWidth == addrWidth, "Address width must match")
    require(intf.dWidth == dataWidth, "Data width must match")
    require(intf.iWidth == idWidth, "ID width must match")
    require(intf.uWidth == userWidth, "User width must match")

    intf.aw.bits.addr   := this.AWADDR
    intf.aw.bits.prot   := this.AWPROT
    intf.aw.valid       := this.AWVALID
    this.AWREADY        := intf.aw.ready
    intf.aw.bits.id     := this.AWID
    intf.aw.bits.len    := this.AWLEN
    intf.aw.bits.size   := this.AWSIZE
    intf.aw.bits.burst  := this.AWBURST
    intf.aw.bits.lock   := this.AWLOCK
    intf.aw.bits.cache  := this.AWCACHE
    intf.aw.bits.qos    := this.AWQOS
    intf.aw.bits.region := this.AWREGION
    intf.aw.bits.user   := this.AWUSER

    intf.w.bits.data := this.WDATA
    intf.w.bits.strb := this.WSTRB
    intf.w.valid     := this.WVALID
    this.WREADY      := intf.w.ready
    intf.w.bits.last := this.WLAST
    intf.w.bits.id   := this.WID
    intf.w.bits.user := this.WUSER

    this.BRESP   := intf.b.bits.resp
    this.BID     := intf.b.bits.id
    this.BUSER   := intf.b.bits.user
    this.BVALID  := intf.b.valid
    intf.b.ready := this.BREADY

    intf.ar.bits.addr   := this.ARADDR
    intf.ar.bits.prot   := this.ARPROT
    intf.ar.valid       := this.ARVALID
    this.ARREADY        := intf.ar.ready
    intf.ar.bits.id     := this.ARID
    intf.ar.bits.len    := this.ARLEN
    intf.ar.bits.size   := this.ARSIZE
    intf.ar.bits.burst  := this.ARBURST
    intf.ar.bits.lock   := this.ARLOCK
    intf.ar.bits.cache  := this.ARCACHE
    intf.ar.bits.qos    := this.ARQOS
    intf.ar.bits.region := this.ARREGION
    intf.ar.bits.user   := this.ARUSER

    this.RDATA   := intf.r.bits.data
    this.RRESP   := intf.r.bits.resp
    this.RLAST   := intf.r.bits.last
    this.RID     := intf.r.bits.id
    this.RUSER   := intf.r.bits.user
    this.RVALID  := intf.r.valid
    intf.r.ready := this.RREADY
  }
}

class AXIFullSlave(
  addrWidth: Int,
  dataWidth: Int,
  idWidth: Int,
  userWidth: Int = 0,
  memSize: BigInt,
  baseAddr: BigInt = 0x0
) extends Module {
  override def desiredName: String =
    s"axifull_slave_ram_${memSize}x${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"
  // AXI Lite Slave Interface
  val maxDataValue = BigInt(1) << dataWidth
  val maxAddrValue = BigInt(1) << addrWidth

  val axi = Wire(new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))

  // Parameters
  val addr_lsb          = log2Ceil(dataWidth / 8)
  val opt_mem_addr_bits = log2Ceil(memSize)

  // Signals
  val axi_awready      = RegInit(false.B)
  val axi_awv_awr_flag = RegInit(false.B)
  val axi_awaddr       = RegInit(0.U(addrWidth.W))
  val axi_awburst      = RegInit(0.U(2.W))
  val axi_awlen        = RegInit(0.U(8.W))
  val axi_awlen_cntr   = RegInit(0.U(8.W))
  val axi_wready       = RegInit(false.B)
  val axi_bvalid       = RegInit(false.B)
  val axi_bresp        = RegInit(0.U(2.W))
  val axi_buser        = RegInit(0.U(userWidth.W))
  val axi_arready      = RegInit(false.B)
  val axi_araddr       = RegInit(0.U(addrWidth.W))
  val axi_arburst      = RegInit(0.U(2.W))
  val axi_arlen        = RegInit(0.U(8.W))
  val axi_arlen_cntr   = RegInit(0.U(8.W))
  val axi_arv_arr_flag = RegInit(false.B)
  val axi_rdata        = Wire(UInt(dataWidth.W))
  val axi_rvalid       = RegInit(false.B)
  val axi_rresp        = RegInit(0.U(2.W))
  val axi_rlast        = RegInit(false.B)
  val axi_ruser        = RegInit(0.U(userWidth.W))

  val aw_wrap_en   = Wire(Bool())
  val aw_wrap_size = Wire(UInt(addrWidth.W))
  val ar_wrap_en   = Wire(Bool())
  val ar_wrap_size = Wire(UInt(addrWidth.W))

  val aw_addr_valid  = Wire(Bool())
  val ar_addr_valid  = Wire(Bool())
  val aw_offset_addr = Wire(UInt(addrWidth.W))
  val ar_offset_addr = Wire(UInt(addrWidth.W))
  val addr_error     = RegInit(false.B)

  // I/O Connections
  axi.aw.ready    := axi_awready
  axi.w.ready     := axi_wready
  axi.b.bits.resp := axi_bresp
  axi.b.bits.user := axi_buser
  axi.b.valid     := axi_bvalid
  axi.b.bits.id   := axi.aw.bits.id
  axi.ar.ready    := axi_arready
  axi.r.bits.data := axi_rdata
  axi.r.bits.resp := axi_rresp
  axi.r.bits.last := axi_rlast
  axi.r.bits.user := axi_ruser
  axi.r.valid     := axi_rvalid
  axi.r.bits.id   := axi.ar.bits.id

  aw_wrap_size := (dataWidth / 8).U * axi_awlen
  ar_wrap_size := (dataWidth / 8).U * axi_arlen
  aw_wrap_en   := Mux((axi_awaddr & aw_wrap_size) === aw_wrap_size, true.B, false.B)
  ar_wrap_en   := Mux((axi_awaddr & ar_wrap_size) === ar_wrap_size, true.B, false.B)

  aw_offset_addr := axi_awaddr - baseAddr.U(addrWidth.W)
  ar_offset_addr := axi_araddr - baseAddr.U(addrWidth.W)
  aw_addr_valid  := (axi_awaddr >= baseAddr.U(
    addrWidth.W
  )) && (aw_offset_addr < ((1 << addr_lsb) * memSize.toInt).U(addrWidth.W))
  ar_addr_valid  := (axi_araddr >= baseAddr.U(
    addrWidth.W
  )) && (ar_offset_addr < ((1 << addr_lsb) * memSize.toInt).U(addrWidth.W))

  // Address Write Channel
  when(!axi_awready && axi.aw.valid && !axi_awv_awr_flag && !axi_arv_arr_flag) {
    axi_awready      := true.B
    axi_awv_awr_flag := true.B
    addr_error       := !aw_addr_valid
  }.elsewhen(axi.w.bits.last && axi_wready) {
    axi_awv_awr_flag := false.B
  }.otherwise {
    axi_awready := false.B
  }

  when(!axi_awready && axi.aw.valid && !axi_awv_awr_flag) {
    axi_awaddr     := axi.aw.bits.addr
    axi_awburst    := axi.aw.bits.burst
    axi_awlen      := axi.aw.bits.len
    axi_awlen_cntr := 0.U
  }.elsewhen((axi_awlen_cntr <= axi_awlen) && axi_wready && axi.w.valid) {
    axi_awlen_cntr := axi_awlen_cntr + 1.U
    when(axi_awburst === 0.U) {
      axi_awaddr := axi_awaddr
    }.elsewhen(axi_awburst === 1.U) {
      axi_awaddr := Cat(axi_awaddr(addrWidth - 1, addr_lsb) + 1.U, Fill(addr_lsb, 0.U))
    }.elsewhen(axi_awburst === 2.U) {
      axi_awaddr := Mux(
        aw_wrap_en,
        axi_awaddr - aw_wrap_size,
        Cat(axi_awaddr(addrWidth - 1, addr_lsb) + 1.U, Fill(addr_lsb, 0.U))
      )
    }.otherwise {
      axi_awaddr := axi_awaddr(addrWidth - 1, addr_lsb) + 1.U
    }
  }

  // Data Write Channel
  when(!axi_wready && axi.w.valid && axi_awv_awr_flag) {
    axi_wready := true.B
  }.elsewhen(axi.w.bits.last && axi_wready) {
    axi_wready := false.B
  }

  when(axi_awv_awr_flag && axi_wready && axi.w.valid && !axi_bvalid && axi.w.bits.last) {
    axi_bvalid := true.B
    axi_bresp  := Mux(addr_error, 2.U, 0.U) // 'SLVERR' if address error else 'OKAY'
  }.elsewhen(axi.b.ready && axi_bvalid) {
    axi_bvalid := false.B
  }

  // Address Read Channel
  when(!axi_arready && axi.ar.valid && !axi_awv_awr_flag && !axi_arv_arr_flag) {
    axi_arready      := true.B
    axi_arv_arr_flag := true.B
    addr_error       := !ar_addr_valid
  }.elsewhen(axi_rvalid && axi.r.ready && (axi_arlen_cntr === axi_arlen)) {
    axi_arv_arr_flag := false.B
  }.otherwise {
    axi_arready := false.B
  }

  when(!axi_arready && axi.ar.valid && !axi_arv_arr_flag) {
    axi_araddr     := axi.ar.bits.addr
    axi_arburst    := axi.ar.bits.burst
    axi_arlen      := axi.ar.bits.len
    axi_arlen_cntr := 0.U
    axi_rlast      := false.B
  }.elsewhen((axi_arlen_cntr <= axi_arlen) && axi_rvalid && axi.r.ready) {
    axi_arlen_cntr := axi_arlen_cntr + 1.U
    axi_rlast      := false.B

    when(axi_arburst === 0.U) {
      axi_araddr := axi_araddr
    }.elsewhen(axi_arburst === 1.U) {
      axi_araddr := Cat(axi_araddr(addrWidth - 1, addr_lsb) + 1.U, Fill(addr_lsb, 0.U))
    }.elsewhen(axi_arburst === 2.U) {
      axi_araddr := Mux(
        ar_wrap_en,
        axi_araddr - ar_wrap_size,
        Cat(axi_araddr(addrWidth - 1, addr_lsb) + 1.U, Fill(addr_lsb, 0.U))
      )
    }.otherwise {
      axi_araddr := axi.ar.bits.addr(addrWidth - 1, addr_lsb) + 1.U
    }
  }.elsewhen((axi_arlen_cntr === axi_arlen) && !axi_rlast && axi_arv_arr_flag) {
    axi_rlast := true.B
  }.elsewhen(axi.r.ready) {
    axi_rlast := false.B
  }

  when(axi_arv_arr_flag && !axi_rvalid) {
    axi_rvalid := true.B
    axi_rresp  := Mux(addr_error, 2.U, 0.U) // 'SLVERR' if address error else 'OKAY'
  }.elsewhen(axi_rvalid && axi.r.ready) {
    axi_rvalid := false.B
  }
}
