# Vopts

A lib impled in chisel/scala for generating (system)Verilog of some operators and modules for my learning projects. (still under dev) <br>

NOTE: THIS REPO IS ONLY FOR PERSONAL USAGE.

## Prerequisite

For code generating:

- sbt version in this project: 1.9.7 (see project/build.properties)
- see chisel/scala version in build.sbt

For autotest:

- gtkwave(waveform visualization)
- verilator(generating executable files for testbench)

## How to use

To generate systemVerilog, write demos under app/, and run

```
sbt app/run
```

Or simply run

```
sbt
```

to start a sbt server.

## Run Test

Run test using verilator(Verilator 5.034 2025-02-24 rev UNKNOWN.REV) and gtkwave(GTKWave Analyzer v3.4.0 (w)1999-2022 BSI) through ./test.sh and fzf.

```
./test.sh
```

Make sure that the tb file located in build/ and to end with xxx_tb.v(or xxx_tb.sv) and dumpfiles are named as xxx.vcd

## References

Some code references

[chisel-template](https://github.com/chipsalliance/chisel-template.git) <br>
[FFT](https://github.com/IA-C-Lab-Fudan/Chisel-FFT-generator.git)
