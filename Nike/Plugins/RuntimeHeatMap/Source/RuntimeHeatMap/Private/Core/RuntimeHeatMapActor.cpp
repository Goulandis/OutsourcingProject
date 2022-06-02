// Fill out your copyright notice in the Description page of Project Settings.
#include "Core/RuntimeHeatMapActor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/KismetMaterialLibrary.h"

DEFINE_LOG_CATEGORY(LogHeatMap)
// Sets default values
ARuntimeHeatMapActor::ARuntimeHeatMapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	/*ISM = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISM"));
	RootComponent = ISM;*/

}

void ARuntimeHeatMapActor::GetStrengthMapFromHeatPointInfos(const FHeatMapInfo& HeatMapInfo)
{
	int MapLengthX = HeatMapInfo.MapLength.X+ WidthOffet;
	int MapLengthY = HeatMapInfo.MapLength.Y+ LengthOffet;
	StrengthMap.Init(FColor(0, 0, 0, 255), MapLengthX * MapLengthY);
	for (FHeatPointInfo SinglePointInfo : HeatMapInfo.PointInfos)
	{
		float StrengthRadius = HeatMapInfo.StrengthRadius * SinglePointInfo.PointStrength;
		int XMin = SinglePointInfo.PointLocation.X - StrengthRadius;
		int XMax = SinglePointInfo.PointLocation.X + StrengthRadius;
		for (int i = XMin < 0 ? 0 : XMin ; i < XMax && i < MapLengthX ; ++i)
		{
			int YMin = SinglePointInfo.PointLocation.Y - StrengthRadius;
			int YMax = SinglePointInfo.PointLocation.Y + StrengthRadius;
			for (int j = YMin < 0 ? 0 : YMin; j < YMax && j < MapLengthY; ++j)
			{
				float PointDistance = FVector2D::Distance(SinglePointInfo.PointLocation, FVector2D(i, j));
                int index = i * MapLengthX + j;
                //生成热力矩阵
				if (PointDistance <= StrengthRadius && index < StrengthMap.Num())
				{
					float LerpStrengthValue = (0.5 * FMath::Sin(PI * FMath::Clamp<float>(PointDistance / StrengthRadius,0,1) + 0.5 * PI) + 0.5) * SinglePointInfo.PointStrength;
					float OverlayValue = FMath::Clamp<float>((StrengthMap[index].R / 255.0f) + LerpStrengthValue, 0, 1);
					StrengthMap[index] = FColor(OverlayValue * 255, OverlayValue * 255, OverlayValue * 255, 255);
                }
			}
		}	
	}
}

UTexture2D* ARuntimeHeatMapActor::GetT2DFromStrengthMap(const FHeatMapInfo& HeatMapInfo)
{
	if (StrengthMap.Num() <= 0)
	{
		return nullptr;
	}
	UTexture2D* T2D = UTexture2D::CreateTransient(HeatMapInfo.MapLength.X, HeatMapInfo.MapLength.Y);
	if (!T2D->IsValidLowLevel())
	{
		return nullptr;
	}
	T2D->bNoTiling = true;
	void* TextureData = T2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(TextureData, &StrengthMap[0], StrengthMap.Num() * sizeof(FColor));
	T2D->PlatformData->Mips[0].BulkData.Unlock();
	T2D->UpdateResource();
	return T2D;
}

//void ARuntimeHeatMapActor::CreatePoint(const FString & SingleHeatDataJson)
//{
//    bool IsJson = false;
//    FJsonStructClient JsonObj = UREBPFunctionLibrary::ParseStringToJson(SingleHeatDataJson, IsJson);
//    if (!IsJson)
//    {
//        UE_LOG(LogHeatMap, Error, TEXT("Failed to parse string to json object"));
//        return;
//    }
//    bool HasDataObj = false;
//    FJsonStructClient DataObj = UREBPFunctionLibrary::GetObjectFromJson(JsonObj, TEXT("data"), HasDataObj);
//    if (!HasDataObj)
//    {
//        UE_LOG(LogHeatMap, Error, TEXT("Failed to get data object from data object"));
//        return;
//    }
//    bool HasCurrent = false;
//    bool HasTotal = false;
//    bool a = false;
//    UREBPFunctionLibrary::GetIntFromJson(DataObj, TEXT("current"), Current, HasCurrent);
//    UREBPFunctionLibrary::GetIntFromJson(DataObj, TEXT("total"), Total, HasTotal);
//    if (!HasCurrent || !HasTotal)
//    {
//        UE_LOG(LogHeatMap, Error, TEXT("Failed to get Current,Total param from data object"));
//        return;
//    }
//    FJsonArrayForClientBp DataArr;
//    int ArrLength = 0;
//    bool hasDataArr = false;
//    UREBPFunctionLibrary::GetArrayFromJson(DataObj,TEXT("data"),DataArr, ArrLength, hasDataArr);
//    if (!hasDataArr)
//    {
//        UE_LOG(LogHeatMap, Error, TEXT("Failed to get data array from data object"));
//        return;
//    }
//    for (int i = 0; i < ArrLength; ++i)
//    {
//        int X = 0;
//        int Y = 0;    
//        FJsonStructClient Item;
//        bool ItemExist = false;
//        bool XExist = false;
//        bool YExist = false;
//        UREBPFunctionLibrary::GetObjFromJsonArray(DataArr, i, Item, ItemExist);
//        UREBPFunctionLibrary::GetIntFromJson(Item, TEXT("x"), X, XExist);
//        UREBPFunctionLibrary::GetIntFromJson(Item, TEXT("y"), Y, YExist);
//        if (!ItemExist || !XExist || !YExist)
//        {
//            UE_LOG(LogHeatMap, Error, TEXT("Failed to get x,y or array item from data object"));
//            return;
//        }
//        FHeatPointInfo PointInfo;
//        //Slam栅格图与热力贴图的坐标转换
//        PointInfo.PointLocation.X = MapSize.X - X;
//        PointInfo.PointLocation.Y = Y;
//        PointInfo.PointStrength = PointStrength;
//        Points.Add(PointInfo);
//    }
//}

//void ARuntimeHeatMapActor::SpawnStaticMeshInstance(const FHeatMapInfo& HeatMapInfo)
//{
//	TArray<FColor> Pixels = GetStrengthMapFromHeatPointInfos(HeatMapInfo);
//	FVector LocationOffset(-100 * 0.5 * HeatMapInfo.MapLength.X * HeatMapInfo.CubeLength.X, -100 * 0.5 * HeatMapInfo.MapLength.Y * HeatMapInfo.CubeLength.Y, 0);;
//	for (int i = 0;i< HeatMapInfo.MapLength.X;++i)
//	{
//		for (int j = 0;j < HeatMapInfo.MapLength.Y;++j)
//		{
//			FTransform Tran;
//			float LerpHeight = HeatMapInfo.MaxHeight * (Pixels[i * HeatMapInfo.MapLength.X + j].R / 255.0f);
//			Tran.SetLocation(LocationOffset + FVector(HeatMapInfo.CubeLength.X * 100 * i, HeatMapInfo.CubeLength.Y * 100 * j, LerpHeight * 100 * 0.5));
//			Tran.SetScale3D(FVector(1, 1, LerpHeight));
//			ISM->AddInstance(Tran);
//		}
//	}
//	UTexture2D* T2D = GetT2DFromStrengthMap(Pixels, HeatMapInfo);
//	if (!T2D->IsValidLowLevel())
//	{
//		return;
//	}
//	UMaterialInstanceDynamic* MID = UKismetMaterialLibrary::CreateDynamicMaterialInstance(GWorld, MI);
//	MID->SetTextureParameterValue("HeatMapT2D", T2D);
//	MID->SetScalarParameterValue("MapLengthX", HeatMapInfo.MapLength.X);
//	MID->SetScalarParameterValue("MapLengthY", HeatMapInfo.MapLength.Y);
//	MID->SetScalarParameterValue("CubeLengthX", HeatMapInfo.CubeLength.X * 100);
//	MID->SetScalarParameterValue("CubeLengthY", HeatMapInfo.CubeLength.Y * 100);
//	ISM->SetMaterial(0, MID);
//}

// Called when the game starts or when spawned
void ARuntimeHeatMapActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARuntimeHeatMapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

