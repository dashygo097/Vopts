package dds

import chisel3._
import chisel3.util._

trait Config extends global.Config {
  val sampleFreq: Int = clkFreq
  val lutWidth: Int = 256
  val phaseWidth: Int = 24
}
