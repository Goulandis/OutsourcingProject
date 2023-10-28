#pragma once

#include "CoreMinimal.h"

#include "DTNativeClientCoreCommon.h"
#include "DTNativeClientCoreSession.generated.h"

class UDTNativeClientCoreTransportData;
class UDTNativeClientCoreTransportDataPool;

/*
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FDTNativeClientCoreConnectionCallback, EDTNativeClientCoreConnectionStatus, ConnectionStatus);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientCoreEventCallback, const TArray<UDTNativeClientCoreTransportData*> &, Data, FString, EventName);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientCoreRequestCallback, const TArray<UDTNativeClientCoreTransportData *> &, Data, int, Status);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTNativeClientCoreDownloadCallback, const TArray<uint8> &, Data, int, Status);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDTNativeClientCoreUploadCallback, int, Status);

/*
 */
UCLASS(ClassGroup = "DTNativeClientCore|Session", BlueprintType, meta=(BlueprintSpawnableComponent))
class DTNATIVECLIENTCORE_API UDTNativeClientCoreSession : public UActorComponent
{
	GENERATED_BODY()

public:
	UDTNativeClientCoreSession();
	virtual ~UDTNativeClientCoreSession() override;

	void Init();
	void Shutdown();
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "DTNativeClientCore|Session")
	void Update();

	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Is Idle", Keywords = "Is Session Idle"), Category = "DTNativeClientCore|Session")
	bool IsIdle() const;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Wait Idle Latent", Keywords = "Session Wait Idle Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientCore|Session")
	void WaitIdleLatent(
		UObject *WorldContext,
		FLatentActionInfo LatentInfo, EDTNativeClientCoreWaitLatentExec &Exec
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Clear", Keywords = "Session Clear"), Category = "DTNativeClientCore|Session")
	void Clear();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Connect", Keywords = "Session Websocket Connect"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketConnect(const FString &Url, FDTNativeClientCoreConnectionCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Connect Latent", Keywords = "Session Websocket Connect Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketConnectLatent(
		UObject *WorldContext, const FString &Url,
		FLatentActionInfo LatentInfo, EDTNativeClientCoreConnectionLatentExec &Exec
	);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Authenticate", Keywords = "Session Websocket Authenticate"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketAuthenticate(const UDTNativeClientCoreTransportData *Data, FDTNativeClientCoreRequestCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Authenticate Latent", Keywords = "Session Websocket Authenticate Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketAuthenticateLatent(
		UObject *WorldContext, const UDTNativeClientCoreTransportData *Data,
		FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
		TArray<UDTNativeClientCoreTransportData *> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Authenticate Local", Keywords = "Session Websocket Authenticate Local"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketAuthenticateLocal(const FString &Login, const FString &Password, const FString &ClientEngine, const FString &ClientOS, FDTNativeClientCoreRequestCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Authenticate Local Latent", Keywords = "Session Websocket Authenticate Local Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketAuthenticateLocalLatent(
		UObject *WorldContext, const FString &Login, const FString &Password, const FString &ClientEngine, const FString &ClientOS,
		FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
		TArray<UDTNativeClientCoreTransportData *> &Result, int &Status
	);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Is Websocket Connected", Keywords = "Is Session Websocket Connected"), Category = "DTNativeClientCore|Session|Websocket")
	bool IsWebsocketConnected();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Disconnect", Keywords = "Session Websocket Disconnect"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketDisconnect();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTNativeClientCore|Session|Websocket")
	int ReconnectAttempts = DTNACL_CORE_CONNECTION_SETTINGS_RECONNECT_ATTEMPTS_DEFAULT;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTNativeClientCore|Session|Websocket")
	int ReconnectDelay = DTNACL_CORE_CONNECTION_SETTINGS_RECONNECT_DELAY_DEFAULT;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTNativeClientCore|Session|Websocket")
	int ReconnectDelayMax = DTNACL_CORE_CONNECTION_SETTINGS_RECONNECT_DELAY_MAX_DEFAULT;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTNativeClientCore|Session|Websocket")
	int PingInterval = DTNACL_CORE_CONNECTION_SETTINGS_PING_INTERVAL_DEFAULT;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTNativeClientCore|Session|Websocket")
	int PingTimeout = DTNACL_CORE_CONNECTION_SETTINGS_PING_TIMEOUT_DEFAULT;

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Websocket User", Keywords = "Session Get Websocket User"), Category = "DTNativeClientCore|Session|Websocket")
	FDTNativeClientCoreUser GetWebsocketUser();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Add Event Listener", Keywords = "Session Websocket Add Event Listener"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketAddEventListener(const FString &EventName, FDTNativeClientCoreEventCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Remove Event Listener", Keywords = "Session Websocket Remove Event Listener"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketRemoveEventListener(const FString &EventName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Clear Websocket Event Listeners", Keywords = "Session Clear Websocket Event Listeners"), Category = "DTNativeClientCore|Session|Websocket")
	void ClearWebsocketEventListeners();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Send", Keywords = "Session Websocket Send", AutoCreateRefTerm = "Parameters"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketSend(const FString &Method, const FString &Service, const TArray<UDTNativeClientCoreTransportData *> &Parameters, FDTNativeClientCoreRequestCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Websocket Send Latent", Keywords = "Session Websocket Send Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext", AutoCreateRefTerm = "Parameters"), Category = "DTNativeClientCore|Session|Websocket")
	void WebsocketSendLatent(
		UObject *WorldContext, const FString &Method, const FString &Service, const TArray<UDTNativeClientCoreTransportData *> &Parameters,
		FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
		TArray<UDTNativeClientCoreTransportData *> &Result, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Clear Websocket Requests", Keywords = "Session Clear Websocket Requests"), Category = "DTNativeClientCore|Session|Websocket")
	void ClearWebsocketRequests();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTNativeClientCore|Session|Http")
	int UploadChunkSize = DTNACL_CORE_HTTP_SETTINGS_UPLOAD_CHUNK_SIZE_DEFAULT;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DTNativeClientCore|Session|Http")
	int UploadChunkAttempts = DTNACL_CORE_HTTP_SETTINGS_UPLOAD_CHUNK_ATTEMPTS_DEFAULT;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Http Download", Keywords = "Session Http Download"), Category = "DTNativeClientCore|Session|Http")
	void HttpDownload(const FString &Url, FDTNativeClientCoreDownloadCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Http Download Latent", Keywords = "Session Http Download Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientCore|Session|Http")
	void HttpDownloadLatent(
		UObject *WorldContext, const FString &Url,
		FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
		TArray<uint8> &Data, int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Http Upload", Keywords = "Session Http Upload"), Category = "DTNativeClientCore|Session|Http")
	void HttpUpload(const FString &Url, const TArray<uint8> &data, const FString &ContentType, FDTNativeClientCoreUploadCallback Callback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Http Upload Latent", Keywords = "Session Http Upload Latent", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Exec", HidePin = "WorldContext", DefaultToSelf = "WorldContext"), Category = "DTNativeClientCore|Session|Http")
	void HttpUploadLatent(
		UObject *WorldContext, const FString &Url, const TArray<uint8> &Data, const FString &ContentType,
		FLatentActionInfo LatentInfo, EDTNativeClientCoreLatentExec &Exec,
		int &Status
	);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Clear Http Requests", Keywords = "Session Clear Http Requests"), Category = "DTNativeClientCore|Session|Http")
	void ClearHttpRequests();

public:
	FORCEINLINE DTNACL_Core_Session GetNativeHandle() const { return Session; }

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	DTNACL_Core_Session Session {DTNACL_NULL_HANDLE};
	TMap<FString, void *> EventListeners;
};
