// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame_Cpp.h"

UMySaveGame_Cpp::UMySaveGame_Cpp()
{
	PlayerLocation = FVector(0.f, 0.f, 0.f);
	InventoryItems_1.Empty();
	ammoPockets = 0.0f;
	ammo = 0.0f;
	Health = 0.0f;
}