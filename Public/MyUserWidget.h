// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
		virtual bool Initialize();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UWrapBox* WrapItemBox;
	//UPROPERTY(meta = (BindWidget))
	//class USizeBox* SizeBox_Items;
	UPROPERTY(meta = (BindWidget))
		class UImage* ImageBox;
};
