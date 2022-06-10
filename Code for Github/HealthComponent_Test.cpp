// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent_Test.h"
#include "TimerManager.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UHealthComponent_Test::UHealthComponent_Test()
{

	Hunger = 100.0f;
	HungerDecrementValue=0.3f;
	Thirst = 100.0f;	
	ThirstDecrementValue=0.5f;

}


// Called when the game starts
void UHealthComponent_Test::BeginPlay()
{
	Super::BeginPlay();
	SetIsReplicated(true);
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UHealthComponent_Test::HandleHungerAndThirst, 3.0f, true);

}

void UHealthComponent_Test::HandleHungerAndThirst()
{
	LowerHunger(HungerDecrementValue);
	LowerThirst(ThirstDecrementValue);

}

void UHealthComponent_Test::LowerThirst(float Value)
{
	Hunger -= Value;
}

void UHealthComponent_Test::LowerHunger(float Value)
{
	Thirst -= Value;
}