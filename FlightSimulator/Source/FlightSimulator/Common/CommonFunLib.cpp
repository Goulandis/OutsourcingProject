// Copyright 2020-2021 CesiumGS, Inc. and Contributors


#include "CommonFunLib.h"

DEFINE_LOG_CATEGORY(CommonFunLibLog);

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

void UCommonFunLib::GetConfigString(FString Section, FString Key, FString FliePath, FString& Value)
{
    if (!GConfig->GetString(*Section, *Key, Value, FliePath))
    {
        UE_LOG(CommonFunLibLog, Error, TEXT("Failed to read string value with Section is %s and Key is %s in %s"), *Section, *Key, *FliePath);
    }
}

void UCommonFunLib::GetConfigFloat(FString Section, FString Key, FString FliePath, float& Value)
{
    if (!GConfig->GetFloat(*Section, *Key, Value, FliePath))
    {
        UE_LOG(CommonFunLibLog, Error, TEXT("Failed to read float value with Section is %s and Key is %s in %s"), *Section, *Key, *FliePath);
    }
}

void UCommonFunLib::GetConfigInt(FString Section, FString Key, FString FliePath, int& Value)
{
    if (!GConfig->GetInt(*Section, *Key, Value, FliePath))
    {
        UE_LOG(CommonFunLibLog, Error, TEXT("Failed to read int value with Section is %s and Key is %s in %s"), *Section, *Key, *FliePath);
    }
}

void UCommonFunLib::GetConfigBool(FString Section, FString Key, FString FliePath, bool& Value)
{
    if (!GConfig->GetBool(*Section, *Key, Value, FliePath))
    {
        UE_LOG(CommonFunLibLog, Error, TEXT("Failed to read bool value with Section is %s and Key is %s in %s"), *Section, *Key, *FliePath);
    }
}

void UCommonFunLib::SetConfigString(FString Section, FString Key, FString FliePath, FString& Value)
{
    GConfig->SetString(*Section, *Key, *Value, FliePath);
}

void UCommonFunLib::SetConfigFloat(FString Section, FString Key, FString FliePath, float& Value)
{
    GConfig->SetFloat(*Section, *Key, Value, FliePath);
}

void UCommonFunLib::SetConfigInt(FString Section, FString Key, FString FliePath, int& Value)
{
    GConfig->SetInt(*Section, *Key, Value, FliePath);
}

void UCommonFunLib::SetConfigBool(FString Section, FString Key, FString FliePath, bool& Value)
{
    GConfig->SetBool(*Section, *Key, Value, FliePath);
}
