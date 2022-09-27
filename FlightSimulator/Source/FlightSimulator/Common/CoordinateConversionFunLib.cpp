// Copyright 2020-2021 CesiumGS, Inc. and Contributors


#include "CoordinateConversionFunLib.h"

FVector UCoordinateConversionFunLib::WGS84ToCartesian(float lat, float lon, float h)
{
    float EarthRedius = 5000000.0f;
    //Hָ�ľ��Ǿ��뺣ƽ��Ĵ�ظߣ�N+HҲ���ǵ�ǰ�������ĵ�ʸ��
    float f = 1.0f / 298.257223563f;
    float b = EarthRedius * (1 - f);
    lat = lat * (-1);
    float e = FMath::Sqrt(EarthRedius * EarthRedius - b * b) / EarthRedius;
    float N = EarthRedius / FMath::Sqrt(1 - e * e * FMath::Sin(lon * PI / 180) * FMath::Sin(lon * PI / 180));
    float X = (N + h) * FMath::Cos(lon * PI / 180) * FMath::Cos(lat * PI / 180);
    float Y = (N + h) * FMath::Cos(lon * PI / 180) * FMath::Sin(lat * PI / 180);
    float Z = (N * (1 - (e * e)) + h) * FMath::Sin(lon * PI / 180);
    return FVector(X, Y, Z);
}

