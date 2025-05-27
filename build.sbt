ThisBuild / scalaVersion     := "2.13.16"
ThisBuild / version          := "0.1.0"
ThisBuild / organization     := "dashygo097"

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
      "org.chipsalliance" %% "chisel" % chiselVersion,
      "org.scalatest" %% "scalatest" % "3.2.16" % "test",
      "edu.berkeley.cs" %% "chiseltest" % "6.0.0" % Test,
      "org.scalanlp" %% "breeze" % "2.1.0",
      "org.scalanlp" %% "breeze-viz" % "2.1.0"
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

lazy val func = (project in file("src/func"))
  .dependsOn(utils)
  .settings(
    name := "func",
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

lazy val dsp = (project in file("src/dsp"))
  .dependsOn(utils, func)
  .settings(
    name := "dsp",
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

lazy val peripheral = (project in file("src/peripheral"))
  .dependsOn(utils, mem)
  .settings(
    name := "peripheral",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )


lazy val mod = (project in file("src/mod"))
  .dependsOn(utils, dds, dsp, func)
  .settings(
    name := "mod",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )


lazy val app = (project in file("app"))
  .dependsOn(utils, peripheral, dds, dsp, mem, com, mod, func)
  .settings(
    name := "app",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )

lazy val test = (project in file("test"))
  .dependsOn(utils, peripheral, dds, dsp, mem, com, mod, func, app)
  .settings(
    name := "test",
    Compile / unmanagedSourceDirectories += baseDirectory.value,
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )



