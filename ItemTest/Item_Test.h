// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAME_FOR_OOP_KR/Inventory/Inventory.h"
#include "GAME_FOR_OOP_KR/Public/Interactable_Interface.h"
#include "Item_Test.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API AItem_Test : public AActor, public IInteractable_Interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem_Test();

protected:
	UPROPERTY(EditDefaultsOnly, Category="Mesh")
		class UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere, Category = "Mesh")
		FItems_Data ItemData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* ItemUsageSound;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Interact(class AFIrstPersonCharacterShooterCpp* Character) override;
	FItems_Data GetItemData() const { return ItemData; }
	virtual void Use(class AFIrstPersonCharacterShooterCpp* Character, bool isInShop = false) override;
};
