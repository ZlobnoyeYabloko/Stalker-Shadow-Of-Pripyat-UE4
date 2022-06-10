// Fill out your copyright notice in the Description page of Project Settings.


#include "Documents.h"

// Sets default values
ADocuments::ADocuments()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Documents = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Documents Mesh"));
	Documents->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADocuments::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADocuments::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADocuments::Interact(AFIrstPersonCharacterShooterCpp* Character)
{
	if (Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("Interacting: %s"), *GetName());
		Destroy();
	}
}