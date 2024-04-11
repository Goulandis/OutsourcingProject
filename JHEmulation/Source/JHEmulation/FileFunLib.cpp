#include "FileFunLib.h"
#include <string>

#include "IImageWrapper.h"
#include "IImageWrapperModule.h"

FString UFileFunLib::ReadFile(const FString& Path,bool& Rel)
{
	FString Content;
	Rel = FFileHelper::LoadFileToString(Content,*Path);
	return Content;
}

TArray<FString> UFileFunLib::ReadFileByLine(const FString& Path, bool& Rel)
{
	TArray<FString> Lines;
	Rel = FFileHelper::LoadFileToStringArray(Lines,*Path);
	return Lines;
}

bool UFileFunLib::WriteFile(const FString& Path, const FString& Content)
{
	return FFileHelper::SaveStringToFile(Content,*Path);
}

UTexture2D* UFileFunLib::LoadTexture2DFromFile(const FString& ImagePath)
{
	UTexture2D* Texture = nullptr;
	if(!FPlatformFileManager::Get().GetPlatformFile().FileExists(*ImagePath))
	{
		return nullptr;
	}
	TArray<uint8> RawFileData;
	if(!FFileHelper::LoadFileToArray(RawFileData,*ImagePath))
	{
		return nullptr;
	}
	TSharedPtr<IImageWrapper> ImageWrapper;
	IImageWrapperModule& Module = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	if(ImagePath.EndsWith(".png"))
	{
		ImageWrapper = Module.CreateImageWrapper(EImageFormat::PNG);
	}
	else if (ImagePath.EndsWith(".jpg") || ImagePath.EndsWith(".jpeg"))
	{
		ImageWrapper = Module.CreateImageWrapper(EImageFormat::JPEG);
	}
	if(ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(),RawFileData.Num()))
	{
		TArray<uint8> UncompressedRGBA;
		if(ImageWrapper->GetRaw(ERGBFormat::RGBA,8,UncompressedRGBA))
		{
			Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(),ImageWrapper->GetHeight(),PF_R8G8B8A8);
			if(Texture != nullptr)
			{
				void* TextureData = Texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(TextureData,UncompressedRGBA.GetData(),UncompressedRGBA.Num());
				Texture->PlatformData->Mips[0].BulkData.Unlock();
				Texture->UpdateResource();
			}
		}
	}
	return Texture;
}
