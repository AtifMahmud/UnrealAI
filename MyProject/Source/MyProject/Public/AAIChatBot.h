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
 
	/// <summary>
	/// Sends a request to OpenAI model with the specific key
	/// </summary>
	/// <param name="inputString">The message for AI</param>
	/// <param name="model">Model to use</param>
	/// <param name="key">The secret key</param>
	/// <returns>The initial string that was passed in as a message</returns>
	UFUNCTION(BlueprintCallable, Category = "AI Chatbot")
	FString SendRequestToAI(FString inputString, FString model, FString key);
};
