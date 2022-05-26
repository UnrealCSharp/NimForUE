#HERE ALL METHODS USES TO COMUNICATE VIA FFI WITH UNREAL
#ALSO export the UEConfig type to Cpp (not sure if it has to be done in the other project)

{.emit: """/*INCLUDESECTION*/
#include "Definitions.NimForUE.h"
#include "Definitions.NimForUEBindings.h"
#include "UObject/UnrealType.h"
""".}

import unreal/coreuobject/uobject
import unreal/core/containers/[unrealstring, array]
import unreal/nimforue/nimForUEBindings
import macros/[ffi, uebind]
import strformat
<<<<<<< HEAD

proc testArrays(obj: UObjectPtr): TArray[FString] =
  type
    Params = object
      toReturn: TArray[FString]

  var params = Params()
  var fnName: FString = "TestArrays"
  callUFuncOn(obj, fnName, params.addr)
  return params.toReturn

proc nimMain() {.importc: "NimMain".}
=======
import std / [times]
>>>>>>> master


proc saySomething(obj:UObjectPtr, msg:FString) : void {.uebind.}



# proc testArrays2(obj:UObjectPtr) : seq[string] {.uebind.}

proc testMultipleParams(obj:UObjectPtr, msg:FString,  num:int) : FString {.uebind.}

proc boolTestFromNimAreEquals(obj:UObjectPtr, numberStr:FString, number:cint, boolParam:bool) : bool {.uebind.}

proc setColorByStringInMesh(obj:UObjectPtr, color:FString): void  {.uebind.}
#define on config.nims
const genFilePath* {.strdefine.} : string = ""

#it's here for ref
#[
proc testCallUFuncOnWrapper(executor:UObjectPtr; str:FString; n:int) : FString    =     
    type Params = object 
            str: FString
            n: int
            toReturn: FString #Output paramaeters 
        
    var parms = Params(str: str, n: n) 
    var funcName = makeFString("TestMultipleParams")
    callUFuncOn(executor, funcName, parms.addr)
    return parms.toReturn
]#


<<<<<<< HEAD
# call functions without obj.
proc printArray(obj:UObjectPtr, arr:TArray[FString]) : void = 
    for str in arr: #add posibility to iterate over
        obj.saySomething(str) 


{.push exportc, cdecl, dynlib.} 
=======
var loaded = false
proc NimMain() {.importc.}

{.push exportc, cdecl, dynlib.} 

proc testCallUFuncOn(obj:pointer) : void  {.ffi:genFilePath}  = 
    if not loaded:
        loaded = true
        NimMain()

    let str = "Test"
    let str2 = str.cstring
>>>>>>> master

# proc testPointerBoolOut(boolean: var bool) : ptr bool {.ffi:genFilePath.} = 
#     return boolean.addr


var returnString = ""
proc testCallUFuncOn(obj:pointer) : void  {.ffi:genFilePath}  = 
    nimMain()
    let executor = cast[UObjectPtr](obj)
 
    let msg = testMultipleParams(executor, "hola", 10)

<<<<<<< HEAD
=======
    let msg = testMultipleParams(executor, $now(), 34)
>>>>>>> master
    executor.saySomething(msg)

    executor.setColorByStringInMesh("(R=0.0 ,G=1,B=1,A=1)")

    if executor.boolTestFromNimAreEquals("5", 5, true) == true:
        executor.saySomething("true")
    else:
        executor.saySomething("false" & $ sizeof(bool))

<<<<<<< HEAD
    let arr = testArrays(executor)
    let number = arr.num()

    # let str = $arr.num()
    
    arr.add("hola")
    arr.add("hola2")
    let arr2 = makeTArray[FString]()
    arr2.add("hola3")
    arr2.add("hola8")
    # printArray(executor, arr)
    let lastElement : FString = arr2[0]
    # let lastElement = makeFString("")
    returnString = "number of elements " & $arr.num() & "the element last element is " & lastElement

    # let nowDontCrash = 
    # let msgArr = "The length of the array is " & $ arr.num()
    executor.saySomething(returnString)
    executor.printArray arr2
    
{.pop.}


=======
{.pop.}
>>>>>>> master
