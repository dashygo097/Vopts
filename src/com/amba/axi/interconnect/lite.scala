package com.amba

import utils._
import chisel3._
import chisel3.util._

class AXILiteInterconnect(
  addrWidth: Int,
  dataWidth: Int,
  addressMap: Seq[(Long, Long)] // (baseAddr, endAddr) for each slave
) extends Module {
  override def desiredName: String =
    s"axilite_interconnect${addressMap.length}_${addrWidth}x$dataWidth"

  require(addressMap.length > 0, "Address map must have at least one slave")
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")

  val slave   = IO(AXILiteSlaveIO(addrWidth, dataWidth))
  val masters = Seq.fill(addressMap.length)(IO(AXILiteMasterIO(addrWidth, dataWidth)))

  def decodeAddress(addr: UInt): UInt = {
    val slaveSelect = Wire(UInt(log2Ceil(addressMap.length).W))
    slaveSelect := 0.U

    for (i <- 0 until addressMap.length) {
      val baseAddr = addressMap(i)._1.U
      val endAddr  = addressMap(i)._2.U
      when(addr >= baseAddr && addr < endAddr) {
        slaveSelect := i.U
      }
    }
    slaveSelect
  }

  slave.suggestName("S_AXI")
  for (i <- 0 until addressMap.length) {
    masters(i).suggestName(s"M${i}_AXI")
    require(addressMap(i)._1 < addressMap(i)._2, s"Invalid address range for slave $i")
  }

  // Write Address Channel
  for (i <- 0 until addressMap.length) {
    masters(i).aw.valid := slave.aw.valid && (decodeAddress(slave.aw.bits.addr) === i.U)
    masters(i).aw.bits  := slave.aw.bits
  }
  slave.aw.ready := Mux1H(
    (0 until addressMap.length).map { i =>
      (decodeAddress(slave.aw.bits.addr) === i.U) -> masters(i).aw.ready
    }
  )

  // Write Data Channel
  for (i <- 0 until addressMap.length) {
    masters(i).w.valid := slave.w.valid && (decodeAddress(slave.aw.bits.addr) === i.U)
    masters(i).w.bits  := slave.w.bits
  }
  slave.w.ready := Mux1H(
    (0 until addressMap.length).map { i =>
      (decodeAddress(slave.aw.bits.addr) === i.U) -> masters(i).w.ready
    }
  )

  // Write Response Channel
  for (i <- 0 until addressMap.length)
    masters(i).b.ready := slave.b.ready && (decodeAddress(slave.aw.bits.addr) === i.U)
  slave.b.valid        := Mux1H(
    (0 until addressMap.length).map { i =>
      (decodeAddress(slave.aw.bits.addr) === i.U) -> masters(i).b.valid
    }
  )
  slave.b.bits         := Mux1H(
    (0 until addressMap.length).map { i =>
      (decodeAddress(slave.aw.bits.addr) === i.U) -> masters(i).b.bits
    }
  )

  // Read Address Channel
  for (i <- 0 until addressMap.length) {
    masters(i).ar.valid := slave.ar.valid && (decodeAddress(slave.ar.bits.addr) === i.U)
    masters(i).ar.bits  := slave.ar.bits
  }
  slave.ar.ready := Mux1H(
    (0 until addressMap.length).map { i =>
      (decodeAddress(slave.ar.bits.addr) === i.U) -> masters(i).ar.ready
    }
  )

  // Read Data Channel
  for (i <- 0 until addressMap.length)
    masters(i).r.ready := slave.r.ready && (decodeAddress(slave.ar.bits.addr) === i.U)
  slave.r.valid        := Mux1H(
    (0 until addressMap.length).map { i =>
      (decodeAddress(slave.ar.bits.addr) === i.U) -> masters(i).r.valid
    }
  )
  slave.r.bits         := Mux1H(
    (0 until addressMap.length).map { i =>
      (decodeAddress(slave.ar.bits.addr) === i.U) -> masters(i).r.bits
    }
  )

  def connect(intf: AXILiteMasterExternalIO): Unit = {
    slave.aw.bits.addr := intf.AWADDR
    slave.aw.bits.prot := intf.AWPROT
    slave.aw.valid     := intf.AWVALID
    intf.AWREADY       := slave.aw.ready
    slave.w.bits.data  := intf.WDATA
    slave.w.bits.strb  := intf.WSTRB
    slave.w.valid      := intf.WVALID
    intf.WREADY        := slave.w.ready
    intf.BRESP         := slave.b.bits.resp
    intf.BVALID        := slave.b.valid
    slave.b.ready      := intf.BREADY
    slave.ar.bits.addr := intf.ARADDR
    slave.ar.bits.prot := intf.ARPROT
    slave.ar.valid     := intf.ARVALID
    intf.ARREADY       := slave.ar.ready
    intf.RDATA         := slave.r.bits.data
    intf.RRESP         := slave.r.bits.resp
    intf.RVALID        := slave.r.valid
    slave.r.ready      := intf.RREADY
  }

  def connect(intf: AXILiteMasterIO): Unit =
    slave <> intf

  def connect(intf: AXILiteSlaveExternalIO, idx: Int): Unit = {
    require(idx >= 0 && idx < masters.length, "Invalid master index")
    intf.AWADDR              := masters(idx).aw.bits.addr
    intf.AWPROT              := masters(idx).aw.bits.prot
    intf.AWVALID             := masters(idx).aw.valid
    masters(idx).aw.ready    := intf.AWREADY
    intf.WDATA               := masters(idx).w.bits.data
    intf.WSTRB               := masters(idx).w.bits.strb
    intf.WVALID              := masters(idx).w.valid
    masters(idx).w.ready     := intf.WREADY
    masters(idx).b.bits.resp := intf.BRESP
    masters(idx).b.valid     := intf.BVALID
    intf.BREADY              := masters(idx).b.ready
    intf.ARADDR              := masters(idx).ar.bits.addr
    intf.ARPROT              := masters(idx).ar.bits.prot
    intf.ARVALID             := masters(idx).ar.valid
    masters(idx).ar.ready    := intf.ARREADY
    masters(idx).r.bits.data := intf.RDATA
    masters(idx).r.bits.resp := intf.RRESP
    masters(idx).r.valid     := intf.RVALID
    intf.RREADY              := masters(idx).r.ready
  }

  def connect(intf: AXILiteSlaveIO, idx: Int): Unit = {
    require(idx >= 0 && idx < masters.length, "Invalid master index")
    masters(idx) <> intf
  }
}

object AXILiteInterconnect {
  def apply(
    addrWidth: Int,
    dataWidth: Int,
    addressMap: Seq[(Long, Long)]
  ): AXILiteInterconnect =
    Module(new AXILiteInterconnect(addrWidth, dataWidth, addressMap))
}

object TestAXILiteInterconnect extends App {
  VerilogEmitter.parse(
    new AXILiteInterconnect(
      32,
      32,
      Seq(
        (0x80000000L, 0x90000000L),
        (0x90000000L, 0xa0000000L)
      )
    ),
    "axi_lite_interconnect.sv",
    info = true
  )
}
