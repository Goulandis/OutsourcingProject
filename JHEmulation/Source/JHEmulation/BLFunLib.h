// Fill out your copyright notice in the Description page of Project Settings.

#define a (double)6378137.0
#define b (double)6356752.0
#define f (1 / 298.257222101)
#define e2 (f*(2-f))
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BLFunLib.generated.h"

/**
 * 
 */
UCLASS()
class JHEMULATION_API UBLFunLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable,Category="BLFunLib")
	static FVector BLH2XYZ(const double& B,const double& L,const double H);
	UFUNCTION(BlueprintCallable,Category="BLFunLib")
	static void Pos1AndPos2();
};
