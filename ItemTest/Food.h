// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAME_FOR_OOP_KR/ItemTest/Item_Test.h"
#include "Food.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API AFood : public AItem_Test
{
	GENERATED_BODY()
public:
	AFood();
	virtual void Use(AFIrstPersonCharacterShooterCpp* Character, bool isInShop) override;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//	class USoundBase* FoodUsageSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimDelay")
		float AnimDelay;
protected:
	UPROPERTY(EditAnywhere, Category = "Food")
		float FoodValue;
};
