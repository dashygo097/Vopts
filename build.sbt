ThisBuild / scalaVersion := "2.13.16"
ThisBuild / version      := "0.1.0"
ThisBuild / organization := "dashygo097"
ThisBuild / publishTo    := Some(Resolver.file("local-ivy", file(Path.userHome + "/.ivy2/local")))

val chiselVersion = "6.7.0"

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
      "org.chipsalliance" %% "chisel"     % chiselVersion,
      "org.scalatest"     %% "scalatest"  % "3.2.16" % "test",
      "edu.berkeley.cs"   %% "chiseltest" % "6.0.0"  % Test,
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val dds = (project in file("src/dds"))
  .dependsOn(utils)
  .settings(
    name := "dds",
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

lazy val mem = (project in file("src/mem"))
  .dependsOn(utils, com)
  .settings(
    name := "mem",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val perip = (project in file("src/perip"))
  .dependsOn(utils, mem)
  .settings(
    name := "perip",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val mod = (project in file("src/mod"))
  .dependsOn(utils, dds, dsp, math)
  .settings(
    name := "mod",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val app = (project in file("app"))
  .dependsOn(utils, perip, dds, dsp, mem, com, mod, math)
  .settings(
    name := "app",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )
