// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FlightSimulatorGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWindowClose);

UCLASS()
class FLIGHTSIMULATOR_API UFlightSimulatorGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
	FOnWindowClose OnWindowClose;
public:
	void OnExit(const TSharedRef<SWindow>& window);
};
