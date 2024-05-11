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

	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void SetupPPT2PNGServer();
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void InitPPT2PNGScript();
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void LoadPNG2Texture(TArray<UTexture2D*>& Texs,FString Dir);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static UTexture2D* LoadPNG2TextureFromFile(const FString& FilePath);
	static TSharedPtr<IImageWrapper> GetImageWrapperByExtention(const FString& ImagePath);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static TMap<FString,FString> GetDirType(const TArray<FString>& Dirs);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static TArray<FTexList> LoadAllTextureFromDirList(const TArray<FString>& Dirs);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static TArray<FString> GetAllSubdirectories(const FString& Dir);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void GetClassifyDir(const FString RootDir,TArray<FString>& ImageDirs,TArray<FString>& VideoDirs,TArray<FString>& OptionalDirs);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static FString GetKeyByDir(const FString& Dir);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static TArray<FString> GetFilesFromDir(const FString& Dir);

	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static bool ChineseCompare(FString Source,FString Target);
	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static void ChineseSrot(TArray<FString>& Results,TArray<FString> StrArr);

	UFUNCTION(BlueprintCallable,Category="CommonFunLib")
	static TMap<FString,FString> GetAllFilesFromDir(const FString& Dir);
};
