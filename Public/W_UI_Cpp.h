// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetSwitcher.h"
#include "GAME_FOR_OOP_KR/Public/W_InventoryItem_Cpp.h"
#include "GAME_FOR_OOP_KR/Public/My_UserWidget_Cpp.h"
#include "GAME_FOR_OOP_KR/Public/W_Crosshair_Cpp.h"
#include "GAME_FOR_OOP_KR/Public/Dialogue_Widget_Cpp.h"
#include "W_UI_Cpp.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API UW_UI_Cpp : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Widget")
		class UMy_UserWidget_Cpp* UserInterface;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta = (BindWidget))
		class UWidgetSwitcher* WidgetSwitcher_1;
	SWidgetSwitcher* Widget2;
	UPROPERTY(EditAnywhere)
		APlayerController* PController;
	UPROPERTY(EditAnywhere) 
		TSubclassOf<UUserWidget> widgetBlackLines;
	UPROPERTY(EditAnywhere)
		UUserWidget* widgetBlackLinesInstance;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UMy_UserWidget_Cpp* W_Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UW_Crosshair_Cpp* W_Crosshair;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	//	UDialogue_Widget_Cpp* W_DialogueWidget;

public:
	UFUNCTION(BlueprintCallable)
		void Crosshair();
	UFUNCTION(BlueprintCallable)
		void Inventory();
	UFUNCTION(BlueprintCallable)
		void Dialogue();
	UFUNCTION(BlueprintCallable)
		void Shop();
	UFUNCTION(BlueprintCallable)
		void MenuWidget();
	UFUNCTION(BlueprintCallable)
		void SetSingleShots1();
	UFUNCTION(BlueprintCallable)
		void SetAutoShots1();
	UFUNCTION(BlueprintCallable, Category = "Update Crosshair Widget")
		void UpdateCrosshairHealthBar(float value);
	UFUNCTION(BlueprintCallable, Category="Update Crosshair Widget")
		void UpdateCrosshairStaminaBar(float value);
	UFUNCTION(BlueprintCallable, Category = "Update Crosshair Widget")
		void UpdateInventoryHealthBar(float value);
	UFUNCTION(BlueprintCallable, Category = "Update Crosshair Widget")
		void UpdateCroshairReleasedAmmo(float value);
	UFUNCTION(BlueprintCallable, Category = "Update Crosshair Widget")
		void UpdateCroshairWeaponAmmo(float value);
};
