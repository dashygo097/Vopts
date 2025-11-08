package com.amba

import utils._
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
  for (i <- 0 until addressMap.length)
    require(addressMap(i)._1 < addressMap(i)._2, s"Invalid address range for slave $i")

  val ext_slave = IO(new AXIFullSlaveExternalIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val slave     = Wire(AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))

  val ext_masters =
    IO(Vec(addressMap.length, new AXIFullMasterExternalIO(addrWidth, dataWidth, idWidth, userWidth)))
  val masters     =
    Seq.fill(addressMap.length)(Wire(AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth)))

  for (i <- 0 until addressMap.length)
    ext_masters(i).suggestName(s"M_AXI_$i")

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

  ext_slave.connect(slave)
  for (i <- 0 until addressMap.length)
    ext_masters(i).connect(masters(i))

  def connect(intf: AXIFullMasterExternalIO): Unit          = intf <> ext_slave
  def connect(intf: AXIFullSlaveExternalIO, idx: Int): Unit = {
    require(idx >= 0 && idx < masters.length, "Invalid master index")
    intf <> ext_masters(idx)
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

object TestAXIFullInterconnect extends App {
  VerilogEmitter.parse(
    new AXIFullInterconnect(
      32,
      32,
      4,
      1,
      Seq(
        (0x80000000L, 0x8000ffffL),
        (0x80010000L, 0x8001ffffL)
      )
    ),
    "axifull_interconnect.sv",
    info = true
  )
}
