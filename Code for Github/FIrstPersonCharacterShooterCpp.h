// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/TimelineComponent.h"
#include "GAME_FOR_OOP_KR/Public/BaseWeapon_1.h"
#include "GAME_FOR_OOP_KR/Inventory/Inventory.h"
#include "GAME_FOR_OOP_KR/Doors/Door.h"
#include "Blueprint/UserWidget.h"
#include "UObject/SoftObjectPtr.h"
#include "Runtime/Engine/Public/Net/UnrealNetwork.h"
#include "GAME_FOR_OOP_KR/Public/W_InventoryItem_Cpp.h"
#include "GAME_FOR_OOP_KR/Public/W_UI_Cpp.h"
#include "GAME_FOR_OOP_KR/Public/My_UserWidget_Cpp.h"
#include "GAME_FOR_OOP_KR/Public/W_Crosshair_Cpp.h"
#include "GAME_FOR_OOP_KR/Public/NPC_TEST.h"
#include "GAME_FOR_OOP_KR/ForQuests/Helicopter_1.h"
#include "GAME_FOR_OOP_KR/ForQuests/Helicopter_2.h"
#include "GAME_FOR_OOP_KR/ForQuests/Documents.h"
#include "GAME_FOR_OOP_KR/SaveGames/SaveGameInstance.h"
#include "GAME_FOR_OOP_KR/SaveGames/MySaveGame_Cpp.h"
#include "GAME_FOR_OOP_KR/ItemTest/Item_Test.h"
#include "GAME_FOR_OOP_KR/ItemTest/Ammo_m16.h"
#include "GAME_FOR_OOP_KR/Public/Subtitle_Struct.h"
#include "GAME_FOR_OOP_KR/Public/Prompts_Widgets_Switcher.h"
#include "Components/SpotLightComponent.h"
#include "GAME_FOR_OOP_KR/TarkovInventoryFolder/Items/Interactable_Interface_1.h"
#include "FIrstPersonCharacterShooterCpp.generated.h"//должно быть в самом низу

class AItem_Test;
class ANPC_TEST;
class AHelicopter_1;

UCLASS()
class GAME_FOR_OOP_KR_API AFIrstPersonCharacterShooterCpp : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "Widget")
		class UMy_UserWidget_Cpp* Inventory_AddItem_Widget;
	UPROPERTY(EditAnywhere, Category = "Widget")
		class UW_UI_Cpp* W_UI_1;
	UPROPERTY(EditAnywhere, Category = "Widget")
		class UMy_UserWidget_Cpp* W_Inventory_1;
	UPROPERTY(VisibleAnywhere, Category = "Widget")
		class TSubclassOf<class UW_InventoryItem_Cpp> WidgetClass_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="W_UI_Widget")
		class UW_UI_Cpp* W_UI_Widget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UUserWidget> W_UI_User_Widget;
	UPROPERTY(EditAnywhere)
		class UW_InventoryItem_Cpp* W_Inventory_Item_2;
	UPROPERTY(EditAnywhere)
		class TSubclassOf<UUserWidget> W_Inventory_Item_Widget;
	UPROPERTY(EditAnywhere)
		class UW_Crosshair_Cpp* W_Crosshair_1;
	UPROPERTY(EditAnywhere)
		class TSubclassOf<UUserWidget> W_Crosshair_Widget;
	UPROPERTY(VisibleAnywhere)
		class AAmmo_m16* AmmoM16;
	bool thisIsNPC;
	UPROPERTY(EditAnywhere)
		class UPrompts_Widgets_Switcher* Prompt_Widget_Switcher1;
	UPROPERTY(EditAnywhere)
		class TSubclassOf<UUserWidget> Prompt_Widget_Switcher1_Class;
	UPROPERTY(EditDefaultsOnly)
		class USpotLightComponent* FlashLight;

	UFUNCTION(BlueprintCallable)
		void SaveGame_1();
	UFUNCTION(BlueprintCallable)
		void LoadGame_1();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMySaveGame_Cpp* SaveGame_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Dead_1;

	UFUNCTION(BlueprintImplementableEvent)
		void DeadWidgetSetup();
	UFUNCTION(BlueprintImplementableEvent)
		void GameEnd();

	void TurnOnOffFlashlight();

	//for quest//
	UPROPERTY(EditDefaultsOnly)
		bool Helicopter1Quest;
	UPROPERTY(EditDefaultsOnly)
		bool Helicopter2Quest;
	UPROPERTY(EditDefaultsOnly)
		bool DocumentsQuest;

	UFUNCTION()
		void QuestComplete();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool InSight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool shotting;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool shottingInSight;
	UFUNCTION()
		void CheckIfShootInSight();
	UFUNCTION()
		bool GetShootInSight();
	UFUNCTION()
		void SetShootInSight(bool InSight_1);
	float TurnOnOff;
	UFUNCTION()
		void AddAmmoFromUse(float value);
	UFUNCTION()
		float GetAmmoInPockets();
public:
	// Sets default values for this character's properties
	AFIrstPersonCharacterShooterCpp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void JumpingCheck();
	void StopJumpingCheck();
	void AddingStaminaAfterStopJumping();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool jumping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanInteractQuest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bool")
		float DialogueWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bool")
		bool WeInDialogue;
	UFUNCTION(BlueprintImplementableEvent)
		void QuestComplete_1();
	UFUNCTION(BlueprintImplementableEvent)
		void QuestComplete_2();
	UFUNCTION(BlueprintImplementableEvent)
		void QuestComplete_3();
	FTimerHandle JumpStaminaPlusDelay;
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* HandsMesh;
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* GunMesh;
	UFUNCTION()
		void DealDamage(float value);
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void UpdateW_Ui_Widget(float value);
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void UpdateW_Ui_WidgetHealth(float value);
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void UpdateInventoryHealth(float value);

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void SetCrosshairWidget();
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void SetInventoryWidget();

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void SetDialogueWidget();

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void UpdateWeaponAmmo(float value);

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void UpdateReleasedWeaponAmmo(float value);

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void SetSingleShotWidget();
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void SetIAutoShotWidget();	

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class AArtifact* Artifact;
	void GetHandsMeshLocation();
public:
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* MuzzleLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = camera)
		class UCameraComponent* FirstPersonCamera;

	//////////////////////////////////////////////////////////////////////////
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float TurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float LookUpRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;
	UPROPERTY(EditDefaultsOnly, Category = "FireDelayTime")
		float DelayFireTime;
	UPROPERTY(EditDefaultsOnly, Category = "Ammo")
		float Ammo;
	UPROPERTY(EditDefaultsOnly, Category = "Ammo")
		float FullAk47Ammo;
	UPROPERTY(EditDefaultsOnly, Category = "Ammo")
		float AmmoInPockets;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Inventory Bool")
		bool InventoryOpenClosed;
	UPROPERTY(EditDefaultsOnly, Category = "FireBool")
		bool FireOrSingleShots;
	void UsageSound(USoundBase* UsageSoundItems2);

	UPROPERTY(EditDefaultsOnly, Category = "FireBool")
	float AnimationTimeUseDelay;

	UPROPERTY(EditAnywhere)
		class ADoor* CurrentDoor;
	UPROPERTY(EditAnywhere)
		class ANPC_TEST* Npc_Test;
	UPROPERTY(EditAnywhere)
		AHelicopter_1* Helictopter;
	UPROPERTY(EditAnywhere)
		class AHelicopter_2* Helictopter_1;
	UPROPERTY(EditAnywhere)
		class ADocuments* Documents;

	//Inventory Widgets
	UPROPERTY(EditAnywhere)
		class UUserWidget* Inventory_Promp_Widget;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget>  Inventory_Promp_Widget_Class;
	UPROPERTY(EditAnywhere)
		class UUserWidget* Croshair_Widget;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget>  Croshair_Widget_Class;
	//Stop Widget

public:
	UFUNCTION(BlueprintCallable, Category = "TestUseItem")
		void UseItem(TSubclassOf<AItem_Test> ItemSubclass, ANPC_TEST* OwningActor, bool IsShopItem=false);
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = References)
		AFIrstPersonCharacterShooterCpp* MyCharacter;

protected:

	void Inventory();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser);

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//	class APlayerController* MyController;

	void OnFire();
	void StopFire();
	void ThrowGrenade();
	void Fire();
	void ReloadWeapon();

	void FlipFlopShots();
	void SetHideAutoShootWidget();
	void SetHideSingleShootWidget();
	FTimerHandle HideAutoWidgetDelay;
	FTimerHandle HideSingleWidgetDelay;
	bool AutoWidget;
	bool SingleWidget;

	//UFUNCTION()
	//	void UpdateAmmo();
	void AnimationResetTimer();
	bool AnimationCompleteBool2;
	FTimerHandle AnimationTimeDelay2;

	float numberInventory;

	float FireSingleorAuto;


	bool bCanFire;
	bool WeaponFull;
	bool ReloadingWeaponSucced;
	bool WeaponReloading;
	void ReloadWeaponDelay();
	void ReloadingWeaponSucces();

	/* Delay time between shots */
	FTimerHandle FireDelayTimerHandle;
	FTimerHandle FireTimeHandle;
	FTimerHandle ReloadTimerDelay;
	FTimerHandle ReloadingTimerDelay;

	void ResetFire();
	UFUNCTION(BlueprintCallable)
		void Interact();
	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
		float DistanceToPickup;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void TurnAtRate(float Rate);
	void LookAtRate(float Rate);

	void Sprint();
	void StopSprinting();

	void Zoom();
	void StopZoom();

public:
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AProjectile> Projectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* UsageItemSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)	
		class UAnimMontage* FireAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimationInSight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimationInSightRifle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* PickUpAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* ReloadAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* ReloadAnimationEmpty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* ReloadAnimation2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* ReloadAnimation2Empty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FastThrowGrenadeAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* SprintAnimation;

	class UAnimInstance* AnimInstance;
	class UAnimInstance* AnimInstanceRifle;

	UPROPERTY()
		UW_InventoryItem_Cpp* UserInterface;

	class UWorld* World;

	FRotator SpawnRotation;
	FVector SpawnLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool isSprinting;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float FullHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float HealthPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
		float Stamina;

	FTimerHandle StaminaMinusDelay;
	bool CanSprint;
	bool Moving;
	void ReduceStamina();
	void AddingStamina();
	float GetStamina();
	void SetStamina(float value);
	FTimerHandle StaminaPlusDelay;
	bool Sprinting;

	//scripts for inventory
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void AddItemToInventoryWidget_1(FItems_Data ItemData, const TArray<FItems_Data>& CurrentInventory=TArray<FItems_Data>());//Add Item and update inventory widget
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Update")
		void AddItemToShopInventoryWidget_1(FItems_Data ItemData, const TArray<FItems_Data>& CurrentInventory = TArray<FItems_Data>());

	UFUNCTION(BlueprintCallable)
		int32 CurrentGold();
	UFUNCTION(BlueprintCallable)
		void RemoveGold(int32 amountToRemove);

	UFUNCTION()
		void UseRemoveItem(TSubclassOf<AItem_Test> ItemSubclass, bool UseItem, uint16 AmountToRemove=1);

	UFUNCTION(BlueprintImplementableEvent, Category="Inventory Widget Update")
		void UpdateInventoryWidget(const TArray<FItems_Data>& InventoryItems2);

	UFUNCTION(BlueprintImplementableEvent)
		void OpenShop(ANPC_TEST* Npc, const TArray<FItems_Data>& Items);
	//UFUNCTION(BlueprintImplementableEvent)
	//	void UpdateShop(const TArray<FItems_Data>& Items);

	UPROPERTY(ReplicatedUsing = OnRep_InventoryItems, EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		TArray<FItems_Data> InventoryItems;
	UFUNCTION()
		void OnRep_InventoryItems();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const override;
	void AddInventoryItem(FItems_Data ItemData);


	void AddHealth(float Value);
	void RemoveHunger(float Value);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Hunger;
	void DealDamage();
	float DamageValue2;

	bool bCanBeDamaged;
	/** Damage Timer */
	UFUNCTION()
		void DamageTimer();

	/** Set Damage State */
	UFUNCTION()
		void SetDamageState();
	struct FTimerHandle MemberTimerHandle;

protected:
	class UHealthComponent_Test* PlayerStats;//PlayerStatComp
};