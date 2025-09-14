package dds.triangle

import utils._
import chisel3._
import scala.math.Pi

class TriangleDDS(freq: Int, pha: Double) extends Module with Config {
  override def desiredName = s"dds_triangle_f${freq}_p${(pha * 180 / Pi).toInt}}"
  val io = IO(new SO(new FP)).suggestName("DDS_TRIANGLE")
}
