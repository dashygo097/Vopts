package utils

import chisel3._
import chisel3.util._
import chisel3.experimental._

class BidirectionalBuffer(width: Int) extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val dataIO = Analog(width.W)
    val dataIn = Output(UInt(width.W))  
    val dataOut = Input(UInt(width.W))  
    val oe = Input(Bool())
  })
  
  setInline("bidirectional_buffer.sv",
    s"""
    |module BidirectionalBuffer(
    |  inout  [${width-1}:0] dataIO,
    |  output [${width-1}:0] dataIn,
    |  input  [${width-1}:0] dataOut,
    |  input  oe
    |);
    |  
    |  // Tristate buffer
    |  assign dataIO = oe ? dataOut : ${width}'bz;
    |  
    |  // Always read from bus
    |  assign dataIn = dataIO;
    |  
    |endmodule
    """.stripMargin)
}


class SyncBidirectionalBuffer(width: Int) extends Module {
  val io = IO(new Bundle {
    val dataIO = Analog(width.W)
    val dataIn = Output(UInt(width.W))
    val dataOut = Input(UInt(width.W))
    val oe = Input(Bool())
  })
  
  val buffer = Module(new BidirectionalBuffer(width))
  attach(io.dataIO, buffer.io.dataIO)
  buffer.io.dataOut := io.dataOut
  buffer.io.oe := io.oe
  
  io.dataIn := RegNext(buffer.io.dataIn)
}
