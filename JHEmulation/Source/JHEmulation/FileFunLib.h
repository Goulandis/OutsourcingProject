// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileFunLib.generated.h"

/**
 * 
 */
UCLASS()
class JHEMULATION_API UFileFunLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable,Category="FileFunLib")
	static FString ReadFile(const FString& Path,bool& Rel);
	UFUNCTION(BlueprintCallable,Category="FileFunLib")
    static bool WriteFile(const FString& Path,const FString& Content);
};
