package com.amba

import utils._
import chisel3._

class AXIFull2LiteBridge(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0) extends Module {
  override def desiredName: String =
    s"axi_full2lite_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"

  val ext_slave = IO(new AXIFullSlaveExternalIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val slave     = Wire(AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))

  val ext_master = IO(new AXILiteMasterExternalIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val master     = Wire(AXILiteMasterIO(addrWidth, dataWidth))

  // To be implemented: AXI Full to AXI Lite bridge logic

  ext_slave.connect(slave)
  ext_master.connect(master)

  def connect(intf: AXIFullMasterExternalIO): Unit = intf <> ext_slave
  def connect(intf: AXILiteSlaveExternalIO): Unit  = intf <> ext_master
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
