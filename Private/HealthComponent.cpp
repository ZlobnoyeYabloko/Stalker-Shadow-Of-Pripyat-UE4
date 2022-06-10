// Fill out your copyright notice in the Description page of Project Settings.



#include "HealthComponent.h"
#include "GAME_FOR_OOP_KR/FIrstPersonCharacterShooterCpp.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	DefaultHealth = 100.0f;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UHealthComponent::DealDamage_HP(float DamageValue)
{
	DefaultHealth -= DamageValue;
}
