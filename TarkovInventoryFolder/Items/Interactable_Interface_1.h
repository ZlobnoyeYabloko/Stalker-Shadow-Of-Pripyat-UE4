// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable_Interface_1.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractable_Interface_1 : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAME_FOR_OOP_KR_API IInteractable_Interface_1
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Interact1(class AFIrstPersonCharacterShooterCpp* Character) = 0;
	virtual void Use1(class AFIrstPersonCharacterShooterCpp* Character) {}
};
