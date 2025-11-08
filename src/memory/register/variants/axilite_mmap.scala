package mem.register

import com.amba._
import utils._
import chisel3._

class AXILiteSlaveMMapRegs(addrWidth: Int, dataWidth: Int, mmap: Seq[Register]) extends AXILiteSlave(addrWidth, dataWidth) {
  override def desiredName: String =
    s"axilite_slave_mmap_${addrWidth}x${dataWidth}_r${mmap.length}"

  val mmap_regs = Module(new MMapRegisters(addrWidth, dataWidth, mmap))

  // Signals
  val slv_reg_we = Wire(Bool())
  val slv_reg_re = Wire(Bool())

  // I/O Connections
  slv_reg_we              := axi_on_awrite 
  mmap_regs.io.write_en   := slv_reg_we
  mmap_regs.io.write_addr := axi_awaddr
  mmap_regs.io.write_data := axi.w.bits.data
  mmap_regs.io.write_strb := axi.w.bits.strb

  slv_reg_re             := axi_on_aread
  mmap_regs.io.read_en   := slv_reg_re
  mmap_regs.io.read_addr := axi_araddr
  axi_rdata              := mmap_regs.io.read_data

  // AW

  // W

  // B
  when(axi_will_bresp) {
    axi_bresp := Mux(mmap_regs.io.write_resp, 0.U, 2.U) // 'SLVERR' if address error else 'OKAY'
  }

  // AR

  // R
  when(axi_will_read) {
    axi_rresp := Mux(mmap_regs.io.read_resp, 0.U, 2.U) // 'SLVERR' if address error else 'OKAY'
  }
}

object TestAXILiteSlaveMMap extends App {
  val mmap = Seq(
    Register("slv_reg0", 0x80000000L, 0x0L),
    Register("slv_reg1", 0x80004000L, 0x0L),
    Register("slv_reg2", 0x80008000L, 0x0L),
    Register("slv_reg3", 0x8000C000L, 0x0L)
  )
  VerilogEmitter.parse(
    new AXILiteSlaveMMapRegs(32, 32, mmap),
    "axilite_slave_mmap.sv",
    info = true
  )
}
