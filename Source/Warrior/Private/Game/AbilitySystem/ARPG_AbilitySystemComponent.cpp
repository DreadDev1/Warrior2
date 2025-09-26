// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/AbilitySystem/ARPG_AbilitySystemComponent.h"

void UARPG_AbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if(!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UARPG_AbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}
