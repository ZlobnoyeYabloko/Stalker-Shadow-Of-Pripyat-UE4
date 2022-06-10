// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item_Test.h"
#include "Ammo.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API AAmmo : public AItem_Test
{
	GENERATED_BODY()
public:
	AAmmo();
	UPROPERTY(EditAnywhere, Category = "Food")
		float AmmoCount;
	virtual void Use(AFIrstPersonCharacterShooterCpp* Character, bool isInShop) override;
};
