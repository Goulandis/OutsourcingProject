// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "AssertionMacros.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RuntimeHeatMapActor.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogHeatMap, Log, All);

class UInstancedStaticMeshComponent;
USTRUCT(BlueprintType)
struct FHeatPointInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector2D PointLocation;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float PointStrength;
};

USTRUCT(BlueprintType)
struct FHeatMapInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector2D MapLength;
	/*UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector2D CubeLength;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int MaxHeight;*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int StrengthRadius;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FHeatPointInfo> PointInfos;
};


UCLASS()
class RUNTIMEHEATMAP_API ARuntimeHeatMapActor : public AActor
{
	GENERATED_BODY()
private:
    TArray<FColor> StrengthMap;
public:
    UPROPERTY(BlueprintReadWrite,EditAnywhere)
    TArray<FHeatPointInfo> Points;
    UPROPERTY(BlueprintReadWrite)
    float PointStrength = 0.4;
    UPROPERTY(BlueprintReadWrite)
    int WidthOffet = 0;
    UPROPERTY(BlueprintReadWrite)
    int LengthOffet = 0;
    UPROPERTY(BlueprintReadWrite)
    FVector2D MapSize;
    UPROPERTY(BlueprintReadWrite)
    int Current = 0;
    UPROPERTY(BlueprintReadWrite)
    int Total = 0;
public:	
	ARuntimeHeatMapActor();
	//UPROPERTY(BlueprintReadWrite)
	//	UInstancedStaticMeshComponent* ISM;
	//UPROPERTY(BlueprintReadWrite,EditAnywhere)
	//	UMaterialInstance* MI;
    UFUNCTION(BlueprintCallable, Category = "RuntimeHeatMap")
	void GetStrengthMapFromHeatPointInfos(const FHeatMapInfo& HeatMapInfo);
    UFUNCTION(BlueprintCallable, Category = "RuntimeHeatMap")
	UTexture2D* GetT2DFromStrengthMap(const FHeatMapInfo& HeatMapInfo);
	//UFUNCTION(BlueprintCallable,Category="RuntimeHeatMap")
	//void CreatePoint(const FString& SingleHeatDataJson);
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
