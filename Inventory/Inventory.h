// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Inventory.generated.h"

USTRUCT(BlueprintType)
struct FItems_Data
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class AItem_Test> ItemClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		class UTexture2D* ItemImage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float ItemCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 StackCount=1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float X_int = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Y_int = 1.0f;
};
