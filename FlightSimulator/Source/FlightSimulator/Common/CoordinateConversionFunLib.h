// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoordinateConversionFunLib.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHTSIMULATOR_API UCoordinateConversionFunLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable,Category="CoordinateConversionFunLib")
	static FVector WGS84ToCartesian(float lat, float lon, float h);
};
