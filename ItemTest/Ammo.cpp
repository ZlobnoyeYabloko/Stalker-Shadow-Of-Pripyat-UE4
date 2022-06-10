// Fill out your copyright notice in the Description page of Project Settings.


#include "Ammo.h"

AAmmo::AAmmo()
{
	ItemData.ItemClass = StaticClass();
	AmmoCount = 30.0f;
}
void AAmmo::Use(AFIrstPersonCharacterShooterCpp* Character, bool isInShop)
{
	Super::Use(Character, isInShop);
	if (Character && !isInShop)
	{
		Character->AddAmmoFromUse(AmmoCount);
	}
}