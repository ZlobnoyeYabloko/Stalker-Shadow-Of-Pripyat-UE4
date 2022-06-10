// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent_Test.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_FOR_OOP_KR_API UHealthComponent_Test : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent_Test();

protected:

	float Hunger;
	UPROPERTY(EditAnywhere, Category="Survival Stats")
		float HungerDecrementValue;

	float Thirst;
	UPROPERTY(EditAnywhere, Category = "Survival Stats")
		float ThirstDecrementValue;

	FTimerHandle TimerHandle;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void HandleHungerAndThirst();
public:
	void LowerHunger(float Value);
	void LowerThirst(float Value);
};
