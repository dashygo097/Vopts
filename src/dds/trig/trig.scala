package dds.trig

import scala.math._
import utils._
import chisel3._
import chisel3.util._

class TrigIO extends Bundle with Config {
  val mag = Input(new FP)
  val freqRatio = Input(new FP)
  val phaseDelta = Input(UInt(phaseWidth.W))
  val out = Output(new FP)
}

class TrigDDS(baseFreq: Int) extends Module with Config {
  override def desiredName = s"dds_trig_f${baseFreq}"
  val io = IO(new TrigIO).suggestName("DDS_TRI")
  val phase = RegInit(0.U(phaseWidth.W))
  val lutAddr = Wire(UInt(log2Ceil(lutWidth).W))


  val freqDelta = RegNext(io.freqRatio.value * baseFreq.S)
  val poffDeltaShifted = RegNext(freqDelta << phaseWidth >> io.out.bp())
  val poffDeltaScaled = RegNext(poffDeltaShifted * magic.U)
  val poffDelta = RegNext(poffDeltaScaled >> magicShift.U)

  val sine_rom = VecInit(
    (0 until lutWidth).map { i => 
      val angle = 2 * Pi * i / lutWidth
      val value = sin(angle)
      new FP(binaryPoint + 2, binaryPoint).fromDouble(value)
    }
  )

  phase := phase + io.phaseDelta + poffDelta.asUInt

  lutAddr := phase(phaseWidth - 1, phaseWidth - log2Ceil(lutWidth))
  val lutValue = sine_rom(lutAddr)
  io.out := lutValue * io.mag
}


