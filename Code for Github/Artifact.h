// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FIrstPersonCharacterShooterCpp.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "Artifact.generated.h"

UCLASS()
class GAME_FOR_OOP_KR_API AArtifact : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArtifact();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "MyComponents")
		UStaticMeshComponent* ArtifactComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Sphere Components")
		USphereComponent* MySphereComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sphere Components")
		USphereComponent* MySphereComponent1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sphere Components")
		USphereComponent* MySphereComponent2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sphere Components")
		USphereComponent* MySphereComponent3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class USoundBase* ArtifactSoundBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anomaly Sound")
		class UAudioComponent* ArtifactSound;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class AFIrstPersonCharacterShooterCpp* Character;
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		FVector location;
	FTimerHandle timeBeforeArtifactHide;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TimeBeforeArtifactGone;
	FTimerHandle timeBeforeArtifactUnHide;

	class USphereComponent* GetMesh() const;
public:
	FVector mCurrentMeshLocation;
	void SetVisible();
	void SetHidden();
	bool Hidden;
	bool Visible;
	bool bCanEverTickNeed;
	bool SetSoundActive;
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare component overlap end function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//Declare for detector overlap
	UFUNCTION()
		void OnOverlapSphere1(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEndSphere1(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void OnOverlapSphere2(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEndSphere2(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void OnOverlapSphere3(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEndSphere3(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
