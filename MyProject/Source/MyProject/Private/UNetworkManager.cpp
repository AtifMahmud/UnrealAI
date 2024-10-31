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
    Request->SetURL("https://api.openai.com/v1/chat/completions");
    Request->SetVerb("POST");
    Request->SetHeader("Content-Type", "application/json");
    Request->SetHeader("Authorization", "Bearer");

    // Create JSON payload
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField("model", "gpt-3.5-turbo");

    // Create the messages array
    TArray<TSharedPtr<FJsonValue>> MessagesArray;

    // Create the user message object
    TSharedPtr<FJsonObject> UserMessage = MakeShareable(new FJsonObject());
    UserMessage->SetStringField("role", "user");
    UserMessage->SetStringField("content", Prompt);

    // Add the user message to the messages array
    MessagesArray.Add(MakeShareable(new FJsonValueObject(UserMessage)));

    // Set the messages array in the main JSON object
    JsonObject->SetArrayField("messages", MessagesArray);

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
        FString ResponseString = Response->GetContentAsString();
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseString);
        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            // Navigate to choices array -> [0] -> message -> content
            TArray<TSharedPtr<FJsonValue>> ChoicesArray = JsonObject->GetArrayField("choices");
            if (ChoicesArray.Num() > 0)
            {
                TSharedPtr<FJsonObject> MessageObject = ChoicesArray[0]->AsObject()->GetObjectField("message");
                FString Content = MessageObject->GetStringField("content");

                OnResponseReceivedDelegate.Broadcast(Content);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Choices array is empty."));
            }
        }
    }
    else
    {
        OnResponseReceivedDelegate.Broadcast(TEXT("Request failed"));
    }
}