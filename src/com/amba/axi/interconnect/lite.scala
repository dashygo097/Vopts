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
  for (i <- 0 until addressMap.length)
    require(addressMap(i)._1 < addressMap(i)._2, s"Invalid address range for slave $i")

  val slave_ext = IO(new AXILiteSlaveExtIO(addrWidth, dataWidth)).suggestName("S_AXI")
  val slave     = Wire(AXILiteSlaveIO(addrWidth, dataWidth))

  val masters_ext =
    IO(Vec(addressMap.length, new AXILiteMasterExtIO(addrWidth, dataWidth))).suggestName("M_AXI")
  val masters     = Seq.fill(addressMap.length)(Wire(AXILiteMasterIO(addrWidth, dataWidth)))

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

  // AW
  for (i <- 0 until addressMap.length) {
    masters(i).aw.valid := slave.aw.valid && (decodeAddress(slave.aw.bits.addr) === i.U)
    masters(i).aw.bits  := slave.aw.bits
  }
  slave.aw.ready := Mux1H(
    (0 until addressMap.length).map { i =>
      (decodeAddress(slave.aw.bits.addr) === i.U) -> masters(i).aw.ready
    }
  )

  // W
  for (i <- 0 until addressMap.length) {
    masters(i).w.valid := slave.w.valid && (decodeAddress(slave.aw.bits.addr) === i.U)
    masters(i).w.bits  := slave.w.bits
  }
  slave.w.ready := Mux1H(
    (0 until addressMap.length).map { i =>
      (decodeAddress(slave.aw.bits.addr) === i.U) -> masters(i).w.ready
    }
  )

  // B
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

  // AR
  for (i <- 0 until addressMap.length) {
    masters(i).ar.valid := slave.ar.valid && (decodeAddress(slave.ar.bits.addr) === i.U)
    masters(i).ar.bits  := slave.ar.bits
  }
  slave.ar.ready := Mux1H(
    (0 until addressMap.length).map { i =>
      (decodeAddress(slave.ar.bits.addr) === i.U) -> masters(i).ar.ready
    }
  )

  // R
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

  slave_ext.connect(slave)
  for (i <- 0 until addressMap.length)
    masters_ext(i).connect(masters(i))
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
        (0x80000000L, 0x8000ffffL),
        (0x80010000L, 0x8001ffffL)
      )
    ),
    "axilite_interconnect.sv",
    info = true
  )
}
