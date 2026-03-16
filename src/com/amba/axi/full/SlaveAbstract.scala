package vopts.com.amba

import chisel3._
import chisel3.util._

abstract class AXIFullSlave(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int, memSize: Int) extends Module {
  protected def getExtAXIName: String = "M_AXI"
  // AXI Interface
  val axi_ext                         = IO(new AXIFullSlaveExtIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val axi                             = Wire(new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))

  dontTouch(axi_ext)

  // Parameters
  protected val addr_lsb      = log2Ceil(dataWidth / 8)
  protected val opt_mem_width = log2Ceil(memSize)

  // Signals
  protected val axi_awready    = RegInit(false.B)
  protected val axi_awaddr     = RegInit(0.U(addrWidth.W))
  protected val axi_awburst    = RegInit(0.U(2.W))
  protected val axi_awlen      = RegInit(0.U(8.W))
  protected val axi_awid       = RegInit(0.U(idWidth.W))
  protected val axi_awlen_cntr = RegInit(0.U(8.W))

  protected val axi_wready = RegInit(false.B)
  protected val axi_bvalid = RegInit(false.B)
  protected val axi_bresp  = RegInit(0.U(2.W))
  protected val axi_buser  = RegInit(0.U(userWidth.W))
  protected val axi_bid    = RegInit(0.U(idWidth.W))

  protected val axi_arready    = RegInit(false.B)
  protected val axi_araddr     = RegInit(0.U(addrWidth.W))
  protected val axi_arburst    = RegInit(0.U(2.W))
  protected val axi_arlen      = RegInit(0.U(8.W))
  protected val axi_arid       = RegInit(0.U(idWidth.W))
  protected val axi_arlen_cntr = RegInit(0.U(8.W))

  protected val axi_rdata  = Wire(UInt(dataWidth.W))
  protected val axi_rvalid = RegInit(false.B)
  protected val axi_rresp  = RegInit(0.U(2.W))
  protected val axi_rlast  = RegInit(false.B)
  protected val axi_ruser  = RegInit(0.U(userWidth.W))
  protected val axi_rid    = RegInit(0.U(idWidth.W))

  // Wrap Size Signals
  protected val aw_wrap_size  = Wire(UInt(addrWidth.W))
  protected val ar_wrap_size  = Wire(UInt(addrWidth.W))
  protected val aw_addr_valid = Wire(Bool())
  protected val ar_addr_valid = Wire(Bool())

  // I/O Connections
  axi.aw.ready    := axi_awready
  axi.w.ready     := axi_wready
  axi.b.bits.resp := axi_bresp
  axi.b.bits.user := axi_buser
  axi.b.valid     := axi_bvalid
  axi.b.bits.id   := axi_bid

  axi.ar.ready    := axi_arready
  axi.r.bits.data := axi_rdata
  axi.r.bits.resp := axi_rresp
  axi.r.bits.last := axi_rlast
  axi.r.bits.user := axi_ruser
  axi.r.valid     := axi_rvalid
  axi.r.bits.id   := axi_rid

  aw_wrap_size := (dataWidth / 8).U * (axi_awlen + 1.U)
  ar_wrap_size := (dataWidth / 8).U * (axi_arlen + 1.U)

  protected def nextIncr(addr: UInt): UInt =
    Cat(addr(addrWidth - 1, addr_lsb) + 1.U, Fill(addr_lsb, 0.U))

  protected def nextWrap(addr: UInt, wrap_size: UInt): UInt = {
    val wrap_boundary = wrap_size >> addr_lsb
    val addr_offset   = addr(opt_mem_width + addr_lsb - 1, addr_lsb)
    val need_wrap     = (addr_offset & (wrap_boundary - 1.U)) === (wrap_boundary - 1.U)
    Mux(need_wrap, addr - Cat(wrap_boundary - 1.U, Fill(addr_lsb, 0.U)), nextIncr(addr))
  }

  protected def nextAddr(addr: UInt, burst: UInt, wrap_size: UInt): UInt =
    MuxCase(
      addr,
      Seq(
        (burst === AXIBurstType.FIXED) -> addr,
        (burst === AXIBurstType.INCR)  -> nextIncr(addr),
        (burst === AXIBurstType.WRAP)  -> nextWrap(addr, wrap_size)
      )
    )

  // Handshake Signals
  protected val axi_will_awrite = axi.aw.valid && !axi_awready
  protected val axi_on_awrite   = axi.aw.valid && axi_awready
  protected val axi_will_write  = axi.w.valid && !axi_wready && axi_awlen_cntr <= axi_awlen
  protected val axi_on_write    = axi.w.valid && axi_wready && !axi.w.bits.last
  protected val axi_last_write  = axi.w.valid && axi_wready && axi.w.bits.last
  protected val axi_will_bresp  = axi_wready && axi.w.valid && axi.w.bits.last && !axi_bvalid
  protected val axi_on_bresp    = axi.b.ready && axi_bvalid
  protected val axi_will_arread = axi.ar.valid && !axi_arready
  protected val axi_on_arread   = axi.ar.valid && axi_arready
  protected val axi_will_read   = !axi_rvalid && axi.r.ready
  protected val axi_on_read     = axi_rvalid && axi.r.ready && !axi_rlast
  protected val axi_last_read   = axi_rvalid && axi.r.ready && axi_rlast

  // AW
  when(axi_will_awrite) {
    axi_awready    := true.B
    axi_awaddr     := axi.aw.bits.addr
    axi_awburst    := axi.aw.bits.burst
    axi_awlen      := axi.aw.bits.len
    axi_awid       := axi.aw.bits.id
    axi_awlen_cntr := 0.U
  }.elsewhen(axi_on_awrite) {
    axi_awready := false.B
  }

  // W
  when(axi_will_write) {
    axi_wready := true.B
  }.elsewhen(axi_on_write) {
    axi_awlen_cntr := axi_awlen_cntr + 1.U
    axi_awaddr     := nextAddr(axi_awaddr, axi_awburst, aw_wrap_size)
  }

  // B
  when(axi_will_bresp) {
    axi_wready := false.B
    axi_bvalid := true.B
    axi_bid    := axi_awid
  }.elsewhen(axi_on_bresp) {
    axi_bvalid := false.B
  }

  // AR
  when(axi_will_arread) {
    axi_arready    := true.B
    axi_araddr     := axi.ar.bits.addr
    axi_arburst    := axi.ar.bits.burst
    axi_arlen      := axi.ar.bits.len
    axi_arid       := axi.ar.bits.id
    axi_arlen_cntr := 0.U
  }.elsewhen(axi_on_arread) {
    axi_arready := false.B
    axi_rvalid  := true.B
    axi_rid     := axi_arid
    // Single beat read
    axi_rlast   := axi_arlen === 0.U
  }

  // R
  when(axi_on_read) {
    axi_arlen_cntr := axi_arlen_cntr + 1.U
    axi_araddr     := nextAddr(axi_araddr, axi_arburst, ar_wrap_size)
    axi_rlast      := axi_arlen_cntr + 1.U === axi_arlen
  }.elsewhen(axi_last_read) {
    axi_rvalid := false.B
    axi_rlast  := false.B
  }

  axi_ext.connect(axi)
}
