package test

import com.uart.UartCore
import app.VerilogEmitter

object Uart extends App {
  VerilogEmitter.parse(new UartCore(115200), "uart.sv")
}


