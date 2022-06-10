// Fill out your copyright notice in the Description page of Project Settings.


#include "W_Crosshair_Cpp.h"

void UW_Crosshair_Cpp::NativeConstruct()
{
	Super::NativeConstruct();
}

void UW_Crosshair_Cpp::SetSingleShots()
{
	int value = 1;
	autoOrSingleFireRateTextBlock->SetText(FText::AsNumber(value));
	UE_LOG(LogTemp, Warning, TEXT("1"));
}

void UW_Crosshair_Cpp::SetAutoShots()
{
	//string name = "A";
	autoOrSingleFireRateTextBlock->SetText(FText::FromString("A"));
	UE_LOG(LogTemp, Warning, TEXT("A"));
}

void UW_Crosshair_Cpp::UpdateHealthBar(float Health2)
{
	float Health3 = Health2 / 100;
	Health->SetPercent(Health3);
}

void UW_Crosshair_Cpp::UpdateStaminaBar(float Stamina2)
{
	float Stamina3 = Stamina2 / 100;
	Stamina->SetPercent(Stamina3);
}
void UW_Crosshair_Cpp::UpdateReleasedAmmo(float value)
{
	ReleasedAmmo->SetText(FText::AsNumber(value));
}
void UW_Crosshair_Cpp::UpdateAmmoInWeapon(float value)
{
	AmmoInWeapon->SetText(FText::AsNumber(value));
}