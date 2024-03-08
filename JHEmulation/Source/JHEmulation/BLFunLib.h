#pragma once

// 地球长半径
#define a (double)6378137.0
// 地球短半径
#define b (double)6356752.0

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BLFunLib.generated.h"

typedef TArray<TArray<double>> GMatrix;

UCLASS()
class JHEMULATION_API UBLFunLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable,Category="BLFunLib",meta=(ToolTip="WGS84坐标系转UE空间坐标系"))
	static FVector BLH2XYZ(const double& B,const double& L,const double H);
	UFUNCTION(BlueprintCallable,Category="BLFunLib",meta=(ToolTip="点的空间转换"))
	static FVector Trans(FVector Pos,FRotator Angle);
	
	// 矩阵乘法
	static GMatrix MatrixMul(GMatrix GM1,GMatrix GM2);

	static double Epsilon;
};
