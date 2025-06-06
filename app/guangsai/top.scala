package app.guangsai

import peripheral.{ADC122S625Core, MCP4921Core}
import com.fsmc.FSMCSlaveRAMCore
import app.VerilogEmitter

import utils._
import chisel3._

class ADCIO extends Bundle {
  val CS = Input(Bool())
  val DOUT = Input(Bool())
  val SCLK = Input(Clock())

  val DATA_A = Output(new FP(12, 11))
  val DATA_B = Output(new FP(12, 11))

  val FULL_A = Output(Bool())
  val FULL_B = Output(Bool())
  val EMPTY_A = Output(Bool())
  val EMPTY_B = Output(Bool())

}

class TopModule extends Module {
  val DFB1_ADC = IO(new ADCIO)
  val adc1 = Module(new ADC122S625Core(128))

  adc1.io.cs_n := DFB1_ADC.CS
  adc1.io.sdo := DFB1_ADC.DOUT
  adc1.io.sclk := DFB1_ADC.SCLK
  adc1.io.gateIn := 1.B
  adc1.io.gateOut := 1.B

  DFB1_ADC.DATA_A := adc1.io.dataA
  DFB1_ADC.DATA_B := adc1.io.dataB

  DFB1_ADC.FULL_A := adc1.io.fullA
  DFB1_ADC.FULL_B := adc1.io.fullB
  DFB1_ADC.EMPTY_A := adc1.io.emptyA
  DFB1_ADC.EMPTY_B := adc1.io.emptyB
}

object Top extends App {
  VerilogEmitter.parse(new TopModule, "top_module.sv")
}
