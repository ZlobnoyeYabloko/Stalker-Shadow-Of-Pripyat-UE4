// Fill out your copyright notice in the Description page of Project Settings.


#include "FIrstPersonCharacterShooterCpp.h"
#include "HealthComponent_Test.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Actor.h"
#include "Projectile.h"
#include "Animation/AnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "FirstPersonShooter_GameMode_CPP.h"
#include "Runtime/Engine/Public/Net/UnrealNetwork.h"
#include "Engine/GameInstance.h"

// Sets default values
AFIrstPersonCharacterShooterCpp::AFIrstPersonCharacterShooterCpp()
{
	GetCapsuleComponent()->InitCapsuleSize(40.0f, 95.0f);
	TurnRate = 45.0f;
	LookUpRate = 45.0f;
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->AddRelativeLocation(FVector(-39.65f, 1.75f, 64.0f));
	FirstPersonCamera->bUsePawnControlRotation = true;
	HandsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Character Mesh"));
	HandsMesh->SetOnlyOwnerSee(true);
	HandsMesh->SetupAttachment(FirstPersonCamera);
	HandsMesh->bCastDynamicShadow = false;
	HandsMesh->CastShadow = false;
	HandsMesh->AddRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	HandsMesh->AddRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	GunMesh->SetOnlyOwnerSee(true);
	GunMesh->bCastDynamicShadow = false;
	GunMesh->CastShadow = false;
	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle Location"));
	MuzzleLocation->SetupAttachment(GunMesh);
	MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));
	GunOffset = FVector(100.0f, 0.0f, 10.0f);
	PlayerStats = CreateDefaultSubobject<UHealthComponent_Test>("PlayerStatComponent");
	FlashLight= CreateDefaultSubobject<USpotLightComponent>("Player Flashlight");
	FlashLight->SetupAttachment(FirstPersonCamera);
	FlashLight->SetHiddenInGame(true);

	TurnOnOff = 0;

	isSprinting = false;
	bCanFire = true;
	DelayFireTime = 1.0f;
	FullAk47Ammo = 5.0f;
	WeaponFull = true;
	ReloadingWeaponSucced = true;
	WeaponReloading = false;
	AmmoInPockets = 120;
	DistanceToPickup = 100.0f;
	InventoryOpenClosed = false;
	Health = 90.0f;
	Hunger = 100.0f;
	FireOrSingleShots = false;
	AnimationCompleteBool2 = true;
	AnimationTimeUseDelay = 0.01f;
	DamageValue2 = 10.0f;
	CurrentDoor = NULL;

	numberInventory = 0;

	FireSingleorAuto = 0;
	Stamina = 100.0f;
	CanSprint = true;
	Moving = false;
	Sprinting = false;
	jumping = false;
	thisIsNPC = false;
	DialogueWidget = 0;
	WeInDialogue = false;
	Helicopter1Quest = false;
	InSight = false;
	shotting = false;
	shottingInSight = false;
	CanInteractQuest = false;
	Helicopter2Quest = false;
	DocumentsQuest = false;
	Dead_1 = false;
}
// Called when the game starts or when spawned
void AFIrstPersonCharacterShooterCpp::BeginPlay()
{
	Super::BeginPlay();

	bCanBeDamaged = true;
	GunMesh->AttachToComponent(HandsMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("R_GunSocket"));

	World = GetWorld();

	AnimInstance = HandsMesh->GetAnimInstance();
	AnimInstanceRifle = GunMesh->GetAnimInstance();

	Ammo = FullAk47Ammo;

	if (Prompt_Widget_Switcher1_Class)
	{
		Prompt_Widget_Switcher1 = CreateWidget<UPrompts_Widgets_Switcher>(GetWorld(), Prompt_Widget_Switcher1_Class);
		if (Prompt_Widget_Switcher1)
		{
			Prompt_Widget_Switcher1->AddToViewport();
		}
	}

	UpdateReleasedWeaponAmmo(AmmoInPockets);
	UpdateWeaponAmmo(Ammo);
	for (int i = 0; i < InventoryItems.Num(); i++) {
		if (InventoryItems.Num())
		{
			AddItemToInventoryWidget_1(InventoryItems[i], InventoryItems);
			AddItemToShopInventoryWidget_1(InventoryItems[i], InventoryItems);
		}
	}
}
void AFIrstPersonCharacterShooterCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult Hit;
	FCollisionQueryParams CollisionParams;
	FVector Start = FirstPersonCamera->GetComponentLocation();

	FVector ForwardVector = FirstPersonCamera->GetForwardVector();
	FVector End = (ForwardVector * 200.0f) + Start;
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, CollisionParams))
	{
		if (Hit.bBlockingHit)
		{
			if (Hit.GetActor()->GetClass()->IsChildOf(ADoor::StaticClass()))
			{
				Prompt_Widget_Switcher1->Door_Prompt_Widget();
				CurrentDoor = Cast<ADoor>(Hit.GetActor());
			}
			else
			{
				CurrentDoor = NULL;
			}
			if (Hit.GetActor()->GetClass()->IsChildOf(ANPC_TEST::StaticClass()) && WeInDialogue != true && InventoryOpenClosed!=true )
			{
				Prompt_Widget_Switcher1->Dialog_Prompt_Widget();
				Npc_Test = Cast<ANPC_TEST>(Hit.GetActor());
			}
			else
			{
				Npc_Test = NULL;
			}
			if (Hit.GetActor()->GetClass()->IsChildOf(AItem_Test::StaticClass()))
			{
				Prompt_Widget_Switcher1->Item_Prompt_Widget();
			}
			if (Hit.GetActor()->GetClass()->IsChildOf(AHelicopter_1::StaticClass()) && WeInDialogue != true && InventoryOpenClosed != true && Helicopter1Quest!=true)
			{
				Prompt_Widget_Switcher1->Helicopter_Prompt_Widget();
				Helictopter = Cast<AHelicopter_1>(Hit.GetActor());
			}
			if (Hit.GetActor()->GetClass()->IsChildOf(AHelicopter_2::StaticClass()) && WeInDialogue != true && InventoryOpenClosed != true && Helicopter2Quest != true)
			{
				Prompt_Widget_Switcher1->Helicopter_Prompt_Widget();
				Helictopter_1 = Cast<AHelicopter_2>(Hit.GetActor());
			}
			if (Hit.GetActor()->GetClass()->IsChildOf(ADocuments::StaticClass()) && WeInDialogue != true && InventoryOpenClosed != true && DocumentsQuest != true)
			{
				Prompt_Widget_Switcher1->Item_Prompt_Widget();
				Documents = Cast<ADocuments>(Hit.GetActor());
			}
			if(!Hit.GetActor()->GetClass()->IsChildOf(AItem_Test::StaticClass()) && !Hit.GetActor()->GetClass()->IsChildOf(ADoor::StaticClass()) && !Hit.GetActor()->GetClass()->IsChildOf(ANPC_TEST::StaticClass()) && !Hit.GetActor()->GetClass()->IsChildOf(ADocuments::StaticClass())  && !Hit.GetActor()->GetClass()->IsChildOf(AHelicopter_1::StaticClass()) && !Hit.GetActor()->GetClass()->IsChildOf(AHelicopter_2::StaticClass()) || WeInDialogue)
			{
				Prompt_Widget_Switcher1->Set_Null_Widget();
			}
		}
		else
		{
			Prompt_Widget_Switcher1->Set_Null_Widget();
		}
	}
	else
	{
		Prompt_Widget_Switcher1->Set_Null_Widget();
		Npc_Test = NULL;
		CurrentDoor = NULL;
		Helictopter = NULL;
		Helictopter_1 = NULL;
		Documents = NULL;
	}
}

void AFIrstPersonCharacterShooterCpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::JumpingCheck);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFIrstPersonCharacterShooterCpp::StopJumpingCheck);
	
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFIrstPersonCharacterShooterCpp::StopSprinting);
			
	//Bind fire events
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::OnFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AFIrstPersonCharacterShooterCpp::StopFire);
	PlayerInputComponent->BindAction("Fast Grenade", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::ThrowGrenade);

	PlayerInputComponent->BindAction("Single", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::FlipFlopShots);

	PlayerInputComponent->BindAction("Zoom", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::Zoom);
	PlayerInputComponent->BindAction("Zoom", IE_Released, this, &AFIrstPersonCharacterShooterCpp::StopZoom);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::ReloadWeapon);
	PlayerInputComponent->BindAction("Pickup", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::Interact);
	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::Inventory);

	PlayerInputComponent->BindAction("SaveGame", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::SaveGame_1);
	PlayerInputComponent->BindAction("LoadGame", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::LoadGame_1);

	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AFIrstPersonCharacterShooterCpp::ReloadWeapon);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFIrstPersonCharacterShooterCpp::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFIrstPersonCharacterShooterCpp::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AFIrstPersonCharacterShooterCpp::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &AFIrstPersonCharacterShooterCpp::LookAtRate);
}
void AFIrstPersonCharacterShooterCpp::SaveGame_1()
{
	SaveGame_2 = Cast<UMySaveGame_Cpp>(UGameplayStatics::CreateSaveGameObject(UMySaveGame_Cpp::StaticClass()));
	SaveGame_2->PlayerLocation = this->GetActorLocation();
	SaveGame_2->InventoryItems_1 = InventoryItems;
	SaveGame_2->ammoPockets = AmmoInPockets;
	SaveGame_2->ammo = Ammo;
	SaveGame_2->Health = Health;
	UGameplayStatics::SaveGameToSlot(SaveGame_2, TEXT("MySlot"),0);
}
void AFIrstPersonCharacterShooterCpp::LoadGame_1()
{
	SaveGame_2 = Cast<UMySaveGame_Cpp>(UGameplayStatics::CreateSaveGameObject(UMySaveGame_Cpp::StaticClass()));
	SaveGame_2 = Cast<UMySaveGame_Cpp>(UGameplayStatics::LoadGameFromSlot("MySlot", 0));
	this->SetActorLocation(SaveGame_2->PlayerLocation);
	InventoryItems = SaveGame_2->InventoryItems_1;
	AmmoInPockets=SaveGame_2->ammoPockets;
	Ammo=SaveGame_2->ammo;
	Health = SaveGame_2->Health;
	OnRep_InventoryItems();
	UpdateReleasedWeaponAmmo(AmmoInPockets);
	UpdateWeaponAmmo(Ammo);
	UpdateW_Ui_WidgetHealth(Health);
	UpdateInventoryHealth(Health);
}
void AFIrstPersonCharacterShooterCpp::TurnOnOffFlashlight()
{
	TurnOnOff++;
	if (TurnOnOff == 1)
	{
		FlashLight->SetHiddenInGame(false);
	}
	if (TurnOnOff == 2)
	{
		FlashLight->SetHiddenInGame(true);
		TurnOnOff = 0;
	}
}
void AFIrstPersonCharacterShooterCpp::Zoom()
{
	if (InventoryOpenClosed != true && Sprinting != true) {
		if (auto firstPersonCamera = FirstPersonCamera)
		{
			InSight = true;
			CheckIfShootInSight();
			firstPersonCamera->SetFieldOfView(50.0f);
		}
	}
}

void AFIrstPersonCharacterShooterCpp::StopZoom()
{
	if (InventoryOpenClosed != true) {
		if (auto firstPersonCamera = FirstPersonCamera)
		{
			InSight = false;
			CheckIfShootInSight();
			firstPersonCamera->SetFieldOfView(90.0f);
		}
	}
}
void AFIrstPersonCharacterShooterCpp::JumpingCheck()
{
	if (GetStamina() >= 1) {
		Jump();
		float value = GetStamina() - 1;
		SetStamina(value);
		//W_UI_Widget->UpdateCrosshairStaminaBar(value);
		UpdateW_Ui_Widget(value);
		jumping = true;
	}
}
void AFIrstPersonCharacterShooterCpp::StopJumpingCheck()
{
	StopJumping();
	GetWorldTimerManager().SetTimer(JumpStaminaPlusDelay, this, &AFIrstPersonCharacterShooterCpp::AddingStaminaAfterStopJumping, 1.0f, false, 1.0f);
}
void AFIrstPersonCharacterShooterCpp::AddingStaminaAfterStopJumping()
{
	jumping = false;
	float value = GetStamina() + 1;
	SetStamina(value);
	//W_UI_Widget->UpdateCrosshairStaminaBar(value);
	UpdateW_Ui_Widget(value);
	GetWorldTimerManager().ClearTimer(JumpStaminaPlusDelay);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float AFIrstPersonCharacterShooterCpp::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	bCanBeDamaged = false;
	Health -= DamageAmount;
	UpdateW_Ui_WidgetHealth(Health);
	UpdateInventoryHealth(Health);
	if (Health <= 0.0f)
	{
		DeadWidgetSetup();
		Destroy();
	}
	DamageTimer();
	return DamageAmount;
}
void AFIrstPersonCharacterShooterCpp::DealDamage(float value)
{
	Health -= value;
	//W_UI_Widget->UpdateCrosshairHealthBar(Health);
	UpdateW_Ui_WidgetHealth(Health);
	UpdateInventoryHealth(Health);
	if (Health <= 0.0f)
	{
		Dead_1 = true;
		DeadWidgetSetup();
		Destroy();
	}
	
}
void AFIrstPersonCharacterShooterCpp::DealDamage()
{
	Health -= DamageValue2;
	UpdateW_Ui_WidgetHealth(Health);
	UpdateInventoryHealth(Health);
}
void AFIrstPersonCharacterShooterCpp::GetHandsMeshLocation()
{
	FVector Position = GetActorLocation();
}
void AFIrstPersonCharacterShooterCpp::QuestComplete()
{
	if (Helicopter1Quest)
	{
		Prompt_Widget_Switcher1->Set_Null_Widget();
		QuestComplete_1();
	}
	if (Helicopter2Quest)
	{
		Prompt_Widget_Switcher1->Set_Null_Widget();
		QuestComplete_2();
	}
	if (DocumentsQuest)
	{
		Prompt_Widget_Switcher1->Set_Null_Widget();
		QuestComplete_3();
		GameEnd();
	}
}
void AFIrstPersonCharacterShooterCpp::CheckIfShootInSight()
{
	if (InSight && shotting && Sprinting != true)
	{
		SetShootInSight(true);
		AnimInstance->Montage_Play(FireAnimationInSight, 1.0f);
		AnimInstanceRifle->Montage_Play(FireAnimationInSightRifle, 1.0f);
	}
	else
	{
		shottingInSight = false;
		SetShootInSight(shottingInSight);
	}
}
bool AFIrstPersonCharacterShooterCpp::GetShootInSight()
{
	return shottingInSight;
}
void AFIrstPersonCharacterShooterCpp::SetShootInSight(bool InSight_1)
{
	shottingInSight = InSight_1;
}
void AFIrstPersonCharacterShooterCpp::AddAmmoFromUse(float value)
{
	UpdateReleasedWeaponAmmo(AmmoInPockets+=value);
}
float AFIrstPersonCharacterShooterCpp::GetAmmoInPockets()
{
	return AmmoInPockets;
}
void AFIrstPersonCharacterShooterCpp::Interact()
{
	if (CurrentDoor)
	{
		CurrentDoor->ToggleDoor();
	}
	if (Npc_Test)
	{
		APlayerController* PC = Cast<APlayerController>(GetController());
		DialogueWidget++;
		if (PC && DialogueWidget == 1)
		{
			WeInDialogue = true;
			InventoryOpenClosed = true;
			Npc_Test->Interact(this);
			SetDialogueWidget();
		}
		if (PC && DialogueWidget == 2)
		{
			WeInDialogue = false;
			InventoryOpenClosed = false;
			SetCrosshairWidget();
			DialogueWidget = 0;
		}
		thisIsNPC = true;
	}
	if (Helictopter && Helicopter1Quest!=true && CanInteractQuest)
	{
		Helicopter1Quest = true;
		QuestComplete();
	}
	if (Helictopter_1 && Helicopter2Quest != true && CanInteractQuest)
	{
		Helicopter2Quest = true;
		QuestComplete();
	}
	if (Documents && DocumentsQuest != true && CanInteractQuest)
	{
		DocumentsQuest = true;
		QuestComplete();
		Documents->Interact(this);
	}
	else
	{
		thisIsNPC = false;
	}
	if (WeaponReloading != true && !Npc_Test && !Helictopter && !Helictopter_1 && !Documents) {
		FVector Start = FirstPersonCamera->GetComponentLocation();
		FVector End = Start + FirstPersonCamera->GetForwardVector() * DistanceToPickup;

		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params))
		{

			if (IInteractable_Interface* Interface = Cast<IInteractable_Interface>(HitResult.GetActor()))
			{

				if (thisIsNPC != true) {
					if (PickUpAnim != NULL)
					{
						AnimInstance->Montage_Play(PickUpAnim, 1.0f);
						DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1, 0, 1);
					}
				}
				Interface->Interact(this);
				Prompt_Widget_Switcher1->Set_Null_Widget();
			}
		}
	}
}
void AFIrstPersonCharacterShooterCpp::UseItem(TSubclassOf<AItem_Test> ItemSubclass, class ANPC_TEST* OwningActor, bool IsShopItem)
{
	if (ItemSubclass && AnimationCompleteBool2)
	{
		AnimationCompleteBool2 = false;
		if (!OwningActor) {

			UseRemoveItem(ItemSubclass, true);
		}
		else
		{
			OwningActor->BuyItem(this, ItemSubclass);
			AnimationTimeUseDelay = 0.01f;
			GetWorld()->GetTimerManager().SetTimer(AnimationTimeDelay2, this, &AFIrstPersonCharacterShooterCpp::AnimationResetTimer, AnimationTimeUseDelay, false);
			OnRep_InventoryItems();
		}
	}
}
int32 AFIrstPersonCharacterShooterCpp::CurrentGold()
{
	for (FItems_Data& Item : InventoryItems)
	{
		if (Item.ItemClass == AMoney_UA::StaticClass())
		{
			return Item.StackCount;
		}
	}
	return 0;
}
void AFIrstPersonCharacterShooterCpp::RemoveGold(int32 amountToRemove)
{
	UseRemoveItem(AMoney_UA::StaticClass(), false, amountToRemove);
}
void AFIrstPersonCharacterShooterCpp::UseRemoveItem(TSubclassOf<AItem_Test> ItemSubclass, bool UseItem, uint16 AmountToRemove)
{
	uint8 Index = 0;
	for (FItems_Data& Item : InventoryItems)
	{
		if (Item.ItemClass == ItemSubclass)
		{
			if (UseItem) {
				if (AItem_Test* ItemCDO = ItemSubclass.GetDefaultObject())
				{
					ItemCDO->Use(this, false);
					UsageSound(UsageItemSound);
					GetWorld()->GetTimerManager().SetTimer(AnimationTimeDelay2, this, &AFIrstPersonCharacterShooterCpp::AnimationResetTimer, AnimationTimeUseDelay, false);
					AnimationTimeUseDelay = 0.01f;
				}
			}
			Item.StackCount-=AmountToRemove;
			if (Item.StackCount <= 0)
			{
				InventoryItems.RemoveAt(Index);
			}
			//W_Inventory_Item_2->UpdateStackCount(Item);
			break;
		}
		++Index;
	}
	OnRep_InventoryItems();
}
void AFIrstPersonCharacterShooterCpp::OnRep_InventoryItems()
{
	if (InventoryItems.Num())
	{
		AddItemToInventoryWidget_1(InventoryItems[InventoryItems.Num() - 1], InventoryItems);
		AddItemToShopInventoryWidget_1(InventoryItems[InventoryItems.Num() - 1], InventoryItems);
	}
	else
	{
		AddItemToInventoryWidget_1(FItems_Data(), InventoryItems);
		AddItemToShopInventoryWidget_1(FItems_Data(), InventoryItems);
	}
}
void AFIrstPersonCharacterShooterCpp::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AFIrstPersonCharacterShooterCpp, InventoryItems, COND_OwnerOnly);

}
void AFIrstPersonCharacterShooterCpp::AddInventoryItem(FItems_Data ItemData)
{
	bool bIsNewItem = true;
	for (FItems_Data& Item : InventoryItems)
	{
		if (Item.ItemClass == ItemData.ItemClass)
		{
			Item.StackCount+=ItemData.StackCount;
			bIsNewItem = false;
			break;
		}
	}
	if (bIsNewItem) {
		InventoryItems.Add(ItemData);
	}
	OnRep_InventoryItems();
}
void AFIrstPersonCharacterShooterCpp::Inventory()
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	numberInventory++;
	if (PC && numberInventory==1.0f)
	{
		InventoryOpenClosed = true;
		SetInventoryWidget();

	}
	if (PC && numberInventory == 2.0f)
	{
		InventoryOpenClosed = false;
		WeInDialogue = false;
		DialogueWidget = 0;
		SetCrosshairWidget();
		numberInventory = 0;
	}
}

void AFIrstPersonCharacterShooterCpp::OnFire()
{
	if (Sprinting != true)
	{
		GetWorldTimerManager().SetTimer(FireTimeHandle, this, &AFIrstPersonCharacterShooterCpp::Fire, DelayFireTime, FireOrSingleShots, 0.05f);
	}
}

void AFIrstPersonCharacterShooterCpp::StopFire()
{
	GetWorldTimerManager().ClearTimer(FireTimeHandle);
	shotting = false;
	CheckIfShootInSight();
}

void AFIrstPersonCharacterShooterCpp::ThrowGrenade()
{
	if (FastThrowGrenadeAnimation != NULL)
	{
		AnimInstance->Montage_Play(FastThrowGrenadeAnimation, 1.0f);
	}
}

void AFIrstPersonCharacterShooterCpp::Fire()
{
		if (WeaponFull && WeaponReloading != true && InventoryOpenClosed != true) {
			shotting = true;
			bCanFire = false;
			CheckIfShootInSight();
			if (World != NULL)
			{
				SpawnRotation = GetControlRotation();
				SpawnLocation = ((MuzzleLocation != nullptr) ? MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				World->SpawnActor<AProjectile>(Projectile, SpawnLocation, SpawnRotation, ActorSpawnParams);

				if (FireSound != NULL)//Playing Fire sound
				{
					UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
				}
				if (FireAnimation != NULL && GetShootInSight() !=true)
				{
					AnimInstance->Montage_Play(FireAnimation, 1.0f);
				}
				if (FireAnimation2 != NULL && GetShootInSight() != true)
				{
					AnimInstanceRifle->Montage_Play(FireAnimation2, 1.0f);
				}
			}
			Ammo -= 1.0f;
			UpdateWeaponAmmo(Ammo);
			if (Ammo == 0)
			{
				WeaponFull = false;
			}
		}
}

void AFIrstPersonCharacterShooterCpp::ReloadWeapon()
{
	if (InventoryOpenClosed != true) {
		if (AmmoInPockets == 0)
		{
			ReloadingWeaponSucced = false;
		}
		if (Ammo != FullAk47Ammo && ReloadingWeaponSucced) {
			if (ReloadingWeaponSucced && AmmoInPockets - (FullAk47Ammo - Ammo) >= 0) {
				if (Ammo >= 1) {
					if (ReloadAnimation != NULL)// Playing Fire animation
					{
						AnimInstance->Montage_Play(ReloadAnimation, 1.0f);
					}
					if (ReloadAnimation2 != NULL)// Playing Fire animation
					{
						AnimInstanceRifle->Montage_Play(ReloadAnimation2, 1.0f);
					}
				}
				if (Ammo == 0) {
					if (ReloadAnimationEmpty != NULL)// Playing Fire animation
					{
						AnimInstance->Montage_Play(ReloadAnimationEmpty, 1.0f);
					}
					if (ReloadAnimation2Empty != NULL)// Playing Fire animation
					{
						AnimInstanceRifle->Montage_Play(ReloadAnimation2Empty, 1.0f);
					}
				}
				ReloadingWeaponSucced = false;
				AmmoInPockets -= FullAk47Ammo - Ammo;
				Ammo = FullAk47Ammo;
				WeaponFull = true;
				UpdateWeaponAmmo(Ammo);
				UpdateReleasedWeaponAmmo(AmmoInPockets);
				GetWorld()->GetTimerManager().SetTimer(ReloadTimerDelay, this, &AFIrstPersonCharacterShooterCpp::ReloadWeaponDelay, 2.0f, false);
				WeaponReloading = true;
				GetWorld()->GetTimerManager().SetTimer(ReloadingTimerDelay, this, &AFIrstPersonCharacterShooterCpp::ReloadingWeaponSucces, 2.0f, false);
			}
			else
			{
				if (Ammo >= 1) {
					if (ReloadAnimation != NULL)// Playing Fire animation
					{
						AnimInstance->Montage_Play(ReloadAnimation, 1.0f);
					}
					if (ReloadAnimation2 != NULL)// Playing Fire animation
					{
						AnimInstanceRifle->Montage_Play(ReloadAnimation2, 1.0f);
					}
				}
				if (Ammo == 0) {
					if (ReloadAnimationEmpty != NULL)// Playing Fire animation
					{
						AnimInstance->Montage_Play(ReloadAnimationEmpty, 1.0f);
					}
					if (ReloadAnimation2Empty != NULL)// Playing Fire animation
					{
						AnimInstanceRifle->Montage_Play(ReloadAnimation2Empty, 1.0f);
					}
				}
				ReloadingWeaponSucced = false;
				Ammo += AmmoInPockets;
				AmmoInPockets = 0;
				WeaponFull = true;
				UpdateWeaponAmmo(Ammo);
				UpdateReleasedWeaponAmmo(AmmoInPockets);
				GetWorld()->GetTimerManager().SetTimer(ReloadTimerDelay, this, &AFIrstPersonCharacterShooterCpp::ReloadWeaponDelay, 2.0f, false);
				WeaponReloading = true;
				GetWorld()->GetTimerManager().SetTimer(ReloadingTimerDelay, this, &AFIrstPersonCharacterShooterCpp::ReloadingWeaponSucces, 2.0f, false);
			}
		}
	}
}
void AFIrstPersonCharacterShooterCpp::FlipFlopShots()
{
	FireSingleorAuto++;
		if (FireSingleorAuto == 0.0f)
		{
			FireOrSingleShots = false;
			SetSingleShotWidget();
		}
		if (FireSingleorAuto == 1.0f)
		{
			FireOrSingleShots = true;
			SetIAutoShotWidget();
		}
		if (FireSingleorAuto == 2.0f)
		{
			FireOrSingleShots = false;
			FireSingleorAuto = 0;
			SetSingleShotWidget();
		}
}
void AFIrstPersonCharacterShooterCpp::SetHideAutoShootWidget()
{
	GetWorldTimerManager().ClearTimer(HideAutoWidgetDelay);
}
void AFIrstPersonCharacterShooterCpp::SetHideSingleShootWidget()
{
	GetWorldTimerManager().ClearTimer(HideSingleWidgetDelay);
}
void AFIrstPersonCharacterShooterCpp::AnimationResetTimer()
{
	AnimationCompleteBool2 = true;
	GetWorldTimerManager().ClearTimer(AnimationTimeDelay2);
}

void AFIrstPersonCharacterShooterCpp::ReloadWeaponDelay()
{
	ReloadingWeaponSucced = true;
	GetWorldTimerManager().ClearTimer(ReloadTimerDelay);
}

void AFIrstPersonCharacterShooterCpp::ReloadingWeaponSucces()
{
	WeaponReloading = false;
	GetWorldTimerManager().ClearTimer(ReloadingTimerDelay);
}

void AFIrstPersonCharacterShooterCpp::ResetFire()
{
	if (InventoryOpenClosed != true) {
		bCanFire = true;
		GetWorldTimerManager().ClearTimer(FireTimeHandle);
	}
}

void AFIrstPersonCharacterShooterCpp::UsageSound(USoundBase* UsageSoundItems2)
{
	if (UsageSoundItems2 != NULL)
	{
		UGameplayStatics::PlaySound2D(this, UsageSoundItems2);
	}
}

void AFIrstPersonCharacterShooterCpp::MoveForward(float Value)
{
	if (Value == 1.0f && WeInDialogue!=true) {
		AddMovementInput(GetActorForwardVector(), Value);
		Moving = true;
	}
	if(Value==0.0f )
	{
		Moving = false;
	}
	if (Value == -1.0f && WeInDialogue != true)
	{
		AddMovementInput(GetActorForwardVector(), Value);
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
		Moving = false;
	}
}

void AFIrstPersonCharacterShooterCpp::MoveRight(float Value)
{
	if (Value != 0.0f && WeInDialogue != true) {
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AFIrstPersonCharacterShooterCpp::TurnAtRate(float Rate)
{
	if (InventoryOpenClosed != true) {
		AddControllerYawInput(Rate * TurnRate * GetWorld()->GetDeltaSeconds());
	}
}

void AFIrstPersonCharacterShooterCpp::LookAtRate(float Rate)
{
	if (InventoryOpenClosed != true) {
		AddControllerPitchInput(Rate * LookUpRate * GetWorld()->GetDeltaSeconds());
	}
}

void AFIrstPersonCharacterShooterCpp::Sprint()
{
	if (InventoryOpenClosed != true && CanSprint && Moving) {
		if (SprintAnimation != NULL)
		{
			AnimInstance->Montage_Play(SprintAnimation, 1.0f);
		}
		isSprinting = true;
		Sprinting = true;
		GetWorldTimerManager().SetTimer(StaminaMinusDelay, this, &AFIrstPersonCharacterShooterCpp::ReduceStamina, 0.1f , true, 0.05f);
	}
}
void AFIrstPersonCharacterShooterCpp::ReduceStamina()
{
	if (Stamina >= 0.5f && Moving) {
		GetCharacterMovement()->MaxWalkSpeed = 1200.0f;
		Stamina -= 0.5f;
		CanSprint = true;
		UpdateW_Ui_Widget(Stamina);
		SetStamina(Stamina);
	}
	if (Stamina <= 0.0f)
	{
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
		CanSprint = false;
		GetWorldTimerManager().ClearTimer(StaminaMinusDelay);
	}
}
void AFIrstPersonCharacterShooterCpp::AddingStamina()
{
	GetStamina();
	if (Stamina == 99.5f && Sprinting!=true && jumping!=true)
	{
		Stamina = 100.0f;
		CanSprint = true;
		UpdateW_Ui_Widget(Stamina);
		GetWorldTimerManager().ClearTimer(StaminaPlusDelay);
	}
	if (Stamina <= 99.0f && Sprinting != true && jumping != true)
	{
		Stamina += 0.5f;
		CanSprint = true;
		UpdateW_Ui_Widget(Stamina);
	}
}
float AFIrstPersonCharacterShooterCpp::GetStamina()
{
	return Stamina;
}
void AFIrstPersonCharacterShooterCpp::SetStamina(float value)
{
	Stamina = value;
}
void AFIrstPersonCharacterShooterCpp::StopSprinting()
{
	if (InventoryOpenClosed != true) {
		Sprinting = false;
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
		isSprinting = false;
		GetWorldTimerManager().ClearTimer(StaminaMinusDelay);
		GetStamina();
		if (Stamina <= 99.5f && Sprinting!=true)
		{
			GetWorldTimerManager().SetTimer(StaminaPlusDelay, this, &AFIrstPersonCharacterShooterCpp::AddingStamina, 0.1f, true, 1.0f);
		}
	}
}

void AFIrstPersonCharacterShooterCpp::AddHealth(float Value)
{	
	if (Health <= 99.0f)
	{
		Health += Value;
		UpdateW_Ui_WidgetHealth(Health);
		UpdateInventoryHealth(Health);
	}
	if (Health > 100.0f)
	{
		Health = 100.0f;
		UpdateW_Ui_WidgetHealth(Health);
		UpdateInventoryHealth(Health);
	}
}

void AFIrstPersonCharacterShooterCpp::RemoveHunger(float Value)
{
	if (Hunger <= 2499.0f)
	{
		Hunger += Value;
	}
	if (Hunger > 2500.0f)
	{
		Hunger = 2500.0f;
	}
}

void AFIrstPersonCharacterShooterCpp::DamageTimer()
{
	bCanBeDamaged = true;
}

void AFIrstPersonCharacterShooterCpp::SetDamageState()
{
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AFIrstPersonCharacterShooterCpp::SetDamageState, 2.0f, false);
}