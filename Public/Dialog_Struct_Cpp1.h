// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "GAME_FOR_OOP_KR/Public/Subtitle_Struct.h"
#include "Dialog_Struct_Cpp1.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FDialog_Struct_Cpp1 : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	/*The question's excerpt - this will be shown inside our UI*/
	UPROPERTY(EditAnywhere)
		FString QuestionExcerpt;

	/*The actual SFX that we're going to play*/
	UPROPERTY(EditAnywhere)
		USoundBase* SFX;

	/*An array of the associated subtitles*/
	UPROPERTY(EditAnywhere)
		TArray<FSubtitle_Struct> Subtitles;

	UPROPERTY(EditAnywhere)
		float NumberForDialogue;

	/*True if we want to wait for the AI to respond*/
	UPROPERTY(EditAnywhere)
		bool bShouldAIAnswer;
	UPROPERTY(EditAnywhere)
		float SentencesCountDialog;
	UPROPERTY(EditAnywhere)
		float DialogUniquesNumber;

};
