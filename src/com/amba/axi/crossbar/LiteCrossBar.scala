package vopts.com.amba

import vopts.utils._
import chisel3._

class AXILiteCrossbar(
  addrWidth: Int,
  dataWidth: Int,
  numMasters: Int,
  addressMap: Seq[(Long, Long)]
) extends Module {
  override def desiredName: String =
    s"axilite_crossbar_${numMasters}x${addressMap.length}_${addrWidth}x$dataWidth"

  require(numMasters > 0, "Number of masters must be at least 1")
  require(addressMap.length > 0, "Address map must have at least one slave")

  val numSlaves = addressMap.length

  // External interfaces
  val slaves_ext  =
    IO(Vec(numSlaves, Flipped(new AXILiteSlaveExtIO(addrWidth, dataWidth)))).suggestName("M_AXI")
  val masters_ext =
    IO(Vec(numMasters, Flipped(new AXILiteMasterExtIO(addrWidth, dataWidth)))).suggestName("S_AXI")

  dontTouch(slaves_ext)
  dontTouch(masters_ext)

  // Instantiate arbiters (one per slave)
  val arbiters = Seq.fill(numSlaves)(Module(new AXILiteArbiter(addrWidth, dataWidth, numMasters)))

  // Instantiate interconnects (one per master)
  val interconnects = Seq.fill(numMasters)(Module(new AXILiteInterconnect(addrWidth, dataWidth, addressMap)))

  for (i <- 0 until numMasters)
    for (j <- 0 until numSlaves)
      arbiters(j).slaves_ext(i) <> interconnects(i).masters_ext(j)

  for (i <- 0 until numSlaves)
    slaves_ext(i) <> arbiters(i).master_ext

  for (i <- 0 until numMasters)
    interconnects(i).slave_ext <> masters_ext(i)
}

object AXILiteCrossbar {
  def apply(
    addrWidth: Int,
    dataWidth: Int,
    numMasters: Int,
    addressMap: Seq[(Long, Long)]
  ): AXILiteCrossbar =
    Module(new AXILiteCrossbar(addrWidth, dataWidth, numMasters, addressMap))
}

object TestAXILiteCrossbar extends App {
  VerilogEmitter.parse(
    new AXILiteCrossbar(
      32,
      32,
      3,
      Seq(
        (0x80000000L, 0x8000ffffL),
        (0x80010000L, 0x8001ffffL),
        (0x80020000L, 0x8002ffffL)
      )
    ),
    "axilite_crossbar.sv",
    info = true
  )
}
