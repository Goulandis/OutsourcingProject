// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonFunLib.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows.h"
#include "Windows/HideWindowsPlatformTypes.h"
#include "Engine.h"
#include <codecvt>
#include <corecrt_io.h>
#include "DesktopPlatformModule.h"
#include "Windows/WindowsWindow.h"

void UCommonFunLib::CopyFilesTo(TArray<FString> Files, FString Dir)
{
	CleanFolder(Dir);
	for(FString File : Files)
	{
		FString TargetFile = FPaths::Combine(Dir,FPaths::GetCleanFilename(File));
		UE_LOG(LogTemp,Log,TEXT("TargetFile:%s"),*TargetFile);
		CopyFileTo(File,TargetFile);
	}
}

void UCommonFunLib::CopyFileTo(FString SourceFile, FString TargetFile)
{
	std::string SourceStr = TCHAR_TO_UTF8(*SourceFile);
	std::string TargetStr = TCHAR_TO_UTF8(*TargetFile);
	std::wstring_convert<std::codecvt_utf8<wchar_t>> Conv;
	std::wstring SourceWStr = Conv.from_bytes(SourceStr);
	std::wstring TargetWStr = Conv.from_bytes(TargetStr);;
	bool Ok = CopyFileW(&SourceWStr[0],&TargetWStr[0],false);
	if(Ok)
	{
		UE_LOG(LogTemp,Log,TEXT("Copy %s to %s"),*SourceFile,*TargetFile);
		FString Msg = "Copy " + SourceFile + " to " + TargetFile;
	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("Failed to copy %s to %s"),*SourceFile,*TargetFile);
		FString Msg = "Failed to copy " + SourceFile + " to " + TargetFile;
	}
	
}

void UCommonFunLib::CleanFolder(FString Dir)
{
	TArray<FString> Files;
	IFileManager::Get().FindFilesRecursive(Files,*Dir,TEXT("*.*"),true,true);
	TArray<FString> SubDirs;
	for(FString File : Files)
	{
		if(FPaths::DirectoryExists(File))
		{
			SubDirs.Add(File);
		}
		else if(FPaths::FileExists(File))
		{
			IFileManager::Get().Delete(*File);
		}
	}
	for(FString SubDir : SubDirs)
	{
		IFileManager::Get().DeleteDirectory(*SubDir);
	}
}

void UCommonFunLib::SetScreenResolution(int Widget, int Height)
{
	GEngine->GetGameUserSettings()->SetFullscreenMode(EWindowMode::Windowed);
	GEngine->GetGameUserSettings()->SetScreenResolution(FIntPoint(Widget, Height));
	GEngine->GetGameUserSettings()->ApplySettings(true);
}

void UCommonFunLib::SetupPPT2PNG(FString Path)
{
	FString CmdStr = Path + "Setup.bat";
	std::string Cmd = TCHAR_TO_UTF8(*CmdStr);
	system(Cmd.c_str());
}

void UCommonFunLib::InitPPT2PNGScript(FString Path)
{
	FString PyScript = Path + "PPT2PNG.py";
	FString CmdStr = "python " + PyScript;
	FString BatFile = Path + "Setup.bat";
	FFileHelper::SaveStringToFile(CmdStr,*BatFile);
}

TArray<FContent> UCommonFunLib::GetContentFromDir(FString Dir)
{
	TArray<FContent> Contents;
	TArray<FString> SubDirs = GetAllSubdirectories(Dir);
	for(FString SubDir : SubDirs)
	{
		if(FPaths::DirectoryExists(SubDir))
		{
			FContent Content;
			TArray<FString> Arr;
			SubDir.ParseIntoArray(Arr,TEXT("/"),false);
			FString Key = Arr.Last();
			Content.Key = Key;
			TArray<FString> Files;
			IFileManager::Get().FindFiles(Files,*SubDir);
			Content.Content = Files;
			Contents.Add(Content);
		}
	}
	return Contents;
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
