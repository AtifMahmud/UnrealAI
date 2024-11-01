// Fill out your copyright notice in the Description page of Project Settings.


#include "AAIChatBot.h"

AAIChatBot::AAIChatBot()
{

}

AAIChatBot::~AAIChatBot()
{

}


FString AAIChatBot::SendRequestToAI(FString inputString, FString model, FString key)
{
	netManager = NewObject<UNetworkManager>();
	netManager->SendRequest(inputString, model, key);
	return inputString;
}
