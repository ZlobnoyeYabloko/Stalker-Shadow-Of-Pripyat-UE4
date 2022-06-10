// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetSwitcher.h"
#include "GAME_FOR_OOP_KR/Public/W_InventoryItem_Cpp.h"
#include "GAME_FOR_OOP_KR/FIrstPersonCharacterShooterCpp.h"
#include "GAME_FOR_OOP_KR/Public/My_UserWidget_Cpp.h"
#include "GAME_FOR_OOP_KR/Public/W_Crosshair_Cpp.h"
#include "GAME_FOR_OOP_KR/TarkovInventoryFolder/Tarkov_Inventory.h"
#include "W_Tarkov_UI_Cpp.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API UW_Tarkov_UI_Cpp : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

public:
	UPROPERTY(EditAnywhere, Category="Widget")
		class UTarkov_Inventory* UserInterface;
	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* WidgetSwitcher_1;
	SWidgetSwitcher* Widget2;
	UPROPERTY(EditAnywhere)
		APlayerController* PController;
	UPROPERTY(EditAnywhere) 
		TSubclassOf<UUserWidget> widgetBlackLines;
	UPROPERTY(EditAnywhere)
		UUserWidget* widgetBlackLinesInstance;
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UTarkov_Inventory* W_Inventory;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UW_Crosshair_Cpp* W_Crosshair;
public:
	UFUNCTION()
		void Crosshair();
	UFUNCTION()
		void Inventory();
	UFUNCTION()
		void SetSingleShots1();
	UFUNCTION()
		void SetAutoShots1();
	UFUNCTION()
		void UpdateCrosshairHealthBar(float value);
	UFUNCTION()
		void UpdateCrosshairStaminaBar(float value);
};
