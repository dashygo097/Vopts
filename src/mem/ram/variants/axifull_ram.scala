package mem.ram

import com.axi._
import chisel3._
import chisel3.util._

class AXIFullSlaveRAM(
  addrWidth: Int,
  dataWidth: Int,
  idWidth: Int,
  memSize: BigInt,
  baseAddr: BigInt = 0x0,
  userWidth: Int = 0
) extends Module {
  override def desiredName: String =
    s"axifull_slave_ram_${addrWidth}x${dataWidth}_i${idWidth}_u${userWidth}_s${memSize}_b$baseAddr"
  // AXI Full Slave Interface
  val ext_axi                      =
    IO(new AXIFullSlaveExternalIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val axi                          = Wire(new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))

  val mmap_region = Module(new MMapRegion(addrWidth, dataWidth, memSize, baseAddr))

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

  val aw_addr_valid = Wire(Bool())
  val ar_addr_valid = Wire(Bool())

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

  mmap_region.io.write_en   := axi_wready && axi.w.valid
  mmap_region.io.write_addr := axi_awaddr
  mmap_region.io.write_data := axi.w.bits.data
  mmap_region.io.write_strb := axi.w.bits.strb
  aw_addr_valid             := mmap_region.io.write_resp

  mmap_region.io.read_en   := axi_arv_arr_flag
  mmap_region.io.read_addr := axi_araddr
  ar_addr_valid            := mmap_region.io.read_resp
  axi_rdata                := Mux(axi_rvalid && ar_addr_valid, mmap_region.io.read_data, 0.U(dataWidth.W))

  // Address Write Channel
  when(!axi_awready && axi.aw.valid && !axi_awv_awr_flag && !axi_arv_arr_flag) {
    axi_awready      := true.B
    axi_awv_awr_flag := true.B
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
    axi_bresp  := Mux(aw_addr_valid, 0.U, 2.U) // 'SLVERR' if address error else 'OKAY'
  }.elsewhen(axi.b.ready && axi_bvalid) {
    axi_bvalid := false.B
  }

  // Address Read Channel
  when(!axi_arready && axi.ar.valid && !axi_awv_awr_flag && !axi_arv_arr_flag) {
    axi_arready      := true.B
    axi_arv_arr_flag := true.B
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
    axi_rresp  := Mux(ar_addr_valid, 0.U, 2.U) // 'SLVERR' if address error else 'OKAY'
  }.elsewhen(axi_rvalid && axi.r.ready) {
    axi_rvalid := false.B
  }

  ext_axi.connect(axi)
}
