// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Door.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API ADoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* DoorFrame;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Door;
	UPROPERTY(EditAnywhere)
		UCurveFloat* DoorCurve;
	UFUNCTION()
		void ControlDoor();
	UFUNCTION()
		void ToggleDoor();
	UFUNCTION()
		void SetState();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class USoundBase* DoorBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class UAudioComponent* DoorSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class USoundBase* DoorCloseBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class UAudioComponent* DoorCloseSound;

	bool Open;
	bool ReadyState;
	float RotateValue;
	float CurveFloatValue;
	float TimelineValue;
	FRotator DoorRotation;
	UTimelineComponent* MyTimeline;
};