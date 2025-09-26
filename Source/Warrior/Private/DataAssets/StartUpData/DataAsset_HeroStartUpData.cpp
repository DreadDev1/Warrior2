// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "Game/AbilitySystem/Abilities/ARPG_HeroGameplayAbility.h"
#include "Game/AbilitySystem/ARPG_AbilitySystemComponent.h"



void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UARPG_AbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FARPG_HeroAbilitySet& AbilitySet : HeroStartUpAbilitySets)
	{
		if(!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
