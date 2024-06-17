// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InVideo/Public/InVideoWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInVideoWidget() {}
// Cross Module References
	INVIDEO_API UClass* Z_Construct_UClass_UInVideoWidget();
	INVIDEO_API UClass* Z_Construct_UClass_UInVideoWidget_NoRegister();
	INVIDEO_API UFunction* Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature();
	INVIDEO_API UFunction* Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature();
	INVIDEO_API UFunction* Z_Construct_UDelegateFunction_InVideo_DelegatePlaySucceeded__DelegateSignature();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_InVideo();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_InVideo_DelegatePlaySucceeded__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_InVideo_DelegatePlaySucceeded__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InVideoWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_InVideo_DelegatePlaySucceeded__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_InVideo, nullptr, "DelegatePlaySucceeded__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_InVideo_DelegatePlaySucceeded__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InVideo_DelegatePlaySucceeded__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_InVideo_DelegatePlaySucceeded__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InVideo_DelegatePlaySucceeded__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InVideoWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_InVideo, nullptr, "DelegatePlayFailed__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InVideoWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_InVideo, nullptr, "DelegateFirstFrame__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UInVideoWidget::execStopPlay)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopPlay();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInVideoWidget::execStartPlay)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_VideoURL);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_Failed);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_FirstFrame);
		P_GET_UBOOL(Z_Param_RealMode);
		P_GET_PROPERTY(FIntProperty,Z_Param_Fps);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartPlay(Z_Param_VideoURL,FDelegatePlayFailed(Z_Param_Failed),FDelegateFirstFrame(Z_Param_FirstFrame),Z_Param_RealMode,Z_Param_Fps);
		P_NATIVE_END;
	}
	void UInVideoWidget::StaticRegisterNativesUInVideoWidget()
	{
		UClass* Class = UInVideoWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "StartPlay", &UInVideoWidget::execStartPlay },
			{ "StopPlay", &UInVideoWidget::execStopPlay },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics
	{
		struct InVideoWidget_eventStartPlay_Parms
		{
			FString VideoURL;
			FScriptDelegate Failed;
			FScriptDelegate FirstFrame;
			bool RealMode;
			int32 Fps;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VideoURL_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_VideoURL;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_Failed;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_FirstFrame;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RealMode_MetaData[];
#endif
		static void NewProp_RealMode_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_RealMode;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_VideoURL_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_VideoURL = { "VideoURL", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InVideoWidget_eventStartPlay_Parms, VideoURL), METADATA_PARAMS(Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_VideoURL_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_VideoURL_MetaData)) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_Failed = { "Failed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InVideoWidget_eventStartPlay_Parms, Failed), Z_Construct_UDelegateFunction_InVideo_DelegatePlayFailed__DelegateSignature, METADATA_PARAMS(nullptr, 0) }; // 1259664695
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_FirstFrame = { "FirstFrame", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InVideoWidget_eventStartPlay_Parms, FirstFrame), Z_Construct_UDelegateFunction_InVideo_DelegateFirstFrame__DelegateSignature, METADATA_PARAMS(nullptr, 0) }; // 3567778404
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_RealMode_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_RealMode_SetBit(void* Obj)
	{
		((InVideoWidget_eventStartPlay_Parms*)Obj)->RealMode = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_RealMode = { "RealMode", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(InVideoWidget_eventStartPlay_Parms), &Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_RealMode_SetBit, METADATA_PARAMS(Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_RealMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_RealMode_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_Fps_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_Fps = { "Fps", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InVideoWidget_eventStartPlay_Parms, Fps), METADATA_PARAMS(Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_Fps_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_Fps_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_VideoURL,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_Failed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_FirstFrame,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_RealMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::NewProp_Fps,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::Function_MetaDataParams[] = {
		{ "Category", "InVideo" },
		{ "CPP_Default_Fps", "25" },
		{ "CPP_Default_RealMode", "true" },
		{ "ModuleRelativePath", "Public/InVideoWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInVideoWidget, nullptr, "StartPlay", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::InVideoWidget_eventStartPlay_Parms), Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInVideoWidget_StartPlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInVideoWidget_StartPlay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInVideoWidget_StopPlay_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInVideoWidget_StopPlay_Statics::Function_MetaDataParams[] = {
		{ "Category", "InVideo" },
		{ "ModuleRelativePath", "Public/InVideoWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInVideoWidget_StopPlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInVideoWidget, nullptr, "StopPlay", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInVideoWidget_StopPlay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInVideoWidget_StopPlay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInVideoWidget_StopPlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInVideoWidget_StopPlay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInVideoWidget);
	UClass* Z_Construct_UClass_UInVideoWidget_NoRegister()
	{
		return UInVideoWidget::StaticClass();
	}
	struct Z_Construct_UClass_UInVideoWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageVideo_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ImageVideo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInVideoWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_InVideo,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInVideoWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInVideoWidget_StartPlay, "StartPlay" }, // 1036575448
		{ &Z_Construct_UFunction_UInVideoWidget_StopPlay, "StopPlay" }, // 514426102
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInVideoWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "InVideoWidget.h" },
		{ "ModuleRelativePath", "Public/InVideoWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInVideoWidget_Statics::NewProp_ImageVideo_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "InVideo" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InVideoWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInVideoWidget_Statics::NewProp_ImageVideo = { "ImageVideo", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UInVideoWidget, ImageVideo), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInVideoWidget_Statics::NewProp_ImageVideo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInVideoWidget_Statics::NewProp_ImageVideo_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInVideoWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInVideoWidget_Statics::NewProp_ImageVideo,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInVideoWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInVideoWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInVideoWidget_Statics::ClassParams = {
		&UInVideoWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UInVideoWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UInVideoWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInVideoWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInVideoWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInVideoWidget()
	{
		if (!Z_Registration_Info_UClass_UInVideoWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInVideoWidget.OuterSingleton, Z_Construct_UClass_UInVideoWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInVideoWidget.OuterSingleton;
	}
	template<> INVIDEO_API UClass* StaticClass<UInVideoWidget>()
	{
		return UInVideoWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInVideoWidget);
	UInVideoWidget::~UInVideoWidget() {}
	struct Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInVideoWidget, UInVideoWidget::StaticClass, TEXT("UInVideoWidget"), &Z_Registration_Info_UClass_UInVideoWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInVideoWidget), 2084333689U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_3074693836(TEXT("/Script/InVideo"),
		Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
