// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SocketIOClient/Public/SocketIOFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSocketIOFunctionLibrary() {}
// Cross Module References
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USocketIOFunctionLibrary_NoRegister();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USocketIOFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_SocketIOClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	SIOJSON_API UClass* Z_Construct_UClass_USIOJsonValue_NoRegister();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USocketIOClientComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(USocketIOFunctionLibrary::execCallFunctionByName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FunctionName);
		P_GET_OBJECT(UObject,Z_Param_Target);
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_OBJECT(USIOJsonValue,Z_Param_Param);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USocketIOFunctionLibrary::CallFunctionByName(Z_Param_FunctionName,Z_Param_Target,Z_Param_WorldContextObject,Z_Param_Param);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOFunctionLibrary::execConstructSocketIOComponent)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USocketIOClientComponent**)Z_Param__Result=USocketIOFunctionLibrary::ConstructSocketIOComponent(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	void USocketIOFunctionLibrary::StaticRegisterNativesUSocketIOFunctionLibrary()
	{
		UClass* Class = USocketIOFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CallFunctionByName", &USocketIOFunctionLibrary::execCallFunctionByName },
			{ "ConstructSocketIOComponent", &USocketIOFunctionLibrary::execConstructSocketIOComponent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics
	{
		struct SocketIOFunctionLibrary_eventCallFunctionByName_Parms
		{
			FString FunctionName;
			UObject* Target;
			UObject* WorldContextObject;
			USIOJsonValue* Param;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FunctionName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FunctionName;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Target;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Param;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_FunctionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_FunctionName = { "FunctionName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOFunctionLibrary_eventCallFunctionByName_Parms, FunctionName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_FunctionName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_FunctionName_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOFunctionLibrary_eventCallFunctionByName_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOFunctionLibrary_eventCallFunctionByName_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_Param = { "Param", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOFunctionLibrary_eventCallFunctionByName_Parms, Param), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SocketIOFunctionLibrary_eventCallFunctionByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SocketIOFunctionLibrary_eventCallFunctionByName_Parms), &Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_FunctionName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_Target,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_Param,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Utility" },
		{ "Comment", "/** Call a function by name with SIOJsonValue signature. Utility for RPC in BPs*/" },
		{ "ModuleRelativePath", "Public/SocketIOFunctionLibrary.h" },
		{ "ToolTip", "Call a function by name with SIOJsonValue signature. Utility for RPC in BPs" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOFunctionLibrary, nullptr, "CallFunctionByName", nullptr, nullptr, sizeof(SocketIOFunctionLibrary_eventCallFunctionByName_Parms), Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics
	{
		struct SocketIOFunctionLibrary_eventConstructSocketIOComponent_Parms
		{
			UObject* WorldContextObject;
			USocketIOClientComponent* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOFunctionLibrary_eventConstructSocketIOComponent_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOFunctionLibrary_eventConstructSocketIOComponent_Parms, ReturnValue), Z_Construct_UClass_USocketIOClientComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Client Static" },
		{ "Comment", "/** Static function to spawn a component that doesn't attach */" },
		{ "ModuleRelativePath", "Public/SocketIOFunctionLibrary.h" },
		{ "ToolTip", "Static function to spawn a component that doesn't attach" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOFunctionLibrary, nullptr, "ConstructSocketIOComponent", nullptr, nullptr, sizeof(SocketIOFunctionLibrary_eventConstructSocketIOComponent_Parms), Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USocketIOFunctionLibrary_NoRegister()
	{
		return USocketIOFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_USocketIOFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USocketIOFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_SocketIOClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USocketIOFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName, "CallFunctionByName" }, // 394445266
		{ &Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent, "ConstructSocketIOComponent" }, // 3529973463
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Static spawning support library\n */" },
		{ "IncludePath", "SocketIOFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/SocketIOFunctionLibrary.h" },
		{ "ToolTip", "Static spawning support library" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USocketIOFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USocketIOFunctionLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USocketIOFunctionLibrary_Statics::ClassParams = {
		&USocketIOFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_USocketIOFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USocketIOFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USocketIOFunctionLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USocketIOFunctionLibrary, 1571377978);
	template<> SOCKETIOCLIENT_API UClass* StaticClass<USocketIOFunctionLibrary>()
	{
		return USocketIOFunctionLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USocketIOFunctionLibrary(Z_Construct_UClass_USocketIOFunctionLibrary, &USocketIOFunctionLibrary::StaticClass, TEXT("/Script/SocketIOClient"), TEXT("USocketIOFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USocketIOFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
