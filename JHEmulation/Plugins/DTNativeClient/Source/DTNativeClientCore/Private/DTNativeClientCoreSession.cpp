#include "DTNativeClientCoreSession.h"
#include "DTNativeClientCoreTransportData.h"
#include "DTNativeClientCoreTransportDataPool.h"

/*
 */
class FDTNativeClientCoreLatentWaitIdle : public FPendingLatentAction
{
public:
	FDTNativeClientCoreLatentWaitIdle() = delete;
	FDTNativeClientCoreLatentWaitIdle(const FDTNativeClientCoreLatentWaitIdle &) = delete;
	FDTNativeClientCoreLatentWaitIdle(FDTNativeClientCoreLatentWaitIdle &&) = delete;

	FDTNativeClientCoreLatentWaitIdle(const FLatentActionInfo &Info, const UDTNativeClientCoreSession *Session, EDTNativeClientCoreWaitLatentExec &Exec)
		: Info(Info), Session(Session), Exec(Exec)
	{
	}

	FDTNativeClientCoreLatentWaitIdle &operator=(const FDTNativeClientCoreLatentWaitIdle &) = delete;
	FDTNativeClientCoreLatentWaitIdle &operator=(FDTNativeClientCoreLatentWaitIdle &&) = delete;

	static FORCEINLINE FDTNativeClientCoreLatentWaitIdle *Create(const UObject *Owner, const FLatentActionInfo &LatentInfo, const UDTNativeClientCoreSession *Session, EDTNativeClientCoreWaitLatentExec &Exec)
	{
		UWorld *World = GEngine->GetWorldFromContextObject(Owner, EGetWorldErrorMode::LogAndReturnNull);
		if (!World)
			return nullptr;

		FLatentActionManager &LatentActionManager = World->GetLatentActionManager();

		FDTNativeClientCoreLatentWaitIdle *LatentAction = nullptr;

		LatentAction = LatentActionManager.FindExistingAction<FDTNativeClientCoreLatentWaitIdle>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		if (LatentAction == nullptr)
		{
			LatentAction = new FDTNativeClientCoreLatentWaitIdle(LatentInfo, Session, Exec);
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, LatentAction);
		}

		return LatentAction;
	}

	void UpdateOperation(FLatentResponse &Response) override
	{
		if (!Session->IsIdle())
			return;

		Exec = EDTNativeClientCoreWaitLatentExec::OnFinished;
		Response.FinishAndTriggerIf(true, Info.ExecutionFunction, Info.Linkage, Info.CallbackTarget);
	}

private:
	FLatentActionInfo Info;
	const UDTNativeClientCoreSession *Session;
	EDTNativeClientCoreWaitLatentExec &Exec;
};


/*
 */
static void OnConnect(DTNACL_Core_Session Session, DTNACL_Core_ConnectionStatus Status, void *UserData)
{
	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreConnectionCallback>;
	Action *Context = reinterpret_cast<Action *>(UserData);
	check(Context != nullptr);

	EDTNativeClientCoreConnectionStatus CallbackStatus = static_cast<EDTNativeClientCoreConnectionStatus>(Status);

	UE_LOG(LogDTNativeClient, Log, TEXT("Calling OnConnect callback with status %d"), static_cast<int>(CallbackStatus));
	Context->Callback.ExecuteIfBound(CallbackStatus);

	delete Context;
}

static void OnConnectLatent(DTNACL_Core_Session Session, DTNACL_Core_ConnectionStatus Status, void *UserData)
{
	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientCoreConnectionLatentExec *>;
	LatentAction *Context = reinterpret_cast<LatentAction *>(UserData);
	check(Context != nullptr);

	EDTNativeClientCoreConnectionStatus CallbackStatus = static_cast<EDTNativeClientCoreConnectionStatus>(Status);
	EDTNativeClientCoreConnectionLatentExec LatentExec = EDTNativeClientCoreConnectionLatentExec::OnFailed;
	bool Finish = false;

	if (CallbackStatus == EDTNativeClientCoreConnectionStatus::DISCONNECTED)
	{
		Finish = true;
		LatentExec = EDTNativeClientCoreConnectionLatentExec::OnDisconnected;
	}
	else if (CallbackStatus == EDTNativeClientCoreConnectionStatus::CONNECTED)
		LatentExec = EDTNativeClientCoreConnectionLatentExec::OnConnected;
	else if (CallbackStatus == EDTNativeClientCoreConnectionStatus::RECONNECT_ATTEMPT)
		LatentExec = EDTNativeClientCoreConnectionLatentExec::OnReconnectAttempt;
	else if (CallbackStatus == EDTNativeClientCoreConnectionStatus::RECONNECT_STARTED)
		LatentExec = EDTNativeClientCoreConnectionLatentExec::OnReconnectStarted;
	else if (CallbackStatus == EDTNativeClientCoreConnectionStatus::FAILED)
	{
		Finish = true;
		LatentExec = EDTNativeClientCoreConnectionLatentExec::OnFailed;
	}

	*(Context->GetParameters().Get<0>()) = LatentExec;

	if (Finish)
		Context->CallAndFinish();
	else
		Context->Call();
}

/*
 */
static void OnRequest(DTNACL_Core_Session Session, const DTNACL_Core_TransportData *Responses, uint64_t NumResponses, DTNACL_Core_Status Status, void *UserData)
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

	UE_LOG(LogDTNativeClient, Log, TEXT("Calling OnRequest callback with status %d"), static_cast<int>(CallbackStatus));
	Context->Callback.ExecuteIfBound(CallbackResponses, CallbackStatus);
	delete Context;
}

static void OnRequestLatent(DTNACL_Core_Session Session, const DTNACL_Core_TransportData *Responses, uint64_t NumResponses, DTNACL_Core_Status Status, void *UserData)
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
static void OnEvent(DTNACL_Core_Session Session, const DTNACL_Core_TransportData *Responses, uint64_t NumResponses, const char *EventName, void *UserData)
{
	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreEventCallback>;
	Action *Context = reinterpret_cast<Action *>(UserData);
	check(Context != nullptr);

	FString CallbackEventName(EventName);

	TArray<UDTNativeClientCoreTransportData *> CallbackResponses;
	CallbackResponses.Reserve(NumResponses);
	for (uint64_t i = 0; i < NumResponses; ++i)
	{
		DTNACL_Core_TransportData Response = Responses[i];
		UDTNativeClientCoreTransportData *CallbackResponse = UDTNativeClientCoreTransportData::CreateFromNativeHandle(Response);
		CallbackResponses.Add(CallbackResponse);
	}

	Context->Callback.ExecuteIfBound(CallbackResponses, CallbackEventName);
}

/*
 */
static void OnHttpDownload(DTNACL_Core_Session Session, const uint8_t *Data, uint64_t Size, DTNACL_Core_Status Status, void *UserData)
{
	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreDownloadCallback>;
	Action *Context = reinterpret_cast<Action *>(UserData);
	check(Context != nullptr);

	int CallbackStatus = static_cast<int>(Status);
	TArray<uint8> Array(Data, static_cast<int32>(Size));

	Context->Callback.ExecuteIfBound(Array, CallbackStatus);
	delete Context;
}

static void OnHttpDownloadLatent(DTNACL_Core_Session Session, const uint8_t *Data, uint64_t Size, DTNACL_Core_Status Status, void *UserData)
{
	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientCoreLatentExec *, TArray<uint8> *, int *>;
	LatentAction *Context = reinterpret_cast<LatentAction *>(UserData);
	check(Context != nullptr);

	int CallbackStatus = static_cast<int>(Status);
	TArray<uint8> Array(Data, static_cast<int32>(Size));

	EDTNativeClientCoreLatentExec LatentExec = EDTNativeClientCoreLatentExec::OnSuccess;
	if (CallbackStatus != DTNACL_CORE_STATUS_OK)
		LatentExec = EDTNativeClientCoreLatentExec::OnFail;

	*(Context->GetParameters().Get<0>()) = LatentExec;
	*(Context->GetParameters().Get<1>()) = MoveTemp(Array);
	*(Context->GetParameters().Get<2>()) = CallbackStatus;

	Context->CallAndFinish();
}

/*
 */
static void OnHttpUpload(DTNACL_Core_Session Session, DTNACL_Core_Status Status, void *UserData)
{
	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreUploadCallback>;
	Action *Context = reinterpret_cast<Action *>(UserData);
	check(Context != nullptr);

	int CallbackStatus = static_cast<int>(Status);

	Context->Callback.ExecuteIfBound(CallbackStatus);
	delete Context;
}

static void OnHttpUploadLatent(DTNACL_Core_Session Session, DTNACL_Core_Status Status, void *UserData)
{
	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientCoreLatentExec *, int *>;
	LatentAction *Context = reinterpret_cast<LatentAction *>(UserData);
	check(Context != nullptr);

	int CallbackStatus = static_cast<int>(Status);

	EDTNativeClientCoreLatentExec LatentExec = EDTNativeClientCoreLatentExec::OnSuccess;
	if (CallbackStatus != DTNACL_CORE_STATUS_OK)
		LatentExec = EDTNativeClientCoreLatentExec::OnFail;

	*(Context->GetParameters().Get<0>()) = LatentExec;
	*(Context->GetParameters().Get<1>()) = CallbackStatus;

	Context->CallAndFinish();
}

/*
 */
UDTNativeClientCoreSession::UDTNativeClientCoreSession()
{
	PrimaryComponentTick.bCanEverTick = true;
	bTickInEditor = true;

	Init();
}

UDTNativeClientCoreSession::~UDTNativeClientCoreSession()
{
	Shutdown();
}

void UDTNativeClientCoreSession::Init()
{
	if (Session != DTNACL_NULL_HANDLE)
	{
		return;
	}

	Session = dtnaclCoreSessionCreate();
	check(Session != DTNACL_NULL_HANDLE);

	DTNACL_Core_ConnectionSettings ConnectionSettings = {};
	ConnectionSettings.reconnect_attempts = static_cast<uint32_t>(ReconnectAttempts);
	ConnectionSettings.reconnect_delay = static_cast<uint32_t>(ReconnectDelay);
	ConnectionSettings.reconnect_delay_max = static_cast<uint32_t>(ReconnectDelayMax);
	ConnectionSettings.ping_interval = static_cast<uint32_t>(PingInterval);
	ConnectionSettings.ping_timeout = static_cast<uint32_t>(PingTimeout);

	dtnaclCoreSessionWebsocketSetConnectionSettings(Session, &ConnectionSettings);

	DTNACL_Core_HttpSettings HttpSettings = {};
	HttpSettings.upload_chunk_size = static_cast<uint32_t>(UploadChunkSize);
	HttpSettings.upload_chunk_attempts = static_cast<uint32_t>(UploadChunkAttempts);

	dtnaclCoreSessionHttpSetSettings(Session, &HttpSettings);
}

void UDTNativeClientCoreSession::Shutdown()
{
	dtnaclCoreSessionDestroy(Session);
	Session = DTNACL_NULL_HANDLE;
}

void UDTNativeClientCoreSession::Update()
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		return;
	}

	dtnaclCoreSessionUpdate(Session);
}

void UDTNativeClientCoreSession::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void UDTNativeClientCoreSession::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Shutdown();
	Super::EndPlay(EndPlayReason);
}

void UDTNativeClientCoreSession::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Update();
}

bool UDTNativeClientCoreSession::IsIdle() const
{
	return dtnaclCoreSessionIsIdle(Session);
}

void UDTNativeClientCoreSession::WaitIdleLatent(
	UObject *WorldContext,
	FLatentActionInfo LatentInfo, EDTNativeClientCoreWaitLatentExec &Exec
)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WaitIdleLatent with an uninitialized Session"));
		return;
	}

	using LatentAction = FDTNativeClientCoreLatentWaitIdle;
	LatentAction::Create(WorldContext, LatentInfo, this, Exec);
}

void UDTNativeClientCoreSession::Clear()
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::Clear with an uninitialized Session"));
		return;
	}

	dtnaclCoreSessionClear(Session);
}

void UDTNativeClientCoreSession::WebsocketConnect(const FString &Url, FDTNativeClientCoreConnectionCallback Callback)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketConnect with an uninitialized Session"));
		return;
	}

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreConnectionCallback>;
	Action *Context = new Action(Callback);

	dtnaclCoreSessionWebsocketConnect(Session, TCHAR_TO_UTF8(*Url), OnConnect, Context);
}

void UDTNativeClientCoreSession::WebsocketConnectLatent(
	UObject *WorldContext, const FString &Url,
	FLatentActionInfo LatentInfo, EDTNativeClientCoreConnectionLatentExec &Exec
)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketConnectLatent with an uninitialized Session"));
		return;
	}

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientCoreConnectionLatentExec *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec);
	
	if (Context == nullptr)
		return;

	dtnaclCoreSessionWebsocketConnect(Session, TCHAR_TO_UTF8(*Url), OnConnectLatent, Context);
}

void UDTNativeClientCoreSession::WebsocketAuthenticate(const UDTNativeClientCoreTransportData *Data, FDTNativeClientCoreRequestCallback Callback)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketAuthenticate with an uninitialized Session"));
		return;
	}

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreRequestCallback>;
	Action *Context = new Action(Callback);

	dtnaclCoreSessionWebsocketAuthenticate(Session, Data->GetNativeHandle(), OnRequest, Context);
}

void UDTNativeClientCoreSession::WebsocketAuthenticateLatent(
	UObject *WorldContext, const UDTNativeClientCoreTransportData *Data, 
	FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
	TArray<UDTNativeClientCoreTransportData *> &Result, int &Status
)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketAuthenticateLatent with an uninitialized Session"));
		return;
	}

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientCoreLatentExec *, TArray<UDTNativeClientCoreTransportData *> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclCoreSessionWebsocketAuthenticate(Session, Data->GetNativeHandle(), OnRequestLatent, Context);
}

void UDTNativeClientCoreSession::WebsocketAuthenticateLocal(const FString &Login, const FString &Password, const FString &ClientEngine, const FString &ClientOS, FDTNativeClientCoreRequestCallback Callback)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketAuthenticateLocal with an uninitialized Session"));
		return;
	}

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreRequestCallback>;
	Action *Context = new Action(Callback);

	auto ClientEngineStr = FTCHARToUTF8(*ClientEngine);
	auto ClientOSStr = FTCHARToUTF8(*ClientOS);
	auto LoginStr = FTCHARToUTF8(*Login);
	auto PasswordStr = FTCHARToUTF8(*Password);

	DTNACL_Core_AuthData Data = {};
	Data.client_engine = ClientEngineStr.Get();
	Data.client_os = ClientOSStr.Get();
	Data.login = LoginStr.Get();
	Data.password = PasswordStr.Get();

	dtnaclCoreSessionWebsocketAuthenticateLocal(Session, &Data, OnRequest, Context);
}

void UDTNativeClientCoreSession::WebsocketAuthenticateLocalLatent(
	UObject *WorldContext, const FString &Login, const FString &Password, const FString &ClientEngine, const FString &ClientOS,
	FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
	TArray<UDTNativeClientCoreTransportData *> &Result, int &Status
)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketAuthenticateLocalLatent with an uninitialized Session"));
		return;
	}

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientCoreLatentExec *, TArray<UDTNativeClientCoreTransportData *> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Result, &Status);
	
	if (Context == nullptr)
		return;

	auto ClientEngineStr = FTCHARToUTF8(*ClientEngine);
	auto ClientOSStr = FTCHARToUTF8(*ClientOS);
	auto LoginStr = FTCHARToUTF8(*Login);
	auto PasswordStr = FTCHARToUTF8(*Password);

	DTNACL_Core_AuthData Data = {};
	Data.client_engine = ClientEngineStr.Get();
	Data.client_os = ClientOSStr.Get();
	Data.login = LoginStr.Get();
	Data.password = PasswordStr.Get();

	dtnaclCoreSessionWebsocketAuthenticateLocal(Session, &Data, OnRequestLatent, Context);
}

bool UDTNativeClientCoreSession::IsWebsocketConnected()
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::IsWebsocketConnected with an uninitialized Session"));
		return false;
	}

	return dtnaclCoreSessionWebsocketIsConnected(Session);
}

void UDTNativeClientCoreSession::WebsocketDisconnect()
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketDisconnect with an uninitialized Session"));
		return;
	}

	dtnaclCoreSessionWebsocketDisconnect(Session);
}

FDTNativeClientCoreUser UDTNativeClientCoreSession::GetWebsocketUser()
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::GetWebsocketUser with an uninitialized Session"));
		return {};
	}

	const DTNACL_Core_User *User = dtnaclCoreSessionWebsocketGetUser(Session);
	check(User);

	FDTNativeClientCoreUser Result = FDTNativeClientCoreUser::FromNative(*User);

	return Result;
}

void UDTNativeClientCoreSession::WebsocketSend(
	const FString &Method, const FString &Service, const TArray<UDTNativeClientCoreTransportData *> &Parameters,
	FDTNativeClientCoreRequestCallback Callback
)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketSend with an uninitialized Session"));
		return;
	}

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreRequestCallback>;
	Action *Context = new Action(Callback);

	TArray<DTNACL_Core_TransportData> NativeParameters;
	NativeParameters.Reserve(Parameters.Num());
	for (auto Parameter : Parameters)
	{
		if (Parameter == nullptr)
		{
			UE_LOG(LogDTNativeClient, Warning, TEXT("Called UDTNativeClientCoreSession::WebsocketSend with a null parameter, skipping it (this may lead to an invalid payload being sent to the server)"));
			continue;
		}
		NativeParameters.Add(Parameter->GetNativeHandle());
	}

	dtnaclCoreSessionWebsocketSend(Session, TCHAR_TO_UTF8(*Method), TCHAR_TO_UTF8(*Service), NativeParameters.GetData(), NativeParameters.Num(), OnRequest, Context);
}

void UDTNativeClientCoreSession::WebsocketSendLatent(
	UObject *WorldContext, const FString &Method, const FString &Service, const TArray<UDTNativeClientCoreTransportData *> &Parameters,
	FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
	TArray<UDTNativeClientCoreTransportData *> &Result, int &Status
)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketSendLatent with an uninitialized Session"));
		return;
	}

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

	dtnaclCoreSessionWebsocketSend(Session, TCHAR_TO_UTF8(*Method), TCHAR_TO_UTF8(*Service), NativeParameters.GetData(), NativeParameters.Num(), OnRequestLatent, Context);
}

void UDTNativeClientCoreSession::ClearWebsocketRequests()
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::ClearWebsocketRequests with an uninitialized Session"));
		return;
	}

	dtnaclCoreSessionClearWebsocketRequests(Session);
}

void UDTNativeClientCoreSession::WebsocketAddEventListener(const FString &EventName, FDTNativeClientCoreEventCallback Callback)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketAddEventListener with an uninitialized Session"));
		return;
	}

	if (EventListeners.Contains(EventName))
		return;

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreEventCallback>;
	Action *Context = new Action(Callback);

	EventListeners.Add(EventName, Context);

	dtnaclCoreSessionWebsocketAddEventListener(Session, TCHAR_TO_UTF8(*EventName), OnEvent, Context);
}

void UDTNativeClientCoreSession::WebsocketRemoveEventListener(const FString &EventName)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::WebsocketRemoveEventListener with an uninitialized Session"));
		return;
	}

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreEventCallback>;
	Action *Context = reinterpret_cast<Action *>(EventListeners.Find(EventName));

	if (!Context)
		return;

	EventListeners.Remove(EventName);

	delete Context;
	dtnaclCoreSessionWebsocketRemoveEventListener(Session, TCHAR_TO_UTF8(*EventName));
}

void UDTNativeClientCoreSession::ClearWebsocketEventListeners()
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::ClearWebsocketEventListeners with an uninitialized Session"));
		return;
	}

	for (auto &Pair: EventListeners)
		delete Pair.Value;

	EventListeners.Empty();
	dtnaclCoreSessionClearWebsocketEventListeners(Session);
}

void UDTNativeClientCoreSession::HttpDownload(const FString &Url, FDTNativeClientCoreDownloadCallback Callback)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::HttpDownload with an uninitialized Session"));
		return;
	}

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreDownloadCallback>;
	Action *Context = new Action(Callback);

	dtnaclCoreSessionHttpDownload(Session, TCHAR_TO_UTF8(*Url), OnHttpDownload, Context);
}

void UDTNativeClientCoreSession::HttpDownloadLatent(
	UObject *WorldContext, const FString &Url,
	FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
	TArray<uint8> &Data, int &Status
)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::HttpDownloadLatent with an uninitialized Session"));
		return;
	}

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientCoreLatentExec *, TArray<uint8> *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Data, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclCoreSessionHttpDownload(Session, TCHAR_TO_UTF8(*Url), OnHttpDownloadLatent, Context);
}

void UDTNativeClientCoreSession::HttpUpload(const FString &Url, const TArray<uint8> &Data, const FString &ContentType, FDTNativeClientCoreUploadCallback Callback)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::HttpUpload with an uninitialized Session"));
		return;
	}

	using Action = FDTNativeClientCoreCallingContext<FDTNativeClientCoreUploadCallback>;
	Action *Context = new Action(Callback);

	dtnaclCoreSessionHttpUpload(Session, TCHAR_TO_UTF8(*Url), Data.GetData(), Data.Num(), TCHAR_TO_UTF8(*ContentType), OnHttpUpload, Context);
}

void UDTNativeClientCoreSession::HttpUploadLatent(
	UObject *WorldContext, const FString &Url, const TArray<uint8> &Data, const FString &ContentType,
	FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
	int &Status
)
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::HttpUploadLatent with an uninitialized Session"));
		return;
	}

	using LatentAction = FDTNativeClientCoreLatentCallingContext<EDTNativeClientCoreLatentExec *, int *>;
	LatentAction *Context = LatentAction::Create(WorldContext, LatentInfo, &Exec, &Status);
	
	if (Context == nullptr)
		return;

	dtnaclCoreSessionHttpUpload(Session, TCHAR_TO_UTF8(*Url), Data.GetData(), Data.Num(), TCHAR_TO_UTF8(*ContentType), OnHttpUploadLatent, Context);
}

void UDTNativeClientCoreSession::ClearHttpRequests()
{
	if (Session == DTNACL_NULL_HANDLE)
	{
		UE_LOG(LogDTNativeClient, Error, TEXT("Called UDTNativeClientCoreSession::ClearHttpRequests with an uninitialized Session"));
		return;
	}

	dtnaclCoreSessionClearHttpRequests(Session);
}
