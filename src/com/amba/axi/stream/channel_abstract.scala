package com.amba

import chisel3._

abstract class AXIStreamChannel(dataWidth: Int, idWidth: Int, destWidth: Int, userWidth: Int) extends Module {
  protected def getExtSAXIName: String = "S_AXIS"
  protected def getExtMAXIName: String = "M_AXIS"

  // AXI-Stream Interface
  val axis_master_ext = IO(new AXIStreamMasterExtIO(dataWidth, idWidth, destWidth, userWidth)).suggestName(getExtMAXIName)
  val axis_master     = Wire(new AXIStreamMasterIO(dataWidth, idWidth, destWidth, userWidth))
  val axis_slave_ext  = IO(new AXIStreamSlaveExtIO(dataWidth, idWidth, destWidth, userWidth)).suggestName(getExtSAXIName)
  val axis_slave      = Wire(new AXIStreamSlaveIO(dataWidth, idWidth, destWidth, userWidth))

  axis_master_ext.connect(axis_master)
  axis_slave_ext.connect(axis_slave)
}
