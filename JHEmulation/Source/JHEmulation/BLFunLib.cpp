// Fill out your copyright notice in the Description page of Project Settings.


#include "BLFunLib.h"

double UBLFunLib::Epsilon = 1e-12;

FVector UBLFunLib::BLH2XYZ(const double& B, const double& L, const double H)
{
	// 角度转弧度，正余弦计算默认使用弧度
	double RB = B*PI/180;
	double RL = L*PI/180;
	FVector RightHandCoordinate,UnrealCoordinate;
	// 计算椭球第一偏心率e
	const double e = FMath::Sqrt(FMath::Pow(a,2)-FMath::Pow(b,2))/a;
	// 计算椭球曲率半径N
	const double N = a/FMath::Sqrt(1-e*e*FMath::Pow(FMath::Sin(RB),2));
	// WGS84坐标系转右手空间直角坐标系，常用转换公式默认转换成右手坐标系
	RightHandCoordinate.X = (N+H)*FMath::Cos(RB)*FMath::Cos(RL);
	RightHandCoordinate.Y = (N+H)*FMath::Cos(RB)*FMath::Sin(RL);
	RightHandCoordinate.Z = (N*(1-e*e)+H)*FMath::Sin(RB);
	// 右手坐标系转左手坐标系，UE使用左手坐标系
	UnrealCoordinate.X = RightHandCoordinate.X*100;
	UnrealCoordinate.Y = RightHandCoordinate.Y*100;
	UnrealCoordinate.Z = -RightHandCoordinate.Z*100;
	return UnrealCoordinate;
}

FVector UBLFunLib::Trans(FVector Pos,FRotator Angle)
{
	FVector Target;
	double XA = Angle.Roll*PI/180;
	double YA = Angle.Pitch*PI/180;
	double ZA = Angle.Yaw*PI/180;
	GMatrix XM = {{1,0,0},{0,FMath::Cos(XA),FMath::Sin(XA)},{0,-FMath::Sin(XA),FMath::Cos(XA)}};
	GMatrix YM = {{FMath::Cos(YA),0,-FMath::Sin(YA)},{0,1,0},{FMath::Sin(YA),0,FMath::Cos(YA)}};
	GMatrix ZM = {{FMath::Cos(ZA),FMath::Sin(ZA),0},{-FMath::Sin(ZA),FMath::Cos(ZA),0},{0,0,1}};
	GMatrix PM = {{Pos.X},{Pos.Y},{Pos.Z}};
	
	GMatrix RM = MatrixMul(XM,PM);
	RM = MatrixMul(YM,RM);
	RM = MatrixMul(ZM,RM);
	if(RM.Num() != 3)
	{
		UE_LOG(LogTemp,Error,TEXT("点的旋转变换矩阵运算错误，请检查输入矩阵"));
		return Target;
	}
	Target.X = RM[0][0];
	Target.Y = RM[1][0];
	Target.Z = RM[2][0];
	return Target;
}

GMatrix UBLFunLib::MatrixMul(GMatrix GM1, GMatrix GM2)
{
	GMatrix RM;
	if(GM1.Num() <= 0 || GM2.Num() <= 0)
	{
		UE_LOG(LogTemp,Error,TEXT("矩阵1或矩阵2存在空矩阵"));
		return RM;
	}
	if(GM1[0].Num() != GM2.Num())
	{
		UE_LOG(LogTemp,Error,TEXT("矩阵1的列数与矩阵2的行数不相等，不满足矩阵乘法的条件"));
		return RM;
	}
	int Row1 = GM1.Num();
	int Row2 = GM2.Num();
	int Col1 = GM1[0].Num();
	int Col2 = GM2[0].Num();
	TArray<double> RMCol;
	RMCol.Init(0,Col2);
	RM.Init(RMCol,Row1);
	for(int i=0;i<Row1;++i)
	{
		for(int j=0;j<Col2;++j)
		{
			for(int k=0;k<Col1;++k)
			{
				RM[i][j] += GM1[i][k]*GM2[k][j];
			}
			if(FMath::Abs(RM[i][j]) < Epsilon)
			{
				RM[i][j] = 0.0;
			}
		}
	}
	return RM;
}
