#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <dtnacl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 */
typedef struct DTNACL_Twinverse_Name_t
{
	const char *en;
	const char *cn;
} DTNACL_Twinverse_Name;

typedef struct DTNACL_Twinverse_Vec3_t
{
	float x, y, z;
} DTNACL_Twinverse_Vec3;

typedef struct DTNACL_Twinverse_Quat_t
{
	float x, y, z, w;
} DTNACL_Twinverse_Quat;

/*
 */
typedef struct DTNACL_Twinverse_Aspect_Transform_t
{
	DTNACL_Twinverse_Vec3 position;
	DTNACL_Twinverse_Quat rotation;
	DTNACL_Twinverse_Vec3 scale;
} DTNACL_Twinverse_Aspect_Transform;

typedef struct DTNACL_Twinverse_Aspect_ViewpointCamera_t
{
	DTNACL_Twinverse_Vec3 position;
	DTNACL_Twinverse_Vec3 target;
} DTNACL_Twinverse_Aspect_ViewpointCamera;

typedef struct DTNACL_Twinverse_Aspect_Hierarchy_t
{
	uint64_t level;
	const char *node_type;
} DTNACL_Twinverse_Aspect_Hierarchy;

typedef struct DTNACL_Twinverse_Aspect_Material_t
{
	const char *color;
	const char *material_id;
} DTNACL_Twinverse_Aspect_Material;

typedef struct DTNACL_Twinverse_Aspect_DTDX_t
{
	float *color_values;
	uint64_t num_color_values;
	uint64_t filesize;
	const char *color_name;
} DTNACL_Twinverse_Aspect_DTDX;

typedef struct DTNACL_Twinverse_Aspect_Visibility_t
{
	bool hidden;
} DTNACL_Twinverse_Aspect_Visibility;

// Outer structs

typedef struct DTNACL_Twinverse_Archetype_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID source_id;
	DTNACL_Twinverse_Name name;
	const char *key;
	const char *aspect_bitmask;
	uint64_t num_aspect_ids;
	DTNACL_Core_UUID *aspect_ids;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_Archetype;

typedef struct DTNACL_Twinverse_Experience_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID thumbnail_asset_id;
	DTNACL_Twinverse_Name name;
	const char *created_at;
	const char *updated_at;
	const char *dimension1_path;
	const char *dimension2_path;
	const char *dimension3_path;
	const char *dimension4_path;
	const char *dimension5_path;
	const char *dimension6_path;
	const char *dimension7_path;
	const char *dimension8_path;
	const char *key;
	DTNACL_Core_UUID dimension1_node_id;
	DTNACL_Core_UUID dimension2_node_id;
	DTNACL_Core_UUID dimension3_node_id;
	DTNACL_Core_UUID dimension4_node_id;
	DTNACL_Core_UUID dimension5_node_id;
	DTNACL_Core_UUID dimension6_node_id;
	DTNACL_Core_UUID dimension7_node_id;
	DTNACL_Core_UUID dimension8_node_id;
	const char *status;
} DTNACL_Twinverse_Experience;

typedef struct DTNACL_Twinverse_Moment_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID layout_id;
	DTNACL_Core_UUID experience_id;
	DTNACL_Twinverse_Name name;
	const char *index;
	const char *created_at;
	const char *updated_at;
	const char *status;
} DTNACL_Twinverse_Moment;

typedef struct DTNACL_Twinverse_Keyframe_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID moment_id;
	DTNACL_Core_UUID scene_id;
	DTNACL_Core_UUID twinstance_id;
	DTNACL_Twinverse_Aspect_Transform *aspect_transform;
	DTNACL_Twinverse_Aspect_ViewpointCamera *aspect_viewpoint_camera;
	DTNACL_Twinverse_Aspect_Visibility *aspect_visibility;
	const char *created_at;
	const char *updated_at;
	DTNACL_Core_TransportData aspects;
} DTNACL_Twinverse_Keyframe;

typedef struct DTNACL_Twinverse_Scene_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID mediaobject_id;
	DTNACL_Twinverse_Name name;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_Scene;

typedef struct DTNACL_Twinverse_Twinstance_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID twinobject_id;
	DTNACL_Core_UUID scene_id;
	DTNACL_Core_UUID twinstance_id;
	DTNACL_Twinverse_Name name;
	bool is_keyframable;
	const char *type;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_Twinstance;

typedef struct DTNACL_Twinverse_Layout_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID source_id;
	DTNACL_Twinverse_Name name;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_Layout;

typedef struct DTNACL_Twinverse_Region_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID source_id;
	DTNACL_Core_UUID layout_id;
	DTNACL_Twinverse_Name name;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_Region;

typedef struct DTNACL_Twinverse_Mediaobject_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Twinverse_Name name;
	const char *type;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_Mediaobject;

typedef struct DTNACL_Twinverse_TwinobjectAsset_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID asset_id;
	DTNACL_Core_UUID twinobject_id;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_TwinobjectAsset;

typedef struct DTNACL_Twinverse_Twinobject_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID archetype_id;
	DTNACL_Core_UUID top_twinobject_id;
	DTNACL_Core_UUID twinobject_id;
	DTNACL_Core_UUID scene_id;
	DTNACL_Twinverse_Name name;
	const char *key;
	const char *aspect_bitmask;
	const char *status;
	DTNACL_Twinverse_Aspect_Transform *aspect_transform;
	DTNACL_Twinverse_Aspect_Hierarchy *aspect_hierarchy;
	DTNACL_Twinverse_Aspect_Material *aspect_material;
	DTNACL_Twinverse_Aspect_DTDX *aspect_dtdx;
	uint64_t num_twinobject_assets;
	DTNACL_Twinverse_TwinobjectAsset *twinobject_assets;
	const char *created_at;
	const char *updated_at;
	DTNACL_Core_TransportData aspects;
} DTNACL_Twinverse_Twinobject;

typedef struct DTNACL_Twinverse_MediaobjectAsset_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID asset_id;
	DTNACL_Core_UUID mediaobject_id;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_MediaobjectAsset;

typedef struct DTNACL_Twinverse_Asset_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID object_service_id;
	DTNACL_Twinverse_Name name;
	const char *asset_type;
	const char *lod;
	const char *hash;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_Asset;

typedef struct DTNACL_Twinverse_ObjectService_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	const char *bucket_id;
	const char *access_key;
	const char *secret;
	const char *type;
	const char *domain;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_ObjectService;

typedef struct DTNACL_Twinverse_File
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID user_id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID object_service_id;
	DTNACL_Core_UUID asset_id;
	const char *name;
	const char *description;
	const char *upload_status;
	const char *object_extension;
	const char *object_storage_id;
	const char *object_storage_download_url;
	const char *object_storage_download_url_expires;
	const char *presigned_put_object_url;
	uint64_t object_size;
	const char *created_at;
	const char *updated_at;
} DTNACL_Twinverse_File;


/* Basic structs APIs
 */
DTNACL_API void dtnaclTwinverseCopyArchetype(const DTNACL_Twinverse_Archetype *source, DTNACL_Twinverse_Archetype *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyExperience(const DTNACL_Twinverse_Experience *source, DTNACL_Twinverse_Experience *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyMoment(const DTNACL_Twinverse_Moment *source, DTNACL_Twinverse_Moment *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyKeyframe(const DTNACL_Twinverse_Keyframe *source, DTNACL_Twinverse_Keyframe *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyScene(const DTNACL_Twinverse_Scene *source, DTNACL_Twinverse_Scene *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyTwinstance(const DTNACL_Twinverse_Twinstance *source, DTNACL_Twinverse_Twinstance *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyLayout(const DTNACL_Twinverse_Layout *source, DTNACL_Twinverse_Layout *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyRegion(const DTNACL_Twinverse_Region *source, DTNACL_Twinverse_Region *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyMediaobject(const DTNACL_Twinverse_Mediaobject *source, DTNACL_Twinverse_Mediaobject *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyTwinobject(const DTNACL_Twinverse_Twinobject *source, DTNACL_Twinverse_Twinobject *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyMediaobjectAsset(const DTNACL_Twinverse_MediaobjectAsset *source, DTNACL_Twinverse_MediaobjectAsset *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyTwinobjectAsset(const DTNACL_Twinverse_TwinobjectAsset *source, DTNACL_Twinverse_TwinobjectAsset *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyAsset(const DTNACL_Twinverse_Asset *source, DTNACL_Twinverse_Asset *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyObjectService(const DTNACL_Twinverse_ObjectService *source, DTNACL_Twinverse_ObjectService *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseCopyFile(const DTNACL_Twinverse_File *source, DTNACL_Twinverse_File *dest, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API void dtnaclTwinverseDeleteArchetype(DTNACL_Twinverse_Archetype *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteExperience(DTNACL_Twinverse_Experience *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteMoment(DTNACL_Twinverse_Moment *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteKeyframe(DTNACL_Twinverse_Keyframe *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteScene(DTNACL_Twinverse_Scene *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteTwinstance(DTNACL_Twinverse_Twinstance *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteLayout(DTNACL_Twinverse_Layout *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteRegion(DTNACL_Twinverse_Region *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteMediaobject(DTNACL_Twinverse_Mediaobject *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteTwinobject(DTNACL_Twinverse_Twinobject *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteMediaobjectAsset(DTNACL_Twinverse_MediaobjectAsset *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteTwinobjectAsset(DTNACL_Twinverse_TwinobjectAsset *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteAsset(DTNACL_Twinverse_Asset *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteObjectService(DTNACL_Twinverse_ObjectService *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclTwinverseDeleteFile(DTNACL_Twinverse_File *object, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

/*
 */
DTNACL_API bool dtnaclTwinverseDeserializeArchetype(DTNACL_Core_TransportData data, DTNACL_Twinverse_Archetype *archetype, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeArchetype(const DTNACL_Twinverse_Archetype *archetype, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeExperience(DTNACL_Core_TransportData data, DTNACL_Twinverse_Experience *experience, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeExperience(const DTNACL_Twinverse_Experience *experience, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeMoment(DTNACL_Core_TransportData data, DTNACL_Twinverse_Moment *moment, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeMoment(const DTNACL_Twinverse_Moment *moment, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeKeyframe(DTNACL_Core_TransportData data, DTNACL_Twinverse_Keyframe *keyframe, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeKeyframe(const DTNACL_Twinverse_Keyframe *keyframe, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeScene(DTNACL_Core_TransportData data, DTNACL_Twinverse_Scene *scene, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeScene(const DTNACL_Twinverse_Scene *scene, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeTwinstance(DTNACL_Core_TransportData data, DTNACL_Twinverse_Twinstance *twinstance, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeTwinstance(const DTNACL_Twinverse_Twinstance *twinstance, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeLayout(DTNACL_Core_TransportData data, DTNACL_Twinverse_Layout *layout, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeLayout(const DTNACL_Twinverse_Layout *layout, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeRegion(DTNACL_Core_TransportData data, DTNACL_Twinverse_Region *region, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeRegion(const DTNACL_Twinverse_Region *region, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeMediaobject(DTNACL_Core_TransportData data, DTNACL_Twinverse_Mediaobject *mediaobject, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeMediaobject(const DTNACL_Twinverse_Mediaobject *mediaobject, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeTwinobject(DTNACL_Core_TransportData data, DTNACL_Twinverse_Twinobject *twinobject, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeTwinobject(const DTNACL_Twinverse_Twinobject *twinobject, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeMediaobjectAsset(DTNACL_Core_TransportData data, DTNACL_Twinverse_MediaobjectAsset *mediaobject_asset, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeMediaobjectAsset(const DTNACL_Twinverse_MediaobjectAsset *mediaobject_asset, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeTwinobjectAsset(DTNACL_Core_TransportData data, DTNACL_Twinverse_TwinobjectAsset *twinobject_asset, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeTwinobjectAsset(const DTNACL_Twinverse_TwinobjectAsset *twinobject_asset, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeAsset(DTNACL_Core_TransportData data, DTNACL_Twinverse_Asset *asset, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeAsset(const DTNACL_Twinverse_Asset *asset, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeObjectService(DTNACL_Core_TransportData data, DTNACL_Twinverse_ObjectService *object_service, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeObjectService(const DTNACL_Twinverse_ObjectService *object_service, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeFile(DTNACL_Core_TransportData data, DTNACL_Twinverse_File *file, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeFile(const DTNACL_Twinverse_File *file, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

/* Aspect API
 */
DTNACL_API bool dtnaclTwinverseDeserializeAspectTransform(DTNACL_Core_TransportData data, DTNACL_Twinverse_Aspect_Transform *aspect_transform, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeAspectTransform(const DTNACL_Twinverse_Aspect_Transform *aspect_transform, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeAspectViewpointCamera(DTNACL_Core_TransportData data, DTNACL_Twinverse_Aspect_ViewpointCamera *aspect_viewpoint_camera, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeAspectViewpointCamera(const DTNACL_Twinverse_Aspect_ViewpointCamera *aspect_viewpoint_camera, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeAspectHierarchy(DTNACL_Core_TransportData data, DTNACL_Twinverse_Aspect_Hierarchy *aspect_hierarchy, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeAspectHierarchy(const DTNACL_Twinverse_Aspect_Hierarchy *aspect_hierarchy, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeAspectMaterial(DTNACL_Core_TransportData data, DTNACL_Twinverse_Aspect_Material *aspect_material, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeAspectMaterial(const DTNACL_Twinverse_Aspect_Material *aspect_material, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeAspectDTDX(DTNACL_Core_TransportData data, DTNACL_Twinverse_Aspect_DTDX *aspect_dtdx, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeAspectDTDX(const DTNACL_Twinverse_Aspect_DTDX *aspect_dtdx, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

DTNACL_API bool dtnaclTwinverseDeserializeAspectVisibility(DTNACL_Core_TransportData data, DTNACL_Twinverse_Aspect_Visibility *aspect_visibility, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclTwinverseSerializeAspectVisibility(const DTNACL_Twinverse_Aspect_Visibility *aspect_visibility, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

/* Callbacks
 */
typedef void(*DTNACL_Twinverse_ArchetypeRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Archetype *archetypes, uint64_t num_archetypes, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_ExperienceRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Experience *experiences, uint64_t num_experiences, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_MomentRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Moment *moments, uint64_t num_moments, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_KeyframeRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Keyframe *keyframes, uint64_t num_keyframes, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_SceneRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Scene *scenes, uint64_t num_scenes, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_TwinstanceRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Twinstance *twinstances, uint64_t num_twinstances, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_LayoutRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Layout *layouts, uint64_t num_layouts, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_RegionRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Region *regions, uint64_t num_regions, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_MediaobjectRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Mediaobject *mediaobjects, uint64_t num_mediaobjects, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_TwinobjectRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Twinobject *twinobjects, uint64_t num_twinobjects, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_MediaobjectAssetRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_MediaobjectAsset *mediaobjects_asset, uint64_t num_mediaobject_assets, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_TwinobjectAssetRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_TwinobjectAsset *twinobjects_asset, uint64_t num_twinobject_assets, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_AssetRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Asset *assets, uint64_t num_assets, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_ObjectServiceRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_ObjectService *object_services, uint64_t num_object_services, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Twinverse_FileRequestCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_File *file, uint64_t num_files, DTNACL_Core_Status status, void *user_data);

typedef void(*DTNACL_Twinverse_ArchetypeEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Archetype *archetypes, uint64_t num_archetypes, void *user_data);
typedef void(*DTNACL_Twinverse_ExperienceEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Experience *experiences, uint64_t num_experiences, void *user_data);
typedef void(*DTNACL_Twinverse_MomentEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Moment *moments, uint64_t num_moments, void *user_data);
typedef void(*DTNACL_Twinverse_KeyframeEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Keyframe *keyframes, uint64_t num_keyframes, void *user_data);
typedef void(*DTNACL_Twinverse_SceneEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Scene *scenes, uint64_t num_scenes, void *user_data);
typedef void(*DTNACL_Twinverse_TwinstanceEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Twinstance *twinstances, uint64_t num_twinstances, void *user_data);
typedef void(*DTNACL_Twinverse_LayoutEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Layout *layouts, uint64_t num_layouts, void *user_data);
typedef void(*DTNACL_Twinverse_RegionEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Region *regions, uint64_t num_regions, void *user_data);
typedef void(*DTNACL_Twinverse_MediaobjectEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Mediaobject *mediaobjects, uint64_t num_mediaobjects, void *user_data);
typedef void(*DTNACL_Twinverse_TwinobjectEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Twinobject *twinobjects, uint64_t num_twinobjects, void *user_data);
typedef void(*DTNACL_Twinverse_MediaobjectAssetEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_MediaobjectAsset *mediaobjects_asset, uint64_t num_mediaobject_assets, void *user_data);
typedef void(*DTNACL_Twinverse_TwinobjectAssetEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_TwinobjectAsset *twinobjects_asset, uint64_t num_twinobject_assets, void *user_data);
typedef void(*DTNACL_Twinverse_AssetEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_Asset *assets, uint64_t num_assets, void *user_data);
typedef void(*DTNACL_Twinverse_ObjectServiceEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_ObjectService *object_services, uint64_t num_object_services, void *user_data);
typedef void(*DTNACL_Twinverse_FileEventCallback)(DTNACL_Core_Session session, const DTNACL_Twinverse_File *file, uint64_t num_files, void *user_data);

/* General twinverse request
 */
DTNACL_API void dtnaclTwinverseRequestAll(DTNACL_Core_Session session, const char *service_name, const DTNACL_Core_TransportData *parameters, uint64_t num_parameters, DTNACL_Core_RequestCallback callback, void *user_data = nullptr);

/* Specialized twinverse requests
 */
DTNACL_API void dtnaclTwinverseCreateArhectype(DTNACL_Core_Session session, const DTNACL_Twinverse_Archetype &experience, DTNACL_Twinverse_ArchetypeRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateExperience(DTNACL_Core_Session session, const DTNACL_Twinverse_Experience &experience, DTNACL_Twinverse_ExperienceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateMoment(DTNACL_Core_Session session, const DTNACL_Twinverse_Moment &moment, DTNACL_Twinverse_MomentRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateKeyframe(DTNACL_Core_Session session, const DTNACL_Twinverse_Keyframe &keyframe, DTNACL_Twinverse_KeyframeRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateScene(DTNACL_Core_Session session, const DTNACL_Twinverse_Scene &scene, DTNACL_Twinverse_SceneRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateTwinstance(DTNACL_Core_Session session, const DTNACL_Twinverse_Twinstance &twinstance, DTNACL_Twinverse_TwinstanceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateLayout(DTNACL_Core_Session session, const DTNACL_Twinverse_Layout &layout, DTNACL_Twinverse_LayoutRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateRegion(DTNACL_Core_Session session, const DTNACL_Twinverse_Region &region, DTNACL_Twinverse_RegionRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateMediaobject(DTNACL_Core_Session session, const DTNACL_Twinverse_Mediaobject &mediaobject, DTNACL_Twinverse_MediaobjectRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateTwinobject(DTNACL_Core_Session session, const DTNACL_Twinverse_Twinobject &twinobject, DTNACL_Twinverse_TwinobjectRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateMediaobjectAsset(DTNACL_Core_Session session, const DTNACL_Twinverse_MediaobjectAsset &mediaobject_asset, DTNACL_Twinverse_MediaobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateTwinobjectAsset(DTNACL_Core_Session session, const DTNACL_Twinverse_TwinobjectAsset &twinobject_asset, DTNACL_Twinverse_TwinobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateAsset(DTNACL_Core_Session session, const DTNACL_Twinverse_Asset &asset, DTNACL_Twinverse_AssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateObjectService(DTNACL_Core_Session session, const DTNACL_Twinverse_ObjectService &object_service, DTNACL_Twinverse_ObjectServiceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseCreateFile(DTNACL_Core_Session session, const DTNACL_Twinverse_File &file, DTNACL_Twinverse_FileRequestCallback callback, void *user_data = nullptr);

DTNACL_API void dtnaclTwinverseRequestAllArchetypes(DTNACL_Core_Session session, DTNACL_Twinverse_ArchetypeRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllExperiences(DTNACL_Core_Session session, DTNACL_Twinverse_ExperienceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllMoments(DTNACL_Core_Session session, DTNACL_Twinverse_MomentRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllKeyframes(DTNACL_Core_Session session, DTNACL_Twinverse_KeyframeRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllScenes(DTNACL_Core_Session session, DTNACL_Twinverse_SceneRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllTwinstances(DTNACL_Core_Session session, DTNACL_Twinverse_TwinstanceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllLayouts(DTNACL_Core_Session session, DTNACL_Twinverse_LayoutRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllRegions(DTNACL_Core_Session session, DTNACL_Twinverse_RegionRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllMediaobjects(DTNACL_Core_Session session, DTNACL_Twinverse_MediaobjectRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllTwinobjects(DTNACL_Core_Session session, DTNACL_Twinverse_TwinobjectRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllMediaobjectAssets(DTNACL_Core_Session session, DTNACL_Twinverse_MediaobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllTwinobjectAssets(DTNACL_Core_Session session, DTNACL_Twinverse_TwinobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllAssets(DTNACL_Core_Session session, DTNACL_Twinverse_AssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllObjectServices(DTNACL_Core_Session session, DTNACL_Twinverse_ObjectServiceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestAllFiles(DTNACL_Core_Session session, DTNACL_Twinverse_FileRequestCallback callback, void *user_data = nullptr);

DTNACL_API void dtnaclTwinversePatchArchetype(DTNACL_Core_Session session, const DTNACL_Twinverse_Archetype &archetype, DTNACL_Twinverse_ArchetypeRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchExperience(DTNACL_Core_Session session, const DTNACL_Twinverse_Experience &experience, DTNACL_Twinverse_ExperienceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchMoment(DTNACL_Core_Session session, const DTNACL_Twinverse_Moment &moment, DTNACL_Twinverse_MomentRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchKeyframe(DTNACL_Core_Session session, const DTNACL_Twinverse_Keyframe &keyframe, DTNACL_Twinverse_KeyframeRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchScene(DTNACL_Core_Session session, const DTNACL_Twinverse_Scene &scene, DTNACL_Twinverse_SceneRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchTwinstance(DTNACL_Core_Session session, const DTNACL_Twinverse_Twinstance &twinstance, DTNACL_Twinverse_TwinstanceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchLayout(DTNACL_Core_Session session, const DTNACL_Twinverse_Layout &layout, DTNACL_Twinverse_LayoutRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchRegion(DTNACL_Core_Session session, const DTNACL_Twinverse_Region &region, DTNACL_Twinverse_RegionRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchMediaobject(DTNACL_Core_Session session, const DTNACL_Twinverse_Mediaobject &mediaobject, DTNACL_Twinverse_MediaobjectRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchTwinobject(DTNACL_Core_Session session, const DTNACL_Twinverse_Twinobject &twinobject, DTNACL_Twinverse_TwinobjectRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchMediaobjectAsset(DTNACL_Core_Session session, const DTNACL_Twinverse_MediaobjectAsset &mediaobject_asset, DTNACL_Twinverse_MediaobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchTwinobjectAsset(DTNACL_Core_Session session, const DTNACL_Twinverse_TwinobjectAsset &twinobject_asset, DTNACL_Twinverse_TwinobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchAsset(DTNACL_Core_Session session, const DTNACL_Twinverse_Asset &asset, DTNACL_Twinverse_AssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchObjectService(DTNACL_Core_Session session, const DTNACL_Twinverse_ObjectService &object_service, DTNACL_Twinverse_ObjectServiceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinversePatchFile(DTNACL_Core_Session session, const DTNACL_Twinverse_File &file, DTNACL_Twinverse_FileRequestCallback callback, void *user_data = nullptr);

DTNACL_API void dtnaclTwinverseRemoveArchetype(DTNACL_Core_Session session, const DTNACL_Core_UUID &archetype_id, DTNACL_Twinverse_ArchetypeRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveExperience(DTNACL_Core_Session session, const DTNACL_Core_UUID &experience_id, DTNACL_Twinverse_ExperienceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveMoment(DTNACL_Core_Session session, const DTNACL_Core_UUID &moment_id, DTNACL_Twinverse_MomentRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveKeyframe(DTNACL_Core_Session session, const DTNACL_Core_UUID &keyframe_id, DTNACL_Twinverse_KeyframeRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveScene(DTNACL_Core_Session session, const DTNACL_Core_UUID &scene_id, DTNACL_Twinverse_SceneRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveTwinstance(DTNACL_Core_Session session, const DTNACL_Core_UUID &twinstance_id, DTNACL_Twinverse_TwinstanceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveLayout(DTNACL_Core_Session session, const DTNACL_Core_UUID &layout_id, DTNACL_Twinverse_LayoutRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveRegion(DTNACL_Core_Session session, const DTNACL_Core_UUID &region_id, DTNACL_Twinverse_RegionRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveMediaobject(DTNACL_Core_Session session, const DTNACL_Core_UUID &mediaobject_id, DTNACL_Twinverse_MediaobjectRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveTwinobject(DTNACL_Core_Session session, const DTNACL_Core_UUID &twinobject_id, DTNACL_Twinverse_TwinobjectRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveMediaobjectAsset(DTNACL_Core_Session session, const DTNACL_Core_UUID &mediaobject_asset_id, DTNACL_Twinverse_MediaobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveTwinobjectAsset(DTNACL_Core_Session session, const DTNACL_Core_UUID &twinobject_asset_id, DTNACL_Twinverse_TwinobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveAsset(DTNACL_Core_Session session, const DTNACL_Core_UUID &asset_id, DTNACL_Twinverse_AssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveObjectService(DTNACL_Core_Session session, const DTNACL_Core_UUID &object_service_id, DTNACL_Twinverse_ObjectServiceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveFile(DTNACL_Core_Session session, const DTNACL_Core_UUID &file_id, DTNACL_Twinverse_FileRequestCallback callback, void *user_data = nullptr);

/*
 */
DTNACL_API void dtnaclTwinverseRequestMomentsForExperience(DTNACL_Core_Session session, DTNACL_Core_UUID experience_id, DTNACL_Twinverse_MomentRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestMomentsForScene(DTNACL_Core_Session session, DTNACL_Core_UUID scene_id, DTNACL_Twinverse_MomentRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestMomentsForTwinstance(DTNACL_Core_Session session, DTNACL_Core_UUID twinstance_id, DTNACL_Twinverse_MomentRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestMomentsForLayout(DTNACL_Core_Session session, DTNACL_Core_UUID layout_id, DTNACL_Twinverse_MomentRequestCallback callback, void *user_data = nullptr);

DTNACL_API void dtnaclTwinverseRequestKeyframesForMoment(DTNACL_Core_Session session, DTNACL_Core_UUID moment_id, DTNACL_Twinverse_KeyframeRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestKeyframesForScene(DTNACL_Core_Session session, DTNACL_Core_UUID scene_id, DTNACL_Twinverse_KeyframeRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestKeyframesForTwinstance(DTNACL_Core_Session session, DTNACL_Core_UUID twinstance_id, DTNACL_Twinverse_KeyframeRequestCallback callback, void *user_data = nullptr);

DTNACL_API void dtnaclTwinverseRequestScenesForMoment(DTNACL_Core_Session session, DTNACL_Core_UUID moment_id, DTNACL_Twinverse_SceneRequestCallback callback, void *user_data = nullptr);

DTNACL_API void dtnaclTwinverseRequestTwinstancesForMoment(DTNACL_Core_Session session, DTNACL_Core_UUID moment_id, DTNACL_Twinverse_TwinstanceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestTwinstancesForScene(DTNACL_Core_Session session, DTNACL_Core_UUID scene_id, DTNACL_Twinverse_TwinstanceRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestTwinstancesForExperience(DTNACL_Core_Session session, DTNACL_Core_UUID experience_id, DTNACL_Twinverse_TwinstanceRequestCallback callback, void *user_data = nullptr);

DTNACL_API void dtnaclTwinverseRequestTwinobjectsForExperience(DTNACL_Core_Session session, DTNACL_Core_UUID experience_id, DTNACL_Twinverse_TwinobjectRequestCallback callback, void *user_data = nullptr);

DTNACL_API void dtnaclTwinverseRequestTwinobjectAssetsForExperience(DTNACL_Core_Session session, DTNACL_Core_UUID experience_id, DTNACL_Twinverse_TwinobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestTwinobjectAssetsForMoment(DTNACL_Core_Session session, DTNACL_Core_UUID moment_id, DTNACL_Twinverse_TwinobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestTwinobjectAssetsForScene(DTNACL_Core_Session session, DTNACL_Core_UUID scene_id, DTNACL_Twinverse_TwinobjectAssetRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestTwinobjectAssetsForTwinstance(DTNACL_Core_Session session, DTNACL_Core_UUID twinstance_id, DTNACL_Twinverse_TwinobjectAssetRequestCallback callback, void *user_data = nullptr);

DTNACL_API void dtnaclTwinverseRequestAssetsForTwinobject(DTNACL_Core_Session session, DTNACL_Core_UUID twinobject_id, DTNACL_Twinverse_AssetRequestCallback callback, void *user_data = nullptr);

DTNACL_API void dtnaclTwinverseRequestFilesForTwinobject(DTNACL_Core_Session session, DTNACL_Core_UUID twinobject_id, DTNACL_Twinverse_FileRequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRequestFilesForAssets(DTNACL_Core_Session session, const DTNACL_Core_UUID *asset_ids, uint64_t num_asset_ids, DTNACL_Twinverse_FileRequestCallback callback, void *user_data = nullptr);

/* Specialized Twinverse event listeners
 */
DTNACL_API void dtnaclTwinverseAddListenerArchetypesCreated(DTNACL_Core_Session session, DTNACL_Twinverse_ArchetypeEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerArchetypesRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_ArchetypeEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerArchetypesPatched(DTNACL_Core_Session session, DTNACL_Twinverse_ArchetypeEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerArchetypesCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerArchetypesRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerArchetypesPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerExperiencesCreated(DTNACL_Core_Session session, DTNACL_Twinverse_ExperienceEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerExperiencesRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_ExperienceEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerExperiencesPatched(DTNACL_Core_Session session, DTNACL_Twinverse_ExperienceEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerExperiencesCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerExperiencesRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerExperiencesPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerMomentsCreated(DTNACL_Core_Session session, DTNACL_Twinverse_MomentEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerMomentsRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_MomentEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerMomentsPatched(DTNACL_Core_Session session, DTNACL_Twinverse_MomentEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerMomentsCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerMomentsRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerMomentsPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerKeyframesCreated(DTNACL_Core_Session session, DTNACL_Twinverse_KeyframeEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerKeyframesRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_KeyframeEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerKeyframesPatched(DTNACL_Core_Session session, DTNACL_Twinverse_KeyframeEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerKeyframesCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerKeyframesRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerKeyframesPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerScenesCreated(DTNACL_Core_Session session, DTNACL_Twinverse_SceneEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerScenesRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_SceneEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerScenesPatched(DTNACL_Core_Session session, DTNACL_Twinverse_SceneEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerScenesCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerScenesRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerScenesPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerTwinstancesCreated(DTNACL_Core_Session session, DTNACL_Twinverse_TwinstanceEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerTwinstancesRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_TwinstanceEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerTwinstancesPatched(DTNACL_Core_Session session, DTNACL_Twinverse_TwinstanceEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerTwinstancesCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerTwinstancesRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerTwinstancesPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerLayoutsCreated(DTNACL_Core_Session session, DTNACL_Twinverse_LayoutEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerLayoutsRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_LayoutEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerLayoutsPatched(DTNACL_Core_Session session, DTNACL_Twinverse_LayoutEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerLayoutsCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerLayoutsRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerLayoutsPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerRegionsCreated(DTNACL_Core_Session session, DTNACL_Twinverse_RegionEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerRegionsRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_RegionEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerRegionsPatched(DTNACL_Core_Session session, DTNACL_Twinverse_RegionEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerRegionsCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerRegionsRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerRegionsPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerMediaobjectsCreated(DTNACL_Core_Session session, DTNACL_Twinverse_MediaobjectEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerMediaobjectsRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_MediaobjectEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerMediaobjectsPatched(DTNACL_Core_Session session, DTNACL_Twinverse_MediaobjectEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerMediaobjectsCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerMediaobjectsRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerMediaobjectsPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerTwinobjectsCreated(DTNACL_Core_Session session, DTNACL_Twinverse_TwinobjectEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerTwinobjectsRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_TwinobjectEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerTwinobjectsPatched(DTNACL_Core_Session session, DTNACL_Twinverse_TwinobjectEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerTwinobjectsCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerTwinobjectsRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerTwinobjectsPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerMediaobjectAssetsCreated(DTNACL_Core_Session session, DTNACL_Twinverse_MediaobjectAssetEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerMediaobjectAssetsRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_MediaobjectAssetEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerMediaobjectAssetsPatched(DTNACL_Core_Session session, DTNACL_Twinverse_MediaobjectAssetEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerMediaobjectAssetsCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerMediaobjectAssetsRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerMediaobjectAssetsPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerTwinobjectAssetsCreated(DTNACL_Core_Session session, DTNACL_Twinverse_TwinobjectAssetEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerTwinobjectAssetsRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_TwinobjectAssetEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerTwinobjectAssetsPatched(DTNACL_Core_Session session, DTNACL_Twinverse_TwinobjectAssetEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerTwinobjectAssetsCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerTwinobjectAssetsRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerTwinobjectAssetsPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerAssetsCreated(DTNACL_Core_Session session, DTNACL_Twinverse_AssetEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerAssetsRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_AssetEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerAssetsPatched(DTNACL_Core_Session session, DTNACL_Twinverse_AssetEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerAssetsCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerAssetsRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerAssetsPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerObjectServicesCreated(DTNACL_Core_Session session, DTNACL_Twinverse_ObjectServiceEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerObjectServicesRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_ObjectServiceEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerObjectServicesPatched(DTNACL_Core_Session session, DTNACL_Twinverse_ObjectServiceEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerObjectServicesCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerObjectServicesRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerObjectServicesPatched(DTNACL_Core_Session session);

DTNACL_API void dtnaclTwinverseAddListenerFilesCreated(DTNACL_Core_Session session, DTNACL_Twinverse_FileEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerFilesRemoved(DTNACL_Core_Session session, DTNACL_Twinverse_FileEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseAddListenerFilesPatched(DTNACL_Core_Session session, DTNACL_Twinverse_FileEventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclTwinverseRemoveListenerFilesCreated(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerFilesRemoved(DTNACL_Core_Session session);
DTNACL_API void dtnaclTwinverseRemoveListenerFilesPatched(DTNACL_Core_Session session);


#ifdef __cplusplus
}
#endif
