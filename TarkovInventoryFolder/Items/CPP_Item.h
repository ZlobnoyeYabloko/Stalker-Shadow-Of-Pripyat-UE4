// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Interactable_Interface_1.h"
#include "CPP_ItemObject.h"
#include "CPP_Item.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API ACPP_Item : public AActor, public IInteractable_Interface_1
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Item();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
		class UStaticMeshComponent* Item_Mesh;
	UFUNCTION()
		virtual void Interact1(class AFIrstPersonCharacterShooterCpp* Character) override;
};
