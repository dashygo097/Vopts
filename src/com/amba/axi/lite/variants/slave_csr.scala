package com.amba

import utils._
import chisel3._
import chisel3.util._

abstract class AXILiteSlaveWithCSR(
  addrWidth: Int, 
  dataWidth: Int, 
  mmap: CSRMMap 
) extends AXILiteSlave(addrWidth, dataWidth) {
  // CSR Registers
  protected val regMap = mmap.registers.map { reg =>
    val value = RegInit(reg.initValue.U(dataWidth.W))
    reg.addr -> (reg, value)
  }.toMap

  // Parameters
  protected val numRegs = mmap.registers.length
  protected val indexWidth = log2Ceil(numRegs)

  // Register Memory
  protected val regMem = SyncReadMem(numRegs, UInt(dataWidth.W))

  protected val initMemory = VecInit(Seq.tabulate(numRegs) { addr =>
    val regInfo = mmap.registers.find(_.addr == addr)
    regInfo.map(r => (r.initValue & ((1L << dataWidth) - 1)).U).getOrElse(0.U)
  })

  protected val writableVec = VecInit(Seq.tabulate(numRegs) { addr =>
    val regInfo = mmap.registers.find(_.addr == addr)
    regInfo.map(_.writable).getOrElse(true).B
  })

  protected val readableVec = VecInit(Seq.tabulate(numRegs) { addr =>
    val regInfo = mmap.registers.find(_.addr == addr)
    regInfo.map(_.readable).getOrElse(true).B
  })

  protected def writable(addr: UInt): Bool = writableVec(addr)
  protected def readable(addr: UInt): Bool = readableVec(addr)

  // Write and Read Logic
  for ((addr, (regInfo, value)) <- regMap) {
    val index = (addr.U - mmap.baseAddr.U) >> addr_lsb
    when(writable(index(indexWidth - 1, 0))) {
      when(axi_on_awrite && axi.w.valid && axi.aw.bits.addr === addr.U(addrWidth.W)) {
        value := axi.w.bits.data
      }
    }
  }

  for ((addr, (regInfo, value)) <- regMap) {
    val index = (addr.U - mmap.baseAddr.U) >> addr_lsb
    when(readable(index(indexWidth - 1, 0))) {
      when(axi.ar.bits.addr === addr.U(addrWidth.W)) {
        axi_rdata := value
      }
    }
  }
  
  // Helpers 
  protected def getCSRAddr(name: String): UInt = {
    regMap.find(_._2._1.name == name) match {
      case Some((addr, _)) => addr.U(addrWidth.W)
      case None => throw new Exception(s"Register $name not found")
    }
  }
  protected def getCSR(name: String): UInt = {
    regMap.find(_._2._1.name == name) match {
      case Some((_, (_, value))) => value
      case None => throw new Exception(s"Register $name not found")
    }
  }
  protected def setCSR(name: String, value: UInt): Unit = {
    regMap.find(_._2._1.name == name) match {
      case Some((addr, (regInfo, value))) => 
        if (regInfo.writable) value := value
      case None => throw new Exception(s"Register $name not found")
    }
  }
}
