// Fill out your copyright notice in the Description page of Project Settings.


#include "Dialogue_Text_Widget.h"
#include "Components/TextBlock.h"
using namespace std;

bool UDialogue_Text_Widget::Initialize()
{
	Super::Initialize();
	return true;
}
void UDialogue_Text_Widget::SetText1(FString Questions1)
{
	FString name = Questions1;
	UE_LOG(LogTemp, Warning, TEXT("%s"), *name);
	Dialogue_Text->SetText(FText::FromString(name));
	/*const int32 NumElements = Questions1.Num();
	UE_LOG(LogTemp, Warning, TEXT("Disbale Button, %i"), NumElements);*/
}
