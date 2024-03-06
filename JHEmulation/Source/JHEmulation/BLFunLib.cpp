// Fill out your copyright notice in the Description page of Project Settings.


#include "BLFunLib.h"

FVector UBLFunLib::BLH2XYZ(const double& B, const double& L, const double H)
{
	double RB = B*PI/180;
	double RL = L*PI/180;
	FVector RightHandCoordinate,LeftHandCoordinate;
	const double e = FMath::Sqrt(FMath::Pow(a,2)-FMath::Pow(b,2))/a;
	const double N = a/FMath::Sqrt(1-e*e*FMath::Pow(FMath::Sin(RB),2));
	RightHandCoordinate.X = (N+H)*FMath::Cos(RB)*FMath::Cos(RL);
	RightHandCoordinate.Y = (N+H)*FMath::Cos(RB)*FMath::Sin(RL);
	RightHandCoordinate.Z = (N*(1-e*e)+H)*FMath::Sin(RB);
	LeftHandCoordinate.X = RightHandCoordinate.X*100;
	LeftHandCoordinate.Y = -RightHandCoordinate.Z*100;
	LeftHandCoordinate.Z = -RightHandCoordinate.Y*100;
	return LeftHandCoordinate;
}

void UBLFunLib::Pos1AndPos2()
{
	FVector Pos1 = UBLFunLib::BLH2XYZ(31.835435,117.089292,33.4724);
	UE_LOG(LogTemp,Log,TEXT("(X=%lf,Y=%lf,Z=%lf)"),Pos1.X,Pos1.Y,Pos1.Z);
	FVector Pos2 = UBLFunLib::BLH2XYZ(31.834883,117.089638,33.3366);
	UE_LOG(LogTemp,Log,TEXT("(X=%lf,Y=%lf,Z=%lf)"),Pos2.X,Pos2.Y,Pos2.Z);
	FVector LenPos = Pos1-Pos2;
	UE_LOG(LogTemp,Log,TEXT("Len=%lf"),LenPos.Length());
}
