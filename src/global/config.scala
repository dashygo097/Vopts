package global

import chisel3._
import chisel3.util._

trait Config {
  // Overall config
  val clkFreq: Int = 100000000
  val dataWidth: Int = 32
  val bp: Int = 20

  // DDS config
  val sampleFreq: Int = clkFreq
  val lutWidth: Int = 256
  val phaseWidth: Int = 24
}
