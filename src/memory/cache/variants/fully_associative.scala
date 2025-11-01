package mem.cache

import utils._
import chisel3._
import chisel3.util._

/*
 *
 *package mem.cache

import utils._
import chisel3._
import chisel3.util._

class DirectMappedCache(
  addrWidth: Int,
  dataWidth: Int,
  lineSize: Int,
  numLines: Int
) extends Module {
  override def desiredName: String =
    s"direct_mapped_cache_${addrWidth}x${dataWidth}_l${lineSize}x$numLines"

  val ext_io = IO(new CacheExternalIO(addrWidth, dataWidth)).suggestName("CACHE")
  val io     = Wire(new CacheIO(addrWidth, dataWidth))

  // Parameters
  val bytesPerWord = dataWidth / 8
  val tagWidth     = addrWidth - log2Ceil(numLines) - log2Ceil(lineSize / bytesPerWord)
  val indexWidth   = log2Ceil(numLines)
  val offsetWidth  = log2Ceil(lineSize / bytesPerWord)

  val cacheArray = SyncReadMem(numLines, new CacheEntry(dataWidth, tagWidth))

  val index   = io.addr(indexWidth + offsetWidth - 1, offsetWidth)
  val addrTag = io.addr(addrWidth - 1, indexWidth + offsetWidth)

  // Pipeline registers
  val index_r      = RegNext(index)
  val addrTag_r    = RegNext(addrTag)
  val write_en_r   = RegNext(io.write_en)
  val write_data_r = RegNext(io.write_data)
  val read_en_r    = RegNext(io.read_en)

  val readData = cacheArray.read(index, io.read_en || io.write_en)

  val validHit = readData.valid && (readData.tag === addrTag_r)
  io.miss := read_en_r && !validHit

  io.read_data := readData.data

  // Write logic
  when(write_en_r) {
    val writeEntry = Wire(new CacheEntry(dataWidth, tagWidth))
    writeEntry.valid := true.B
    writeEntry.tag   := addrTag_r
    writeEntry.data  := write_data_r

    cacheArray.write(index_r, writeEntry)
  }

  ext_io.connect(io)
}

object TestDirectMappedCache extends App {
  VerilogEmitter.parse(
    new DirectMappedCache(32, 32, 16, 64),
    "direct_mapped_cache.sv",
    info = true
  )
}
 */

class FullyAssociativeCache(addrWidth: Int, dataWidth: Int, lineSize: Int, numLines: Int) extends Module {
  override def desiredName: String =
    s"fully_associative_cache_${addrWidth}x${dataWidth}_l${lineSize}x$numLines"

  val ext_io = IO(new CacheExternalIO(addrWidth, dataWidth))
  val io     = Wire(new CacheIO(addrWidth, dataWidth))

  // Parameters
  val bytesPerWord = dataWidth / 8
  val tagWidth     = addrWidth - log2Ceil(lineSize / bytesPerWord)
  val offsetWidth  = log2Ceil(lineSize / bytesPerWord)

  val cacheArray = SyncReadMem(numLines, new CacheEntry(dataWidth, tagWidth))

  val addrTag = io.addr(addrWidth - 1, offsetWidth)

  // Pipeline registers
  val addrTag_r    = RegNext(addrTag)
  val write_en_r   = RegNext(io.write_en)
  val write_data_r = RegNext(io.write_data)
  val read_en_r    = RegNext(io.read_en)

  // Read logic
  val readDataVec = Wire(Vec(numLines, new CacheEntry(dataWidth, tagWidth)))
  for (i <- 0 until numLines)
    readDataVec(i) := cacheArray.read(i.U, io.read_en || io.write_en)
}
