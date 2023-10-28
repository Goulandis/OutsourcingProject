#include "DTNativeClientCoreTransportDataPool.h"

/*
 */
void UDTNativeClientCoreTransportDataPool::BeginDestroy()
{
	Super::BeginDestroy();
	if (Pool != DTNACL_NULL_HANDLE)
		dtnaclCoreTransportDataPoolDestroy(Pool);

	Pool = DTNACL_NULL_HANDLE;
}

UDTNativeClientCoreTransportDataPool *UDTNativeClientCoreTransportDataPool::Create()
{
	UDTNativeClientCoreTransportDataPool *Result = NewObject<UDTNativeClientCoreTransportDataPool>();
	Result->Pool = dtnaclCoreTransportDataPoolCreate();
	return Result;
}
