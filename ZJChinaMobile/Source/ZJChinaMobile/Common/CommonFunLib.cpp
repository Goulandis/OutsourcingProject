#include "CommonFunLib.h"
#include <thread>
#include "IImageWrapperModule.h"
#include "HAL/FileManager.h"
#include <io.h>
#include <string>
#include "Windows/AllowWindowsPlatformTypes.h"
#include <windows.h>
#include "Windows/HideWindowsPlatformTypes.h"

DEFINE_LOG_CATEGORY(LOGPPT2PNG);

void UCommonFunLib::SetupPPT2PNGServer()
{
	FString CmdStr = FPaths::ProjectDir() + "Setup.bat";
	std::string Cmd = TCHAR_TO_UTF8(*CmdStr);
	system(Cmd.c_str());
}

void UCommonFunLib::InitPPT2PNGScript()
{
	FString PyScript = FPaths::ProjectDir() + "PPT2PNG.py";
	FString CmdStr = "python " + PyScript;
	FString BatFile = FPaths::ProjectDir() + "Setup.bat";
	FFileHelper::SaveStringToFile(CmdStr,*BatFile);
}

void UCommonFunLib::LoadPNG2Texture(TArray<UTexture2D*>& Texs, FString& Key, FString Dir)
{
	if(!IFileManager::Get().DirectoryExists(*Dir))
	{
		UE_LOG(LOGPPT2PNG,Error,TEXT("%s is not exists"),*Dir);
		return;
	}
	TArray<FString> Files;
	IFileManager::Get().FindFiles(Files,*Dir);
	for(FString File : Files)
	{
		UTexture2D* Tex = nullptr;
		FString ImgPath = Dir + "/" + File;
		if(!IFileManager::Get().FileExists(*ImgPath))
		{
			UE_LOG(LOGPPT2PNG,Error,TEXT("PNG %s is not exists"),*ImgPath);
			continue;
		}
		TArray<uint8> RawFileData;
		if(!FFileHelper::LoadFileToArray(RawFileData,*ImgPath))
		{
			UE_LOG(LOGPPT2PNG,Error,TEXT("Failed to load Img to memory : %s"),*ImgPath);
			continue;
		}
		TSharedPtr<IImageWrapper> ImageWrapper = GetImageWrapperByExtention(ImgPath);
		if(ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(),RawFileData.Num()))
		{
			TArray<uint8> UncompressedRGBBA;
			if(ImageWrapper->GetRaw(ERGBFormat::RGBA,8,UncompressedRGBBA))
			{
				Tex = UTexture2D::CreateTransient(ImageWrapper->GetWidth(),ImageWrapper->GetHeight(),PF_R8G8B8A8);
				if(Tex)
				{
					void* TexData = Tex->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
					FMemory::Memcpy(TexData,UncompressedRGBBA.GetData(),UncompressedRGBBA.Num());
					Tex->PlatformData->Mips[0].BulkData.Unlock();
					Tex->UpdateResource();
					Texs.Add(Tex);
				}
			}
		}
	}
	TArray<FString> Arr;
	Dir.ParseIntoArray(Arr,TEXT("/"),false);
	Key = Arr.Last();
}

TSharedPtr<IImageWrapper> UCommonFunLib::GetImageWrapperByExtention(const FString& ImagePath)
{
	IImageWrapperModule& Module = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	if(ImagePath.EndsWith(".png"))
	{
		return Module.CreateImageWrapper(EImageFormat::PNG);
	}
	if(ImagePath.EndsWith(".jpg") || ImagePath.EndsWith(".jpeg"))
	{
		return Module.CreateImageWrapper(EImageFormat::JPEG);
	}
	return nullptr;
}

TArray<FTexList> UCommonFunLib::LoadAllTextureRecursive(const FString& Dir)
{
	TArray<FTexList> Texls;
	if(IFileManager::Get().DirectoryExists(*Dir))
	{
		TArray<FString> DirArr;
		DirArr = GetAllSubdirectories(Dir);
		for(FString SubDir : DirArr)
		{
			TArray<FString> SubDirArr = GetAllSubdirectories(SubDir);
			if(SubDirArr.Num() < 0)
			{
				continue;
			}
			FString PNGDir = SubDirArr[0];
			TArray<UTexture2D*> Texs;
			FString Key;
			LoadPNG2Texture(Texs,Key,PNGDir);
			FTexList Texl;
			Texl.Key = Key;
			Texl.Texs = Texs;
			Texls.Add(Texl);
		}
	}
	return Texls;
}

TArray<FTexList> UCommonFunLib::LoadAllTextureFromDirList(const TArray<FString>& Dirs)
{
	TArray<FTexList> Texls;
	for(FString Dir : Dirs)
	{
		TArray<FString> SubDir = GetAllSubdirectories(Dir);
		if(SubDir.Num() == 0)
		{
			TArray<FString> FileNames;
			IFileManager::Get().FindFiles(FileNames,*Dir);
			bool HasImg = false;
			for(FString FileName : FileNames)
			{
				if(FileName.EndsWith(".png") || FileName.EndsWith(".jpg") || FileName.EndsWith(".jpeg"))
				{
					HasImg = true;
					break;
				}
			}
			if(HasImg)
			{
				TArray<UTexture2D*> Texs;
				FString Key;
				LoadPNG2Texture(Texs,Key,Dir);
				FTexList Texl;
				Texl.Key = Key;
				Texl.Texs = Texs;
				Texls.Add(Texl);
			}
		}
		if(SubDir.Num() > 0)
		{
			TArray<UTexture2D*> Texs;
			FString Key;
			LoadPNG2Texture(Texs,Key,SubDir[0]);
			FTexList Texl;
			Texl.Key = Key;
			Texl.Texs = Texs;
			Texls.Add(Texl);
		}
	}
	return Texls;
}

TArray<FString> UCommonFunLib::GetAllSubdirectories(const FString& Dir)
{
	TArray<FString> Dirs;
	long long hFile = 0;
	struct _finddata_t FileInfo;
	std::string p;
	std::string Path = TCHAR_TO_UTF8(*Dir);
	if ((hFile = _findfirst(p.assign(Path).append("\\*").c_str(), &FileInfo)) != -1)
	{
		do
		{
			if(FileInfo.attrib & _A_SUBDIR)
			{
				const char* DirNameChr = p.assign(Path).append("/").append(FileInfo.name).c_str();
				int Size = MultiByteToWideChar(CP_OEMCP,0,DirNameChr,strlen(DirNameChr)+1,NULL,0);
				wchar_t* DirNameWChr = new wchar_t[Size];
				MultiByteToWideChar(CP_OEMCP,0,DirNameChr,strlen(DirNameChr)+1,DirNameWChr,Size);
				FString Item = DirNameWChr;
				if(!Item.Contains(TEXT(".")))
				{
					Dirs.Add(Item);
				}
			}
		}
		while(_findnext(hFile,&FileInfo) == 0);
		_findclose(hFile);
	}
	return Dirs;
}

void UCommonFunLib::GetClassifyDir(const FString RootDir, TArray<FString>& ImageDirs, TArray<FString>& VideoDirs)
{
	TArray<FString> SubDirs = GetAllSubdirectories(RootDir);
	for(FString Dir : SubDirs)
	{
		TArray<FString> FileNames;
		UE_LOG(LOGPPT2PNG,Log,TEXT("%s"),*Dir)
		IFileManager::Get().FindFiles(FileNames,*Dir);
		if(FileNames.Num() == 0) continue;
		if(FileNames[0].EndsWith(".png") || FileNames[0].EndsWith(".jpg") || FileNames[0].EndsWith(".jpeg") || FileNames[0].EndsWith(".pptx"))
		{
			ImageDirs.Add(Dir);
		}
		if(FileNames[0].EndsWith(".mp4"))
		{
			VideoDirs.Add(Dir);
		}
	}
}

FString UCommonFunLib::GetKeyByDir(const FString& Dir)
{
	TArray<FString> Arr;
	Dir.ParseIntoArray(Arr,TEXT("/"),false);
	return Arr.Last();
}


