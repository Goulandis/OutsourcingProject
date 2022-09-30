// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonFunLib.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(CommonFunLibLog, Log, All);

UCLASS()
class FLIGHTSIMULATOR_API UCommonFunLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "CoordinateConversion")
	static FVector WGS84ToCartesian(float lon, float lat, float H);
	UFUNCTION(BlueprintCallable, Category = "CoordinateConversion")
	static float LonLatDistance(float LonA, float LatA, float LonB,float LatB);

	UFUNCTION(BlueprintCallable, Category = "ReadConfig")
	static void GetConfigString(FString Section, FString Key, FString FliePath, FString& Value);
	UFUNCTION(BlueprintCallable, Category = "ReadConfig")
	static void GetConfigFloat(FString Section, FString Key, FString FliePath, float& Value);
	UFUNCTION(BlueprintCallable, Category = "ReadConfig")
	static void GetConfigInt(FString Section, FString Key, FString FliePath, int& Value);
	UFUNCTION(BlueprintCallable, Category = "ReadConfig")
	static void GetConfigBool(FString Section, FString Key, FString FliePath, bool& Value);
	UFUNCTION(BlueprintCallable, Category = "WriteConfig")
	static void SetConfigString(FString Section, FString Key, FString FliePath, FString& Value);
	UFUNCTION(BlueprintCallable, Category = "WriteConfig")
	static void SetConfigFloat(FString Section, FString Key, FString FliePath, float& Value);
	UFUNCTION(BlueprintCallable, Category = "WriteConfig")
	static void SetConfigInt(FString Section, FString Key, FString FliePath, int& Value);
	UFUNCTION(BlueprintCallable, Category = "WriteConfig")
	static void SetConfigBool(FString Section, FString Key, FString FliePath, bool& Value);
};
