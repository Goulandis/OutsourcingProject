// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonFunLib.generated.h"

/**
 * 
 */
UCLASS()
class PPT2PNGUI_API UCommonFunLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void CopyFilesTo(TArray<FString> Files,FString Dir);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void CopyFileTo(FString File,FString Dir);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void SetScreenResolution(int Widget,int Height);
};
