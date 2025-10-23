package mod.psk

import dds.trig._
import utils._
import chisel3._
import scala.math._

class BPSKIO[T <: Data](gen: T) extends Bundle {
  val data = Input(Bool())
  val out  = Output(gen)
}

class BPSK[T <: Data](gen: T)(carrierFreq: Int, phaseWidth: Int, lutWidth: Int, clkFreq: Int)(
  implicit analog: Analog[T]
) extends Module {
  override def desiredName = s"bpsk_cf$carrierFreq"
  val io                   = IO(new BPSKIO(gen)).suggestName("BPSK")
  val cw                   = Module(new CWDDS(gen, 1.0, carrierFreq, 0.0, phaseWidth, lutWidth, clkFreq))
  val zero                 = gen.fromDouble(0.0)

  io.out := Mux(io.data, cw.io.out, zero - cw.io.out)
}

class QPSKIO[T <: Data](gen: T) extends Bundle {
  val data = Input(UInt(2.W))
  val out  = Output(gen)
}

class QPSK[T <: Data](gen: T, carrierFreq: Int, phaseWidth: Int, lutWidth: Int, clkFreq: Int)(
  implicit analog: Analog[T]
) extends Module {
  override def desiredName = s"qpsk_cf$carrierFreq"
  val io                   = IO(new QPSKIO(gen)).suggestName("QPSK")
  val trig                 = Module(new LiteTrigDDS(gen, carrierFreq, phaseWidth, lutWidth, clkFreq))

  val deltaPhase = (pow(2.0, phaseWidth) / pow(2.0, 2)).toInt.U

  val last_data = RegInit(0.U(2.W))

  trig.io.mag        := gen.fromDouble(1.0)
  trig.io.phaseDelta := 0.U

  when(io.data =/= last_data) {
    trig.io.phaseDelta := deltaPhase * (io.data - last_data)
    last_data          := io.data
  }

  io.out := trig.io.out
}

class nPSKIO[T <: Data](gen: T, dw: Int) extends Bundle {
  val data = Input(UInt(dw.W))
  val out  = Output(gen)
}

class nPSK[T <: Data](gen: T)(
  carrierFreq: Int,
  dw: Int,
  phaseWidth: Int,
  lutWidth: Int,
  clkFreq: Int
)(implicit analog: Analog[T])
    extends Module {
  override def desiredName = s"psk_n${dw}_cf$carrierFreq"
  val io                   = IO(new nPSKIO(gen, dw)).suggestName("nPSK")
  val trig                 = Module(new LiteTrigDDS(gen, carrierFreq, phaseWidth, lutWidth, clkFreq))

  val deltaPhase = (pow(2.0, phaseWidth) / pow(2.0, dw)).toInt.U
  val last_data  = RegInit(0.U(dw.W))

  trig.io.mag        := gen.fromDouble(1.0)
  trig.io.phaseDelta := 0.U

  when(io.data =/= last_data) {
    trig.io.phaseDelta := deltaPhase * (io.data - last_data)
    last_data          := io.data
  }

  io.out := trig.io.out
}
