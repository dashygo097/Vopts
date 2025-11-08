package mem.ram

import com.amba._
import chisel3._

class AXILiteSlaveRAM(
  addrWidth: Int,
  dataWidth: Int,
  memSize: Int,
  baseAddr: BigInt
) extends AXILiteSlave(addrWidth, dataWidth) {
  override def desiredName: String =
    s"axilite_slave_ram_${addrWidth}x${dataWidth}_s${memSize}_b$baseAddr"

  val mmap_region = Module(new MMapRegion(addrWidth, dataWidth, memSize, baseAddr, false))

  val aw_addr_valid = Wire(Bool())
  val ar_addr_valid = Wire(Bool())

  // Memory connections
  mmap_region.io.write_en   := axi_on_awrite 
  mmap_region.io.write_addr := axi_awaddr
  mmap_region.io.write_data := axi.w.bits.data
  mmap_region.io.write_strb := axi.w.bits.strb
  aw_addr_valid             := mmap_region.io.write_resp

  mmap_region.io.read_en   := axi_on_aread
  mmap_region.io.read_addr := axi_araddr
  ar_addr_valid            := mmap_region.io.read_resp
  axi_rdata                := Mux(axi_rvalid && ar_addr_valid, mmap_region.io.read_data, 0.U(dataWidth.W))

  // AW

  // W

  // B
  when(axi_will_bresp) {
    axi_bresp := Mux(aw_addr_valid, 0.U, 2.U) // 'SLVERR' if address error else 'OKAY'
  }

  // AR

  // R
  when(axi_will_read) {
    axi_rresp := Mux(ar_addr_valid, 0.U, 2.U) // 'SLVERR' if address error else 'OKAY'
  }
}
