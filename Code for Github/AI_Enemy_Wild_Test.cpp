// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Enemy_Wild_Test.h"

// Sets default values
AAI_Enemy_Wild_Test::AAI_Enemy_Wild_Test()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_Enemy_Wild_Test::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_Enemy_Wild_Test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Enemy_Wild_Test::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

