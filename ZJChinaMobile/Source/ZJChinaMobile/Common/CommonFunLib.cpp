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
	FString CmdStr = FPaths::ProjectPluginsDir() + "PPT2PNG/PythonServer/Setup.bat";
	std::string Cmd = TCHAR_TO_UTF8(*CmdStr);
	system(Cmd.c_str());
}

void UCommonFunLib::InitPPT2PNGScript()
{
	FString PyExe = FPaths::ProjectPluginsDir() + "PPT2PNG/PythonServer/Scripts/python.exe";
	FString PyScript = FPaths::ProjectPluginsDir() + "PPT2PNG/PythonServer/PPT2PNG.py";
	FString CmdStr = PyExe + " " + PyScript;
	FString BatFile = FPaths::ProjectPluginsDir() + "PPT2PNG/PythonServer/Setup.bat";
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
		// IFileManager::Get().FindFilesRecursive(DirArr,*Dir,TEXT("*"),false,true,false);
		
		DirArr = GetAllSubdirectories(Dir);
		for(FString SubDir : DirArr)
		{
			TArray<FString> SubDirArr = GetAllSubdirectories(SubDir);
			if(SubDirArr.Num() < 0)
			{
				continue;
			}
			FString PNGDir = SubDirArr[0];
			UE_LOG(LOGPPT2PNG,Warning,TEXT("PNGDir:%s"),*PNGDir)
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


