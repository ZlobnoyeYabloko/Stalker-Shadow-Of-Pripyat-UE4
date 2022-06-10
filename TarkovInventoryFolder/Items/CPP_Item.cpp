// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Item.h"

// Sets default values
ACPP_Item::ACPP_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Item_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tarkov Static Mesh"));
	RootComponent = Item_Mesh;
}

// Called when the game starts or when spawned
void ACPP_Item::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACPP_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_Item::Interact1(AFIrstPersonCharacterShooterCpp* Character)
{
	
}