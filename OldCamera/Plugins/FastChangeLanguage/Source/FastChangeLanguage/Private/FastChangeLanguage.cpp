// Copyright Epic Games, Inc. All Rights Reserved.

#include "FastChangeLanguage.h"
#include "../Plugins/Experimental/PythonScriptPlugin/Source/PythonScriptPlugin/Private/PythonScriptPlugin.h"

#define LOCTEXT_NAMESPACE "FFastChangeLanguageModule"

void FFastChangeLanguageModule::StartupModule()
{
	TickHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateLambda([this](float DeltaTime)
		{
			Tick(DeltaTime);
			return true;
		}));
}

void FFastChangeLanguageModule::ShutdownModule()
{
	
	
}

void FFastChangeLanguageModule::Tick(const float InDeltaTime)
{
	// �ο� Python �ٷ���� | �����ʼ�����֮�� ͨ�� tick ����ʼ�� initialize.py �ű�
	if (!bHasTicked) {
		bHasTicked = true;
		FString InitScript = TEXT("py \"") + FPaths::ProjectPluginsDir() / TEXT("FastChangeLanguage/Content/init_unreal.py") + TEXT("\"");
		GEngine->Exec(NULL, InitScript.GetCharArray().GetData());

		//UE_LOG(LogTemp, Error, TEXT("one"));
	}

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFastChangeLanguageModule, FastChangeLanguage)