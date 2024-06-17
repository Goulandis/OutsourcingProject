// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InVideo/Public/InSceneRecord.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInSceneRecord() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	INVIDEO_API UClass* Z_Construct_UClass_AInSceneRecord();
	INVIDEO_API UClass* Z_Construct_UClass_AInSceneRecord_NoRegister();
	UPackage* Z_Construct_UPackage__Script_InVideo();
// End Cross Module References
	DEFINE_FUNCTION(AInSceneRecord::execStoptRecord)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StoptRecord();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AInSceneRecord::execStartRecord)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
		P_GET_PROPERTY(FIntProperty,Z_Param_Fps);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartRecord(Z_Param_FilePath,Z_Param_Fps);
		P_NATIVE_END;
	}
	void AInSceneRecord::StaticRegisterNativesAInSceneRecord()
	{
		UClass* Class = AInSceneRecord::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "StartRecord", &AInSceneRecord::execStartRecord },
			{ "StoptRecord", &AInSceneRecord::execStoptRecord },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics
	{
		struct InSceneRecord_eventStartRecord_Parms
		{
			FString FilePath;
			int32 Fps;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Fps_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_Fps;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InSceneRecord_eventStartRecord_Parms, FilePath), METADATA_PARAMS(Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::NewProp_FilePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::NewProp_FilePath_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::NewProp_Fps_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::NewProp_Fps = { "Fps", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InSceneRecord_eventStartRecord_Parms, Fps), METADATA_PARAMS(Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::NewProp_Fps_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::NewProp_Fps_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::NewProp_FilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::NewProp_Fps,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::Function_MetaDataParams[] = {
		{ "Category", "InVideo" },
		{ "CPP_Default_Fps", "25" },
		{ "ModuleRelativePath", "Public/InSceneRecord.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInSceneRecord, nullptr, "StartRecord", nullptr, nullptr, sizeof(Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::InSceneRecord_eventStartRecord_Parms), Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AInSceneRecord_StartRecord()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInSceneRecord_StartRecord_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AInSceneRecord_StoptRecord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInSceneRecord_StoptRecord_Statics::Function_MetaDataParams[] = {
		{ "Category", "InVideo" },
		{ "ModuleRelativePath", "Public/InSceneRecord.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInSceneRecord_StoptRecord_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInSceneRecord, nullptr, "StoptRecord", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AInSceneRecord_StoptRecord_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AInSceneRecord_StoptRecord_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AInSceneRecord_StoptRecord()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInSceneRecord_StoptRecord_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AInSceneRecord);
	UClass* Z_Construct_UClass_AInSceneRecord_NoRegister()
	{
		return AInSceneRecord::StaticClass();
	}
	struct Z_Construct_UClass_AInSceneRecord_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInSceneRecord_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_InVideo,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AInSceneRecord_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AInSceneRecord_StartRecord, "StartRecord" }, // 3886555702
		{ &Z_Construct_UFunction_AInSceneRecord_StoptRecord, "StoptRecord" }, // 3526878535
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInSceneRecord_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InSceneRecord.h" },
		{ "ModuleRelativePath", "Public/InSceneRecord.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInSceneRecord_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInSceneRecord>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AInSceneRecord_Statics::ClassParams = {
		&AInSceneRecord::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AInSceneRecord_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AInSceneRecord_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AInSceneRecord()
	{
		if (!Z_Registration_Info_UClass_AInSceneRecord.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AInSceneRecord.OuterSingleton, Z_Construct_UClass_AInSceneRecord_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AInSceneRecord.OuterSingleton;
	}
	template<> INVIDEO_API UClass* StaticClass<AInSceneRecord>()
	{
		return AInSceneRecord::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInSceneRecord);
	AInSceneRecord::~AInSceneRecord() {}
	struct Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InSceneRecord_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InSceneRecord_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AInSceneRecord, AInSceneRecord::StaticClass, TEXT("AInSceneRecord"), &Z_Registration_Info_UClass_AInSceneRecord, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AInSceneRecord), 2114712870U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InSceneRecord_h_558639620(TEXT("/Script/InVideo"),
		Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InSceneRecord_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InSceneRecord_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
