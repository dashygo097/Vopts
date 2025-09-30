# Vopts

#### A generative hardware library impled in chisel for common (system)verilog modules

###### **NOTE: THIS REPO IS STILL UNDER DEVELOPMENT AND TARGETED FOR MY PERSONAL USAGE**

## Prerequisite

#### For code generation:

- sbt version in this project: 1.10.11 (see **project/build.properties**)
- see chisel/scala version in **build.sbt**
- For FIR/IIR, scipy is used.

#### For autotest:

##### For regular autotest impled in verilog:

- gtkwave / surfer (waveform visualization)
- verilator (generating executable files for testbench)
- fzf(optional)

##### For cocotb autotest impled in python:

- icarus & cocotb (only tested under cocotb 1.9.2)
- fzf (optional)

## How to use

To generate systemVerilog, write demos under **app/...** , and run

> ```bash
> make run
> ```

or

> ```bash
> sbt app/run
> ```

**ALSO**, the global params can be changed in **src/utils/config.scala**

## Run Autotest

Run test using **verilator**(Verilator 5.034 2025-02-24 rev UNKNOWN.REV) and **gtkwave**(GTKWave Analyzer v3.4.0 (w)1999-2022 BSI) through **tb.sh(or fzf version tb_fzf.sh).**

> ```bash
> make tb # (make tb-fzf)
> ```

Make sure that the tb file located in **testbench/tb** <br>

or using

> ```bash
> make cocotb # (make cocotb-fzf)
> ```

for cocotb

Similarly, make sure that the py scripts are located in **testbench/cocotb**

###### All the related scripts can be found in scripts/

## References

#### Some code references:

> [chisel-template](https://github.com/chipsalliance/chisel-template.git) <br> [FFT](https://github.com/IA-C-Lab-Fudan/Chisel-FFT-generator.git) <br> [AXI-IF](https://github.com/maltanar/axi-in-chisel)
