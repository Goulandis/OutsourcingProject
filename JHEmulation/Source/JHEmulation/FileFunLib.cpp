// Fill out your copyright notice in the Description page of Project Settings.


#include "FileFunLib.h"
#include <fstream>
#include <string>

FString UFileFunLib::ReadFile(const FString& Path,bool& Rel)
{
	Rel = false;
	FString RelStr;
	std::ifstream Ifs;
	std::string PathStr = TCHAR_TO_UTF8(&Path);
	Ifs.open(PathStr);
	if(Ifs.is_open())
	{
		UE_LOG(LogTemp,Error,TEXT("Start Read"));
		std::string Line;
		std::string Content;
		while(std::getline(Ifs,Line))
		{
			Content += Line;
			UE_LOG(LogTemp,Error,TEXT("Reading..."));
		}
		Rel = true;
		RelStr = FString(UTF8_TO_TCHAR(Content.c_str()));
		UE_LOG(LogTemp,Error,TEXT("Content:%s"),*RelStr);
	}
	Ifs.close();
	return RelStr;
}
