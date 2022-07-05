
include ../definitions
import ../Core/Containers/unrealstring
import nametypes
import std/[genasts, macros, sequtils]

import uobjectflags
export uobjectflags



type 
    
    FField* {. importcpp, inheritable, pure .} = object 
        next*  {.importcpp:"Next".} : ptr FField
    FFieldPtr* = ptr FField 
    FProperty* {. importcpp, inheritable,  header:ueIncludes, pure.} = object of FField 
    FPropertyPtr* = ptr FProperty
    UObject* {.importcpp, inheritable, pure .} = object #TODO Create a macro that takes the header path as parameter?
    UObjectPtr* = ptr UObject #This can be autogenerated by a macro

    UField* {.importcpp, inheritable, pure .} = object of UObject
        Next* : ptr UField #Next Field in the linked list 
    UFieldPtr* = ptr UField 

    UStruct* {.importcpp, inheritable, pure .} = object of UField
        Children* : UFieldPtr # Pointer to start of linked list of child fields */
        childProperties* {.importcpp:"ChildProperties".}: FFieldPtr #  /** Pointer to start of linked list of child fields */
        propertyLink* {.importcpp:"PropertyLink".}: FPropertyPtr #  /** 	/** In memory only: Linked list of properties from most-derived to base */

        
    UStructPtr* = ptr UStruct 



    UClass* {.importcpp, inheritable, pure .} = object of UStruct
        classWithin* {.importcpp:"ClassWithin".}: UClassPtr #  The required type for the outer of instances of this class */
        classConfigName* {.importcpp:"ClassConfigName".}: FName 
        classFlags* {.importcpp:"ClassFlags".}: EClassFlags
        classCastFlags* {.importcpp:"ClassCastFlags".}: EClassCastFlags
        classConstructor* {.importcpp:"ClassConstructor".}: pointer


    UClassPtr* = ptr UClass

    UScriptStruct* {.importcpp, inheritable, pure .} = object of UStruct
    UScriptStructPtr* = ptr UScriptStruct


    UFunction* {.importcpp, inheritable, pure .} = object of UStruct
        functionFlags* {.importcpp:"FunctionFlags".} : EFunctionFlags
        numParms* {.importcpp:"NumParms".}: uint8
        parmsSize* {.importcpp:"ParmsSize".}: uint16
    UFunctionPtr* = ptr UFunction


proc castField*[T : FField ](src:FFieldPtr) : ptr T {. importcpp:"CastField<'*0>(#)" .}

proc getName*(prop:FFieldPtr) : FString {. importcpp:"#->GetName()" .}

proc getOffsetForUFunction*(prop:FPropertyPtr) : int32 {. importcpp:"#->GetOffset_ForUFunction()".}
proc initializeValueInContainer*(prop:FPropertyPtr, container:pointer) : void {. importcpp:"#->InitializeValue_InContainer(#)".}

proc getSize*(prop:FPropertyPtr) : int32 {. importcpp:"#->GetSize()".}
proc setPropertyFlags*(prop:FPropertyPtr, flags:EPropertyFlags) : void {. importcpp:"#->SetPropertyFlags(#)".}
proc getPropertyFlags*(prop:FPropertyPtr) : EPropertyFlags {. importcpp:"#->GetPropertyFlags()".}
proc getNameCPP*(prop:FPropertyPtr) : FString {.importcpp: "#->GetNameCPP()".}
proc getCPPType*(prop:FPropertyPtr) : FString {.importcpp: "#->GetCPPType()".}
proc getOwnerStruct*(str:FPropertyPtr) : UStructPtr {.importcpp:"#->GetOwnerStruct()".}


type FFieldVariant* {.importcpp.} = object
proc makeFieldVariant*(field:FFieldPtr) : FFieldVariant {. importcpp: "'0(#)", constructor.}
proc makeFieldVariant*(obj:UObjectPtr) : FFieldVariant {. importcpp: "'0(#)", constructor.}


macro bindFProperty(propNames : static openarray[string] ) : untyped = 
    proc bindProp(name:string) : NimNode = 
        let constructorName = ident "make"&name
        let ptrName = ident name&"Ptr"

        genAst(name=ident name, ptrName, constructorName):
            type 
                name* {.inject, importcpp.} = object of FProperty
                ptrName* {.inject.} = ptr name

            proc constructorName*(fieldVariant:FFieldVariant, propName:FName, flags:EObjectFlags) : ptrName {. importcpp: "new '*0(@)", constructor, inject.}

    
    nnkStmtList.newTree(propNames.map(bindProp))

bindFProperty(["FStrProperty", "FIntProperty", "FArrayProperty", "FMapProperty", "FDelegateProperty", "FMulticastDelegateProperty"])

proc getInnerProp*(arrProp:FArrayPropertyPtr) : FPropertyPtr {.importcpp:"(#->Inner)".}
proc getKeyProp*(arrProp:FMapPropertyPtr) : FPropertyPtr {.importcpp:"(#->KeyProp)".}
proc getValueProp*(arrProp:FMapPropertyPtr) : FPropertyPtr {.importcpp:"(#->ValueProp)".}
proc getSignatureFunction*(delProp:FDelegatePropertyPtr | FMulticastDelegatePropertyPtr) : UFunctionPtr {.importcpp:"(#->SignatureFunction)".}



type


    FOutParmRec* {.importcpp.} = object
        property* {.importcpp:"Property".} : FPropertyPtr
        propAddr* {.importcpp:"PropAddr".}: pointer 
        nextOutParm* {.importcpp:"NextOutParm".}: ptr FOutParmRec
        mostRecentProperty* {.importcpp:"MostRecentProperty".}: FPropertyPtr
        propertyChainForCompiledIn* {.importcpp:"PropertyChainForCompiledIn".}: FPropertyPtr#This is FField but should not matter
        
       
    FFrame* {.importcpp .} = object
        code* {.importcpp:"Code".} : ptr uint8
        node* {.importcpp:"Node".} : UFunctionPtr
        locals* {.importcpp:"Locals".} : ptr uint8
        outParms* {.importcpp:"OutParms".} : ptr FOutParmRec



#UFIELD
proc setMetadata*(field:UFieldPtr, key, inValue:FString) : void {.importcpp:"#->SetMetaData(*#, *#)".}

#USTRUCT
proc staticLink*(str:UStructPtr, bRelinkExistingProperties:bool) : void {.importcpp:"#->StaticLink(@)".}

#This belongs to this file due to nim not being able to forward declate types. We may end up merging this file into uobject
proc addCppProperty*(str:UStructPtr, prop:FPropertyPtr) : void {.importcpp:"#->AddCppProperty(@)".}
#     virtual const TCHAR* GetPrefixCPP() const { return TEXT("F"); }
proc getPrefixCpp*(str:UStructPtr) : FString {.importcpp:"FString(#->GetPrefixCPP())".}
proc setSuperStruct*(str, suprStruct :UStructPtr) : void {.importcpp:"#->SetSuperStruct(#)".}

#UCLASS
proc findFunctionByName*(cls : UClassPtr, name:FName) : UFunctionPtr {. importcpp: "#.FindFunctionByName(#)"}
proc addFunctionToFunctionMap*(cls : UClassPtr, fn : UFunctionPtr, name:FName) : void {. importcpp: "#.AddFunctionToFunctionMap(@)"}
proc removeFunctionFromFunctionMap*(cls : UClassPtr, fn : UFunctionPtr) : void {. importcpp: "#.RemoveFunctionFromFunctionMap(@)"}
proc getDefaultObject*(cls:UClassPtr) : UObjectPtr {. importcpp:"#->GetDefaultObject()" .}
proc getSuperClass*(cls:UClassPtr) : UClassPtr {. importcpp:"#->GetSuperClass()" .}
proc bindCls*(cls:UClassPtr) : void {. importcpp:"#->Bind()" .} #notice bind is a reserverd keyword in nim


#UOBJECT
proc getFName*(obj:UObjectPtr) : FName {. importcpp: "#->GetFName()" .}
proc getClass*(obj : UObjectPtr) : UClassPtr {. importcpp: "#->GetClass()" .}
proc getName*(obj : UObjectPtr) : FString {. importcpp:"#->GetName()" .}
proc conditionalBeginDestroy*(obj:UObjectPtr) : void {. importcpp:"#->ConditionalBeginDestroy()".}
proc processEvent*(obj : UObjectPtr, fn:UFunctionPtr, params:pointer) : void {. importcpp:"#->ProcessEvent(@)" .}



#FUNC
proc initializeDerivedMembers*(fn:UFunctionPtr) : void {.importcpp:"#->InitializeDerivedMembers()".}
proc getReturnProperty*(fn:UFunctionPtr) : FPropertyPtr {.importcpp:"#->GetReturnProperty()".}





type TFieldIterator* [T:UStruct] {.importcpp.} = object
proc makeTFieldIterator*[T](inStruct : UStructPtr, flag:EFieldIterationFlags) : TFieldIterator[T] {. importcpp:"'0(@)" constructor .}

proc next*[T](it:var TFieldIterator[T]) : void {. importcpp:"(++#)" .} 
proc isValid[T](it: TFieldIterator[T]): bool {.importcpp: "((bool)(#))", noSideEffect.}
proc get*[T](it:TFieldIterator[T]) : ptr T {. importcpp:"*#" .} 

iterator items*[T](it:var TFieldIterator[T]) : var TFieldIterator[T] =
    while it.isValid():
        yield it
        it.next()
       


#StepExplicitProperty
proc stepExplicitProperty*(frame:var FFrame, result:pointer, prop:FPropertyPtr) {.importcpp:"#.StepExplicitProperty(@)".}



iterator items*(ustr: UStructPtr): FFieldPtr =
    var currentProp = ustr.childProperties
    while not currentProp.isNil():
        yield currentProp
        currentProp = currentProp.next