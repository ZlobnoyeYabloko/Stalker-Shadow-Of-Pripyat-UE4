// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu_GameModeCpp.h"
#include "Kismet/GameplayStatics.h"

void AMainMenu_GameModeCpp::BeginPlay()
{
	Super::BeginPlay();

	GameInstance = Cast<USaveGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (GameInstance != nullptr)
	{

		bool bIsNewGame = GameInstance->IsNewGame();

		OnShowMainMenu(bIsNewGame);
	}
}


void AMainMenu_GameModeCpp::OnNewGame_Implementation(FName MapNameToLoad)
{
	if (GameInstance == nullptr) return;

	if (GameInstance->CreateNewSaveGame())
	{
		UE_LOG(LogTemp, Warning, TEXT("Open Level"));
		UGameplayStatics::OpenLevel(GetWorld(), MapNameToLoad, true);
	}
}


void AMainMenu_GameModeCpp::OnLoadGame_Implementation(FName MapNameToLoad)
{
	UGameplayStatics::OpenLevel(GetWorld(), MapNameToLoad, true);
}