#pragma once
#include "IImageWrapper.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonFunLib.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LOGPPT2PNG, All, All)

USTRUCT(BlueprintType)
struct FTexList
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite)
	FString Key;
	UPROPERTY(BlueprintReadWrite)
	TArray<UTexture2D*> Texs;
};

UCLASS()
class ZJCHINAMOBILE_API UCommonFunLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable,Category="PPT2PNG")
	static void SetupPPT2PNGServer();
	UFUNCTION(BlueprintCallable,Category="PPT2PNG")
	static void InitPPT2PNGScript();
	UFUNCTION(BlueprintCallable,Category="PPT2PNG")
	static void LoadPNG2Texture(TArray<UTexture2D*>& Texs,FString& Key,FString Dir);
	static TSharedPtr<IImageWrapper> GetImageWrapperByExtention(const FString& ImagePath);
	UFUNCTION(BlueprintCallable,Category="PPT2PNG")
	static TArray<FTexList> LoadAllTextureRecursive(const FString& Dir);
	static TArray<FString> GetAllSubdirectories(const FString& Dir);
};
