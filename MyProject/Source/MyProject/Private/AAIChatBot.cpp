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
	netManager = NewObject<UNetworkManager>();
	netManager->SendRequest(inputString);
	return inputString;
}
