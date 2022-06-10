// Fill out your copyright notice in the Description page of Project Settings.


#include "Item_Test.h"
#include "Components/StaticMeshComponent.h"
#include "GAME_FOR_OOP_KR/FIrstPersonCharacterShooterCpp.h"

// Sets default values
AItem_Test::AItem_Test()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem_Test::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem_Test::Interact(class AFIrstPersonCharacterShooterCpp* Character)
{
	if (Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("Interacting: %s"), *GetName());
		Character->AddInventoryItem(ItemData);
		Destroy();
	}
}

void AItem_Test::Use(AFIrstPersonCharacterShooterCpp* Character, bool isInShop)
{
	if (Character && isInShop)
	{
		Character->AddInventoryItem(ItemData);
		UE_LOG(LogTemp, Warning, TEXT("StackCount: %i"), Character->CurrentGold());
		//Character->UsageSound(ItemUsageSound);
	}
}
