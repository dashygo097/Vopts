package mem.ram

import com.amba._
import chisel3._
import chisel3.util._

class AXILiteSlaveRAM(
  addrWidth: Int,
  dataWidth: Int,
  memSize: Int,
  baseAddr: BigInt
) extends Module {
  override def desiredName: String =
    s"axilite_slave_ram_${addrWidth}x${dataWidth}_s${memSize}_b$baseAddr"

  // AXI Lite Slave Interface
  val ext_axi = IO(new AXILiteSlaveExternalIO(addrWidth, dataWidth)).suggestName("S_AXI")
  val axi     = Wire(new AXILiteSlaveIO(addrWidth, dataWidth))

  val mmap_region = Module(new MMapRegion(addrWidth, dataWidth, memSize, baseAddr))

  // Parameters
  val addr_lsb = log2Ceil(dataWidth / 8)

  // Signals
  val axi_awready = RegInit(false.B)
  val axi_awaddr  = RegInit(0.U(addrWidth.W))
  val axi_wready  = RegInit(false.B)
  val axi_bvalid  = RegInit(false.B)
  val axi_bresp   = RegInit(0.U(2.W))
  val axi_arready = RegInit(false.B)
  val axi_araddr  = RegInit(0.U(addrWidth.W))
  val axi_rdata   = Wire(UInt(dataWidth.W))
  val axi_rvalid  = RegInit(false.B)
  val axi_rresp   = RegInit(0.U(2.W))

  val aw_addr_valid = Wire(Bool())
  val ar_addr_valid = Wire(Bool())

  // I/O Connections
  axi.aw.ready    := axi_awready
  axi.w.ready     := axi_wready
  axi.b.bits.resp := axi_bresp
  axi.b.valid     := axi_bvalid
  axi.ar.ready    := axi_arready
  axi.r.bits.data := axi_rdata
  axi.r.bits.resp := axi_rresp
  axi.r.valid     := axi_rvalid

  // Memory connections
  mmap_region.io.write_en   := axi_wready && axi.w.valid
  mmap_region.io.write_addr := axi_awaddr
  mmap_region.io.write_data := axi.w.bits.data
  mmap_region.io.write_strb := axi.w.bits.strb
  aw_addr_valid             := mmap_region.io.write_resp

  mmap_region.io.read_en   := axi_arready && axi.ar.valid
  mmap_region.io.read_addr := axi_araddr
  ar_addr_valid            := mmap_region.io.read_resp
  axi_rdata                := Mux(axi_rvalid && ar_addr_valid, mmap_region.io.read_data, 0.U(dataWidth.W))

  // Address Write Channel
  when(!axi_awready && axi.aw.valid) {
    axi_awaddr  := axi.aw.bits.addr
    axi_awready := true.B
  }.otherwise {
    axi_awready := false.B
  }

  // Data Write Channel
  when(!axi_wready && axi_awready && axi.aw.valid) {
    axi_wready := true.B
  }.otherwise {
    when(axi_wready && axi.w.valid) {
      axi_wready := false.B
    }
  }

  // Write Response Channel
  when(!axi_bvalid && axi_wready && axi.w.valid) {
    axi_bvalid := true.B
    axi_bresp  := Mux(aw_addr_valid, 0.U, 2.U) // 'SLVERR' if address error else 'OKAY'
  }.otherwise {
    when(axi.b.ready && axi_bvalid) {
      axi_bvalid := false.B
    }
  }

  // Address Read Channel
  when(!axi_arready && axi.ar.valid) {
    axi_araddr  := axi.ar.bits.addr
    axi_arready := true.B
  }.otherwise {
    axi_arready := false.B
  }

  // Data Read Channel
  when(!axi_rvalid && axi_arready && axi.ar.valid) {
    axi_rvalid := true.B
    axi_rresp  := Mux(ar_addr_valid, 0.U, 2.U) // 'SLVERR' if address error else 'OKAY'
  }.otherwise {
    when(axi_rvalid && axi.r.ready) {
      axi_rvalid := false.B
    }
  }

  ext_axi.connect(axi)
}
