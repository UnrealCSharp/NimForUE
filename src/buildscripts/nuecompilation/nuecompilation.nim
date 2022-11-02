#Host guest (which will be renamed as plugin) and the game will be compiled from this file. Nue will use functions from here. 
#We may extrac the compilation option to another file since there are a lot of platforms. 

import std / [ options, os, osproc, parseopt, sequtils, strformat, strutils, sugar, tables, times ]
import buildscripts/[buildcommon, buildscripts, nimforueconfig]
import ../switches/switches
let config = getNimForUEConfig()



proc compileHost*() = 
#generateFFIGenFile(config) # this is currently generated by nue g, but it should be generated by host itself here!
  doAssert(fileExists("./src/hostnimforue/ffigen.nim"), "Please run: nue g")

  let buildFlags = @[buildSwitches, targetSwitches, hostPlatformSwitches].foldl(a & " " & b.join(" "), "")
  doAssert(execCmd(&"nim cpp {buildFlags} --header:NimForUEFFI.h --threads --tlsEmulation:off --app:lib --nomain --d:host --nimcache:.nimcache/host src/hostnimforue/hostnimforue.nim") == 0)
  # copy header
  let ffiHeaderSrc = ".nimcache/host/NimForUEFFI.h"
  let ffiHeaderDest = "NimHeaders/NimForUEFFI.h"
  copyFile(ffiHeaderSrc, ffiHeaderDest)
  log("Copied " & ffiHeaderSrc & " to " & ffiHeaderDest)

  # copy lib
  let libDir = "./Binaries/nim"
  let libDirUE = libDir / "ue"
  createDir(libDirUE)

  let hostLibName = "hostnimforue"
  let baseFullLibName = getFullLibName(hostLibName)
  let fileFullSrc = libDir/baseFullLibName
  let fileFullDst = libDirUE/baseFullLibName

  try:
    copyFile(fileFullSrc, fileFullDst)
  except OSError as e:
    when defined windows: # This will fail on windows if the host dll is in use.
      quit("Error copying to " & fileFullDst & ". " & e.msg, QuitFailure)

  log("Copied " & fileFullSrc & " to " & fileFullDst)

  when defined windows:
    let weakSymbolsLib = hostLibName & ".lib"
    copyFile(libDir/weakSymbolsLib, libDirUE/weakSymbolsLib)
  elif defined macosx: #needed for dllimport in ubt mac only
    let dst = "/usr/local/lib" / baseFullLibName
    copyFile(fileFullSrc, dst)
    log("Copied " & fileFullSrc & " to " & dst)




proc compilePlugin*(extraSwitches:seq[string]) =
  generateFFIGenFile(config)
  let bindingPrefix =
    "-d:BindingPrefix=.nimcache/gencppbindings/@m..@snimforue@sunreal@sbindings@sexported@s"
  
  let buildFlags = @[buildSwitches, targetSwitches, ueincludes, uesymbols, pluginPlatformSwitches, extraSwitches].foldl(a & " " & b.join(" "), "")
  let compCmd = &"nim cpp {buildFlags} {bindingPrefix} --app:lib --nomain --d:genffi -d:withPCH --nimcache:.nimcache/guest src/nimforue.nim"
  doAssert(execCmd(compCmd)==0)
  
  copyNimForUELibToUEDir()


proc compileGame*(extraSwitches:seq[string]) = 
  let gameSwitches = @[
    "-d:game",
    "-p:src/game/",
    "-p:src/nimforue/",
    "-p:src/nimforue/unreal",
    "-p:src/nimforue/unreal/bindings",
    # "--include:../game/nueprelude"
  ]

  let bindingPrefix =
    "-d:BindingPrefix=.nimcache/gencppbindings/@m..@snimforue@sunreal@sbindings@sexported@s"
  
  let buildFlags = @[buildSwitches, targetSwitches, ueincludes, uesymbols, pluginPlatformSwitches, gameSwitches, extraSwitches].foldl(a & " " & b.join(" "), "")
  let compCmd = &"nim cpp {buildFlags} {bindingPrefix} --app:lib --nomain --d:genffi -d:withPCH --nimcache:.nimcache/game src/game/game.nim"
  doAssert(execCmd(compCmd)==0)
  



proc compileGenerateBindings*() = 
  let buildFlags = @[buildSwitches, targetSwitches, pluginPlatformSwitches, ueincludes, uesymbols].foldl(a & " " & b.join(" "), "")
  doAssert(execCmd(&"nim  cpp {buildFlags}  --noMain --compileOnly --header:UEGenBindings.h  --nimcache:.nimcache/gencppbindings src/codegen/maingencppbindings.nim") == 0)
  copyFile("./.nimcache/gencppbindings/UEGenBindings.h", "./NimHeaders/UEGenBindings.h")
