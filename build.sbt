ThisBuild / scalaVersion := "2.13.16"
ThisBuild / version      := "0.1.0"
ThisBuild / organization := "dashygo097"
ThisBuild / publishTo    := Some(
  Resolver.file("local-ivy", file(Path.userHome + "/.ivy2/local"))
)

val chiselVersion = "7.0.0"
val hardfloatVersion = "1.5-SNAPSHOT"

ThisBuild / scalacOptions ++= Seq(
  "-language:reflectiveCalls",
  "-deprecation",
  "-feature",
  "-unchecked",
  "-Xlint",
  "-Xcheckinit",
  "-Ymacro-annotations"
)

lazy val utils = (project in file("src/utils"))
  .settings(
    name := "utils",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
      "edu.berkeley.cs" %% "hardfloat" % hardfloatVersion,
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val math = (project in file("src/math"))
  .dependsOn(utils)
  .settings(
    name := "math",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val com = (project in file("src/com"))
  .dependsOn(utils)
  .settings(
    name := "com",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val dsp = (project in file("src/dsp"))
  .dependsOn(utils, math)
  .settings(
    name := "dsp",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val mem = (project in file("src/memory"))
  .dependsOn(utils, com)
  .settings(
    name := "mem",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val perip = (project in file("src/peripherals"))
  .dependsOn(utils, mem)
  .settings(
    name := "perip",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val net = (project in file("src/network"))
  .dependsOn(utils, com, mem)
  .settings(
    name := "net",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val app = (project in file("app"))
  .dependsOn(utils, perip, dsp, mem, com, net, math)
  .settings(
    name := "app",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val root = (project in file("."))
  .aggregate(utils, math, com, dsp, mem, perip, net)
