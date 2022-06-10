// Fill out your copyright notice in the Description page of Project Settings.


#include "Artifact.h"
#include "Math/TransformNonVectorized.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AArtifact::AArtifact()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	ArtifactComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MoonLight"));
	RootComponent = ArtifactComponent;
	//ArtifactComponent->SetupAttachment(RootComponent);
	ArtifactSound = CreateDefaultSubobject<UAudioComponent>(TEXT("Soundtest"));
	ArtifactSound->SetupAttachment(RootComponent);

	MySphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphereComponent"));
	MySphereComponent->InitSphereRadius(50.0f);
	MySphereComponent->SetupAttachment(RootComponent);

	MySphereComponent1 = CreateDefaultSubobject<USphereComponent>(TEXT("MySphereFirstComponent"));
	MySphereComponent1->InitSphereRadius(60.0f);
	MySphereComponent1->SetupAttachment(GetMesh());
	MySphereComponent2 = CreateDefaultSubobject<USphereComponent>(TEXT("MySphereSecondComponent"));
	MySphereComponent2->InitSphereRadius(70.0f);
	MySphereComponent2->SetupAttachment(GetMesh());
	MySphereComponent3 = CreateDefaultSubobject<USphereComponent>(TEXT("MySphereThreeComponent"));
	MySphereComponent3->InitSphereRadius(80.0f);
	MySphereComponent3->SetupAttachment(GetMesh());

	MySphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AArtifact::OnOverlapBegin);
	MySphereComponent->OnComponentEndOverlap.AddDynamic(this, &AArtifact::OnOverlapEnd);

	MySphereComponent3->OnComponentBeginOverlap.AddDynamic(this, &AArtifact::OnOverlapSphere3);
	MySphereComponent3->OnComponentEndOverlap.AddDynamic(this, &AArtifact::OnOverlapEndSphere3);

	MySphereComponent2->OnComponentBeginOverlap.AddDynamic(this, &AArtifact::OnOverlapSphere2);
	MySphereComponent2->OnComponentEndOverlap.AddDynamic(this, &AArtifact::OnOverlapEndSphere2);

	MySphereComponent1->OnComponentBeginOverlap.AddDynamic(this, &AArtifact::OnOverlapSphere1);
	MySphereComponent1->OnComponentEndOverlap.AddDynamic(this, &AArtifact::OnOverlapEndSphere1);


	Visible = false;
	bCanEverTickNeed = false;

	PrimaryActorTick.bCanEverTick = false;
	TimeBeforeArtifactGone = 1.0f;
	//UE_LOG(LogTemp, Warning, TEXT("Setting bCanEverTickNeed"));
}

// Called when the game starts or when spawned
void AArtifact::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<AFIrstPersonCharacterShooterCpp>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	bCanEverTickNeed = false;
	ArtifactComponent->SetHiddenInGame(true);
	SetSoundActive = false;
	if (ArtifactSound != NULL)//Playing Fire sound
	{
		ArtifactSound->Stop();
	}
}

// Called every frame
void AArtifact::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Gettind distance"));
	////Character->GetActorLocation();
	//float distance = this->GetDistanceTo(Character);
	location = ArtifactComponent->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("Gettind location"));
	//UE_LOG(LogTemp, Warning, TEXT("Distance %f"), distance);
	//if (distance < 250)
	//{
	//	ArtifactComponent->SetHiddenInGame(false);
	//	SetActorEnableCollision(true);
	//	UE_LOG(LogTemp, Warning, TEXT("Unhide artifact"));
	//}
	//else
	//{
	//	ArtifactComponent->SetHiddenInGame(true);
	//	SetActorEnableCollision(true);
	//	UE_LOG(LogTemp, Warning, TEXT("Hide artifact"));
	//}
}

USphereComponent* AArtifact::GetMesh() const
{
	return MySphereComponent;
}

void AArtifact::SetVisible()
{
	if (Visible != true) {
		Visible = true;
		UE_LOG(LogTemp, Warning, TEXT("Set visible"));
		ArtifactComponent->SetHiddenInGame(false);
		SetActorEnableCollision(true);
		if (ArtifactSound != NULL && SetSoundActive != true)//Playing Fire sound
		{
			SetSoundActive = true;
			ArtifactSound->Play();
			UE_LOG(LogTemp, Warning, TEXT("Set active sound"));
		}
		GetWorldTimerManager().ClearTimer(timeBeforeArtifactHide);
		GetWorldTimerManager().ClearTimer(timeBeforeArtifactUnHide);
	}
}

void AArtifact::SetHidden()
{
	if (Visible) {
		Visible = false;
		bCanEverTickNeed = false;
		UE_LOG(LogTemp, Warning, TEXT("Set hidden"));
		ArtifactComponent->SetHiddenInGame(true);
		SetActorEnableCollision(true);
		if (ArtifactSound != NULL && SetSoundActive)//Playing Fire sound
		{
			SetSoundActive = false;
			ArtifactSound->Stop();
			UE_LOG(LogTemp, Warning, TEXT("Set false sound"));
		}
		GetWorldTimerManager().ClearTimer(timeBeforeArtifactUnHide);
		GetWorldTimerManager().ClearTimer(timeBeforeArtifactHide);
	}
}

void AArtifact::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Character = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (Character && OtherActor != this && OtherComp!=MySphereComponent1 && OtherComp != MySphereComponent2 && OtherComp != MySphereComponent3)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlaping 1"));
		Visible = false;
		if (Visible != true) {
			GetWorldTimerManager().SetTimer(timeBeforeArtifactUnHide, this, &AArtifact::SetVisible, 0.01f, true, 0.01f);
			bCanEverTickNeed = true;
			UE_LOG(LogTemp, Warning, TEXT("Overlaping 1"));
		}
	}
}

void AArtifact::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Character = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (Character && OtherActor != this && OtherComp != MySphereComponent1 && OtherComp != MySphereComponent2 && OtherComp != MySphereComponent3)
	{
		UE_LOG(LogTemp, Warning, TEXT("Stop Overlaping 1"));
		if (Visible) {
			GetWorldTimerManager().SetTimer(timeBeforeArtifactHide, this, &AArtifact::SetHidden, TimeBeforeArtifactGone, true, TimeBeforeArtifactGone);
			UE_LOG(LogTemp, Warning, TEXT("Stop Overlaping 1"));
		}
	}
}

void AArtifact::OnOverlapSphere1(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Character = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (OtherActor != this && Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlaping 2"));
	}
}

void AArtifact::OnOverlapEndSphere1(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Character = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (OtherActor != this && Character)
	{
		GetWorldTimerManager().SetTimer(timeBeforeArtifactHide, this, &AArtifact::SetHidden, TimeBeforeArtifactGone, true, TimeBeforeArtifactGone);
		//Visible = true;
		UE_LOG(LogTemp, Warning, TEXT("Stop Overlaping 2"));
	}
}
void AArtifact::OnOverlapSphere2(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Character = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (OtherActor != this && Character)
	{
		//Visible = true;
		UE_LOG(LogTemp, Warning, TEXT("Overlaping 3"));
	}
}

void AArtifact::OnOverlapEndSphere2(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Character = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (OtherActor != this && Character)
	{
		GetWorldTimerManager().SetTimer(timeBeforeArtifactHide, this, &AArtifact::SetHidden, TimeBeforeArtifactGone, true, TimeBeforeArtifactGone);
		//Visible = true;
		UE_LOG(LogTemp, Warning, TEXT("Stop Overlaping 3"));
	}
}
void AArtifact::OnOverlapSphere3(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Character = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (OtherActor != this && Character)
	{
		//Visible = false;
		UE_LOG(LogTemp, Warning, TEXT("Overlaping 4"));
	}
}

void AArtifact::OnOverlapEndSphere3(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Character = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (OtherActor != this && Character)
	{
		if (Visible) {
			GetWorldTimerManager().SetTimer(timeBeforeArtifactHide, this, &AArtifact::SetHidden, TimeBeforeArtifactGone, true, TimeBeforeArtifactGone);
		}
		UE_LOG(LogTemp, Warning, TEXT("Stop Overlaping 4"));
	}
}