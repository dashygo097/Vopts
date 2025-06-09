package app.guangsai

import peripheral.{ADC122S625Core, MCP4921Core}
import com.fsmc.FSMCSlaveRAMCore
import com.uart.UartCore
import app.VerilogEmitter

import utils._
import chisel3._
import chisel3.util._

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

class UARTIO extends Bundle {
  val TX = Output(Bool())
  val TX_CHANNEL = Flipped(Decoupled(UInt(8.W)))
  val TX_BUSY = Output(Bool())
  val RX = Input(Bool())
  val RX_CHANNEL = Decoupled(UInt(8.W))
  val RX_ERROR = Output(Bool())
}

class TopModule extends Module {

  // ControlFlow
  val uart = Module(new UartCore(115200))
  val UART = IO(new UARTIO)

  UART.TX := uart.io.tx.txd
  UART.TX_CHANNEL <> uart.io.tx.channel
  UART.TX_BUSY := uart.io.tx.busy
  uart.io.rx.rxd := UART.RX
  UART.RX_CHANNEL <> uart.io.rx.channel
  UART.RX_ERROR := uart.io.rx.error


  // ADC and DAC IOs
  val DFB1_ADC = IO(new ADCIO)
  val DFB2_ADC = IO(new ADCIO)
  val DFB3_ADC = IO(new ADCIO)
  val DFB4_ADC = IO(new ADCIO)
  val TEC1_ADC = IO(new ADCIO)
  val TEC2_ADC = IO(new ADCIO)
  val TEC3_ADC = IO(new ADCIO)
  val TEC4_ADC = IO(new ADCIO)

  val DFB1_DAC = IO(new DACIO)
  val DFB2_DAC = IO(new DACIO)
  val DFB3_DAC = IO(new DACIO)
  val DFB4_DAC = IO(new DACIO)
  val DFBM1_DAC = IO(new DACIO)
  val DFBM2_DAC = IO(new DACIO)
  val DFBM3_DAC = IO(new DACIO)
  val DFBM4_DAC = IO(new DACIO)
  val TEC1_DAC = IO(new DACIO)
  val TEC2_DAC = IO(new DACIO)
  val TEC3_DAC = IO(new DACIO)
  val TEC4_DAC = IO(new DACIO)

  // ADC and DAC modules
  val dfb1_adc = Module(new ADC122S625Core(64))
  val dfb2_adc = Module(new ADC122S625Core(64))
  val dfb3_adc = Module(new ADC122S625Core(64))
  val dfb4_adc = Module(new ADC122S625Core(64))
  val tec1_adc = Module(new ADC122S625Core(64))
  val tec2_adc = Module(new ADC122S625Core(64))
  val tec3_adc = Module(new ADC122S625Core(64))
  val tec4_adc = Module(new ADC122S625Core(64))

  val dfb1_dac = Module(new MCP4921Core)
  val dfb2_dac = Module(new MCP4921Core)
  val dfb3_dac = Module(new MCP4921Core)
  val dfb4_dac = Module(new MCP4921Core)
  val dfbm1_dac = Module(new MCP4921Core)
  val dfbm2_dac = Module(new MCP4921Core)
  val dfbm3_dac = Module(new MCP4921Core)
  val dfbm4_dac = Module(new MCP4921Core)
  val tec1_dac = Module(new MCP4921Core)
  val tec2_dac = Module(new MCP4921Core)
  val tec3_dac = Module(new MCP4921Core)
  val tec4_dac = Module(new MCP4921Core)

  def connectADC(adc: ADCIO, module: ADC122S625Core): Unit = {
    module.io.sclk := adc.SCLK
    module.io.cs_n := adc.CS
    module.io.sdo := adc.DOUT

    module.io.gateIn := adc.GATE_IN
    module.io.gateOut := adc.GATE_OUT
    adc.DATA_A := module.io.dataA
    adc.DATA_B := module.io.dataB
    adc.FULL_A := module.io.fullA
    adc.FULL_B := module.io.fullB
    adc.EMPTY_A := module.io.emptyA
    adc.EMPTY_B := module.io.emptyB
  }

  def connectDAC(dac: DACIO, module: MCP4921Core): Unit = {
    module.io.sclk := dac.SCK
    dac.SDI := module.io.sdi
    dac.CS := module.io.cs_n
    dac.LDAC := module.io.ldac_n

    module.io.en := dac.EN
    module.io.buf := dac.BUF
    module.io.gain_n := dac.GAIN_N
    module.io.shdn_n := dac.SHDN_N
    module.io.dataIn := dac.DATA_IN
  }

  connectADC(DFB1_ADC, dfb1_adc)
  connectADC(DFB2_ADC, dfb2_adc)
  connectADC(DFB3_ADC, dfb3_adc)
  connectADC(DFB4_ADC, dfb4_adc)
  connectADC(TEC1_ADC, tec1_adc)
  connectADC(TEC2_ADC, tec2_adc)
  connectADC(TEC3_ADC, tec3_adc)
  connectADC(TEC4_ADC, tec4_adc)

  connectDAC(DFB1_DAC, dfb1_dac)
  connectDAC(DFB2_DAC, dfb2_dac)
  connectDAC(DFB3_DAC, dfb3_dac)
  connectDAC(DFB4_DAC, dfb4_dac)
  connectDAC(DFBM1_DAC, dfbm1_dac)
  connectDAC(DFBM2_DAC, dfbm2_dac)
  connectDAC(DFBM3_DAC, dfbm3_dac)
  connectDAC(DFBM4_DAC, dfbm4_dac)
  connectDAC(TEC1_DAC, tec1_dac)
  connectDAC(TEC2_DAC, tec2_dac)
  connectDAC(TEC3_DAC, tec3_dac)
  connectDAC(TEC4_DAC, tec4_dac)
}

object Top extends App {
  VerilogEmitter.parse(new TopModule, "top_module.sv")
}
