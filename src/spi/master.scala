package spi

import chisel3._
import chisel3.util._


class SPIMasterInterfaceIO extends Bundle {
  val sck = Output(Bool())  
  val mosi = Output(Bool()) 
  val miso = Input(Bool())  
  val ss = Output(Bool())
}

class SPIMasterDataIO(sDataWidth: Int) extends Bundle {
  val txData = Input(UInt(sDataWidth.W)) 
  val rxData = Output(UInt(sDataWidth.W))
  val start = Input(Bool()) 
  val done = Output(Bool())
}

