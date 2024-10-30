// Fill out your copyright notice in the Description page of Project Settings.


#include "AAIChatBot.h"

AAIChatBot::AAIChatBot()
{

}

AAIChatBot::~AAIChatBot()
{

}


FString AAIChatBot::SendRequestToAI(FString inputString)
{
	UNetworkManager* manager = NewObject<UNetworkManager>();
	manager->SendRequest(inputString);
	return inputString;
}
