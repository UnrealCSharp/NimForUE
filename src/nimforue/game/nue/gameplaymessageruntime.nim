#[ requirements 
nuegame.h:
#include "GameFramework/GameplayMessageSubsystem.h"

game.json: 
{
    "gamePlugins": ["GameplayMessageRouter"]
}
]#

import std/[macros, genasts]
include unrealprelude
when WithEditor:
  import  ../../unreal/bindings/imported/gameplaymessageruntime
else:
  import  ../../unreal/bindings/exported/gameplaymessageruntime

proc registerListenerImpl[T: UObject](msgSubsystem: UGameplayMessageSubsystemPtr, channel: FGameplayTag, obj: ptr T, fnName: static string): FGameplayMessageListenerHandle = 
  const importcpp = &"#->RegisterListener(#, #, &'*3::{fnName.capitalizeAscii()})"
  proc registerListenerInner[T](msgSubsystem: UGameplayMessageSubsystemPtr, channel: FGameplayTag, obj: ptr T): FGameplayMessageListenerHandle {.importcpp: importcpp.}
  registerListenerInner(msgSubsystem, channel, obj)


macro registerListener*(msgSubsystem, channel, obj, fn: typed): FGameplayMessageListenerHandle = 
  fn.ensureIsMember()  
  let fnName = newLit repr fn

  genAst(msgSubsystem, channel, obj, fnName):
    registerListenerImpl(msgSubsystem, channel, obj, fnName)

proc unregisterListener*(msgSubsystem: UGameplayMessageSubsystemPtr, handle: FGameplayMessageListenerHandle) {.importcpp:"#->UnregisterListener(#)".}

proc unregister*(handle: FGameplayMessageListenerHandle) {.importcpp: "#.Unregister()".}

proc isValid*(handle: FGameplayMessageListenerHandle): bool {.importcpp:"#.IsValid()".}

proc broadcastMessage*[T](msgSubsystem: UGameplayMessageSubsystemPtr, channel: FGameplayTag, msg {.byref.}: T) {.importcpp:"#->BroadcastMessage<'3>(@)".}
