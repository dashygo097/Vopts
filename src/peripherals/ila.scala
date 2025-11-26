package perip

import utils._
import chisel3._

class ILAProbes(probeWidth: Int, numProbes: Int) extends Bundle {
  val probes = IO(Vec(numProbes, Input(UInt(probeWidth.W))))
}
