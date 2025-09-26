// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/AbilitySystem/Abilities/ARPG_GameplayAbility.h"
#include "Components/Combat/PawnCombatCompontent.h"
#include "Game/AbilitySystem/ARPG_AbilitySystemComponent.h"

void UARPG_GameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EARPGAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UARPG_GameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == EARPGAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UPawnCombatComponent* UARPG_GameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

UARPG_AbilitySystemComponent* UARPG_GameplayAbility::GetARPG_AbilitySystemComponentFromActorInfo() const
{
	return Cast<UARPG_AbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}
