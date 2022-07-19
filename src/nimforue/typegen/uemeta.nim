include ../unreal/prelude
import std/[times,strformat, strutils, options, sugar, algorithm, sequtils]
import fproperty
import models
export models


#UE META CONSTRUCTORS. Notice they are here because they pull type definitions from Cpp which cant be loaded in the ScriptVM
func makeFieldAsUProp*(name, uPropType: string, flags=CPF_None, metas:seq[UEMetadata] = @[]) : UEField = 
    UEField(kind:uefProp, name: name, uePropType: uPropType, propFlags:EPropertyFlagsVal(flags), metadata:metas)       

func makeFieldAsUPropMulDel*(name, uPropType: string, flags=CPF_None, metas:seq[UEMetadata] = @[]) : UEField = 
    UEField(kind:uefProp, name: name, uePropType: uPropType, propFlags:EPropertyFlagsVal(flags), metadata: @[makeUEMetadata(MulticastDelegateMetadataKey)]&metas)       

func makeFieldAsUPropDel*(name, uPropType: string, flags=CPF_None, metas:seq[UEMetadata] = @[]) : UEField = 
    UEField(kind:uefProp, name: name, uePropType: uPropType, propFlags:EPropertyFlagsVal(flags), metadata: @[makeUEMetadata(DelegateMetadataKey)]&metas)       


func makeFieldAsUFun*(name:string, signature:seq[UEField], flags=FUNC_None) : UEField = 
    UEField(kind:uefFunction, name:name, signature:signature, fnFlags:EFunctionFlagsVal(flags))

func makeFieldAsUPropParam*(name, uPropType: string, flags=CPF_Parm) : UEField = 
    UEField(kind:uefProp, name: name, uePropType: uPropType, propFlags:EPropertyFlagsVal(flags))       

func makeUEClass*(name, parent:string, clsFlags:EClassFlags, fields:seq[UEField], metadata : seq[UEMetadata] = @[]) : UEType = 
    UEType(kind:uetClass, name:name, parent:parent, clsFlags: EClassFlagsVal(clsFlags), fields:fields)

func makeUEStruct*(name:string, fields:seq[UEField], superStruct="", metadata : seq[UEMetadata] = @[], flags = STRUCT_NoFlags) : UEType = 
    UEType(kind:uetStruct, name:name, fields:fields, superStruct:superStruct, metadata: metadata, structFlags: flags)

func makeUEMulDelegate*(name:string, fields:seq[UEField]) : UEType = 
    UEType(kind:uetDelegate, name:name, fields:fields)



func isTArray(prop:FPropertyPtr) : bool = not castField[FArrayProperty](prop).isNil()
func isTMap(prop:FPropertyPtr) : bool = not castField[FMapProperty](prop).isNil()
func isTEnum(prop:FPropertyPtr) : bool = "TEnumAsByte" in prop.getName()
func isDynDel(prop:FPropertyPtr) : bool = not castField[FDelegateProperty](prop).isNil()
func isMulticastDel(prop:FPropertyPtr) : bool = not castField[FMulticastDelegateProperty](prop).isNil()
#TODO Dels

func getNimTypeAsStr(prop:FPropertyPtr) : string = #The expected type is something that UEField can understand
    if prop.isTArray(): 
        let innerType = castField[FArrayProperty](prop).getInnerProp().getCPPType()
        return fmt"TArray[{innerType}]"

    if prop.isTMap(): #better pattern here, i.e. option chain
        let mapProp = castField[FMapProperty](prop)
        let keyType = mapProp.getKeyProp().getCPPType()
        let valueType = mapProp.getValueProp().getCPPType()
        return fmt"TMap[{keyType}, {valueType}]"

    let cppType = prop.getCPPType() #TODO review this

    if prop.isTEnum(): #Not sure if it would be better to just support it on the macro
        return cppType.replace("TEnumAsByte<","")
                      .replace(">", "")


    let nimType = cppType.replace("<", "[")
                         .replace(">", "]")
                         .replace("*", "Ptr")
    

    # UE_Warn prop.getTypeName() #private?
    return nimType

#Function that receives a FProperty and returns a Type as string
func toUEField*(prop:FPropertyPtr) : UEField = #The expected type is something that UEField can understand
    let name = prop.getName()
    let nimType = prop.getNimTypeAsStr()
    #MOVE THIS 
    # if prop.isDynDel() or prop.isMulticastDel():
    #     let signature = if prop.isDynDel(): 
    #                         castField[FDelegateProperty](prop).getSignatureFunction() 
    #                     else: 
    #                         castField[FMulticastDelegateProperty](prop).getSignatureFunction()
        
    #     var signatureAsStrs = getFPropsFromUStruct(signature)
    #                             .map(prop=>getNimTypeAsStr(prop))
    #     return makeFieldAsDel(name, uedelDynScriptDelegate, signatureAsStrs)


    return makeFieldAsUProp(prop.getName(), nimType, prop.getPropertyFlags())

    
# func toUEField(udel:UDelegateFunctionPtr) : UEField = 
#     let params = getFPropsFromUStruct(udel).map(toUEField).map(x=>x.uePropType)
#     makeFieldAsMulDel(udel.getName(), params)


func toUEField*(ufun:UFunctionPtr) : UEField = 
    # let asDel = ueCast[UDelegateFunction](ufun)
    # if not asDel.isNil(): return toUEField asDel

    let params = getFPropsFromUStruct(ufun).map(toUEField)
    # UE_Warn(fmt"{ufun.getName()}")
    makeFieldAsUFun(ufun.getName(), params, ufun.functionFlags)
    

func toUEType*(cls:UClassPtr) : UEType =
    let fields = getFuncsFromClass(cls)
                    .map(toUEField) & 
                 getFPropsFromUStruct(cls)
                    .map(toUEField)
    let name = cls.getPrefixCpp() & cls.getName()
    let parent = cls.getSuperClass()
    let parentName = parent.getPrefixCpp() & parent.getName()

    UEType(name:name, kind:uetClass, parent:parentName, fields:fields.reversed())

func toUEType*(str:UStructPtr) : UEType =
    let fields = getFPropsFromUStruct(str)
                    .map(toUEField)
    let name = str.getPrefixCpp() & str.getName()
    # let parent = str.getSuperClass()
    # let parentName = parent.getPrefixCpp() & parent.getName()

    UEType(name:name, kind:uetStruct, fields:fields.reversed())


proc emitFProperty*(propField:UEField, outer : UStructPtr) : FPropertyPtr = 
    let prop : FPropertyPtr = newFProperty(outer, propField)
    prop.setPropertyFlags(propField.propFlags or prop.getPropertyFlags())
    for metadata in propField.metadata:
        prop.setMetadata(metadata.name, $metadata.value)
    outer.addCppProperty(prop)
    prop



proc emitUClass*(ueType : UEType, package:UPackagePtr) : UStructPtr =
    const objClsFlags  =  (RF_Public | RF_Standalone | RF_Transactional | RF_LoadCompleted)
    # const objClsFlags  =  (RF_Public || RF_Standalone || RF_Transactional || RF_LoadCompleted)
    # let objClsFlags  =  RF_Standalone || RF_Public
    let
        newCls = newUObject[UNimClassBase](package, makeFName(ueType.name.removeFirstLetter()), cast[EObjectFlags](objClsFlags))
        parent = getClassByName(ueType.parent.removeFirstLetter())
    
    assetCreated(newCls)

    newCls.classConstructor = nil
    newCls.propertyLink = parent.propertyLink
    newCls.classWithin = parent.classWithin
    newCls.classConfigName = parent.classConfigName

    newCls.setSuperStruct(parent)

    # use explicit casting between uint32 and enum to avoid range checking bug https://github.com/nim-lang/Nim/issues/20024
    newCls.classFlags = cast[EClassFlags](ueType.clsFlags.uint32 and parent.classFlags.uint32)

    newCls.classCastFlags = parent.classCastFlags
    
    copyMetadata(parent, newCls)
    newCls.setMetadata("IsBlueprintBase", "true") #todo move to ueType
    newCls.setMetadata("BlueprintType", "true") #todo move to ueType
    
    for field in ueType.fields:
        let fProp = field.emitFProperty(newCls) 


    newCls.bindType()
    newCls.staticLink(true)
    newCls.assembleReferenceTokenStream()
    # discard newCls.getDefaultObject() #forces the creation of the cdo
    # broadcastAsset(newCls) Dont think this is needed since the notification will be done in the boundary of the plugin
    newCls


proc emitUStruct*[T](ueType : UEType, package:UPackagePtr) : UStructPtr =
      
    const objClsFlags  =  (RF_Public | RF_Standalone | RF_MarkAsRootSet)
    let scriptStruct = newUObject[UNimScriptStruct](package, makeFName(ueType.name.removeFirstLetter()), objClsFlags)
        
    # scriptStruct.setMetadata("BlueprintType", "true") #todo move to ueType
    for metadata in ueType.metadata:
        scriptStruct.setMetadata(metadata.name, $metadata.value)

    scriptStruct.assetCreated()
    
    for field in ueType.fields:
        discard field.emitFProperty(scriptStruct) 

    setCppStructOpFor[T](scriptStruct, nil)
    scriptStruct.bindType()
    scriptStruct.staticLink(true)

    scriptStruct




proc emitUStruct*[T](ueType : UEType, package:string) : UStructPtr =
    let package = getPackageByName(package)
    if package.isnil():
        raise newException(Exception, "Package not found!")
    emitUStruct[T](ueType, package)
    


proc emitUDelegate*(delType : UEType, package:UPackagePtr) : UStructPtr = 
    let fnName = (delType.name.removeFirstLetter() & DelegateFuncSuffix).makeFName()
    let objFlags = RF_Public | RF_Standalone | RF_MarkAsRootSet
    var fn = newUObject[UDelegateFunction](package, fnName, objFlags)
    fn.functionFlags = FUNC_MulticastDelegate or FUNC_Delegate
    for field in delType.fields:
        let fprop =  field.emitFProperty(fn)
        # UE_Warn "Has Return " & $ (CPF_ReturnParm in fprop.getPropertyFlags())
    fn.staticLink(true)
    fn


#note at some point class can be resolved from the UEField?
proc emitUFunction*(fnField : UEField, cls:UClassPtr, fnImpl:UFunctionNativeSignature) : UFunctionPtr = 
    let fnName = fnField.name.makeFName()
    var fn = newUObject[UFunction](cls, fnName)
    fn.functionFlags = fnField.fnFlags

    fn.Next = cls.Children 
    cls.Children = fn
    
    for field in fnField.signature:
        let fprop =  field.emitFProperty(fn)
        # UE_Warn "Has Return " & $ (CPF_ReturnParm in fprop.getPropertyFlags())

    cls.addFunctionToFunctionMap(fn, fnName)
    fn.setNativeFunc(makeFNativeFuncPtr(fnImpl))
    fn.staticLink(true)
    # fn.parmsSize = uprops.foldl(a + b.getSize(), 0) doesnt seem this is necessary 
    fn

proc createUFunctionInClass*(cls:UClassPtr, fnField : UEField, fnImpl:UFunctionNativeSignature) : UFunctionPtr {.deprecated: "use emitUFunction instead".}= 
    fnField.emitUFunction(cls, fnImpl)



