package com.axi

import chisel3._
import chisel3.util._

class AXILiteInterconnect(
  addrWidth: Int,
  dataWidth: Int,
  addressMap: Seq[(Long, Long)] // (baseAddr, endAddr) for each slave
) extends Module {
  override def desiredName: String =
    s"axi_lite_interconnect${addressMap.length}_${addrWidth}x$dataWidth"

  require(addressMap.length > 0, "Address map must have at least one slave")
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")

  val slave   = IO(AXILiteSlaveIO(addrWidth, dataWidth))
  val masters = Seq.fill(addressMap.length)(IO(AXILiteMasterIO(addrWidth, dataWidth)))

  slave.suggestName("S_AXI")
  for (i <- 0 until addressMap.length)
    masters(i).suggestName(s"M${i}_AXI")

  for (i <- 0 until addressMap.length)
    require(addressMap(i)._1 < addressMap(i)._2, s"Invalid address range for slave $i")

  // Write Address Channel
  for (i <- 0 until addressMap.length) {
    masters(i).aw.valid := slave.aw.valid &&
      (slave.aw.bits.addr >= addressMap(i)._1.U && slave.aw.bits.addr < addressMap(i)._2.U)
    masters(i).aw.bits  := slave.aw.bits
  }

  slave.aw.ready := Mux1H(masters.map(_.aw.valid), masters.map(_.aw.ready))

  // Write Data Channel
  for (i <- 0 until addressMap.length) {
    masters(i).w.valid := slave.w.valid &&
      (slave.aw.bits.addr >= addressMap(i)._1.U && slave.aw.bits.addr < addressMap(i)._2.U)
    masters(i).w.bits  := slave.w.bits
  }

  slave.w.ready := Mux1H(masters.map(_.w.valid), masters.map(_.w.ready))

  // Write Response Channel
  for (i <- 0 until addressMap.length) {
    slave.b.valid      := Mux1H(masters.map(_.aw.valid), masters.map(_.b.valid))
    slave.b.bits       := Mux1H(masters.map(_.aw.valid), masters.map(_.b.bits))
    masters(i).b.ready := slave.b.ready &&
      (slave.aw.bits.addr >= addressMap(i)._1.U && slave.aw.bits.addr < addressMap(i)._2.U)
  }

  // Read Address Channel
  for (i <- 0 until addressMap.length) {
    masters(i).ar.valid := slave.ar.valid &&
      (slave.ar.bits.addr >= addressMap(i)._1.U && slave.ar.bits.addr < addressMap(i)._2.U)
    masters(i).ar.bits  := slave.ar.bits
  }

  slave.ar.ready := Mux1H(masters.map(_.ar.valid), masters.map(_.ar.ready))

  // Read Data Channel
  for (i <- 0 until addressMap.length) {
    slave.r.valid      := Mux1H(masters.map(_.ar.valid), masters.map(_.r.valid))
    slave.r.bits       := Mux1H(masters.map(_.ar.valid), masters.map(_.r.bits))
    masters(i).r.ready := slave.r.ready &&
      (slave.ar.bits.addr >= addressMap(i)._1.U && slave.ar.bits.addr < addressMap(i)._2.U)
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

class AXIFullInterconect extends Module {

}
