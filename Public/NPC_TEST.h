// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GAME_FOR_OOP_KR/Public/Subtitle_Struct.h"
#include "GAME_FOR_OOP_KR/Public/Interactable_Interface.h"
#include "GAME_FOR_OOP_KR/Inventory/Inventory.h"
#include "NPC_TEST.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API ANPC_TEST : public ACharacter, public IInteractable_Interface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC_TEST();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Interact(class AFIrstPersonCharacterShooterCpp* Character) override;
	void TransfferedItem(TSubclassOf<AItem_Test> ItemSubclass);

	UPROPERTY(ReplicatedUsing= OnRep_Items, EditAnywhere, BlueprintReadWrite)
		TArray<FItems_Data> Items;
	UFUNCTION()
		void OnRep_Items();

	bool CanBuyItem(int32 CurrentGold, TSubclassOf<AItem_Test> ItemSubclass);
	bool BuyItem(class AFIrstPersonCharacterShooterCpp* Character, TSubclassOf<AItem_Test> ItemSubclass);

	//UPROPERTY(EditAnywhere, Category = "ItemData")
	//	FItems_Data ItemData;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const override;

	UFUNCTION(BlueprintImplementableEvent)
		void Interacting();
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SkelComp;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* NpcMesh;
};
