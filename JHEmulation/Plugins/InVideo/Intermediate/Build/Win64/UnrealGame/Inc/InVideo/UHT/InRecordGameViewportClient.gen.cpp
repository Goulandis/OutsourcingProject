// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InVideo/Public/InRecordGameViewportClient.h"
#include "Engine/Classes/Engine/Engine.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInRecordGameViewportClient() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameViewportClient();
	INVIDEO_API UClass* Z_Construct_UClass_UInRecordGameViewportClient();
	INVIDEO_API UClass* Z_Construct_UClass_UInRecordGameViewportClient_NoRegister();
	UPackage* Z_Construct_UPackage__Script_InVideo();
// End Cross Module References
	void UInRecordGameViewportClient::StaticRegisterNativesUInRecordGameViewportClient()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInRecordGameViewportClient);
	UClass* Z_Construct_UClass_UInRecordGameViewportClient_NoRegister()
	{
		return UInRecordGameViewportClient::StaticClass();
	}
	struct Z_Construct_UClass_UInRecordGameViewportClient_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInRecordGameViewportClient_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameViewportClient,
		(UObject* (*)())Z_Construct_UPackage__Script_InVideo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInRecordGameViewportClient_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "InRecordGameViewportClient.h" },
		{ "ModuleRelativePath", "Public/InRecordGameViewportClient.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInRecordGameViewportClient_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInRecordGameViewportClient>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInRecordGameViewportClient_Statics::ClassParams = {
		&UInRecordGameViewportClient::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000ACu,
		METADATA_PARAMS(Z_Construct_UClass_UInRecordGameViewportClient_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInRecordGameViewportClient_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInRecordGameViewportClient()
	{
		if (!Z_Registration_Info_UClass_UInRecordGameViewportClient.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInRecordGameViewportClient.OuterSingleton, Z_Construct_UClass_UInRecordGameViewportClient_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInRecordGameViewportClient.OuterSingleton;
	}
	template<> INVIDEO_API UClass* StaticClass<UInRecordGameViewportClient>()
	{
		return UInRecordGameViewportClient::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInRecordGameViewportClient);
	UInRecordGameViewportClient::~UInRecordGameViewportClient() {}
	struct Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InRecordGameViewportClient_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InRecordGameViewportClient_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInRecordGameViewportClient, UInRecordGameViewportClient::StaticClass, TEXT("UInRecordGameViewportClient"), &Z_Registration_Info_UClass_UInRecordGameViewportClient, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInRecordGameViewportClient), 1330312818U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InRecordGameViewportClient_h_2688236951(TEXT("/Script/InVideo"),
		Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InRecordGameViewportClient_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InRecordGameViewportClient_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
