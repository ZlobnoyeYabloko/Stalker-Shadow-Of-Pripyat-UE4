// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon_1.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API ABaseWeapon_1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon_1();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		int maxTotalAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		int maxClipAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		int totalAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		int clipAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		float reloadTime;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
