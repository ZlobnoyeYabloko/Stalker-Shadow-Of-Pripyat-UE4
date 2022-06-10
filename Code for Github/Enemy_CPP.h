// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Enemy_CPP.generated.h"


UCLASS()
class GAME_FOR_OOP_KR_API AEnemy_CPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy_CPP(const class FObjectInitializer& PCIP);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* DamageCollision;
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	// ��������� �� �����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float Speed;
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Crovosos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float SpeedBP_1;
	// ������� �������� �������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float HitPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float IsHittingPlayer;
	// ���� ���������� �� �����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		int32 Experience;
	// Blueprint ���� �������� ���������� ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		UClass* BPLoot;
	// ����� ����� ����������� �� �����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float BaseAttackDamage;
	// ����� �������, ����������� ������� ��� ������
	// ����� �������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float AttackTimeout;
	// ����� � ���������� ����� �������, �������� � blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MonsterProperties)
		float TimeSinceLastStrike;
	// ���������� �� ������� �� �����
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* SightSphere;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* MeeleWeapon;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* MonsterCollisionDamage;
	// ��������� ��� �����. ��������������� � ��������� ��� �����
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* AttackRangeSphere;
	UPROPERTY(EditAnywhere)
		class AFIrstPersonCharacterShooterCpp* MyCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		bool TryToHitPlayer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class USoundBase* CrovososSoundBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class UAudioComponent* CrovososSound;
	UFUNCTION(BlueprintImplementableEvent)
		void DestroyCrovosos();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class USoundBase* CrovososSoundBase2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class UAudioComponent* CrovososSound2;
	FTimerHandle ResetYronTimer;
	UFUNCTION()
		void ResetYron();
	UFUNCTION()
		void DealDamage_1(float DealDamage_1);
	UFUNCTION()
		void OverlapHitSphere(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OverlapHitSphereEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void DamagePlayer(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void NoDamagePlayer(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	inline bool isInSightRange(float d)
	{
		return d < SightSphere->GetScaledSphereRadius();
	}
	inline bool isInAttackRange(float d)
	{
		return d < AttackRangeSphere->GetScaledSphereRadius();
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
		bool IsGettingHit;
public:
	void DealDamage(float DamageAmount);
};
