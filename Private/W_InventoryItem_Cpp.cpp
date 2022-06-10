// Fill out your copyright notice in the Description page of Project Settings.


#include "W_InventoryItem_Cpp.h"//must be on top
#include "GAME_FOR_OOP_KR/Inventory/Inventory.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Engine/Texture2D.h"
#include "Internationalization/Text.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include <Runtime/Core/Public/Misc/OutputDeviceNull.h>

void UW_InventoryItem_Cpp::NativeConstruct()
{
	Super::NativeConstruct();
	I_Item->SetBrushFromTexture(ItemDatas.ItemImage);
	FVector2D hello;
	hello.X = GetItemData().X_int;
	hello.Y = GetItemData().Y_int;
	I_Item->SetRenderScale(hello);
	B_Item->SetVisibility(ESlateVisibility::Visible);
	ItemsStackTextBlock->SetText(FText::AsNumber(GetItemData().StackCount));
	ItemsStackTextBlock->SetVisibility(ESlateVisibility::Visible);
}
bool UW_InventoryItem_Cpp::Initialize()
{
	Super::Initialize();
	B_Item->OnClicked.AddDynamic(this, &UW_InventoryItem_Cpp::StartItemButtonClicked);
	return true;
}
void UW_InventoryItem_Cpp::StartItemButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Our button is working!"));
	AFIrstPersonCharacterShooterCpp* MyCharacter;
	if (GetBool1())
	{
		UE_LOG(LogTemp, Warning, TEXT("True 111111111111"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("False 222222222222222222222"));
	}
	MyCharacter = Cast<AFIrstPersonCharacterShooterCpp>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	MyCharacter->UseItem(ItemDatas.ItemClass, GetNpc_1(), GetBool1());
	if (GetNpc_1())
	{
		GetName();
	}
}
bool UW_InventoryItem_Cpp::GetBool1()
{
	return inShop_1;
}
bool UW_InventoryItem_Cpp::GetIsGold()
{
	return NotGold;
}
void UW_InventoryItem_Cpp::SetInShop(bool Bool, ANPC_TEST* Npc_1)
{
	inShop_1 = Bool;
	Npc = Npc_1;
}
ANPC_TEST* UW_InventoryItem_Cpp::GetNpc_1()
{
	return Npc;
}
void UW_InventoryItem_Cpp::SetItemData(FItems_Data ItemData)
{
	ItemDatas = ItemData;
	UE_LOG(LogTemp, Warning, TEXT("Stack Count =, %i"),ItemDatas.StackCount);
}
void UW_InventoryItem_Cpp::UpdateStackCount(FItems_Data ItemData)
{
	SetItemData(ItemData);

	if (GetItemData().StackCount > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Update stack count 1000, %d"), GetItemData().StackCount);
		ItemsStackTextBlock->SetText(FText::AsNumber(GetItemData().StackCount));
		UE_LOG(LogTemp, Warning, TEXT("Enable"));
		EnableButton();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Remove item !!!!!!!!!!!!!!!!!!"));
		DisableButton();
	}
}
void UW_InventoryItem_Cpp::DisableButton()
{
	//SizeBox_Items->SetVisibility(ESlateVisibility::Collapsed);
	//UE_LOG(LogTemp, Warning, TEXT("Dissable button !!!!!!!!!!!!!!"));
	//SetItemData(GetItemData());
	FOutputDeviceNull ar;
	CallFunctionByNameWithArguments(TEXT("DeleteButton"), ar, NULL, true);
}
void UW_InventoryItem_Cpp::EnableButton()
{
	SizeBox_Items->SetVisibility(ESlateVisibility::Visible);
	UE_LOG(LogTemp, Warning, TEXT("Enable button !!!!!!!!!!!!!!!!!!"));
	SetItemData(GetItemData());
}
FItems_Data UW_InventoryItem_Cpp::GetItemData()
{
	return ItemDatas;
}

void UW_InventoryItem_Cpp::SetNewAndUpdateItemData(FItems_Data ItemData)
{
	ItemDatas = ItemData;
	EnableButton();
}