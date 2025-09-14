package mem.register

import com.axi._
import chisel3._
import chisel3.util._
import scala.math.BigInt

class AXISlaveMMap(dataWidth: Int, addrWidth: Int, mmap: Seq[RegisterFactory]) extends Module {
  override def desiredName: String = s"axi_slave_mmap_${addrWidth}x${dataWidth}_r${mmap.length}"
  // AXI Lite Slave Interface
  val maxDataValue = BigInt(1) << dataWidth
  val maxAddrValue = BigInt(1) << addrWidth
  for (reg <- mmap) {
    require(reg.addr >= 0 && reg.addr < maxAddrValue, 
            s"Register address ${reg.addr} out of range for addrWidth $addrWidth")
    require(reg.initValue >= 0 && reg.initValue < maxDataValue, 
            s"Register initial value ${reg.initValue} out of range for dataWidth $dataWidth")
  }

  val ext_axi = IO(new AXILiteExternalIO(dataWidth, addrWidth)).suggestName("S_AXI")
  val axi = Wire(new AXILiteSlaveIO(dataWidth, addrWidth))
  val addr_lsb = log2Ceil(dataWidth / 8)
  val opt_mem_addr_bits = log2Ceil(mmap.length)

  val aw_en = RegInit(true.B)
  val axi_awready = RegInit(false.B)
  val axi_awaddr = RegInit(0.U(addrWidth.W))
  val axi_wready = RegInit(false.B)
  val axi_bvalid = RegInit(false.B)
  val axi_bresp = RegInit(0.U(2.W))
  val axi_arready = RegInit(false.B)
  val axi_araddr = RegInit(0.U(addrWidth.W))
  val axi_rdata = RegInit(0.U(dataWidth.W))
  val axi_rvalid = RegInit(false.B)
  val axi_rresp = RegInit(0.U(2.W))

  val slv_reg_we = Wire(Bool())
  val slv_reg_re = Wire(Bool())

  val addr_map = mmap.map { reg => reg.addr }
  val slv_regs = mmap.map { reg => RegInit(reg.initValue.U(dataWidth.W)).suggestName(reg.name) }

  val byteBanks = Wire(Vec((dataWidth / 8), UInt(8.W)))

  // I/O Connections
  axi.aw.ready := axi_awready
  axi.w.ready := axi_wready
  axi.b.bits.resp := axi_bresp
  axi.b.valid := axi_bvalid
  axi.ar.ready := axi_arready
  axi.r.bits.data := axi_rdata
  axi.r.bits.resp := axi_rresp
  axi.r.valid := axi_rvalid

  slv_reg_we := axi_wready && axi.w.valid && axi_awready && axi.aw.valid
  slv_reg_re := axi_arready && axi.ar.valid && !axi_rvalid

  for (i <- 0 until (dataWidth / 8)) {
    byteBanks(i) := axi.w.bits.data(8 * (i + 1) - 1, 8 * i)
  }

  // Address Write Channel
  when (!axi_awready && axi.aw.valid && axi.w.valid && aw_en) {
    // Accepting
    axi_awaddr := axi.aw.bits.addr
    axi_awready := true.B
    aw_en := false.B
  } .elsewhen(axi.b.ready && axi_bvalid) {
    axi_awready := false.B
    aw_en := true.B
  } .otherwise {
    axi_awready := false.B
  }

  // Data Write Channel
  when (!axi_wready && axi.w.valid && axi.aw.valid && aw_en) {
    axi_wready := true.B
  } .otherwise {
    axi_wready := false.B
  }

  // Register Memory Mapping Write Logic
  when (slv_reg_we) {
    val addr_reg = axi_awaddr(addr_lsb + opt_mem_addr_bits - 1, addr_lsb)
    for (i <- 0 until mmap.length) {
      when ((addr_map(i) >> addr_lsb).U(opt_mem_addr_bits.W) === addr_reg) {
        slv_regs(i) := Cat((0 until (dataWidth / 8)).map { j =>
          Mux(axi.w.bits.strb(j), byteBanks(j), slv_regs(i)(8 * (j + 1) - 1, 8 * j))
        }.reverse)
      }
    }
  }

  // Write Response Channel
  when (axi_awready && axi.aw.valid && !axi_bvalid && axi_wready && axi.w.valid) {
    axi_bvalid := true.B
    axi_bresp := 0.U // OKAY response
  } .otherwise {
    when (axi.b.ready && axi_bvalid) {
      axi_bvalid := false.B
    }
  }

  // Address Read Channel
  when (!axi_arready && axi.ar.valid) {
    axi_araddr := axi.ar.bits.addr
    axi_arready := true.B
  } .otherwise {
    axi_arready := false.B
  }

  // Data Read Channel
  when (axi_arready && axi.ar.valid && !axi_rvalid) {
    axi_rvalid := true.B
    axi_rresp := 0.U // OKAY response
  } .otherwise {
    when (axi_rvalid && axi.r.ready) {
      axi_rvalid := false.B
    }
  }

  // Register Memory Mapping Read Logic
  when (slv_reg_re) {
    val addr_reg = axi_araddr(addr_lsb + opt_mem_addr_bits - 1, addr_lsb)
    axi_rdata := MuxCase(0.U, mmap.zipWithIndex.map { case (reg, i) =>
      ((addr_map(i) >> addr_lsb).U === addr_reg) -> slv_regs(i)
    })
  }

  ext_axi.connect(axi)
}
