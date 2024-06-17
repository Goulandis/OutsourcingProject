// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InVideoWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INVIDEO_InVideoWidget_generated_h
#error "InVideoWidget.generated.h already included, missing '#pragma once' in InVideoWidget.h"
#endif
#define INVIDEO_InVideoWidget_generated_h

#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_19_DELEGATE \
static inline void FDelegatePlaySucceeded_DelegateWrapper(const FScriptDelegate& DelegatePlaySucceeded) \
{ \
	DelegatePlaySucceeded.ProcessDelegate<UObject>(NULL); \
}


#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_20_DELEGATE \
static inline void FDelegatePlayFailed_DelegateWrapper(const FScriptDelegate& DelegatePlayFailed) \
{ \
	DelegatePlayFailed.ProcessDelegate<UObject>(NULL); \
}


#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_21_DELEGATE \
static inline void FDelegateFirstFrame_DelegateWrapper(const FScriptDelegate& DelegateFirstFrame) \
{ \
	DelegateFirstFrame.ProcessDelegate<UObject>(NULL); \
}


#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_SPARSE_DATA
#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStopPlay); \
	DECLARE_FUNCTION(execStartPlay);


#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStopPlay); \
	DECLARE_FUNCTION(execStartPlay);


#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_ACCESSORS
#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInVideoWidget(); \
	friend struct Z_Construct_UClass_UInVideoWidget_Statics; \
public: \
	DECLARE_CLASS(UInVideoWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/InVideo"), NO_API) \
	DECLARE_SERIALIZER(UInVideoWidget)


#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_INCLASS \
private: \
	static void StaticRegisterNativesUInVideoWidget(); \
	friend struct Z_Construct_UClass_UInVideoWidget_Statics; \
public: \
	DECLARE_CLASS(UInVideoWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/InVideo"), NO_API) \
	DECLARE_SERIALIZER(UInVideoWidget)


#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInVideoWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInVideoWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInVideoWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInVideoWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInVideoWidget(UInVideoWidget&&); \
	NO_API UInVideoWidget(const UInVideoWidget&); \
public: \
	NO_API virtual ~UInVideoWidget();


#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInVideoWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInVideoWidget(UInVideoWidget&&); \
	NO_API UInVideoWidget(const UInVideoWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInVideoWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInVideoWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInVideoWidget) \
	NO_API virtual ~UInVideoWidget();


#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_73_PROLOG
#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_SPARSE_DATA \
	FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_RPC_WRAPPERS \
	FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_ACCESSORS \
	FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_INCLASS \
	FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_SPARSE_DATA \
	FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_ACCESSORS \
	FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_INCLASS_NO_PURE_DECLS \
	FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h_76_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVIDEO_API UClass* StaticClass<class UInVideoWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_JHEmulation_Plugins_InVideo_Source_InVideo_Public_InVideoWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
