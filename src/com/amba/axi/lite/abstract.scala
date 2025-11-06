package com.amba

import chisel3._

abstract class AXILiteSlave(val addrWidth: Int, val dataWidth: Int) extends Module {
  val maxDataValue                 = BigInt(1) << dataWidth
  val maxAddrValue                 = BigInt(1) << addrWidth

  val ext_axi = IO(new AXILiteSlaveExternalIO(addrWidth, dataWidth)).suggestName("S_AXI")
  private val axi = Wire(new AXILiteSlaveIO(addrWidth, dataWidth))
  ext_axi.connect(axi)

  val awready = RegInit(false.B)
  val wready  = RegInit(false.B)
  val bvalid  = RegInit(false.B)
  val arready = RegInit(false.B)
  val rvalid  = RegInit(false.B)
  
  val awaddr = Reg(UInt(addrWidth.W))
  val araddr = Reg(UInt(addrWidth.W))
  
  axi.aw.ready := awready
  axi.w.ready  := wready
  axi.b.valid  := bvalid
  axi.ar.ready := arready
  axi.r.valid  := rvalid

  axi.b.bits.resp := 0.U(2.W)
  axi.r.bits.resp := 0.U(2.W)

  // AW
  when(!awready && axi.aw.valid) {
    awaddr  := axi.aw.bits.addr
    awready := true.B
  } .elsewhen(axi.w.fire) { 
    awready := false.B
  }

  // W
  when(!wready && awready) {
    wready := true.B
  } .elsewhen(axi.w.fire) {
    wready := false.B
  }

  // B 
  when(axi.w.fire && !bvalid) {
    bvalid := true.B
  } .elsewhen(bvalid && axi.b.ready) {
    bvalid := false.B
  }

  // AR
  when(!arready && axi.ar.valid) {
    araddr  := axi.ar.bits.addr
    arready := true.B
  } .elsewhen(axi.r.fire) { 
    arready := false.B
  }

  // R
  when(axi.ar.fire && !rvalid) {
    rvalid := true.B
  } .elsewhen(axi.r.fire) {
    rvalid := false.B
  }

  def doWrite(addr: UInt, data: UInt, strb: UInt): Unit
  def doRead(addr: UInt): UInt
  def getBresp(addr: UInt): UInt = 0.U(2.W)
  def getRresp(addr: UInt): UInt = 0.U(2.W)

  when(axi.w.fire) {
    doWrite(awaddr, axi.w.bits.data, axi.w.bits.strb)
  }
  
  axi.r.bits.data := doRead(araddr)
  axi.b.bits.resp := getBresp(awaddr)
  axi.r.bits.resp := getRresp(araddr)
}
