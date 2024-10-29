// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
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

	UFUNCTION(BlueprintCallable, Category = "AIChatBot")
	static FString TextTest(FString test);
};
