package app

import global._
import uart.UARTCore
import java.io.{BufferedWriter, File, FileWriter}

import chisel3._
import chisel3.util._

import _root_.circt.stage.ChiselStage

object UART extends App {
  VerilogEmitter.parse(new UARTCore(115200), "uart.sv")
}
