# UnrealAI

This is a sample test project to interface with an AI agent. 

## This project was made with Unreal Engine v5.4.4 and Visual Studio 2022 

## Instructions (Please watch [this video](UnrealAI_Demo.mkv) for a demo)

1. Clone this repository
2. Open up the project in unreal engine
3. Navigate to [this scene](MyProject/Content/Levels/DemoLevel.umap) (MyProject/Content/Levels/DemoLevel.umap)
4. From the Outliner, select `BP_Chatbot` and in the inspector, put in your key
5. Once you hit play, put in your message, select the model, hit send, and enjoy!

## Important Files

1. `EML-Tech Dev Assignment-Oct 28 2024.pdf` - Assignment Description
2. `UnrealAI_Demo.mkv` - Demo of project
3. `ThoughtProcess.txt` - Some notes as a I approached this, akin to scribbling on a notepad as I figure things out
4. `MyProject/Content/Levels/DemoLevel.umap` - The scene/level where everything happens
5. `MyProject/Content/UI/UMG_Chatbot.uasset` - The widget the user will interact with
6. `MyProject/Source/MyProject/Public/AAIChatBot.h` - Header file for the Chabot API
7. `MyProject/Source/MyProject/Public/UNetworkManager.h` - Header file for the NetworkManager
8. `MyProject/Source/MyProject/Private/AAIChatBot.cpp` - Code for the Chatbot API
9. `MyProject/Source/MyProject/Private/UNetworkManager.cpp` - Code for the NetworkManager

## Possible improvements
1. Improved error handling: For network errors, server errors (essentially all non 200 responses)
2. Adding more models
3. Allowing for text-to-speech or text-to-image (like DALL-E)
4. User login or SSO to get key
5. Aesthetic improvements
6. Integrate this into a game so a in-game character can talk to the AI


If you have any questions, please feel free to email me at atifmahmud95@gmail.com!
