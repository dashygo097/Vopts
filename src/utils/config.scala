package utils

trait Config {
  // Overall config
  val clkFreq: Int = 100000000
  val dataWidth: Int = 32
  val binaryPoint: Int = 16

  // DDS config
  val sampleFreq: Int = clkFreq
  val lutWidth: Int = 256
  val phaseWidth: Int = 24

  // FFT Default Params
  val defaultFFTSize: Int = 128

  // Mod Default Params
  val defaultCarrierFreq: Int = 1000000 // 1MHz
  val defaultFMDeltaFreq: Int = 500000 // 500kHz

  // CORDIC Default Params
  val cordicIter: Int = 16
  val cordicAngleWidth: Int = 32
}
