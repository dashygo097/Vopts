package dds.triangle

import utils._
import chisel3._

class TriangleCore(freq: Int, pha: Double) extends Module with Config {
  val io = IO(new SO(new FP)).suggestName("DDS_TRIANGLE")

}
