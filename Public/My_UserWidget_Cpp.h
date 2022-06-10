// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_InventoryItem_Cpp.h"
#include "Components/WrapBox.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Internationalization/Text.h"
#include "My_UserWidget_Cpp.generated.h"

/**
 * 
 */
class ANPC_TEST;
UCLASS()
class GAME_FOR_OOP_KR_API UMy_UserWidget_Cpp : public UUserWidget
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
		UPROPERTY(EditAnywhere)
			TSubclassOf<UUserWidget> ItemWidgetTest;
		UPROPERTY(EditAnywhere)
			class UW_InventoryItem_Cpp* W_Inventory_Item_2;
		UPROPERTY(EditAnywhere)
			TSubclassOf<UUserWidget> W_Inventory_Item_Widget;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UProgressBar* Health1;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* Money_1;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Data2")
			FItems_Data ItemDatas3;
		UPROPERTY(EditAnywhere)
			class TSubclassOf<UUserWidget> W_Inventory_Item_Widget1;
		UFUNCTION()
			void UpdateHealthBar1(float Health2);

		UFUNCTION()
			void SetMoneyText(FItems_Data ItemData);

		//UFUNCTION()
		//	void AddItemToImageBox(UUserWidget* Widget);
		//UFUNCTION()
		//	void Update(TArray<FItems_Data> InventoryItems);
		UFUNCTION(BlueprintImplementableEvent)
			void SetInShop1(bool Bool2, class ANPC_TEST* Npc);
		UFUNCTION()
			void RemoveItemFromImageBox(UUserWidget* Widget);
		UFUNCTION(BlueprintCallable)
			bool ShouldAddNewItem1(TArray<FItems_Data> InventoryItems);
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			class ANPC_TEST* Npc_1;

		UFUNCTION(BlueprintCallable)
			void SetNpc_1(ANPC_TEST* Npc_2);
		UFUNCTION(BlueprintCallable)
			ANPC_TEST* GetNpc_1();

		UPROPERTY(EditAnywhere)
			int32 TotalNumberItems1=0;
		UFUNCTION(BlueprintCallable)
			bool AddItemToWidget1(UUserWidget* UserWidget1, bool IsShopItem, class ANPC_TEST* Npc, FItems_Data ItemData);
		UFUNCTION(BlueprintCallable)
			void Update1(TArray<FItems_Data> ItemData);
		UFUNCTION()
			void RemoveItem1(TArray<FItems_Data> CurrentInventory);
		bool ItemIsInInventory1=false;
};
