// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonFunLib.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows.h"
#include "Windows/HideWindowsPlatformTypes.h"
#include "Engine.h"

void UCommonFunLib::CopyFilesTo(TArray<FString> Files, FString Dir)
{
	for(FString File : Files)
	{
		FString NewPath = Dir + FPaths::GetCleanFilename(File);
		IFileManager::Get().Copy(*File, *NewPath);
		UE_LOG(LogTemp,Log,TEXT("Copy %s to %s"),*File,*NewPath);
	}
}

void UCommonFunLib::CopyFileTo(FString File, FString Dir)
{
	char* Source = TCHAR_TO_ANSI(*File);
	char* Destination = "E:/Git/ZJChinaMobile/ZJChinaMobile/DiyContents/1/123.pptx";
}

void UCommonFunLib::SetScreenResolution(int Widget, int Height)
{
	GEngine->GetGameUserSettings()->SetFullscreenMode(EWindowMode::Windowed);
	GEngine->GetGameUserSettings()->SetScreenResolution(FIntPoint(Widget, Height));
	GEngine->GetGameUserSettings()->ApplySettings(true);
}
