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
class MYPROJECT_API NetworkManager
{
public:
	NetworkManager();
	~NetworkManager();

	void SendRequest();
	void OnResponseReceived();
};
