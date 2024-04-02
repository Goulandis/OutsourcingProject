// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PPT2PNG/Public/PPT2PNGFunLib.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePPT2PNGFunLib() {}
// Cross Module References
	PPT2PNG_API UClass* Z_Construct_UClass_UPPT2PNGFunLib_NoRegister();
	PPT2PNG_API UClass* Z_Construct_UClass_UPPT2PNGFunLib();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_PPT2PNG();
// End Cross Module References
	void UPPT2PNGFunLib::StaticRegisterNativesUPPT2PNGFunLib()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPPT2PNGFunLib);
	UClass* Z_Construct_UClass_UPPT2PNGFunLib_NoRegister()
	{
		return UPPT2PNGFunLib::StaticClass();
	}
	struct Z_Construct_UClass_UPPT2PNGFunLib_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPPT2PNGFunLib_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PPT2PNG,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPPT2PNGFunLib_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PPT2PNGFunLib.h" },
		{ "ModuleRelativePath", "Public/PPT2PNGFunLib.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPPT2PNGFunLib_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPPT2PNGFunLib>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPPT2PNGFunLib_Statics::ClassParams = {
		&UPPT2PNGFunLib::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPPT2PNGFunLib_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPPT2PNGFunLib_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPPT2PNGFunLib()
	{
		if (!Z_Registration_Info_UClass_UPPT2PNGFunLib.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPPT2PNGFunLib.OuterSingleton, Z_Construct_UClass_UPPT2PNGFunLib_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPPT2PNGFunLib.OuterSingleton;
	}
	template<> PPT2PNG_API UClass* StaticClass<UPPT2PNGFunLib>()
	{
		return UPPT2PNGFunLib::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPPT2PNGFunLib);
	struct Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPPT2PNGFunLib, UPPT2PNGFunLib::StaticClass, TEXT("UPPT2PNGFunLib"), &Z_Registration_Info_UClass_UPPT2PNGFunLib, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPPT2PNGFunLib), 1041944301U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_1451677867(TEXT("/Script/PPT2PNG"),
		Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
