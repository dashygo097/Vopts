ThisBuild / scalaVersion     := "2.13.16"
ThisBuild / version          := "0.1.0"
ThisBuild / organization     := "dashygo097"

val chiselVersion = "6.7.0"

lazy val global = (project in file("src/global"))
  .settings(
    name := "global",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
      "org.scalatest" %% "scalatest" % "3.2.16" % "test",
      "edu.berkeley.cs" %% "chiseltest" % "6.0.0" % Test,
    ),
    scalacOptions ++= Seq(
      "-language:reflectiveCalls",
      "-deprecation",
      "-feature",
      "-Xcheckinit",
      "-Ymacro-annotations",
    ),
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )


lazy val dds = (project in file("src/dds"))
  .dependsOn(global)
  .settings(
    name := "dds",
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val fft = (project in file("src/fft"))
  .dependsOn(global)
  .settings(
    name := "fft",
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val fir = (project in file("src/fir"))
  .dependsOn(dds, global)
  .settings(
    name := "fir",
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val fm = (project in file("src/fm"))
  .dependsOn(global, dds, fir)
  .settings(
    name := "fm",
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val sampler = (project in file("src/sampler"))
  .dependsOn(global, dds)
  .settings(
    name := "sampler",
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val app = (project in file("app"))
  .dependsOn(global, dds, fft, fir, sampler, fm)
  .settings(
    name := "app",
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )


