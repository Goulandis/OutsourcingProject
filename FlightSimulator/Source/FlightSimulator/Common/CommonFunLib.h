// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonFunLib.generated.h"

UCLASS()
class FLIGHTSIMULATOR_API UCommonFunLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "CoordinateConversion")
	static FVector WGS84ToCartesian(float lon, float lat, float H);
	UFUNCTION(BlueprintCallable, Category = "CoordinateConversion")
	static float LonLatDistance(float LonA, float LatA, float LonB,float LatB);
};
