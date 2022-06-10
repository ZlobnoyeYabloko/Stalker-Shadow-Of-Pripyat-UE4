// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGameInstance.h"
#include "Kismet/GameplayStatics.h"
const FString USaveGameInstance::UNIQUE_SAVE_SLOT = "SaveData_0";

bool USaveGameInstance::IsNewGame()
{
	if (UGameplayStatics::DoesSaveGameExist(UNIQUE_SAVE_SLOT, 0))
	{
		return false;
	}
	return true;
}

bool USaveGameInstance::CreateNewSaveGame()
{
	CurrentSaveGame = nullptr;
	if (CurrentSaveGame == nullptr)
	{
		USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(UMainSaveGame::StaticClass());

		if (NewSaveGame != nullptr)
		{
			CurrentSaveGame = Cast<UMainSaveGame>(NewSaveGame);
		}
	}
	else
	{
		CurrentSaveGame->CreateSlot(UNIQUE_SAVE_SLOT);
	}
	return UGameplayStatics::SaveGameToSlot(CurrentSaveGame, UNIQUE_SAVE_SLOT, 0);
}

bool USaveGameInstance::LoadGame()
{
	USaveGame* Slot = UGameplayStatics::LoadGameFromSlot(UNIQUE_SAVE_SLOT, 0);
	UE_LOG(LogTemp, Warning, TEXT("CurrentSaveGame != nullptr"));
	if (Slot != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Slot != nullptr"));
		if (CurrentSaveGame != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("[USaveGameInstance::LoadGame] Success loading %s"), *UNIQUE_SAVE_SLOT);

			return true;
		}
	}
	return false;
}

bool USaveGameInstance::SaveGame()
{
	if (CurrentSaveGame != nullptr)
	{
		return UGameplayStatics::SaveGameToSlot(CurrentSaveGame, UNIQUE_SAVE_SLOT, 0);
	}
	return false;
}