// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Math/Vector2D.h"
#include "Inventory_Tarkov_Struct_Tile.generated.h"

USTRUCT(BlueprintType)
struct FTarkov_Items_Tile_Data
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		int32 X;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		int32 Y;
};
