package mem.register

import com.axi._
import chisel3._
import chisel3.util._

class AXILiteSlaveMMapRegs(addrWidth: Int, dataWidth: Int, mmap: Seq[Register]) extends Module {
  override def desiredName: String =
    s"axilite_slave_mmap_${addrWidth}x${dataWidth}_r${mmap.length}"
  // AXI Lite Slave Interface
  val maxDataValue                 = BigInt(1) << dataWidth
  val maxAddrValue                 = BigInt(1) << addrWidth
  for (reg <- mmap) {
    require(
      reg.addr >= 0 && reg.addr < maxAddrValue,
      s"Register address ${reg.addr} out of range for addrWidth $addrWidth"
    )
    require(
      reg.initValue >= 0 && reg.initValue < maxDataValue,
      s"Register initial value ${reg.initValue} out of range for dataWidth $dataWidth"
    )
  }

  val ext_axi = IO(new AXILiteExternalIO(addrWidth, dataWidth)).suggestName("S_AXI")
  val axi     = Wire(new AXILiteSlaveIO(addrWidth, dataWidth))

  val mmap_regs = Module(new MMapRegisters(addrWidth, dataWidth, mmap))

  // Parameters
  val addr_lsb          = log2Ceil(dataWidth / 8)
  val addr_bits_needed  = log2Ceil(mmap.map(_.addr).max + 1)
  val opt_mem_addr_bits = math.min(addr_bits_needed, addrWidth - addr_lsb)

  // Signals
  val aw_en       = RegInit(true.B)
  val axi_awready = RegInit(false.B)
  val axi_awaddr  = RegInit(0.U(addrWidth.W))
  val axi_wready  = RegInit(false.B)
  val axi_bvalid  = RegInit(false.B)
  val axi_bresp   = RegInit(0.U(2.W))
  val axi_arready = RegInit(false.B)
  val axi_araddr  = RegInit(0.U(addrWidth.W))
  val axi_rdata   = RegInit(0.U(dataWidth.W))
  val axi_rvalid  = RegInit(false.B)
  val axi_rresp   = RegInit(0.U(2.W))

  val slv_reg_we = Wire(Bool())
  val slv_reg_re = Wire(Bool())

  // I/O Connections
  axi.aw.ready    := axi_awready
  axi.w.ready     := axi_wready
  axi.b.bits.resp := axi_bresp
  axi.b.valid     := axi_bvalid
  axi.ar.ready    := axi_arready
  axi.r.bits.data := axi_rdata
  axi.r.bits.resp := axi_rresp
  axi.r.valid     := axi_rvalid

  // MMap Connect to AXI interface
  slv_reg_we              := axi_wready && axi.w.valid && axi_awready && axi.aw.valid
  mmap_regs.io.write_en   := slv_reg_we
  mmap_regs.io.write_addr := axi_awaddr
  mmap_regs.io.write_data := axi.w.bits.data
  mmap_regs.io.write_strb := axi.w.bits.strb

  slv_reg_re             := axi_arready && axi.ar.valid && !axi_rvalid
  mmap_regs.io.read_en   := slv_reg_re
  mmap_regs.io.read_addr := axi_araddr
  axi_rdata            := mmap_regs.io.read_data

  // Address Write Channel
  when(!axi_awready && axi.aw.valid && axi.w.valid && aw_en) {
    // Accepting
    axi_awaddr  := axi.aw.bits.addr
    axi_awready := true.B
    aw_en       := false.B
  }.elsewhen(axi.b.ready && axi_bvalid) {
    axi_awready := false.B
    aw_en       := true.B
  }.otherwise {
    axi_awready := false.B
  }

  // Data Write Channel
  when(!axi_wready && axi.w.valid && axi.aw.valid && aw_en) {
    axi_wready := true.B
  }.otherwise {
    axi_wready := false.B
  }

  // Write Response Channel
  when(axi_awready && axi.aw.valid && !axi_bvalid && axi_wready && axi.w.valid) {
    axi_bvalid := true.B
    axi_bresp  := Mux(mmap_regs.io.read_resp, 0.U, 2.U) // 'SLVERR' if address error else 'OKAY'
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
  when(axi_arready && axi.ar.valid && !axi_rvalid) {
    axi_rvalid := true.B
    axi_rresp  := Mux(mmap_regs.io.read_resp, 0.U, 2.U) // 'SLVERR' if address error else 'OKAY'
  }.otherwise {
    when(axi_rvalid && axi.r.ready) {
      axi_rvalid := false.B
    }
  }

  ext_axi.connect(axi)
}
