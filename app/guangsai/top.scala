package app.guangsai

import peripheral.{ADC122S625Core, MCP4921Core}
import com.fsmc.FSMCSlaveRAMCore
import app.VerilogEmitter

import utils._
import chisel3._

class ADCIO extends Bundle {
  val SCLK = Input(Clock())
  val CS = Input(Bool())
  val DOUT = Input(Bool())

  val DATA_A = Output(new FP(12, 11))
  val DATA_B = Output(new FP(12, 11))
  val GATE_IN = Input(Bool())
  val GATE_OUT = Input(Bool())
  val FULL_A = Output(Bool())
  val FULL_B = Output(Bool())
  val EMPTY_A = Output(Bool())
  val EMPTY_B = Output(Bool())
}

class DACIO extends Bundle {
  val SCK = Input(Clock())
  val CS = Output(Bool())
  val SDI = Output(Bool())
  val LDAC = Output(Bool())

  val EN = Input(Bool())
  val BUF = Input(Bool())
  val GAIN_N = Input(Bool())
  val SHDN_N = Input(Bool())
  val DATA_IN = Input(new FP(12, 11))
}

class TopModule extends Module {
  val DFB1_ADC = IO(new ADCIO)
  val DFB1_DAC = IO(new DACIO)
  val dfb1_adc = Module(new ADC122S625Core(128))
  val dfb1_dac = Module(new MCP4921Core)

  dfb1_adc.io.sclk := DFB1_ADC.SCLK
  dfb1_adc.io.cs_n := DFB1_ADC.CS
  dfb1_adc.io.sdo := DFB1_ADC.DOUT

  dfb1_adc.io.gateIn := DFB1_ADC.GATE_IN
  dfb1_adc.io.gateOut := DFB1_ADC.GATE_OUT
  DFB1_ADC.DATA_A := dfb1_adc.io.dataA
  DFB1_ADC.DATA_B := dfb1_adc.io.dataB
  DFB1_ADC.FULL_A := dfb1_adc.io.fullA
  DFB1_ADC.FULL_B := dfb1_adc.io.fullB
  DFB1_ADC.EMPTY_A := dfb1_adc.io.emptyA
  DFB1_ADC.EMPTY_B := dfb1_adc.io.emptyB

  dfb1_dac.io.sclk := DFB1_DAC.SCK
  DFB1_DAC.SDI := dfb1_dac.io.sdi
  DFB1_DAC.CS := dfb1_dac.io.cs_n
  DFB1_DAC.LDAC := dfb1_dac.io.ldac_n

  dfb1_dac.io.en := DFB1_DAC.EN
  dfb1_dac.io.buf := DFB1_DAC.BUF
  dfb1_dac.io.gain_n := DFB1_DAC.GAIN_N
  dfb1_dac.io.shdn_n := DFB1_DAC.SHDN_N
  dfb1_dac.io.dataIn := DFB1_DAC.DATA_IN
}

object Top extends App {
  VerilogEmitter.parse(new TopModule, "top_module.sv")
}
