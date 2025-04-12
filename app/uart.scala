package app

import uart.UARTCore

object UART extends App {
  VerilogEmitter.parse(new UARTCore(115200), "uart.sv")
}
