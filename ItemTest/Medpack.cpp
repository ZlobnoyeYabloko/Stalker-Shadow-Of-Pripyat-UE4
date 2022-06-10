// Fill out your copyright notice in the Description page of Project Settings.


#include "Medpack.h"
#include "UObject/ConstructorHelpers.h"
#include "GAME_FOR_OOP_KR/FIrstPersonCharacterShooterCpp.h"
#include "Kismet/GameplayStatics.h"

AMedpack::AMedpack()
{
	HealthValue = 10.0f;
	AnimDelay = 3.0f;
}
void AMedpack::Use(AFIrstPersonCharacterShooterCpp* Character, bool isInShop)
{
	Super::Use(Character, isInShop);
	if (Character && !isInShop)
	{
		Character->AddHealth(HealthValue);
		Character->UsageSound(ItemUsageSound);
		Character->AnimationTimeUseDelay = AnimDelay;
		UE_LOG(LogTemp, Warning, TEXT("Health Added"));
	}
}