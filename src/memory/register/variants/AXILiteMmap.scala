package vopts.mem.register

import vopts.com.amba._
import vopts.utils._
import chisel3._

class AXILiteSlaveMMapRegs(addrWidth: Int, dataWidth: Int, mmap: Seq[Register]) extends AXILiteSlave(addrWidth, dataWidth) {
  override def desiredName: String =
    s"axilite_slave_mmap_${addrWidth}x${dataWidth}_r${mmap.length}"

  val mmap_regs = Module(new MMapRegisters(addrWidth, dataWidth, mmap))

  // I/O Connections
  mmap_regs.io.write_en   := axi_last_write
  mmap_regs.io.write_addr := axi_awaddr
  mmap_regs.io.write_data := axi.w.bits.data
  mmap_regs.io.write_strb := axi.w.bits.strb

  mmap_regs.io.read_en   := axi_will_read
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
    Register("slv_reg3", 0x8000c000L, 0x0L)
  )
  VerilogEmitter.parse(
    new AXILiteSlaveMMapRegs(32, 32, mmap),
    "axilite_slave_mmap.sv",
    info = true
  )
}
