// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_TEST.h"
#include "..\Public\NPC_TEST.h"
#include <GAME_FOR_OOP_KR/Public/Dialog_Struct_Cpp1.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include <Runtime/Engine/Public/Net/UnrealNetwork.h>

// Sets default values
ANPC_TEST::ANPC_TEST()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Skeletal case
	NpcMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Npc Mesh"));
	NpcMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ANPC_TEST::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ANPC_TEST::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANPC_TEST::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANPC_TEST::Interact(AFIrstPersonCharacterShooterCpp* Character)
{
	if (Character)
	{
		Character->OpenShop(this,Items);
		Interacting();
	}
}

void ANPC_TEST::TransfferedItem(TSubclassOf<AItem_Test> ItemSubclass)
{
	uint8 Index = 0;
	for (FItems_Data& Item : Items)
	{
		if (Item.ItemClass == ItemSubclass)
		{
			--Item.StackCount;
			if (Item.StackCount <= 0)
			{
				Items.RemoveAt(Index);
			}
			break;
		}
		++Index;
	}
	OnRep_Items();
}

void ANPC_TEST::OnRep_Items()
{
	if (AFIrstPersonCharacterShooterCpp* Character=Cast<AFIrstPersonCharacterShooterCpp>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)))
	{
		Character->OpenShop(this, Items);
	}
}

bool ANPC_TEST::CanBuyItem(int32 CurrentGold, TSubclassOf<AItem_Test> ItemSubclass)
{
	for (FItems_Data& Item : Items)
	{
		if (Item.ItemClass == ItemSubclass)
		{
			return CurrentGold >= Item.ItemCost;
		}
	}
	return false;
}
bool ANPC_TEST::BuyItem(AFIrstPersonCharacterShooterCpp* Character, TSubclassOf<AItem_Test> ItemSubclass)
{
	if (Character && ItemSubclass)
	{
		for (FItems_Data& Item : Items)
		{
			if (Item.ItemClass == ItemSubclass)
			{
				if(CanBuyItem(Character->CurrentGold(), ItemSubclass))
				{
					if (AItem_Test* ItemCDO = ItemSubclass.GetDefaultObject())
					{
						ItemCDO->Use(Character, true);
						Character->RemoveGold(Item.ItemCost);
						TransfferedItem(ItemSubclass);
						return true;
					}
				}
			}
		}
	}
	return false;
}
void ANPC_TEST::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ANPC_TEST, Items);
}