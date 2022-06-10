// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Math/Vector2D.h"
#include "Inventory_Tarkov_Struct.generated.h"

USTRUCT(BlueprintType)
struct FTarkov_Items_Data
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FVector2D Start;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FVector2D End;
};
