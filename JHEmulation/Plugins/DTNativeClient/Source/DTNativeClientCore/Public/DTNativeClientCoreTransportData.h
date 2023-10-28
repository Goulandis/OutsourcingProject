#pragma once

#include "CoreMinimal.h"

#include "DTNativeClientCoreCommon.h"
#include "DTNativeClientCoreTransportData.generated.h"

class UDTNativeClientCoreTransportDataPool;

/*
 */
UCLASS(ClassGroup = "DTNativeClientCore|TransportData", BlueprintType)
class DTNATIVECLIENTCORE_API UDTNativeClientCoreTransportData : public UObject
{
	GENERATED_BODY()

public:
	static UDTNativeClientCoreTransportData *CreateFromNativeHandle(DTNACL_Core_TransportData Data, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	void BeginDestroy() override;

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Type", Keywords = "TransportData Type"), Category = "DTNativeClientCore|TransportData")
	EDTNativeClientCoreTransportDataType GetType(const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "From Boolean", Keywords = "TransportData From Boolean"), Category = "DTNativeClientCore|TransportData|Value")
	static UDTNativeClientCoreTransportData *FromBoolean(bool Value, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "From Integer", Keywords = "TransportData From Integer"), Category = "DTNativeClientCore|TransportData|Value")
	static UDTNativeClientCoreTransportData *FromInteger(int32 Value, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "From Float", Keywords = "TransportData From Float"), Category = "DTNativeClientCore|TransportData|Value")
	static UDTNativeClientCoreTransportData *FromFloat(float Value, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	// Note: Unfortunately Blueprints can't work with doubles so we can't use this function as a Blueprint node
	UFUNCTION(meta = (DisplayName = "From double", Keywords = "TransportData From Double"), Category = "DTNativeClientCore|TransportData|Value")
	static UDTNativeClientCoreTransportData *FromDouble(double Value, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "From String", Keywords = "TransportData From String"), Category = "DTNativeClientCore|TransportData|Value")
	static UDTNativeClientCoreTransportData *FromString(FString Value, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "From Array", Keywords = "TransportData From Array", AutoCreateRefTerm = "Value"), Category = "DTNativeClientCore|TransportData|Value")
	static UDTNativeClientCoreTransportData *FromArray(TArray<UDTNativeClientCoreTransportData *> Value, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "To Boolean", Keywords = "TransportData To Boolean"), Category = "DTNativeClientCore|TransportData|Value")
	bool ToBoolean(bool DefaultValue, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "To Integer", Keywords = "TransportData To Integer"), Category = "DTNativeClientCore|TransportData|Value")
	int32 ToInteger(int32 DefaultValue, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "To Float", Keywords = "TransportData To Float"), Category = "DTNativeClientCore|TransportData|Value")
	float ToFloat(float DefaultValue, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	// Note: Unfortunately Blueprints can't work with doubles so we can't use this function as a Blueprint node
	UFUNCTION(meta = (DisplayName = "To Double", Keywords = "TransportData To Double"), Category = "DTNativeClientCore|TransportData|Value")
	double ToDouble(double DefaultValue, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String", Keywords = "TransportData To String"), Category = "DTNativeClientCore|TransportData|Value")
	FString ToString(FString DefaultValue, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "To Array", Keywords = "TransportData To Array"), Category = "DTNativeClientCore|TransportData|Value")
	TArray<UDTNativeClientCoreTransportData *> ToArray(const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Parse From JSON String", Keywords = "TransportData From JSON String"), Category = "DTNativeClientCore|TransportData|JSON")
	static UDTNativeClientCoreTransportData *ParseJSONString(FString Value, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Make JSON String", Keywords = "TransportData To JSON String"), Category = "DTNativeClientCore|TransportData|JSON")
	FString MakeJSONString(const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create Null", Keywords = "TransportData Create Null"), Category = "DTNativeClientCore|TransportData|Null")
	static UDTNativeClientCoreTransportData *CreateNull(const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create Object", Keywords = "TransportData Create Object"), Category = "DTNativeClientCore|TransportData|Object")
	static UDTNativeClientCoreTransportData *CreateObject(const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Has Key", Keywords = "TransportData Has Key"), Category = "DTNativeClientCore|TransportData|Object")
	bool HasKey(FString Key, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Object Member", Keywords = "TransportData Object Member Key"), Category = "DTNativeClientCore|TransportData|Object")
	UDTNativeClientCoreTransportData *GetObjectMember(FString Key, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Object Member", Keywords = "TransportData Object Member Key"), Category = "DTNativeClientCore|TransportData|Object")
	void SetObjectMember(FString Key, const UDTNativeClientCoreTransportData *Value, const UDTNativeClientCoreTransportDataPool *Pool = nullptr);

public:
	FORCEINLINE DTNACL_Core_TransportData GetNativeHandle() const { return Data; }

private:
	DTNACL_Core_TransportData Data {DTNACL_NULL_HANDLE};
};
