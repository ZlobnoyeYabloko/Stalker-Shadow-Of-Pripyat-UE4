// Fill out your copyright notice in the Description page of Project Settings.


#include "Helicopter_2.h"

// Sets default values
AHelicopter_2::AHelicopter_2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Helicopter = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Helicopter Mesh1"));
	Helicopter->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHelicopter_2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHelicopter_2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHelicopter_2::Interact(AFIrstPersonCharacterShooterCpp* Character)
{
	if (Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("Interacting: %s"), *GetName());
	}
}