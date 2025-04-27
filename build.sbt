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

lazy val dsp = (project in file("src/dsp"))
  .dependsOn(utils)
  .settings(
    name := "dsp",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val mod = (project in file("src/mod"))
  .dependsOn(utils, dds, dsp)
  .settings(
    name := "mod",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val com = (project in file("src/com"))
  .dependsOn(utils, mem)
  .settings(
    name := "com",
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


lazy val app = (project in file("app"))
  .dependsOn(utils, dds, dsp, mem, com, mod)
  .settings(
    name := "app",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )





