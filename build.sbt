ThisBuild / scalaVersion     := "2.13.16"
ThisBuild / version          := "0.1.0"
ThisBuild / organization     := "dashygo097"

val chiselVersion = "6.7.0"

lazy val utils = (project in file("src/utils"))
  .settings(
    name := "utils",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
      "org.scalatest" %% "scalatest" % "3.2.16" % "test",
      "edu.berkeley.cs" %% "chiseltest" % "6.0.0" % Test,
    ),
    scalacOptions ++= Seq(
      "-language:reflectiveCalls",
      "-deprecation",
      "-feature",
      "-unchecked",              // Enable additional warnings where generated code depends on assumptions
      "-Xlint", 
      "-Xcheckinit",
      "-Ymacro-annotations",
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )


lazy val dds = (project in file("src/dds"))
  .dependsOn(utils)
  .settings(
    name := "dds",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val fft = (project in file("src/fft"))
  .dependsOn(utils)
  .settings(
    name := "fft",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val fir = (project in file("src/fir"))
  .dependsOn(dds, utils)
  .settings(
    name := "fir",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val fm = (project in file("src/fm"))
  .dependsOn(utils, dds, fir)
  .settings(
    name := "fm",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val sampler = (project in file("src/sampler"))
  .dependsOn(utils)
  .settings(
    name := "sampler",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val pwm = (project in file("src/pwm"))
  .dependsOn(utils)
  .settings(
    name := "pwm",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val uart = (project in file("src/uart"))
  .dependsOn(utils)
  .settings(
    name := "uart",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val mem = (project in file("src/mem"))
  .dependsOn(utils)
  .settings(
    name := "mem",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val fmc = (project in file("src/fmc"))
  .dependsOn(utils, mem)
  .settings(
    name := "fmc",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val spi = (project in file("src/spi"))
  .dependsOn(utils, mem)
  .settings(
    name := "spi",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),                 
  )


lazy val app = (project in file("app"))
  .dependsOn(utils, dds, fft, fir, sampler, fm, pwm, uart, fmc, mem, spi)
  .settings(
    name := "app",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )


