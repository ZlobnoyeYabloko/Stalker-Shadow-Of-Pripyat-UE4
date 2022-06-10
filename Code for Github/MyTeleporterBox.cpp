// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTeleporterBox.h"
using namespace std;

AMyTeleporterBox::AMyTeleporterBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AMyTeleporterBox::EnterTeleporter);
	OnActorEndOverlap.AddDynamic(this, &AMyTeleporterBox::ExitTeleporter);
	teleporting = false;
}
void AMyTeleporterBox::BeginPlay()
{
	Super::BeginPlay();
}
void AMyTeleporterBox::EnterTeleporter(class AActor* overlappedActor, class AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		if (otherTele)
		{
			AFIrstPersonCharacterShooterCpp* character = Cast <AFIrstPersonCharacterShooterCpp>(otherActor);
			if (character && !otherTele->teleporting)
			{
				teleporting = true;
				character->SetActorRotation(otherTele->GetActorRotation());
				character->GetController()->SetControlRotation(character->GetActorRotation());
				character->SetActorLocation(otherTele->GetActorLocation());
			}
		}
	}
}
void AMyTeleporterBox::ExitTeleporter(class AActor* overlapperActor, class AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		if (otherTele && !teleporting)
		{
			otherTele->teleporting = false;
		}
	}
}

