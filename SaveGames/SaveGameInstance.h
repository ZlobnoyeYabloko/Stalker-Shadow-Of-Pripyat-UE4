// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameFramework/SaveGame.h"
#include "GAME_FOR_OOP_KR/FIrstPersonCharacterShooterCpp.h"
#include "GAME_FOR_OOP_KR/ItemTest/Item_Test.h"
#include "Math/Vector.h"
#include "GAME_FOR_OOP_KR/Inventory/Inventory.h"
#include "GameFramework/Actor.h"
#include "SaveGameInstance.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API UMainSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString SaveGameName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FDateTime CreationTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		TArray<FItems_Data> InventoryItems_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		FVector PlayerLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AFIrstPersonCharacterShooterCpp* MyCharacter;

	void CreateSlot(const FString& SlotName)
	{
		SaveGameName = SlotName;
		CreationTime = FDateTime::Now();
		InventoryItems_1.Empty();
	};

};
UCLASS()
class GAME_FOR_OOP_KR_API USaveGameInstance : public UGameInstance
{
	GENERATED_BODY()
private:

	static const FString UNIQUE_SAVE_SLOT;
public:
	UPROPERTY()
		UMainSaveGame* CurrentSaveGame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		class AFIrstPersonCharacterShooterCpp* MyCharacter;
public:
	bool IsNewGame();
	bool CreateNewSaveGame();
	bool LoadGame();
	bool SaveGame();
};