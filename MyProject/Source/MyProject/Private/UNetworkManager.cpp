// Fill out your copyright notice in the Description page of Project Settings.


#include "UNetworkManager.h"

UNetworkManager::UNetworkManager()
{

}

UNetworkManager::~UNetworkManager()
{

}

void UNetworkManager::SendRequest(FString& Prompt)
{
    TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
    Request->SetURL("https://api.openai.com/v1/completions");
    Request->SetVerb("POST");
    Request->SetHeader("Content-Type", "application/json");
    Request->SetHeader("Authorization", "Bearer YOUR_API_KEY");

    // Create JSON payload
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField("model", "text-davinci-003");
    JsonObject->SetStringField("prompt", Prompt);
    JsonObject->SetNumberField("max_tokens", 50);

    FString RequestBody;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

    Request->SetContentAsString(RequestBody);

    // Bind to response callback
    Request->OnProcessRequestComplete().BindUObject(this, &UNetworkManager::OnResponseReceived);
    Request->ProcessRequest();
}

void UNetworkManager::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (bWasSuccessful && Response.IsValid())
    {
        FString ResponseContent = Response->GetContentAsString();
        OnResponseReceivedDelegate.Broadcast(ResponseContent);
    }
    else
    {
        OnResponseReceivedDelegate.Broadcast(TEXT("Request failed"));
    }
}