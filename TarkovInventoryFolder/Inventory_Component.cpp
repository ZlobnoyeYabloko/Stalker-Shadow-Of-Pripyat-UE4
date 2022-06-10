// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory_Component.h"

// Sets default values
AInventory_Component::AInventory_Component()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>("Inventory Component 1");
}

// Called when the game starts or when spawned
void AInventory_Component::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventory_Component::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}