package app.guangsai

import peripheral.{ADC122S625Core, MCP4921Core}
import com.fsmc.FSMCSlaveRAMCore
import app.VerilogEmitter

import utils._
import chisel3._

class ADC1IO extends Bundle {
  val ADC1_EN = Input(Bool())
  val ADC1_CS_N = Output(Bool())
  val ADC1_SDO = Input(Bool())
  val ADC1_DATA_A = Output(new FP(12, 11))
  val ADC1_DATA_B = Output(new FP(12, 11))

  val ADC1_SCLK = Input(Clock())
  val ADC1_GATE_IN = Input(Bool())
  val ADC1_GATE_OUT = Input(Bool())
  
  val ADC1_FULL_A = Output(Bool())
  val ADC1_FULL_B = Output(Bool())
  val ADC1_EMPTY_A = Output(Bool())
  val ADC1_EMPTY_B = Output(Bool())
}

class Top extends Module {
  val adc1_io = IO(new ADC1IO)
  val adc1 = Module(new ADC122S625Core(128))

  // ADC1 INPUT
  adc1.io.en := adc1_io.ADC1_EN
  adc1.io.sdo := adc1_io.ADC1_SDO
  adc1.io.sclk := adc1_io.ADC1_SCLK
  adc1.io.gateIn := adc1_io.ADC1_GATE_IN
  adc1.io.gateOut := adc1_io.ADC1_GATE_OUT

  // ADC1 OUTPUT
  adc1_io.ADC1_CS_N := adc1.io.cs_n
  adc1_io.ADC1_DATA_A := adc1.io.dataA
  adc1_io.ADC1_DATA_B := adc1.io.dataB
  adc1_io.ADC1_FULL_A := adc1.io.fullA
  adc1_io.ADC1_FULL_B := adc1.io.fullB
  adc1_io.ADC1_EMPTY_A := adc1.io.emptyA
  adc1_io.ADC1_EMPTY_B := adc1.io.emptyB

}

object Top extends App {
  VerilogEmitter.parse(new Top, "top.sv")
}
