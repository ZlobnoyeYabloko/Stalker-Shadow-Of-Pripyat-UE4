// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GAME_FOR_OOP_KR/ItemTest/Item_Test.h"
#include "Math/Vector.h"
#include "GAME_FOR_OOP_KR/Inventory/Inventory.h"
#include "MySaveGame_Cpp.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API UMySaveGame_Cpp : public USaveGame
{
	GENERATED_BODY()
public: 
	UMySaveGame_Cpp();

	UPROPERTY(EditAnywhere)
		FVector PlayerLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		TArray<FItems_Data> InventoryItems_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float ammo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float ammoPockets;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Health;
};
