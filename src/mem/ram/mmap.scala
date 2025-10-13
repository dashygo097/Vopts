package com.ram

import chisel3._

class MMapRAMIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  // Write Interface
  val write_en   = Input(Bool())
  val write_addr = Input(UInt(addrWidth.W))
  val write_data = Input(UInt(dataWidth.W))
  val write_strb = Input(UInt((dataWidth / 8).W))
  val write_resp = Output(Bool()) // true = OKAY, false = SLVERR

  // Read Interface
  val read_en   = Input(Bool())
  val read_addr = Input(UInt(addrWidth.W))
  val read_data = Output(UInt(dataWidth.W))
  val read_resp = Output(Bool()) // true = OKAY, false = SLVERR
}

class RAMRegion(addrWidth: Int, dataWidth: Int, memSize: BigInt, baseAddr: BigInt = 0x0) extends Module {
  val maxAddrValue                 = BigInt(1) << addrWidth
  require(
    memSize > 0 && baseAddr >= 0 && (baseAddr + (memSize * dataWidth)) <= maxAddrValue,
    s"RAM address out of range for addrWidth $addrWidth"
  )
}
