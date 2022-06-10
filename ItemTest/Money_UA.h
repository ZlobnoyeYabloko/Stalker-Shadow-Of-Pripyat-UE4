// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item_Test.h"
#include "Money_UA.generated.h"

/**
 * 
 */
class AFIrstPersonCharacterShooterCpp;

UCLASS()
class GAME_FOR_OOP_KR_API AMoney_UA : public AItem_Test
{
	GENERATED_BODY()
	
public:
	AMoney_UA();

	virtual void Use(class AFIrstPersonCharacterShooterCpp* Character, bool isInShop) override;
};
