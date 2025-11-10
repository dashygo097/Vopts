package com.amba

import utils._
import chisel3._

abstract class AXILiteSlaveWithCSR(
  addrWidth: Int,
  dataWidth: Int,
  mmap: CSRMMap
) extends AXILiteSlave(addrWidth, dataWidth) {
  // CSR Registers
  private val regMap = mmap.registers.map { reg =>
    val value = RegInit(reg.initValue.U(dataWidth.W))
    reg.addr -> (reg, value)
  }.toMap

  // Helpers
  protected def getAddr(name: String): UInt =
    regMap.find(_._2._1.name == name) match {
      case Some((addr, _)) => addr.U(addrWidth.W)
      case None            => throw new Exception(s"Register $name not found")
    }

  // RW Access
  protected def writeAccess(name: String): Bool =
    getAddr(name) === axi_awaddr
  protected def readAccess(name: String): Bool  =
    getAddr(name) === axi_araddr

  // Factory Methods
  protected def registerRead(name: String, value: UInt): Unit =
    when(readAccess(name)) {
      axi_rdata := value
    }

  axi_rdata := 0.U
}
