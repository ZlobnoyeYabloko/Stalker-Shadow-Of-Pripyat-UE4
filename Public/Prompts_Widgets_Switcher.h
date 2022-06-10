// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Prompts_Widgets_Switcher.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API UPrompts_Widgets_Switcher : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;
public:
	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* WidgetSwitcher_1;
	UFUNCTION(BlueprintCallable)
		void Set_Null_Widget();
	UFUNCTION(BlueprintCallable)
		void Item_Prompt_Widget();
	UFUNCTION(BlueprintCallable)
		void Door_Prompt_Widget();
	UFUNCTION(BlueprintCallable)
		void Dialog_Prompt_Widget();
	UFUNCTION(BlueprintCallable)
		void Helicopter_Prompt_Widget();
};
