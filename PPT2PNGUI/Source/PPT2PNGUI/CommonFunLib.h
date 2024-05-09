// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonFunLib.generated.h"

USTRUCT(BlueprintType)
struct FContent
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite)
	FString Key;
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> Content;
};

UCLASS()
class PPT2PNGUI_API UCommonFunLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void CopyFilesTo(TArray<FString> Files,FString Dir);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void CopyFileTo(FString File,FString Dir);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void CleanFolder(FString Dir);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void SetScreenResolution(int Widget,int Height);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void SetupPPT2PNG(FString Path);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void InitPPT2PNGScript(FString Path);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static TArray<FContent> GetContentFromDir(FString Dir);
	static TArray<FString> GetAllSubdirectories(const FString& Dir);
};
