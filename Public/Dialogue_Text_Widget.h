// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Dialogue_Text_Widget.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API UDialogue_Text_Widget : public UUserWidget
{
	GENERATED_BODY()
		virtual bool Initialize();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* SizeBox_Dialogue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* Dialogue_Text;
	UFUNCTION()
		void SetText1(FString Questions1);
};
