// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonFunLib.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows.h"
#include "Windows/HideWindowsPlatformTypes.h"
#include "Engine.h"
#include <codecvt>
#include <corecrt_io.h>

void UCommonFunLib::CopyFilesTo(TArray<FString> Files, FString Dir)
{
	CleanFolder(Dir);
	for(FString File : Files)
	{
		FString TargetFile = FPaths::Combine(Dir,FPaths::GetCleanFilename(File));
		CopyFileTo(File,TargetFile);
	}
}

TArray<FString> UCommonFunLib::CopyFoldersTo(FString RootDir, FString TargetDir)
{
	CleanFolder(TargetDir);
	TArray<FString> SubDirsSubfix;
	TArray<FString> SubDirs = GetAllSubdirectories(RootDir);
	for(FString SubDir : SubDirs)
	{
		TArray<FString> Splits;
		SubDir.ParseIntoArray(Splits,TEXT("/"));
		FString Subfix = Splits.Last();
		SubDirsSubfix.Add(Subfix);
		FString NewTargetSubDir = FPaths::Combine(TargetDir,Subfix);
		if(FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*NewTargetSubDir))
		{
			TArray<FString> Files;
			IFileManager::Get().FindFiles(Files,*SubDir);
			for(FString File : Files)
			{
				FString CleanFilename = FPaths::GetCleanFilename(File);
				FString FilePath = FPaths::Combine(SubDir,File);
				FString NewFilePath = FPaths::Combine(NewTargetSubDir,CleanFilename);
				CopyFileTo(FilePath,NewFilePath);
			}
		}
	}
	return SubDirsSubfix;
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
	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("Failed to copy %s to %s"),*SourceFile,*TargetFile);
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
			if(Files.Num() > 0)
			{
				Content.Content = Files;
				Content.Type = TEXT("File");
				Contents.Add(Content);
			}
			else if(Files.Num() == 0)
			{
				TArray<FString> SubSubDirs = GetAllSubdirectories(SubDir);
				TArray<FString> SubSubDirNames;
				for (FString SubSubDir : SubSubDirs)
				{
					TArray<FString> Split;
					SubSubDir.ParseIntoArray(Split,TEXT("/"));
					SubSubDirNames.Add(Split.Last());
				}
				Content.Content = SubSubDirNames;
				Content.Type = TEXT("Folder");
				Contents.Add(Content);
			}
		}
	}
	return Contents;
}

TArray<FString> UCommonFunLib::GetAllSubdirectories(const FString& Dir)
{
	TArray<FString> Dirs;
	long long hFile = 0;
	_wfinddata_t FileInfo;
	std::wstring_convert<std::codecvt_utf8<wchar_t>> Conv;
	std::wstring RootPath = Conv.from_bytes(TCHAR_TO_UTF8(*Dir));
	std::wstring WPath = RootPath + L"\\*";
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
