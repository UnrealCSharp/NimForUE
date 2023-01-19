
import std/[
  algorithm,
  options,
  os,
  osproc,
  sequtils,
  strformat,
  strscans,
  strutils,
  sugar,
  times
  ]




import buildcommon, nimforueconfig
export buildcommon, nimforueconfig
import ../nimforue/utils/utils


proc generateFFIGenFile*(config: NimForUEConfig) = 
  let content = """

#AUTOGENERATED FILE. DO NOT EDIT.

import locks
import std/dynlib
import hostbase


"""

  writeFile(GenFilePath, content)


func getNextFileName*(currentFilename : string) : string = 
  const splitter = "-"
  let (_, filename, extension) = splitFile(currentFilename)
  let fileSplit = filename.split(splitter)
  doAssert(fileSplit.len == 1 or fileSplit.len == 2)
  if fileSplit.len == 2:
    let num = fileSplit[1].tryParseInt().get(0) + 1
    return &"{fileSplit[0]}{splitter}{num}{extension}"
  else:
    &"{filename}{splitter}1{extension}"


proc getAllLibsFromPath*(libPath, libName:string) : seq[string] =
  let libName = getFullLibName(libName)
  let libDir = libPath.replace(libName, "")
  let walkPattern = libDir / libName.replace(".", "*.")
  var libs = toSeq(walkFiles(walkPattern))
  let orderByRecent = (a, b : string) => cmp(getLastModificationTime(a), getLastModificationTime(b))
  libs.sorted(orderByRecent, Descending)


proc getLastLibPath*(libPath, libName:string): Option[string] =
  let libs = getAllLibsFromPath(libPath, libName)
  if libs.len == 0:
    return none[string]()
  some libs[0]

const NueExec = when defined(windows): "nue.exe" else: "nue"

proc compileGameSyncFromPlugin*() : string = 
  let (output, _) = execCmdEx(&"{PluginDir}/{NueExec} game")
  output

proc compileGuestSyncFromPlugin*() : string =
  let cmd = &"{PluginDir}/{NueExec} guest"
  let (output, _) = execCmdEx(cmd)
  output

proc executeNueTask(task: string) =
  let cmd = &"{PluginDir}/{NueExec} {task}"
  let (output, _) = execCmdEx(cmd)
  log output



proc copyNimForUELibToUEDir*(libName:string) = 
  var conf = getNimForUEConfig()
  let libDir = PluginDir/"Binaries/nim"
  let libDirUE = libDir / "ue"   
  createDir(libDirUE)

  when defined(windows):
    # #deletes previous used ones
    for libPath in getAllLibsFromPath(libDirUE, libName):
      discard tryRemoveFile(libPath) #We just ignore if it fails as it isnt critical to keep going

  let libsCandidates = getAllLibsFromPath(libDirUE, libName)

  proc extractNumber(path: string): int = 
    var ignore : string
    let (_, filename, _) = path.splitFile
    discard scanf(filename, "$*-$i", ignore, result) # ok if no match, number is 0

  let nextLibNumber = if libsCandidates.any():
                        libsCandidates
                          .map(path => extractNumber(path))
                          .max() + 1
                      else:
                        0

  let baseLibName = getFullLibName(libName)
  let nextFileName = getFullLibName(&"{libname}-{nextLibNumber}")

  let fileFullSrc = libDir/baseLibName
  let fileFullDst: string =
    if libsCandidates.isEmpty: #no libs, we just keep the same name
      libDirUE/baseLibName
    else: #more than one lib, we create a new name
      libDirUE/nextFileName

  copyFile(fileFullSrc, fileFullDst)
  log "Copied " & fileFullSrc & " to " & fileFullDst