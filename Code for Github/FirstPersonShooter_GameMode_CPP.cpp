// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonShooter_GameMode_CPP.h"

void AFirstPersonShooter_GameMode_CPP::BeginPlay()
{
    Super::BeginPlay();
    ChangeMenuWidget(StartingWidgetClass);
}
void AFirstPersonShooter_GameMode_CPP::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{

}