// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAME_FOR_OOP_KR/Inventory/Inventory.h"
#include "GAME_FOR_OOP_KR/Public/Interactable_Interface.h"
#include "Documents.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API ADocuments : public AActor, public IInteractable_Interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADocuments();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact(class AFIrstPersonCharacterShooterCpp* Character) override;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Documents;

};
