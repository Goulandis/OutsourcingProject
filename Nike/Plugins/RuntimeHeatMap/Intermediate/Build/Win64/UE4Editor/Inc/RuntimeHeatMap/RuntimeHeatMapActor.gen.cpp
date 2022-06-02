// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RuntimeHeatMap/Public/Core/RuntimeHeatMapActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRuntimeHeatMapActor() {}
// Cross Module References
	RUNTIMEHEATMAP_API UScriptStruct* Z_Construct_UScriptStruct_FHeatMapInfo();
	UPackage* Z_Construct_UPackage__Script_RuntimeHeatMap();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	RUNTIMEHEATMAP_API UScriptStruct* Z_Construct_UScriptStruct_FHeatPointInfo();
	RUNTIMEHEATMAP_API UClass* Z_Construct_UClass_ARuntimeHeatMapActor_NoRegister();
	RUNTIMEHEATMAP_API UClass* Z_Construct_UClass_ARuntimeHeatMapActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
class UScriptStruct* FHeatMapInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RUNTIMEHEATMAP_API uint32 Get_Z_Construct_UScriptStruct_FHeatMapInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FHeatMapInfo, Z_Construct_UPackage__Script_RuntimeHeatMap(), TEXT("HeatMapInfo"), sizeof(FHeatMapInfo), Get_Z_Construct_UScriptStruct_FHeatMapInfo_Hash());
	}
	return Singleton;
}
template<> RUNTIMEHEATMAP_API UScriptStruct* StaticStruct<FHeatMapInfo>()
{
	return FHeatMapInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FHeatMapInfo(FHeatMapInfo::StaticStruct, TEXT("/Script/RuntimeHeatMap"), TEXT("HeatMapInfo"), false, nullptr, nullptr);
static struct FScriptStruct_RuntimeHeatMap_StaticRegisterNativesFHeatMapInfo
{
	FScriptStruct_RuntimeHeatMap_StaticRegisterNativesFHeatMapInfo()
	{
		UScriptStruct::DeferCppStructOps<FHeatMapInfo>(FName(TEXT("HeatMapInfo")));
	}
} ScriptStruct_RuntimeHeatMap_StaticRegisterNativesFHeatMapInfo;
	struct Z_Construct_UScriptStruct_FHeatMapInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapLength_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MapLength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StrengthRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_StrengthRadius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PointInfos_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PointInfos_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PointInfos;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHeatMapInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHeatMapInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_MapLength_MetaData[] = {
		{ "Category", "HeatMapInfo" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_MapLength = { "MapLength", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FHeatMapInfo, MapLength), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_MapLength_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_MapLength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_StrengthRadius_MetaData[] = {
		{ "Category", "HeatMapInfo" },
		{ "Comment", "/*UPROPERTY(BlueprintReadWrite, EditAnywhere)\n\x09\x09""FVector2D CubeLength;\n\x09UPROPERTY(BlueprintReadWrite, EditAnywhere)\n\x09\x09int MaxHeight;*/" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
		{ "ToolTip", "UPROPERTY(BlueprintReadWrite, EditAnywhere)\n               FVector2D CubeLength;\n       UPROPERTY(BlueprintReadWrite, EditAnywhere)\n               int MaxHeight;" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_StrengthRadius = { "StrengthRadius", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FHeatMapInfo, StrengthRadius), METADATA_PARAMS(Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_StrengthRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_StrengthRadius_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_PointInfos_Inner = { "PointInfos", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FHeatPointInfo, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_PointInfos_MetaData[] = {
		{ "Category", "HeatMapInfo" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_PointInfos = { "PointInfos", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FHeatMapInfo, PointInfos), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_PointInfos_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_PointInfos_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHeatMapInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_MapLength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_StrengthRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_PointInfos_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeatMapInfo_Statics::NewProp_PointInfos,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHeatMapInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RuntimeHeatMap,
		nullptr,
		&NewStructOps,
		"HeatMapInfo",
		sizeof(FHeatMapInfo),
		alignof(FHeatMapInfo),
		Z_Construct_UScriptStruct_FHeatMapInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeatMapInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FHeatMapInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeatMapInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FHeatMapInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FHeatMapInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RuntimeHeatMap();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("HeatMapInfo"), sizeof(FHeatMapInfo), Get_Z_Construct_UScriptStruct_FHeatMapInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FHeatMapInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FHeatMapInfo_Hash() { return 4180482019U; }
class UScriptStruct* FHeatPointInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RUNTIMEHEATMAP_API uint32 Get_Z_Construct_UScriptStruct_FHeatPointInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FHeatPointInfo, Z_Construct_UPackage__Script_RuntimeHeatMap(), TEXT("HeatPointInfo"), sizeof(FHeatPointInfo), Get_Z_Construct_UScriptStruct_FHeatPointInfo_Hash());
	}
	return Singleton;
}
template<> RUNTIMEHEATMAP_API UScriptStruct* StaticStruct<FHeatPointInfo>()
{
	return FHeatPointInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FHeatPointInfo(FHeatPointInfo::StaticStruct, TEXT("/Script/RuntimeHeatMap"), TEXT("HeatPointInfo"), false, nullptr, nullptr);
static struct FScriptStruct_RuntimeHeatMap_StaticRegisterNativesFHeatPointInfo
{
	FScriptStruct_RuntimeHeatMap_StaticRegisterNativesFHeatPointInfo()
	{
		UScriptStruct::DeferCppStructOps<FHeatPointInfo>(FName(TEXT("HeatPointInfo")));
	}
} ScriptStruct_RuntimeHeatMap_StaticRegisterNativesFHeatPointInfo;
	struct Z_Construct_UScriptStruct_FHeatPointInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PointLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PointLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PointStrength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PointStrength;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHeatPointInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHeatPointInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewProp_PointLocation_MetaData[] = {
		{ "Category", "HeatPointInfo" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewProp_PointLocation = { "PointLocation", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FHeatPointInfo, PointLocation), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewProp_PointLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewProp_PointLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewProp_PointStrength_MetaData[] = {
		{ "Category", "HeatPointInfo" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewProp_PointStrength = { "PointStrength", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FHeatPointInfo, PointStrength), METADATA_PARAMS(Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewProp_PointStrength_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewProp_PointStrength_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHeatPointInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewProp_PointLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeatPointInfo_Statics::NewProp_PointStrength,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHeatPointInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RuntimeHeatMap,
		nullptr,
		&NewStructOps,
		"HeatPointInfo",
		sizeof(FHeatPointInfo),
		alignof(FHeatPointInfo),
		Z_Construct_UScriptStruct_FHeatPointInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeatPointInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FHeatPointInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeatPointInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FHeatPointInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FHeatPointInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RuntimeHeatMap();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("HeatPointInfo"), sizeof(FHeatPointInfo), Get_Z_Construct_UScriptStruct_FHeatPointInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FHeatPointInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FHeatPointInfo_Hash() { return 986543172U; }
	DEFINE_FUNCTION(ARuntimeHeatMapActor::execGetT2DFromStrengthMap)
	{
		P_GET_STRUCT_REF(FHeatMapInfo,Z_Param_Out_HeatMapInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=P_THIS->GetT2DFromStrengthMap(Z_Param_Out_HeatMapInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ARuntimeHeatMapActor::execGetStrengthMapFromHeatPointInfos)
	{
		P_GET_STRUCT_REF(FHeatMapInfo,Z_Param_Out_HeatMapInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetStrengthMapFromHeatPointInfos(Z_Param_Out_HeatMapInfo);
		P_NATIVE_END;
	}
	void ARuntimeHeatMapActor::StaticRegisterNativesARuntimeHeatMapActor()
	{
		UClass* Class = ARuntimeHeatMapActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetStrengthMapFromHeatPointInfos", &ARuntimeHeatMapActor::execGetStrengthMapFromHeatPointInfos },
			{ "GetT2DFromStrengthMap", &ARuntimeHeatMapActor::execGetT2DFromStrengthMap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics
	{
		struct RuntimeHeatMapActor_eventGetStrengthMapFromHeatPointInfos_Parms
		{
			FHeatMapInfo HeatMapInfo;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HeatMapInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HeatMapInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::NewProp_HeatMapInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::NewProp_HeatMapInfo = { "HeatMapInfo", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RuntimeHeatMapActor_eventGetStrengthMapFromHeatPointInfos_Parms, HeatMapInfo), Z_Construct_UScriptStruct_FHeatMapInfo, METADATA_PARAMS(Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::NewProp_HeatMapInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::NewProp_HeatMapInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::NewProp_HeatMapInfo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "RuntimeHeatMap" },
		{ "Comment", "//UPROPERTY(BlueprintReadWrite)\n//\x09UInstancedStaticMeshComponent* ISM;\n//UPROPERTY(BlueprintReadWrite,EditAnywhere)\n//\x09UMaterialInstance* MI;\n" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
		{ "ToolTip", "UPROPERTY(BlueprintReadWrite)\n       UInstancedStaticMeshComponent* ISM;\nUPROPERTY(BlueprintReadWrite,EditAnywhere)\n       UMaterialInstance* MI;" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARuntimeHeatMapActor, nullptr, "GetStrengthMapFromHeatPointInfos", nullptr, nullptr, sizeof(RuntimeHeatMapActor_eventGetStrengthMapFromHeatPointInfos_Parms), Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics
	{
		struct RuntimeHeatMapActor_eventGetT2DFromStrengthMap_Parms
		{
			FHeatMapInfo HeatMapInfo;
			UTexture2D* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HeatMapInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HeatMapInfo;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::NewProp_HeatMapInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::NewProp_HeatMapInfo = { "HeatMapInfo", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RuntimeHeatMapActor_eventGetT2DFromStrengthMap_Parms, HeatMapInfo), Z_Construct_UScriptStruct_FHeatMapInfo, METADATA_PARAMS(Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::NewProp_HeatMapInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::NewProp_HeatMapInfo_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RuntimeHeatMapActor_eventGetT2DFromStrengthMap_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::NewProp_HeatMapInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "RuntimeHeatMap" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARuntimeHeatMapActor, nullptr, "GetT2DFromStrengthMap", nullptr, nullptr, sizeof(RuntimeHeatMapActor_eventGetT2DFromStrengthMap_Parms), Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARuntimeHeatMapActor_NoRegister()
	{
		return ARuntimeHeatMapActor::StaticClass();
	}
	struct Z_Construct_UClass_ARuntimeHeatMapActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Points_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Points_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Points;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PointStrength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PointStrength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WidthOffet_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_WidthOffet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LengthOffet_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_LengthOffet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MapSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Current_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Current;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Total_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Total;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARuntimeHeatMapActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_RuntimeHeatMap,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ARuntimeHeatMapActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ARuntimeHeatMapActor_GetStrengthMapFromHeatPointInfos, "GetStrengthMapFromHeatPointInfos" }, // 3888975035
		{ &Z_Construct_UFunction_ARuntimeHeatMapActor_GetT2DFromStrengthMap, "GetT2DFromStrengthMap" }, // 3088845185
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARuntimeHeatMapActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/RuntimeHeatMapActor.h" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Points_Inner = { "Points", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FHeatPointInfo, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Points_MetaData[] = {
		{ "Category", "RuntimeHeatMapActor" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Points = { "Points", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARuntimeHeatMapActor, Points), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Points_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Points_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_PointStrength_MetaData[] = {
		{ "Category", "RuntimeHeatMapActor" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_PointStrength = { "PointStrength", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARuntimeHeatMapActor, PointStrength), METADATA_PARAMS(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_PointStrength_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_PointStrength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_WidthOffet_MetaData[] = {
		{ "Category", "RuntimeHeatMapActor" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_WidthOffet = { "WidthOffet", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARuntimeHeatMapActor, WidthOffet), METADATA_PARAMS(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_WidthOffet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_WidthOffet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_LengthOffet_MetaData[] = {
		{ "Category", "RuntimeHeatMapActor" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_LengthOffet = { "LengthOffet", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARuntimeHeatMapActor, LengthOffet), METADATA_PARAMS(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_LengthOffet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_LengthOffet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_MapSize_MetaData[] = {
		{ "Category", "RuntimeHeatMapActor" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_MapSize = { "MapSize", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARuntimeHeatMapActor, MapSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_MapSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_MapSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Current_MetaData[] = {
		{ "Category", "RuntimeHeatMapActor" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Current = { "Current", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARuntimeHeatMapActor, Current), METADATA_PARAMS(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Current_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Current_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Total_MetaData[] = {
		{ "Category", "RuntimeHeatMapActor" },
		{ "ModuleRelativePath", "Public/Core/RuntimeHeatMapActor.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Total = { "Total", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARuntimeHeatMapActor, Total), METADATA_PARAMS(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Total_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Total_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARuntimeHeatMapActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Points_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Points,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_PointStrength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_WidthOffet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_LengthOffet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_MapSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Current,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARuntimeHeatMapActor_Statics::NewProp_Total,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARuntimeHeatMapActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARuntimeHeatMapActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARuntimeHeatMapActor_Statics::ClassParams = {
		&ARuntimeHeatMapActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ARuntimeHeatMapActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARuntimeHeatMapActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARuntimeHeatMapActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARuntimeHeatMapActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARuntimeHeatMapActor, 2216355637);
	template<> RUNTIMEHEATMAP_API UClass* StaticClass<ARuntimeHeatMapActor>()
	{
		return ARuntimeHeatMapActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARuntimeHeatMapActor(Z_Construct_UClass_ARuntimeHeatMapActor, &ARuntimeHeatMapActor::StaticClass, TEXT("/Script/RuntimeHeatMap"), TEXT("ARuntimeHeatMapActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARuntimeHeatMapActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
