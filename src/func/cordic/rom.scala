package func.cordic

import utils._
import datatype.fp.FP

import chisel3._
import scala.math._

class CordicIO extends Bundle {
  val in = Input(new FP)
  val start = Input(Bool())
  val out = Output(new FP)
  val done = Output(Bool())
}

object CordicLUT extends Config {
  def atan_rom() : Seq[FP] = {
    (0 until cordicIter).map { i =>
      val angle = atan(pow(2, -i))
      val angleFP = FP(angle)
      angleFP
    }
  }

  def gain_rom() : Seq[FP] = {
    (0 until cordicIter).map { i =>
      val gain = 1 / sqrt(1 + pow(2, -2 * i))
      val gainFP = FP(gain)
      gainFP
    }
  }
}



