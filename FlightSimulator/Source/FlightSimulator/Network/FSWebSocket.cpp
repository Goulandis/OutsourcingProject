// Copyright 2020-2021 CesiumGS, Inc. and Contributors


#include "FSWebSocket.h"

DEFINE_LOG_CATEGORY(FSWebSocketLog);
// Sets default values
AFSWebSocket::AFSWebSocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFSWebSocket::BeginPlay()
{
	Super::BeginPlay();
	
	FModuleManager::Get().LoadModuleChecked("WebSockets");

	Socket = FWebSocketsModule::Get().CreateWebSocket(ServerURL, ServerProtocol);

	Socket->OnConnected().AddUObject(this, &AFSWebSocket::OnConnected);
	Socket->OnConnectionError().AddUObject(this, &AFSWebSocket::OnConnectionError);
	Socket->OnClosed().AddUObject(this, &AFSWebSocket::OnClosed);
	Socket->OnMessage().AddUObject(this, &AFSWebSocket::OnMessage);
	Socket->OnMessageSent().AddUObject(this, &AFSWebSocket::OnMessageSent);
}

// Called every frame
void AFSWebSocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFSWebSocket::Connect()
{
	Socket->Connect();
}

void AFSWebSocket::OnConnected_Implementation()
{
	IsConnected = true;
	UE_LOG(FSWebSocketLog, Log, TEXT("%s"), *FString(__FUNCTION__));
}

void AFSWebSocket::OnConnectionError_Implementation(const FString& Error)
{
	UE_LOG(FSWebSocketLog, Log, TEXT("%s Error:%s"), *FString(__FUNCTION__), *Error);
}

void AFSWebSocket::OnClosed_Implementation(int32 StatusCode, const FString& Reason, bool bWasClean)
{
	IsConnected = false;
	UE_LOG(FSWebSocketLog, Log, TEXT("%s StatusCode:%d Reason:%s bWasClean:%d"),
		*FString(__FUNCTION__), StatusCode, *Reason, bWasClean);
}

void AFSWebSocket::OnMessage_Implementation(const FString& Message)
{
	UE_LOG(FSWebSocketLog, Log, TEXT("%s Message:%s"), *FString(__FUNCTION__), *Message);
}

void AFSWebSocket::OnMessageSent_Implementation(const FString& MessageString)
{
	UE_LOG(FSWebSocketLog, Log, TEXT("%s MessageString:%s"), *FString(__FUNCTION__), *MessageString);
}

