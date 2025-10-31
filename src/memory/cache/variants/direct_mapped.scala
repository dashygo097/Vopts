package mem.cache

import utils._
import chisel3._
import chisel3.util._

class DirectMappedCache[T <: Data](
  gen: T, 
  addrWidth: Int, 
  lineSize: Int, 
  numLines: Int
) extends Module {
  override def desiredName: String = 
    s"direct_mapped_cache_a${addrWidth}_l${lineSize}x${numLines}"
  
  val ext_io = IO(new CacheExternalIO(gen, addrWidth)).suggestName("CACHE")
  val io = Wire(new CacheIO(gen, addrWidth))

  val tagWidth    = addrWidth - log2Ceil(numLines) - log2Ceil(lineSize/4)
  val indexWidth  = log2Ceil(numLines)
  val offsetWidth = log2Ceil(lineSize/4)

  val cacheArray = SyncReadMem(numLines, new CacheEntry(gen, tagWidth))

  val index   = io.addr(indexWidth + offsetWidth - 1, offsetWidth)
  val addrTag = io.addr(addrWidth - 1, indexWidth + offsetWidth)

  // Pipeline registers
  val index_r       = RegNext(index)
  val addrTag_r     = RegNext(addrTag)
  val write_en_r    = RegNext(io.write_en)
  val write_data_r  = RegNext(io.write_data)
  val read_en_r     = RegNext(io.read_en)

  val memReadEn = (io.read_en || io.write_en) && !reset.asBool
  val readData = cacheArray.read(index, memReadEn)

  val validHit = readData.valid && (readData.tag === addrTag_r)
  io.miss := read_en_r && !validHit
  
  io.read_data := readData.data

  // Write logic
  when(write_en_r) {
    val writeEntry = Wire(new CacheEntry(gen, tagWidth))
    writeEntry.valid := true.B
    writeEntry.tag   := addrTag_r
    writeEntry.data  := write_data_r
    
    cacheArray.write(index_r, writeEntry)
  }

  ext_io.connect(io)
}

object DirectMappedCache {
  def apply[T <: Data](
    gen: T, 
    addrWidth: Int, 
    lineSize: Int, 
    numLines: Int
  ): CacheIO[T] = {
    val cache = Module(new DirectMappedCache(gen, addrWidth, lineSize, numLines))
    cache.io
  }
}

object TestDirectMappedCache extends App {
  VerilogEmitter.parse(
    new DirectMappedCache(UInt(32.W), 32, 16, 64),
    "direct_mapped_cache.sv",
    info = true
  )
}


