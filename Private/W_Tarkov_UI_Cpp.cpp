// Fill out your copyright notice in the Description page of Project Settings.


#include "W_Tarkov_UI_Cpp.h"
#include "GAME_FOR_OOP_KR/Public/W_InventoryItem_Cpp.h"
#include "GAME_FOR_OOP_KR/FIrstPersonCharacterShooterCpp.h"
#include "GAME_FOR_OOP_KR/Public/My_UserWidget_Cpp.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
using namespace std;

void UW_Tarkov_UI_Cpp::NativeConstruct()
{
	Super::NativeConstruct();
	//widgetBlackLinesInstance = CreateWidget<UUserWidget>(GetWorld(), widgetBlackLines);
	//WidgetSwitcher_1->AddChild(widgetBlackLinesInstance);
}

void UW_Tarkov_UI_Cpp::Crosshair()
{
	WidgetSwitcher_1->SetActiveWidgetIndex(0);
	PController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	W_Crosshair->SetAutoShots();
	if (PController) {
		PController->SetInputMode(FInputModeGameOnly());
		PController->bShowMouseCursor = false;
		PController->bEnableClickEvents = false;
		PController->bEnableMouseOverEvents = false;
	}
}

void UW_Tarkov_UI_Cpp::Inventory()
{
	WidgetSwitcher_1->SetActiveWidgetIndex(1);
	PController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PController) {
		PController->SetInputMode(FInputModeGameOnly());
		PController->bShowMouseCursor = true;
		PController->bEnableClickEvents = true;
		PController->bEnableMouseOverEvents = true;
	}
}
void UW_Tarkov_UI_Cpp::SetSingleShots1()
{
	W_Crosshair->SetSingleShots();
}

void UW_Tarkov_UI_Cpp::SetAutoShots1()
{
	W_Crosshair->SetAutoShots();
}

void UW_Tarkov_UI_Cpp::UpdateCrosshairHealthBar(float value)
{
	W_Crosshair->UpdateHealthBar(value);
}

void UW_Tarkov_UI_Cpp::UpdateCrosshairStaminaBar(float value)
{
	W_Crosshair->UpdateStaminaBar(value);
}