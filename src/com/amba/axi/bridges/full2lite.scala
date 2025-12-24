package com.amba

import utils._
import chisel3._

class AXIFull2LiteBridge(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0) extends Module {
  override def desiredName: String =
    s"axi_full2lite_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"

  val slave_ext = IO(new AXIFullSlaveExtIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val slave     = Wire(AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))

  val master_ext = IO(new AXILiteMasterExtIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val master     = Wire(AXILiteMasterIO(addrWidth, dataWidth))

  // To be implemented: AXI Full to AXI Lite bridge logic

  slave_ext.connect(slave)
  master_ext.connect(master)
}

object AXIFull2LiteBridge {
  def apply(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0): AXIFull2LiteBridge =
    Module(new AXIFull2LiteBridge(addrWidth, dataWidth, idWidth, userWidth))
}

object TestAXIFull2LiteBridge extends App {
  VerilogEmitter.parse(
    new AXIFull2LiteBridge(32, 32, 4, 1),
    "axifull_to_lite_bridge.sv",
    info = true
  )
}
