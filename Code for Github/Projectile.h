// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Projectile.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		class USphereComponent* CollisionSphere;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		class UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		class UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
		class UParticleSystemComponent* OnHitOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
		class UParticleSystem* HitParticle;
	UPROPERTY(EditAnywhere)
		float DamageValue = 100.0f;
	UPROPERTY(EditAnywhere)
		float MaxSpeedFloat=20000.0f;
	UPROPERTY(EditAnywhere)
		float InitialSpeedFloat = 20000.0f;
	void DestroyProjectile();
};
