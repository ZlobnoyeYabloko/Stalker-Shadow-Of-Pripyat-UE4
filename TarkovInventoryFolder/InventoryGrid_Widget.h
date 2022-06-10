// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/CanvasPanel.h"
#include "GAME_FOR_OOP_KR/TarkovInventoryFolder/InventoryComponent.h"
#include "Components/ActorComponent.h"
#include "Inventory_Tarkov_Struct.h"
#include "InventoryGrid_Widget.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API UInventoryGrid_Widget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget), BlueprintReadWrite)
		UBorder* GridBorder;
	UPROPERTY(EditAnywhere, meta = (BindWidget), BlueprintReadWrite)
		UCanvasPanel* GridCanvasPanel;
	UFUNCTION()
		void Help();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UInventoryComponent* InventoryComponent2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TileSize1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FTarkov_Items_Data> Line;
};
