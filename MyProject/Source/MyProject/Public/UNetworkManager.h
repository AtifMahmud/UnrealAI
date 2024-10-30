// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "HttpManager.h"
#include "Json.h"
#include "JsonUtilities.h"

/**
 * 
 */ 
class MYPROJECT_API UNetworkManager : public UObject
{
public:
	UNetworkManager();
	~UNetworkManager();

	void SendRequest(FString& Prompt);
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
