package test

import peripheral.ADS7251Core
import app.VerilogEmitter

object ADS7251 extends App {
  VerilogEmitter.parse(new ADS7251Core, "ads7251.sv")
}
