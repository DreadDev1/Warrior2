// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "Game/AbilitySystem/ARPG_AbilitySystemComponent.h"
#include "Game/AbilitySystem/Abilities/ARPG_GameplayAbility.h"

#include "GameplayAbilitySpec.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UARPG_AbilitySystemComponent* InASCToGive,
                                                              int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities,InASCToGive,ApplyLevel);
	GrantAbilities(ReactiveAbilities,InASCToGive,ApplyLevel); 
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UARPG_GameplayAbility>>& InAbilitiesToGive,
	UARPG_AbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UARPG_GameplayAbility>& Ability : InAbilitiesToGive)
	{
		if(!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
