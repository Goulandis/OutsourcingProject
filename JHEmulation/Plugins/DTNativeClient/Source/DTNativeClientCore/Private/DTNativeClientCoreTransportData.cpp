#include "DTNativeClientCoreTransportData.h"
#include "DTNativeClientCoreTransportDataPool.h"

/*
 */
UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::CreateFromNativeHandle(DTNACL_Core_TransportData Data, const UDTNativeClientCoreTransportDataPool *Pool)
{
	if (Data == DTNACL_NULL_HANDLE)
		return nullptr;

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;

	UDTNativeClientCoreTransportData *Result = NewObject<UDTNativeClientCoreTransportData>();
	Result->Data = dtnaclCoreTransportDataRetain(Data, PoolHandle);

	return Result;
}

/*
 */
void UDTNativeClientCoreTransportData::BeginDestroy()
{
	Super::BeginDestroy();
	if (Data != DTNACL_NULL_HANDLE)
		dtnaclCoreTransportDataRelease(Data);

	Data = DTNACL_NULL_HANDLE;
}

/*
 */
EDTNativeClientCoreTransportDataType UDTNativeClientCoreTransportData::GetType(const UDTNativeClientCoreTransportDataPool *Pool)
{
	check(Data != DTNACL_NULL_HANDLE);

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	DTNACL_Core_TransportDataType Type = dtnaclCoreTransportDataGetType(Data, PoolHandle);

	return static_cast<EDTNativeClientCoreTransportDataType>(Type);
}

/*
 */
UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::FromBoolean(bool Value, const UDTNativeClientCoreTransportDataPool *Pool)
{
	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	DTNACL_Core_TransportData DataHandle = dtnaclCoreTransportDataCreateBool(Value, PoolHandle);

	return UDTNativeClientCoreTransportData::CreateFromNativeHandle(DataHandle, Pool);
}

UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::FromInteger(int32 Value, const UDTNativeClientCoreTransportDataPool *Pool)
{
	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	DTNACL_Core_TransportData DataHandle = dtnaclCoreTransportDataCreateInt(Value, PoolHandle);

	return UDTNativeClientCoreTransportData::CreateFromNativeHandle(DataHandle, Pool);
}

UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::FromFloat(float Value, const UDTNativeClientCoreTransportDataPool *Pool)
{
	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	DTNACL_Core_TransportData DataHandle = dtnaclCoreTransportDataCreateFloat(Value, PoolHandle);

	return UDTNativeClientCoreTransportData::CreateFromNativeHandle(DataHandle, Pool);
}

UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::FromDouble(double Value, const UDTNativeClientCoreTransportDataPool *Pool)
{
	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	DTNACL_Core_TransportData DataHandle = dtnaclCoreTransportDataCreateDouble(Value, PoolHandle);

	return UDTNativeClientCoreTransportData::CreateFromNativeHandle(DataHandle, Pool);

}

UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::FromString(FString Value, const UDTNativeClientCoreTransportDataPool *Pool)
{
	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	DTNACL_Core_TransportData DataHandle = dtnaclCoreTransportDataCreateString(TCHAR_TO_UTF8(*Value), PoolHandle);

	return UDTNativeClientCoreTransportData::CreateFromNativeHandle(DataHandle, Pool);

}

UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::FromArray(TArray<UDTNativeClientCoreTransportData *> Value, const UDTNativeClientCoreTransportDataPool *Pool)
{
	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	DTNACL_Core_TransportData DataHandle = dtnaclCoreTransportDataCreateArray(PoolHandle);

	for (UDTNativeClientCoreTransportData *Item : Value)
	{
		check(Item);
		DTNACL_Core_TransportData ItemHandle = Item->GetNativeHandle();

		dtnaclCoreTransportDataAddArrayItem(DataHandle, ItemHandle, PoolHandle);
	}

	return UDTNativeClientCoreTransportData::CreateFromNativeHandle(DataHandle, Pool);
}

/*
 */
bool UDTNativeClientCoreTransportData::ToBoolean(bool DefaultValue, const UDTNativeClientCoreTransportDataPool *Pool)
{
	if (Data == DTNACL_NULL_HANDLE)
		return DefaultValue;

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;

	return dtnaclCoreTransportDataGetBoolValue(Data, DefaultValue, PoolHandle);
}

int32 UDTNativeClientCoreTransportData::ToInteger(int32 DefaultValue, const UDTNativeClientCoreTransportDataPool *Pool)
{
	if (Data == DTNACL_NULL_HANDLE)
		return DefaultValue;

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;

	return dtnaclCoreTransportDataGetIntValue(Data, DefaultValue, PoolHandle);
}

float UDTNativeClientCoreTransportData::ToFloat(float DefaultValue, const UDTNativeClientCoreTransportDataPool *Pool)
{
	if (Data == DTNACL_NULL_HANDLE)
		return DefaultValue;

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;

	return dtnaclCoreTransportDataGetFloatValue(Data, DefaultValue, PoolHandle);
}

double UDTNativeClientCoreTransportData::ToDouble(double DefaultValue, const UDTNativeClientCoreTransportDataPool *Pool)
{
	if (Data == DTNACL_NULL_HANDLE)
		return DefaultValue;

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;

	return dtnaclCoreTransportDataGetDoubleValue(Data, DefaultValue, PoolHandle);
}

FString UDTNativeClientCoreTransportData::ToString(FString DefaultValue, const UDTNativeClientCoreTransportDataPool *Pool)
{
	if (Data == DTNACL_NULL_HANDLE)
		return DefaultValue;

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;

	const char *Result = dtnaclCoreTransportDataGetStringValue(Data, TCHAR_TO_UTF8(*DefaultValue), PoolHandle);

	return FString(Result);
}

TArray<UDTNativeClientCoreTransportData *> UDTNativeClientCoreTransportData::ToArray(const UDTNativeClientCoreTransportDataPool *Pool)
{
	TArray<UDTNativeClientCoreTransportData *> Result;
	if (Data == DTNACL_NULL_HANDLE)
		return Result;

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	uint64 ArraySize = dtnaclCoreTransportDataGetArrayItemCount(Data, PoolHandle);

	for (uint64 i = 0; i < ArraySize; ++i)
	{
		DTNACL_Core_TransportData ArrayItemHandle = dtnaclCoreTransportDataGetArrayItem(Data, i, PoolHandle);
		UDTNativeClientCoreTransportData *ArrayItem = UDTNativeClientCoreTransportData::CreateFromNativeHandle(ArrayItemHandle, Pool);

		Result.Add(ArrayItem);
	}

	return Result;
}

/*
 */
UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::ParseJSONString(FString Value, const UDTNativeClientCoreTransportDataPool *Pool)
{
	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	DTNACL_Core_TransportData DataHandle = dtnaclCoreTransportDataCreateFromJson(TCHAR_TO_UTF8(*Value), PoolHandle);

	if (DataHandle == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("UDTNativeClientCoreTransportData::ParseJSONString(): failed to parse '%s' as JSON"), *Value);
		return nullptr;
	}

	return UDTNativeClientCoreTransportData::CreateFromNativeHandle(DataHandle, Pool);
}

FString UDTNativeClientCoreTransportData::MakeJSONString(const UDTNativeClientCoreTransportDataPool *Pool)
{
	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	const char *JSON = dtnaclCoreTransportDataCreateJsonString(Data, PoolHandle);

	FString Result(JSON);
	dtnaclCoreTransportDataDestroyJsonString(JSON, PoolHandle);

	return Result;
}

/*
 */
UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::CreateNull(const UDTNativeClientCoreTransportDataPool *Pool)
{
	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	DTNACL_Core_TransportData DataHandle = dtnaclCoreTransportDataCreateNull(PoolHandle);

	return UDTNativeClientCoreTransportData::CreateFromNativeHandle(DataHandle, Pool);
}

/*
 */
UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::CreateObject(const UDTNativeClientCoreTransportDataPool *Pool)
{
	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;
	DTNACL_Core_TransportData DataHandle = dtnaclCoreTransportDataCreateObject(PoolHandle);

	return UDTNativeClientCoreTransportData::CreateFromNativeHandle(DataHandle, Pool);
}

bool UDTNativeClientCoreTransportData::HasKey(FString Key, const UDTNativeClientCoreTransportDataPool *Pool)
{
	if (Data == DTNACL_NULL_HANDLE)
		return false;

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;

	return dtnaclCoreTransportDataHasMember(Data, TCHAR_TO_UTF8(*Key), PoolHandle);
}

UDTNativeClientCoreTransportData *UDTNativeClientCoreTransportData::GetObjectMember(FString Key, const UDTNativeClientCoreTransportDataPool *Pool)
{
	if (Data == DTNACL_NULL_HANDLE)
		return nullptr;

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;

	DTNACL_Core_TransportData ItemHandle = dtnaclCoreTransportDataGetObjectMember(Data, TCHAR_TO_UTF8(*Key), PoolHandle);

	return UDTNativeClientCoreTransportData::CreateFromNativeHandle(ItemHandle, Pool);
}

void UDTNativeClientCoreTransportData::SetObjectMember(FString Key, const UDTNativeClientCoreTransportData *Value, const UDTNativeClientCoreTransportDataPool *Pool)
{
	if (Data == DTNACL_NULL_HANDLE)
		return;

	check(Value);

	DTNACL_Core_TransportDataPool PoolHandle = (Pool) ? Pool->GetNativeHandle() : DTNACL_NULL_HANDLE;

	dtnaclCoreTransportDataSetObjectMember(Data, TCHAR_TO_UTF8(*Key), Value->GetNativeHandle(), PoolHandle);
}
