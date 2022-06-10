// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Dialog_Struct_Cpp1.h"
#include "Subtitle_Struct.h"
#include "Dialogue_Text_Widget.h"
#include "Components/TextBlock.h"

#include "Components/Button.h"
#include "Components/WrapBox.h"
#include "Dialogue_Widget_Cpp.generated.h"

/**
 * 
 */
UCLASS()
class GAME_FOR_OOP_KR_API UDialogue_Widget_Cpp : public UUserWidget
{
	GENERATED_BODY()
	virtual bool Initialize();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* MarketPlace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UWrapBox* WrapDialogBox1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* DialogueSentences;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* DialogueSentences_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* DialogueSentences_3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Dialogue_Button1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Dialogue_Button1_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Dialogue_Button1_3;
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Widget Text")
		void SetText1(const FText &Text1);
	/*Updates the displayed subtitles based on the given array*/
	//UFUNCTION(BlueprintCallable, Category = "DialogSystem")
	//	void UpdateSubtitles();
	//TArray<FString> GetArray();
	//TArray<FDialog_Struct_Cpp1> GetStruct();
	//UFUNCTION()
	//void SetStruct(TArray<FDialog_Struct_Cpp1> StructArray);
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	UDialogue_Text_Widget* WidgetText;
	//UPROPERTY(EditAnywhere)
	//	class TSubclassOf<UUserWidget> WidgetText_Class;
	//UFUNCTION()
	//	void CreateWidget1();
	//UFUNCTION()
	//	void AddToDialogueBox(UUserWidget* UserWidget1);

	///*This array will populate our buttons from within the show function*/
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//	TArray<FString> Questions;
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//	TArray<FDialog_Struct_Cpp1> Answers;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	FDialog_Struct_Cpp1 DialogStruct;
	//UFUNCTION(BlueprintCallable)
	//	void Show();
	//UFUNCTION()
	//	void SetQuestion(TArray<FString> Questions1);

};
