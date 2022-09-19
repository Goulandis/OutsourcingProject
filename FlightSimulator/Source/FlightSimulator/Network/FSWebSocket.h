// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#pragma once
#include "WebSocketsModule.h"
#include "IWebSocket.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSWebSocket.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(FSWebSocketLog, Log, All);

UCLASS()
class FLIGHTSIMULATOR_API AFSWebSocket : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "FSWebSocket")
	FString ServerURL = "ws://localhost:8080/myWs";
	UPROPERTY(EditAnywhere, Category = "FSWebSocket")
	FString ServerProtocol = "ws";
	TSharedPtr<IWebSocket> Socket = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "FSWebSocket")
	bool IsConnected = false;
public:	
	// Sets default values for this actor's properties
	AFSWebSocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintNativeEvent, Category = "FSWebSocket")
	void OnConnected();
	UFUNCTION(BlueprintNativeEvent, Category = "FSWebSocket")
	void OnConnectionError(const FString& Error);
	UFUNCTION(BlueprintNativeEvent, Category = "FSWebSocket")
	void OnClosed(int32 StatusCode, const FString& Reason, bool bWasClean);
	UFUNCTION(BlueprintNativeEvent, Category = "FSWebSocket")
	void OnMessage(const FString& Message); // 接收消息时
	UFUNCTION(BlueprintNativeEvent, Category = "FSWebSocket")
	void OnMessageSent(const FString& MessageString); // 发送消息时
	UFUNCTION(BlueprintCallable,Category="FSWebSocket")
	void Connect();
};
