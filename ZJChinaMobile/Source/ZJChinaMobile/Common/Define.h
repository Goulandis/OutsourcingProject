#include <comdef.h>
#include "RHI.h"

DECLARE_LOG_CATEGORY_EXTERN(GLOG, All, All)
#define TOFS(Str) FString(UTF8_TO_TCHAR(Str.c_str()))
//#define GLOG(CategoryName,Verbosity,Format,...) UE_PRIVATE_LOG(PREPROCESSOR_NOTHING, constexpr, CategoryName, Verbosity, Format, ##__VA_ARGS__)