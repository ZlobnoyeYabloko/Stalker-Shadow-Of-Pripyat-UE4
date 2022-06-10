// Fill out your copyright notice in the Description page of Project Settings.


#include "Helicopter_1.h"

// Sets default values
AHelicopter_1::AHelicopter_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Helicopter = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Helicopter Mesh"));
	Helicopter->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHelicopter_1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHelicopter_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHelicopter_1::Interact(AFIrstPersonCharacterShooterCpp* Character)
{
	if (Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("Interacting: %s"), *GetName());
	}
}