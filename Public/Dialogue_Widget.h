// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/WrapBox.h"
#include "Components/TextBlock.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
//#include "GAME_FOR_OOP_KR/Public/Subtitle_Struct.h"
//#include "GAME_FOR_OOP_KR/Public/Dialog_Struct_Cpp1.h"
#include "Dialogue_Widget.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API UDialogue_Widget : public UUserWidget
{
	GENERATED_BODY()
	
		virtual bool Initialize();
public:
	UPROPERTY(meta = (BindWidget))
		class UButton* MarketPlace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UWrapBox* WrapItemBox1;
	UPROPERTY(meta = (BindWidget))
		class UImage* ImageBox1;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextBlock1;

	UFUNCTION()
		void MarketButton();
};
