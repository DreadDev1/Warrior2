// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPG_Types/ARPG_StructTypes.h"
#include "Game/AbilitySystem/Abilities/ARPG_GameplayAbility.h"

bool FARPG_HeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
