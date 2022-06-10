// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGrid_Widget.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanelSlot.h"
#include "InventoryComponent.h"
#include <Runtime/Core/Public/Misc/OutputDeviceNull.h>

void UInventoryGrid_Widget::NativeConstruct()
{
	Super::NativeConstruct();
}
void UInventoryGrid_Widget::Help()
{
	UE_LOG(LogTemp, Warning, TEXT("Weapon Reloaded Else Ifom"));
}