#pragma once

#include "CoreMinimal.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine.h"

#include <dtnacl_core.h>

#include "DTNativeClientCoreCommon.generated.h"

/*
 */
DECLARE_LOG_CATEGORY_EXTERN(LogDTNativeClient, Log, All);

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTCORE_API FDTNativeClientCoreUUID
{
	GENERATED_BODY()

	UPROPERTY()
	uint64 Low;
	UPROPERTY()
	uint64 High;
	UPROPERTY()
	uint32 Bytes;

	static FDTNativeClientCoreUUID FromNative(const DTNACL_Core_UUID &UUID);
	DTNACL_Core_UUID ToNative() const;
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTCORE_API FDTNativeClientCoreUser
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID TenantId;

	UPROPERTY(BlueprintReadOnly)
	FString AccessToken;

	static FDTNativeClientCoreUser FromNative(const DTNACL_Core_User &User);
};

/*
 */
UENUM(BlueprintType)
enum class EDTNativeClientCoreTransportDataType : uint8
{
	__ZERO = 0,

	BOOL = DTNACL_CORE_TRANSPORT_DATA_TYPE_BOOL UMETA(DisplayName = "Bool"),
	INT = DTNACL_CORE_TRANSPORT_DATA_TYPE_INT UMETA(DisplayName = "Int32"),
	FLOAT = DTNACL_CORE_TRANSPORT_DATA_TYPE_FLOAT UMETA(DisplayName = "Float"),
	DOUBLE = DTNACL_CORE_TRANSPORT_DATA_TYPE_DOUBLE UMETA(DisplayName = "Double"),
	STRING = DTNACL_CORE_TRANSPORT_DATA_TYPE_STRING UMETA(DisplayName = "String"),
	OBJECT = DTNACL_CORE_TRANSPORT_DATA_TYPE_OBJECT UMETA(DisplayName = "Object"),
	ARRAY = DTNACL_CORE_TRANSPORT_DATA_TYPE_ARRAY UMETA(DisplayName = "Array"),
	NULL_TYPE = DTNACL_CORE_TRANSPORT_DATA_TYPE_NULL_TYPE UMETA(DisplayName = "Null Type"),
	BINARY = DTNACL_CORE_TRANSPORT_DATA_TYPE_BINARY UMETA(DisplayName = "Binary"),
	UNKNOWN = DTNACL_CORE_TRANSPORT_DATA_TYPE_UNKNOWN UMETA(DisplayName = "Unknown"),
};

/*
 */
UENUM(BlueprintType)
enum class EDTNativeClientCoreConnectionStatus : uint8
{
	__ZERO = 0,

	DISCONNECTED = DTNACL_CORE_CONNECTION_STATUS_DISCONNECTED UMETA(DisplayName = "Disconnected"),
	CONNECTED = DTNACL_CORE_CONNECTION_STATUS_CONNECTED UMETA(DisplayName = "Connected"),
	FAILED = DTNACL_CORE_CONNECTION_STATUS_FAILED UMETA(DisplayName = "Failed"),
	RECONNECT_STARTED = DTNACL_CORE_CONNECTION_STATUS_RECONNECT_STARTED UMETA(DisplayName = "Reconnect Started"),
	RECONNECT_ATTEMPT= DTNACL_CORE_CONNECTION_STATUS_RECONNECT_ATTEMPT UMETA(DisplayName = "Reconnect Attempt"),
};

/*
 */
UCLASS(ClassGroup = "DTNativeClientCore|UUID", BlueprintType)
class DTNATIVECLIENTCORE_API UDTNativeClientCoreUUIDHelper: public UObject
{
	GENERATED_BODY()

public:
	UDTNativeClientCoreUUIDHelper(const class FObjectInitializer &ObjectInitializer);

	UFUNCTION(Category = "DTNativeClientCore|UUID", BlueprintPure, DisplayName = "Generate UUID")
	static FDTNativeClientCoreUUID GenerateUUID();

	UFUNCTION(Category = "DTNativeClientCore|UUID", BlueprintPure, DisplayName = "Make 16-byte UUID")
	static FDTNativeClientCoreUUID MakeFullUUID(
		uint8 B0,  uint8 B1,  uint8 B2,  uint8 B3,
		uint8 B4,  uint8 B5,  uint8 B6,  uint8 B7,
		uint8 B8,  uint8 B9,  uint8 B10, uint8 B11,
		uint8 B12, uint8 B13, uint8 B14, uint8 B15
	);

	UFUNCTION(Category = "DTNativeClientCore|UUID", BlueprintPure, DisplayName = "Make 12-byte UUID")
	static FDTNativeClientCoreUUID MakeShortUUID(
		uint8 B0,  uint8 B1,  uint8 B2,  uint8 B3,
		uint8 B4,  uint8 B5,  uint8 B6,  uint8 B7,
		uint8 B8,  uint8 B9,  uint8 B10, uint8 B11
	);

	UFUNCTION(Category = "DTNativeClientCore|UUID", BlueprintPure, DisplayName = "Break UUID")
	static void BreakUUID(
		const FDTNativeClientCoreUUID &UUID,
		uint8 &B0,  uint8 &B1,  uint8 &B2,  uint8 &B3,
		uint8 &B4,  uint8 &B5,  uint8 &B6,  uint8 &B7,
		uint8 &B8,  uint8 &B9,  uint8 &B10, uint8 &B11,
		uint8 &B12, uint8 &B13, uint8 &B14, uint8 &B15
	);

	UFUNCTION(Category = "DTNativeClientCore|UUID", BlueprintPure, DisplayName = "UUID To String")
	static FString ToString(const FDTNativeClientCoreUUID &UUID);
};

/*
 */
UENUM(BlueprintType)
enum class EDTNativeClientCoreLatentExec : uint8
{
	OnSuccess,
	OnFail,
};

UENUM(BlueprintType)
enum class EDTNativeClientCoreWaitLatentExec : uint8
{
	OnFinished,
};

UENUM(BlueprintType)
enum class EDTNativeClientCoreConnectionLatentExec : uint8
{
	OnDisconnected,
	OnConnected,
	OnFailed,
	OnReconnectStarted,
	OnReconnectAttempt,
};

/*
 */
template<typename T>
struct FDTNativeClientCoreCallingContext
{
	T Callback;

	FDTNativeClientCoreCallingContext() = delete;
	FDTNativeClientCoreCallingContext(const FDTNativeClientCoreCallingContext<T> &) = delete;
	FDTNativeClientCoreCallingContext(FDTNativeClientCoreCallingContext<T> &&) = delete;

	FDTNativeClientCoreCallingContext(const T &Callback)
		: Callback(Callback)
	{
	}

	FDTNativeClientCoreCallingContext<T> &operator=(const FDTNativeClientCoreCallingContext<T> &) = delete;
	FDTNativeClientCoreCallingContext<T> &operator=(FDTNativeClientCoreCallingContext<T> &&) = delete;
};

template<typename... Args>
class FDTNativeClientCoreLatentCallingContext : public FPendingLatentAction
{
public:
	FDTNativeClientCoreLatentCallingContext() = delete;
	FDTNativeClientCoreLatentCallingContext(const FDTNativeClientCoreLatentCallingContext<Args...> &) = delete;
	FDTNativeClientCoreLatentCallingContext(FDTNativeClientCoreLatentCallingContext<Args...> &&) = delete;

	FDTNativeClientCoreLatentCallingContext(const FLatentActionInfo &Info, Args &&...Arguments)
		: Finished(false), Called(false), Info(Info), Parameters(Forward<Args>(Arguments)...)
	{
	}

	FDTNativeClientCoreLatentCallingContext<Args...> &operator=(const FDTNativeClientCoreLatentCallingContext<Args...> &) = delete;
	FDTNativeClientCoreLatentCallingContext<Args...> &operator=(FDTNativeClientCoreLatentCallingContext<Args...> &&) = delete;

	static FORCEINLINE FDTNativeClientCoreLatentCallingContext<Args...> *Create(const UObject *Owner, const FLatentActionInfo &LatentInfo, Args &&...Arguments)
	{
		UWorld *World = GEngine->GetWorldFromContextObject(Owner, EGetWorldErrorMode::LogAndReturnNull);
		if (!World)
			return nullptr;

		FLatentActionManager &LatentActionManager = World->GetLatentActionManager();

		FDTNativeClientCoreLatentCallingContext<Args...> *LatentAction = new FDTNativeClientCoreLatentCallingContext<Args...>(LatentInfo, Forward<Args>(Arguments)...);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, LatentAction);

		return LatentAction;
	}

	FORCEINLINE const TTuple<Args...> &GetParameters() const { return Parameters; }
	FORCEINLINE TTuple<Args...> &GetParameters() { return Parameters; }

	FORCEINLINE void Call()
	{
		Called = true;
	}

	FORCEINLINE void CallAndFinish()
	{
		Finished = true;
		Called = true;
	}

	void UpdateOperation(FLatentResponse &Response) override
	{
		if (Called)
		{
			Response.TriggerLink(Info.ExecutionFunction, Info.Linkage, Info.CallbackTarget);
			Called = false;
		}
		Response.DoneIf(Finished);
	}

private:
	bool Finished {false};
	bool Called {false};
	FLatentActionInfo Info;
	TTuple<Args...> Parameters;
};
