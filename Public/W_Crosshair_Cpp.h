// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"
#include "Components/ProgressBar.h"
#include "W_Crosshair_Cpp.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API UW_Crosshair_Cpp : public UUserWidget
{
	GENERATED_BODY()

		virtual void NativeConstruct() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta = (BindWidget))
		class UImage* Croshair_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Croshair_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UProgressBar* Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UProgressBar* Stamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* ReleasedAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* AmmoInWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* QuestTextSystem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* QuestTextSystem_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* QuestTextSystem_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Quest_Image_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Quest_Image_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Quest_Image_3;
public:
	UFUNCTION()
		void SetSingleShots();
	UFUNCTION()
		void SetAutoShots();
	UFUNCTION()
		void UpdateHealthBar(float Health2);
	UFUNCTION()
		void UpdateStaminaBar(float Stamina2);

	UFUNCTION()
		void UpdateReleasedAmmo(float value);
	UFUNCTION()
		void UpdateAmmoInWeapon(float value);
public:
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
		class UTextBlock* autoOrSingleFireRateTextBlock;
};
