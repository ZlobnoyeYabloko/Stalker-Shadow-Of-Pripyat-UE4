// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon_1.h"

// Sets default values
ABaseWeapon_1::ABaseWeapon_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	maxTotalAmmo = 100;
	maxClipAmmo = 30;
	totalAmmo = 64;
	clipAmmo = 12;
	reloadTime = 1.0f;
}

// Called when the game starts or when spawned
void ABaseWeapon_1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

