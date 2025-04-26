package app

import spi.SPIMasterCore

object SPIMaster extends App {
  VerilogEmitter.parse(new SPIMasterCore(12, 100), "spi.sv")
}
