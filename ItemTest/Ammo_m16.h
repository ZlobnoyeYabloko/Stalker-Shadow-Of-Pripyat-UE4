// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item_Test.h"
#include "Ammo_m16.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API AAmmo_m16 : public AItem_Test
{
	GENERATED_BODY()
public:
	AAmmo_m16();
	void UpdateAmmoCount(float value);
	float ammoCount;
	AFIrstPersonCharacterShooterCpp* Character;
	float GetAmmoCount();
};
