// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/AbilitySystem/Abilities/ARPG_HeroGameplayAbility.h"
#include "Characters/Hero/ARPG_HeroCharacter.h"
#include "Controllers/ARPG_HeroController.h"

AARPG_HeroCharacter* UARPG_HeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedARPG_HeroCharacter.IsValid())
	{
		CachedARPG_HeroCharacter = Cast<AARPG_HeroCharacter>(CurrentActorInfo->AvatarActor);
	}
   
	return CachedARPG_HeroCharacter.IsValid()? CachedARPG_HeroCharacter.Get() : nullptr;
}

AARPG_HeroController* UARPG_HeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedARPG_HeroController.IsValid())
	{
		CachedARPG_HeroController = Cast<AARPG_HeroController>(CurrentActorInfo->PlayerController);
	}

	return CachedARPG_HeroController.IsValid()? CachedARPG_HeroController.Get() : nullptr;
}

UHeroCombatComponent* UARPG_HeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
