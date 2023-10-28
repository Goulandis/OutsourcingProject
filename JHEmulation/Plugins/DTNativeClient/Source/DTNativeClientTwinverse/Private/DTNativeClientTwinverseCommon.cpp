#include "DTNativeClientTwinverseCommon.h"
#include "DTNativeClientCoreTransportData.h"

/*
 */
DEFINE_LOG_CATEGORY(LogDTNativeClientTwinverse);

/*
 */
static TMap<FString, UDTNativeClientCoreTransportData *> MapAspects(const DTNACL_Core_TransportData &Data)
{
	TMap<FString, UDTNativeClientCoreTransportData *> Result;

	DTNACL_Core_TransportDataIterator It = dtnaclCoreTransportDataCreateIterator(Data);
	while (!dtnaclCoreTransportDataIteratorIsEnd(It))
	{
		const char *Key = dtnaclCoreTransportDataIteratorGetKey(It);
		DTNACL_Core_TransportData Value = dtnaclCoreTransportDataIteratorGetValue(It);

		Result.Add(FString(Key), UDTNativeClientCoreTransportData::CreateFromNativeHandle(dtnaclCoreTransportDataDeepCopy(Value)));
		dtnaclCoreTransportDataIteratorNext(It);
	}

	dtnaclCoreTransportDataDestroyIterator(It);
	return Result;
}

/*
 */
FDTNativeClientTwinverseName FDTNativeClientTwinverseName::FromNative(const DTNACL_Twinverse_Name &Name)
{
	FDTNativeClientTwinverseName Result = {};

	Result.En = FString(Name.en);
	Result.Cn = FString(Name.cn);

	return Result;
}

/*
 */
UDTNativeClientTwinverseAspectTransform *UDTNativeClientTwinverseAspectTransform::CreateFromNative(const DTNACL_Twinverse_Aspect_Transform *Transform)
{
	if (Transform == nullptr)
		return nullptr;

	UDTNativeClientTwinverseAspectTransform *Result = NewObject<UDTNativeClientTwinverseAspectTransform>();

	Result->Position = FVector(Transform->position.x, Transform->position.y, Transform->position.z);
	Result->Rotation = FVector4(Transform->rotation.x, Transform->rotation.y, Transform->rotation.z, Transform->rotation.w);
	Result->Scale = FVector(Transform->scale.x, Transform->scale.y, Transform->scale.z);

	return Result;
}

/*
 */
UDTNativeClientTwinverseAspectViewpointCamera *UDTNativeClientTwinverseAspectViewpointCamera::CreateFromNative(const DTNACL_Twinverse_Aspect_ViewpointCamera *Camera)
{
	if (Camera == nullptr)
		return nullptr;

	UDTNativeClientTwinverseAspectViewpointCamera *Result = NewObject<UDTNativeClientTwinverseAspectViewpointCamera>();

	Result->Position = FVector(Camera->position.x, Camera->position.y, Camera->position.z);
	Result->Target = FVector(Camera->target.x, Camera->target.y, Camera->target.z);

	return Result;
}

/*
 */
UDTNativeClientTwinverseAspectHierarchy *UDTNativeClientTwinverseAspectHierarchy::CreateFromNative(const DTNACL_Twinverse_Aspect_Hierarchy *Hierarchy)
{
	if (Hierarchy == nullptr)
		return nullptr;

	UDTNativeClientTwinverseAspectHierarchy *Result = NewObject<UDTNativeClientTwinverseAspectHierarchy>();

	Result->Level = Hierarchy->level;
	Result->NodeType = FString(Hierarchy->node_type);

	return Result;
}

/*
 */
UDTNativeClientTwinverseAspectMaterial *UDTNativeClientTwinverseAspectMaterial::CreateFromNative(const DTNACL_Twinverse_Aspect_Material *Material)
{
	if (Material == nullptr)
		return nullptr;

	UDTNativeClientTwinverseAspectMaterial *Result = NewObject<UDTNativeClientTwinverseAspectMaterial>();

	Result->Color = FString(Material->color);
	Result->MaterialId = FString(Material->material_id);

	return Result;
}

/*
 */
UDTNativeClientTwinverseAspectDTDX *UDTNativeClientTwinverseAspectDTDX::CreateFromNative(const DTNACL_Twinverse_Aspect_DTDX *DTDX)
{
	if (DTDX == nullptr)
		return nullptr;

	UDTNativeClientTwinverseAspectDTDX *Result = NewObject<UDTNativeClientTwinverseAspectDTDX>();

	for (uint64 i = 0; i < DTDX->num_color_values; i++)
		Result->ColorValues.Add(DTDX->color_values[i]);

	Result->FileSize = DTDX->filesize;
	Result->ColorName = FString(DTDX->color_name);

	return Result;
}

/*
 */
UDTNativeClientTwinverseAspectVisibility *UDTNativeClientTwinverseAspectVisibility::CreateFromNative(const DTNACL_Twinverse_Aspect_Visibility *Visibility)
{
	if (Visibility == nullptr)
		return nullptr;

	UDTNativeClientTwinverseAspectVisibility *Result = NewObject<UDTNativeClientTwinverseAspectVisibility>();

	Result->Hidden = Visibility->hidden;

	return Result;
}

/*
 */
FDTNativeClientTwinverseArchetype FDTNativeClientTwinverseArchetype::FromNative(const DTNACL_Twinverse_Archetype &Archetype)
{
	FDTNativeClientTwinverseArchetype Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Archetype.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Archetype.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Archetype.world_id);
	Result.SourceId = FDTNativeClientCoreUUID::FromNative(Archetype.source_id);
	Result.Name = FDTNativeClientTwinverseName::FromNative(Archetype.name);
	Result.Key = FString(Archetype.key);
	Result.AspectBitmask = FString(Archetype.aspect_bitmask);

	Result.AspectIds.Reserve(Archetype.num_aspect_ids);
	for (uint64 i = 0; i < Archetype.num_aspect_ids; ++i)
		Result.AspectIds.Push(FDTNativeClientCoreUUID::FromNative(Archetype.aspect_ids[i]));

	FDateTime::Parse(FString(Archetype.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Archetype.updated_at), Result.UpdatedAt);

	return Result;
}

/*
 */
FDTNativeClientTwinverseExperience FDTNativeClientTwinverseExperience::FromNative(const DTNACL_Twinverse_Experience &Experience)
{
	FDTNativeClientTwinverseExperience Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Experience.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Experience.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Experience.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(Experience.enterprise_id);
	Result.ThumbnailAssetId = FDTNativeClientCoreUUID::FromNative(Experience.thumbnail_asset_id);
	Result.Name = FDTNativeClientTwinverseName::FromNative(Experience.name);
	FDateTime::Parse(FString(Experience.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Experience.updated_at), Result.UpdatedAt);
	Result.Dimension1Path = FString(Experience.dimension1_path);
	Result.Dimension2Path = FString(Experience.dimension2_path);
	Result.Dimension3Path = FString(Experience.dimension3_path);
	Result.Dimension4Path = FString(Experience.dimension4_path);
	Result.Dimension5Path = FString(Experience.dimension5_path);
	Result.Dimension6Path = FString(Experience.dimension6_path);
	Result.Dimension7Path = FString(Experience.dimension7_path);
	Result.Dimension8Path = FString(Experience.dimension8_path);
	Result.Key = FString(Experience.key);
	Result.Dimension1NodeId = FDTNativeClientCoreUUID::FromNative(Experience.dimension1_node_id);
	Result.Dimension2NodeId = FDTNativeClientCoreUUID::FromNative(Experience.dimension2_node_id);
	Result.Dimension3NodeId = FDTNativeClientCoreUUID::FromNative(Experience.dimension3_node_id);
	Result.Dimension4NodeId = FDTNativeClientCoreUUID::FromNative(Experience.dimension4_node_id);
	Result.Dimension5NodeId = FDTNativeClientCoreUUID::FromNative(Experience.dimension5_node_id);
	Result.Dimension6NodeId = FDTNativeClientCoreUUID::FromNative(Experience.dimension6_node_id);
	Result.Dimension7NodeId = FDTNativeClientCoreUUID::FromNative(Experience.dimension7_node_id);
	Result.Dimension8NodeId = FDTNativeClientCoreUUID::FromNative(Experience.dimension8_node_id);
	Result.Status = FString(Experience.status);

	return Result;
}

/*
 */
FDTNativeClientTwinverseMoment FDTNativeClientTwinverseMoment::FromNative(const DTNACL_Twinverse_Moment &Moment)
{
	FDTNativeClientTwinverseMoment Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Moment.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Moment.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Moment.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(Moment.enterprise_id);
	Result.LayoutId = FDTNativeClientCoreUUID::FromNative(Moment.layout_id);
	Result.ExperienceId = FDTNativeClientCoreUUID::FromNative(Moment.experience_id);
	Result.Name = FDTNativeClientTwinverseName::FromNative(Moment.name);
	Result.Index = FString(Moment.index);
	FDateTime::Parse(FString(Moment.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Moment.updated_at), Result.UpdatedAt);
	Result.Status = FString(Moment.status);

	return Result;
}

/*
 */
FDTNativeClientTwinverseKeyframe FDTNativeClientTwinverseKeyframe::FromNative(const DTNACL_Twinverse_Keyframe &Keyframe)
{
	FDTNativeClientTwinverseKeyframe Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Keyframe.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Keyframe.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Keyframe.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(Keyframe.enterprise_id);
	Result.MomentId = FDTNativeClientCoreUUID::FromNative(Keyframe.moment_id);
	Result.SceneId = FDTNativeClientCoreUUID::FromNative(Keyframe.scene_id);
	Result.TwinstanceId = FDTNativeClientCoreUUID::FromNative(Keyframe.twinstance_id);
	Result.AspectTransform = UDTNativeClientTwinverseAspectTransform::CreateFromNative(Keyframe.aspect_transform);
	Result.AspectViewpointCamera = UDTNativeClientTwinverseAspectViewpointCamera::CreateFromNative(Keyframe.aspect_viewpoint_camera);
	Result.AspectVisibility = UDTNativeClientTwinverseAspectVisibility::CreateFromNative(Keyframe.aspect_visibility);
	FDateTime::Parse(FString(Keyframe.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Keyframe.updated_at), Result.UpdatedAt);
	Result.Aspects = MapAspects(Keyframe.aspects);

	return Result;
}

/*
 */
FDTNativeClientTwinverseScene FDTNativeClientTwinverseScene::FromNative(const DTNACL_Twinverse_Scene &Scene)
{
	FDTNativeClientTwinverseScene Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Scene.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Scene.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Scene.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(Scene.enterprise_id);
	Result.MediaobjectId = FDTNativeClientCoreUUID::FromNative(Scene.mediaobject_id);
	Result.Name = FDTNativeClientTwinverseName::FromNative(Scene.name);
	FDateTime::Parse(FString(Scene.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Scene.updated_at), Result.UpdatedAt);

	return Result;
}

/*
 */
FDTNativeClientTwinverseTwinstance FDTNativeClientTwinverseTwinstance::FromNative(const DTNACL_Twinverse_Twinstance &Twinstance)
{
	FDTNativeClientTwinverseTwinstance Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Twinstance.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Twinstance.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Twinstance.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(Twinstance.enterprise_id);
	Result.TwinobjectId = FDTNativeClientCoreUUID::FromNative(Twinstance.twinobject_id);
	Result.SceneId = FDTNativeClientCoreUUID::FromNative(Twinstance.scene_id);
	Result.TwinstanceId = FDTNativeClientCoreUUID::FromNative(Twinstance.twinstance_id);
	Result.Name = FDTNativeClientTwinverseName::FromNative(Twinstance.name);
	Result.Keyframable = Twinstance.is_keyframable;
	Result.Type = FString(Twinstance.type);
	FDateTime::Parse(FString(Twinstance.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Twinstance.updated_at), Result.UpdatedAt);

	return Result;
}

/*
 */
FDTNativeClientTwinverseLayout FDTNativeClientTwinverseLayout::FromNative(const DTNACL_Twinverse_Layout &Layout)
{
	FDTNativeClientTwinverseLayout Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Layout.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Layout.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Layout.world_id);
	Result.SourceId = FDTNativeClientCoreUUID::FromNative(Layout.source_id);
	Result.Name = FDTNativeClientTwinverseName::FromNative(Layout.name);
	FDateTime::Parse(FString(Layout.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Layout.updated_at), Result.UpdatedAt);

	return Result;
}

/*
 */
FDTNativeClientTwinverseRegion FDTNativeClientTwinverseRegion::FromNative(const DTNACL_Twinverse_Region &Region)
{
	FDTNativeClientTwinverseRegion Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Region.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Region.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Region.world_id);
	Result.SourceId = FDTNativeClientCoreUUID::FromNative(Region.source_id);
	Result.LayoutId = FDTNativeClientCoreUUID::FromNative(Region.layout_id);
	Result.Name = FDTNativeClientTwinverseName::FromNative(Region.name);
	FDateTime::Parse(FString(Region.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Region.updated_at), Result.UpdatedAt);

	return Result;
}

/*
 */
FDTNativeClientTwinverseMediaobject FDTNativeClientTwinverseMediaobject::FromNative(const DTNACL_Twinverse_Mediaobject &Mediaobject)
{
	FDTNativeClientTwinverseMediaobject Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Mediaobject.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Mediaobject.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Mediaobject.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(Mediaobject.enterprise_id);
	Result.Name = FDTNativeClientTwinverseName::FromNative(Mediaobject.name);
	Result.Type = FString(Mediaobject.type);
	FDateTime::Parse(FString(Mediaobject.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Mediaobject.updated_at), Result.UpdatedAt);

	return Result;
}

/*
 */
FDTNativeClientTwinverseTwinobject FDTNativeClientTwinverseTwinobject::FromNative(const DTNACL_Twinverse_Twinobject &Twinobject)
{
	FDTNativeClientTwinverseTwinobject Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Twinobject.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Twinobject.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Twinobject.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(Twinobject.enterprise_id);
	Result.ArchetypeId = FDTNativeClientCoreUUID::FromNative(Twinobject.archetype_id);
	Result.TopTwinobjectId = FDTNativeClientCoreUUID::FromNative(Twinobject.top_twinobject_id);
	Result.TwinobjectId = FDTNativeClientCoreUUID::FromNative(Twinobject.twinobject_id);
	Result.SceneId = FDTNativeClientCoreUUID::FromNative(Twinobject.scene_id);
	Result.Name = FDTNativeClientTwinverseName::FromNative(Twinobject.name);
	Result.Key = FString(Twinobject.key);
	Result.AspectBitmask = FString(Twinobject.aspect_bitmask);
	Result.Status = FString(Twinobject.status);
	Result.AspectTransform = UDTNativeClientTwinverseAspectTransform::CreateFromNative(Twinobject.aspect_transform);
	Result.AspectHierarchy = UDTNativeClientTwinverseAspectHierarchy::CreateFromNative(Twinobject.aspect_hierarchy);
	Result.AspectMaterial = UDTNativeClientTwinverseAspectMaterial::CreateFromNative(Twinobject.aspect_material);
	Result.AspectDTDX = UDTNativeClientTwinverseAspectDTDX::CreateFromNative(Twinobject.aspect_dtdx);

	Result.TwinobjectAssets.Reserve(Twinobject.num_twinobject_assets);
	for (uint64 i = 0; i < Twinobject.num_twinobject_assets; ++i)
		Result.TwinobjectAssets.Push(FDTNativeClientTwinverseTwinobjectAsset::FromNative(Twinobject.twinobject_assets[i]));

	FDateTime::Parse(FString(Twinobject.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Twinobject.updated_at), Result.UpdatedAt);
	Result.Aspects = MapAspects(Twinobject.aspects);

	return Result;
}

/*
 */
FDTNativeClientTwinverseMediaobjectAsset FDTNativeClientTwinverseMediaobjectAsset::FromNative(const DTNACL_Twinverse_MediaobjectAsset &MediaobjectAsset)
{
	FDTNativeClientTwinverseMediaobjectAsset Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(MediaobjectAsset.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(MediaobjectAsset.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(MediaobjectAsset.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(MediaobjectAsset.enterprise_id);
	Result.AssetId = FDTNativeClientCoreUUID::FromNative(MediaobjectAsset.asset_id);
	Result.MediaobjectId = FDTNativeClientCoreUUID::FromNative(MediaobjectAsset.mediaobject_id);
	FDateTime::Parse(FString(MediaobjectAsset.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(MediaobjectAsset.updated_at), Result.UpdatedAt);

	return Result;
}

/*
 */
FDTNativeClientTwinverseTwinobjectAsset FDTNativeClientTwinverseTwinobjectAsset::FromNative(const DTNACL_Twinverse_TwinobjectAsset &TwinobjectAsset)
{
	FDTNativeClientTwinverseTwinobjectAsset Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(TwinobjectAsset.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(TwinobjectAsset.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(TwinobjectAsset.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(TwinobjectAsset.enterprise_id);
	Result.AssetId = FDTNativeClientCoreUUID::FromNative(TwinobjectAsset.asset_id);
	Result.TwinobjectId = FDTNativeClientCoreUUID::FromNative(TwinobjectAsset.twinobject_id);
	FDateTime::Parse(FString(TwinobjectAsset.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(TwinobjectAsset.updated_at), Result.UpdatedAt);

	return Result;
}

/*
 */
FDTNativeClientTwinverseAsset FDTNativeClientTwinverseAsset::FromNative(const DTNACL_Twinverse_Asset &Asset)
{
	FDTNativeClientTwinverseAsset Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(Asset.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(Asset.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(Asset.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(Asset.enterprise_id);
	Result.ObjectServiceId = FDTNativeClientCoreUUID::FromNative(Asset.object_service_id);
	Result.Name = FDTNativeClientTwinverseName::FromNative(Asset.name);
	Result.AssetType = FString(Asset.asset_type);
	Result.Lod = FString(Asset.lod);
	Result.Hash = FString(Asset.hash);
	FDateTime::Parse(FString(Asset.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(Asset.updated_at), Result.UpdatedAt);

	return Result;
}

/*
 */
FDTNativeClientTwinverseObjectService FDTNativeClientTwinverseObjectService::FromNative(const DTNACL_Twinverse_ObjectService &ObjectService)
{
	FDTNativeClientTwinverseObjectService Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(ObjectService.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(ObjectService.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(ObjectService.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(ObjectService.enterprise_id);
	Result.BucketId = FString(ObjectService.bucket_id);
	Result.AccessKey = FString(ObjectService.access_key);
	Result.Secret = FString(ObjectService.secret);
	Result.Type = FString(ObjectService.type);
	Result.Domain = FString(ObjectService.domain);
	FDateTime::Parse(FString(ObjectService.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(ObjectService.updated_at), Result.UpdatedAt);

	return Result;
}

/*
 */
FDTNativeClientTwinverseFile FDTNativeClientTwinverseFile::FromNative(const DTNACL_Twinverse_File &File)
{
	FDTNativeClientTwinverseFile Result = {};

	Result.Id = FDTNativeClientCoreUUID::FromNative(File.id);
	Result.UserId = FDTNativeClientCoreUUID::FromNative(File.user_id);
	Result.WorldId = FDTNativeClientCoreUUID::FromNative(File.world_id);
	Result.EnterpriseId = FDTNativeClientCoreUUID::FromNative(File.enterprise_id);
	Result.ObjectServiceId = FDTNativeClientCoreUUID::FromNative(File.object_service_id);
	Result.AssetId = FDTNativeClientCoreUUID::FromNative(File.asset_id);
	Result.Name = FString(File.name);
	Result.Description = FString(File.description);
	Result.UploadStatus = FString(File.upload_status);
	Result.ObjectExtension = FString(File.object_extension);
	Result.ObjectStorageId = FString(File.object_storage_id);
	Result.ObjectStorageDownloadUrl = FString(File.object_storage_download_url);
	Result.PresignedPutObjectUrl = FString(File.presigned_put_object_url);
	FDateTime::Parse(FString(File.object_storage_download_url_expires), Result.ObjectStorageDownloadUrlExpires);
	Result.ObjectSize = File.object_size;
	FDateTime::Parse(FString(File.created_at), Result.CreatedAt);
	FDateTime::Parse(FString(File.updated_at), Result.UpdatedAt);

	return Result;
}
