// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonFunLib.h"

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
	FString NewPath = Dir + FPaths::GetCleanFilename(File);
	IFileManager::Get().Copy(*File, *NewPath);
	UE_LOG(LogTemp,Log,TEXT("Copy %s to %s"),*File,*NewPath);
}
