// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInVideo_init() {}
	INVIDEO_API UFunction* Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature();
	INVIDEO_API UFunction* Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature();
	INVIDEO_API UFunction* Z_Construct_UDelegateFunction_InVideo_DelegatePlaySucceeded__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_InVideo;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_InVideo()
	{
		if (!Z_Registration_Info_UPackage__Script_InVideo.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_InVideo_DelegatePlaySucceeded__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/InVideo",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x1E7EEC53,
				0xECAF7987,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_InVideo.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_InVideo.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_InVideo(Z_Construct_UPackage__Script_InVideo, TEXT("/Script/InVideo"), Z_Registration_Info_UPackage__Script_InVideo, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x1E7EEC53, 0xECAF7987));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
