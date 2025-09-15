package mem.ram

import com.axi._
import chisel3._
import chisel3.util._
import scala.math.BigInt

class AXIFullSlaveBlockRAM(addrWidth: Int, dataWidth: Int, idWidth: Int,  userNumMem: Int, optMemAddrBits: Int = 0, userWidth: Int = 0) extends Module {
  override def desiredName: String = s"axi_slave_mmap_${addrWidth}x${dataWidth}"
  // AXI Lite Slave Interface
  val maxDataValue = BigInt(1) << dataWidth
  val maxAddrValue = BigInt(1) << addrWidth

  val ext_axi = IO(new AXIFullSlaveExternalIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val axi = Wire(new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))

  // Parameters
  val addr_lsb = log2Ceil(dataWidth / 8)
  val opt_mem_addr_bits = if (optMemAddrBits < addrWidth) optMemAddrBits else addrWidth

  // Signals
  val axi_awready = RegInit(false.B)
  val axi_awv_awr_flag = RegInit(false.B)
  val axi_awaddr = RegInit(0.U(addrWidth.W))
  val axi_awburst = RegInit(0.U(2.W))
  val axi_awlen = RegInit(0.U(8.W))
  val axi_awlen_cntr = RegInit(0.U(8.W))

  val axi_wready = RegInit(false.B)
  val axi_bvalid = RegInit(false.B)
  val axi_bresp = RegInit(0.U(2.W))
  val axi_buser = RegInit(0.U(userWidth.W))
  val axi_arready = RegInit(false.B)
  val axi_araddr = RegInit(0.U(addrWidth.W))
  val axi_arburst = RegInit(0.U(2.W))
  val axi_arlen = RegInit(0.U(8.W))
  val axi_arlen_cntr = RegInit(0.U(8.W))
  val axi_arv_arr_flag = RegInit(false.B)
  val axi_rdata = RegInit(0.U(dataWidth.W))
  val axi_rvalid = RegInit(false.B)
  val axi_rresp = RegInit(0.U(2.W))
  val axi_rlast = RegInit(false.B)
  val axi_ruser = RegInit(0.U(userWidth.W))

  val aw_wrap_en = Wire(Bool())
  val aw_wrap_size = Wire(UInt(addrWidth.W))
  val ar_wrap_en = Wire(Bool())
  val ar_wrap_size = Wire(UInt(addrWidth.W))

  val mem_addr = Wire(UInt(opt_mem_addr_bits.W))
  val mem_select = Wire(UInt(userNumMem.W))
  val mem_data_out = Wire(Vec(userNumMem, UInt(dataWidth.W)))

  // I/O Connections
  axi.aw.ready := axi_awready
  axi.w.ready := axi_wready
  axi.b.bits.resp := axi_bresp
  axi.b.bits.user := axi_buser
  axi.b.valid := axi_bvalid
  axi.b.bits.id := axi.aw.bits.id
  axi.ar.ready := axi_arready
  axi.r.bits.data := axi_rdata
  axi.r.bits.resp := axi_rresp
  axi.r.bits.last := axi_rlast
  axi.r.bits.user := axi_ruser
  axi.r.valid := axi_rvalid
  axi.r.bits.id := axi.ar.bits.id

  aw_wrap_size := (dataWidth / 8).U * axi_awlen
  ar_wrap_size := (dataWidth / 8).U * axi_arlen
  aw_wrap_en := Mux((axi_awaddr & aw_wrap_size) === aw_wrap_size, true.B, false.B)
  ar_wrap_en := Mux((axi_awaddr & ar_wrap_size) === ar_wrap_size, true.B, false.B)

  mem_select := axi_awaddr(addrWidth - 1, addrWidth - opt_mem_addr_bits)
  mem_addr := Mux(axi_arv_arr_flag, 
    axi_araddr(opt_mem_addr_bits + addr_lsb - 1, addr_lsb),
    Mux(axi_awv_awr_flag, 
      axi_awaddr(opt_mem_addr_bits + addr_lsb - 1, addr_lsb),
      0.U
    )
  )

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

  when(axi_awv_awr_flag && axi_wready && axi.w.valid && !axi_bvalid && axi.w.bits.last) {
    axi_bvalid := true.B
    axi_bresp := 0.U // 'OKAT' response
  } .elsewhen (axi.b.ready && axi_bvalid) {
    axi_bvalid := false.B
  }

  // Address Read Channel
  when (!axi_arready && axi.ar.valid && !axi_awv_awr_flag && !axi_arv_arr_flag) {
    axi_arready := true.B
    axi_arv_arr_flag := true.B
  } .elsewhen (axi_rvalid && axi.r.ready && (axi_arlen_cntr === axi_arlen)) {
    axi_arv_arr_flag := false.B
  } .otherwise {
    axi_arready := false.B
  }

  when (!axi_arready && axi.ar.valid && !axi_arv_arr_flag) {
    axi_araddr := axi.ar.bits.addr
    axi_arburst := axi.ar.bits.burst
    axi_arlen := axi.ar.bits.len
    axi_arlen_cntr := 0.U
    axi_rlast := false.B
  } .elsewhen ((axi_arlen_cntr <= axi_arlen) && axi_rvalid && axi.r.ready) {
    axi_arlen_cntr := axi_arlen_cntr + 1.U
    axi_rlast := false.B

    when (axi_arburst === 0.U) {
      axi_araddr := axi_araddr
    } .elsewhen (axi_arburst === 1.U) {
      axi_araddr := Cat(axi_araddr(addrWidth - 1, addr_lsb) + 1.U, Fill(addr_lsb, 0.U))
    } .elsewhen (axi_arburst === 2.U) {
      axi_araddr := Mux(ar_wrap_en, axi_araddr - ar_wrap_size, Cat(axi_araddr(addrWidth - 1, addr_lsb) + 1.U, Fill(addr_lsb, 0.U)))
    } .otherwise {
      axi_araddr := axi.ar.bits.addr(addrWidth - 1, addr_lsb) + 1.U
    }
  } .elsewhen ((axi_arlen_cntr === axi_arlen) && !axi_rlast && axi_arv_arr_flag) {
    axi_rlast := true.B
  } .elsewhen (axi.r.ready) {
    axi_rlast := false.B
  }

  when (axi_arv_arr_flag && !axi_rvalid) {
    axi_rvalid := true.B
    axi_rresp := 0.U // 'OKAT' response
  } .elsewhen (axi_rvalid && axi.r.ready) {
    axi_rvalid := false.B
  }

  // Implement Accessing User Memory region (Gen Block RAM(s))
  for (i <- 0 until userNumMem) {
    val mem_we = Wire(Bool())
    val mem_re = Wire(Bool())

    mem_we := axi_wready && axi.w.valid
    mem_re := axi_arv_arr_flag

    for (mem_byte_index <- 0 until dataWidth / 8) {
      val data_in = Wire(UInt(8.W))
      val data_out = Wire(UInt(8.W))
    val byte_ram = SyncReadMem(1 << opt_mem_addr_bits, UInt(8.W))

      data_in := axi.w.bits.data(mem_byte_index * 8 + 7, mem_byte_index * 8)
      data_out := byte_ram.read(mem_addr, mem_re && (mem_select === i.U))
      when (mem_we && (mem_select === i.U) && axi.w.bits.strb(mem_byte_index)) {
        byte_ram.write(mem_addr, data_in)
      }
      when (mem_re && (mem_select === i.U)) {
        mem_data_out(i) := Cat(data_out, mem_data_out(i)(dataWidth - 1, 8))
      } 
    }
  }

  when (axi_rvalid) {
    axi_rdata := mem_data_out(mem_select)
  } .otherwise {
    axi_rdata := 0.U
  }
}
