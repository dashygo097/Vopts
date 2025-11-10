package com.amba

import utils._
import chisel3._

abstract class AXILiteSlaveWithCSR(
  addrWidth: Int, 
  dataWidth: Int, 
  mmap: CSRMMap 
) extends AXILiteSlave(addrWidth, dataWidth) {
  
  protected val regMap = mmap.registers.map { reg =>
    val hwReg = RegInit(reg.initValue.U(dataWidth.W))
    reg.addr -> (reg, hwReg)
  }.toMap
  
  protected val csr_write_enable = axi_on_awrite && axi.w.valid
  
  for ((addr, (regInfo, hwReg)) <- regMap) {
    when(csr_write_enable && axi.aw.bits.addr === addr.U(addrWidth.W)) {
      if (regInfo.writable) {
        hwReg := axi.w.bits.data
      }
    }
  }
  
  protected val csr_read_data = WireDefault(0.U(dataWidth.W))
  
  for ((addr, (regInfo, hwReg)) <- regMap) {
    when(axi.ar.bits.addr === addr.U(addrWidth.W)) {
      if (regInfo.readable) {
        csr_read_data := hwReg
      }
    }
  }
  
  protected def getReg(name: String): UInt = {
    regMap.find(_._2._1.name == name) match {
      case Some((_, (_, hwReg))) => hwReg
      case None => throw new Exception(s"Register $name not found")
    }
  }
  
  protected def updateReg(name: String, value: UInt): Unit = {
    regMap.find(_._2._1.name == name) match {
      case Some((addr, (regInfo, hwReg))) => 
        if (regInfo.writable) hwReg := value
      case None => throw new Exception(s"Register $name not found")
    }
  }
}
