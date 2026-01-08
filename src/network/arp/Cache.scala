package vopts.net.arp

import chisel3._
import chisel3.util._

class ARPCacheEntry extends Bundle {
  val valid = Bool()
  val ip    = UInt(32.W)
  val mac   = UInt(48.W)
  val age   = UInt(16.W)
}

class ARPCache(entries: Int) extends Module {
  override def desiredName: String = "arp_cache"

  val io = IO(new Bundle {
    val lookup = new Bundle {
      val valid = Input(Bool())
      val ip    = Input(UInt(32.W))
      val found = Output(Bool())
      val mac   = Output(UInt(48.W))
    }

    val update = new Bundle {
      val valid = Input(Bool())
      val ip    = Input(UInt(32.W))
      val mac   = Input(UInt(48.W))
    }

    val clear = Input(Bool())
  })

  val cache      = RegInit(VecInit(Seq.fill(entries)(0.U.asTypeOf(new ARPCacheEntry))))
  val ageCounter = RegInit(0.U(16.W))

  ageCounter := ageCounter + 1.U

  // Lookup
  val lookupHit = Wire(Bool())
  val lookupMAC = Wire(UInt(48.W))

  lookupHit := false.B
  lookupMAC := 0.U

  for (i <- 0 until entries)
    when(cache(i).valid && cache(i).ip === io.lookup.ip) {
      lookupHit := true.B
      lookupMAC := cache(i).mac
    }

  io.lookup.found := lookupHit
  io.lookup.mac   := lookupMAC

  // Update
  when(io.update.valid) {
    val updateHit = Wire(Bool())
    val updateIdx = Wire(UInt(log2Ceil(entries).W))

    updateHit := false.B
    updateIdx := 0.U

    for (i <- 0 until entries)
      when(cache(i).valid && cache(i).ip === io.update.ip) {
        updateHit := true.B
        updateIdx := i.U
      }

    when(updateHit) {
      cache(updateIdx).mac := io.update.mac
      cache(updateIdx).age := ageCounter
    }.otherwise {
      val victimIdx  = Wire(UInt(log2Ceil(entries).W))
      val hasInvalid = Wire(Bool())

      hasInvalid := VecInit(cache.map(!_.valid)).asUInt.orR

      victimIdx := 0.U
      when(!cache(0).valid) {
        victimIdx := 0.U
      }.otherwise {
        var oldestAge = cache(0).age
        var oldestIdx = 0.U

        for (i <- 1 until entries)
          when(!cache(i).valid) {
            victimIdx := i.U
          }.elsewhen(cache(i).age < oldestAge) {
            oldestAge = cache(i).age
            oldestIdx = i.U
          }

        when(!hasInvalid) {
          victimIdx := oldestIdx
        }
      }

      cache(victimIdx).valid := true.B
      cache(victimIdx).ip    := io.update.ip
      cache(victimIdx).mac   := io.update.mac
      cache(victimIdx).age   := ageCounter
    }
  }

  when(io.clear) {
    for (i <- 0 until entries)
      cache(i).valid := false.B
  }
}
