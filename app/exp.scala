package app
import global.Config

import chisel3._
import chisel3.util._

class StreamLightCoreIO extends Bundle {
  val mod = Input(Bool())
  val out = Output(UInt(4.W))
} 

class StreamLightCore extends Module with Config {
  val io = IO(new StreamLightCoreIO)
  val divider = 100000000
  val counter = RegInit(0.U(log2Ceil(divider).W))
  val bit = RegInit(0.U(2.W))

  counter := Mux(counter === (divider - 1).U, 0.U, counter + 1.U)
  when (counter === divider.U - 1.U) {
    bit := Mux(io.mod, bit - 1.U, bit + 1.U)
  }

  io.out := 1.U << bit
}

object StreamLight extends App {
  VerilogEmitter.parse(new StreamLightCore, "streamlight.sv")
}
