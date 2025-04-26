package app

import com.uart.{UartCore, SerialUartCore}

object UART extends App {
  VerilogEmitter.parse(new UartCore(115200), "uart.sv")
  VerilogEmitter.parse(new SerialUartCore(115200), "serial_uart.sv")
}

