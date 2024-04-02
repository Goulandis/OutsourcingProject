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
	PPT2PNG_API UScriptStruct* Z_Construct_UScriptStruct_FTexList();
	UPackage* Z_Construct_UPackage__Script_PPT2PNG();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	PPT2PNG_API UClass* Z_Construct_UClass_UPPT2PNGFunLib_NoRegister();
	PPT2PNG_API UClass* Z_Construct_UClass_UPPT2PNGFunLib();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TexList;
class UScriptStruct* FTexList::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TexList.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TexList.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTexList, Z_Construct_UPackage__Script_PPT2PNG(), TEXT("TexList"));
	}
	return Z_Registration_Info_UScriptStruct_TexList.OuterSingleton;
}
template<> PPT2PNG_API UScriptStruct* StaticStruct<FTexList>()
{
	return FTexList::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FTexList_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Texs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Texs;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTexList_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PPT2PNGFunLib.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FTexList_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTexList>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Key_MetaData[] = {
		{ "Category", "TexList" },
		{ "ModuleRelativePath", "Public/PPT2PNGFunLib.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTexList, Key), METADATA_PARAMS(Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Key_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Key_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Texs_Inner = { "Texs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Texs_MetaData[] = {
		{ "Category", "TexList" },
		{ "ModuleRelativePath", "Public/PPT2PNGFunLib.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Texs = { "Texs", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTexList, Texs), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Texs_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Texs_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTexList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Texs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTexList_Statics::NewProp_Texs,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTexList_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PPT2PNG,
		nullptr,
		&NewStructOps,
		"TexList",
		sizeof(FTexList),
		alignof(FTexList),
		Z_Construct_UScriptStruct_FTexList_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTexList_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTexList_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTexList_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTexList()
	{
		if (!Z_Registration_Info_UScriptStruct_TexList.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TexList.InnerSingleton, Z_Construct_UScriptStruct_FTexList_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_TexList.InnerSingleton;
	}
	DEFINE_FUNCTION(UPPT2PNGFunLib::execLoadAllTextureRecursive)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Dir);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FTexList>*)Z_Param__Result=UPPT2PNGFunLib::LoadAllTextureRecursive(Z_Param_Dir);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPPT2PNGFunLib::execLoadPNG2Texture)
	{
		P_GET_TARRAY_REF(UTexture2D*,Z_Param_Out_Texs);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Key);
		P_GET_PROPERTY(FStrProperty,Z_Param_Dir);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPPT2PNGFunLib::LoadPNG2Texture(Z_Param_Out_Texs,Z_Param_Out_Key,Z_Param_Dir);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPPT2PNGFunLib::execInitPPT2PNGScript)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UPPT2PNGFunLib::InitPPT2PNGScript();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPPT2PNGFunLib::execSetupPPT2PNGServer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UPPT2PNGFunLib::SetupPPT2PNGServer();
		P_NATIVE_END;
	}
	void UPPT2PNGFunLib::StaticRegisterNativesUPPT2PNGFunLib()
	{
		UClass* Class = UPPT2PNGFunLib::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "InitPPT2PNGScript", &UPPT2PNGFunLib::execInitPPT2PNGScript },
			{ "LoadAllTextureRecursive", &UPPT2PNGFunLib::execLoadAllTextureRecursive },
			{ "LoadPNG2Texture", &UPPT2PNGFunLib::execLoadPNG2Texture },
			{ "SetupPPT2PNGServer", &UPPT2PNGFunLib::execSetupPPT2PNGServer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPPT2PNGFunLib_InitPPT2PNGScript_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPPT2PNGFunLib_InitPPT2PNGScript_Statics::Function_MetaDataParams[] = {
		{ "Category", "PPT2PNG" },
		{ "ModuleRelativePath", "Public/PPT2PNGFunLib.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPPT2PNGFunLib_InitPPT2PNGScript_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPPT2PNGFunLib, nullptr, "InitPPT2PNGScript", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPPT2PNGFunLib_InitPPT2PNGScript_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPPT2PNGFunLib_InitPPT2PNGScript_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPPT2PNGFunLib_InitPPT2PNGScript()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPPT2PNGFunLib_InitPPT2PNGScript_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics
	{
		struct PPT2PNGFunLib_eventLoadAllTextureRecursive_Parms
		{
			FString Dir;
			TArray<FTexList> ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Dir_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Dir;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::NewProp_Dir_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::NewProp_Dir = { "Dir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PPT2PNGFunLib_eventLoadAllTextureRecursive_Parms, Dir), METADATA_PARAMS(Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::NewProp_Dir_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::NewProp_Dir_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FTexList, METADATA_PARAMS(nullptr, 0) }; // 3549464087
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PPT2PNGFunLib_eventLoadAllTextureRecursive_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 3549464087
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::NewProp_Dir,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::Function_MetaDataParams[] = {
		{ "Category", "PPT2PNG" },
		{ "ModuleRelativePath", "Public/PPT2PNGFunLib.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPPT2PNGFunLib, nullptr, "LoadAllTextureRecursive", nullptr, nullptr, sizeof(Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::PPT2PNGFunLib_eventLoadAllTextureRecursive_Parms), Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics
	{
		struct PPT2PNGFunLib_eventLoadPNG2Texture_Parms
		{
			TArray<UTexture2D*> Texs;
			FString Key;
			FString Dir;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texs_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Texs;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Dir;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::NewProp_Texs_Inner = { "Texs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::NewProp_Texs = { "Texs", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PPT2PNGFunLib_eventLoadPNG2Texture_Parms, Texs), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PPT2PNGFunLib_eventLoadPNG2Texture_Parms, Key), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::NewProp_Dir = { "Dir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PPT2PNGFunLib_eventLoadPNG2Texture_Parms, Dir), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::NewProp_Texs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::NewProp_Texs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::NewProp_Dir,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::Function_MetaDataParams[] = {
		{ "Category", "PPT2PNG" },
		{ "ModuleRelativePath", "Public/PPT2PNGFunLib.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPPT2PNGFunLib, nullptr, "LoadPNG2Texture", nullptr, nullptr, sizeof(Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::PPT2PNGFunLib_eventLoadPNG2Texture_Parms), Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04442401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPPT2PNGFunLib_SetupPPT2PNGServer_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPPT2PNGFunLib_SetupPPT2PNGServer_Statics::Function_MetaDataParams[] = {
		{ "Category", "PPT2PNG" },
		{ "ModuleRelativePath", "Public/PPT2PNGFunLib.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPPT2PNGFunLib_SetupPPT2PNGServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPPT2PNGFunLib, nullptr, "SetupPPT2PNGServer", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPPT2PNGFunLib_SetupPPT2PNGServer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPPT2PNGFunLib_SetupPPT2PNGServer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPPT2PNGFunLib_SetupPPT2PNGServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPPT2PNGFunLib_SetupPPT2PNGServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPPT2PNGFunLib);
	UClass* Z_Construct_UClass_UPPT2PNGFunLib_NoRegister()
	{
		return UPPT2PNGFunLib::StaticClass();
	}
	struct Z_Construct_UClass_UPPT2PNGFunLib_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
	const FClassFunctionLinkInfo Z_Construct_UClass_UPPT2PNGFunLib_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPPT2PNGFunLib_InitPPT2PNGScript, "InitPPT2PNGScript" }, // 2729189609
		{ &Z_Construct_UFunction_UPPT2PNGFunLib_LoadAllTextureRecursive, "LoadAllTextureRecursive" }, // 3493857271
		{ &Z_Construct_UFunction_UPPT2PNGFunLib_LoadPNG2Texture, "LoadPNG2Texture" }, // 4220979565
		{ &Z_Construct_UFunction_UPPT2PNGFunLib_SetupPPT2PNGServer, "SetupPPT2PNGServer" }, // 600824520
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPPT2PNGFunLib_Statics::Class_MetaDataParams[] = {
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
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_Statics::ScriptStructInfo[] = {
		{ FTexList::StaticStruct, Z_Construct_UScriptStruct_FTexList_Statics::NewStructOps, TEXT("TexList"), &Z_Registration_Info_UScriptStruct_TexList, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTexList), 3549464087U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPPT2PNGFunLib, UPPT2PNGFunLib::StaticClass, TEXT("UPPT2PNGFunLib"), &Z_Registration_Info_UClass_UPPT2PNGFunLib, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPPT2PNGFunLib), 236308720U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_1453524605(TEXT("/Script/PPT2PNG"),
		Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ZJChinaMobile_Plugins_PPT2PNG_Source_PPT2PNG_Public_PPT2PNGFunLib_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
