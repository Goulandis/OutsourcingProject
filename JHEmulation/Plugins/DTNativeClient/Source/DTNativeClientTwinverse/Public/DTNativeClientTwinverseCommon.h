#pragma once

#include "CoreMinimal.h"

#include <dtnacl_twinverse.h>

#include "DTNativeClientCoreCommon.h"
#include "DTNativeClientTwinverseCommon.generated.h"

class UDTNativeClientCoreTransportData;

/*
 */
DECLARE_LOG_CATEGORY_EXTERN(LogDTNativeClientTwinverse, Log, All);

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseName
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString En;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Cn;

	static FDTNativeClientTwinverseName FromNative(const DTNACL_Twinverse_Name &Name);
};

/*
 */
UCLASS(BlueprintType)
class DTNATIVECLIENTTWINVERSE_API UDTNativeClientTwinverseAspectTransform : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FVector Position;

	UPROPERTY(BlueprintReadOnly)
	FVector4 Rotation;

	UPROPERTY(BlueprintReadOnly)
	FVector Scale;

	static UDTNativeClientTwinverseAspectTransform *CreateFromNative(const DTNACL_Twinverse_Aspect_Transform *Transform);
};

/*
 */
UCLASS(BlueprintType)
class DTNATIVECLIENTTWINVERSE_API UDTNativeClientTwinverseAspectViewpointCamera : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FVector Position;

	UPROPERTY(BlueprintReadOnly)
	FVector Target;

	static UDTNativeClientTwinverseAspectViewpointCamera *CreateFromNative(const DTNACL_Twinverse_Aspect_ViewpointCamera *Camera);
};

/*
 */
UCLASS(BlueprintType)
class DTNATIVECLIENTTWINVERSE_API UDTNativeClientTwinverseAspectHierarchy : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint64 Level;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString NodeType;

	static UDTNativeClientTwinverseAspectHierarchy *CreateFromNative(const DTNACL_Twinverse_Aspect_Hierarchy *Hierarchy);
};

/*
 */
UCLASS(BlueprintType)
class DTNATIVECLIENTTWINVERSE_API UDTNativeClientTwinverseAspectMaterial : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Color;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString MaterialId;

	static UDTNativeClientTwinverseAspectMaterial *CreateFromNative(const DTNACL_Twinverse_Aspect_Material *Material);
};

/*
 */
UCLASS(BlueprintType)
class DTNATIVECLIENTTWINVERSE_API UDTNativeClientTwinverseAspectDTDX : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	TArray<float> ColorValues;

	UPROPERTY()
	uint64 FileSize;

	UPROPERTY(BlueprintReadOnly)
	FString ColorName;

	static UDTNativeClientTwinverseAspectDTDX *CreateFromNative(const DTNACL_Twinverse_Aspect_DTDX *DTDX);
};

/*
 */
UCLASS(BlueprintType)
class DTNATIVECLIENTTWINVERSE_API UDTNativeClientTwinverseAspectVisibility : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Hidden;

	static UDTNativeClientTwinverseAspectVisibility *CreateFromNative(const DTNACL_Twinverse_Aspect_Visibility *Visibility);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseArchetype
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID SourceId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDTNativeClientTwinverseName Name;

	UPROPERTY(BlueprintReadOnly)
	FString Key;

	UPROPERTY(BlueprintReadOnly)
	FString AspectBitmask;

	UPROPERTY(BlueprintReadOnly)
	TArray<FDTNativeClientCoreUUID> AspectIds;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseArchetype FromNative(const DTNACL_Twinverse_Archetype &Archetype);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseExperience
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID ThumbnailAssetId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientTwinverseName Name;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	UPROPERTY(BlueprintReadOnly)
	FString Dimension1Path;

	UPROPERTY(BlueprintReadOnly)
	FString Dimension2Path;

	UPROPERTY(BlueprintReadOnly)
	FString Dimension3Path;

	UPROPERTY(BlueprintReadOnly)
	FString Dimension4Path;

	UPROPERTY(BlueprintReadOnly)
	FString Dimension5Path;

	UPROPERTY(BlueprintReadOnly)
	FString Dimension6Path;

	UPROPERTY(BlueprintReadOnly)
	FString Dimension7Path;

	UPROPERTY(BlueprintReadOnly)
	FString Dimension8Path;

	UPROPERTY(BlueprintReadOnly)
	FString Key;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Dimension1NodeId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Dimension2NodeId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Dimension3NodeId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Dimension4NodeId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Dimension5NodeId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Dimension6NodeId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Dimension7NodeId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Dimension8NodeId;

	UPROPERTY(BlueprintReadOnly)
	FString Status;

	static FDTNativeClientTwinverseExperience FromNative(const DTNACL_Twinverse_Experience &Experience);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseMoment
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID LayoutId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID ExperienceId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDTNativeClientTwinverseName Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Index;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	UPROPERTY(BlueprintReadOnly)
	FString Status;

	static FDTNativeClientTwinverseMoment FromNative(const DTNACL_Twinverse_Moment &Moment);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseKeyframe
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID MomentId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID SceneId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID TwinstanceId;

	UPROPERTY(BlueprintReadOnly)
	UDTNativeClientTwinverseAspectTransform *AspectTransform;

	UPROPERTY(BlueprintReadOnly)
	UDTNativeClientTwinverseAspectViewpointCamera *AspectViewpointCamera;

	UPROPERTY(BlueprintReadOnly)
	UDTNativeClientTwinverseAspectVisibility *AspectVisibility;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<FString, UDTNativeClientCoreTransportData *> Aspects;

	static FDTNativeClientTwinverseKeyframe FromNative(const DTNACL_Twinverse_Keyframe &Keyframe);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseScene
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID MediaobjectId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDTNativeClientTwinverseName Name;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseScene FromNative(const DTNACL_Twinverse_Scene &Scene);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseTwinstance
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID TwinobjectId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID SceneId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID TwinstanceId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDTNativeClientTwinverseName Name;

	UPROPERTY(BlueprintReadOnly)
	bool Keyframable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Type;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseTwinstance FromNative(const DTNACL_Twinverse_Twinstance &Twinstance);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseLayout
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID SourceId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDTNativeClientTwinverseName Name;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseLayout FromNative(const DTNACL_Twinverse_Layout &Layout);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseRegion
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID SourceId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID LayoutId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDTNativeClientTwinverseName Name;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseRegion FromNative(const DTNACL_Twinverse_Region &Region);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseMediaobject
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDTNativeClientTwinverseName Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Type;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseMediaobject FromNative(const DTNACL_Twinverse_Mediaobject &Mediaobject);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseTwinobjectAsset
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID AssetId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID TwinobjectId;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseTwinobjectAsset FromNative(const DTNACL_Twinverse_TwinobjectAsset &TwinobjectAsset);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseTwinobject
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID ArchetypeId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID TopTwinobjectId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID TwinobjectId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID SceneId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDTNativeClientTwinverseName Name;

	UPROPERTY(BlueprintReadOnly)
	FString Key;

	UPROPERTY(BlueprintReadOnly)
	FString AspectBitmask;

	UPROPERTY(BlueprintReadOnly)
	FString Status;

	UPROPERTY(BlueprintReadOnly)
	UDTNativeClientTwinverseAspectTransform *AspectTransform;

	UPROPERTY(BlueprintReadOnly)
	UDTNativeClientTwinverseAspectHierarchy *AspectHierarchy;

	UPROPERTY(BlueprintReadOnly)
	UDTNativeClientTwinverseAspectMaterial *AspectMaterial;

	UPROPERTY(BlueprintReadOnly)
	UDTNativeClientTwinverseAspectDTDX *AspectDTDX;

	UPROPERTY(BlueprintReadOnly)
	TArray<FDTNativeClientTwinverseTwinobjectAsset> TwinobjectAssets;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TMap<FString, UDTNativeClientCoreTransportData *> Aspects;

	static FDTNativeClientTwinverseTwinobject FromNative(const DTNACL_Twinverse_Twinobject &Twinobject);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseMediaobjectAsset
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID AssetId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID MediaobjectId;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseMediaobjectAsset FromNative(const DTNACL_Twinverse_MediaobjectAsset &MediaobjectAsset);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseAsset
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID ObjectServiceId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDTNativeClientTwinverseName Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString AssetType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Lod;

	UPROPERTY(BlueprintReadOnly)
	FString Hash;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseAsset FromNative(const DTNACL_Twinverse_Asset &Asset);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseObjectService
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FString BucketId;

	UPROPERTY(BlueprintReadOnly)
	FString AccessKey;

	UPROPERTY(BlueprintReadOnly)
	FString Secret;

	UPROPERTY(BlueprintReadOnly)
	FString Type;

	UPROPERTY(BlueprintReadOnly)
	FString Domain;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseObjectService FromNative(const DTNACL_Twinverse_ObjectService &ObjectService);
};

/*
 */
USTRUCT(BlueprintType)
struct DTNATIVECLIENTTWINVERSE_API FDTNativeClientTwinverseFile
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID Id;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID UserId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID WorldId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID EnterpriseId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID ObjectServiceId;

	UPROPERTY(BlueprintReadOnly)
	FDTNativeClientCoreUUID AssetId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Name;

	UPROPERTY(BlueprintReadOnly)
	FString Description;

	UPROPERTY(BlueprintReadOnly)
	FString UploadStatus;

	UPROPERTY(BlueprintReadOnly)
	FString ObjectExtension;

	UPROPERTY(BlueprintReadOnly)
	FString ObjectStorageId;

	UPROPERTY(BlueprintReadOnly)
	FString ObjectStorageDownloadUrl;

	UPROPERTY(BlueprintReadOnly)
	FDateTime ObjectStorageDownloadUrlExpires;

	UPROPERTY(BlueprintReadOnly)
	FString PresignedPutObjectUrl;

	UPROPERTY()
	uint64 ObjectSize;

	UPROPERTY(BlueprintReadOnly)
	FDateTime CreatedAt;

	UPROPERTY(BlueprintReadOnly)
	FDateTime UpdatedAt;

	static FDTNativeClientTwinverseFile FromNative(const DTNACL_Twinverse_File &File);
};

/*
 */
UENUM(BlueprintType)
enum class EDTNativeClientTwinverseLatentExec : uint8
{
	OnFinished
};
