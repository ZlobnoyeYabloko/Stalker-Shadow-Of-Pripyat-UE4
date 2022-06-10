// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "Anomaly_Test_1.generated.h"

class UBoxComponent;
class UParticleSystemComponent;

UCLASS()
class GAME_FOR_OOP_KR_API AAnomaly_Test_1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnomaly_Test_1();
protected:
	virtual void BeginPlay() override;
public:	
	// Called every frame
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* Fire;
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* FireSparks;
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* FireDisortion;

	bool HideSparksDisortion;
	UPROPERTY(EditAnywhere)
		UBoxComponent* MyBoxComponent;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UDamageType> FireDamageType;

	UPROPERTY(EditAnywhere)
		AFIrstPersonCharacterShooterCpp* MyCharacter;

	UPROPERTY(EditAnywhere)
		FHitResult MyHit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class USoundBase* AnomalySoundBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class UAudioComponent* AnomalySound;

	bool bCanApplyDamage;
	bool AnomalySoundStop;
	FTimerHandle FireTimerHandle;
	FTimerHandle TimeEffectHiden;
	FTimerHandle SetTimeToZero;

	void SetNumberToZero();
	void HideAnomalyEffect();
	UPROPERTY(EditAnywhere)
		float AnomalyDamage;

	UPROPERTY(EditAnywhere)
		bool HideAnomalyEffectBool;

	float number = 0;

	// declare component overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare component overlap end function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void ApplyFireDamage();

};
