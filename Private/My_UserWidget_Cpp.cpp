// Fill out your copyright notice in the Description page of Project Settings.


#include "My_UserWidget_Cpp.h"
#include "Components/Button.h"
#include "W_InventoryItem_Cpp.h"
#include "Components/WrapBox.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"

bool UMy_UserWidget_Cpp::Initialize()
{
	Super::Initialize();
	return true;
}

void UMy_UserWidget_Cpp::UpdateHealthBar1(float Health2)
{
	float Health3 = Health2 / 100;
	Health1->SetPercent(Health3);
}

void UMy_UserWidget_Cpp::RemoveItemFromImageBox(UUserWidget* Widget)
{
	WrapItemBox->RemoveChild(Widget);
	UE_LOG(LogTemp, Warning, TEXT("Delete child"));
}

bool UMy_UserWidget_Cpp::ShouldAddNewItem1(TArray<FItems_Data> InventoryItems)
{
	if (InventoryItems.Num() > TotalNumberItems1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void UMy_UserWidget_Cpp::SetNpc_1(ANPC_TEST* Npc_2)
{
	Npc_1 = Npc_2;
}
ANPC_TEST* UMy_UserWidget_Cpp::GetNpc_1()
{
	return Npc_1;
}
void UMy_UserWidget_Cpp::SetMoneyText(FItems_Data ItemData)
{
	if (ItemData.ItemClass == AMoney_UA::StaticClass()) {
		Money_1->SetText(FText::AsNumber(ItemData.StackCount));
	}
	if (ItemData.ItemClass == AMoney_UA::StaticClass()) {
		if (ItemData.StackCount == 0)
		{
			Money_1->SetText(FText::AsNumber(0));
		}
	}
}
bool UMy_UserWidget_Cpp::AddItemToWidget1(UUserWidget* UserWidget1, bool IsShopItem, class ANPC_TEST* Npc, FItems_Data ItemData)
{
	WrapItemBox->AddChildToWrapBox(UserWidget1);
	UE_LOG(LogTemp, Warning, TEXT("Add Item"));
	TotalNumberItems1+=1;
	SetNpc_1(Npc);
	SetMoneyText(ItemData);
	return IsShopItem;
}
void UMy_UserWidget_Cpp::Update1(TArray<FItems_Data> ItemData)
{
	bool Bool = ItemData.Num() < TotalNumberItems1;
	if (Bool)
	{
		UE_LOG(LogTemp, Warning, TEXT("Remove item"));
		RemoveItem1(ItemData);
	}
	else
	{
		for (FItems_Data& Item : ItemData)
		{
			for (auto Child : WrapItemBox->GetAllChildren())
			{
				W_Inventory_Item_2 = Cast<UW_InventoryItem_Cpp>(Child);
				//ItemDatas3.ItemClass = Inventory2->GetItemData().ItemClass;
				if (W_Inventory_Item_2->GetItemData().ItemClass == Item.ItemClass)
				{
					UE_LOG(LogTemp, Warning, TEXT("Updating"));
					W_Inventory_Item_2->UpdateStackCount(Item);
					SetMoneyText(Item);
					break;
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("No updating"));
				}
			}
		}
	}
}
void UMy_UserWidget_Cpp::RemoveItem1(TArray<FItems_Data> CurrentInventory)
{
	TotalNumberItems1-=1;
	for (auto Child : WrapItemBox->GetAllChildren())
	{
		W_Inventory_Item_2 = Cast<UW_InventoryItem_Cpp>(Child);
		for (FItems_Data& Item : CurrentInventory)
		{
			if (Item.ItemClass == W_Inventory_Item_2->GetItemData().ItemClass)
			{
				ItemIsInInventory1 = true;
				UE_LOG(LogTemp, Warning, TEXT("True"));
				SetMoneyText(Item);
				break;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("False"));
			}
		}
		if (ItemIsInInventory1)
		{
			UE_LOG(LogTemp, Warning, TEXT("2"));
			ItemIsInInventory1 = false;
		}
		else if (ItemIsInInventory1 != true)
		{
			UE_LOG(LogTemp, Warning, TEXT("Disable Button"));
			W_Inventory_Item_2->DisableButton();
			ItemIsInInventory1 = false;
		}

	}
}