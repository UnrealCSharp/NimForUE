// Fill out your copyright notice in the Description page of Project Settings.


#include "NimClassBase.h"

#include "ReflectionHelpers.h"


void UNimClassBase::SetClassConstructor(void(* NimClassConstructor)(FObjectInitializer&)) {
	this->ClassConstructor = reinterpret_cast<ClassConstructorType>(NimClassConstructor);
}

void UNimClassBase::SetAddClassReferencedObjectType(void(* ClassAddReferencedObjectsFn)(UObject*, FReferenceCollector&)) {
	// this->ClassAddReferencedObjects = ClassAddReferencedObjectsFn;
	this->ParentClassReferencedObject = ClassAddReferencedObjectsFn;
	this->ClassAddReferencedObjects = [](UObject* InThis, FReferenceCollector& Collector) {
		UClass* This = Cast<UClass>(InThis);
		if(!This)
			This = Cast<UClass>(InThis->GetClass());
		// UClass::AddReferencedObjects(This, Collector);
		// This->ParentClassReferencedObject(This, Collector);
	};
}

void UNimClassBase::AddNimReferenceObjects(UObject* InThis, FReferenceCollector& Collector) {
	
}


UNimClassBase* UNimClassBase::GetFirstNimClassBase(UObject* Obj) {
	UClass* Parent = Obj->GetClass();
	while (Parent != nullptr)
	{
		if (Cast<UNimClassBase>(Parent) != nullptr)
			return (UNimClassBase*)Parent;
		Parent = Parent->GetSuperClass();
	}
	return nullptr;
}

UNimEnum::UNimEnum(const FObjectInitializer& Initializer) : UEnum(Initializer) {
	SetEnumFlags(EEnumFlags::Flags);
}

TArray<TPair<FName, int64>> UNimEnum::GetEnums() {
	return this->Names;
}

void UNimEnum::MarkNewVersionExists() {
	SetEnumFlags(EEnumFlags::NewerVersionExists);
}
