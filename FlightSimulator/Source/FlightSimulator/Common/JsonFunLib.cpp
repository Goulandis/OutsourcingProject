// Copyright 2020-2021 CesiumGS, Inc. and Contributors


#include "JsonFunLib.h"
#include "JsonFunLib.h"

//FJsonObject* UJsonFunLib::StringToJson(const FString& str, , bool& ok)
//{
//	ok = false;
//	TSharedPtr<FJsonObject> rootObject = MakeShareable(new FJsonObject());
//	TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(str);
//	if (FJsonSerializer::Deserialize(jsonReader, rootObject))
//	{
//		ok = true;
//		return rootObject.Get();
//	}
//    return nullptr;
//}

//double UJsonFunLib::GetNumber(const FJsonObject* rootObj, const FString& key, bool& ok)
//{
//	double res = 0.0f;
//	ok = false;
//	if (rootObj->TryGetNumberField(key,res))
//	{
//		ok = true;
//	}
//	return res;
//}
