// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "UObject/ConstructorHelpers.h"
#include "GAME_FOR_OOP_KR/FIrstPersonCharacterShooterCpp.h"
#include "Kismet/GameplayStatics.h"

AFood::AFood()
{
	FoodValue = 25.0f;
	AnimDelay = 1.5f;
}
void AFood::Use(AFIrstPersonCharacterShooterCpp* Character, bool isInShop)
{
	Super::Use(Character, isInShop);
	if (Character && !isInShop)
	{
		Character->RemoveHunger(FoodValue);
		Character->UsageSound(ItemUsageSound);
		//Character->UsageSound(FoodUsageSound);
		Character->AnimationTimeUseDelay = AnimDelay;
		//Destroy();
	}
}