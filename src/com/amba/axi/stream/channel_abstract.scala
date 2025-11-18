package com.amba

import chisel3._

abstract class AXIStreamChannel(dataWidth: Int, idWidth: Int, destWidth: Int, userWidth: Int) extends Module {
  protected def getExtSAXIName: String = "S_AXIS"
  protected def getExtMAXIName: String = "M_AXIS"

  // AXI-Stream Interface
  val ext_axis_master = IO(new AXIStreamMasterExternalIO(dataWidth, idWidth, destWidth, userWidth)).suggestName(getExtMAXIName)
  val axis_master     = Wire(new AXIStreamMasterIO(dataWidth, idWidth, destWidth, userWidth))
  val ext_axis_slave  = IO(new AXIStreamSlaveExternalIO(dataWidth, idWidth, destWidth, userWidth)).suggestName(getExtSAXIName)
  val axis_slave      = Wire(new AXIStreamSlaveIO(dataWidth, idWidth, destWidth, userWidth))

  ext_axis_master.connect(axis_master)
  ext_axis_slave.connect(axis_slave)
}
