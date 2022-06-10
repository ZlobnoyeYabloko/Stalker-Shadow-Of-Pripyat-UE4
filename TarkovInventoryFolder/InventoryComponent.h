// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GAME_FOR_OOP_KR/TarkovInventoryFolder/Items/CPP_ItemObject.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_FOR_OOP_KR_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category="ColumnsInt")
		int32 ColumnsInt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "ColumnsInt")
		int32 RowsInt;
	UFUNCTION()
		int32 getColumnsInt();
	UFUNCTION()
		int32 getRowsInt();
	UFUNCTION()
		bool TryAddItem(class UCPP_ItemObject* ItemObject);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UCPP_ItemObject*> ItemObject1;
};
