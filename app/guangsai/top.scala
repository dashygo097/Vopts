package app.guangsai

import peripheral.{ADC122S625Core, MCP4921Core}
import com.fsmc.FSMCSlaveRAMCore
import app.VerilogEmitter

import utils._
import chisel3._

class TopIO extends Bundle {
}

class Top extends Module {
  val io = IO(new TopIO)
}

object Top extends App {
  VerilogEmitter.parse(new Top, "top.sv")
}
