// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TimelineComponent.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Open = false;
	ReadyState = true;

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Frame"));
	RootComponent = DoorFrame;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	RotateValue = 1.0f;
	if (DoorCurve)
	{
		FOnTimelineFloat TimeLineCallBack;
		FOnTimelineEventStatic TimelineFinishedCallback;

		TimeLineCallBack.BindUFunction(this, FName("ControlDoor"));
		TimelineFinishedCallback.BindUFunction(this, FName("SetState"));

		MyTimeline = NewObject<UTimelineComponent>(this, FName("DoorAnimation"));
		MyTimeline->AddInterpFloat(DoorCurve, TimeLineCallBack);
		MyTimeline->SetTimelineFinishedFunc(TimelineFinishedCallback);
		MyTimeline->RegisterComponent();
	}
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyTimeline != NULL)
	{
		MyTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
	}
}

void ADoor::ControlDoor()
{
	TimelineValue = MyTimeline->GetPlaybackPosition();
	CurveFloatValue = RotateValue * DoorCurve->GetFloatValue(TimelineValue);

	FQuat NewRotation = FQuat(FRotator(0.0f, CurveFloatValue, 0.0f));

	Door->SetRelativeRotation(NewRotation);
}

void ADoor::SetState()
{
	ReadyState = true;
}

void ADoor::ToggleDoor()
{
	if (ReadyState)
	{
		Open = !Open;
		APawn* OurPawn = UGameplayStatics::GetPlayerPawn(this, 0);
		FVector PawnLocation = OurPawn->GetActorLocation();
		FVector Direction = GetActorLocation() - PawnLocation;
		Direction = UKismetMathLibrary::LessLess_VectorRotator(Direction, GetActorRotation());
		FVector location = Door->GetComponentLocation();
		DoorSound = UGameplayStatics::SpawnSoundAtLocation(this, DoorBase, location, FRotator::ZeroRotator, 0.5f, 1.0f, 0.0f, nullptr, nullptr, true);
		if (Open)
		{
			if (Direction.X > 0.0f)
			{
				RotateValue = 1.0f;
			}
			ReadyState = false;
			if (MyTimeline != NULL)
			{
				MyTimeline->PlayFromStart();

			}
		}
		else
		{
			ReadyState = false;
			if (MyTimeline != NULL)
			{
				MyTimeline->Reverse();
				FVector location1 = Door->GetComponentLocation();
				DoorCloseSound = UGameplayStatics::SpawnSoundAtLocation(this, DoorCloseBase, location1, FRotator::ZeroRotator, 0.5f, 1.0f, 1.0f, nullptr, nullptr, true);
			}
		}
	}
	//Скрипт снизу позволяет закрывать дверь в середине анимации
	//else
	//{
	//	if (MyTimeline->IsReversing())
	//	{
	//		Open = true;
	//		MyTimeline->Play();
	//	}
	//	else
	//	{
	//		Open = false;
	//		MyTimeline->Reverse();
	//	}
	//}
}