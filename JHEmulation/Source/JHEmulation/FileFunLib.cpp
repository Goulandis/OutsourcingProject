#include "FileFunLib.h"
#include <string>

FString UFileFunLib::ReadFile(const FString& Path,bool& Rel)
{
	FString Content;
	Rel = FFileHelper::LoadFileToString(Content,*Path);
	return Content;
}

bool UFileFunLib::WriteFile(const FString& Path, const FString& Content)
{
	return FFileHelper::SaveStringToFile(Content,*Path);
}
