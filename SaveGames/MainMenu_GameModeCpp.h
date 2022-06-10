// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SaveGameInstance.h"
#include "GAME_FOR_OOP_KR/FIrstPersonCharacterShooterCpp.h"
#include "Math/Vector.h"
#include "MainMenu_GameModeCpp.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API AMainMenu_GameModeCpp : public AGameModeBase
{
	GENERATED_BODY()
protected:

	virtual void BeginPlay() override;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Game Settings")
		class USaveGameInstance* GameInstance;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Menu Events")
		void OnShowMainMenu(bool NewGame);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		class AFIrstPersonCharacterShooterCpp* MyCharacter;

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Menu Events")
		void OnNewGame(FName MapNameToLoad);

	void OnNewGame_Implementation(FName MapNameToLoad);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Menu Events")
		void OnLoadGame(FName MapNameToLoad);

	void OnLoadGame_Implementation(FName MapNameToLoad);
};
