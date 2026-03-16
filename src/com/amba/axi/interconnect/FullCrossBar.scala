package vopts.com.amba

import vopts.utils._
import chisel3._

class AXIFullCrossbar(
  addrWidth: Int,
  dataWidth: Int,
  idWidth: Int,
  numMasters: Int,
  addressMap: Seq[(Long, Long)],
  arbiterFifoDepth: Int = 4,
  userWidth: Int = 0
) extends Module {
  override def desiredName: String =
    s"axifull_crossbar_${numMasters}x${addressMap.length}_${addrWidth}x$dataWidth"

  require(numMasters > 0, "Number of masters must be at least 1")
  require(addressMap.length > 0, "Address map must have at least one slave")

  val numSlaves = addressMap.length

  // External interfaces
  val slaves_ext  =
    IO(Vec(numSlaves, Flipped(new AXIFullSlaveExtIO(addrWidth, dataWidth, idWidth, userWidth)))).suggestName("M_AXI")
  val masters_ext =
    IO(Vec(numMasters, Flipped(new AXIFullMasterExtIO(addrWidth, dataWidth, idWidth, userWidth)))).suggestName("S_AXI")

  dontTouch(slaves_ext)
  dontTouch(masters_ext)

  // Instantiate arbiters (one per slave)
  val arbiters = Seq.fill(numSlaves)(Module(new AXIFullArbiter(addrWidth, dataWidth, idWidth, numMasters, arbiterFifoDepth)))

  // Instantiate interconnects (one per master)
  val interconnects = Seq.fill(numMasters)(Module(new AXIFullDecoder(addrWidth, dataWidth, idWidth, userWidth, addressMap)))

  for (i <- 0 until numMasters)
    for (j <- 0 until numSlaves)
      arbiters(j).slaves_ext(i) <> interconnects(i).masters_ext(j)

  for (i <- 0 until numSlaves)
    slaves_ext(i) <> arbiters(i).master_ext

  for (i <- 0 until numMasters)
    interconnects(i).slave_ext <> masters_ext(i)
}

object AXIFullCrossbar {
  def apply(
    addrWidth: Int,
    dataWidth: Int,
    idWidth: Int,
    numMasters: Int,
    addressMap: Seq[(Long, Long)],
    arbiterFifoDepth: Int = 4
  ): AXIFullCrossbar =
    Module(new AXIFullCrossbar(addrWidth, dataWidth, idWidth, numMasters, addressMap, arbiterFifoDepth))
}

object TestAXIFullCrossbar extends App {
  VerilogEmitter.parse(
    new AXIFullCrossbar(
      32,
      32,
      4,
      3,
      Seq(
        (0x80000000L, 0x8000ffffL),
        (0x80010000L, 0x8001ffffL),
        (0x80020000L, 0x8002ffffL)
      ),
      4
    ),
    "axifull_crossbar.sv",
    info = true
  )
}
