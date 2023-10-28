#pragma once

#include "CoreMinimal.h"

#include "DTNativeClientCoreCommon.h"
#include "DTNativeClientCoreTransportDataPool.generated.h"

/*
 */
UCLASS(ClassGroup = "DTNativeClientCore|TransportDataPool", BlueprintType)
class DTNATIVECLIENTCORE_API UDTNativeClientCoreTransportDataPool : public UObject
{
	GENERATED_BODY()

public:
	void BeginDestroy() override;
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create", Keywords = "TransportData Pool Create"), Category = "DTNativeClientCore|TransportDataPool")
	static UDTNativeClientCoreTransportDataPool *Create();

public:
	FORCEINLINE DTNACL_Core_TransportDataPool GetNativeHandle() const { return Pool; }

private:
	DTNACL_Core_TransportDataPool Pool {DTNACL_NULL_HANDLE};
};
