// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UInteractable_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAME_FOR_OOP_KR_API IInteractable_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Interact(class AFIrstPersonCharacterShooterCpp* Character) = 0;
	virtual void Use(class AFIrstPersonCharacterShooterCpp* Character, bool isInShop=false) {}
};
