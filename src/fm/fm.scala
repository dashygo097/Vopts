package fm
import utils.{Float, Config, DataWrapper}

import scala.math._

import chisel3._
import chisel3.util._

class FMIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class ModFMIO extends Bundle {
  val mod = Input(new Float)
  val in = Input(new Float)
  val out = Output(new Float)
}

class FMCore(carrierFreq: Int, deltaFreq: Int) extends Module with Config {
  val io = IO(new FMIO)
  val trig = Module(new dds.TrigCore(carrierFreq))

  val deviationFactor = (pow(2.0, phaseWidth) / sampleFreq * deltaFreq).toInt
  val deviation = ((io.in.value * deviationFactor.S) >> bp)(phaseWidth - 1, 0).asUInt

  trig.io.mag := (new Float).fromDouble(1.0)
  trig.io.phaseDelta := DataWrapper(deviation) // Convert combitional signal to sequential signal 

  io.out := trig.io.out
}

class ModFMCore(carrierFreq: Int, deltaFreq: Int) extends Module with Config {
  val io = IO(new ModFMIO)
  val sine = Module(new dds.SineCore(carrierFreq))

  val deviationFactor = (pow(2.0, phaseWidth) / sampleFreq * deltaFreq).toInt
  val deviation = ((io.in.value * deviationFactor.S) >> bp)(phaseWidth - 1, 0).asUInt

  sine.io.mag := (new Float).fromDouble(1.0)
  sine.io.freqRatio := io.mod
  sine.io.phaseDelta := DataWrapper(deviation) // Convert combitional signal to sequential signal 

  io.out := sine.io.out


}
