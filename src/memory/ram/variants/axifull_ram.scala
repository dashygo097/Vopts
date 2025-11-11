package mem.ram

import com.amba._
import utils._
import chisel3._
import chisel3.util._

class AXIFullSlaveRAM(
  addrWidth: Int,
  dataWidth: Int,
  idWidth: Int,
  userWidth: Int,
  memSize: Int,
  baseAddr: BigInt
) extends Module {
  override def desiredName: String =
    s"axifull_slave_ram_${addrWidth}x${dataWidth}_i${idWidth}_u${userWidth}_s${memSize}_b$baseAddr"

  // AXI Interface
  val ext_axi = IO(new AXIFullSlaveExternalIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val axi     = Wire(new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))

  val mmap_region = Module(new MMapRegion(addrWidth, dataWidth, memSize, baseAddr, false))

  // Parameters
  val addr_lsb = log2Ceil(dataWidth / 8)

  // Signals
  val axi_awready    = RegInit(false.B)
  val axi_awaddr     = RegInit(0.U(addrWidth.W))
  val axi_awburst    = RegInit(0.U(2.W))
  val axi_awlen      = RegInit(0.U(8.W))
  val axi_awid       = RegInit(0.U(idWidth.W))
  val axi_awlen_cntr = RegInit(0.U(8.W))

  val axi_wready = RegInit(false.B)
  val axi_bvalid = RegInit(false.B)
  val axi_bresp  = RegInit(0.U(2.W))
  val axi_buser  = RegInit(0.U(userWidth.W))
  val axi_bid    = RegInit(0.U(idWidth.W))

  val axi_arready    = RegInit(false.B)
  val axi_araddr     = RegInit(0.U(addrWidth.W))
  val axi_arburst    = RegInit(0.U(2.W))
  val axi_arlen      = RegInit(0.U(8.W))
  val axi_arid       = RegInit(0.U(idWidth.W))
  val axi_arlen_cntr = RegInit(0.U(8.W))

  val axi_rdata  = Wire(UInt(dataWidth.W))
  val axi_rvalid = RegInit(false.B)
  val axi_rresp  = RegInit(0.U(2.W))
  val axi_rlast  = RegInit(false.B)
  val axi_ruser  = RegInit(0.U(userWidth.W))
  val axi_rid    = RegInit(0.U(idWidth.W))

  // Wrap Size Signals
  val aw_wrap_size  = Wire(UInt(addrWidth.W))
  val ar_wrap_size  = Wire(UInt(addrWidth.W))
  val aw_addr_valid = Wire(Bool())
  val ar_addr_valid = Wire(Bool())

  // Handshake Signals

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

  mmap_region.io.write_en   := axi_wready && axi.w.valid
  mmap_region.io.write_addr := axi_awaddr
  mmap_region.io.write_data := axi.w.bits.data
  mmap_region.io.write_strb := axi.w.bits.strb
  aw_addr_valid             := mmap_region.io.write_resp

  mmap_region.io.read_en   := axi_arready || axi_rvalid
  mmap_region.io.read_addr := axi_araddr
  ar_addr_valid            := mmap_region.io.read_resp
  axi_rdata                := Mux(axi_rvalid && ar_addr_valid, mmap_region.io.read_data, 0.U(dataWidth.W))

  def nextIncr(addr: UInt): UInt =
    Cat(addr(addrWidth - 1, addr_lsb) + 1.U, Fill(addr_lsb, 0.U))

  def nextWrap(addr: UInt, wrap_size: UInt): UInt = {
    val wrap_boundary = wrap_size >> addr_lsb
    val addr_offset   = addr(log2Ceil(memSize * (dataWidth / 8)) - 1, addr_lsb)
    val need_wrap     = (addr_offset & (wrap_boundary - 1.U)) === (wrap_boundary - 1.U)
    Mux(need_wrap, addr - Cat(wrap_boundary - 1.U, Fill(addr_lsb, 0.U)), nextIncr(addr))
  }

  def nextAddr(addr: UInt, burst: UInt, wrap_size: UInt): UInt =
    MuxCase(
      addr,
      Seq(
        (burst === AXIBurstType.FIXED) -> addr,
        (burst === AXIBurstType.INCR)  -> nextIncr(addr),
        (burst === AXIBurstType.WRAP)  -> nextWrap(addr, wrap_size)
      )
    )

  // AW
  when(axi.aw.valid && !axi_awready) {
    axi_awready    := true.B
    axi_awaddr     := axi.aw.bits.addr
    axi_awburst    := axi.aw.bits.burst
    axi_awlen      := axi.aw.bits.len
    axi_awid       := axi.aw.bits.id
    axi_awlen_cntr := 0.U
  }.elsewhen(axi_awready) {
    axi_awready := false.B
  }

  // W & B
  when(axi.w.valid && !axi_wready && axi_awlen_cntr <= axi_awlen) {
    axi_wready := true.B
  }

  when(axi_wready && axi.w.valid) {
    when(!axi.w.bits.last) {
      axi_awlen_cntr := axi_awlen_cntr + 1.U
      axi_awaddr     := nextAddr(axi_awaddr, axi_awburst, aw_wrap_size)
    }
    when(axi.w.bits.last && !axi_bvalid) {
      axi_wready := false.B
      axi_bvalid := true.B
      axi_bresp  := Mux(aw_addr_valid, 0.U, 2.U)
      axi_bid    := axi_awid
    }
  }

  when(axi.b.ready && axi_bvalid) {
    axi_bvalid := false.B
  }

  // AR
  when(axi.ar.valid && !axi_arready) {
    axi_arready    := true.B
    axi_araddr     := axi.ar.bits.addr
    axi_arburst    := axi.ar.bits.burst
    axi_arlen      := axi.ar.bits.len
    axi_arid       := axi.ar.bits.id
    axi_arlen_cntr := 0.U
  }.elsewhen(axi_arready) {
    axi_arready := false.B
    axi_rvalid  := true.B
    axi_rid    := axi_arid
    axi_rlast  := axi_arlen === 0.U
  }

  // R
  when(axi_rvalid && axi.r.ready) {
    when(!axi_rlast) {
      axi_arlen_cntr := axi_arlen_cntr + 1.U
      axi_araddr     := nextAddr(axi_araddr, axi_arburst, ar_wrap_size)
      axi_rresp := Mux(ar_addr_valid, 0.U, 2.U)
      axi_rlast      := axi_arlen_cntr + 1.U === axi_arlen
    }.otherwise {
      axi_rvalid := false.B
      axi_rlast := false.B
    }
  }

  ext_axi.connect(axi)
}

object TestAXIFullSlaveRAM extends App {
  VerilogEmitter.parse(
    new AXIFullSlaveRAM(32, 32, 4, 1, 8, 0x80000000L),
    "axifull_slave_ram.sv",
    info = true
  )
}
