package net.arp

import net.eth._
import utils._
import chisel3._
import chisel3.util._

object ARPLookupState extends ChiselEnum {
  val IDLE     = Value(0.U(2.W))
  val SEND_REQ = Value(1.U(2.W))
  val WAIT     = Value(2.U(2.W))
}

class ARP(cache_entries: Int, send_timeout: Int = 100, wait_timeout: Int = 12500) extends Module {
  override def desiredName: String = "arp"

  val io = IO(new Bundle {
    val config = Input(new Bundle {
      val myMAC = UInt(48.W)
      val myIP  = UInt(32.W)
    })

    val request = Flipped(Decoupled(new Bundle {
      val targetIP = UInt(32.W)
    }))

    val response = Decoupled(new Bundle {
      val ip  = UInt(32.W)
      val mac = UInt(48.W)
    })

    val ethTx = Decoupled(new EthernetFrameIO)
    val ethRx = Flipped(Decoupled(new EthernetFrameIO))
  })

  val cache = Module(new ARPCache(cache_entries))
  val tx    = Module(new ARPTx)
  val rx    = Module(new ARPRx)

  tx.io.config      := io.config
  rx.io.config.myIP := io.config.myIP

  io.ethTx <> tx.io.ethTx
  io.ethRx <> rx.io.ethRx

  val state     = RegInit(ARPLookupState.IDLE)
  val pendingIP = RegInit(0.U(32.W))
  val timeout   = RegInit(0.U(24.W))

  val respValid = RegInit(false.B)
  val respIP    = RegInit(0.U(32.W))
  val respMAC   = RegInit(0.U(48.W))

  val replyPending = RegInit(false.B)
  val replyIP      = RegInit(0.U(32.W))
  val replyMAC     = RegInit(0.U(48.W))

  io.response.valid    := respValid
  io.response.bits.ip  := respIP
  io.response.bits.mac := respMAC

  when(io.response.fire) {
    respValid := false.B
  }

  io.request.ready := state === ARPLookupState.IDLE

  cache.io.lookup.valid := io.request.valid && io.request.ready
  cache.io.lookup.ip    := io.request.bits.targetIP

  cache.io.update.valid := rx.io.arpRx.fire
  cache.io.update.ip    := rx.io.arpRx.bits.senderIP
  cache.io.update.mac   := rx.io.arpRx.bits.senderMAC
  cache.io.clear        := false.B

  rx.io.arpRx.ready := true.B

  when(rx.io.arpRx.fire) {
    when(
      rx.io.arpRx.bits.operation === ARPOp.REQUEST &&
        rx.io.arpRx.bits.targetIP === io.config.myIP
    ) {
      replyPending := true.B
      replyIP      := rx.io.arpRx.bits.senderIP
      replyMAC     := rx.io.arpRx.bits.senderMAC
    }

    when(
      state === ARPLookupState.WAIT &&
        rx.io.arpRx.bits.operation === ARPOp.REPLY &&
        rx.io.arpRx.bits.senderIP === pendingIP
    ) {
      respValid := true.B
      respIP    := rx.io.arpRx.bits.senderIP
      respMAC   := rx.io.arpRx.bits.senderMAC
      state     := ARPLookupState.IDLE
    }
  }

  when(replyPending) {
    tx.io.arpTx.valid          := true.B
    tx.io.arpTx.bits.operation := ARPOp.REPLY
    tx.io.arpTx.bits.targetIP  := replyIP
    tx.io.arpTx.bits.targetMAC := replyMAC

    when(tx.io.arpTx.fire) {
      replyPending := false.B
    }
  }.elsewhen(state === ARPLookupState.SEND_REQ) {
    tx.io.arpTx.valid          := true.B
    tx.io.arpTx.bits.operation := ARPOp.REQUEST
    tx.io.arpTx.bits.targetIP  := pendingIP
    tx.io.arpTx.bits.targetMAC := 0.U
  }.otherwise {
    tx.io.arpTx.valid          := false.B
    tx.io.arpTx.bits.operation := 0.U
    tx.io.arpTx.bits.targetIP  := 0.U
    tx.io.arpTx.bits.targetMAC := 0.U
  }

  switch(state) {
    is(ARPLookupState.IDLE) {
      timeout := 0.U
      when(io.request.fire) {
        respValid := false.B

        pendingIP := io.request.bits.targetIP
        when(cache.io.lookup.found) {
          respValid := true.B
          respIP    := io.request.bits.targetIP
          respMAC   := cache.io.lookup.mac
        }.otherwise {
          state := ARPLookupState.SEND_REQ
        }
      }
    }

    is(ARPLookupState.SEND_REQ) {
      when(tx.io.arpTx.fire) {
        state   := ARPLookupState.WAIT
        timeout := 0.U
      }

      timeout := timeout + 1.U
      when(timeout > send_timeout.U) {
        state := ARPLookupState.IDLE
      }
    }

    is(ARPLookupState.WAIT) {
      timeout := timeout + 1.U
      when(timeout > wait_timeout.U) {
        state := ARPLookupState.IDLE
      }
    }
  }
}

object TestARP extends App {
  VerilogEmitter.parse(new ARP(16), "arp.sv")
}
