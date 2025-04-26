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

class SPIMasterCore(sDataWidth: Int, clkDiv: Int) extends Module {
  val io = IO(new Bundle {
    val interface = new SPIMasterInterfaceIO
    val data = new SPIMasterDataIO(sDataWidth)
  })

  val sckCounter = RegInit(0.U(log2Ceil(clkDiv).W))
  val sckReg = RegInit(false.B)  // CPOL=0 (starts low)
  val txReg = RegInit(0.U(sDataWidth.W))
  val rxReg = RegInit(0.U(sDataWidth.W))
  val bitCounter = RegInit(0.U((log2Ceil(sDataWidth) + 1).W))
  val active = RegInit(false.B)
  val doneReg = RegInit(false.B)

  io.interface.mosi := txReg(sDataWidth - 1)  // MSB first
  io.interface.ss := !active
  io.interface.sck := sckReg
  io.data.rxData := rxReg
  io.data.done := doneReg

  when(active) {
    sckCounter := sckCounter + 1.U

    when(sckCounter === (clkDiv - 1).U) {
      sckReg := !sckReg
      sckCounter := 0.U

      when(sckReg) {  
        // Shift out next bit (MSB first)
        txReg := Cat(txReg(sDataWidth - 2, 0), 0.U)
        bitCounter := bitCounter + 1.U
      }.otherwise {  // Rising edge (leading edge for CPHA=0)
        rxReg := Cat(rxReg(sDataWidth - 2, 0), io.interface.miso)
      }

      when(bitCounter === sDataWidth.U) {
        active := false.B
        doneReg := true.B
      }
    }
  }.otherwise {
    when(io.data.start) {
      active := true.B
      doneReg := false.B
      txReg := io.data.txData
      rxReg := 0.U
      bitCounter := 0.U
      sckReg := false.B  // CPOL=0
      sckCounter := 0.U
    }
  }
}
