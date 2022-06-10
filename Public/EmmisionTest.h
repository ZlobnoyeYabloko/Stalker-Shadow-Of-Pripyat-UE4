// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "GAME_FOR_OOP_KR/FIrstPersonCharacterShooterCpp.h"
#include "EmmisionTest.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API AEmmisionTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEmmisionTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UBoxComponent* MyBoxComponent;
	UPROPERTY(EditAnywhere)
		UBoxComponent* SafePlaceComponent;
	UPROPERTY(EditAnywhere)
		AFIrstPersonCharacterShooterCpp* MyCharacter2;
	UPROPERTY(EditAnywhere)
		bool inSafePlace1;
	class UBoxComponent* GetMesh() const;
	void checkBoolForDamage();
	bool GetBool();
	void SetBool(bool Bool);
	FTimerHandle checkBool;
	FTimerHandle EmmisionStartedTimer;
	FTimerHandle EmmisionStopTimer;
	FTimerHandle GettingDamageTimer;
	UPROPERTY(EditAnywhere)
		float TimeBeforeEmission;
	UPROPERTY(EditAnywhere)
		float TimeStopEmission;
	UPROPERTY(EditAnywhere)
		float EmissionDamage;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UDamageType> EmissionDamageType;
	UPROPERTY(EditAnywhere)
		FHitResult MyHit2;

	void EmmisionStarted();
	void EmmisionStop();
	void GettingDamage();
	

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare component overlap end function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void inSafePlace(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void notInSafePlace(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void ApplyFireDamage();

};
