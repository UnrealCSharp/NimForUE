﻿#include "ReinstanceBindings.h"

#include "EditorUtils.h"
#include "NimForUEEngineSubsystem.h"
#include "Engine/Engine.h"
#include "Kismet2/ReloadUtilities.h"


void ReinstanceBindings::ReinstanceNueTypes(FString NueModule, FNimHotReload* NimHotReload, FString NimError) {
	UNimForUEEngineSubsystem* NimForUESubsystem = GEngine->GetEngineSubsystem<UNimForUEEngineSubsystem>();
	bool bIsFirstLoad = !NimForUESubsystem->ReloadCounter.Contains(NueModule);
	
	FReload* UnrealReload = nullptr;
	if(!bIsFirstLoad) //We need to instanciate the unreal reloader because it's used across the engine when reloading
		UnrealReload = new FReload(EActiveReloadType::HotReload, TEXT(""), *GLog);

	if(bIsFirstLoad) {//Only crash on first load
		checkf(NimHotReload, TEXT("NimHotReload is null. Probably nim crashed on startup. See the log for a stacktrace."));
	}
	if(NimHotReload == nullptr){
		UE_LOG(LogTemp, Error, TEXT("NimForUE just crashed. Review the log"), *NimError);
		delete UnrealReload;
		return;
		
	}
	if (NimHotReload->bShouldHotReload && !bIsFirstLoad) {
		// if (!bIsFirstLoad) {
		NimForUESubsystem->EditorUtils = NewObject<UEditorUtils>();
		NimForUESubsystem->EditorUtils->HotReload(NimHotReload, UnrealReload);
	
	}
	if (UnrealReload != nullptr)
		delete UnrealReload;
	// delete NimHotReload;

	// FCoreUObjectDelegates::ReloadCompleteDelegate.Broadcast(EReloadCompleteReason::HotReloadManual);
	UEditorUtils::ShowLoadNotification(bIsFirstLoad);
	UE_LOG(LogTemp, Log, TEXT("NimForUE just hot reloaded!! %s"), *NimError);
	if (bIsFirstLoad) {
		NimForUESubsystem->ReloadCounter.Add(NueModule, 0);
	} else {
		NimForUESubsystem->ReloadCounter[NueModule]++;
	}
		
}

