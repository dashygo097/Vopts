package app

import spi.SPIMasterReceiver

object SPIMasterReceiver extends App {
  VerilogEmitter.parse(new SPIMasterReceiver(12, 5), "spi.sv")
}
