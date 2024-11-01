// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "HttpManager.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "UNetworkManager.generated.h"

/**
 * 
 */ 
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResponseReceivedDelegate, FString, ResponseContent);

UCLASS()
class MYPROJECT_API UNetworkManager : public UObject
{
	GENERATED_BODY()

public:
	UNetworkManager();
	~UNetworkManager();

	UPROPERTY(BlueprintAssignable, Category = "Network")
	FOnResponseReceivedDelegate OnResponseReceivedDelegate;

	void SendRequest(FString& Prompt, FString model, FString key);
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
