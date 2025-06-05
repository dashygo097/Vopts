package app

import peripheral.{ADC122S625Core, MCP4921Core}
import app.VerilogEmitter

object ADC122S625 extends App {
  VerilogEmitter.parse(new ADC122S625Core(8), "adc122s625.sv")
}

object MCP4921 extends App {
  VerilogEmitter.parse(new MCP4921Core, "mcp4921.sv")
}
