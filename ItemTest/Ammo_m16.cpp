// Fill out your copyright notice in the Description page of Project Settings.


#include "Ammo_m16.h"
AAmmo_m16::AAmmo_m16()
{
	ammoCount = GetItemData().StackCount;
}
void AAmmo_m16::UpdateAmmoCount(float value)
{
	ammoCount -= value;
}
float AAmmo_m16::GetAmmoCount()
{
	return ammoCount;
}