// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_CPP.h"
#include "Components/BoxComponent.h"
#include "FIrstPersonCharacterShooterCpp.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
AEnemy_CPP::AEnemy_CPP(const class FObjectInitializer& PCIP) : Super(PCIP)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = SpeedBP_1; // Скорость
	HitPoints = 100; // Здоровье
	Experience = 0; // Опыт
	Damage = 20;
	BPLoot = NULL; // Трофеи
	BaseAttackDamage = 1; // Урон базовой атаки
	AttackTimeout = 1.5f; // Длительность атаки
	TimeSinceLastStrike = 0; // Прошло времени с последнего удара
	Crovosos = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Crovosos Mesh"));
	SightSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this,TEXT("SightSphere-1"));
	SightSphere->AttachTo(RootComponent);
	AttackRangeSphere = PCIP.CreateDefaultSubobject <USphereComponent>(this,TEXT("AttackRangeSphere-2"));
	AttackRangeSphere->AttachTo(RootComponent);
	MeeleWeapon = PCIP.CreateDefaultSubobject <USphereComponent>(this, TEXT("LapaKrovososa"));
	AttackRangeSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemy_CPP::OverlapHitSphere);
	AttackRangeSphere->OnComponentEndOverlap.AddDynamic(this, &AEnemy_CPP::OverlapHitSphereEnd);
	MeeleWeapon->OnComponentBeginOverlap.AddDynamic(this, &AEnemy_CPP::DamagePlayer);
	MeeleWeapon->OnComponentEndOverlap.AddDynamic(this, &AEnemy_CPP::NoDamagePlayer);
	TryToHitPlayer = false;
}
// Called when the game starts or when spawned
void AEnemy_CPP::BeginPlay()
{
	Super::BeginPlay();
	MeeleWeapon->AttachToComponent(Crovosos, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("CrovososHand"));
}
// Called every frame
void AEnemy_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// базовый интеллект: двигает монстра на игрока
	AFIrstPersonCharacterShooterCpp* avatar = Cast<AFIrstPersonCharacterShooterCpp>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!avatar) return;
	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
	float distanceToPlayer = toPlayer.Size();
	// Если игрок не в SightSphere монстра,
	// идём назад
	if (distanceToPlayer > SightSphere->GetScaledSphereRadius())
	{
		Speed = 0;
		return;
	}
	else
	{
		Speed = SpeedBP_1;
	}
	toPlayer /= distanceToPlayer; // нормализуем вектор
	// Собственно двигаем монстра на игрока по немногу
	AddMovementInput(toPlayer, Speed * DeltaTime);
	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; // 0 off the pitch
	RootComponent->SetWorldRotation(toPlayerRotation);
	// (остальная часть функции такая же как прежде (вращение))
}

// Called to bind functionality to input
void AEnemy_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemy_CPP::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	IsGettingHit = true;

}
void AEnemy_CPP::OverlapHitSphere(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	MyCharacter = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (MyCharacter && OtherActor != this)
	{
		TryToHitPlayer = true;
	}
}

void AEnemy_CPP::DealDamage_1(float DamageAmount)
{
	HitPoints -= DamageAmount;
	if (HitPoints <= 0)
	{
		Destroy();
	}
}
void AEnemy_CPP::ResetYron()
{
	TryToHitPlayer = true;
	GetWorldTimerManager().ClearTimer(ResetYronTimer);
}
void AEnemy_CPP::OverlapHitSphereEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	MyCharacter = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (MyCharacter && OtherActor != this)
	{
		TryToHitPlayer = false;
	}
}
void AEnemy_CPP::DamagePlayer(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	MyCharacter = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (MyCharacter && OtherActor != this && TryToHitPlayer)
	{
		FVector location = Crovosos->GetComponentLocation();
		CrovososSound2 = UGameplayStatics::SpawnSoundAtLocation(this, CrovososSoundBase2, location, FRotator::ZeroRotator, 0.5f, 1.0f, 0.0f, nullptr, nullptr, true);
		MyCharacter->DealDamage(Damage);
		TryToHitPlayer = false;
		GetWorldTimerManager().SetTimer(ResetYronTimer, this, &AEnemy_CPP::ResetYron, 2.2f, false);
	}
	
}
void AEnemy_CPP::NoDamagePlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	MyCharacter = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (MyCharacter && OtherActor != this)
	{
		TryToHitPlayer = false;
	}
}