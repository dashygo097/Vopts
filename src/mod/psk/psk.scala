package mod.psk

import utils._
import datatype.fp.FP
import dds.trig.{BaseTrigCore, CWCore}

import scala.math.pow
import chisel3._

class BPSKIO extends Bundle {
  val data = Input(Bool())
  val out = Output(new FP)
}

class BPSKCore(carrierFreq: Int) extends Module {
  val io = IO(new BPSKIO)
  val cw = Module(new CWCore(1.0, carrierFreq, 0.0))
  val zero = FP(0.0)

  io.out := Mux(io.data, cw.io.out, zero - cw.io.out)
}

class QPSKIO extends Bundle {
  val data = Input(UInt(2.W))
  val out = Output(new FP)
}

class QPSKCore(carrierFreq: Int) extends Module with Config {
  val io = IO(new QPSKIO)
  val trig = Module(new BaseTrigCore(carrierFreq))

  val deltaPhase = (pow(2.0, phaseWidth) / pow(2.0, 2)).toInt.U

  val last_data = RegInit(0.U(2.W))

  trig.io.mag := FP(1.0)
  trig.io.phaseDelta := 0.U

  when (io.data =/= last_data) {
    trig.io.phaseDelta := deltaPhase * (io.data - last_data)
    last_data := io.data
  }

  io.out := trig.io.out
}

class nPSKIO(dw: Int) extends Bundle {
  val data = Input(UInt(dw.W))
  val out = Output(new FP)
}

class nPSKCore(carrierFreq: Int, dw: Int) extends Module with Config {
  val io = IO(new nPSKIO(dw))
  val trig = Module(new BaseTrigCore(carrierFreq))
  
  val deltaPhase = (pow(2.0, phaseWidth) / pow(2.0, dw)).toInt.U
  val last_data = RegInit(0.U(dw.W))

  trig.io.mag := FP(1.0)
  trig.io.phaseDelta := 0.U

  when (io.data =/= last_data) {
    trig.io.phaseDelta := deltaPhase * (io.data - last_data)
    last_data := io.data
  }

  io.out := trig.io.out
}
