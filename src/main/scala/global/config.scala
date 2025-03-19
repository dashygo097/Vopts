package global

import chisel3._
import chisel3.util._

trait Config {
  val clkFreq: Int = 100000000
  val dataWidth: Int = 32
  val bp: Int = 20
}
