#include "DTNativeClientTwinverseSession.h"
#include "DTNativeClientCoreTransportData.h"
#include "LatentActions.h"

/*
 */
static void OnRequestAll(DTNACL_Core_Session Session, const DTNACL_Core_TransportData *Responses, uint64_t NumResponses, DTNACL_Core_Status Status, void *UserData)
{
	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreRequestCallback>;
	Action *Context = reinterpret_cast<Action *>(UserData);
	check(Context != nullptr);

	int CallbackStatus = static_cast<int>(Status);

	TArray<UDTNativeClientCoreTransportData *> CallbackResponses;
	CallbackResponses.Reserve(NumResponses);
	for (uint64_t i = 0; i < NumResponses; ++i)
	{
		DTNACL_Core_TransportData Response = Responses[i];
		UDTNativeClientCoreTransportData *CallbackResponse = UDTNativeClientCoreTransportData::CreateFromNativeHandle(Response);
		CallbackResponses.Add(CallbackResponse);
	}

	Context->Callback.ExecuteIfBound(CallbackResponses, CallbackStatus);
	delete Context;
}

static void OnRequestAllLatent(DTNACL_Core_Session Session, const DTNACL_Core_TransportData *Responses, uint64_t NumResponses, DTNACL_Core_Status Status, void *UserData)
{
	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientCoreLatentExec *, TArray<UDTNativeClientCoreTransportData *> *, int *>;
	LatentAction *Context = reinterpret_cast<LatentAction *>(UserData);
	check(Context != nullptr);

	int CallbackStatus = static_cast<int>(Status);

	TArray<UDTNativeClientCoreTransportData *> CallbackResponses;
	CallbackResponses.Reserve(NumResponses);
	for (uint64_t i = 0; i < NumResponses; ++i)
	{
		DTNACL_Core_TransportData Response = Responses[i];
		UDTNativeClientCoreTransportData *CallbackResponse = UDTNativeClientCoreTransportData::CreateFromNativeHandle(Response);
		CallbackResponses.Add(CallbackResponse);
	}

	EDTNativeClientCoreLatentExec LatentExec = EDTNativeClientCoreLatentExec::OnSuccess;
	if (CallbackStatus != DTNACL_CORE_STATUS_OK)
		LatentExec = EDTNativeClientCoreLatentExec::OnFail;

	*(Context->GetParameters().Get<0>()) = LatentExec;
	*(Context->GetParameters().Get<1>()) = MoveTemp(CallbackResponses);
	*(Context->GetParameters().Get<2>()) = CallbackStatus;

	Context->CallAndFinish();
}

/*
 */
template<typename TNativeData, typename TData, typename TCallback>
static void OnEntriesReceived(DTNACL_Core_Session Session, const TNativeData *Entries, uint64_t NumEntries, DTNACL_Core_Status Status, void *UserData)
{
	using Action = FDTNativeClientCoreCallingContext<TCallback>;
	Action *Context = reinterpret_cast<Action *>(UserData);
	check(Context != nullptr);

	int CallbackStatus = static_cast<int>(Status);

	TArray<TData> CallbackData;
	CallbackData.Reserve(NumEntries);
	for (uint64_t i = 0; i < NumEntries; ++i)
	{
		const TData &Data = TData::FromNative(Entries[i]);
		CallbackData.Add(Data);
	}

	UE_LOG(LogDTNativeClientTwinverse, Log, TEXT("Calling OnEntriesReceived callback with status %d"), static_cast<int>(CallbackStatus));
	Context->Callback.ExecuteIfBound(CallbackData, CallbackStatus);
}

template<typename TNativeData, typename TData>
static void OnEntriesReceivedLatent(DTNACL_Core_Session Session, const TNativeData *Entries, uint64_t NumEntries, DTNACL_Core_Status Status, void *UserData)
{
	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<TData> *, int *>;
	LatentAction *Context = reinterpret_cast<LatentAction *>(UserData);
	check(Context != nullptr);

	int CallbackStatus = static_cast<int>(Status);

	TArray<TData> CallbackData;
	CallbackData.Reserve(NumEntries);
	for (uint64_t i = 0; i < NumEntries; ++i)
	{
		const TData &Data = TData::FromNative(Entries[i]);
		CallbackData.Add(Data);
	}

	EDTNativeClientTwinverseLatentExec LatentExec = EDTNativeClientTwinverseLatentExec::OnFinished;
	
	*(Context->GetParameters().Get<0>()) = LatentExec;
	*(Context->GetParameters().Get<1>()) = MoveTemp(CallbackData);
	*(Context->GetParameters().Get<2>()) = CallbackStatus;

	Context->CallAndFinish();
}

/*
 */
template<typename TNativeData, typename TData, typename TCallback>
static void OnListenerEvent(DTNACL_Core_Session Session, const TNativeData *Entries, uint64_t NumEntries, void *UserData)
{
	TCallback *Callback = reinterpret_cast<TCallback *>(UserData);
	check(Callback != nullptr);

	TArray<TData> CallbackData;
	CallbackData.Reserve(NumEntries);
	for (uint64_t i = 0; i < NumEntries; ++i)
	{
		const TData &Data = TData::FromNative(Entries[i]);
		CallbackData.Add(Data);
	}

	UE_LOG(LogDTNativeClientTwinverse, Log, TEXT("Calling ListenerEvent callback"));
	Callback->Broadcast(CallbackData);
}

/*
 */
UDTNativeClientTwinverseSession::UDTNativeClientTwinverseSession()
	: UDTNativeClientCoreSession()
{
}

void UDTNativeClientTwinverseSession::AddListeners()
{
	check(Session != DTNACL_NULL_HANDLE);

	DTNACL_Twinverse_ArchetypeEventCallback ArchetypeEvent = OnListenerEvent<DTNACL_Twinverse_Archetype, FDTNativeClientTwinverseArchetype, FDTNativeClientTwinverseArchetypeListEvent>;

	dtnaclTwinverseAddListenerArchetypesCreated(Session, ArchetypeEvent, &OnArchetypesCreated);
	dtnaclTwinverseAddListenerArchetypesRemoved(Session, ArchetypeEvent, &OnArchetypesRemoved);
	dtnaclTwinverseAddListenerArchetypesPatched(Session, ArchetypeEvent, &OnArchetypesPatched);

	DTNACL_Twinverse_ExperienceEventCallback ExperienceEvent = OnListenerEvent<DTNACL_Twinverse_Experience, FDTNativeClientTwinverseExperience, FDTNativeClientTwinverseExperienceListEvent>;

	dtnaclTwinverseAddListenerExperiencesCreated(Session, ExperienceEvent, &OnExperiencesCreated);
	dtnaclTwinverseAddListenerExperiencesRemoved(Session, ExperienceEvent, &OnExperiencesRemoved);
	dtnaclTwinverseAddListenerExperiencesPatched(Session, ExperienceEvent, &OnExperiencesPatched);

	DTNACL_Twinverse_MomentEventCallback MomentEvent = OnListenerEvent<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment, FDTNativeClientTwinverseMomentListEvent>;

	dtnaclTwinverseAddListenerMomentsCreated(Session, MomentEvent, &OnMomentsCreated);
	dtnaclTwinverseAddListenerMomentsRemoved(Session, MomentEvent, &OnMomentsRemoved);
	dtnaclTwinverseAddListenerMomentsPatched(Session, MomentEvent, &OnMomentsPatched);

	DTNACL_Twinverse_KeyframeEventCallback KeyframeEvent = OnListenerEvent<DTNACL_Twinverse_Keyframe, FDTNativeClientTwinverseKeyframe, FDTNativeClientTwinverseKeyframeListEvent>;

	dtnaclTwinverseAddListenerKeyframesCreated(Session, KeyframeEvent, &OnKeyframesCreated);
	dtnaclTwinverseAddListenerKeyframesRemoved(Session, KeyframeEvent, &OnKeyframesRemoved);
	dtnaclTwinverseAddListenerKeyframesPatched(Session, KeyframeEvent, &OnKeyframesPatched);

	DTNACL_Twinverse_SceneEventCallback SceneEvent = OnListenerEvent<DTNACL_Twinverse_Scene, FDTNativeClientTwinverseScene, FDTNativeClientTwinverseSceneListEvent>;

	dtnaclTwinverseAddListenerScenesCreated(Session, SceneEvent, &OnScenesCreated);
	dtnaclTwinverseAddListenerScenesRemoved(Session, SceneEvent, &OnScenesRemoved);
	dtnaclTwinverseAddListenerScenesPatched(Session, SceneEvent, &OnScenesPatched);

	DTNACL_Twinverse_TwinstanceEventCallback TwinstanceEvent = OnListenerEvent<DTNACL_Twinverse_Twinstance, FDTNativeClientTwinverseTwinstance, FDTNativeClientTwinverseTwinstanceListEvent>;

	dtnaclTwinverseAddListenerTwinstancesCreated(Session, TwinstanceEvent, &OnTwinstancesCreated);
	dtnaclTwinverseAddListenerTwinstancesRemoved(Session, TwinstanceEvent, &OnTwinstancesRemoved);
	dtnaclTwinverseAddListenerTwinstancesPatched(Session, TwinstanceEvent, &OnTwinstancesPatched);

	DTNACL_Twinverse_LayoutEventCallback LayoutEvent = OnListenerEvent<DTNACL_Twinverse_Layout, FDTNativeClientTwinverseLayout, FDTNativeClientTwinverseLayoutListEvent>;

	dtnaclTwinverseAddListenerLayoutsCreated(Session, LayoutEvent, &OnLayoutsCreated);
	dtnaclTwinverseAddListenerLayoutsRemoved(Session, LayoutEvent, &OnLayoutsRemoved);
	dtnaclTwinverseAddListenerLayoutsPatched(Session, LayoutEvent, &OnLayoutsPatched);

	DTNACL_Twinverse_RegionEventCallback RegionEvent = OnListenerEvent<DTNACL_Twinverse_Region, FDTNativeClientTwinverseRegion, FDTNativeClientTwinverseRegionListEvent>;

	dtnaclTwinverseAddListenerRegionsCreated(Session, RegionEvent, &OnRegionsCreated);
	dtnaclTwinverseAddListenerRegionsRemoved(Session, RegionEvent, &OnRegionsRemoved);
	dtnaclTwinverseAddListenerRegionsPatched(Session, RegionEvent, &OnRegionsPatched);

	DTNACL_Twinverse_MediaobjectEventCallback MediaobjectEvent = OnListenerEvent<DTNACL_Twinverse_Mediaobject, FDTNativeClientTwinverseMediaobject, FDTNativeClientTwinverseMediaobjectListEvent>;

	dtnaclTwinverseAddListenerMediaobjectsCreated(Session, MediaobjectEvent, &OnMediaobjectsCreated);
	dtnaclTwinverseAddListenerMediaobjectsRemoved(Session, MediaobjectEvent, &OnMediaobjectsRemoved);
	dtnaclTwinverseAddListenerMediaobjectsPatched(Session, MediaobjectEvent, &OnMediaobjectsPatched);

	DTNACL_Twinverse_TwinobjectEventCallback TwinobjectEvent = OnListenerEvent<DTNACL_Twinverse_Twinobject, FDTNativeClientTwinverseTwinobject, FDTNativeClientTwinverseTwinobjectListEvent>;

	dtnaclTwinverseAddListenerTwinobjectsCreated(Session, TwinobjectEvent, &OnTwinobjectsCreated);
	dtnaclTwinverseAddListenerTwinobjectsRemoved(Session, TwinobjectEvent, &OnTwinobjectsRemoved);
	dtnaclTwinverseAddListenerTwinobjectsPatched(Session, TwinobjectEvent, &OnTwinobjectsPatched);

	DTNACL_Twinverse_MediaobjectAssetEventCallback MediaobjectAssetEvent = OnListenerEvent<DTNACL_Twinverse_MediaobjectAsset, FDTNativeClientTwinverseMediaobjectAsset, FDTNativeClientTwinverseMediaobjectAssetListEvent>;

	dtnaclTwinverseAddListenerMediaobjectAssetsCreated(Session, MediaobjectAssetEvent, &OnMediaobjectAssetsCreated);
	dtnaclTwinverseAddListenerMediaobjectAssetsRemoved(Session, MediaobjectAssetEvent, &OnMediaobjectAssetsRemoved);
	dtnaclTwinverseAddListenerMediaobjectAssetsPatched(Session, MediaobjectAssetEvent, &OnMediaobjectAssetsPatched);

	DTNACL_Twinverse_TwinobjectAssetEventCallback TwinobjectAssetEvent = OnListenerEvent<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset, FDTNativeClientTwinverseTwinobjectAssetListEvent>;

	dtnaclTwinverseAddListenerTwinobjectAssetsCreated(Session, TwinobjectAssetEvent, &OnTwinobjectAssetsCreated);
	dtnaclTwinverseAddListenerTwinobjectAssetsRemoved(Session, TwinobjectAssetEvent, &OnTwinobjectAssetsRemoved);
	dtnaclTwinverseAddListenerTwinobjectAssetsPatched(Session, TwinobjectAssetEvent, &OnTwinobjectAssetsPatched);

	DTNACL_Twinverse_AssetEventCallback AssetEvent = OnListenerEvent<DTNACL_Twinverse_Asset, FDTNativeClientTwinverseAsset, FDTNativeClientTwinverseAssetListEvent>;

	dtnaclTwinverseAddListenerAssetsCreated(Session, AssetEvent, &OnAssetsCreated);
	dtnaclTwinverseAddListenerAssetsRemoved(Session, AssetEvent, &OnAssetsRemoved);
	dtnaclTwinverseAddListenerAssetsPatched(Session, AssetEvent, &OnAssetsPatched);

	DTNACL_Twinverse_ObjectServiceEventCallback ObjectServiceEvent = OnListenerEvent<DTNACL_Twinverse_ObjectService, FDTNativeClientTwinverseObjectService, FDTNativeClientTwinverseObjectServiceListEvent>;

	dtnaclTwinverseAddListenerObjectServicesCreated(Session, ObjectServiceEvent, &OnObjectServicesCreated);
	dtnaclTwinverseAddListenerObjectServicesRemoved(Session, ObjectServiceEvent, &OnObjectServicesRemoved);
	dtnaclTwinverseAddListenerObjectServicesPatched(Session, ObjectServiceEvent, &OnObjectServicesPatched);

	DTNACL_Twinverse_FileEventCallback FileEvent = OnListenerEvent<DTNACL_Twinverse_File, FDTNativeClientTwinverseFile, FDTNativeClientTwinverseFileListEvent>;

	dtnaclTwinverseAddListenerFilesCreated(Session, FileEvent, &OnFilesCreated);
	dtnaclTwinverseAddListenerFilesRemoved(Session, FileEvent, &OnFilesRemoved);
	dtnaclTwinverseAddListenerFilesPatched(Session, FileEvent, &OnFilesPatched);
}

void UDTNativeClientTwinverseSession::RemoveListeners()
{
	check(Session != DTNACL_NULL_HANDLE);

	dtnaclTwinverseRemoveListenerArchetypesCreated(Session);
	dtnaclTwinverseRemoveListenerArchetypesRemoved(Session);
	dtnaclTwinverseRemoveListenerArchetypesPatched(Session);

	dtnaclTwinverseRemoveListenerExperiencesCreated(Session);
	dtnaclTwinverseRemoveListenerExperiencesRemoved(Session);
	dtnaclTwinverseRemoveListenerExperiencesPatched(Session);

	dtnaclTwinverseRemoveListenerMomentsCreated(Session);
	dtnaclTwinverseRemoveListenerMomentsRemoved(Session);
	dtnaclTwinverseRemoveListenerMomentsPatched(Session);

	dtnaclTwinverseRemoveListenerKeyframesCreated(Session);
	dtnaclTwinverseRemoveListenerKeyframesRemoved(Session);
	dtnaclTwinverseRemoveListenerKeyframesPatched(Session);

	dtnaclTwinverseRemoveListenerScenesCreated(Session);
	dtnaclTwinverseRemoveListenerScenesRemoved(Session);
	dtnaclTwinverseRemoveListenerScenesPatched(Session);

	dtnaclTwinverseRemoveListenerTwinstancesCreated(Session);
	dtnaclTwinverseRemoveListenerTwinstancesRemoved(Session);
	dtnaclTwinverseRemoveListenerTwinstancesPatched(Session);

	dtnaclTwinverseRemoveListenerLayoutsCreated(Session);
	dtnaclTwinverseRemoveListenerLayoutsRemoved(Session);
	dtnaclTwinverseRemoveListenerLayoutsPatched(Session);

	dtnaclTwinverseRemoveListenerRegionsCreated(Session);
	dtnaclTwinverseRemoveListenerRegionsRemoved(Session);
	dtnaclTwinverseRemoveListenerRegionsPatched(Session);

	dtnaclTwinverseRemoveListenerMediaobjectsCreated(Session);
	dtnaclTwinverseRemoveListenerMediaobjectsRemoved(Session);
	dtnaclTwinverseRemoveListenerMediaobjectsPatched(Session);

	dtnaclTwinverseRemoveListenerTwinobjectsCreated(Session);
	dtnaclTwinverseRemoveListenerTwinobjectsRemoved(Session);
	dtnaclTwinverseRemoveListenerTwinobjectsPatched(Session);

	dtnaclTwinverseRemoveListenerMediaobjectAssetsCreated(Session);
	dtnaclTwinverseRemoveListenerMediaobjectAssetsRemoved(Session);
	dtnaclTwinverseRemoveListenerMediaobjectAssetsPatched(Session);

	dtnaclTwinverseRemoveListenerTwinobjectAssetsCreated(Session);
	dtnaclTwinverseRemoveListenerTwinobjectAssetsRemoved(Session);
	dtnaclTwinverseRemoveListenerTwinobjectAssetsPatched(Session);

	dtnaclTwinverseRemoveListenerAssetsCreated(Session);
	dtnaclTwinverseRemoveListenerAssetsRemoved(Session);
	dtnaclTwinverseRemoveListenerAssetsPatched(Session);

	dtnaclTwinverseRemoveListenerObjectServicesCreated(Session);
	dtnaclTwinverseRemoveListenerObjectServicesRemoved(Session);
	dtnaclTwinverseRemoveListenerObjectServicesPatched(Session);

	dtnaclTwinverseRemoveListenerFilesCreated(Session);
	dtnaclTwinverseRemoveListenerFilesRemoved(Session);
	dtnaclTwinverseRemoveListenerFilesPatched(Session);
}

void UDTNativeClientTwinverseSession::BeginPlay()
{
	Super::BeginPlay();
	AddListeners();
}

void UDTNativeClientTwinverseSession::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	RemoveListeners();
	Super::EndPlay(EndPlayReason);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAll(
	const FString &Service, const TArray<UDTNativeClientCoreTransportData *> &Parameters,
	FDTNativeClientCoreRequestCallback Callback
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreRequestCallback>;
	Action *Context = new Action(Callback);

	TArray<DTNACL_Core_TransportData> NativeParameters;
	NativeParameters.Reserve(Parameters.Num());
	for (auto Parameter : Parameters)
	{
		check(Parameter != nullptr);
		NativeParameters.Add(Parameter->GetNativeHandle());
	}

	dtnaclTwinverseRequestAll(Session, TCHAR_TO_UTF8(*Service), NativeParameters.GetData(), NativeParameters.Num(), OnRequestAll, Context);
}

void UDTNativeClientTwinverseSession::RequestAllLatent(
	UObject *WorldContext, const FString &Service, const TArray<UDTNativeClientCoreTransportData *> &Parameters,
	FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
	TArray<UDTNativeClientCoreTransportData *> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientCoreLatentExec *, TArray<UDTNativeClientCoreTransportData *> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	TArray<DTNACL_Core_TransportData> NativeParameters;
	NativeParameters.Reserve(Parameters.Num());
	for (auto Parameter : Parameters)
	{
		check(Parameter != nullptr);
		NativeParameters.Add(Parameter->GetNativeHandle());
	}

	dtnaclTwinverseRequestAll(Session, TCHAR_TO_UTF8(*Service), NativeParameters.GetData(), NativeParameters.Num(), OnRequestAllLatent, Context);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllArchetypes(FDTNativeClientTwinverseArchetypeListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseArchetypeListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllArchetypes(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Archetype, FDTNativeClientTwinverseArchetype, FDTNativeClientTwinverseArchetypeListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllArchetypesLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseArchetype> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseArchetype> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllArchetypes(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Archetype, FDTNativeClientTwinverseArchetype>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllExperiences(FDTNativeClientTwinverseExperienceListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseExperienceListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllExperiences(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Experience, FDTNativeClientTwinverseExperience, FDTNativeClientTwinverseExperienceListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllExperiencesLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseExperience> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseExperience> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllExperiences(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Experience, FDTNativeClientTwinverseExperience>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllMoments(FDTNativeClientTwinverseMomentListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseMomentListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllMoments(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment, FDTNativeClientTwinverseMomentListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllMomentsLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseMoment> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseMoment> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllMoments(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestMomentsForExperience(const FDTNativeClientCoreUUID &ExperienceID, FDTNativeClientTwinverseMomentListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseMomentListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestMomentsForExperience(
		Session,
		ExperienceID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment, FDTNativeClientTwinverseMomentListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestMomentsForExperienceLatent(
	const FDTNativeClientCoreUUID &ExperienceID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseMoment> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseMoment> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestMomentsForExperience(
		Session,
		ExperienceID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestMomentsForScene(const FDTNativeClientCoreUUID &SceneID, FDTNativeClientTwinverseMomentListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseMomentListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestMomentsForScene(
		Session,
		SceneID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment, FDTNativeClientTwinverseMomentListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestMomentsForSceneLatent(
	const FDTNativeClientCoreUUID &SceneID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseMoment> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseMoment> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestMomentsForScene(
		Session,
		SceneID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestMomentsForTwinstance(const FDTNativeClientCoreUUID &TwinstanceID, FDTNativeClientTwinverseMomentListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseMomentListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestMomentsForTwinstance(
		Session,
		TwinstanceID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment, FDTNativeClientTwinverseMomentListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestMomentsForTwinstanceLatent(
	const FDTNativeClientCoreUUID &TwinstanceID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseMoment> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseMoment> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestMomentsForTwinstance(
		Session,
		TwinstanceID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestMomentsForLayout(const FDTNativeClientCoreUUID &LayoutID, FDTNativeClientTwinverseMomentListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseMomentListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestMomentsForLayout(
		Session,
		LayoutID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment, FDTNativeClientTwinverseMomentListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestMomentsForLayoutLatent(
	const FDTNativeClientCoreUUID &LayoutID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseMoment> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseMoment> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestMomentsForLayout(
		Session,
		LayoutID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Moment, FDTNativeClientTwinverseMoment>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllKeyframes(FDTNativeClientTwinverseKeyframeListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseKeyframeListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllKeyframes(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Keyframe, FDTNativeClientTwinverseKeyframe, FDTNativeClientTwinverseKeyframeListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllKeyframesLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseKeyframe> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseKeyframe> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllKeyframes(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Keyframe, FDTNativeClientTwinverseKeyframe>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestKeyframesForMoment(const FDTNativeClientCoreUUID &MomentID, FDTNativeClientTwinverseKeyframeListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseKeyframeListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestKeyframesForMoment(
		Session,
		MomentID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Keyframe, FDTNativeClientTwinverseKeyframe, FDTNativeClientTwinverseKeyframeListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestKeyframesForMomentLatent(
	const FDTNativeClientCoreUUID &MomentID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseKeyframe> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseKeyframe> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestKeyframesForMoment(
		Session,
		MomentID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Keyframe, FDTNativeClientTwinverseKeyframe>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestKeyframesForScene(const FDTNativeClientCoreUUID &SceneID, FDTNativeClientTwinverseKeyframeListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseKeyframeListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestKeyframesForScene(
		Session,
		SceneID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Keyframe, FDTNativeClientTwinverseKeyframe, FDTNativeClientTwinverseKeyframeListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestKeyframesForSceneLatent(
	const FDTNativeClientCoreUUID &SceneID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseKeyframe> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseKeyframe> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestKeyframesForScene(
		Session,
		SceneID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Keyframe, FDTNativeClientTwinverseKeyframe>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestKeyframesForTwinstance(const FDTNativeClientCoreUUID &TwinstanceID, FDTNativeClientTwinverseKeyframeListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseKeyframeListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestKeyframesForTwinstance(
		Session,
		TwinstanceID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Keyframe, FDTNativeClientTwinverseKeyframe, FDTNativeClientTwinverseKeyframeListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestKeyframesForTwinstanceLatent(
	const FDTNativeClientCoreUUID &TwinstanceID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseKeyframe> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseKeyframe> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestKeyframesForTwinstance(
		Session,
		TwinstanceID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Keyframe, FDTNativeClientTwinverseKeyframe>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllScenes(FDTNativeClientTwinverseSceneListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseSceneListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllScenes(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Scene, FDTNativeClientTwinverseScene, FDTNativeClientTwinverseSceneListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllScenesLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseScene> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseScene> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllScenes(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Scene, FDTNativeClientTwinverseScene>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestScenesForMoment(const FDTNativeClientCoreUUID &MomentID, FDTNativeClientTwinverseSceneListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseSceneListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestScenesForMoment(
		Session,
		MomentID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Scene, FDTNativeClientTwinverseScene, FDTNativeClientTwinverseSceneListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestScenesForMomentLatent(
	const FDTNativeClientCoreUUID &MomentID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseScene> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseScene> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestScenesForMoment(
		Session,
		MomentID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Scene, FDTNativeClientTwinverseScene>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllTwinstances(FDTNativeClientTwinverseTwinstanceListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinstanceListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllTwinstances(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Twinstance, FDTNativeClientTwinverseTwinstance, FDTNativeClientTwinverseTwinstanceListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllTwinstancesLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinstance> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinstance> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllTwinstances(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Twinstance, FDTNativeClientTwinverseTwinstance>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestTwinstancesForMoment(const FDTNativeClientCoreUUID &MomentID, FDTNativeClientTwinverseTwinstanceListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinstanceListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestTwinstancesForMoment(
		Session,
		MomentID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Twinstance, FDTNativeClientTwinverseTwinstance, FDTNativeClientTwinverseTwinstanceListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestTwinstancesForMomentLatent(
	const FDTNativeClientCoreUUID &MomentID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinstance> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinstance> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestTwinstancesForMoment(
		Session,
		MomentID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Twinstance, FDTNativeClientTwinverseTwinstance>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestTwinstancesForScene(const FDTNativeClientCoreUUID &SceneID, FDTNativeClientTwinverseTwinstanceListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinstanceListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestTwinstancesForScene(
		Session,
		SceneID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Twinstance, FDTNativeClientTwinverseTwinstance, FDTNativeClientTwinverseTwinstanceListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestTwinstancesForSceneLatent(
	const FDTNativeClientCoreUUID &SceneID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinstance> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinstance> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestTwinstancesForScene(
		Session,
		SceneID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Twinstance, FDTNativeClientTwinverseTwinstance>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestTwinstancesForExperience(const FDTNativeClientCoreUUID &ExperienceID, FDTNativeClientTwinverseTwinstanceListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinstanceListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestTwinstancesForExperience(
		Session,
		ExperienceID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Twinstance, FDTNativeClientTwinverseTwinstance, FDTNativeClientTwinverseTwinstanceListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestTwinstancesForExperienceLatent(
	const FDTNativeClientCoreUUID &ExperienceID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinstance> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinstance> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestTwinstancesForExperience(
		Session,
		ExperienceID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Twinstance, FDTNativeClientTwinverseTwinstance>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllLayouts(FDTNativeClientTwinverseLayoutListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseLayoutListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllLayouts(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Layout, FDTNativeClientTwinverseLayout, FDTNativeClientTwinverseLayoutListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllLayoutsLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseLayout> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseLayout> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllLayouts(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Layout, FDTNativeClientTwinverseLayout>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllRegions(FDTNativeClientTwinverseRegionListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseRegionListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllRegions(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Region, FDTNativeClientTwinverseRegion, FDTNativeClientTwinverseRegionListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllRegionsLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseRegion> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseRegion> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllRegions(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Region, FDTNativeClientTwinverseRegion>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllMediaobjects(FDTNativeClientTwinverseMediaobjectListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseMediaobjectListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllMediaobjects(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Mediaobject, FDTNativeClientTwinverseMediaobject, FDTNativeClientTwinverseMediaobjectListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllMediaobjectsLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseMediaobject> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseMediaobject> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllMediaobjects(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Mediaobject, FDTNativeClientTwinverseMediaobject>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllTwinobjects(FDTNativeClientTwinverseTwinobjectListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinobjectListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllTwinobjects(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Twinobject, FDTNativeClientTwinverseTwinobject, FDTNativeClientTwinverseTwinobjectListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllTwinobjectsLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinobject> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinobject> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllTwinobjects(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Twinobject, FDTNativeClientTwinverseTwinobject>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestTwinobjectsForExperience(const FDTNativeClientCoreUUID &ExperienceID, FDTNativeClientTwinverseTwinobjectListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinobjectListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestTwinobjectsForExperience(
		Session,
		ExperienceID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Twinobject, FDTNativeClientTwinverseTwinobject, FDTNativeClientTwinverseTwinobjectListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestTwinobjectsForExperienceLatent(
	const FDTNativeClientCoreUUID &ExperienceID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinobject> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinobject> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestTwinobjectsForExperience(
		Session,
		ExperienceID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Twinobject, FDTNativeClientTwinverseTwinobject>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllMediaobjectAssets(FDTNativeClientTwinverseMediaobjectAssetListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseMediaobjectAssetListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllMediaobjectAssets(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_MediaobjectAsset, FDTNativeClientTwinverseMediaobjectAsset, FDTNativeClientTwinverseMediaobjectAssetListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllMediaobjectAssetsLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseMediaobjectAsset> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseMediaobjectAsset> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllMediaobjectAssets(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_MediaobjectAsset, FDTNativeClientTwinverseMediaobjectAsset>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllTwinobjectAssets(FDTNativeClientTwinverseTwinobjectAssetListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinobjectAssetListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllTwinobjectAssets(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset, FDTNativeClientTwinverseTwinobjectAssetListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllTwinobjectAssetsLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinobjectAsset> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinobjectAsset> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllTwinobjectAssets(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestTwinobjectAssetsForExperience(const FDTNativeClientCoreUUID &ExperienceID, FDTNativeClientTwinverseTwinobjectAssetListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinobjectAssetListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestTwinobjectAssetsForExperience(
		Session,
		ExperienceID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset, FDTNativeClientTwinverseTwinobjectAssetListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestTwinobjectAssetsForExperienceLatent(
	const FDTNativeClientCoreUUID &ExperienceID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinobjectAsset> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinobjectAsset> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestTwinobjectAssetsForExperience(
		Session,
		ExperienceID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestTwinobjectAssetsForMoment(const FDTNativeClientCoreUUID &MomentID, FDTNativeClientTwinverseTwinobjectAssetListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinobjectAssetListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestTwinobjectAssetsForMoment(
		Session,
		MomentID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset, FDTNativeClientTwinverseTwinobjectAssetListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestTwinobjectAssetsForMomentLatent(
	const FDTNativeClientCoreUUID &MomentID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinobjectAsset> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinobjectAsset> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestTwinobjectAssetsForMoment(
		Session,
		MomentID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestTwinobjectAssetsForScene(const FDTNativeClientCoreUUID &SceneID, FDTNativeClientTwinverseTwinobjectAssetListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinobjectAssetListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestTwinobjectAssetsForScene(
		Session,
		SceneID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset, FDTNativeClientTwinverseTwinobjectAssetListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestTwinobjectAssetsForSceneLatent(
	const FDTNativeClientCoreUUID &SceneID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinobjectAsset> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinobjectAsset> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestTwinobjectAssetsForScene(
		Session,
		SceneID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestTwinobjectAssetsForTwinstance(const FDTNativeClientCoreUUID &TwinstanceID, FDTNativeClientTwinverseTwinobjectAssetListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseTwinobjectAssetListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestTwinobjectAssetsForTwinstance(
		Session,
		TwinstanceID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset, FDTNativeClientTwinverseTwinobjectAssetListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestTwinobjectAssetsForTwinstanceLatent(
	const FDTNativeClientCoreUUID &TwinstanceID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseTwinobjectAsset> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseTwinobjectAsset> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestTwinobjectAssetsForTwinstance(
		Session,
		TwinstanceID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_TwinobjectAsset, FDTNativeClientTwinverseTwinobjectAsset>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllAssets(FDTNativeClientTwinverseAssetListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseAssetListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllAssets(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_Asset, FDTNativeClientTwinverseAsset, FDTNativeClientTwinverseAssetListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllAssetsLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseAsset> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseAsset> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllAssets(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_Asset, FDTNativeClientTwinverseAsset>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAssetsForTwinobject(const FDTNativeClientCoreUUID &TwinobjectID, FDTNativeClientTwinverseAssetListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseAssetListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAssetsForTwinobject(
		Session,
		TwinobjectID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_Asset, FDTNativeClientTwinverseAsset, FDTNativeClientTwinverseAssetListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAssetsForTwinobjectLatent(
	const FDTNativeClientCoreUUID &TwinobjectID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseAsset> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseAsset> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAssetsForTwinobject(
		Session,
		TwinobjectID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_Asset, FDTNativeClientTwinverseAsset>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllObjectServices(FDTNativeClientTwinverseObjectServiceListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseObjectServiceListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllObjectServices(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_ObjectService, FDTNativeClientTwinverseObjectService, FDTNativeClientTwinverseObjectServiceListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllObjectServicesLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseObjectService> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseObjectService> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllObjectServices(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_ObjectService, FDTNativeClientTwinverseObjectService>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestAllFiles(FDTNativeClientTwinverseFileListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseFileListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestAllFiles(
		Session,
		OnEntriesReceived<DTNACL_Twinverse_File, FDTNativeClientTwinverseFile, FDTNativeClientTwinverseFileListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestAllFilesLatent(
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseFile> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseFile> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestAllFiles(
		Session,
		OnEntriesReceivedLatent<DTNACL_Twinverse_File, FDTNativeClientTwinverseFile>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestFilesForTwinobject(const FDTNativeClientCoreUUID &TwinobjectID, FDTNativeClientTwinverseFileListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseFileListCallback>;
	Action *Context = new Action(Callback);

	dtnaclTwinverseRequestFilesForTwinobject(
		Session,
		TwinobjectID.ToNative(),
		OnEntriesReceived<DTNACL_Twinverse_File, FDTNativeClientTwinverseFile, FDTNativeClientTwinverseFileListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestFilesForTwinobjectLatent(
	const FDTNativeClientCoreUUID &TwinobjectID,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseFile> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseFile> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclTwinverseRequestFilesForTwinobject(
		Session,
		TwinobjectID.ToNative(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_File, FDTNativeClientTwinverseFile>,
		Context
	);
}

/*
 */
void UDTNativeClientTwinverseSession::RequestFilesForAssets(const TArray<FDTNativeClientCoreUUID> &AssetIDs, FDTNativeClientTwinverseFileListCallback Callback)
{
	check(Session != DTNACL_NULL_HANDLE);

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientTwinverseFileListCallback>;
	Action *Context = new Action(Callback);

	TArray<DTNACL_Core_UUID> NativeIDs;
	NativeIDs.Reserve(AssetIDs.Num());
	for (auto AssetID : AssetIDs)
		NativeIDs.Add(AssetID.ToNative());

	dtnaclTwinverseRequestFilesForAssets(
		Session,
		NativeIDs.GetData(),
		NativeIDs.Num(),
		OnEntriesReceived<DTNACL_Twinverse_File, FDTNativeClientTwinverseFile, FDTNativeClientTwinverseFileListCallback>,
		Context
	);
}

void UDTNativeClientTwinverseSession::RequestFilesForAssetsLatent(
	const TArray<FDTNativeClientCoreUUID> &AssetIDs,
	UObject *WorldContext, FLatentActionInfo LatentInfo, EDTNativeClientTwinverseLatentExec &Exec,
	TArray<FDTNativeClientTwinverseFile> &Result, int &Status
)
{
	check(Session != DTNACL_NULL_HANDLE);

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientTwinverseLatentExec *, TArray<FDTNativeClientTwinverseFile> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	TArray<DTNACL_Core_UUID> NativeIDs;
	NativeIDs.Reserve(AssetIDs.Num());
	for (auto AssetID : AssetIDs)
		NativeIDs.Add(AssetID.ToNative());

	dtnaclTwinverseRequestFilesForAssets(
		Session,
		NativeIDs.GetData(),
		NativeIDs.Num(),
		OnEntriesReceivedLatent<DTNACL_Twinverse_File, FDTNativeClientTwinverseFile>,
		Context
	);
}
