package app.guangsai

import com.uart.UartCore
import app.VerilogEmitter

object Uart extends App {
  VerilogEmitter.parse(new UartCore(115200), "guangsai/uart.sv")
}
