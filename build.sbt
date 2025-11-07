ThisBuild / scalaVersion := "2.13.16"
ThisBuild / version      := "0.1.0"
ThisBuild / organization := "dashygo097"
ThisBuild / publishTo    := Some(
  Resolver.file("local-ivy", file(Path.userHome + "/.ivy2/local"))
)

val chiselVersion = "7.0.0"

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
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
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
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val com = (project in file("src/com"))
  .dependsOn(utils)
  .settings(
    name := "com",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val dsp = (project in file("src/dsp"))
  .dependsOn(utils, math)
  .settings(
    name := "dsp",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val mem = (project in file("src/memory"))
  .dependsOn(utils, com)
  .settings(
    name := "mem",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val perip = (project in file("src/peripherals"))
  .dependsOn(utils, mem)
  .settings(
    name := "perip",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val net = (project in file("src/network"))
  .dependsOn(utils, com, mem)
  .settings(
    name := "net",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val mod = (project in file("src/modulation"))
  .dependsOn(utils, dds, dsp, math)
  .settings(
    name := "mod",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val app = (project in file("app"))
  .dependsOn(utils, perip, dds, dsp, mem, com, mod, net, math)
  .settings(
    name := "app",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
    ),
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin(
      "org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full
    ),
  )

lazy val root = (project in file("."))
  .aggregate(utils, dds, math, com, dsp, mem, perip, net, mod)
