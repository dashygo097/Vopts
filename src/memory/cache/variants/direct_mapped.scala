package mem.cache

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
  // Parameters
  val bytesPerWord = dataWidth / 8
  val wordsPerLine = lineSize / bytesPerWord
  val tagWidth     = addrWidth - log2Ceil(numLines) - log2Ceil(wordsPerLine) - log2Ceil(bytesPerWord)
  val byteOffWidth = log2Ceil(bytesPerWord)
  val offsetWidth  = log2Ceil(wordsPerLine)
  val indexWidth   = log2Ceil(numLines)
  
  val ext_io = IO(new CacheExternalIO(addrWidth, dataWidth, wordsPerLine)).suggestName("CACHE")
  val io = Wire(new CacheIO(addrWidth, dataWidth, wordsPerLine))
  
  val tagValidArray = SyncReadMem(numLines, UInt((tagWidth + 1).W)).suggestName("tag_valid_array")
  val dataArrays = Seq.fill(wordsPerLine)(SyncReadMem(numLines, UInt(dataWidth.W)).suggestName("data_array"))
  
  val wordOffset = io.addr(byteOffWidth + offsetWidth - 1, byteOffWidth)
  val index      = io.addr(byteOffWidth + offsetWidth + indexWidth - 1, byteOffWidth + offsetWidth)
  val addrTag    = io.addr(addrWidth - 1, byteOffWidth + offsetWidth + indexWidth)
  
  // Pipeline registers
  val wordOffset_r = RegNext(wordOffset)
  val index_r      = RegNext(index)
  val addrTag_r    = RegNext(addrTag)
  val write_en_r   = RegNext(io.write_en)
  val write_data_r = RegNext(io.write_data)
  val read_en_r    = RegNext(io.read_en)
  
  // Read tag/valid 
  val readTagValid = tagValidArray.read(index, io.read_en || io.write_en)
  
  // Read data word
  val readDataWords = VecInit(dataArrays.zipWithIndex.map { case (mem, i) =>
    mem.read(index, (io.read_en || io.write_en) && wordOffset === i.U)
  })
  
  // Hit detection
  val readTag = readTagValid(tagWidth, 1)
  val readValid = readTagValid(0)
  val validHit = readValid && (readTag === addrTag_r)
  
  io.miss := read_en_r && !validHit
  io.read_data := readDataWords(wordOffset_r)
  
  // Write logic
  when(write_en_r) {
    val writeTagValid = Cat(addrTag_r, true.B)
    tagValidArray.write(index_r, writeTagValid)
    
    for (i <- 0 until wordsPerLine) {
      val wordData = write_data_r((i + 1) * dataWidth - 1, i * dataWidth)
      dataArrays(i).write(index_r, wordData)
    }
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
