// Fill out your copyright notice in the Description page of Project Settings.


#include "EmmisionTest.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
// Sets default values
AEmmisionTest::AEmmisionTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	MyBoxComponent->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	RootComponent = MyBoxComponent;
	SafePlaceComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Safe place"));
	SafePlaceComponent->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	SafePlaceComponent->SetupAttachment(GetMesh());

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AEmmisionTest::OnOverlapBegin);
	MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &AEmmisionTest::OnOverlapEnd);

	SafePlaceComponent->OnComponentBeginOverlap.AddDynamic(this, &AEmmisionTest::inSafePlace);
	SafePlaceComponent->OnComponentEndOverlap.AddDynamic(this, &AEmmisionTest::notInSafePlace);
	inSafePlace1 = false;
	TimeBeforeEmission = 300.0f;
	TimeStopEmission = 10.0f;
	EmissionDamage = 2.0f;
}

// Called when the game starts or when spawned
void AEmmisionTest::BeginPlay()
{
	Super::BeginPlay();
	MyCharacter2 = Cast<AFIrstPersonCharacterShooterCpp>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void AEmmisionTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UBoxComponent* AEmmisionTest::GetMesh() const
{
	return MyBoxComponent;
}

void AEmmisionTest::checkBoolForDamage()
{
	if (inSafePlace1 != true)
	{
		UE_LOG(LogTemp, Warning, TEXT("You getting Damage"));
		ApplyFireDamage();
	}
}

bool AEmmisionTest::GetBool()
{
	return inSafePlace1;
}

void AEmmisionTest::SetBool(bool Bool)
{
	inSafePlace1 = Bool;
}
void AEmmisionTest::EmmisionStarted()
{
	UE_LOG(LogTemp, Warning, TEXT("Emission Started"));
	GetWorldTimerManager().SetTimer(checkBool, this, &AEmmisionTest::checkBoolForDamage, 1.0f, true, 1.0f);
}
void AEmmisionTest::EmmisionStop()
{
	inSafePlace1 = true;
	UE_LOG(LogTemp, Warning, TEXT("Emission Stop"));
	Destroy();
}
void AEmmisionTest::GettingDamage()
{
	if (inSafePlace1 != true)
	{
		UE_LOG(LogTemp, Warning, TEXT("You dying"));
	}
}
void AEmmisionTest::inSafePlace(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	MyCharacter2 = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (OtherActor != this && MyCharacter2)
	{
		inSafePlace1 = true;
		UE_LOG(LogTemp, Warning, TEXT("You in safe place"));
	}
}

void AEmmisionTest::notInSafePlace(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	MyCharacter2 = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (OtherActor != this && MyCharacter2)
	{
		inSafePlace1 = false;
		UE_LOG(LogTemp, Warning, TEXT("You not in safe place"));
	}
}
void AEmmisionTest::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	MyCharacter2 = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (MyCharacter2 && OtherActor != this)
	{
		inSafePlace1 = false;
		UE_LOG(LogTemp, Warning, TEXT("You overlaping"));
		GetWorldTimerManager().SetTimer(EmmisionStartedTimer, this, &AEmmisionTest::EmmisionStarted, TimeBeforeEmission, false, TimeBeforeEmission);
		GetWorldTimerManager().SetTimer(EmmisionStopTimer, this, &AEmmisionTest::EmmisionStop, TimeStopEmission, false, TimeStopEmission);
	}
}

void AEmmisionTest::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	MyCharacter2 = Cast<AFIrstPersonCharacterShooterCpp>(OtherActor);
	if (OtherActor != this && MyCharacter2)
	{
		inSafePlace1 = true;
		UE_LOG(LogTemp, Warning, TEXT("You stop hitting"));
		GetWorldTimerManager().ClearTimer(GettingDamageTimer);
		GetWorldTimerManager().ClearTimer(EmmisionStartedTimer);
		GetWorldTimerManager().ClearTimer(checkBool);
		GetWorldTimerManager().ClearTimer(EmmisionStopTimer);
	}
}

void AEmmisionTest::ApplyFireDamage()
{
	MyCharacter2 = Cast<AFIrstPersonCharacterShooterCpp>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UGameplayStatics::ApplyPointDamage(MyCharacter2, EmissionDamage, MyCharacter2->GetActorLocation(), MyHit2, nullptr, this, EmissionDamageType);
	UE_LOG(LogTemp, Warning, TEXT("You start hitting"));
}