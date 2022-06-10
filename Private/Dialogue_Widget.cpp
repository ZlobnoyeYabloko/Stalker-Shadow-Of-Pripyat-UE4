// Fill out your copyright notice in the Description page of Project Settings.


#include "Dialogue_Widget.h"
#include "..\Public\Dialogue_Widget.h"

bool UDialogue_Widget::Initialize()
{
	Super::Initialize();
	MarketPlace->OnClicked.AddDynamic(this, &UDialogue_Widget::MarketButton);
	return true;
}
void UDialogue_Widget::MarketButton()
{
	UE_LOG(LogTemp, Warning, TEXT("Delete child"));
}
