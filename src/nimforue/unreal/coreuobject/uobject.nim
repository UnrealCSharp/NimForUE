
import ../Core/Containers/unrealstring
import nametypes
import std/[genasts, macros, sequtils]

import uobjectflags
export uobjectflags



include ../definitions

type 
    
    FField* {. importcpp, inheritable, pure .} = object 
        Next* : ptr FField
    FFieldPtr* = ptr FField 


    FProperty* {. importcpp, inheritable, pure.} = object of FField 
    FPropertyPtr* = ptr FProperty
    

    UObject* {.importcpp, inheritable, pure .} = object #TODO Create a macro that takes the header path as parameter?
    UObjectPtr* = ptr UObject #This can be autogenerated by a macro

    UField* {.importcpp, inheritable, pure .} = object of UObject
        Next* : ptr UField #Next Field in the linked list 
    UFieldPtr* = ptr UField 

    UStruct* {.importcpp, inheritable, pure .} = object of UField
        Children* : UFieldPtr # Pointer to start of linked list of child fields */
        ChildProperties* : FFieldPtr #  /** Pointer to start of linked list of child fields */


    UStructPtr* = ptr UStruct 

    UClass* {.importcpp, inheritable, pure .} = object of UStruct
    UClassPtr* = ptr UClass

    UScriptStruct* {.importcpp, inheritable, pure .} = object of UStruct
    UScriptStructPtr* = ptr UScriptStruct


    UFunction* {.importcpp, inheritable, pure .} = object of UStruct
        functionFlags* {.importcpp:"FunctionFlags".} : EFunctionFlags
        numParms* {.importcpp:"NumParms".}: uint8
        parmsSize* {.importcpp:"ParmsSize".}: uint16

        
    UFunctionPtr* = ptr UFunction

    FFrame* {.importcpp .} = object
        code* {.importcpp:"Code".} : ptr uint8
        node* {.importcpp:"Node".} : UFunctionPtr
        locals* {.importcpp:"Locals".} : ptr uint8
    

proc getName*(prop:FFieldPtr) : FString {. importcpp:"#->GetName()" .}

proc getOffsetForUFunction*(prop:FPropertyPtr) : int32 {. importcpp:"#->GetOffset_ForUFunction()".}

proc getSize*(prop:FPropertyPtr) : int32 {. importcpp:"#->GetSize()".}
proc setPropertyFlags*(prop:FPropertyPtr, flags:EPropertyFlags) : void {. importcpp:"#->SetPropertyFlags(#)".}
proc getPropertyFlags*(prop:FPropertyPtr) : EPropertyFlags {. importcpp:"#->GetPropertyFlags()".}


proc staticLink*(str:UStructPtr, bRelinkExistingProperties:bool) : void {.importcpp:"#->StaticLink(@)".}
#This belongs to this file due to nim not being able to forward declate types. We may end up merging this file into uobject
proc addCppProperty*(str:UStructPtr, prop:FPropertyPtr) : void {.importcpp:"#->AddCppProperty(@)".}

    # FUNC_Public | FUNC_BlueprintCallable | FUNC_BlueprintEvent

proc getClass*(obj : UObjectPtr) : UClassPtr {. importcpp: "#->GetClass()" .}
proc getName*(obj : UObjectPtr) : FString {. importcpp:"#->GetName()" .}
proc processEvent*(obj : UObjectPtr, fn:UFunctionPtr, params:pointer) : void {. importcpp:"#->ProcessEvent(@)" .}

proc findFunctionByName*(cls : UClassPtr, name:FName) : UFunctionPtr {. importcpp: "#.FindFunctionByName(#)"}
proc addFunctionToFunctionMap*(cls : UClassPtr, fn : UFunctionPtr, name:FName) : void {. importcpp: "#.AddFunctionToFunctionMap(@)"}
proc removeFunctionFromFunctionMap*(cls : UClassPtr, fn : UFunctionPtr) : void {. importcpp: "#.RemoveFunctionFromFunctionMap(@)"}

proc getFName*(obj:UObjectPtr) : FName {. importcpp: "#->GetFName()" .}



proc initializeDerivedMembers*(fn:UFunctionPtr) : void {.importcpp:"#->InitializeDerivedMembers()".}
proc getReturnProperty*(fn:UFunctionPtr) : FPropertyPtr {.importcpp:"#->GetReturnProperty()".}




type FFieldVariant* {.importcpp.} = object
proc makeFieldVariant*(field:FFieldPtr) : FFieldVariant {. importcpp: "'0(#)", constructor.}
proc makeFieldVariant*(obj:UObjectPtr) : FFieldVariant {. importcpp: "'0(#)", constructor.}

# type 
#     FStrProperty* {.importcpp.} = object of FProperty
#     FStrPropertyPtr* = ptr FStrProperty


# proc makeFStringProperty*(fieldVariant:FFieldVariant, name:FName, flags:EObjectFlags) : FStrPropertyPtr {. importcpp: "new '*0(@)".}


macro bindFProperty(propNames : static openarray[string] ) : untyped = 
    proc bindProp(name:string) : NimNode = 
        let constructorName = ident "make"&name
        let ptrName = ident name&"Ptr"

        genAst(name=ident name, ptrName, constructorName):
            type 
                name* {.inject, importcpp.} = object of FProperty
                ptrName* {.inject.} = ptr name

            proc constructorName*(fieldVariant:FFieldVariant, propName:FName, flags:EObjectFlags) : ptrName {. importcpp: "new '*0(@)", inject.}

    
    nnkStmtList.newTree(propNames.map(bindProp))

bindFProperty(["FStrProperty", "FIntProperty"])
