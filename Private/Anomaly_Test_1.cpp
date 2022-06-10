// Fill out your copyright notice in the Description page of Project Settings.


#include "Anomaly_Test_1.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GAME_FOR_OOP_KR/FIrstPersonCharacterShooterCpp.h"
#include "Components/AudioComponent.h"

// Sets default values
AAnomaly_Test_1::AAnomaly_Test_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
    MyBoxComponent->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
    RootComponent = MyBoxComponent;
    Fire = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("My Fire"));
    Fire->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    Fire->SetupAttachment(RootComponent);
    HideAnomalyEffectBool = true;
    Fire->SetHiddenInGame(HideAnomalyEffectBool);
    HideSparksDisortion = false;
    FireSparks = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireSparks"));
    FireSparks->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    FireSparks->SetupAttachment(RootComponent);
    FireSparks->SetHiddenInGame(HideSparksDisortion);
    FireDisortion = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireDisortion"));
    FireDisortion->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    FireDisortion->SetupAttachment(RootComponent);
    FireDisortion->SetHiddenInGame(HideSparksDisortion);
    MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AAnomaly_Test_1::OnOverlapBegin);
    MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &AAnomaly_Test_1::OnOverlapEnd);
    bCanApplyDamage = false;
    AnomalyDamage = 15.0f;
    number = 0;

}
void AAnomaly_Test_1::BeginPlay()
{
    Super::BeginPlay();
    FVector location = MyBoxComponent->GetComponentLocation();
    AnomalySound = UGameplayStatics::SpawnSoundAtLocation(this, AnomalySoundBase, location, FRotator::ZeroRotator, 0.5f, 1.0f, 0.0f, nullptr, nullptr, true);
    if (AnomalySoundBase != NULL && AnomalySoundStop!=true && AnomalySound != NULL)//Playing Fire sound
    {
        AnomalySound->SetActive(false);
        AnomalySoundStop = true;
    }
}
void AAnomaly_Test_1::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

    MyCharacter = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
    if (MyCharacter && OtherActor!=this)
    {
        if (AnomalySoundStop && AnomalySound != NULL) {
            AnomalySound->SetActive(true);
            UE_LOG(LogTemp, Warning, TEXT("Sound on"));
            AnomalySoundStop = false;
        }
        HideAnomalyEffectBool = false;
        HideSparksDisortion = true;
        Fire->SetHiddenInGame(HideAnomalyEffectBool);
        FireDisortion->SetHiddenInGame(HideSparksDisortion);
        FireSparks->SetHiddenInGame(HideSparksDisortion);
        UE_LOG(LogTemp, Warning, TEXT("You got overlaped"));
        bCanApplyDamage = true;
        MyHit = SweepResult;
        number += 1;
        if (number == 6.0f) {
            UE_LOG(LogTemp, Warning, TEXT("You start hitting == 6, %f"), number);
            GetWorldTimerManager().SetTimer(FireTimerHandle, this, &AAnomaly_Test_1::ApplyFireDamage, 2.2f, true, 0.02f);
        }
        if (number > 6.0f) {
            UE_LOG(LogTemp, Warning, TEXT("You start hitting > 6, %f"), number);
            GetWorldTimerManager().SetTimer(FireTimerHandle, this, &AAnomaly_Test_1::ApplyFireDamage, 2.2f, true);
        }

    }
}
void AAnomaly_Test_1::SetNumberToZero()
{
    number = 0.0f;
    GetWorldTimerManager().ClearTimer(SetTimeToZero);
}
void AAnomaly_Test_1::HideAnomalyEffect()
{
    if (AnomalySoundBase != NULL && AnomalySoundStop!=true && AnomalySound!=NULL)//Playing Fire sound
    {
        AnomalySound->SetActive(false);
        AnomalySoundStop = true;
        UE_LOG(LogTemp, Warning, TEXT("Sound stop, %f"), number);
    }
    number = 0.0f;
    HideAnomalyEffectBool = true;
    HideSparksDisortion = false;

    Fire->SetHiddenInGame(HideAnomalyEffectBool);
    FireDisortion->SetHiddenInGame(HideSparksDisortion);
    FireSparks->SetHiddenInGame(HideSparksDisortion);
    UE_LOG(LogTemp, Warning, TEXT("Anomaly Hidden, %f"), number);

    GetWorldTimerManager().ClearTimer(TimeEffectHiden);
}
void AAnomaly_Test_1::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    MyCharacter = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
    if (OtherActor != this && MyCharacter)
    {
        bCanApplyDamage = false;
        UE_LOG(LogTemp, Warning, TEXT("You stop overlaped"));
        GetWorldTimerManager().ClearTimer(FireTimerHandle);
        GetWorldTimerManager().SetTimer(SetTimeToZero, this, &AAnomaly_Test_1::SetNumberToZero, 0.5f, true);
        GetWorldTimerManager().SetTimer(TimeEffectHiden, this, &AAnomaly_Test_1::HideAnomalyEffect, 4.4f, true);
    }
}

void AAnomaly_Test_1::ApplyFireDamage()
{
    if (AnomalySoundStop && AnomalySound!=NULL)
    {
        AnomalySound->SetActive(true);
        AnomalySoundStop = false;
    }
    if (HideAnomalyEffectBool) {
        HideAnomalyEffectBool = false;
        HideSparksDisortion = true;
        Fire->SetHiddenInGame(HideAnomalyEffectBool);
        FireDisortion->SetHiddenInGame(HideSparksDisortion);
        FireSparks->SetHiddenInGame(HideSparksDisortion);
        UE_LOG(LogTemp, Warning, TEXT("Anomaly Unhidden"));
    }
    if (bCanApplyDamage && HideAnomalyEffectBool!=true)
    {
        MyCharacter = Cast<AFIrstPersonCharacterShooterCpp>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
        UGameplayStatics::ApplyPointDamage(MyCharacter, AnomalyDamage, MyCharacter->GetActorLocation(), MyHit, nullptr, this, FireDamageType);
    }

}