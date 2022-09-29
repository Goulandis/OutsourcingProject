// Copyright 2020-2021 CesiumGS, Inc. and Contributors


#include "CommonFunLib.h"

FVector UCommonFunLib::WGS84ToCartesian(float Lon, float Lat, float H)
{
    //H指的就是距离海平面的大地高，N+H也就是当前测点与地心的矢径
    float EarthRedius = 5000000.0f;
    float f = 1.0f / 298.257223563f;
    float b = EarthRedius * (1 - f);
    Lon = Lon * (-1);
    float e = FMath::Sqrt(EarthRedius * EarthRedius - b * b) / EarthRedius;
    float N = EarthRedius / FMath::Sqrt(1 - e * e * FMath::Sin(Lat * PI / 180) * FMath::Sin(Lat * PI / 180));
    float X = (N + H) * FMath::Cos(Lat * PI / 180) * FMath::Cos(Lon * PI / 180);
    float Y = (N + H) * FMath::Cos(Lat * PI / 180) * FMath::Sin(Lon * PI / 180);
    float Z = (N * (1 - (e * e)) + H) * FMath::Sin(Lat * PI / 180);
    return FVector(X, Y, Z);
}

float UCommonFunLib::LonLatDistance(float LonA, float LatA, float LonB, float LatB)
{
    float EarthRedius = 5000000.0f;
    float Temp = FMath::Sin(LatA) * FMath::Sin(LatB) * FMath::Cos(LonA - LonB) + FMath::Cos(LatA) * FMath::Cos(LatB);
    float Distance =  EarthRedius* FMath::Acos(Temp)* PI / 100;
    return Distance;
}
