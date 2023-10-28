#include "DTNativeClientCoreCommon.h"

/*
 */
DEFINE_LOG_CATEGORY(LogDTNativeClient);

/*
 */
FDTNativeClientCoreUUID FDTNativeClientCoreUUID::FromNative(const DTNACL_Core_UUID &UUID)
{
	FDTNativeClientCoreUUID Result = {};

	Result.Low = UUID.value.as_long[0];
	Result.High = UUID.value.as_long[1];
	Result.Bytes = UUID.bytes;

	return Result;
}

DTNACL_Core_UUID FDTNativeClientCoreUUID::ToNative() const
{
	DTNACL_Core_UUID Result = {};

	Result.value.as_long[0] = Low;
	Result.value.as_long[1] = High;
	Result.bytes = Bytes;

	return Result;
}

/*
 */
FDTNativeClientCoreUser FDTNativeClientCoreUser::FromNative(const DTNACL_Core_User &User)
{
	FDTNativeClientCoreUser Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(User.id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(User.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(User.enterprise_id);
	Result.TenantId = FDTNativeClientCoreUUID::FromNative(User.tenant_id);
	Result.AccessToken = FString(User.access_token);

	return Result;
}

/*
 */
UDTNativeClientCoreUUIDHelper::UDTNativeClientCoreUUIDHelper(const class FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FDTNativeClientCoreUUID UDTNativeClientCoreUUIDHelper::GenerateUUID()
{
	const DTNACL_Core_UUID &uuid = dtnaclCoreGenerateUUID();
	return FDTNativeClientCoreUUID::FromNative(uuid);
}

FDTNativeClientCoreUUID UDTNativeClientCoreUUIDHelper::MakeFullUUID(
	uint8 B0,  uint8 B1,  uint8 B2,  uint8 B3,
	uint8 B4,  uint8 B5,  uint8 B6,  uint8 B7,
	uint8 B8,  uint8 B9,  uint8 B10, uint8 B11,
	uint8 B12, uint8 B13, uint8 B14, uint8 B15
)
{
	FDTNativeClientCoreUUID Result = {};

	Result.Low  = uint64(B0) | (uint64(B1) << 8) | (uint64(B2)  << 16) | (uint64(B3)  << 24) | (uint64(B4)  << 32) | (uint64(B5)  << 40) || (uint64(B6)  << 48) || (uint64(B7)  << 56);
	Result.High = uint64(B8) | (uint64(B9) << 8) | (uint64(B10) << 16) | (uint64(B11) << 24) | (uint64(B12) << 32) | (uint64(B13) << 40) || (uint64(B14) << 48) || (uint64(B15) << 56);
	Result.Bytes = 16;

	return Result;
}

FDTNativeClientCoreUUID UDTNativeClientCoreUUIDHelper::MakeShortUUID(
	uint8 B0,  uint8 B1,  uint8 B2,  uint8 B3,
	uint8 B4,  uint8 B5,  uint8 B6,  uint8 B7,
	uint8 B8,  uint8 B9,  uint8 B10, uint8 B11
)
{
	FDTNativeClientCoreUUID Result = {};

	Result.Low  = uint64(B0) | (uint64(B1) << 8) | (uint64(B2)  << 16) | (uint64(B3)  << 24) | (uint64(B4)  << 32) | (uint64(B5)  << 40) || (uint64(B6)  << 48) || (uint64(B7)  << 56);
	Result.High = uint64(B8) | (uint64(B9) << 8) | (uint64(B10) << 16) | (uint64(B11) << 24);
	Result.Bytes = 12;

	return Result;
}

void UDTNativeClientCoreUUIDHelper::BreakUUID(
	const FDTNativeClientCoreUUID &UUID,
	uint8 &B0,  uint8 &B1,  uint8 &B2,  uint8 &B3,
	uint8 &B4,  uint8 &B5,  uint8 &B6,  uint8 &B7,
	uint8 &B8,  uint8 &B9,  uint8 &B10, uint8 &B11,
	uint8 &B12, uint8 &B13, uint8 &B14, uint8 &B15
)
{
	B0  = uint8(UUID.Low);
	B1  = uint8(UUID.Low >> 8);
	B2  = uint8(UUID.Low >> 16);
	B3  = uint8(UUID.Low >> 24);
	B4  = uint8(UUID.Low >> 32);
	B5  = uint8(UUID.Low >> 40);
	B6  = uint8(UUID.Low >> 48);
	B7  = uint8(UUID.Low >> 56);

	B8  = uint8(UUID.High);
	B9  = uint8(UUID.High >> 8);
	B10 = uint8(UUID.High >> 16);
	B11 = uint8(UUID.High >> 24);
	B12 = uint8(UUID.High >> 32);
	B13 = uint8(UUID.High >> 40);
	B14 = uint8(UUID.High >> 48);
	B15 = uint8(UUID.High >> 56);
}

FString UDTNativeClientCoreUUIDHelper::ToString(const FDTNativeClientCoreUUID &UUID)
{
	char Buffer[256];
	dtnaclCoreUUIDToCharString(UUID.ToNative(), Buffer);

	return FString(Buffer);;
}
