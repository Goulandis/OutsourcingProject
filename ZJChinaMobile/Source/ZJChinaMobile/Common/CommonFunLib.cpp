#include "CommonFunLib.h"
#include <thread>
#include "IImageWrapperModule.h"
#include "HAL/FileManager.h"
#include <io.h>
#include <string>
#include "Windows/AllowWindowsPlatformTypes.h"
#include <windows.h>
#include "Windows/HideWindowsPlatformTypes.h"
#include <codecvt>

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

void UCommonFunLib::LoadPNG2Texture(TArray<UTexture2D*>& Texs, FString Dir)
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
}

UTexture2D* UCommonFunLib::LoadPNG2TextureFromFile(const FString& FilePath)
{
	UTexture2D* Tex = nullptr;
	if(!IFileManager::Get().FileExists(*FilePath))
	{
		UE_LOG(LOGPPT2PNG,Error,TEXT("%s is not exists"),*FilePath);
		return Tex;
	}
	TArray<uint8> RawFileData;
	if(!FFileHelper::LoadFileToArray(RawFileData,*FilePath))
	{
		UE_LOG(LOGPPT2PNG,Error,TEXT("Failed to load file to memory : %s"),*FilePath);
		return Tex;
	}
	TSharedPtr<IImageWrapper> ImageWrapper = GetImageWrapperByExtention(FilePath);
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
			}
		}
	}
	return Tex;
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

TMap<FString, FString> UCommonFunLib::GetDirType(const TArray<FString>& Dirs)
{
	TMap<FString,FString> DirTypeMap;
	for(FString Dir : Dirs)
	{
		TArray<FString> FileNames;
		IFileManager::Get().FindFiles(FileNames,*Dir);
		if(FileNames.Num() == 0)
		{
			continue;
		}
		if(FileNames[0].EndsWith(".png") || FileNames[0].EndsWith(".jpg") || FileNames[0].EndsWith(".jpeg"))
		{
			DirTypeMap.Add(TPair<FString,FString>(Dir,TEXT("Image")));
			continue;
		}
		if(FileNames[0].EndsWith(".pptx"))
		{
			DirTypeMap.Add(TPair<FString,FString>(Dir,TEXT("PPT")));
			continue;
		}
		if(FileNames[0].EndsWith(".mp4"))
		{
			DirTypeMap.Add(TPair<FString,FString>(Dir,TEXT("Video")));
		}
	}
	return DirTypeMap;
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
				TArray<FString> Arr;
				Dir.ParseIntoArray(Arr,TEXT("/"),false);
				Key = Arr.Last();
				LoadPNG2Texture(Texs,Dir);
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
			TArray<FString> Arr;
			Dir.ParseIntoArray(Arr,TEXT("/"),false);
			Key = Arr.Last();
			LoadPNG2Texture(Texs,SubDir[0]);
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
	_wfinddata_t FileInfo;
	std::wstring_convert<std::codecvt_utf8<wchar_t>> Conv;
	std::wstring RootPath = Conv.from_bytes(TCHAR_TO_UTF8(*Dir));
	std::wstring WPath = RootPath + L"\\*";
	//std::wstring* wp;
	if ((hFile = _wfindfirst(WPath.c_str(), &FileInfo)) != -1)
	{
		do
		{
			if(FileInfo.attrib & _A_SUBDIR && wcscmp(FileInfo.name,L".") != 0 && wcscmp(FileInfo.name,L"..") != 0)
			{
				std::wstring SubPath = RootPath + L"/" + FileInfo.name;
				const wchar_t* DirNameChr = SubPath.c_str();
				Dirs.Add(FString(DirNameChr));
			}
		}
		while(_wfindnext(hFile,&FileInfo) == 0);
		_findclose(hFile);
	}
	return Dirs;
}

void UCommonFunLib::GetClassifyDir(const FString RootDir, TArray<FString>& ImageDirs, TArray<FString>& VideoDirs,TArray<FString>& OptionalDirs)
{
	TArray<FString> SubDirs = GetAllSubdirectories(RootDir);
	for(FString Dir : SubDirs)
	{
		TArray<FString> FileNames;
		IFileManager::Get().FindFiles(FileNames,*Dir);
		if(FileNames.Num() == 0)
		{
			TArray<FString> SubSubDirs = GetAllSubdirectories(Dir);
			if(SubSubDirs.Num() > 0)
			{
				OptionalDirs.Add(Dir);
			}
			continue;
		}
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

TArray<FString> UCommonFunLib::GetFilesFromDir(const FString& Dir)
{
	TArray<FString> FileNames;
	IFileManager::Get().FindFiles(FileNames,*Dir);
	TArray<FString> FilePaths;
	for(FString FileName : FileNames)
	{
		FString FilePath = FPaths::Combine(Dir,FileName);
		FilePaths.Add(FilePath);
	}
	return FilePaths;
}

bool UCommonFunLib::ChineseCompare(FString Source, FString Target)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> Conv;
	std::wstring WSource = Conv.from_bytes(TCHAR_TO_UTF8(*Source));
	std::wstring WTarget = Conv.from_bytes(TCHAR_TO_UTF8(*Target));
	return !(WSource >= WTarget);
}

void UCommonFunLib::ChineseSrot(TArray<FString>& Results, TArray<FString> StrArr)
{
	if(StrArr.Num() <= 0)
	{
		return;
	}
	std::wstring_convert<std::codecvt_utf8<wchar_t>> Conv;
	std::wstring Tmp;
	int Index = 0;
	for(int i=0;i<StrArr.Num();++i)
	{
		FString FirstStr = StrArr[i].Mid(0,1);
		std::wstring WStr = Conv.from_bytes(TCHAR_TO_UTF8(*FirstStr));
		if(Tmp == L"")
		{
			Tmp = WStr;
			Index = i;
		}
		else
		{
			if(Tmp < WStr)
			{
				Tmp = WStr;
				Index = i;
			}
		}
	}
	Results.Add(StrArr[Index]);
	StrArr.RemoveAt(Index);
	ChineseSrot(Results,StrArr);
}

TMap<FString,FString> UCommonFunLib::GetAllFilesFromDir(const FString& Dir)
{
	TArray<FString> FileNames;
	IFileManager::Get().FindFiles(FileNames,*Dir);
	TMap<FString,FString> FilePathAndTypeMap;
	for(FString FileName : FileNames)
	{
		FString FilePath = FPaths::Combine(Dir,FileName);
		FString FileType = TEXT("None");
		if(FilePath.EndsWith(".png") || FilePath.EndsWith(".jpg") || FilePath.EndsWith(".jpeg"))
		{
			FileType = TEXT("Image");
			FilePathAndTypeMap.Add(TPair<FString,FString>(FilePath,FileType));
		}
		else if(FilePath.EndsWith(".mp4"))
		{
			FileType = TEXT("Video");
			FilePathAndTypeMap.Add(TPair<FString,FString>(FilePath,FileType));
		}
	}
	if(!FilePathAndTypeMap.IsEmpty())
	{
		return FilePathAndTypeMap;
	}
	else
	{
		if(FileNames.Num() > 0)
		{
			FString FilePath = FPaths::Combine(Dir,FileNames[0]);
			if(FilePath.EndsWith(".pptx"))
			{
				FString SubDir = FPaths::Combine(Dir,FPaths::GetBaseFilename(FilePath));
				TArray<FString> SubFiles;
				IFileManager::Get().FindFiles(SubFiles,*SubDir);
				for(FString SubFile : SubFiles)
				{
					FString SubFilePath = FPaths::Combine(SubDir,SubFile);
					FString FileType = TEXT("None");
					if(SubFilePath.EndsWith(".png") || SubFilePath.EndsWith(".jpg") || SubFilePath.EndsWith(".jpeg"))
					{
						FileType = TEXT("Image");
						FilePathAndTypeMap.Add(TPair<FString,FString>(SubFilePath,FileType));
					}
					else if(SubFilePath.EndsWith(".mp4"))
					{
						FileType = TEXT("Video");
						FilePathAndTypeMap.Add(TPair<FString,FString>(SubFilePath,FileType));
					}
				}
				return FilePathAndTypeMap;
			}
		}
	}
	return FilePathAndTypeMap;
}



