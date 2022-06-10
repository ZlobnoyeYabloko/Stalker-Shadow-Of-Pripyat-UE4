// Fill out your copyright notice in the Description page of Project Settings.


#include "Prompts_Widgets_Switcher.h"
#include "..\Public\Prompts_Widgets_Switcher.h"

void UPrompts_Widgets_Switcher::NativeConstruct()
{
	Super::NativeConstruct();
}

void UPrompts_Widgets_Switcher::Set_Null_Widget()
{
	WidgetSwitcher_1->SetActiveWidgetIndex(0);
}

void UPrompts_Widgets_Switcher::Item_Prompt_Widget()
{
	WidgetSwitcher_1->SetActiveWidgetIndex(1);
}

void UPrompts_Widgets_Switcher::Door_Prompt_Widget()
{
	WidgetSwitcher_1->SetActiveWidgetIndex(2);
}

void UPrompts_Widgets_Switcher::Dialog_Prompt_Widget()
{
	WidgetSwitcher_1->SetActiveWidgetIndex(3);
}
void UPrompts_Widgets_Switcher::Helicopter_Prompt_Widget()
{
	WidgetSwitcher_1->SetActiveWidgetIndex(4);
}