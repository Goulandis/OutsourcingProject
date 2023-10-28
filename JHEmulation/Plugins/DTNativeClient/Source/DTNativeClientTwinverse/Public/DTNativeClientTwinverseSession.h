#pragma once

#include "CoreMinimal.h"

#include "DTNativeClientCoreSession.h"
#include "DTNativeClientTwinverseCommon.h"
#include "DTNativeClientTwinverseSession.generated.h"

/*
 */
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseArchetypeListCallback, const TArray<FDTNativeClientTwinverseArchetype> &, Archetypes, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseExperienceListCallback, const TArray<FDTNativeClientTwinverseExperience> &, Experiences, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseMomentListCallback, const TArray<FDTNativeClientTwinverseMoment> &, Moments, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseKeyframeListCallback, const TArray<FDTNativeClientTwinverseKeyframe> &, Keyframes, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseSceneListCallback, const TArray<FDTNativeClientTwinverseScene> &, Scenes, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseTwinstanceListCallback, const TArray<FDTNativeClientTwinverseTwinstance> &, Twinstances, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseLayoutListCallback, const TArray<FDTNativeClientTwinverseLayout> &, Layouts, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseRegionListCallback, const TArray<FDTNativeClientTwinverseRegion> &, Regions, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseMediaobjectListCallback, const TArray<FDTNativeClientTwinverseMediaobject> &, Mediaobjects, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseTwinobjectListCallback, const TArray<FDTNativeClientTwinverseTwinobject> &, Twinobjects, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseMediaobjectAssetListCallback, const TArray<FDTNativeClientTwinverseMediaobjectAsset> &, MediaobjectAssets, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseTwinobjectAssetListCallback, const TArray<FDTNativeClientTwinverseTwinobjectAsset> &, TwinobjectAssets, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseAssetListCallback, const TArray<FDTNativeClientTwinverseAsset> &, Assets, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseObjectServiceListCallback, const TArray<FDTNativeClientTwinverseObjectService> &, ObjectServices, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientTwinverseFileListCallback, const TArray<FDTNativeClientTwinverseFile> &, Files, int, Status);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseArchetypeListEvent, const TArray<FDTNativeClientTwinverseArchetype> &, Archetypes);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseExperienceListEvent, const TArray<FDTNativeClientTwinverseExperience> &, Experiences);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseMomentListEvent, const TArray<FDTNativeClientTwinverseMoment> &, Moments);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseKeyframeListEvent, const TArray<FDTNativeClientTwinverseKeyframe> &, Keyframes);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseSceneListEvent, const TArray<FDTNativeClientTwinverseScene> &, Scenes);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseTwinstanceListEvent, const TArray<FDTNativeClientTwinverseTwinstance> &, Twinstances);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseLayoutListEvent, const TArray<FDTNativeClientTwinverseLayout> &, Layouts);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseRegionListEvent, const TArray<FDTNativeClientTwinverseRegion> &, Regions);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseMediaobjectListEvent, const TArray<FDTNativeClientTwinverseMediaobject> &, Mediaobjects);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseTwinobjectListEvent, const TArray<FDTNativeClientTwinverseTwinobject> &, Twinobjects);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseMediaobjectAssetListEvent, const TArray<FDTNativeClientTwinverseMediaobjectAsset> &, MediaobjectAssets);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseTwinobjectAssetListEvent, const TArray<FDTNativeClientTwinverseTwinobjectAsset> &, TwinobjectAssets);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseAssetListEvent, const TArray<FDTNativeClientTwinverseAsset> &, Assets);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseObjectServiceListEvent, const TArray<FDTNativeClientTwinverseObjectService> &, ObjectServices);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTNativeClientTwinverseFileListEvent, const TArray<FDTNativeClientTwinverseFile> &, Files);

/*
 */
UCLASS(ClassGroup = "DTNativeClientTwinverse|Session", BlueprintType, meta=(BlueprintSpawnableComponent))
class DTNATIVECLIENTTWINVERSE_API UDTNativeClientTwinverseSession : public UDTNativeClientCoreSession
{
	GENERATED_BODY()

public:
	UDTNativeClientTwinverseSession();

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "DTNativeClientTwinverse|Session")
	void AddListeners();
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "DTNativeClientTwinverse|Session")
	void RemoveListeners();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All", Keywords = "Twinverse Session Request", AutoCreateRefTerm = "Parameters"), Category = "DTNativeClientTwinverse|Session")
	void RequestAll(const FString &Service, const TArray<UDTNativeClientCoreTransportData *> &Parameters, FDTNativeClientCoreRequestCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Latent", Keywords = "Twinverse Session Request Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext", AutoCreateRefTerm = "Parameters"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllLatent(
		UObject *WorldContext, const FString &Service, const TArray<UDTNativeClientCoreTransportData *> &Parameters,
		FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
		TArray<UDTNativeClientCoreTransportData *> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Archetypes", Keywords = "Twinverse Session Request Archetypes"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllArchetypes(FDTNativeClientTwinverseArchetypeListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Archetypes Latent", Keywords = "Twinverse Session Request Archetypes Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllArchetypesLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseArchetype> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseArchetypeListEvent OnArchetypesCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseArchetypeListEvent OnArchetypesRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseArchetypeListEvent OnArchetypesPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Experiences", Keywords = "Twinverse Session Request Experiences"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllExperiences(FDTNativeClientTwinverseExperienceListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Experiences Latent", Keywords = "Twinverse Session Request Experiences Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllExperiencesLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseExperience> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseExperienceListEvent OnExperiencesCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseExperienceListEvent OnExperiencesRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseExperienceListEvent OnExperiencesPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Moments", Keywords = "Twinverse Session Request Moments"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllMoments(FDTNativeClientTwinverseMomentListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Moments Latent", Keywords = "Twinverse Session Request Moments Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllMomentsLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseMoment> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Moments For Experience", Keywords = "Twinverse Session Request Moments"), Category = "DTNativeClientTwinverse|Session")
	void RequestMomentsForExperience(const FDTNativeClientCoreUUID &ExperienceID, FDTNativeClientTwinverseMomentListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Moments For Experience Latent", Keywords = "Twinverse Session Request Moments Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestMomentsForExperienceLatent(
		const FDTNativeClientCoreUUID &ExperienceID, 
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseMoment> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Moments For Scene", Keywords = "Twinverse Session Request Moments"), Category = "DTNativeClientTwinverse|Session")
	void RequestMomentsForScene(const FDTNativeClientCoreUUID &SceneID, FDTNativeClientTwinverseMomentListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Moments For Scene Latent", Keywords = "Twinverse Session Request Moments Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestMomentsForSceneLatent(
		const FDTNativeClientCoreUUID &SceneID, 
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseMoment> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Moments For Twinstance", Keywords = "Twinverse Session Request Moments"), Category = "DTNativeClientTwinverse|Session")
	void RequestMomentsForTwinstance(const FDTNativeClientCoreUUID &TwinstanceID, FDTNativeClientTwinverseMomentListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Moments For Twinstance Latent", Keywords = "Twinverse Session Request Moments Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestMomentsForTwinstanceLatent(
		const FDTNativeClientCoreUUID &TwinstanceID, 
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseMoment> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Moments For Layout", Keywords = "Twinverse Session Request Moments"), Category = "DTNativeClientTwinverse|Session")
	void RequestMomentsForLayout(const FDTNativeClientCoreUUID &LayoutID, FDTNativeClientTwinverseMomentListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Moments For Layout Latent", Keywords = "Twinverse Session Request Moments Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestMomentsForLayoutLatent(
		const FDTNativeClientCoreUUID &LayoutID, 
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseMoment> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseMomentListEvent OnMomentsCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseMomentListEvent OnMomentsRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseMomentListEvent OnMomentsPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Keyframes", Keywords = "Twinverse Session Request Keyframes"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllKeyframes(FDTNativeClientTwinverseKeyframeListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Keyframes Latent", Keywords = "Twinverse Session Request Keyframes Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllKeyframesLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseKeyframe> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Keyframes For Moment", Keywords = "Twinverse Session Request Keyframes"), Category = "DTNativeClientTwinverse|Session")
	void RequestKeyframesForMoment(const FDTNativeClientCoreUUID &MomentID, FDTNativeClientTwinverseKeyframeListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Keyframes For Moment Latent", Keywords = "Twinverse Session Request Keyframes Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestKeyframesForMomentLatent(
		const FDTNativeClientCoreUUID &MomentID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseKeyframe> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Keyframes For Scene", Keywords = "Twinverse Session Request Keyframes"), Category = "DTNativeClientTwinverse|Session")
	void RequestKeyframesForScene(const FDTNativeClientCoreUUID &SceneID, FDTNativeClientTwinverseKeyframeListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Keyframes For Scene Latent", Keywords = "Twinverse Session Request Keyframes Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestKeyframesForSceneLatent(
		const FDTNativeClientCoreUUID &SceneID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseKeyframe> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Keyframes For Twinstance", Keywords = "Twinverse Session Request Keyframes"), Category = "DTNativeClientTwinverse|Session")
	void RequestKeyframesForTwinstance(const FDTNativeClientCoreUUID &TwinstanceID, FDTNativeClientTwinverseKeyframeListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Keyframes For Twinstance Latent", Keywords = "Twinverse Session Request Keyframes Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestKeyframesForTwinstanceLatent(
		const FDTNativeClientCoreUUID &TwinstanceID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseKeyframe> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseKeyframeListEvent OnKeyframesCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseKeyframeListEvent OnKeyframesRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseKeyframeListEvent OnKeyframesPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Scenes", Keywords = "Twinverse Session Request Scenes"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllScenes(FDTNativeClientTwinverseSceneListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Scenes Latent", Keywords = "Twinverse Session Request Scenes Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllScenesLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseScene> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Scenes For Moment", Keywords = "Twinverse Session Request Scenes"), Category = "DTNativeClientTwinverse|Session")
	void RequestScenesForMoment(const FDTNativeClientCoreUUID &MomentID, FDTNativeClientTwinverseSceneListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Scenes For Moment Latent", Keywords = "Twinverse Session Request Scenes Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestScenesForMomentLatent(
		const FDTNativeClientCoreUUID &MomentID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseScene> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseSceneListEvent OnScenesCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseSceneListEvent OnScenesRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseSceneListEvent OnScenesPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Twinstances", Keywords = "Twinverse Session Request Twinstances"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllTwinstances(FDTNativeClientTwinverseTwinstanceListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Twinstances Latent", Keywords = "Twinverse Session Request Twinstances Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllTwinstancesLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinstance> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinstances For Moment", Keywords = "Twinverse Session Request Twinstances"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinstancesForMoment(const FDTNativeClientCoreUUID &MomentID, FDTNativeClientTwinverseTwinstanceListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinstances For Moment Latent", Keywords = "Twinverse Session Request Twinstances Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinstancesForMomentLatent(
		const FDTNativeClientCoreUUID &MomentID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinstance> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinstances For Scene", Keywords = "Twinverse Session Request Twinstances"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinstancesForScene(const FDTNativeClientCoreUUID &SceneID, FDTNativeClientTwinverseTwinstanceListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinstances For Scene Latent", Keywords = "Twinverse Session Request Twinstances Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinstancesForSceneLatent(
		const FDTNativeClientCoreUUID &SceneID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinstance> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinstances For Experience", Keywords = "Twinverse Session Request Twinstances"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinstancesForExperience(const FDTNativeClientCoreUUID &ExperienceID, FDTNativeClientTwinverseTwinstanceListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinstances For Experience Latent", Keywords = "Twinverse Session Request Twinstances Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinstancesForExperienceLatent(
		const FDTNativeClientCoreUUID &ExperienceID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinstance> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseTwinstanceListEvent OnTwinstancesCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseTwinstanceListEvent OnTwinstancesRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseTwinstanceListEvent OnTwinstancesPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Layouts", Keywords = "Twinverse Session Request Layouts"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllLayouts(FDTNativeClientTwinverseLayoutListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Layouts Latent", Keywords = "Twinverse Session Request Layouts Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllLayoutsLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseLayout> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseLayoutListEvent OnLayoutsCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseLayoutListEvent OnLayoutsRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseLayoutListEvent OnLayoutsPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Regions", Keywords = "Twinverse Session Request Regions"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllRegions(FDTNativeClientTwinverseRegionListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Regions Latent", Keywords = "Twinverse Session Request Regions Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllRegionsLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseRegion> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseRegionListEvent OnRegionsCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseRegionListEvent OnRegionsRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseRegionListEvent OnRegionsPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Mediaobjects", Keywords = "Twinverse Session Request Mediaobjects"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllMediaobjects(FDTNativeClientTwinverseMediaobjectListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Mediaobjects Latent", Keywords = "Twinverse Session Request Mediaobjects Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllMediaobjectsLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseMediaobject> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseMediaobjectListEvent OnMediaobjectsCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseMediaobjectListEvent OnMediaobjectsRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseMediaobjectListEvent OnMediaobjectsPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Twinobjects", Keywords = "Twinverse Session Request Twinobjects"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllTwinobjects(FDTNativeClientTwinverseTwinobjectListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Twinobjects Latent", Keywords = "Twinverse Session Request Twinobjects Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllTwinobjectsLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinobject> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinobjects For Experience", Keywords = "Twinverse Session Request Twinobjects"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinobjectsForExperience(const FDTNativeClientCoreUUID &ExperienceID, FDTNativeClientTwinverseTwinobjectListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinobjects For Experience Latent", Keywords = "Twinverse Session Request Twinobjects Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinobjectsForExperienceLatent(
		const FDTNativeClientCoreUUID &ExperienceID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinobject> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseTwinobjectListEvent OnTwinobjectsCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseTwinobjectListEvent OnTwinobjectsRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseTwinobjectListEvent OnTwinobjectsPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Mediaobject Assets", Keywords = "Twinverse Session Request Mediaobject Assets"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllMediaobjectAssets(FDTNativeClientTwinverseMediaobjectAssetListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Mediaobject Assets Latent", Keywords = "Twinverse Session Request Mediaobject Assets Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllMediaobjectAssetsLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseMediaobjectAsset> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseMediaobjectAssetListEvent OnMediaobjectAssetsCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseMediaobjectAssetListEvent OnMediaobjectAssetsRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseMediaobjectAssetListEvent OnMediaobjectAssetsPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Twinobject Assets", Keywords = "Twinverse Session Request Twinobject Assets"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllTwinobjectAssets(FDTNativeClientTwinverseTwinobjectAssetListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Twinobject Assets Latent", Keywords = "Twinverse Session Request Twinobject Assets Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllTwinobjectAssetsLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinobjectAsset> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinobject Assets For Experience", Keywords = "Twinverse Session Request Twinobject Assets"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinobjectAssetsForExperience(const FDTNativeClientCoreUUID &ExperienceID, FDTNativeClientTwinverseTwinobjectAssetListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinobject Assets For Experience Latent", Keywords = "Twinverse Session Request Twinobject Assets Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinobjectAssetsForExperienceLatent(
		const FDTNativeClientCoreUUID &ExperienceID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinobjectAsset> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinobject Assets For Moment", Keywords = "Twinverse Session Request Twinobject Assets"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinobjectAssetsForMoment(const FDTNativeClientCoreUUID &MomentID, FDTNativeClientTwinverseTwinobjectAssetListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinobject Assets For Moment Latent", Keywords = "Twinverse Session Request Twinobject Assets Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinobjectAssetsForMomentLatent(
		const FDTNativeClientCoreUUID &MomentID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinobjectAsset> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinobject Assets For Scene", Keywords = "Twinverse Session Request Twinobject Assets"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinobjectAssetsForScene(const FDTNativeClientCoreUUID &SceneID, FDTNativeClientTwinverseTwinobjectAssetListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinobject Assets For Scene Latent", Keywords = "Twinverse Session Request Twinobject Assets Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinobjectAssetsForSceneLatent(
		const FDTNativeClientCoreUUID &SceneID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinobjectAsset> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinobject Assets For Twinstance", Keywords = "Twinverse Session Request Twinobject Assets"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinobjectAssetsForTwinstance(const FDTNativeClientCoreUUID &TwinstanceID, FDTNativeClientTwinverseTwinobjectAssetListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Twinobject Assets For Twinstance Latent", Keywords = "Twinverse Session Request Twinobject Assets Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestTwinobjectAssetsForTwinstanceLatent(
		const FDTNativeClientCoreUUID &TwinstanceID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseTwinobjectAsset> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseTwinobjectAssetListEvent OnTwinobjectAssetsCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseTwinobjectAssetListEvent OnTwinobjectAssetsRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseTwinobjectAssetListEvent OnTwinobjectAssetsPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Assets", Keywords = "Twinverse Session Request Assets"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllAssets(FDTNativeClientTwinverseAssetListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Assets Latent", Keywords = "Twinverse Session Request Assets Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllAssetsLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseAsset> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Assets For Twinobject", Keywords = "Twinverse Session Request Assets"), Category = "DTNativeClientTwinverse|Session")
	void RequestAssetsForTwinobject(const FDTNativeClientCoreUUID &TwinobjectID, FDTNativeClientTwinverseAssetListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Assets For Twinobject Latent", Keywords = "Twinverse Session Request Assets Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAssetsForTwinobjectLatent(
		const FDTNativeClientCoreUUID &TwinobjectID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseAsset> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseAssetListEvent OnAssetsCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseAssetListEvent OnAssetsRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseAssetListEvent OnAssetsPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Object Services", Keywords = "Twinverse Session Request Object Services"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllObjectServices(FDTNativeClientTwinverseObjectServiceListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Object Services Latent", Keywords = "Twinverse Session Request Object Services Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllObjectServicesLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseObjectService> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseObjectServiceListEvent OnObjectServicesCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseObjectServiceListEvent OnObjectServicesRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseObjectServiceListEvent OnObjectServicesPatched;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Files", Keywords = "Twinverse Session Request Files"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllFiles(FDTNativeClientTwinverseFileListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request All Files Latent", Keywords = "Twinverse Session Request Files Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestAllFilesLatent(
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseFile> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Files For Twinobject", Keywords = "Twinverse Session Request Files"), Category = "DTNativeClientTwinverse|Session")
	void RequestFilesForTwinobject(const FDTNativeClientCoreUUID &TwinobjectID, FDTNativeClientTwinverseFileListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Files For Twinobject Latent", Keywords = "Twinverse Session Request Files Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestFilesForTwinobjectLatent(
		const FDTNativeClientCoreUUID &TwinobjectID,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseFile> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Files For Assets", Keywords = "Twinverse Session Request Files"), Category = "DTNativeClientTwinverse|Session")
	void RequestFilesForAssets(const TArray<FDTNativeClientCoreUUID> &AssetIDs, FDTNativeClientTwinverseFileListCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Files For Assets Latent", Keywords = "Twinverse Session Request Files Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientTwinverse|Session")
	void RequestFilesForAssetsLatent(
		const TArray<FDTNativeClientCoreUUID> &AssetIDs,
		UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
		TArray<FDTNativeClientTwinverseFile> &Result, int &Status
	);

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseFileListEvent OnFilesCreated;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseFileListEvent OnFilesRemoved;

	UPROPERTY(BlueprintAssignable, Category = "DTNativeClientTwinverse|Session")
	FDTNativeClientTwinverseFileListEvent OnFilesPatched;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};
