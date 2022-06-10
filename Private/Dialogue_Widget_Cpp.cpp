// Fill out your copyright notice in the Description page of Project Settings.


#include "Dialogue_Widget_Cpp.h"
#include "..\Public\Dialogue_Widget_Cpp.h"
using namespace std;

bool UDialogue_Widget_Cpp::Initialize()
{
	Super::Initialize();
	//Dialogue_Button1->OnClicked.AddDynamic(this, &UDialogue_Widget_Cpp::CreateWidget1);

	FText text1 = DialogueSentences_3->GetText();
	FString convertedString = text1.ToString();
	if (convertedString == "")
	{
		Dialogue_Button1_3->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		UE_LOG(LogTemp, Warning, TEXT("Disbale Button"));
	}
	else
	{
		Dialogue_Button1_3->SetVisibility(ESlateVisibility::Visible);
		UE_LOG(LogTemp, Warning, TEXT("Visible Button"));
	}
	FText text2 = DialogueSentences_2->GetText();
	FString convertedString1 = text2.ToString();
	if (convertedString1 == "")
	{
		Dialogue_Button1_2->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		UE_LOG(LogTemp, Warning, TEXT("Disbale Button"));
	}
	else
	{
		Dialogue_Button1_2->SetVisibility(ESlateVisibility::Visible);
		UE_LOG(LogTemp, Warning, TEXT("Visible Button"));
	}
	FText text3 = DialogueSentences->GetText();
	FString convertedString2 = text3.ToString();
	if (convertedString2 == "")
	{
		Dialogue_Button1->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		UE_LOG(LogTemp, Warning, TEXT("Disbale Button"));
	}
	else
	{
		Dialogue_Button1->SetVisibility(ESlateVisibility::Visible);
		UE_LOG(LogTemp, Warning, TEXT("Visible Button"));
	}
	return true;
}
//void UDialogue_Widget_Cpp::UpdateSubtitles()
//{
//
//}
//TArray<FString> UDialogue_Widget_Cpp::GetArray()
//{
//	return Questions;
//}
//TArray<FDialog_Struct_Cpp1> UDialogue_Widget_Cpp::GetStruct()
//{
//	return  Answers;
//}
//void UDialogue_Widget_Cpp::SetStruct(TArray<FDialog_Struct_Cpp1> StructArray)
//{
//	Answers = StructArray;
//}
//void UDialogue_Widget_Cpp::CreateWidget1()
//{
//	if (WidgetText_Class)
//	{
//		WidgetText = Cast<UDialogue_Text_Widget>(CreateWidget(GetWorld(), WidgetText_Class));
//	}
//	Questions = GetArray();
//	WidgetText->SetText1(Questions[0]);
//	AddToDialogueBox(WidgetText);
//
//}
//void UDialogue_Widget_Cpp::AddToDialogueBox(UUserWidget* UserWidget1)
//{
//	WrapDialogBox1->AddChildToWrapBox(UserWidget1);
//}
//void UDialogue_Widget_Cpp::Show()
//{
//	WrapDialogBox1->ClearChildren();
//	UE_LOG(LogTemp, Warning, TEXT("Clear childrens"));
//	Questions = GetArray();
//	DialogueSentences->SetText(FText::FromString(Questions[0]));
//	const int32 NumElements = Answers.Num();
//	UE_LOG(LogTemp, Warning, TEXT("Disbale Button, %i"), NumElements);
//	DialogueSentences_2->SetText(FText::FromString(Questions[1]));
//	DialogueSentences_3->SetText(FText::FromString(Questions[2]));
//}
//
//void UDialogue_Widget_Cpp::SetQuestion(TArray<FString> Questions1)
//{
//	Questions=Questions1;
//}
