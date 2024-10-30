// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include "UNetworkManager.h"
#include "AAIChatBot.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MYPROJECT_API AAIChatBot : public AActor
{
	GENERATED_BODY()

public:
	AAIChatBot();
	~AAIChatBot();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AI Chatbot")
	UNetworkManager* netManager;
 
	UFUNCTION(BlueprintCallable, Category = "AI Chatbot")
	FString SendRequestToAI(FString inputString);
};
