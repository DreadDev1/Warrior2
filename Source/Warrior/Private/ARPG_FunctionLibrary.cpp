// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPG_FunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Game/AbilitySystem/ARPG_AbilitySystemComponent.h"

UARPG_AbilitySystemComponent* UARPG_FunctionLibrary::NativeGetARPG_ASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UARPG_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UARPG_FunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UARPG_AbilitySystemComponent* ASC = NativeGetARPG_ASCFromActor(InActor);

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UARPG_FunctionLibrary::RemoveGameplayFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UARPG_AbilitySystemComponent* ASC = NativeGetARPG_ASCFromActor(InActor);

	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UARPG_FunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UARPG_AbilitySystemComponent* ASC = NativeGetARPG_ASCFromActor(InActor);

	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UARPG_FunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EARPG_ConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor,TagToCheck)? EARPG_ConfirmType::Yes : EARPG_ConfirmType::No;
}
