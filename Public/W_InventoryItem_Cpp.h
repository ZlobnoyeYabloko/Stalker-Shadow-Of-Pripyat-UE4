// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/SizeBox.h"
#include "GAME_FOR_OOP_KR/Inventory/Inventory.h"
#include "Components/TextBlock.h"
#include "GAME_FOR_OOP_KR/ItemTest/Money_UA.h"
#include "Internationalization/Text.h"

#include "W_InventoryItem_Cpp.generated.h"//must on bottom

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API UW_InventoryItem_Cpp : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	virtual bool Initialize();

	UFUNCTION()
		void StartItemButtonClicked();

protected:
	float countHelp=0.0f;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* B_Item;
	UPROPERTY(EditAnywhere, meta = (BindWidget), BlueprintReadWrite)
		class UImage* I_Item;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), BlueprintReadWrite)
		class USizeBox* SizeBox_Items;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
		class UTextBlock* ItemsStackTextBlock;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", Meta=(ExposeOnSpawn = true))
		FItems_Data ItemDatas;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool NotGold=true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool InShop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ANPC_TEST* Npc;
	UFUNCTION()
		bool GetBool1();
	UFUNCTION()
		bool GetIsGold();

	//For shop transfer items
	UFUNCTION(BlueprintCallable)
		void SetInShop(bool Bool, ANPC_TEST* Npc_1);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool inShop_1;
	UFUNCTION(BlueprintCallable)
		ANPC_TEST* GetNpc_1();
	UFUNCTION(BlueprintImplementableEvent)
		void GetName();


	void SetItemData(FItems_Data ItemData);
	void UpdateStackCount(FItems_Data ItemData);
	void DisableButton();
	void EnableButton();
	UFUNCTION()
		FItems_Data GetItemData();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 value=1;
	void SetNewAndUpdateItemData(FItems_Data ItemData);
};
