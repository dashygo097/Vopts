package mem.register

import com.axi._
import chisel3._
import chisel3.util._
import scala.math.BigInt

class AXIFullSlaveMMap(addrWidth: Int, dataWidth: Int, idWidth: Int, mmap: Seq[RegisterFactory], userWidth: Int = 0) extends Module {
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

  val ext_axi = IO(new AXIFullSlaveExternalIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val axi = Wire(new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))

  // Parameters
  val addr_lsb = log2Ceil(dataWidth / 8)
  val opt_mem_addr_bits = log2Ceil(mmap.length)

  // Signals
  val axi_awready = RegInit(false.B)
  val axi_awv_awr_flag = RegInit(false.B)
  val axi_awaddr = RegInit(0.U(addrWidth.W))
  val axi_awburst = RegInit(0.U(2.W))
  val axi_awlen = RegInit(0.U(8.W))
  val axi_awlen_cntr = RegInit(0.U(8.W))
  val aw_wrap_en = Wire(Bool())
  val aw_wrap_size = Wire(UInt(addrWidth.W))
  val axi_wready = RegInit(false.B)
  val axi_arv_arr_flag = RegInit(false.B)

  // I/O Connections

  // Address Write Channel

  when (!axi_awready && axi.aw.valid && !axi_awv_awr_flag && !axi_arv_arr_flag) {
    axi_awready := true.B
    axi_awv_awr_flag := true.B
  } .elsewhen (axi.w.bits.last && axi_wready) {
    axi_awv_awr_flag := false.B
  } .otherwise {
    axi_awready := false.B
  }

  when (!axi_awready && axi.aw.valid && !axi_awv_awr_flag) {
    axi_awaddr := axi.aw.bits.addr
    axi_awburst := axi.aw.bits.burst
    axi_awlen := axi.aw.bits.len
    axi_awlen_cntr := 0.U
  } .elsewhen ((axi_awlen_cntr <= axi_awlen) && axi_wready && axi.w.valid) {
    axi_awlen_cntr := axi_awlen_cntr + 1.U
    when (axi_awburst === 0.U) {
      axi_awaddr := axi_awaddr
    } .elsewhen (axi_awburst === 1.U) {
      axi_awaddr := Cat(axi_awaddr(addrWidth - 1, addr_lsb) + 1.U, Fill(addr_lsb, 0.U))
    } .elsewhen (axi_awburst === 2.U) {
      axi_awaddr := Mux(aw_wrap_en, axi_awaddr - aw_wrap_size, Cat(axi_awaddr(addrWidth - 1, addr_lsb) + 1.U, Fill(addr_lsb, 0.U)))
    } .otherwise {
      axi_awaddr := axi_awaddr(addrWidth - 1, addr_lsb) + 1.U
    }
  }

  // Data Write Channel
  when (!axi_wready && axi.w.valid && axi_awv_awr_flag) {
    axi_wready := true.B
  } .elsewhen (axi.w.bits.last && axi_wready) {
    axi_wready := false.B
  }
}
