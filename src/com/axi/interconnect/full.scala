package com.axi

import chisel3._
import chisel3.util._

class AXIFullInterconnect(
  addrWidth: Int,
  dataWidth: Int,
  idWidth: Int,
  userWidth: Int,
  addressMap: Seq[(Long, Long)] // (baseAddr, endAddr) for each slave
) extends Module {
  override def desiredName: String =
    s"axifull_interconnect${addressMap.length}_${addrWidth}x$dataWidth"

  require(addressMap.length > 0, "Address map must have at least one slave")
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")

  val slave   = IO(AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))
  val masters =
    Seq.fill(addressMap.length)(IO(AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth)))

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

  def connect(intf: AXIFullMasterExternalIO): Unit = {
    slave.aw.bits.addr   := intf.AWADDR
    slave.aw.bits.prot   := intf.AWPROT
    slave.aw.bits.len    := intf.AWLEN
    slave.aw.bits.size   := intf.AWSIZE
    slave.aw.bits.burst  := intf.AWBURST
    slave.aw.bits.lock   := intf.AWLOCK
    slave.aw.bits.cache  := intf.AWCACHE
    slave.aw.bits.qos    := intf.AWQOS
    slave.aw.bits.region := intf.AWREGION
    slave.aw.bits.id     := intf.AWID
    slave.aw.bits.user   := intf.AWUSER
    slave.aw.valid       := intf.AWVALID
    intf.AWREADY         := slave.aw.ready
    slave.w.bits.data    := intf.WDATA
    slave.w.bits.strb    := intf.WSTRB
    slave.w.bits.last    := intf.WLAST
    slave.w.bits.id      := intf.WID
    slave.w.bits.user    := intf.WUSER
    slave.w.valid        := intf.WVALID
    intf.WREADY          := slave.w.ready
    intf.BRESP           := slave.b.bits.resp
    intf.BID             := slave.b.bits.id
    intf.BUSER           := slave.b.bits.user
    intf.BVALID          := slave.b.valid
    slave.b.ready        := intf.BREADY
    slave.ar.bits.addr   := intf.ARADDR
    slave.ar.bits.prot   := intf.ARPROT
    slave.ar.bits.len    := intf.ARLEN
    slave.ar.bits.size   := intf.ARSIZE
    slave.ar.bits.burst  := intf.ARBURST
    slave.ar.bits.lock   := intf.ARLOCK
    slave.ar.bits.cache  := intf.ARCACHE
    slave.ar.bits.qos    := intf.ARQOS
    slave.ar.bits.region := intf.ARREGION
    slave.ar.bits.id     := intf.ARID
    slave.ar.bits.user   := intf.ARUSER
    slave.ar.valid       := intf.ARVALID
    intf.ARREADY         := slave.ar.ready
    intf.RDATA           := slave.r.bits.data
    intf.RRESP           := slave.r.bits.resp
    intf.RLAST           := slave.r.bits.last
    intf.RID             := slave.r.bits.id
    intf.RUSER           := slave.r.bits.user
    intf.RVALID          := slave.r.valid
    slave.r.ready        := intf.RREADY
  }

  def connect(intf: AXIFullMasterIO): Unit =
    slave <> intf

  def connect(intf: AXIFullSlaveExternalIO, idx: Int): Unit = {
    require(idx >= 0 && idx < masters.length, "Invalid master index")
    intf.AWADDR              := masters(idx).aw.bits.addr
    intf.AWPROT              := masters(idx).aw.bits.prot
    intf.AWLEN               := masters(idx).aw.bits.len
    intf.AWSIZE              := masters(idx).aw.bits.size
    intf.AWBURST             := masters(idx).aw.bits.burst
    intf.AWLOCK              := masters(idx).aw.bits.lock
    intf.AWCACHE             := masters(idx).aw.bits.cache
    intf.AWQOS               := masters(idx).aw.bits.qos
    intf.AWREGION            := masters(idx).aw.bits.region
    intf.AWID                := masters(idx).aw.bits.id
    intf.AWUSER              := masters(idx).aw.bits.user
    intf.AWVALID             := masters(idx).aw.valid
    masters(idx).aw.ready    := intf.AWREADY
    intf.WDATA               := masters(idx).w.bits.data
    intf.WSTRB               := masters(idx).w.bits.strb
    intf.WLAST               := masters(idx).w.bits.last
    intf.WID                 := masters(idx).w.bits.id
    intf.WUSER               := masters(idx).w.bits.user
    intf.WVALID              := masters(idx).w.valid
    masters(idx).w.ready     := intf.WREADY
    masters(idx).b.bits.resp := intf.BRESP
    masters(idx).b.bits.id   := intf.BID
    masters(idx).b.bits.user := intf.BUSER
    masters(idx).b.valid     := intf.BVALID
    intf.BREADY              := masters(idx).b.ready
    intf.ARADDR              := masters(idx).ar.bits.addr
    intf.ARPROT              := masters(idx).ar.bits.prot
    intf.ARLEN               := masters(idx).ar.bits.len
    intf.ARSIZE              := masters(idx).ar.bits.size
    intf.ARBURST             := masters(idx).ar.bits.burst
    intf.ARLOCK              := masters(idx).ar.bits.lock
    intf.ARCACHE             := masters(idx).ar.bits.cache
    intf.ARQOS               := masters(idx).ar.bits.qos
    intf.ARREGION            := masters(idx).ar.bits.region
    intf.ARID                := masters(idx).ar.bits.id
    intf.ARUSER              := masters(idx).ar.bits.user
    intf.ARVALID             := masters(idx).ar.valid
    masters(idx).ar.ready    := intf.ARREADY
    masters(idx).r.bits.data := intf.RDATA
    masters(idx).r.bits.resp := intf.RRESP
    masters(idx).r.bits.last := intf.RLAST
    masters(idx).r.bits.id   := intf.RID
    masters(idx).r.bits.user := intf.RUSER
    masters(idx).r.valid     := intf.RVALID
    intf.RREADY              := masters(idx).r.ready
  }

  def connect(intf: AXIFullSlaveIO, idx: Int): Unit = {
    require(idx >= 0 && idx < masters.length, "Invalid master index")
    masters(idx) <> intf
  }
}

object AXIFullInterconnect {
  def apply(
    addrWidth: Int,
    dataWidth: Int,
    idWidth: Int,
    userWidth: Int,
    addressMap: Seq[(Long, Long)]
  ): AXIFullInterconnect =
    Module(new AXIFullInterconnect(addrWidth, dataWidth, idWidth, userWidth, addressMap))
}
