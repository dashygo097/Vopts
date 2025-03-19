package fm

import chisel3._
import chisel3.util._


trait Config extends dds.Config {
  val carrierFreq: Int = 1000000
  val deltaFreq: Int = 10000
}
